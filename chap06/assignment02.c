/*
* �ۼ���: �����
* ���ϸ�: assignment02
* �ۼ���: 2025.07.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double get_area_of_square();
void print_area(double lenth);

int main()
{
	double lenth = get_area_of_square();

	print_area(lenth);

	return 0;
}

double get_area_of_square()
{
	double lenth;

	printf("�� ���� ����? ");
	scanf("%lf", &lenth);

	return lenth;
}

void print_area(double lenth)
{
	printf("���簢���� ����: %lf", lenth*lenth);

	return;
}