/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanMoney();
void printMoney(int krw, int er);

int main()
{
	scanMoney();

	return 0;
}

void scanMoney()
{
	int krw = 0, ER = 0;

	printf("KRW? ");
	scanf("%d", &krw);
	printf("원/달러 환율? ");
	scanf("%d", &ER);

	printMoney(krw, ER);

	return;
}

void printMoney(int krw, int er)
{
	printf("KRW %d = USD %.2lf", krw, (double)krw / (double)er);

	return;
}