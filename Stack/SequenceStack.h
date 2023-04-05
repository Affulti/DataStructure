#include "BiTree.h"
//顺序栈：顺序存储的栈
#define ElemType BiTree

//--------------------------------类型描述--------------------------------
#define MaxSize 50          //定义栈中元素的最大个数
typedef struct {            
    ElemType data[MaxSize]; //存放栈中的元素
    int top;                //栈顶指针
}SqStack;

//--------------------------------基本操作--------------------------------

//初始化
void InitStack(SqStack &S){
    //初始化栈顶指针
    S.top = -1;
}

//栈判空
bool IsEmpty(SqStack S){
    //栈不空
    if(S.top != -1){
        return false;
    }
    //栈空
    return true;
}

//进栈
bool Push(SqStack &S, ElemType x){
    //栈满，报错
    if(S.top + 1 >= MaxSize){
        return false;
    }
    //指针先加1再入栈
    S.data[++S.top] = x;
    return true;
}

//出栈
bool Pop(SqStack &S, ElemType &x){
    //栈空，报错
    if(S.top == -1){
        return false;
    }
    //先出栈，指针再减1
    x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, ElemType &x){
    //栈空，报错
    if(S.top == -1){
        return false;
    }
    //x记录栈顶元素
    x = S.data[S.top];
    return true;
}

