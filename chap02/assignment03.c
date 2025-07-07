/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanD();
void printD(int y, int m, int d);

int main()
{
	scanD();

	return 0;
}

void scanD()
{
	int y = 0, m = 0, d = 0;

	printf("연? ");
	scanf("%d", &y);
	printf("월? ");
	scanf("%d", &m);
	printf("일? ");
	scanf("%d", &d);

	printD(y, m, d);

	return;
}

void printD(int y, int m, int d)
{
	printf("입력한 날짜는 %d년 %d월 %d일입니다.", y, m, d);

	return;
}