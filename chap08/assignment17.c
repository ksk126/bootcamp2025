/*
* �ۼ���: �����
* ���ϸ�: assignment17
* �ۼ���: 2025.07.15
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

	printf("�迭�� �߰��� ����? ");
	scanf("%d", &arr[count]);

	for (i = 0; i <= count; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 1;
}
