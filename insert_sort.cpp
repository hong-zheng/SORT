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
		printf("�޸�����\n");
		return;
	}
	if (0 == length){
		printf("��������Ԫ��\n");
		return;
	}
	// 1�����±�Ϊ1��Ԫ�ؿ�ʼ����,��Ϊ�Ƚ����ٵ�����������
	for (int i = 1; i < length; i++){
		// 2���Ƚϣ������ǰ����С��ǰһ��������Ҫ����ԭ����
		if (arr[i] < arr[i - 1]){
			//3����¼��Ҫ������ԭ���� 
			int j = 0;
			//4����¼��ǰԪ�أ����ڵ�ǰԪ��Ҫ���Ķ���������Ҫ��ǰ��¼����
			int tmp = arr[i];
			// 5���ƶ���ǰԪ�ص�ǰһ��Ԫ��ֱ����Ԫ��С�ڵ�ǰԪ�أ�������ƶ�������λ�ô�
			for (j = i - 1; j >= 0 && arr[j] > tmp; j--){
				arr[j + 1] = arr[j];
			}
			// 6������Ҫ�����Ԫ�ز������飬��������ֽ�j��1����˴˴���Ҫ+1
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
