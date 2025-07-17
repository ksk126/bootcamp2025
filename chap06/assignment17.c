/*
* 작성자: 김수경
* 파일명: assignment17
* 작성일: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_quadrant(int x, int y);
void run_quadrant_checker();

int main()
{
	run_quadrant_checker();
	return 0;
}

int get_quadrant(int x, int y)
{
	if (x > 0 && y > 0)
		return 1;
	else if (x < 0 && y > 0)
		return 2;
	else if (x < 0 && y < 0)
		return 3;
	else if (x > 0 && y < 0)
		return 4;
	else
		return 0;
}

void run_quadrant_checker()
{
	int x, y;
	int quadrant;

	do {
		printf("점의 좌표 (x y)? ");
		scanf("%d %d", &x, &y);

		quadrant = get_quadrant(x, y);

		if (quadrant > 0)
			printf("%d사분면의 점입니다.\n", quadrant);

	} while (quadrant != 0);

	return;
}
