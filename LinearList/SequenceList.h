//顺序表: 线性表的顺序存储
//用数组来描述
#define ElemType int

//--------------------------------类型描述--------------------------------
//数组静态分配
#define MaxSize 50          //定义线性表的最大长度
typedef struct {
    ElemType data[MaxSize]; //顺序表的元素
    int length;             //顺序表的当前长度
}SqList;                    //顺序表的类型定义

//数组动态分配
#define InitSize 50     //表长度的初始定义
typedef struct {
    ElemType *data;     //指示动态分配数组的指针
    int MAXSize,length; //数组的最大容量和当前个数
}SeqList;               //动态分配数组顺序表的类型定义

//--------------------------------基本操作--------------------------------

//插入
bool ListInsert(SqList &L, int i, ElemType e){
    //判断i的范围是否有效
    if(i > L.length + 1 || i < 1){
        return false;
    }
    //当前存储空间已满，不能插入
    if(L.length >= MaxSize){
        return false;
    }
    //将i个元素及之后的元素后移
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    //再位置i处放入e
    L.data[i - 1] = e;
    //线性表长度加一
    L.length++; 
    return true;
}

//删除
bool ListDelete(SqList &L, int i, ElemType &e) {
    //判断i的范围是否有效
    if(i < 1 || i > L.length){
        return false;
    }
    //将删除的元素赋值给e
    e = L.data[i - 1]; 
    //将第i个位置后的元素前移
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    //线性表长度减1
    L.length--;
    return true;
}

//按值查找
int LocalElem(SqList &L, ElemType e){
    int i;
    for(i = 0; i < L.length; i++){
        //下标为i的元素等于e,返回其位序i+1 
        if(L.data[i] == e)
            return i+1;
    }
    //退出循环，说明查找失败
    return 0;
}