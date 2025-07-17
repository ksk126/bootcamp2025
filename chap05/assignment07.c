/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct electric {
	int basic;
	int use;
} ELECTRIC;

int scanElectric();
ELECTRIC computeElectric(int use, ELECTRIC electric);
void printElectric(ELECTRIC electric);

int main()
{
	ELECTRIC electric = { 0 };

	int use = scanElectric();

	electric = computeElectric(use, electric);

	printElectric(electric);

	return 0;
}

int scanElectric()
{
	int use = 0;

	printf("월 사용량 (kWh)? ");
	scanf("%d", &use);

	return use;
}

ELECTRIC computeElectric(int use, ELECTRIC electric)
{
	if (use <= 200)
	{
		electric.basic = 910;
		electric.use = use * 93.3;
	}
	else if (use <= 400)
	{
		electric.basic = 1600;
		electric.use = (200 * 93.3) + ((use - 200) * 187.9);
	}
	else
	{
		electric.basic = 7300;
		electric.use = (200 * 93.3) + (200 * 187.9) + ((use - 400) * 280.6);
	}

	return electric;
}

void printElectric(ELECTRIC electric)
{
	printf("전기 요금 합계: %d원\n", electric.basic + electric.use);
	printf("\t- 기본요금: %d원\n", electric.basic);
	printf("\t- 전력량요금: %d원\n", electric.use);

	return;
}
