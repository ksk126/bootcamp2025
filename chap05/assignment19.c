/*
* �ۼ���: �����
* ���ϸ�: assignment19
* �ۼ���: 2025.07.04
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
	printf("�⺻ �⿬��? ");
	scanf("%d", &m.basic);
	printf("���� �б��� ���� ��? ");
	scanf("%d", &m.audience);
	printf("���� 1�δ� ���� ����Ƽ? ");
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
		printf("���� %8d�� �� �� ���� �⿬��: %9d��\n", i, result);
	}

	return;
}