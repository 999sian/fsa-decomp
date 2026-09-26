#include "dolphin/os.h"
#include "JSystem/J3D/J3DAnmBase.h"
#include "JSystem/J3D/J3DAnmCluster.h"
#include "JSystem/J3D/J3DAnmColor.h"
#include "JSystem/J3D/J3DAnmTevRegKey.h"
#include "JSystem/J3D/J3DAnmTexPattern.h"
#include "JSystem/J3D/J3DAnmTextureSRTKey.h"
#include "JSystem/J3D/J3DAnmTransform.h"
#include "JSystem/J3D/J3DAnmVtxColor.h"
#include "JSystem/J3D/J3DFrameCtrl.h"
#include "JSystem/J3D/J3DModel.h"
#include "JSystem/JUtility/JUTNameTab.h"
#include "JSystem/JMath/JMath.h"
#include "types.h"

template <class T>
f32 J3DGetKeyFrameInterpolation(f32, J3DAnmKeyTableBase*, T*);

/**
 * @note Address: 0x80067678
 * @note Size: 0x30
 */
void J3DFrameCtrl::init(s16 i_end)
{
	mAttr = J3DAA_UNKNOWN_2;
	mState     = 0;
	mStartFrame     = 0;
	mEndFrame       = i_end;
	mLoop      = 0;
	mRate      = 1.0f;
	mFrame     = 0.0f;
}

int J3DFrameCtrl::checkPass(f32 passFrame) {
    f32 next_frame = mFrame + mRate;

    switch (mAttr) {
    case 0:
    case 1:
        if (next_frame < mStartFrame) {
            next_frame = mStartFrame;
        }

        if (next_frame >= mEndFrame) {
            next_frame = mEndFrame - 0.001f;
        }

        if (mFrame <= next_frame) {
            if (mFrame <= passFrame && passFrame < next_frame) {
                return true;
            } else {
                return false;
            }
        }

        if (next_frame <= passFrame && passFrame < mFrame) {
            return true;
        }
        return false;
    case 2:
        if (mFrame < mStartFrame) {
            while (next_frame < mStartFrame) {
                if (mLoop - mStartFrame <= 0.0f) {
                    break;
                }
                next_frame += mLoop - mStartFrame;
            }

            if (next_frame <= passFrame && passFrame < mLoop) {
                return true;
            } else {
                return false;
            }
        } else if (mEndFrame <= mFrame) {
            while (next_frame >= mEndFrame) {            
                if (mEndFrame - mLoop <= 0.0f) {
                    break;
                }
                next_frame -= mEndFrame - mLoop;
            }

            if (mLoop <= passFrame && passFrame < next_frame) {
                return true;
            } else {
                return false;
            }
        } else if (next_frame < mStartFrame) {
            while (next_frame < mStartFrame) {            
                if (mLoop - mStartFrame <= 0.0f) {
                    break;
                }
                next_frame += mLoop - mStartFrame;
            }

            if ((mStartFrame <= passFrame && passFrame < mFrame) || (next_frame <= passFrame && passFrame < mLoop)) {
                return true;
            } else {
                return false;
            }
        } else if (mEndFrame <= next_frame) {
            while (next_frame >= mEndFrame) {            
                if (mEndFrame - mLoop <= 0.0f) {
                    break;
                }

                next_frame -= mEndFrame - mLoop;
            }

            if ((mFrame <= passFrame && passFrame < mEndFrame) || (mLoop <= passFrame && passFrame < next_frame)) {
                return true;
            } else {
                return false;
            }
        } else if (mFrame <= next_frame) {
            if (mFrame <= passFrame && passFrame < next_frame) {
                return true;
            } else {
                return false;
            }
        } else if (next_frame <= passFrame && passFrame < mFrame) {
            return true;
        }
        return false;
    case 3:
    case 4:
        if (next_frame >= mEndFrame) {
            next_frame = mEndFrame - 0.001f;
        }

        if (next_frame < mStartFrame) {
            next_frame = mStartFrame;
        }

        if (mFrame <= next_frame) {
            if (mFrame <= passFrame && passFrame < next_frame) {
                return true;
            } else {
                return false;
            }
        }

        if (next_frame <= passFrame && passFrame < mFrame) {
            return true;
        }
        return false;
    default:
        return false;
    }
}

/**
 * @note Address: 0x800676A8
 * @note Size: 0x474
 */
void J3DFrameCtrl::update()
{
	mState = 0;
	mFrame += mRate;
	switch (mAttr) {
	case J3DAA_UNKNOWN_0:
		if (mFrame < mStartFrame) {
			mFrame = mStartFrame;
			mRate  = 0.0f;
			mState |= 1;
		}
		if (mFrame >= mEndFrame) {
			mFrame = mEndFrame - 0.001f;
			mRate  = 0.0f;
			mState |= 1;
		}
		break;
	case J3DAA_UNKNOWN_1:
		if (mFrame < mStartFrame) {
			mFrame = mStartFrame;
			mRate  = 0.0f;
			mState |= 1;
		}
		if (mFrame >= mEndFrame) {
			mFrame = mStartFrame;
			mRate  = 0.0f;
			mState |= 1;
		}
		break;
	case J3DAA_UNKNOWN_2:
		while (mFrame < mStartFrame) {
			mState |= 2;
			if (mLoop - mStartFrame <= 0.0f) {
				break;
			}
			mFrame += mLoop - mStartFrame;
		}
		while (mFrame >= mEndFrame) {
			mState |= 2;
			if (mEndFrame - mLoop <= 0.0f) {
				break;
			}
			mFrame -= mEndFrame - mLoop;
		}
		break;
	case J3DAA_UNKNOWN_3:
		if (mFrame >= mEndFrame) {
			mFrame = mEndFrame - (mFrame - mEndFrame);
			mRate  = -mRate;
		}
		if (mFrame < mStartFrame) {
			mFrame = mStartFrame - (mFrame - mStartFrame);
			mRate  = 0.0f;
			mState |= 1;
		}
		break;
	case J3DAA_UNKNOWN_4:
		if (mFrame >= mEndFrame - 1.0f) {
			mFrame = (mEndFrame - 1.0f) - (mFrame - (mEndFrame - 1.0f));
			mRate  = -mRate;
		}
		if (mFrame < mStartFrame) {
			mFrame = mStartFrame - (mFrame - mStartFrame);
			mRate  = -mRate;
			mState |= 2;
		}
		break;
	}
}

