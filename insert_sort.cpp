#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void print(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void insert_sort(int arr[], int length){
	if (NULL == arr){
		printf("无该数组\n");
		return;
	}
	if (0 == length){
		printf("数组中无元素\n");
		return;
	}
	// 1、从下标为1的元素开始计数,因为比较至少得有两个数据
	for (int i = 1; i < length; i++){
		// 2、比较，如果当前数据小于前一个，则需要操作原数组
		if (arr[i] < arr[i - 1]){
			//3、记录需要操作的原数组 
			int j = 0;
			//4、记录当前元素，由于当前元素要被改动，所以需要提前记录下来
			int tmp = arr[i];
			// 5、移动当前元素的前一个元素直到有元素小于当前元素，否则就移动数组首位置处
			for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
				arr[j + 1] = arr[j];
			}
			// 6、将需要插入的元素插入数组，由于最后又将j减1，因此此处需要+1
			arr[j + 1] = tmp;
		}
	}
}
int main(void){
	int arr[] = { 35, 2, 4, 75, 6, 45, 34, 23, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	insert_sort(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}
