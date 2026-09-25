#include "JSystem/J3D/J3DSkinDeform.h"
#include "JSystem/J3D/J3DAnmCluster.h"
#include "JSystem/JMath/JMath.h"
#include "dolphin/os.h"
#include "dolphin/base/PPCArch.h"

// JMath::acosDegree (inlined from JMATrigonometric.h)
static inline f32 J3DAcosDegree(f32 value)
{
	f32 angle;
	if (value >= 1.0f) {
		angle = 0.0f;
	} else if (value <= -1.0f) {
		angle = JMath::TAngleConstant_<f32>::RADIAN_DEG180();
	} else if (value < 0.0f) {
		value = -value;
		angle = JMath::asinAcosTable_.mTable[(u32)(value * (1024 - 0.5f))] + JMath::TAngleConstant_<f32>::RADIAN_DEG090();
	} else {
		angle = JMath::TAngleConstant_<f32>::RADIAN_DEG090() - JMath::asinAcosTable_.mTable[(u32)(value * (1024 - 0.5f))];
	}
	return angle * JMath::TAngleConstant_<f32>::RADIAN_TO_DEGREE_FACTOR();
}

/**
 * @note Address: 0x8006A59C
 * @note Size: 0x24
 */
void J3DDeformData::deform(J3DModel* model)
{
	deform(model->getVertexBuffer());
}

/**
 * @note Address: 0x8006A5C0
 * @note Size: 0xD4
 */
void J3DDeformData::deform(J3DVertexBuffer* vtxbuffer)
{
	// Swap vtxbuffer positions
	vtxbuffer->swapVtxPosArrayPointer();
	vtxbuffer->swapVtxNrmArrayPointer();

	for (u16 i = 0; i < mClusterNum; i++) {
		mClusterPointer[i].getDeformer()->deform(vtxbuffer, i);
	}

	DCStoreRangeNoSync(vtxbuffer->getVtxPosArrayPointer(0), vtxbuffer->getVertexData()->getVtxNum() * 12);
	DCStoreRangeNoSync(vtxbuffer->getVtxNrmArrayPointer(0), vtxbuffer->getVertexData()->getNrmNum() * 12);
	PPCSync();

	vtxbuffer->setCurrentVtxPos(vtxbuffer->getVtxPosArrayPointer(0));
	vtxbuffer->setCurrentVtxNrm(vtxbuffer->getVtxNrmArrayPointer(0));
}

/**
 * @note Address: 0x8006A694
 * @note Size: 0x168
 */
void J3DDeformer::deform(J3DVertexBuffer* vtxbuffer, u16 index)
{
	u16 size = 0;
	if (mAnmCluster) {
		for (u16 i = 0; i < index; i++) {
			size += mDeformData->getClusterPointer(i)->mKeyNum;
		}

		u16 max = mDeformData->getClusterPointer(index)->mKeyNum;
		for (u16 i = 0; i < max; i++) {
			mWeightList[i] = mAnmCluster->getWeight(size++);
		}
		deform(vtxbuffer, index, mWeightList);
	}
}

/**
 * @note Address: 0x8006A7FC
 * @note Size: 0x26C
 */
void J3DDeformer::deform_VtxPosF32(J3DVertexBuffer* i_buffer, J3DCluster* i_cluster, J3DClusterKey* i_key, f32* i_weights)
{
	J3DClusterKey* key;
	int posNum        = i_cluster->mPosNum;
	int keyNum        = i_cluster->mKeyNum;
	f32* vtxPosArray  = (f32*)i_buffer->getVtxPosArrayPointer(0);
	f32* deformVtxPos = mDeformData->getVtxPos();
	u16* posDstIdx    = i_cluster->mPosDstIdx;

	for (int i = 0; i < posNum; i++) {
		int index              = posDstIdx[i] * 3;
		vtxPosArray[index]     = 0.0f;
		vtxPosArray[index + 1] = 0.0f;
		vtxPosArray[index + 2] = 0.0f;
	}

	f32 sign[2] = { 1.0f, -1.0f };

	for (u16 i = 0; i < posNum; i++) {
		int index = i_cluster->mPosDstIdx[i] * 3;
		for (u16 j = 0; j < keyNum; j++) {
			int flag;
			int vtx;
			key  = &i_key[j];
			flag = vtx = key->mPosFlag[i];
			vtx &= ~0xE000;
			vtx *= 3;
			f32 deform0 = deformVtxPos[vtx];
			f32 deform1 = deformVtxPos[vtx + 1];
			f32 deform2 = deformVtxPos[vtx + 2];
			deform0 *= sign[((flag & 0x8000) >> 0xF)];
			deform1 *= sign[((flag & 0x4000) >> 0xE)];
			deform2 *= sign[((flag & 0x2000) >> 0xD)];
			vtxPosArray[index] += deform0 * i_weights[j];
			vtxPosArray[index + 1] += deform1 * i_weights[j];
			vtxPosArray[index + 2] += deform2 * i_weights[j];
		}
	}
}

/**
 * @note Address: 0x8006AA68
 * @note Size: 0x470
 */
