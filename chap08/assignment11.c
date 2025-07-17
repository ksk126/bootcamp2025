/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void rectInfo(int* w, int* h);
int input(const char* msg);

int main()
{
	int width = 0, height = 0;

	width = input("가로? ");
	height = input("세로? ");

	rectInfo(&width, &height);

	return 0;
}

int input(const char* msg)
{
	int val;
	printf("%s", msg);
	scanf("%d", &val);
	return val;
}

void rectInfo(int* w, int* h)
{
	int area = (*w) * (*h);
	int peri = (*w) * 2 + (*h) * 2;

	printf("넓이: %d, 둘레: %d\n", area, peri);
	return;
}
