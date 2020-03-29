#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
#include "MyTree.h"
using namespace std;
#define AREA 999
#define NUM 10	
void Print(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
}
#define MAX 932
//// Ͱ����
void bucket_sort(int arr[], int length){
	// ȷ���������
	for (int i = 1; i < AREA; i *= 10){
		// �����ʼ��Ͱ
		int tmp[10][NUM];
		memset(tmp, -1, sizeof(int) * 10 * NUM);

		// ���ݹ�����Ͱ
		for (int j = 0; j < length; j++){
			int m = arr[j] / i % 10;
			tmp[m][j] = arr[j];
		}

		// ��Ͱ
		int idx = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < NUM; j++){
				if (-1 != tmp[i][j]){
					arr[idx++] = tmp[i][j];
				}
			}
		}
	}
}

int main(){
	int arr[] = { 488, 7, 932, 122, 6, 38, 237, 245, 23, 67 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bucket_sort(arr, len);
	Print(arr, len);
	system("pause");
	return 0;
}