void J3DDeformer::deform_VtxNrmF32(J3DVertexBuffer* i_buffer, J3DCluster* i_cluster, J3DClusterKey* i_key, f32* i_weights)
{
	f32* vtxNrmArray  = (f32*)i_buffer->getVtxNrmArrayPointer(0);
	f32* deformVtxNrm = mDeformData->getVtxNrm();
	f32* nrm          = mDeformedNrm;
	u16 keyNum        = i_cluster->mKeyNum;
	int vtxNum        = i_cluster->mClusterVertexNum;

	for (u16 i = 0; i < i_cluster->mNrmNum; i++) {
		int index      = i * 3;
		nrm[index]     = 0.0f;
		nrm[index + 1] = 0.0f;
		nrm[index + 2] = 0.0f;
		for (u16 j = 0; j < keyNum; j++) {
			J3DClusterKey* key = &i_key[j];
			int vtx            = key->mNrmFlag[i];
			int flag           = vtx;
			vtx &= ~0xE000;
			vtx *= 3;
			Vec deform0;
			if (flag & 0x8000) {
				deform0.x = -deformVtxNrm[vtx];
			} else {
				deform0.x = deformVtxNrm[vtx];
			}
			if (flag & 0x4000) {
				deform0.y = -deformVtxNrm[vtx + 1];
			} else {
				deform0.y = deformVtxNrm[vtx + 1];
			}
			if (flag & 0x2000) {
				deform0.z = -deformVtxNrm[vtx + 2];
			} else {
				deform0.z = deformVtxNrm[vtx + 2];
			}
			nrm[index] += deform0.x * i_weights[j];
			nrm[index + 1] += deform0.y * i_weights[j];
			nrm[index + 2] += deform0.z * i_weights[j];
		}
		normalize(&nrm[index]);
	}

	for (u16 i = 0; i < vtxNum; i++) {
		J3DClusterVertex* clusterVtx = &i_cluster->mClusterVertex[i];
		Vec vec;
		vec.x     = 0.0f;
		vec.y     = 0.0f;
		vec.z     = 0.0f;
		f32 scale = 1.0f / clusterVtx->mNum;
		for (u16 j = 0; j < clusterVtx->mNum; j++) {
			int index = clusterVtx->mSrcIdx[j] * 3;
			vec.x += scale * nrm[index];
			vec.y += scale * nrm[index + 1];
			vec.z += scale * nrm[index + 2];
		}
		normalize((f32*)&vec);

		for (u16 j = 0; j < clusterVtx->mNum; j++) {
			u16 dst = clusterVtx->mDstIdx[j];
			if (dst == 0xffff) {
				continue;
			}
			int index  = dst * 3;
			u16 src    = clusterVtx->mSrcIdx[j];
			int index2 = src * 3;

			f32 dot = vec.x * nrm[index2] + vec.y * nrm[index2 + 1] + vec.z * nrm[index2 + 2];
			f32 angle;
			if (dot >= 1.0f) {
				angle = 0.0f;
			} else if (dot > -1.0f) {
				angle = J3DAcosDegree(dot);
			} else {
				angle = 180.0f;
			}

			if (angle <= i_cluster->mMinAngle) {
				vtxNrmArray[index]     = vec.x;
				vtxNrmArray[index + 1] = vec.y;
				vtxNrmArray[index + 2] = vec.z;
			} else if (angle > i_cluster->mMaxAngle) {
				vtxNrmArray[index]     = nrm[src * 3];
				vtxNrmArray[index + 1] = nrm[src * 3 + 1];
				vtxNrmArray[index + 2] = nrm[src * 3 + 2];
			} else {
				f32 weights[2];
				weights[0]             = (angle - i_cluster->mMinAngle) / (i_cluster->mMaxAngle - i_cluster->mMinAngle);
				weights[1]             = 1.0f - weights[0];
				vtxNrmArray[index]     = weights[0] * nrm[index2] + weights[1] * vec.x;
				vtxNrmArray[index + 1] = weights[0] * nrm[index2 + 1] + weights[1] * vec.y;
				vtxNrmArray[index + 2] = weights[0] * nrm[index2 + 2] + weights[1] * vec.z;
			}
		}
	}
}

/**
 * @note Address: 0x8006AED8
 * @note Size: 0x1CC
 */
void J3DDeformer::deform(J3DVertexBuffer* vtxbuffer, u16 index, f32* weights)
{
	if (checkFlag(2) && vtxbuffer->getVertexData()->getVtxPosType() == GX_F32) {

		J3DCluster* cluster = mDeformData->getClusterPointer(index);

		u16 size = 0;
		for (u16 i = 0; i < index; i++) {
			size += mDeformData->getClusterPointer(i)->mKeyNum + 1;
		}

		J3DClusterKey* key = mDeformData->getClusterKeyPointer(size);
		normalizeWeight(cluster->mKeyNum, weights);
		deform_VtxPosF32(vtxbuffer, cluster, key, weights);
		if (checkFlag(1) && cluster->mFlags && vtxbuffer->getVertexData()->getVtxNrmType() == GX_F32) {
			deform_VtxNrmF32(vtxbuffer, cluster, key, weights);
		}
	}
}

/**
 * @note Address: 0x8006B0A4
 * @note Size: 0x15C
 */
void J3DDeformer::normalizeWeight(int count, f32* weights)
{
	f32 total = 0.0f;
	for (u16 i = 0; i < count; i++) {
		total += weights[i];
	}
	total = 1.0f / total;

	for (u16 i = 0; i < count; i++) {
		weights[i] *= total;
	}
}
