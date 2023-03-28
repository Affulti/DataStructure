//双链表
#define ElemType int

//--------------------------------类型描述--------------------------------
typedef struct DNode {          //定义双链表结点类型
    ElemType data;              //数据域
    struct DNode *prior,*next;  //前驱和后继指针
}DNode,*DLinkList;

//--------------------------------基本操作--------------------------------