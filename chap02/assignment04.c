/*
* �ۼ���: �����
* ���ϸ�: assignment04
* �ۼ���: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanT();
void printT(int h, int m, int s);

int main()
{
	scanT();

	return 0;
}

void scanT()
{
	int h = 0, m = 0, s = 0;

	printf("��? ");
	scanf("%d", &h);
	printf("��? ");
	scanf("%d", &m);
	printf("��? ");
	scanf("%d", &s);

	printT(h, m, s);

	return;
}

void printT(int h, int m, int s)
{
	printf("�Է��� �ð��� %02d:%02d:%02d�Դϴ�.", h, m, s);

	return;
}