// Not present in the DOL (dead-stripped), but its inlined J3DAnmBase base
// constructor is what makes the weak ~J3DAnmBase land right after update().
J3DAnmTransform::J3DAnmTransform()
	: mScaleVals(nullptr)
	, mRotationVals(nullptr)
	, mTranslationVals(nullptr)
	, _18(0)
	, _1A(0)
	, _1C(0)
	, _1E(0)
{
}

J3DAnmTransform::J3DAnmTransform(s16 frameMax, f32* scale, s16* rot, f32* trans)
	: J3DAnmBase(frameMax)
{
	mScaleVals       = scale;
	mRotationVals    = rot;
	mTranslationVals = trans;
	_18              = 0;
	_1A              = 0;
	_1C              = 0;
	_1E              = 0;
}

/**
 * @note Address: 0x80067B1C
 * @note Size: 0x360
 */
void J3DAnmTransformFull::getTransform(u16 idx, J3DTransformInfo* info) const
{
	u16 tableIdx                     = idx * 3;
	J3DAnmTransformFullTable* xTable = &mTable[tableIdx];
	J3DAnmTransformFullTable* yTable = &mTable[tableIdx + 1];
	J3DAnmTransformFullTable* zTable = &mTable[tableIdx + 2];

	if (getFrame() < 0.0f) {
		info->mScale.x = mScaleVals[xTable->mScaleOffset];
		info->mScale.y = mScaleVals[yTable->mScaleOffset];
		info->mScale.z = mScaleVals[zTable->mScaleOffset];

		info->mRotation.x = mRotationVals[xTable->mRotationOffset];
		info->mRotation.y = mRotationVals[yTable->mRotationOffset];
		info->mRotation.z = mRotationVals[zTable->mRotationOffset];

		info->mTranslation.x = mTranslationVals[xTable->mTranslationOffset];
		info->mTranslation.y = mTranslationVals[yTable->mTranslationOffset];
		info->mTranslation.z = mTranslationVals[zTable->mTranslationOffset];

	} else {
		u32 maxFrame = (int)(getFrame() + 0.5f);

		// X VALUES
		if (maxFrame >= xTable->mScaleMaxFrame) {
			info->mScale.x = mScaleVals[xTable->mScaleMaxFrame - 1 + xTable->mScaleOffset];
		} else {
			info->mScale.x = mScaleVals[xTable->mScaleOffset + maxFrame];
		}

		if (maxFrame >= xTable->mRotationMaxFrame) {
			info->mRotation.x = mRotationVals[xTable->mRotationMaxFrame - 1 + xTable->mRotationOffset];
		} else {
			info->mRotation.x = mRotationVals[xTable->mRotationOffset + maxFrame];
		}

		if (maxFrame >= xTable->mTranslationMaxFrame) {
			info->mTranslation.x = mTranslationVals[xTable->mTranslationMaxFrame - 1 + xTable->mTranslationOffset];
		} else {
			info->mTranslation.x = mTranslationVals[xTable->mTranslationOffset + maxFrame];
		}

		// Y VALUES
		if (maxFrame >= yTable->mScaleMaxFrame) {
			info->mScale.y = mScaleVals[yTable->mScaleMaxFrame - 1 + yTable->mScaleOffset];
		} else {
			info->mScale.y = mScaleVals[yTable->mScaleOffset + maxFrame];
		}

		if (maxFrame >= yTable->mRotationMaxFrame) {
			info->mRotation.y = mRotationVals[yTable->mRotationMaxFrame - 1 + yTable->mRotationOffset];
		} else {
			info->mRotation.y = mRotationVals[yTable->mRotationOffset + maxFrame];
		}

		if (maxFrame >= yTable->mTranslationMaxFrame) {
			info->mTranslation.y = mTranslationVals[yTable->mTranslationMaxFrame - 1 + yTable->mTranslationOffset];
		} else {
			info->mTranslation.y = mTranslationVals[yTable->mTranslationOffset + maxFrame];
		}

		// Z VALUES
		if (maxFrame >= zTable->mScaleMaxFrame) {
			info->mScale.z = mScaleVals[zTable->mScaleMaxFrame - 1 + zTable->mScaleOffset];
		} else {
			info->mScale.z = mScaleVals[zTable->mScaleOffset + maxFrame];
		}

		if (maxFrame >= zTable->mRotationMaxFrame) {
			info->mRotation.z = mRotationVals[zTable->mRotationMaxFrame - 1 + zTable->mRotationOffset];
		} else {
			info->mRotation.z = mRotationVals[zTable->mRotationOffset + maxFrame];
		}

		if (maxFrame >= zTable->mTranslationMaxFrame) {
			info->mTranslation.z = mTranslationVals[zTable->mTranslationMaxFrame - 1 + zTable->mTranslationOffset];
		} else {
			info->mTranslation.z = mTranslationVals[zTable->mTranslationOffset + maxFrame];
		}
	}
}

