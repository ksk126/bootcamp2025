/*
* 작성자: 김수경
* 파일명: assignment06
* 작성일: 2025.07.03
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

	printf("옷 사이즈(S,M,L)? ");
	scanf("%c", &size);

	printS(size);

	return;
}

void printS(char s)
{
	printf("%c 사이즈를 선택했습니다.", s);

	return;
}