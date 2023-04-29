#define ElemType int

//--------------------------------直接插入排序--------------------------------

void DirectInsertSort(ElemType A[], int n){
    int i,j;
    //依次将A[2] ~ A[n]插入到前面已排序序列
    for(i = 2; i < n; i++){ 
        //若A[i] 关键字小于其前驱，则将A[i]插入有序序列    
        if(A[i] < A[i - 1]){   
            //复制为哨兵，A[0]不存放元素 
            A[0] = A[i];   
            //从后往前查找待插入位置     
            for(j = i - 1; A[0] < A[j]; j--){ 
                //往后移位  
                A[j + 1] = A[j];  
            }
            //复制到插入位置
            A[j + 1] = A[0];    
        }
    }
}

//--------------------------------直接插入排序--------------------------------

void HalfInsertSort(ElemType A[], int n){
    int i, j, low, high, mid;
    //依次将A[2] ~ A[n]插入到前面已排序序列
    for(i = 2; i <= n; i++){
        //将A[i] 暂存到A[0]
        A[0] = A[i];
        //设置折半查找的范围
        low = 1;high = i - 1;
        //折半查找(默认递增有序)
        while(low <= high){
            //取中间点
            mid = (low + high) / 2;
            if(A[mid] > A[0]){
                //查找左半子表
                high = mid -1;
            }else{
                //查找右半子表
                low = mid + 1;
            }
        }
        //统一后移元素，空出插入位置
        for(j = i - 1; j >= high + 1; j--){
            A[j + 1] = A[j];
        }
        //插入操作
        A[high + 1] = A[0];
    }
}

//--------------------------------直接插入排序--------------------------------

void ShellSort(ElemType A[], int n){
    //A[0]只是暂存单元，不是哨兵，当j <= 0时，插入位置已到
    int dk, i, j;
    //增量变化(无统一规定)
    for(dk = n / 2; dk >= 1; dk = dk / 2){
        for(i = dk + 1; i <= n; i++){
            if(A[i] < A[i -dk]){
                //暂存在A[0]
                A[0] = A[i];
                for(j = i -dk; j >0 && A[0] < A[j]; j -= dk){
                    //记录后移，查找插入的位置
                    A[j + dk] = A[j];
                }
                //插入
                A[j + dk] = A[0];
            }
        }
    }
}