void J3DAnmTransformFullWithLerp::getTransform(u16 jointNo, J3DTransformInfo* pTransform) const {


    u16 idx = jointNo * 3;
    J3DAnmTransformFullTable* entryX = &mTable[idx];
    J3DAnmTransformFullTable* entryY = &mTable[idx + 1];
    J3DAnmTransformFullTable* entryZ = &mTable[idx + 2];

    if (mCurrentFrame < 0.0f) {
        pTransform->mScale.x = mScaleVals[entryX->mScaleOffset];
        pTransform->mScale.y = mScaleVals[entryY->mScaleOffset];
        pTransform->mScale.z = mScaleVals[entryZ->mScaleOffset];

        pTransform->mRotation.x = mRotationVals[entryX->mRotationOffset];
        pTransform->mRotation.y = mRotationVals[entryY->mRotationOffset];
        pTransform->mRotation.z = mRotationVals[entryZ->mRotationOffset];

        pTransform->mTranslation.x = mTranslationVals[entryX->mTranslationOffset];
        pTransform->mTranslation.y = mTranslationVals[entryY->mTranslationOffset];
        pTransform->mTranslation.z = mTranslationVals[entryZ->mTranslationOffset];
    } else {
        u32 frame_max;
        int frame = (int)mCurrentFrame;

        if (frame == mCurrentFrame) {
            frame_max = entryX->mScaleMaxFrame;
            if (frame >= frame_max) {
                pTransform->mScale.x = mScaleVals[entryX->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.x = mScaleVals[entryX->mScaleOffset + frame];
            }

            frame_max = entryX->mRotationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mRotation.x = mRotationVals[entryX->mRotationOffset + (frame_max - 1)];
            } else {
                pTransform->mRotation.x = mRotationVals[entryX->mRotationOffset + frame];
            }

            frame_max = entryX->mTranslationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mTranslation.x = mTranslationVals[entryX->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.x = mTranslationVals[entryX->mTranslationOffset + frame];
            }

            frame_max = entryY->mScaleMaxFrame;
            if (frame >= frame_max) {
                pTransform->mScale.y = mScaleVals[entryY->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.y = mScaleVals[entryY->mScaleOffset + frame];
            }

            frame_max = entryY->mRotationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mRotation.y = mRotationVals[entryY->mRotationOffset + (frame_max - 1)];
            } else {
                pTransform->mRotation.y = mRotationVals[entryY->mRotationOffset + frame];
            }

            frame_max = entryY->mTranslationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mTranslation.y = mTranslationVals[entryY->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.y = mTranslationVals[entryY->mTranslationOffset + frame];
            }

            frame_max = entryZ->mScaleMaxFrame;
            if (frame >= frame_max) {
                pTransform->mScale.z = mScaleVals[entryZ->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.z = mScaleVals[entryZ->mScaleOffset + frame];
            }

            frame_max = entryZ->mRotationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mRotation.z = mRotationVals[entryZ->mRotationOffset + (frame_max - 1)];
            } else {
                pTransform->mRotation.z = mRotationVals[entryZ->mRotationOffset + frame];
            }

            frame_max = entryZ->mTranslationMaxFrame;
            if (frame >= frame_max) {
                pTransform->mTranslation.z = mTranslationVals[entryZ->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.z = mTranslationVals[entryZ->mTranslationOffset + frame];
            }
        } else {
            f32 rate = mCurrentFrame - frame;
            f32 var_f30 = 1.0f - rate;

            u32 next_frame = frame + 1;

            frame_max = entryX->mScaleMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mScale.x = mScaleVals[entryX->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.x = mScaleVals[entryX->mScaleOffset + frame]
                    + rate * (mScaleVals[entryX->mScaleOffset + next_frame]
                            - mScaleVals[entryX->mScaleOffset + frame]);
            }

            frame_max = entryX->mRotationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mRotation.x = mRotationVals[entryX->mRotationOffset + (frame_max - 1)];
            } else {
                u32 rot1 = (u16)mRotationVals[entryX->mRotationOffset + frame];
                u32 rot2 = (u16)mRotationVals[entryX->mRotationOffset + next_frame];
                int delta = rot2 - rot1;
                if (delta > 0x8000) {
                    rot1 += 0x10000;
                    delta -= 0x10000;
                } else if (-delta > 0x8000) {
                    delta += 0x10000;
                }
                pTransform->mRotation.x = (u32)((f32)rot1 + rate * (f32)delta);
            }

            frame_max = entryX->mTranslationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mTranslation.x = mTranslationVals[entryX->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.x = mTranslationVals[entryX->mTranslationOffset + frame]
                    + rate * (mTranslationVals[entryX->mTranslationOffset + next_frame]
                            - mTranslationVals[entryX->mTranslationOffset + frame]);
            }

            frame_max = entryY->mScaleMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mScale.y = mScaleVals[entryY->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.y = mScaleVals[entryY->mScaleOffset + frame]
                    + rate * (mScaleVals[entryY->mScaleOffset + next_frame]
                            - mScaleVals[entryY->mScaleOffset + frame]);
            }

            frame_max = entryY->mRotationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mRotation.y = mRotationVals[entryY->mRotationOffset + (frame_max - 1)];
            } else {
                u32 rot1 = (u16)mRotationVals[entryY->mRotationOffset + frame];
                u32 rot2 = (u16)mRotationVals[entryY->mRotationOffset + next_frame];
                int delta = rot2 - rot1;
                if (delta > 0x8000) {
                    rot1 += 0x10000;
                    delta -= 0x10000;
                } else if (-delta > 0x8000) {
                    delta += 0x10000;
                }
                pTransform->mRotation.y = (u32)((f32)rot1 + rate * (f32)delta);
            }

            frame_max = entryY->mTranslationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mTranslation.y = mTranslationVals[entryY->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.y = mTranslationVals[entryY->mTranslationOffset + frame]
                    + rate * (mTranslationVals[entryY->mTranslationOffset + next_frame]
                            - mTranslationVals[entryY->mTranslationOffset + frame]);
            }

            frame_max = entryZ->mScaleMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mScale.z = mScaleVals[entryZ->mScaleOffset + (frame_max - 1)];
            } else {
                pTransform->mScale.z = mScaleVals[entryZ->mScaleOffset + frame]
                    + rate * (mScaleVals[entryZ->mScaleOffset + next_frame]
                            - mScaleVals[entryZ->mScaleOffset + frame]);
            }

            frame_max = entryZ->mRotationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mRotation.z = mRotationVals[entryZ->mRotationOffset + (frame_max - 1)];
            } else {
                u32 rot1 = (u16)mRotationVals[entryZ->mRotationOffset + frame];
                u32 rot2 = (u16)mRotationVals[entryZ->mRotationOffset + next_frame];
                int delta = rot2 - rot1;
                if (delta > 0x8000) {
                    rot1 += 0x10000;
                    delta -= 0x10000;
                } else if (-delta > 0x8000) {
                    delta += 0x10000;
                }
                pTransform->mRotation.z = (u32)((f32)rot1 + rate * (f32)delta);
            }

            frame_max = entryZ->mTranslationMaxFrame;
            if (next_frame >= frame_max) {
                pTransform->mTranslation.z = mTranslationVals[entryZ->mTranslationOffset + (frame_max - 1)];
            } else {
                pTransform->mTranslation.z = mTranslationVals[entryZ->mTranslationOffset + frame]
                    + rate * (mTranslationVals[entryZ->mTranslationOffset + next_frame]
                            - mTranslationVals[entryZ->mTranslationOffset + frame]);
            }
        }
    }
}

