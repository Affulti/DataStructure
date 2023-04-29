#include <malloc.h>

#define ElemType int 
#define KeyType int 

//--------------------------------类型描述--------------------------------
typedef struct BSTNode{
    ElemType data;                  //数据域
    struct BSTNode *lchild, *rchild;//左，右孩子指针
}BSTNode, *BiTree;

//--------------------------------基本操作--------------------------------

//二叉排序树的查找
BSTNode *BST_Search(BiTree T, ElemType key){
    //若树空或者等于根结点值，则结束循环
    while(T != NULL && key != T->data){
        //大于，则在右子树上查找
        if(key > T->data){
            T = T->rchild;
        }else{
            //小于，则在左子树上查找
            T = T->lchild;
        }
    }
    return T;
}

/**
 * 二叉排序树的插入
 * 
 * return 1 for success.
 * return 0 for failure.
*/
int BST_Insert(BiTree &T, KeyType k){
    //原树为空，新插入的记录为根节点
    if(T == NULL){
        T = (BiTree)malloc(sizeof(BSTNode));
        T->data = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(k == T->data){
        //如果树中存在相同关键字的结点，插入失败
        return 0;
    }else if(k < T->data){
        //如果小于树中关键字，则插入到树T的左子树
        return BST_Insert(T->lchild, k);
    }else{
        //如果大于树中关键字，则插入到树T的右子树
        return BST_Insert(T->rchild, k);
    }
}

//二叉排序树的构造
void Create_BST(BiTree &T, KeyType str[], int n){
    //初始时T为空树
    T = NULL;
    int i = 0;
    //依次将每个关键字插入到二叉树中
    while(i < n){
        BST_Insert(T, str[i]);
        i++;
    }
}
