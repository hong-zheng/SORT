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
void selectSort(int* arr, int length){
	for (int i = 0; i < length; i++){
		int cur = arr[i];
		int flag = -1;

		for (int j = i + 1; j < length; j++){
			if (arr[j] < cur){
				cur = arr[j];
				flag = j;
			}
		}
		if (flag >= 0){
			arr[flag] = arr[i];
			arr[i] = cur;
		}
	}
}
int main(){
	int arr1[] = { 210, 110, 1, 22, 111, 214, 56, 1332, 152, 111, 214, 56, 1332, 152, 2422, 349, 77, 78, 79, 88, 98, 111, 123, 344 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	Print(arr1, len1);
	selectSort(arr1, len1);
	Print(arr1, len1);
	system("pause");
	return 0;
}