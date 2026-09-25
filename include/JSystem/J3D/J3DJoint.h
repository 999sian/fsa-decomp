#ifndef _JSYSTEM_J3D_J3DJOINT_H
#define _JSYSTEM_J3D_J3DJOINT_H

#include "JSystem/J3D/J3DTypes.h"
#include "JSystem/JGeometry.h"
#include "JSystem/JMath/JMath.h"
#include "types.h"

struct J3DMaterial;
struct J3DMtxCalc;
struct J3DMtxCalcAnmBase;
struct J3DJoint;

typedef bool (*J3DJointCallBack)(J3DJoint*, int);

struct J3DJoint {
    enum J3DJointKind {
        JOINTKIND_Unk1 = 0x1,
        JOINTKIND_Unk2 = 0x2,
        JOINTKIND_Unk3 = 0x4,
        JOINTKIND_Unk4 = 0x8,
        JOINTKIND_Unk5 = 0x10,
        JOINTKIND_Unk6 = 0x20,
    };

    J3DJoint();

    void appendChild(J3DJoint*);
    void entryIn();
    void recursiveCalc();
    u8 getKind() const { return mKind & 0x0F; }
    u8 getMtxType() const { return (u8)mKind >> 4; }
    void setMtxType(u8 type) { mKind = (mKind & ~0xF0) | (type << 4); }
    void resetMtxType() { mKind &= 0x0F; }
    u16 getJntNo() const { return mJointIdx; }
    f32 getRadius() const { return mRadius; }
    J3DJoint* getYounger() { return mParent; }
    J3DJoint* getChild() { return mChild; }
    J3DMaterial* getMesh() { return mMaterial; }
    u8 getScaleCompensate() const { return mIgnoreParentScaling; }
    J3DTransformInfo& getTransformInfo() { return mTransformInfo; }
    Vec* getMax() { return &mMax; }
    Vec* getMin() { return &mMin; }

    void setYounger(J3DJoint* parent) { mParent = parent; }
    void setCallBack(J3DJointCallBack callback) { mFunction = callback; }
    void setMtxCalc(J3DMtxCalc* i_mtxCalc) { mMtxCalc = i_mtxCalc; }
    void setCurrentMtxCalc(J3DMtxCalc* calc) { mCurrentMtxCalc = calc; }

    

    static J3DMtxCalc* mCurrentMtxCalc;

    u32 mCallBackUserData;           // _00
    J3DJointCallBack mFunction;      // _04
    u32 _08;                         // _08
    J3DJoint* mChild;                // _0C
    J3DJoint* mParent;               // _10
    u16 mJointIdx;                   // _14
    s8 mKind;                        // _16, high nibble = mtx type
    u8 mIgnoreParentScaling;         // _17
    J3DTransformInfo mTransformInfo; // _18
    f32 mRadius;                     // _38, bounding sphere radius
    Vec mMin;                        // _3C
    Vec mMax;                        // _48
    J3DMtxCalc* mMtxCalc;            // _54
    J3DMaterial* mMaterial;          // _58
};

#endif
