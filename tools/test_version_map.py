import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

import version_map


class SourceCoverageTests(unittest.TestCase):
    def test_unmapped_data_does_not_hide_code_but_unmapped_code_is_rejected(self):
        for code_delta in (0x100, None):
            with self.subTest(code_delta=code_delta), tempfile.TemporaryDirectory() as directory:
                root = Path(directory)
                source_splits = root / "source.txt"
                target_splits = root / "target.txt"
                target_symbols = root / "symbols.txt"
                version_map.write_splits(str(source_splits), ["Sections:"], [
                    ("shared.cpp", [(".text", 0x1000, 0x1004, ""),
                                    (".data", 0x2000, 0x2004, "")])])
                version_map.write_splits(str(target_splits), ["Sections:"], [])
                source = SimpleNamespace(vid="US", split_path=str(source_splits), syms=[
                    version_map.Sym("shared", ".text", 0x1000, " type:function size:0x4")])
                target = SimpleNamespace(vid="PAL", split_path=str(target_splits),
                                         sym_path=str(target_symbols), syms=[])
                mapping = SimpleNamespace(A=source, B=target, pairs=[])
                data = SimpleNamespace(a2b={})

                def delta(_mapping, _data, section, _start, _end):
                    if section == ".text" and code_delta is not None:
                        return code_delta, ""
                    return None, "unmapped"

                with patch.object(version_map, "section_delta", side_effect=delta), \
                     patch.object(version_map, "verify_range", return_value=""):
                    version_map.propagate(mapping, data, True, False)

                _, units = version_map.load_splits(str(target_splits))
                expected = [("shared.cpp", [(".text", 0x1100, 0x1104, "")])]
                self.assertEqual(units, expected if code_delta is not None else [])
                if code_delta is not None:
                    self.assertIn("shared = .text:0x00001100;", target_symbols.read_text())


if __name__ == "__main__":
    unittest.main()
