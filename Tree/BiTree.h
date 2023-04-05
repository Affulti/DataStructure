#include <stdio.h>
#include "SequenceStack.h"
#include "SequenceQueue.h"

//二叉树的链式存储结构
#define ElemType int

//访问根节点
void visit(BiTree T){
    printf("%d\n", T->data);
}

//--------------------------------类型描述--------------------------------
typedef struct BiTNode{
    ElemType data;                  //数据域
    struct BiTNode *lchild, *rchild;//左，右孩子指针
}BiTNode, *BiTree;

//--------------------------------基本操作--------------------------------

//先序遍历(递归)
void PreOrder(BiTree T){
    if(T != NULL){
        //访问根节点
        visit(T);      
        //递归遍历左子树       
        PreOrder(T->lchild);
        //递归遍历右子树
        PreOrder(T->rchild);
    }
}

//中序遍历(递归)
void InOrder(BiTree T){
    if(T != NULL){
        //递归遍历左子树 
        InOrder(T->lchild);
        //访问根节点
        visit(T);
        //递归遍历右子树        
        InOrder(T->rchild);
    }
}

//后序遍历(递归)
void PostOrder(BiTree T){
    if(T != NULL){
        //递归遍历左子树 
        PostOrder(T->lchild);
        //递归遍历右子树        
        PostOrder(T->rchild);
        //访问根节点
        visit(T);
    }
}

//先序遍历(非递归)
void PreOrder2(BiTree T){
    //初始化栈S
    SqStack S;
    InitStack(S);
    //p是遍历指针
    BiTree p = T;
    //p不空或栈不空时循环
    while(p || IsEmpty(S)){
        //一路向左
        if(p) {
            //访问当前结点，并入栈
            visit(p);
            Push(S, p);
            //左孩子不空，一直向左走
            p = p->lchild;
        }else{ //出栈，并转向出栈结点的右子树
            //栈顶元素出栈
            Pop(S, p);
            //往右子树走，p赋值为当前结点的右孩子
            p = p-> rchild;
        }
        //返回while循环继续进入if-else语句
    }
}


//中序遍历(非递归)
void InOrder2(BiTree T){
    //初始化栈S
    SqStack S;
    InitStack(S);
    //p是遍历指针
    BiTree p = T;
    //p不空或栈不空时循环
    while(p || IsEmpty(S)){
        //一路向左
        if(p) {
            //当前结点入栈
            Push(S, p);
            //左孩子不空，一直向左走
            p = p->lchild;
        }else{ //出栈，并转向出栈结点的右子树
            //栈顶元素出栈，访问出栈结点
            Pop(S, p);
            visit(p);
            //往右子树走，p赋值为当前结点的右孩子
            p = p-> rchild;
        }
        //返回while循环继续进入if-else语句
    }
}

//层序遍历
void LevelOrder(BiTree T){
    SqQueue Q;
    //初始化辅助队列
    InitQueue(Q);
    BiTree p;
    //将根节点入队
    EnQueue(Q, p);
    //队列不空则循环
    while(!IsEmpty(Q)){
        //队头结点出队
        DeQueue(Q, p);
        //访问出队结点
        visit(p);
        //左子树不空，则左子树根节点入队
        if(p->lchild != NULL){
            EnQueue(Q, p->lchild);
        }
        //右子树不空，则右子树根节点入队
        if(p->rchild != NULL){
            EnQueue(Q, p->rchild);
        }
    }
}