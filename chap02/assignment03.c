/*
* �ۼ���: �����
* ���ϸ�: assignment03
* �ۼ���: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanD();
void printD(int y, int m, int d);

int main()
{
	scanD();

	return 0;
}

void scanD()
{
	int y = 0, m = 0, d = 0;

	printf("��? ");
	scanf("%d", &y);
	printf("��? ");
	scanf("%d", &m);
	printf("��? ");
	scanf("%d", &d);

	printD(y, m, d);

	return;
}

void printD(int y, int m, int d)
{
	printf("�Է��� ��¥�� %d�� %d�� %d���Դϴ�.", y, m, d);

	return;
}