/*
* �ۼ���: �����
* ���ϸ�: assignment01
* �ۼ���: 2025.07.15
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
		printf("x[%d]�� �ּ�: %X\n", i, q + i);

	return;
}