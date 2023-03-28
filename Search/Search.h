#define ElemType int

//--------------------------------类型描述--------------------------------
typedef struct{     //查找表的数据结构
    ElemType *elem; //元素存储空间基址，建表时按实际长度分配
    int TableLen;   //表的长度
}SSTable;

//--------------------------------查找操作--------------------------------

/**
 * name : 一般线性表的顺序查找
 * 说明： 0号位置留空
 */
int Search_Seq(SSTable ST, ElemType key){
    //"哨兵"
    ST.elem[0] = key;
    //从后往前找
    int i;
    for(i = ST.TableLen; ST.elem[i] != key; i--);
    //若表中不存在关键字为key的元素，将查找到i为0时退出for循环
    return i;
}

/**
 * name ： 折半查找 || 二分查找
 * 适用情况：升序的顺序表
 * 说明：0号位置不留空
 */
 int Binary_Search(SSTable ST, ElemType key){
    int low = 0, high = ST.TableLen - 1, mid;
    while(low <= high){
        //取中间位置
        mid = (low + high)/2;
        if(ST.elem[mid] == key){
            //查找成功则返回所在位置
            return mid;
        }else if(ST.elem[mid] > key){
            //从前半部分继续查找
            high = mid -1;
        }else{
            //从后半部分继续查找
            low = mid + 1;
        }
    }
    //查找失败，返回-1
    return -1;
 }

 