/*
* 작성자: 김수경
* 파일명: assignment06
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct area {
	int area;
	char c;
}AREA;

AREA scanArea(AREA area);
double computeArea(AREA area);
void printArea(double result, AREA area);

int main()
{
	AREA area = { 0 };

	area = scanArea(area);

	double result = computeArea(area);

	printArea(result, area);

	return 0;
}

AREA scanArea(AREA area)
{
	printf("넓이? ");
	scanf("%d %c", &area.area, &area.c);

	return area;
}

double computeArea(AREA area)
{
	double result = 0;

	if (area.c == 'p')
	{
		result = (double)area.area * 3.305785;

		return result;
	}
	else if (area.c == 'm')
	{
		result = (double)area.area * 0.3025;

		return result;
	}
}

void printArea(double result, AREA area)
{
	if (area.c == 'p')
	{
		printf("%.2lf 제곱미터 == %.2lf 평", (double)area.area, result);
	}
	else if (area.c == 'm')
	{
		printf("%.2lf 평 == %.2lf 제곱미터", (double)area.area, result);
	}

	return;
}