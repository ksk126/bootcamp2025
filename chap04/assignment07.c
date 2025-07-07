/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct unit {
	int base;
	int height;
}UNIT;

UNIT scanLenth(UNIT lenth);
double computeLenth(UNIT lenth);
void printLenth(double result);

int main()
{
	UNIT lenth = { 0 };

	lenth = scanLenth(lenth);

	double result = computeLenth(lenth);

	printLenth(result);

	return 0;
}

UNIT scanLenth(UNIT lenth)
{
	printf("밑변? ");
	scanf("%d", &lenth.base);
	printf("높이? ");
	scanf("%d", &lenth.height);

	return lenth;
}

double computeLenth(UNIT lenth)
{
	double result = sqrt((lenth.base * lenth.base) + (lenth.height * lenth.height));

	return result;
}

void printLenth(double result)
{
	printf("빗변의 길이: %lf", result);

	return;
}