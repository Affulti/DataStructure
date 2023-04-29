#include <stdio.h>
#define ElemType int

//堆排序
void HeapSort(ElemType A[], int len){
    //初建始堆
    BuildMaxHeap(A, len);
    //n-1趟的建堆和交换过程
    for(int i = len; i > 1; i--){
        //输出堆顶元素(并和堆底元素交换)
        visit(A[i]);
        swap(A[i], A[1]);
        //调整，把剩下的i-1个元素调整成大根堆
        HeadAdjust(A, i, len);
    }
}

//建立大根堆
void BuildMaxHeap(ElemType A[], int len){
    //从i = n/2 ~ 1反复调整堆
    for(int i = len / 2; i > 0; i--){
        HeadAdjust(A, i, len);
    }
}

//HeadAdjust将元素k为根的子树进行调整
void HeadAdjust(ElemType A[], int k, int len){
    //A[0]暂存子树的根节点
    A[0] = A[k];
    //沿k较大的子结点开始筛选
    for(int i = k * 2; i <= len; i *= 2){
        if(i < len && A[i] < A[i + 1]){
            i++;
        }
        //取k较大的子结点的下标i
        if(A[0] >= A[i]){
            break;
        }else{
            //将A[i]调整到双亲结点上
            A[k] = A[i];
            //修改k值，以便继续向下筛选(此操作打乱了根结点为A[i]的子树，则需要迭代地将A[i]所在的子树调整为大根堆)
            k = i;
        }
    }
    //被筛选结点的值放到最终位置
    A[k] = A[0];
}

//交换两个元素的值
void swap(ElemType a, ElemType b){
    ElemType temp = a;
    a = b;
    b = temp;
}

//输出结点
void visit(int a){
    printf("%d\n", a);
}
