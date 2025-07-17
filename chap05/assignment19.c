/*
* 작성자: 김수경
* 파일명: assignment19
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct movie {
	int basic;
	int audience;
	int guarantee;
}MOVIE;

MOVIE scanMovie(MOVIE m);
void printMovie(MOVIE m);

int main()
{
	MOVIE m = { 0 };

	m = scanMovie(m);
	printMovie(m);

	return 0;
}

MOVIE scanMovie(MOVIE m)
{
	printf("기본 출연료? ");
	scanf("%d", &m.basic);
	printf("손익 분기점 관객 수? ");
	scanf("%d", &m.audience);
	printf("관객 1인당 러닝 개런티? ");
	scanf("%d", &m.guarantee);

	return m;
}

void printMovie(MOVIE m)
{
	int result = 0;
	for (int i = 1000000; i < 16000000; i += 1000000)
	{
		if (i > m.audience)
			result = m.basic + (i - m.audience) * m.guarantee;
		else
			result = m.basic;
		printf("관객 %8d명 일 때 예상 출연료: %9d원\n", i, result);
	}

	return;
}