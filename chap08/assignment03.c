/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.15
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
	printf("배열:");
	for (i = 0; i < 10; i++)
		printf(" %d ", *(fp + i));

	int *lp = &arr[9];
	printf("\n역순:");
	for (i = 0; i < 10; i++)
		printf(" %d ", *(lp - i));

	return;
}