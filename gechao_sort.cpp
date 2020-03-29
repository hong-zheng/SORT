#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
#include "MyTree.h"
using namespace std;
void gechao_sort(int arr[], int len, int max){
	// 鸽巢排序
	// 创建临时数组存放数据,大小为(max+1)
	int* tmp = (int*)malloc((max + 1)*sizeof(int));
	memset(tmp, 0, (max + 1)*sizeof(int));
	for (int i = 0; i < len; i++){
		tmp[arr[i]]++;
	}
	// 将数组中有元素的地方的下标打印出来
	for (int i = 0; i < max + 1; i++){
		while (tmp[i]){
			printf("%d ", i);
			tmp[i]--;
		}
	}
}
// 高内聚低耦合
int main(void){
	// 不可以出现负数或者小数
	// 需要用到临时数组放元素取元素
	int arr[] = { 48, 7, 92, 1, 6, 38, 7, 2, 3, 67, 6, 51, 1, 30, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int max = arr[0];
	for (int i = 1; i < len; i++){
		if (max < arr[i]){
			max = arr[i];
		}
	}
	gechao_sort(arr, len, max);
	system("pause");
	return 0;
}