/**
 * @note Address: 0x80067E7C
 * @note Size: 0x420
 * TODO: Needs J3DGetKeyFrameAnimation to be defined.
 */
void J3DAnmTransformKey::calcTransform(f32 p1, u16 p2, J3DTransformInfo* info) const
{
	u16 idx                       = p2 * 3;
	J3DAnmTransformKeyTable* xInf = &mTable[idx];
	J3DAnmTransformKeyTable* yInf = &mTable[idx + 1];
	J3DAnmTransformKeyTable* zInf = &mTable[idx + 2];

	switch (xInf->mScaleInfo.mMaxFrame) {
	case 0:
		info->mScale.x = 1;
		break;
	case 1:
		info->mScale.x = mScaleVals[xInf->mScaleInfo.mOffset];
		break;
	default:
		info->mScale.x = J3DGetKeyFrameInterpolation<f32>(p1, &xInf->mScaleInfo, &mScaleVals[xInf->mScaleInfo.mOffset]);
	}

	switch (yInf->mScaleInfo.mMaxFrame) {
	case 0:
		info->mScale.y = 1;
		break;
	case 1:
		info->mScale.y = mScaleVals[yInf->mScaleInfo.mOffset];
		break;
	default:
		info->mScale.y = J3DGetKeyFrameInterpolation<f32>(p1, &yInf->mScaleInfo, &mScaleVals[yInf->mScaleInfo.mOffset]);
	}

	switch (zInf->mScaleInfo.mMaxFrame) {
	case 0:
		info->mScale.z = 1;
		break;
	case 1:
		info->mScale.z = mScaleVals[zInf->mScaleInfo.mOffset];
		break;
	default:
		info->mScale.z = J3DGetKeyFrameInterpolation<f32>(p1, &zInf->mScaleInfo, &mScaleVals[zInf->mScaleInfo.mOffset]);
	}

	switch (xInf->mRotationInfo.mMaxFrame) {
	case 0:
		info->mRotation.x = 0;
		break;
	case 1:
		info->mRotation.x = mRotationVals[xInf->mRotationInfo.mOffset] << _20;
		break;
	default:
		info->mRotation.x
		    = static_cast<s32>(J3DGetKeyFrameInterpolation<s16>(p1, &xInf->mRotationInfo, &mRotationVals[xInf->mRotationInfo.mOffset]))
		   << _20;
	}

	switch (yInf->mRotationInfo.mMaxFrame) {
	case 0:
		info->mRotation.y = 0;
		break;
	case 1:
		info->mRotation.y = mRotationVals[yInf->mRotationInfo.mOffset] << _20;
		break;
	default:
		info->mRotation.y
		    = static_cast<s32>(J3DGetKeyFrameInterpolation<s16>(p1, &yInf->mRotationInfo, &mRotationVals[yInf->mRotationInfo.mOffset]))
		   << _20;
	}

	switch (zInf->mRotationInfo.mMaxFrame) {
	case 0:
		info->mRotation.z = 0;
		break;
	case 1:
		info->mRotation.z = mRotationVals[zInf->mRotationInfo.mOffset] << _20;
		break;
	default:
		info->mRotation.z
		    = static_cast<s32>(J3DGetKeyFrameInterpolation<s16>(p1, &zInf->mRotationInfo, &mRotationVals[zInf->mRotationInfo.mOffset]))
		   << _20;
	}

	switch (xInf->mTranslationInfo.mMaxFrame) {
	case 0:
		info->mTranslation.x = 0;
		break;
	case 1:
		info->mTranslation.x = mTranslationVals[xInf->mTranslationInfo.mOffset];
		break;
	default:
		info->mTranslation.x
		    = J3DGetKeyFrameInterpolation<f32>(p1, &xInf->mTranslationInfo, &mTranslationVals[xInf->mTranslationInfo.mOffset]);
	}

	switch (yInf->mTranslationInfo.mMaxFrame) {
	case 0:
		info->mTranslation.y = 0;
		break;
	case 1:
		info->mTranslation.y = mTranslationVals[yInf->mTranslationInfo.mOffset];
		break;
	default:
		info->mTranslation.y
		    = J3DGetKeyFrameInterpolation<f32>(p1, &yInf->mTranslationInfo, &mTranslationVals[yInf->mTranslationInfo.mOffset]);
	}

	switch (zInf->mTranslationInfo.mMaxFrame) {
	case 0:
		info->mTranslation.z = 0;
		break;
	case 1:
		info->mTranslation.z = mTranslationVals[zInf->mTranslationInfo.mOffset];
		break;
	default:
		info->mTranslation.z
		    = J3DGetKeyFrameInterpolation<f32>(p1, &zInf->mTranslationInfo, &mTranslationVals[zInf->mTranslationInfo.mOffset]);
	}
}

J3DAnmTextureSRTKey::J3DAnmTextureSRTKey()
{
	_0C                = 0;
	_1A                = 0;
	_18                = 0;
	_16                = 0;
	mUpdateMaterialNum = 0;
	_10                = nullptr;
	_24                = nullptr;
	_1C                = nullptr;
	_20                = nullptr;
	_48                = 0;
	_46                = 0;
	_44                = 0;
	_4A                = 0;
	_58                = nullptr;
	_54                = nullptr;
	_4C                = nullptr;
	_50                = nullptr;
	mTexMtxCalcType    = 0;
}

/**
 * @note Address: 0x8006829C
 * @note Size: 0x268
 */
