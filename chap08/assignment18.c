/*
* 작성자: 김수경
* 파일명: assignment18
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int add(int *arr, int count);
void printArr(int *arr, int size);

int main()
{
	int arr[SIZE];
	int count = 0;

	while (count < SIZE) {
		int result = add(arr, count);
		if (result >= 0) {
			printf("해당 원소가 이미 [%d]에 존재합니다.\n", result);
			printArr(arr, count);
			continue;
		}
		arr[count] = arr[SIZE];
		count++;
		printArr(arr, count);
	}

	return 0;
}

int add(int *arr, int count)
{
	int val, i;
	printf("배열에 추가할 원소? ");
	scanf("%d", &val);

	for (i = 0; i < count; i++) {
		if (arr[i] == val)
			return i;
	}

	arr[SIZE] = val;
	return -1;
}

void prinprintArrt_arr(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
