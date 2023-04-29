#include <malloc.h>
#define ElemType int
#define Length 100
//二路归并排序
int n = Length;
//辅助数组B
ElemType *B = (ElemType *)malloc((n + 1) * sizeof(ElemType));

void MergeSort(ElemType A[], int low, int high){
    if(low < high){
        //从中间划分两个子序列
        int mid = (low + high) / 2;
        //对左侧子序列进行递归排序
        MergeSort(A, low, mid);
        //对右侧子序列进行递归排序
        MergeSort(A, mid + 1, high);
        //归并
        Merge(A, low, mid, high);
    }
}

//表A的两段A[low...mid]和A[mid+1...high]各自有序，将他们合并成一个有序表
void Merge(ElemType A[], int low, int mid, int high){
    int i, j, k;
    //将A中的所有元素复制到B中
    for(k = low; k <= high; k++){
        B[k] = A[k];
    }
    for(i = low,j = mid + 1, k = i; i <= mid && j <= high; k++){
        //比较B的左右两段中的元素
        //将较小的值复制到A中
        if(B[i] <= B[j]){
            A[k] = B[i++];
        }else{
            A[k] = B[j++];
        }
    }
    //下面两个while循环实际只会执行一个
    //若第一个表未检测完，复制
    while(i <= mid){
        A[k++] = B[i++];
    }
    //若第二个表未检测完，复制
    while(j <= high){
        A[k++] = B[j++];
    }
}