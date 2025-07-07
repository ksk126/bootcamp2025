/*
* 작성자: 김수경
* 파일명: assignment13
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct xy {
	int x;
	int y;
}XY;

typedef struct distance {
	XY start;
	XY end;
} DISTANCE;

DISTANCE scanCoord(DISTANCE coord);
double computeCoord(DISTANCE coord);
void printCoord(double result);

int main()
{
	DISTANCE coord = { 0 };

	coord = scanCoord(coord);

	double result = computeCoord(coord);

	printCoord(result);

	return 0;
}

DISTANCE scanCoord(DISTANCE coord)
{
	printf("직선의 시작점 (x1, y1)? ");
	scanf("%d %d", &coord.start.x, &coord.start.y);

	printf("직선의 끝점 (x2, y2)? ");
	scanf("%d %d", &coord.end.x, &coord.end.y);

	return coord;
}

double computeCoord(DISTANCE coord)
{
	double result = sqrt(((coord.end.x - coord.start.x) * (coord.end.x - coord.start.x) + (coord.end.y - coord.start.y) * (coord.end.y - coord.start.y)));

	return result;
}

void printCoord(double result)
{
	printf("직선의 길이: %lf", result);
}