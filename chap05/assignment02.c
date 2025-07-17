/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct coord {
	int x;
	int y;
}COORD;

COORD scanCoord(COORD coord);
int computeCoord(COORD coord);
void printCoord(int result);

int main()
{
	COORD coord = { 0 };

	coord = scanCoord(coord);

	int result = computeCoord(coord);

	printCoord(result);

	return 0;
}

COORD scanCoord(COORD coord)
{
	printf("���� ��ǥ (x, y)? ");
	scanf("%d %d", &coord.x, &coord.y);

	return coord;
}

int computeCoord(COORD coord)
{
	int result = 0;

	if (coord.x > 0)
	{
		if (coord.y > 0)
		{
			result = 1;
		}

		else if (coord.y < 0)
		{
			result = 4;
		}
	}
	else if (coord.x < 0)
	{
		if (coord.y > 0)
		{
			result = 2;
		}

		else if (coord.y < 0)
		{
			result = 3;
		}
	}
	
	return result;
}

void printCoord(int result)
{
	printf("%d��и鿡 �ֽ��ϴ�.", result);

	return;
}