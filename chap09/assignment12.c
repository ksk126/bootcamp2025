/*
* 작성자: 김수경
* 파일명: assignment12
* 작성일: 2025.07.17
* 내용: 입력받은 문자열에 대하여 이동할 글자 수를 입력받아 왼쪽이나 오른쪽으로 회전(rotate)한 결과를
* 출력하는 프로그램을 작성하시오. 예를 들어 "abcdef"를 오른쪽으로 2글자 회전하면 "efabcd"가 된다.
* 이동할 글자 수가 음수면 왼쪽으로, 양수면 오른쪽으로 이동한다. 이동할 글자수로 0이 입력되면 프로그램을 종료한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
    char result[1000];
} TEXT;

TEXT scanInitial(TEXT input);
int scanShift();
TEXT rotateString(TEXT base, int shift);
void printResult(TEXT output);

int main()
{
    TEXT base = { "", "" };
    base = scanInitial(base);

    int shift;
    while ((shift = scanShift()) != 0)
    {
        TEXT output = rotateString(base, shift);
        printResult(output);
    }

    return 0;
}

TEXT scanInitial(TEXT input)
{
    printf("문자열? ");
    scanf(" %[^\n]", input.str);
    return input;
}

int scanShift()
{
    int s;
    printf("이동할 글자 수? ");
    scanf("%d", &s);
    return s;
}

TEXT rotateString(TEXT base, int shift)
{
    int len = strlen(base.str);
    if (len == 0)
    {
        base.result[0] = '\0';
        return base;
    }

    int k = shift % len;
    if (k < 0)
        k = (k + len) % len;

    for (int i = 0; i < len; i++)
    {
        int src = (i - k + len) % len;
        base.result[i] = base.str[src];
    }
    base.result[len] = '\0';

    return base;
}

void printResult(TEXT output)
{
    printf("%s\n", output.result);
    return;
}