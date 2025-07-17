/*
* 작성자: 김수경
* 파일명: assignment05
* 작성일: 2025.07.14
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

	printf("배열:");
	for (i = 0; i < 10; i++)
	{
		printf(" %d", arr[i]);
	}

	printf("\n찾을 값? ");
	scanf("%d", &key);

	for (i = 0; i < 10; i++)
	{
		if (key == arr[i])
		{
			printf("%d는 %d번째 원소입니다.\n", key, i);
			chk = 1;
			break;
		}
	}

	if (chk == 0)
	{
		printf("찾으시는 원소가 없습니다.\n");
	}

	return;
}
