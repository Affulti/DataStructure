#define ElemType int
//简单选择排序

void SelectSort(ElemType A[], int n){
    //总共进行n-1趟
    for(int i = 0; i < n - 1; i++){
        //记录最小元素位置
        int min = i;
        //在A[i...n-1]中选择最小的元素
        for(int j = i + 1; j < n; j++){
            //更新最小元素位置
            if(A[j] < A[min]){
                min = j;
            }
        }
        //封装的swap()共移动元素3次
        if( min != i){
            swap(A[min], A[i]);
        }
    }
}

//交换两个元素的值
void swap(ElemType a, ElemType b){
    ElemType temp = a;
    a = b;
    b = temp;
}

