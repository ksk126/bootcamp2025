/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.24
* 내용: 점의 좌표를 나타내는 POINT 구조체에 대해서 두 점의 좌표를 맞바꾸는 swap_point 함수를 정의하시오.
* 크기가 10인 POINT 구조체 배열에 대하여 x좌표를 기준으로 선택 정렬하는 프로그램을 작성하시오.
* POINT 구조체 배열의 초기값은 마음대로 정한다.
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

    printf("<<정렬 전>>\n");
    PrintPoints(pts, POINT_COUNT);

    SelectionSortByX(pts, POINT_COUNT);

    printf("\n<<x좌표 기준 오름차순 정렬>>\n");
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