void J3DAnmTextureSRTKey::calcTransform(f32 frame, u16 index, J3DTextureSRTInfo* info) const
{
	u16 idx                       = index * 3;
	J3DAnmTransformKeyTable* xInf = &_10[idx];
	J3DAnmTransformKeyTable* yInf = &_10[idx + 1];
	J3DAnmTransformKeyTable* zInf = &_10[idx + 2];

	switch (xInf->mScaleInfo.mMaxFrame) {
	case 0:
		info->mScaleX = 1;
		break;
	case 1:
		info->mScaleX = _1C[xInf->mScaleInfo.mOffset];
		break;
	default:
		info->mScaleX = J3DGetKeyFrameInterpolation<f32>(frame, &xInf->mScaleInfo, &_1C[xInf->mScaleInfo.mOffset]);
	}

	switch (yInf->mScaleInfo.mMaxFrame) {
	case 0:
		info->mScaleY = 1;
		break;
	case 1:
		info->mScaleY = _1C[yInf->mScaleInfo.mOffset];
		break;
	default:
		info->mScaleY = J3DGetKeyFrameInterpolation<f32>(frame, &yInf->mScaleInfo, &_1C[yInf->mScaleInfo.mOffset]);
	}

	switch (zInf->mRotationInfo.mMaxFrame) {
	case 0:
		info->mRotation = 0;
		break;
	case 1:
		info->mRotation = _20[zInf->mRotationInfo.mOffset] << _0C;
		break;
	default:
		info->mRotation
		    = static_cast<s32>(J3DGetKeyFrameInterpolation<s16>(frame, &zInf->mRotationInfo, &_20[zInf->mRotationInfo.mOffset]))
		   << _0C;
	}

	switch (xInf->mTranslationInfo.mMaxFrame) {
	case 0:
		info->mTranslationX = 0;
		break;
	case 1:
		info->mTranslationX = _24[xInf->mTranslationInfo.mOffset];
		break;
	default:
		info->mTranslationX
		    = J3DGetKeyFrameInterpolation<f32>(frame, &xInf->mTranslationInfo, &_24[xInf->mTranslationInfo.mOffset]);
	}

	switch (yInf->mTranslationInfo.mMaxFrame) {
	case 0:
		info->mTranslationY = 0;
		break;
	case 1:
		info->mTranslationY = _24[yInf->mTranslationInfo.mOffset];
		break;
	default:
		info->mTranslationY
		    = J3DGetKeyFrameInterpolation<f32>(frame, &yInf->mTranslationInfo, &_24[yInf->mTranslationInfo.mOffset]);
	}
}

/**
 * @note Address: 0x80068504
 * @note Size: 0x94
 */
f32 J3DAnmClusterFull::getWeight(u16 idx) const
{
	int index      = idx;
	int maxFrame   = (getFrame() + 0.5f);
	int tableFrame = mTables[index]._00[0];
	if (getFrame() < 0.0f) {
		return _0C[mTables[index]._00[1]];
	}
	if (maxFrame >= tableFrame) {
		return _0C[tableFrame - 1 + mTables[index]._00[1]];
	}

	return _0C[maxFrame + mTables[index]._00[1]];
}

/**
 * @note Address: 0x80068598
 * @note Size: 0x84
 * getWeight__16J3DAnmClusterKeyCFUs
 */
f32 J3DAnmClusterKey::getWeight(u16 idx) const
{
	switch (mTables[idx].mMaxFrame) {
	case 0:
		return 1.0f;
	case 1:
		return _0C[mTables[idx].mOffset];
	}

	return J3DGetKeyFrameInterpolation<f32>(mCurrentFrame, &mTables[idx], &_0C[mTables[idx].mOffset]);
}

J3DAnmVtxColorFull::J3DAnmVtxColorFull()
{
	mTable[0] = nullptr;
	mTable[1] = nullptr;
}

/**
 * @note Address: 0x8006861C
 * @note Size: 0x178
 */
void J3DAnmVtxColorFull::getColor(u8 col, u16 idx, GXColor* outColor) const
{
	int index                   = idx;
	J3DAnmColorFullTable* table = &mTable[col][idx];
	if (getFrame() < 0.0f) {
		outColor->r = mRedVals[table->mData[0][1]];
		outColor->g = mGreenVals[table->mData[1][1]];
		outColor->b = mBlueVals[table->mData[2][1]];
		outColor->a = mAlphaVals[table->mData[3][1]];
		return;
	}

	int maxFrame = getFrame() + 0.5f;
	int redMax   = table->mData[0][0];
	if (maxFrame >= redMax) {
		outColor->r = mRedVals[table->mData[0][1] - 1 + redMax];
	} else {
		outColor->r = mRedVals[table->mData[0][1] + maxFrame];
	}

	int greenMax = table->mData[1][0];
	if (maxFrame >= greenMax) {
		outColor->g = mGreenVals[table->mData[1][1] - 1 + greenMax];
	} else {
		outColor->g = mGreenVals[table->mData[1][1] + maxFrame];
	}

	int blueMax = table->mData[2][0];
	if (maxFrame >= blueMax) {
		outColor->b = mBlueVals[table->mData[2][1] - 1 + blueMax];
	} else {
		outColor->b = mBlueVals[table->mData[2][1] + maxFrame];
	}

	int alphaMax = table->mData[3][0];
	if (maxFrame >= alphaMax) {
		outColor->a = mAlphaVals[table->mData[3][1] - 1 + alphaMax];
	} else {
		outColor->a = mAlphaVals[table->mData[3][1] + maxFrame];
	}
}

J3DAnmVtxColorKey::J3DAnmVtxColorKey()
{
	mTable[0] = nullptr;
	mTable[1] = nullptr;
}

/**
 * @note Address: 0x80068794
 * @note Size: 0x2F4
 */
