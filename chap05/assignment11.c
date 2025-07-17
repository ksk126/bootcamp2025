/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.04
*/

#include <stdio.h>

void print();

int main()
{
	print();

	return 0;
}

void print()
{
	int x = 1;

	for (int i = 0; i < 32; i++)
	{
		printf("%d번 비트만 1인인 값: %08x, %d\n", i, x, x);
		x *= 2;
	}
}