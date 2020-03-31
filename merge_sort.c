#define _CRT_SRCURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Print(int arr[], int length){
	for(int i=0;i<length;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
// 合并,将左右两边 都有序的数组合并为一个全局有序的数组
void mergeSort(int* arr,int l,int m,int r){
	int len = r - l + 1;
	int* newArr = (int*)malloc(len*sizeof(int));
	int left = l;
	int right = m + 1;
	int k = 0;
	while (left <= m && right<=r){
		if (arr[left] < arr[right]){
			newArr[k++] = arr[left++];
		}
		else{
			newArr[k++] = arr[right++];
		}
	}
	while (left <= m){
		newArr[k++] = arr[left++];
	}
	while (right<=r){
		newArr[k++] = arr[right++];
	}
	memcpy(arr+l,newArr,sizeof(int)*len);
	free(newArr);
	newArr = NULL;
}
//拆分，将一个整数组拆分为两个数组，递归拆分
void chaifen(int* arr,int l,int r){
	if (l == r){
		return;
	}
	int m = l + (r - l) / 2;
	chaifen(arr, l, m);
	chaifen(arr, m+1, r);
	mergeSort(arr,l,m,r);
}
void MERGESORT(int* arr, int length){
	chaifen(arr, 0, length - 1);
}
int main(){
	int nums2[] = { 1,2,4,5,6,7};
	//int num2 = 6;
	//int nums1[] = { 1,1,2,3,0,0,0,0,0,0};
	//int num1 = 4;
	////merge(nums1, sizeof(nums1) / sizeof(nums1[0]), num1, nums2, sizeof(nums1) / sizeof(nums1[0]), num2);
	//Print(nums1, sizeof(nums1) / sizeof(nums1[0]));

	int arr[] = { 210, 110, 1,22, 111, 214, 56,1332, 152, 2422, 349 };
	int length = sizeof(arr) / sizeof(arr[0]);
	Print(arr, length);
	MERGESORT(arr, length);
	//MERGRSORT(arr,length);
	Print(arr, length);
	//int sum = 100133;
	//int count = 0;
	//for (int i = 1; i<=sum; i *= 10){
	//	count++;
	//}
	//printf("%d ",count);
	system("pause");
	return 0;
}