void J3DAnmVtxColorKey::getColor(u8 col, u16 idx, GXColor* outColor) const
{
	f32 frame;
	u16 index                  = idx * 3;
	J3DAnmColorKeyTable* table = &mTable[col][idx];
	switch (table->mColorInfo[0].mMaxFrame) {
	case 0:
		outColor->r = 0;
		break;
	case 1:
		outColor->r = mRedVals[table->mColorInfo[0].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[0],
		                                         &mRedVals[table->mColorInfo[0].mOffset]);
		if (frame <= 0.0f) {
			outColor->r = 0;
		} else if (frame <= 255.0f) {
			OSf32tou8(&frame, &outColor->r);
		} else {
			outColor->r = 255;
		}
	}

	switch (table->mColorInfo[1].mMaxFrame) {
	case 0:
		outColor->g = 0;
		break;
	case 1:
		outColor->g = mGreenVals[table->mColorInfo[1].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[1],
		                                         &mGreenVals[table->mColorInfo[1].mOffset]);
		if (frame <= 0.0f) {
			outColor->g = 0;
		} else if (frame <= 255.0f) {
			OSf32tou8(&frame, &outColor->g);
		} else {
			outColor->g = 255;
		}
	}

	switch (table->mColorInfo[2].mMaxFrame) {
	case 0:
		outColor->b = 0;
		break;
	case 1:
		outColor->b = mBlueVals[table->mColorInfo[2].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[2],
		                                         &mBlueVals[table->mColorInfo[2].mOffset]);
		if (frame <= 0.0f) {
			outColor->b = 0;
		} else if (frame <= 255.0f) {
			OSf32tou8(&frame, &outColor->b);
		} else {
			outColor->b = 255;
		}
	}

	switch (table->mColorInfo[3].mMaxFrame) {
	case 0:
		outColor->a = 0;
		break;
	case 1:
		outColor->a = mAlphaVals[table->mColorInfo[3].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[3],
		                                         &mAlphaVals[table->mColorInfo[3].mOffset]);
		if (frame <= 0.0f) {
			outColor->a = 0;
		} else if (frame <= 255.0f) {
			OSf32tou8(&frame, &outColor->a);
		} else {
			outColor->a = 255;
		}
	}
}

/**
 * @note Address: 0x80068A88
 * @note Size: 0xA8
 */
void J3DAnmColor::searchUpdateMaterialID(J3DModelData* data)
{
	for (u16 i = 0; i < mUpdateMaterialNum; i++) {
		JUTNameTab* matNameTable = data->mMaterialTable.mMaterialNames;
		int index                = matNameTable->getIndex(mNameTab.getName(i));
		if (index != -1) {
			mUpdateMaterialID[i] = index;
		} else {
			mUpdateMaterialID[i] = 0xFFFF;
		}
	}
}

J3DAnmColorFull::J3DAnmColorFull()
	: _2C(nullptr)
	, _30(nullptr)
	, _34(nullptr)
	, _38(nullptr)
	, mTable(nullptr)
{
}

/**
 * @note Address: 0x80068B30
 * @note Size: 0x170
 */
void J3DAnmColorFull::getColor(u16 tableIndex, GXColor* color) const
{
	J3DAnmColorFullTable* table = mTable + tableIndex;
	if (getFrame() < 0.0f) {
		color->r = _2C[table->mData[0][1]];
		color->g = _30[table->mData[1][1]];
		color->b = _34[table->mData[2][1]];
		color->a = _38[table->mData[3][1]];
		return;
	}

	int frame  = getFrame() + 0.5f;
	int redMax = table->mData[0][0];
	if (frame >= redMax) {
		color->r = _2C[table->mData[0][1] - 1 + redMax];
	} else {
		color->r = _2C[table->mData[0][1] + frame];
	}

	int greenMax = table->mData[1][0];
	if (frame >= greenMax) {
		color->g = _30[table->mData[1][1] - 1 + greenMax];
	} else {
		color->g = _30[table->mData[1][1] + frame];
	}

	int blueMax = table->mData[2][0];
	if (frame >= blueMax) {
		color->b = _34[table->mData[2][1] - 1 + blueMax];
	} else {
		color->b = _34[table->mData[2][1] + frame];
	}

	int alphaMax = table->mData[3][0];
	if (frame >= alphaMax) {
		color->a = _38[table->mData[3][1] - 1 + alphaMax];
	} else {
		color->a = _38[table->mData[3][1] + frame];
	}
}

J3DAnmColorKey::J3DAnmColorKey()
	: _2C(nullptr)
	, _30(nullptr)
	, _34(nullptr)
	, _38(nullptr)
	, mTable(nullptr)
{
}

/**
 * @note Address: 0x80068CA0
 * @note Size: 0x2CC
 */
void J3DAnmColorKey::getColor(u16 tableIndex, GXColor* outColor) const
{
	f32 frame;
	J3DAnmColorKeyTable* table = mTable + tableIndex;
	switch (table->mColorInfo[0].mMaxFrame) {
	case 0:
		outColor->r = 0;
		break;
	case 1:
		outColor->r = _2C[table->mColorInfo[0].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[0],
		                                         &_2C[table->mColorInfo[0].mOffset]);
		if (frame < 0.0f) {
			outColor->r = 0;
		} else if (frame > 255.0f) {
			outColor->r = 255;
		} else {
			OSf32tou8(&frame, &outColor->r);
		}
	}

	switch (table->mColorInfo[1].mMaxFrame) {
	case 0:
		outColor->g = 0;
		break;
	case 1:
		outColor->g = _30[table->mColorInfo[1].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[1],
		                                         &_30[table->mColorInfo[1].mOffset]);
		if (frame < 0.0f) {
			outColor->g = 0;
		} else if (frame > 255.0f) {
			outColor->g = 255;
		} else {
			OSf32tou8(&frame, &outColor->g);
		}
	}

	switch (table->mColorInfo[2].mMaxFrame) {
	case 0:
		outColor->b = 0;
		break;
	case 1:
		outColor->b = _34[table->mColorInfo[2].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[2],
		                                         &_34[table->mColorInfo[2].mOffset]);
		if (frame < 0.0f) {
			outColor->b = 0;
		} else if (frame > 255.0f) {
			outColor->b = 255;
		} else {
			OSf32tou8(&frame, &outColor->b);
		}
	}

	switch (table->mColorInfo[3].mMaxFrame) {
	case 0:
		outColor->a = 0;
		break;
	case 1:
		outColor->a = _38[table->mColorInfo[3].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mColorInfo[3],
		                                         &_38[table->mColorInfo[3].mOffset]);
		if (frame < 0.0f) {
			outColor->a = 0;
		} else if (frame > 255.0f) {
			outColor->a = 255;
		} else {
			OSf32tou8(&frame, &outColor->a);
		}
	}
}

