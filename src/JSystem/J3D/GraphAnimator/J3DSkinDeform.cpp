#include "types.h"
#include "JSystem/J3D/J3DVtxColorCalc.h"
#include "JSystem/J3D/J3DAnmVtxColor.h"
#include "JSystem/J3D/J3DSkinDeform.h"

/**
 * @note Address: 0x80088658
 * @note Size: 0x88
 */
void J3DSkinDeform::deform(J3DModel* model)
{
	if (model->checkFlag(J3DMODEL_SkinPosCpu)) {
		setFlag(J3DSKIN_Unk2);
	} else {
		resetFlag(J3DSKIN_Unk2);
	}

	if (model->checkFlag(J3DMODEL_SkinNrmCpu)) {
		setFlag(J3DSKIN_Unk1);
	} else {
		resetFlag(J3DSKIN_Unk1);
	}
	deform(model->getVertexBuffer(), model->mMtxBuffer);
}

/**
 * @note Address: 0x800886E0
 * @note Size: 0x30
 */
void J3DVtxColorCalc::calc(J3DModel* model)
{
	calc(model->getVertexBuffer());
}
