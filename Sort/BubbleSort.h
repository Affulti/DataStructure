#define ElemType int

//--------------------------------冒泡排序--------------------------------

void BubbleSort(ElemType A[], int n){
    for(int i = 0; i < n-1; i++){
        //表示本趟排序是否发生交换的标志
        bool flag = false;
        //一趟冒泡排序
        for(int j = n - 1; j > i; j--){
            //若为逆序
            if(A[j] < A[j - 1]){
                //交换
                swap(A[j], A[j -1]);
                flag = true;
            }
        }
        //本趟遍历后没有发生交换，说明表已经有序
        if(flag == false){
            return;
        }
    }
}

//交换两个元素的值
void swap(ElemType a, ElemType b){
    ElemType temp = a;
    a = b;
    b = temp;
}