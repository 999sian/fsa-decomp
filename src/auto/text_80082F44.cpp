#include "JSystem/JKernel/JKRFileFinder.h"
#include "JSystem/JKernel/JKRArchive.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

JKRArcFinder::JKRArcFinder(JKRArchive *archive, long startindex, long entries) : JKRFileFinder()
{
    mArchive = archive;

    mIsAvailable = entries > 0;
    mStartIndex = startindex;
    mEndIndex = startindex + entries - 1;
    mNextIndex = mStartIndex;

    findNextFile();
}
