/*
* �ۼ���: �����
* ���ϸ�: assignment18
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scanFee(int time);
int computeFee(int time);
void printFee(int result);

int main()
{
	int time = 1;

	while (time != 0)
	{
		time = scanFee(time);

		int result = computeFee(time);

		printFee(result);
	}

	return 0;
}

int scanFee(int time)
{
	printf("���� �ð�(��)? ");
	scanf("%d", &time);

	while (time > 1440)
	{
		printf("���� �ð��� �ִ� 24�ð�(1440��)�� ���� �� �����ϴ�.\n");
		printf("���� �ð�(��)? ");
		scanf("%d", &time);
	}

	if (time == 0)
	{
		return 0;
	}

	return time;
}

int computeFee(int time)
{
	int fee = 0;

	if (time <= 30)
	{
		fee = 2000;
	}
	else
	{
		time -= 30;
		fee = 2000 + (time / 10) * 1000;
	}
	return fee;
}


void printFee(int result)
{
	printf("���� ���: %d��\n", result);

	return;
}