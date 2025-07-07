/*
* �ۼ���: �����
* ���ϸ�: assignment12p
* �ۼ���: 2025.07.04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct time {
    double distance;  
    double speed;    
} TIME;

TIME scanTime(TIME time);
int computeTime(TIME time);
void printTime(int result);

int main()
{
    TIME time = { 0 };

    time = scanTime(time);

    int result = computeTime(time);

    printTime(result);

    return 0;
}

TIME scanTime(TIME time)
{
    printf("�̵� �Ÿ�(km)? ");
    scanf("%lf", &time.distance);

    printf("���� �ӷ�(km/h)? ");
    scanf("%lf", &time.speed);

    return time;
}

int computeTime(TIME time)
{
    int result = (int)(time.distance / time.speed * 60);
    return result;
}

void printTime(int result)
{
    printf("�������� ���� �ҿ� �ð��� %d���Դϴ�.\n", result);
}