J3DAnmTevRegKey::J3DAnmTevRegKey()
{
	mKRegUpdateMaterialNum = 0;
	mCRegUpdateMaterialNum = 0;
	_16                    = 0;
	_14                    = 0;
	_12                    = 0;
	_10                    = 0;
	_1E                    = 0;
	_1C                    = 0;
	_1A                    = 0;
	_18                    = 0;
	mKRegUpdateMaterialID  = nullptr;
	mCRegUpdateMaterialID  = nullptr;
	mCAlphaVals            = nullptr;
	mCBlueVals             = nullptr;
	mCGreenVals            = nullptr;
	mCRedVals              = nullptr;
	mKAlphaVals            = nullptr;
	mKBlueVals             = nullptr;
	mKGreenVals            = nullptr;
	mKRedVals              = nullptr;
}

J3DAnmTexPattern::J3DAnmTexPattern()
	: _0C(nullptr)
	, mAnmTable(nullptr)
	, _14(0)
	, mUpdateMaterialNum(0)
	, mUpdateMaterialID(nullptr)
{
}

/**
 * @note Address: 0x80068F6C
 * @note Size: 0xB4
 */
void J3DAnmTexPattern::getTexNo(u16 idx, u16* texNo) const
{
	int index                        = idx;
	J3DAnmTexPatternFullTable* table = mAnmTable;
	u32 maxFrame                     = table[index].mData[0][0];
	if (getFrame() < 0.0f) {
		*texNo = _0C[table[index].mData[0][1]];
		return;
	}

	if (getFrame() >= (f32)maxFrame) {
		*texNo = _0C[maxFrame - 1 + table[index].mData[0][1]];
		return;
	}

	*texNo = _0C[(int)mCurrentFrame + table[index].mData[0][1]];
}

/**
 * @note Address: 0x80069020
 * @note Size: 0x124
 */
void J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DMaterialTable* table)
{
	for (u16 i = 0; i < getUpdateMaterialNum(); i++) {
		s32 materialID = table->getMaterialName()->getIndex(_30.getName(i));
		if (materialID != -1) {
			mUpdateMaterialID[i] = materialID;
		} else {
			mUpdateMaterialID[i] = 0xFFFF;
		}
	}
	for (u16 i = 0; i < (u16)(_4A / 3); i++) {
		s32 materialID = table->getMaterialName()->getIndex(_64.getName(i));
		if (materialID != -1) {
			_60[i] = materialID;
		} else {
			_60[i] = 0xFFFF;
		}
	}
}

void J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DModelData* modelData)
{
	searchUpdateMaterialID(&modelData->getMaterialTable());
}

/**
 * @note Address: 0x80069144
 * @note Size: 0x2CC
 */
void J3DAnmTevRegKey::getTevColorReg(u16 tableIndex, _GXColorS10* outColor) const
{
	f32 frame;
	J3DAnmCRegKeyTable* table = mCRegKeyTable + tableIndex;
	switch (table->mTables[0].mMaxFrame) {
	case 0:
		outColor->r = 0;
		break;
	case 1:
		outColor->r = mCRedVals[table->mTables[0].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[0],
		                                         &mCRedVals[table->mTables[0].mOffset]);
		if (frame < -1024.0f) {
			outColor->r = -1024;
		} else if (frame > 1023.0f) {
			outColor->r = 1023;
		} else {
			OSf32tos16(&frame, &outColor->r);
		}
	}

	switch (table->mTables[1].mMaxFrame) {
	case 0:
		outColor->g = 0;
		break;
	case 1:
		outColor->g = mCGreenVals[table->mTables[1].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[1],
		                                         &mCGreenVals[table->mTables[1].mOffset]);
		if (frame < -1024.0f) {
			outColor->g = -1024;
		} else if (frame > 1023.0f) {
			outColor->g = 1023;
		} else {
			OSf32tos16(&frame, &outColor->g);
		}
	}

	switch (table->mTables[2].mMaxFrame) {
	case 0:
		outColor->b = 0;
		break;
	case 1:
		outColor->b = mCBlueVals[table->mTables[2].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[2],
		                                         &mCBlueVals[table->mTables[2].mOffset]);
		if (frame < -1024.0f) {
			outColor->b = -1024;
		} else if (frame > 1023.0f) {
			outColor->b = 1023;
		} else {
			OSf32tos16(&frame, &outColor->b);
		}
	}

	switch (table->mTables[3].mMaxFrame) {
	case 0:
		outColor->a = 0;
		break;
	case 1:
		outColor->a = mCAlphaVals[table->mTables[3].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[3],
		                                         &mCAlphaVals[table->mTables[3].mOffset]);
		if (frame < -1024.0f) {
			outColor->a = -1024;
		} else if (frame > 1023.0f) {
			outColor->a = 1023;
		} else {
			OSf32tos16(&frame, &outColor->a);
		}
	}
}

/**
 * @note Address: 0x80069410
 * @note Size: 0x2CC
 */
