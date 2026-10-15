// Adapted from zeldaret/tww (CC0); verified against Navi Trackers retail code.
#include "Navi/f_pc/f_pc_layer.h"

/* fpcLy_CancelQTo__FP24process_method_tag_class */
void fpcLy_CancelQTo(process_method_tag_class* i_methods) {
    fpcMtdTg_MethodQTo(i_methods);
}

/* fpcLy_ToCancelQ__FP11layer_classP24process_method_tag_class */
s32 fpcLy_ToCancelQ(layer_class* i_layer, process_method_tag_class* i_methods) {
    return fpcMtdTg_ToMethodQ(&i_layer->mCancelList, i_methods);
}

/* fpcLy_CancelMethod__FP24process_method_tag_class */
bool fpcLy_CancelMethod(process_method_tag_class* i_layer) {
    return fpcMtdTg_Do(i_layer) == TRUE;
}

/* fpcLy_IntoQueue__FP11layer_classiP16create_tag_classi */
s32 fpcLy_IntoQueue(layer_class* i_layer, int i_treeListNo, create_tag_class* i_createTag, int i_no) {
    return cTg_InsertToTree(&i_layer->mNodeListTree, i_treeListNo, i_createTag, i_no);
}

/* fpcLy_ToQueue__FP11layer_classiP16create_tag_class */
s32 fpcLy_ToQueue(layer_class* i_layer, int i_treeListNo, create_tag_class* i_createTag) {
    return cTg_AdditionToTree(&i_layer->mNodeListTree, i_treeListNo, i_createTag);
}

/* fpcLy_QueueTo__FP11layer_classP16create_tag_class */
s32 fpcLy_QueueTo(layer_class* i_layer, create_tag_class* i_createTag) {
    return cTg_SingleCutFromTree(i_createTag);
}

/* fpcLy_IsDeletingMesg__FP11layer_class */
BOOL fpcLy_IsDeletingMesg(layer_class* i_layer) {
    return i_layer->counts.mDeletingCount > 0;
}

/* fpcLy_DeletingMesg__FP11layer_class */
void fpcLy_DeletingMesg(layer_class* i_layer) {
    i_layer->counts.mDeletingCount++;
}

/* fpcLy_DeletedMesg__FP11layer_class */
void fpcLy_DeletedMesg(layer_class* i_layer) {
    if (i_layer->counts.mDeletingCount > 0) {
        i_layer->counts.mDeletingCount--;
    }
}

/* fpcLy_IsCreatingMesg__FP11layer_class */
BOOL fpcLy_IsCreatingMesg(layer_class* i_layer) {
    return i_layer->counts.mCreatingCount > 0;
}

/* fpcLy_CreatingMesg__FP11layer_class */
void fpcLy_CreatingMesg(layer_class* i_layer) {
    i_layer->counts.mCreatingCount++;
}

/* fpcLy_CreatedMesg__FP11layer_class */
void fpcLy_CreatedMesg(layer_class* i_layer) {
    if (i_layer->counts.mCreatingCount > 0) {
        i_layer->counts.mCreatingCount--;
    }
}

static layer_class l_fpcLy_Crear = {
    NULL, NULL, 0, 0xFFFFFFFF, NULL, 0, NULL, NULL, NULL, 0, 0, 0,
};

static node_list_class l_fpcLy_LayerList = {
    NULL,
    NULL,
    0,
};

/* fpcLy_RootLayer__Fv */
layer_class* fpcLy_RootLayer(void) {
    return (layer_class*)l_fpcLy_LayerList.mpHead;
}

static layer_class* l_fpcLy_CurrLayer_p;

/* fpcLy_SetCurrentLayer__FP11layer_class */
void fpcLy_SetCurrentLayer(layer_class* i_layer) {
    l_fpcLy_CurrLayer_p = i_layer;
}

/* fpcLy_CurrentLayer__Fv */
layer_class* fpcLy_CurrentLayer() {
    return l_fpcLy_CurrLayer_p;
}

/* fpcLy_Search__FUi */
layer_class* fpcLy_Search(uint i_layerID) {
    layer_class* layer_p = fpcLy_RootLayer();
    while (layer_p != NULL) {
        if (layer_p->mLayerID == i_layerID) {
            return layer_p;
        }
        layer_p = (layer_class*)layer_p->mNode.mpNextNode;
    }
    return NULL;
}

/* fpcLy_Layer__FUi */
layer_class* fpcLy_Layer(uint i_layerID) {
    if (i_layerID == 0 || fpcLy_RootLayer()->mLayerID == i_layerID) {
        return fpcLy_RootLayer();
    } else if (i_layerID == 0xFFFFFFFD || fpcLy_CurrentLayer()->mLayerID == i_layerID) {
        return fpcLy_CurrentLayer();
    } else {
        return fpcLy_Search(i_layerID);
    }
}

/* fpcLy_Regist__FP11layer_class */
void fpcLy_Regist(layer_class* i_layer) {
    cLs_Addition(&l_fpcLy_LayerList, (node_class*)i_layer);
}

/* fpcLy_Delete__FP11layer_class */
BOOL fpcLy_Delete(layer_class* i_layer) {
    if (i_layer->mNodeListTree.mpLists->mSize == 0 && i_layer->mCancelList.mSize == 0) {
        cLs_SingleCut((node_class*)i_layer);
        *i_layer = l_fpcLy_Crear;
        return TRUE;
    } else {
        return FALSE;
    }
}

/* fpcLy_Cancel__FP11layer_class */
BOOL fpcLy_Cancel(layer_class* i_layer) {
    return fpcMtdIt_Method(&i_layer->mCancelList, (fpcMtdIt_MethodFunc)fpcLy_CancelMethod);
}

/* fpcLy_Create__FP11layer_classPvP15node_list_classi */
void fpcLy_Create(layer_class* i_layer, void* i_node, node_list_class* i_nodeList, int i_numLists) {
    static int IsInitOfLayerList = 1;
    static int layer_id = 0;
    *i_layer = l_fpcLy_Crear;
    cNd_Create((node_class*)i_layer, NULL);
    i_layer->mLayerID = layer_id++;
    i_layer->mpPcNode = static_cast<process_node_class*>(i_node);
    if (IsInitOfLayerList == 1) {
        IsInitOfLayerList = 0;
        cLs_Create(&l_fpcLy_LayerList);
        fpcLy_SetCurrentLayer(i_layer);
    }
    i_layer->mNodeListTree.mpLists = i_nodeList;
    i_layer->mNodeListTree.mNumLists = i_numLists;
    cTr_Create(&i_layer->mNodeListTree, i_layer->mNodeListTree.mpLists, i_layer->mNodeListTree.mNumLists);
    fpcLy_Regist(i_layer);
}
