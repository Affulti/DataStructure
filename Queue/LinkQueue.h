//队列的链式存储结构(带头结点的单链表)
#include <malloc.h>
#define ElemType int

//--------------------------------类型描述--------------------------------

//链式队列结点
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

//链式队列
typedef struct{
    LinkNode *front, *rear; //队列的队头指针和队尾指针
}*LinkQueue;

//--------------------------------基本操作--------------------------------

//初始化
void InitQueue(LinkQueue &Q){
    //建立头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    //初始为空
    Q.front->next = NULL;
}

//判队空
bool IsEmpty(LinkQueue Q){
    if(Q->front == Q->rear){
        return true;
    }
    return false;
}

//入队
void EnQueue(LinkQueue  &Q, ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    //创建新结点，插入到链尾
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

//出队
bool (LinkQueue &Q, ElemType &x){
    //空队
    if(Q.front == Q.rear){
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    //若队列只有一个结点，则删除后变空
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
