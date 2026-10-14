// Adapted from zeldaret/tww (CC0); verified against Navi Trackers retail code.
#include "Navi/SSystem/c_tag.h"

BOOL cTg_IsUse(create_tag_class* pTag) {
    return pTag->mbIsUse;
}

BOOL cTg_SingleCutFromTree(create_tag_class* pTag) {
    if (pTag->mbIsUse == true) {
        pTag->mbIsUse = false;
        cTr_SingleCut(&pTag->mNode);
        return TRUE;
    } else {
        return FALSE;
    }
}

int cTg_AdditionToTree(node_lists_tree_class* pTree, int listIdx, create_tag_class* pTag) {
    if (!pTag->mbIsUse) {
        int ret = cTr_Addition(pTree, listIdx, &pTag->mNode);
        if (ret) {
            pTag->mbIsUse = true;
            return ret;
        }
    }
    return 0;
}

int cTg_InsertToTree(node_lists_tree_class* pTree, int listIdx, create_tag_class* pTag, int idx) {
    if (!pTag->mbIsUse) {
        int ret = cTr_Insert(pTree, listIdx, &pTag->mNode, idx);
        if (ret) {
            pTag->mbIsUse = true;
            return ret;
        }
    }
    return 0;
}

node_class* cTg_GetFirst(node_list_class* pList) {
    create_tag_class* pTag = (create_tag_class*)cLs_GetFirst(pList);
    if (pTag != NULL) {
        pTag->mbIsUse = false;
    } else {
        pTag = NULL;
    }
    // The node is the first member; preserve a null result without dereferencing it.
    return (node_class*)pTag;
}

int cTg_SingleCut(create_tag_class* pTag) {
    if (pTag->mbIsUse == 1) {
        pTag->mbIsUse = false;
        cLs_SingleCut(&pTag->mNode);
        return 1;
    }
    return 0;
}

int cTg_Addition(node_list_class* pList, create_tag_class* pTag) {
    if (!pTag->mbIsUse) {
        int ret = cLs_Addition(pList, &pTag->mNode);
        if (ret) {
            pTag->mbIsUse = true;
            return ret;
        }
    }
    return 0;
}

void cTg_Create(create_tag_class* pTag, void* pData) {
    cNd_Create(&pTag->mNode, NULL);
    pTag->mpTagData = pData;
    pTag->mbIsUse = false;
}
