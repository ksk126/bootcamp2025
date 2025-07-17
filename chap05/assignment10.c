/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct truncation {
	int money;
	int point;
}TRUNCATION;

typedef struct print {
	int result;
	int point;
}PRINT;

TRUNCATION scanTruncation(TRUNCATION t);
PRINT computeTruncation(TRUNCATION t, PRINT p);
void printTruncation(PRINT p);

int main()
{
	TRUNCATION truncation = { 0 };
	PRINT print = { 0 };

	truncation = scanTruncation(truncation);

	print = computeTruncation(truncation, print);

	printTruncation(print);

	return 0;
}

TRUNCATION scanTruncation(TRUNCATION t)
{
	printf("금액? ");
	scanf("%d", &t.money);
	printf("절사단위 (10의 지수승)? ");
	scanf("%d", &t.point);

	return t;
}

PRINT computeTruncation(TRUNCATION t, PRINT p)
{
	p.point = 10;

	for (int i = 1; i < t.point; i++)
	{
		p.point = p.point * 10;
	}

	p.result = t.money - (t.money % p.point);

	return p;
}

void printTruncation(PRINT p)
{
	printf("금액(%d 미만 절사): %d", p.point, p.result);

	return;
}