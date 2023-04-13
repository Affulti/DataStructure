//--------------------------------并查集--------------------------------

//结构定义
#define SIZE 100
int UFSets[SIZE];   //集合元素数组(双亲指针数组)

//初始化操作
void Initial(int S[]){
    //每个自成单元素集合
    for(int i = 0; i < SIZE; i++){
        S[i] = -1;  
    }
}

//查找集合S中单元素x所在的子集和，并返回该子集和的根节点
int Find(int S[], int x){
    //循环寻找x的根
    while(S[x] > 0){
        x = S[x];
    }
    //根的S[]小于0
    return x;
}


//把集合S中的子集和Root2并入子集和Root1,要求Root1和Root2互不相交，否则不执行合并
void Union(int S[], int Root1, int Root2){
    //要求Root1 和Root2 是不同的集合
    if(Root1 == Root2){
        return;
    }
    //将根Root2连接到另一根Root1下面
    S[Root2] = Root1;
}