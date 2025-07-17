/*
* �ۼ���: �����
* ���ϸ�: assignment07
* �ۼ���: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scan_prime();
int is_prime(int n);
void print_prime(int result);

int main()
{
	int n = scan_prime();

	int result = is_prime(n);

	print_prime(result);

	return 0;
}

int scan_prime()
{
	int n;

	printf("1~N������ �Ҽ��� ���մϴ�. N��? ");
	scanf("%d", &n);

	return n;
}

//prime�� 1 �̻��̸� �Ҽ�, 0�̸� �ƴ�.
int is_prime(int n)
{
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		int prime = 1;

		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
				break;
			}
		}

		if (prime)
		{
			printf("%3d ", i);
			result++;
		}
	}

	return result;
}

void print_prime(int result)
{
	printf("\n�Ҽ��� ��� %d���Դϴ�.", result);
}