void J3DAnmTevRegKey::getTevKonstReg(u16 tableIndex, GXColor* outColor) const
{
	f32 frame;
	J3DAnmKRegKeyTable* table = mKRegKeyTable + tableIndex;
	switch (table->mTables[0].mMaxFrame) {
	case 0:
		outColor->r = 0;
		break;
	case 1:
		outColor->r = mKRedVals[table->mTables[0].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[0],
		                                         &mKRedVals[table->mTables[0].mOffset]);
		if (frame < 0.0f) {
			outColor->r = 0;
		} else if (frame > 255.0f) {
			outColor->r = 255;
		} else {
			OSf32tou8(&frame, &outColor->r);
		}
	}

	switch (table->mTables[1].mMaxFrame) {
	case 0:
		outColor->g = 0;
		break;
	case 1:
		outColor->g = mKGreenVals[table->mTables[1].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[1],
		                                         &mKGreenVals[table->mTables[1].mOffset]);
		if (frame < 0.0f) {
			outColor->g = 0;
		} else if (frame > 255.0f) {
			outColor->g = 255;
		} else {
			OSf32tou8(&frame, &outColor->g);
		}
	}

	switch (table->mTables[2].mMaxFrame) {
	case 0:
		outColor->b = 0;
		break;
	case 1:
		outColor->b = mKBlueVals[table->mTables[2].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[2],
		                                         &mKBlueVals[table->mTables[2].mOffset]);
		if (frame < 0.0f) {
			outColor->b = 0;
		} else if (frame > 255.0f) {
			outColor->b = 255;
		} else {
			OSf32tou8(&frame, &outColor->b);
		}
	}

	switch (table->mTables[3].mMaxFrame) {
	case 0:
		outColor->a = 0;
		break;
	case 1:
		outColor->a = mKAlphaVals[table->mTables[3].mOffset];
		break;
	default:
		frame = J3DGetKeyFrameInterpolation<s16>(mCurrentFrame, &table->mTables[3],
		                                         &mKAlphaVals[table->mTables[3].mOffset]);
		if (frame < 0.0f) {
			outColor->a = 0;
		} else if (frame > 255.0f) {
			outColor->a = 255;
		} else {
			OSf32tou8(&frame, &outColor->a);
		}
	}
}

/**
 * @note Address: 0x800696DC
 * @note Size: 0x10C
 * searchUpdateMaterialID__15J3DAnmTevRegKeyFP12J3DModelData
 */
void J3DAnmTevRegKey::searchUpdateMaterialID(J3DModelData* data)
{
	u16 i;
	for (i = 0; i < mCRegUpdateMaterialNum; i++) {
		JUTNameTab* nameTable = data->mMaterialTable.mMaterialNames;
		int index             = nameTable->getIndex(mCRegNameTable.getName(i));
		if (index != -1) {
			mCRegUpdateMaterialID[i] = index;
		} else {
			mCRegUpdateMaterialID[i] = 0xFFFF;
		}
	}
	for (i = 0; i < mKRegUpdateMaterialNum; i++) {
		JUTNameTab* nameTable = data->mMaterialTable.mMaterialNames;
		int index             = nameTable->getIndex(mKRegNameTable.getName(i));
		if (index != -1) {
			mKRegUpdateMaterialID[i] = index;
		} else {
			mKRegUpdateMaterialID[i] = 0xFFFF;
		}
	}
}

template <typename T>
inline f32 J3DHermiteInterpolation(f32, T*, T*, T*, T*, T*, T*);

template <>
inline f32 J3DHermiteInterpolation<f32>(f32 f1, f32* f2, f32* f3, f32* f4, f32* f5, f32* f6, f32* f7)
{
	return JMAHermiteInterpolation(f1, *f2, *f3, *f4, *f5, *f6, *f7);
}

template <>
inline f32 J3DHermiteInterpolation<s16>(register f32 pp1, register s16* pp2, register s16* pp3, register s16* pp4, register s16* pp5,
                                        register s16* pp6, register s16* pp7)
{
	register f32 p1 = pp1;
	register f32 ff8;
	register f32 ff7;
	register f32 ff6;
	register f32 ff5;
	register f32 ff4;
	register f32 ff3;
	register f32 ff2;
	register f32 ff0;
	register f32 fout;
	register s16* p2 = pp2;
	register s16* p3 = pp3;
	register s16* p4 = pp4;
	register s16* p5 = pp5;
	register s16* p6 = pp6;
	register s16* p7 = pp7;
#ifdef __MWERKS__ // clang-format off
	asm {
		psq_l ff2, 0(p2), 0x1, 5
		psq_l ff0, 0(p5), 0x1, 5
		psq_l ff7, 0(p3), 0x1, 5
		fsubs ff5, ff0, ff2
		psq_l ff6, 0(p6), 0x1, 5
		fsubs ff3, p1, ff2
		psq_l ff0, 0(p7), 0x1, 5
		fsubs ff4, ff6, ff7
		fdivs ff3, ff3, ff5
		psq_l fout, 0(p4), 0x1, 5
		fmadds ff0, ff0, ff5, ff7
		fmuls ff2, ff3, ff3
		fnmsubs ff4, ff5, fout, ff4
		fsubs ff0, ff0, ff6
		fsubs ff0, ff0, ff4
		fmuls ff0, ff2, ff0
		fmadds fout, ff5, fout, ff0
		fmadds fout, fout, ff3, ff7
		fmadds fout, ff4, ff2, fout
		fsubs fout, fout, ff0
	}
#endif // clang-format on
	return fout;
}

template <typename T>
f32 J3DGetKeyFrameInterpolation(f32 frame, J3DAnmKeyTableBase* table, T* values)
{
	if (frame < values[0]) {
		return values[1];
	} else {
		if (table->mType == 0) {
			if (values[(table->mMaxFrame - 1) * 3] <= frame) {
				return values[(table->mMaxFrame - 1) * 3 + 1];
			} else {
				u32 tmp = table->mMaxFrame;
				while (tmp > 1) {
					u32 halfTmp = tmp / 2;
					u32 upIdx   = halfTmp * 3;
					if (frame >= values[upIdx]) {
						values = values + upIdx;
						tmp -= halfTmp;
					} else {
						tmp = halfTmp;
					}
				}
				return J3DHermiteInterpolation<T>(frame, &values[0], &values[1], &values[2], &values[3], &values[4], &values[5]);
			}
		} else if (values[(table->mMaxFrame - 1) * 4] <= frame) {
			return values[(table->mMaxFrame - 1) * 4 + 1];
		} else {
			u32 tmp = table->mMaxFrame;
			while (tmp > 1) {
				u32 halfTmp = tmp / 2;
				u32 upIdx   = halfTmp * 4;
				if (frame >= values[upIdx]) {
					values = values + upIdx;
					tmp -= halfTmp;
				} else {
					tmp = halfTmp;
				}
			}
			return J3DHermiteInterpolation<T>(frame, &values[0], &values[1], &values[3], &values[4], &values[5], &values[6]);
		}
	}
}
