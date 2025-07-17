/*
* 작성자: 김수경
* 파일명: assignment17
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int add(int *arr, int count);

int main()
{
	int arr[SIZE];
	int count = 0;

	while (count < SIZE) {
		if (!add(arr, count))
			break;
		count++;
	}

	return 0;
}

int add(int *arr, int count)
{
	int i;

	printf("배열에 추가할 원소? ");
	scanf("%d", &arr[count]);

	for (i = 0; i <= count; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 1;
}
