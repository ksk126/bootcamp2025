/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.15
*/

#include <stdio.h>

void assignment0803();

int main()
{
	assignment0803();

	return 0;
}

void assignment0803()
{
	int arr[] = { 44, 32, 65, 23, 45, 76, 77, 89, 23, 45 };
	int i;

	int *fp = &arr[0];
	printf("�迭:");
	for (i = 0; i < 10; i++)
		printf(" %d ", *(fp + i));

	int *lp = &arr[9];
	printf("\n����:");
	for (i = 0; i < 10; i++)
		printf(" %d ", *(lp - i));

	return;
}