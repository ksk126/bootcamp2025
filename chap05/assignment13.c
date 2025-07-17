/*
* 작성자: 김수경
* 파일명: assignment13
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
	int x = 0;
	for (int i = 32; i < 127; i++)
	{
		printf("%c ", i);

		x++;
		if (x == 24)
		{
			printf("\n");
			x = 0;
		}
	}
}