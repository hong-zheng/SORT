#define _CRT_SRCURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Print(int arr[], int length){
	for (int i = 0; i<length; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// 快速排序
// 单次分割，返回中间位置
int piv(int* arr, int l, int h){
	int indx = arr[l];
	while (l<h){
		while (l<h && arr[h] >= indx){
			h--;
		}
		arr[l] = arr[h];
		while (l<h && arr[l] < indx){
			l++;
		}
		arr[h] = arr[l];
	}
	arr[l] = indx;
	return l;
}
// 递归排序
void QSort(int* arr, int l, int h){
	if (l<h){
		int m = piv(arr, l, h);
		QSort(arr, l, m - 1);
		QSort(arr, m + 1, h);
	}
}
void QSORT(int* arr, int len){
	QSort(arr, 0, len - 1);
}
int main(){
	int arr1[] = { 210, 110, 1, 22, 111, 214, 56, 1332, 152, 111, 214, 56, 1332, 152, 2422, 349, 77, 78, 79, 88, 98, 111, 123, 344 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	Print(arr1, len1);
	QSORT(arr1, len1);
	Print(arr1, len1);
	system("pause");
	return 0;
}