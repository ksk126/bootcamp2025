/*
* �ۼ���: �����
* ���ϸ�: assignment14
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct unit {
	int basic;
	int use;
}UNIT;

UNIT scanUse(UNIT electric);
int computeUse(UNIT electric);
void printUse(int result);


int main()
{
	UNIT electric = { 0 };

	electric = scanUse(electric);

	int result = computeUse(electric);

	printUse(result);

	return 0;
}

UNIT scanUse(UNIT electric)
{
	printf("�⺻ ���? ");
	scanf("%d", &electric.basic);
	printf("�� ��뷮 (kwh)? ");
	scanf("%d", &electric.use);

	return electric;
}

int computeUse(UNIT electric)
{
	int result = electric.basic + electric.use * 190;

	return result;
}

void printUse(result)
{
	printf("���� ���: %d��", result);

	return;
}