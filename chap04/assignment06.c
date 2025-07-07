/*
* 작성자: 김수경
* 파일명: assignment06
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct xy {
	int x;
	int y;
}XY;

typedef struct unit {
	XY one;
	XY two;
} UNIT;

UNIT scanCoord(UNIT coord);
double computeCoord(UNIT coord);
void printCoord(double result);

int main()
{
	UNIT coord = { 0 };

	coord = scanCoord(coord);

	double result = computeCoord(coord);

	printCoord(result);

	return 0;
}

UNIT scanCoord(UNIT coord)
{
	printf("한 점의 좌표 (x1, y1)? ");
	scanf("%d %d", &coord.one.x, &coord.one.y);
	printf("또 다른 점의 좌표(x2, y2) ? ");
	scanf("%d %d", &coord.two.x, &coord.two.y);

	return coord;
}

double computeCoord(UNIT coord)
{
	double result = (coord.two.y - coord.one.y) / (coord.two.x - coord.one.x);

	return result;
}

void printCoord(double result)
{
	printf("직선의 기울기: %lf", result);
}