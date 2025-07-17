/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);
void show_array(void);

int main(void)
{
    show_array();
    return 0;
}

void show_array(void)
{
    int arr[10] = { 12, 34, 56, 78, 99, 26, 31, 48, 1, 35 };
    int max, min;

    print_array(arr, 10);
    max = find_max(arr, 10);
    min = find_min(arr, 10);

    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    return;
}

void print_array(int arr[], int size)
{
    printf("배열:");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return;
}

int find_max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int find_min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
