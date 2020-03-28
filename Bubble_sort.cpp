#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void print(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int arr[],int length){
	if (NULL == arr){
		return;
	}
	if (0 == length){
		return;
	}
	// 1、外层循环，每走一次就将数组减短，使得末尾数组不再参与比较
	for (int i = 0; i < length - 1;i++){
		// 2、内层循环，每走一次就确定数组中最后一个数
		for (int j = 0; j < length - i - 1;j++){
			//3、比较相邻两个数之间的大小，满足关系走进if
			if (arr[j+1] < arr[j]){
				// 4、定义临时变量进行交换
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main(void){
	int arr[] = { 35, 2, 4, 75, 6, 45, 34, 23, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	bubble_sort(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}
