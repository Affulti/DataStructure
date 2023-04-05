#include "BiTree.h"
//循环队列：队列采取顺序存储
#define MaxSize 50      //定义队列中元素的最大个数
#define ElemType BiTree

//--------------------------------类型描述--------------------------------
typedef struct{
    int front,rear;         //队头指针和队尾指针
    ElemType data[MaxSize]; //存放队列元素
}SqQueue;

//--------------------------------基本操作--------------------------------

//初始化
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

//判队满
bool IsFull(SqQueue Q){
    if((Q.rear + 1) % MaxSize == Q.front){
        return true;
    }
    return false;
}

//判队空
bool IsEmpty(SqQueue Q){
    if(Q.rear = Q.front){
        return true;
    }
    return false;
}

//入队
bool EnQueue(SqQueue &Q, ElemType x){
    //队满则报错
    if((Q.rear + 1) % MaxSize == Q.front){
        return false;
    }
    Q.data[Q.rear] = x; 
    //队尾指针加1取模
    Q.rear = (Q.rear + 1) % MaxSize;   
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &x){
    //队空则报错
    if(Q.rear == Q.front){
        return false;
    }

    x = Q.data[Q.front];
    //队头指针加1取模
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}