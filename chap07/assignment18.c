/*
* �ۼ���: �����
* ���ϸ�: assignment18
* �ۼ���: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int checkOverlap(int arr[], int length);
void printArray(int arr[], int size);
void inputUniqueArray(int arr[], int size);

int main()
{
	int arr[SIZE];

	inputUniqueArray(arr, SIZE);

	return 0;
}

int checkOverlap(int arr[], int length)
{
	int i, j;
	for (i = 0; i <= length; i++)
	{
		for (j = i + 1; j <= length; j++)
		{
			if (arr[i] == arr[j])
			{
				return i;
			}
		}
	}
	return -1;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void inputUniqueArray(int arr[], int size)
{
	int i = 0, j, chk;

	while (i < size)
	{
		printf("�迭�� �߰��� ����? ");
		scanf("%d", &arr[i]);

		chk = checkOverlap(arr, i);
		if (chk != -1)
		{
			printf("�ش� ���Ұ� �̹� [%d]�� �����մϴ�.\n", chk);
			printArray(arr, i);
			continue;
		}

		printArray(arr, i + 1);
		i++;
	}
	return;
}
