/*
* 작성자: 김수경
* 파일명: assignment16
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	int num;
	int n;
}UNIT;

UNIT scanUnit(UNIT unit);
void printUnit(UNIT unit);

int main()
{
	UNIT unit = { 0 };

	unit = scanUnit(unit);

	printUnit(unit);

	return 0;
}

UNIT scanUnit(UNIT unit)
{
	printf("양의 정수? ");
	scanf("%d", &unit.num);
	printf("배수의 개수? ");
	scanf("%d", &unit.n);

	return unit;
}

void printUnit(UNIT unit)
{
	for (int i = 1; i <= unit.n; i++)
	{
		printf("%d ", unit.num * i);
	}

	return;
}