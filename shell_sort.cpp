#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void print(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//希尔排序
void shellSort(int arr[], int length){
	if (NULL == arr){
		return;
	}
	if (0 == length){
		return;
	}
	// 1、定义步长,初始化为原数组长度的一半
	int step = length / 2;
	// 2、循环步长，只要步长达到1，就说明已经达到最后排序标准，每排一次序，步长/2
	while (step>=1){
		// 3、当前步长情况下需要分的组数，根据组数进行循环
		for (int k = step; k < length;k++){
			// 4、循环其中的每一个数据
			for (int i = 1; i < length;i++){
				// 5、比较相邻两个数据之间的大小
				if (arr[i] < arr[i-1]){
					int j = 0;
					// 6、记录当前数据大小，便于后期插入
					int tmp = arr[i];
					// 7、对改组的数据进行插入排序
					for (j = i - step; j >= 0 && arr[j] > tmp;j-=step){
						arr[j + step] = arr[j];
					}
					// 8、插入数据
					arr[j + step] = tmp;
				}
			}
		}
		// 9、改变step，步长，每一次减少一半，直到步长为1
		step /= 2;
	}
}
int main(void){
	int arr[] = { 35, 2, 4, 75, 6, 45, 34, 23, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	shellSort(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}
