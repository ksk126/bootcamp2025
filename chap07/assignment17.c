/*
* �ۼ���: �����
* ���ϸ�: assignment17
* �ۼ���: 2025.07.14
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
		printf("�迭�� �߰��� ����? ");
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
