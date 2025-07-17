/*
* 작성자: 김수경
* 파일명: assignment17
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

void inputAndPrintArray(int arr[], int size);

int main()
{
	int arr[SIZE];

	inputAndPrintArray(arr, SIZE);

	return 0;
}

void inputAndPrintArray(int arr[], int size)
{
	int cnt = 0, i;

	while (cnt < size)
	{
		printf("배열에 추가할 원소? ");
		scanf("%d", &arr[cnt]);

		for (i = 0; i <= cnt; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");

		cnt++;
	}
	return;
}
