//单链表：线性表的链式存储
#include <malloc.h>
#include <stdio.h>
#define ElemType int

//--------------------------------类型描述--------------------------------
typedef struct LNode {  //定义单链表结点类型
    ElemType data;      //数据域
    struct LNode *next; //指针域
}LNode, *LinkList;

//--------------------------------基本操作--------------------------------

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
    //逆向建立单链表
     
    LNode *s, int x;
    //创建头结点
    L = (LinkList)malloc(sizeof(LNode));
    //初始为空链表
    L->next = NULL;
    //输入结点的值
    scanf("%d", &x);
    //输入9999表示结束
    while(x != 9999){
      //创立新节点
      s = (LNode*)malloc(sizeof(LNode));
      s->data = x;
      s->next = L->next;
      //将新结点插入表中
      L->next = s;
      scanf("%d", &x);
    }
    return L;
}

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &L) { 
    //正向建立单链表

    int x;
    //创建头结点
    L = (LinkList)malloc(sizeof(LNode));
    //r为表尾指针
    LNode *s,  *r = L;
    //输入结点的值
    scanf("%d", &x);
    //输入9999表示结束
    while(x != 9999){
      //创立新节点
      s = (LNode*)malloc(sizeof(LNode));
      s->data = x;
      r->next = s;
      //r指向新的表尾结点
      r = s;
      scanf("%d", &x);
    }
    //尾结点指针为空
    r->next = NULL;
    return L;
}

//按序号查找结点
LNode *GetElem(LinkList L, int i) {
    //若i无效，则返回NULL
    if(i < 1){
        return NULL;
    }
    //第1个结点指针赋给p
    LNode *p = L->next;
    //计数，初始为1
    int j = 1;
    //从第1个结点开始找，查找第i个结点
    while(p!= NULL && j < i){
        p = p->next;
        j++;
    }
    //返回第i个结点的指针，若i大于表长，则返回NULL
    return p;
}

//按值查找表结点
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    //从第一个结点开始查找data域为e的结点
    while(p != NULL && p->data != e){
        p = p->next;
    }
    //找到后返回该结点指针，否则返回NULL
    return p;
}
