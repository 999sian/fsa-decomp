#ifndef NAVI_SSYSTEM_C_TAG_H
#define NAVI_SSYSTEM_C_TAG_H

#include "types.h"

// Wind Waker SSystem layouts, checked against Navi Trackers member accesses.
typedef struct node_class {
    struct node_class* mpPrevNode;
    void* mpData;
    struct node_class* mpNextNode;
} node_class;

typedef struct node_list_class {
    node_class* mpHead;
    node_class* mpTail;
    int mSize;
} node_list_class;

typedef struct node_lists_tree_class {
    node_list_class* mpLists;
    int mNumLists;
} node_lists_tree_class;

typedef struct create_tag_class {
    node_class mNode;
    void* mpTagData;
    s8 mbIsUse;
} create_tag_class;

void cNd_Create(node_class* pNode, void* pData);
int cLs_SingleCut(node_class* pNode);
int cLs_Addition(node_list_class* pList, node_class* pNode);
int cLs_Insert(node_list_class* pList, int idx, node_class* pNode);
node_class* cLs_GetFirst(node_list_class* pList);
void cLs_Create(node_list_class* pList);
int cTr_SingleCut(node_class* pNode);
int cTr_Addition(node_lists_tree_class* pTree, int listIdx, node_class* pNode);
int cTr_Insert(node_lists_tree_class* pTree, int listIdx, node_class* pNode, int idx);
void cTr_Create(node_lists_tree_class* pTree, node_list_class* pLists, int numLists);

BOOL cTg_IsUse(create_tag_class* pTag);
BOOL cTg_SingleCutFromTree(create_tag_class* pTag);
int cTg_AdditionToTree(node_lists_tree_class* pTree, int listIdx, create_tag_class* pTag);
int cTg_InsertToTree(node_lists_tree_class* pTree, int listIdx, create_tag_class* pTag, int idx);
node_class* cTg_GetFirst(node_list_class* pList);
int cTg_SingleCut(create_tag_class* pTag);
int cTg_Addition(node_list_class* pList, create_tag_class* pTag);
void cTg_Create(create_tag_class* pTag, void* pData);

#endif
