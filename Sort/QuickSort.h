#define ElemType int

//--------------------------------快速排序--------------------------------
//基于分治法
//low 数组的下标; high 数组的上标
// 
void QuickSort(ElemType a[], int low, int high){
	//递归跳出的条件
	if (low < high) {  
		//划分
		int pivotPos = partition(a,low,high); 
		//依次对两个子表进行递归的排序
		QuickSort(a,low, pivotPos-1); 
		QuickSort(a,pivotPos+1, high); 	
	} 

	
} 

//一趟划分
int partition(ElemType a[],int low, int high) { 
	//将当前数组中的第一个元素设置为枢轴，对数组进行划分
	int pivot = a[low];   
	 while(low < high) {
	 	while(low < high && pivot <= a[high]) {
	 		high--; 
		}
		//将比枢轴小的元素移到左边
		a[low] = a[high]; 
		while(low < high && pivot >= a[low]) {
			low++;
		}
		//将比枢轴大的元素移到右边
		a[high] = a[low]; 
	 } 
	//此时low == high 
	//枢轴元素存放到最终位置
	a[low] = pivot; 
	//返回枢轴元素的下标位置
	return low; 
}
