/*
* �ۼ���: �����
* ���ϸ�: assignment06
* �ۼ���: 2025.07.03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void scanS();
void printS(char s);

int main()
{
	scanS();

	return 0;
}

void scanS()
{
	char size = 0;

	printf("�� ������(S,M,L)? ");
	scanf("%c", &size);

	printS(size);

	return;
}

void printS(char s)
{
	printf("%c ����� �����߽��ϴ�.", s);

	return;
}