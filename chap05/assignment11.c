/*
* �ۼ���: �����
* ���ϸ�: assignment11
* �ۼ���: 2025.07.04
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
		printf("%d�� ��Ʈ�� 1���� ��: %08x, %d\n", i, x, x);
		x *= 2;
	}
}