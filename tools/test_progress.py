import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import progress


class ProgressReportIdentityTests(unittest.TestCase):
    def test_rejects_reports_bound_to_another_target(self):
        for relative_path in (
            "build/G4SE01_progress.json",
            "config/G4SE01/progress.json",
        ):
            with self.subTest(producer=relative_path), tempfile.TemporaryDirectory() as directory:
                root = Path(directory)
                report = root / relative_path
                report.parent.mkdir(parents=True)
                report.write_text(json.dumps({"version": "G4SJ01", "measures": {}}))
                with patch.object(progress, "ROOT", root):
                    with self.assertRaises(SystemExit):
                        progress.load_progress_data("G4SE01")


if __name__ == "__main__":
    unittest.main()
