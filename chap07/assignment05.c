/*
* �ۼ���: �����
* ���ϸ�: assignment05
* �ۼ���: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printArray();

int main()
{
	printArray();
	return 0;
}

void printArray()
{
	int arr[10] = { 12, 34, 56, 78, 99, 26, 31, 48, 1, 35 };
	int i, key, chk = 0;

	printf("�迭:");
	for (i = 0; i < 10; i++)
	{
		printf(" %d", arr[i]);
	}

	printf("\nã�� ��? ");
	scanf("%d", &key);

	for (i = 0; i < 10; i++)
	{
		if (key == arr[i])
		{
			printf("%d�� %d��° �����Դϴ�.\n", key, i);
			chk = 1;
			break;
		}
	}

	if (chk == 0)
	{
		printf("ã���ô� ���Ұ� �����ϴ�.\n");
	}

	return;
}
