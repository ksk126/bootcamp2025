/*
* 작성자: 김수경
* 파일명: assignment02
* 작성일: 2025.07.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_sequence(double* term, double* ratio);
void generate_geometric_sequence(double term, double ratio, double arr[], int size);
void print_sequence(double arr[], int size);

int main(void)
{
    double term, ratio;
    double sequence[10];

    input_sequence(&term, &ratio);
    generate_geometric_sequence(term, ratio, sequence, 10);
    print_sequence(sequence, 10);

    return 0;
}

void input_sequence(double* term, double* ratio)
{
    printf("첫 번째 항? ");
    scanf("%lf", term);

    printf("공비? ");
    scanf("%lf", ratio);

    return;
}

void generate_geometric_sequence(double term, double ratio, double arr[], int size)
{
    arr[0] = term;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] * ratio;
    }

    return;
}

void print_sequence(double arr[], int size)
{
    printf("등비수열:");
    for (int i = 0; i < size; i++) {
        if (i == 0)
            printf(" %.1lf", arr[i]);
        else if (i == size - 1)
            printf(" %.5e", arr[i]);
        else
            printf(" %.0lf", arr[i]);
    }
    printf("\n");

    return;
}
