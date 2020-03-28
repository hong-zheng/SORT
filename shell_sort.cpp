#define _CRT_SRCURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void print(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ϣ������
void shellSort(int arr[], int length){
	if (NULL == arr){
		return;
	}
	if (0 == length){
		return;
	}
	// 1�����岽��,��ʼ��Ϊԭ���鳤�ȵ�һ��
	int step = length / 2;
	// 2��ѭ��������ֻҪ�����ﵽ1����˵���Ѿ��ﵽ��������׼��ÿ��һ���򣬲���/2
	while (step>=1){
		// 3����ǰ�����������Ҫ�ֵ�������������������ѭ��
		for (int k = step; k < length;k++){
			// 4��ѭ�����е�ÿһ������
			for (int i = 1; i < length;i++){
				// 5���Ƚ�������������֮��Ĵ�С
				if (arr[i] < arr[i-1]){
					int j = 0;
					// 6����¼��ǰ���ݴ�С�����ں��ڲ���
					int tmp = arr[i];
					// 7���Ը�������ݽ��в�������
					for (j = i - step; j >= 0 && arr[j] > tmp;j-=step){
						arr[j + step] = arr[j];
					}
					// 8����������
					arr[j + step] = tmp;
				}
			}
		}
		// 9���ı�step��������ÿһ�μ���һ�룬ֱ������Ϊ1
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
