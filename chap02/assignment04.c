/*
* 작성자: 김수경
* 파일명: assignment04
* 작성일: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanT();
void printT(int h, int m, int s);

int main()
{
	scanT();

	return 0;
}

void scanT()
{
	int h = 0, m = 0, s = 0;

	printf("시? ");
	scanf("%d", &h);
	printf("분? ");
	scanf("%d", &m);
	printf("초? ");
	scanf("%d", &s);

	printT(h, m, s);

	return;
}

void printT(int h, int m, int s)
{
	printf("입력한 시간은 %02d:%02d:%02d입니다.", h, m, s);

	return;
}