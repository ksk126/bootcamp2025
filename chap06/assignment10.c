/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.09
*/

#include <stdio.h>
#include <stdlib.h>

int random();
void printRandom(int result);

int main()
{
	int result = random();

	printRandom(result);

	return 0;
}

int random()
{
	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 5;
		printf("%d ", random);
		result += random;
	}

	return result;
}

void printRandom(int result)
{
	printf("\n�հ�: %d", result);

	return;
}