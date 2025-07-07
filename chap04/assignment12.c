/*
* 작성자: 김수경
* 파일명: assignment12p
* 작성일: 2025.07.04
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
    printf("이동 거리(km)? ");
    scanf("%lf", &time.distance);

    printf("예상 속력(km/h)? ");
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
    printf("도착까지 예상 소요 시간은 %d분입니다.\n", result);
}
