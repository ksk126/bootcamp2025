/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	double g;
	double cm3;
}UNIT;

UNIT scanUnit();
void printDensity(UNIT density);


int main()
{
	UNIT density;

	density = scanUnit();

	printDensity(density);

	return 0;
}

UNIT scanUnit()
{
	UNIT density;

	printf("질량(g)? ");
	scanf("%lf", &density.g);
	printf("부피(세제곱센티미터)? ");
	scanf("%lf", &density.cm3);

	return density;
}

void printDensity(UNIT density)
{
	double result = (density.g) / (density.cm3);
	printf("밀도: %lf", result);

	return;
}