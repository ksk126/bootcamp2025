/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.24
* 내용: 크기가 3인 RECT 구조체 배열을 선언하고 0~99사이의 임의의 좌표로 설정한다.
* 직사각형의 우상단점의 좌표가 좌하단점보다 크도록 정규화하는 normalize_rect 함수와
* 직사각형의 중심점의 좌표를 구하는 center_rect 함수를 정의하고 배열 전체에 대하여
* 각각 호출하는 프로그램을 작성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RECT_COUNT 3

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} RECT;

void    RunRectDemo(void);
void    InitializeRects(RECT rects[], int size);
void    NormalizeRect(RECT* r);
void    PrintRectWithCenter(const RECT* r);

int main(void)
{
    RunRectDemo();
    return 0;
}

void RunRectDemo(void)
{
    RECT rects[RECT_COUNT];
    InitializeRects(rects, RECT_COUNT);

    for (int i = 0; i < RECT_COUNT; i++)
        NormalizeRect(&rects[i]);

    for (int i = 0; i < RECT_COUNT; i++)
        PrintRectWithCenter(&rects[i]);
}

void InitializeRects(RECT rects[], int size)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        rects[i].x1 = rand() % 100;
        rects[i].y1 = rand() % 100;
        rects[i].x2 = rand() % 100;
        rects[i].y2 = rand() % 100;
    }
}

void NormalizeRect(RECT* r)
{
    int left = r->x1 < r->x2 ? r->x1 : r->x2;
    int right = r->x1 > r->x2 ? r->x1 : r->x2;
    int bottom = r->y1 < r->y2 ? r->y1 : r->y2;
    int top = r->y1 > r->y2 ? r->y1 : r->y2;

    r->x1 = left;
    r->y1 = bottom;
    r->x2 = right;
    r->y2 = top;
}

void PrintRectWithCenter(const RECT* r)
{
    int cx = (r->x1 + r->x2) / 2;
    int cy = (r->y1 + r->y2) / 2;

    printf("[RECT 좌하단점:(%d, %d)  우상단점:(%d, %d)]    중심점: (%d, %d)\n",
        r->x1, r->y1, r->x2, r->y2, cx, cy);
}