/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.24
* ����: ���� ��ǥ�� ��Ÿ���� POINT ����ü�� ���ؼ� �� ���� ��ǥ�� �¹ٲٴ� swap_point �Լ��� �����Ͻÿ�.
* ũ�Ⱑ 10�� POINT ����ü �迭�� ���Ͽ� x��ǥ�� �������� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* POINT ����ü �迭�� �ʱⰪ�� ������� ���Ѵ�.
*/

#include <stdio.h>

#define POINT_COUNT 10

typedef struct {
    int x;
    int y;
} Point;

void RunPointSort(void);
void SwapPoint(Point* a, Point* b);
void SelectionSortByX(Point pts[], int size);
void PrintPoints(const Point pts[], int size);

int main(void)
{
    RunPointSort();
    return 0;
}

void RunPointSort(void)
{
    Point pts[POINT_COUNT] = {
        { 5,  9}, { 1, 11}, { 8,  3}, { 2, 15}, { 7,  2},
        { 3, 13}, { 6,  4}, { 4, 12}, {10,  1}, { 9,  6}
    };

    printf("<<���� ��>>\n");
    PrintPoints(pts, POINT_COUNT);

    SelectionSortByX(pts, POINT_COUNT);

    printf("\n<<x��ǥ ���� �������� ����>>\n");
    PrintPoints(pts, POINT_COUNT);
}bbbbbbb

void SwapPoint(Point* a, Point* b)
{
    Point tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSortByX(Point pts[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (pts[j].x < pts[minIdx].x)
                minIdx = j;
        }
        if (minIdx != i)
            SwapPoint(&pts[i], &pts[minIdx]);
    }

    return;
}

void PrintPoints(const Point pts[], int size)
{
    for (int i = 0; i < size; i++)
        printf("(%d, %d) ", pts[i].x, pts[i].y);
    printf("\n");

    return;
}