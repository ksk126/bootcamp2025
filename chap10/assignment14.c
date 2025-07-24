/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.24
* ����: ũ�Ⱑ 3�� RECT ����ü �迭�� �����ϰ� 0~99������ ������ ��ǥ�� �����Ѵ�.
* ���簢���� �������� ��ǥ�� ���ϴ������� ũ���� ����ȭ�ϴ� normalize_rect �Լ���
* ���簢���� �߽����� ��ǥ�� ���ϴ� center_rect �Լ��� �����ϰ� �迭 ��ü�� ���Ͽ�
* ���� ȣ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

    printf("[RECT ���ϴ���:(%d, %d)  ������:(%d, %d)]    �߽���: (%d, %d)\n",
        r->x1, r->y1, r->x2, r->y2, cx, cy);
}