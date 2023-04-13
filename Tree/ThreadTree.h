//线索二叉树
#include <stdio.h>
#define ElemType int

//访问根节点
void visit(ThreadTree T){
    printf("%d\n", T->data);
}

//--------------------------------类型描述--------------------------------
typedef struct ThreadNode{
    ElemType data;                      //数据元素
    struct ThreadNode *lchild, *rchild; //左，右孩子指针
    int ltag, rtag;                     //左，右线索标志(0: 孩子；1：前驱或后继)
}ThreadNode, *ThreadTree;

//--------------------------------基本操作--------------------------------

//通过中序遍历建立中序线索二叉树
void CreateInThread(ThreadTree T){
    ThreadTree pre = nullptr;
    //非空二叉树，线索化
    if(T != nullptr){
        //线索化二叉树
        InThread(T, pre);
        //处理遍历的最后一个结点
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}
//通过中序遍历对二叉树线索化
void InThread(ThreadTree &p, ThreadTree &pre){
    //pre指向p的前驱
    if(p != nullptr){
        //递归，线索化左子树
        InThread(p->lchild, pre);
        //左子树为空，建立前驱线索
        if(p->lchild == nullptr){
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != nullptr && pre->rchild == nullptr){
            //建立前驱结点的后继线索
            pre->rchild = p;
            pre->rtag =  1;
        }
        //标记当前结点成为刚刚访问过的结点
        pre = p;
        //递归， 线索化右子树
        InThread(p->rchild, pre);
    }
}

//中序线索二叉树中中序序列的第一个结点
ThreadNode *FirstNode(ThreadNode *p){
    while(p->ltag == 0){
        //最左下结点(不一定是叶结点)
        p = p->lchild;
    }
    return p;
}

//中序线索二叉树中结点p在中序序列中的后继
ThreadNode *NextNode(ThreadNode *p){
    if(p->rtag == 0){
        return FirstNode(p->rchild);
    }else{
        //rtag == 1 直接返回后继线索
        return p->rchild;
    }
}

//中序线索二叉树的中序遍历
void Inorder(ThreadNode *T){
    for(ThreadNode *p = FirstNode(T); p != nullptr; p = NextNode(p)){
        visit(p);
    }
}