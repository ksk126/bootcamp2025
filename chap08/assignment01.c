/*
* 작성자: 김수경
* 파일명: assignment01
* 작성일: 2025.07.15
*/

#include <stdio.h>

void assignment0801();

int main()
{
	assignment0801();
	
	return 0;
}

void assignment0801()
{
	double x[3];
	double* q = x;

	int i;
	for (i = 0; i < 3; i++)
		printf("x[%d]의 주소: %X\n", i, q + i);

	return;
}