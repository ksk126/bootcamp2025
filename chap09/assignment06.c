/*
* 작성자: 김수경
* 파일명: assignment06
* 작성일: 2025.07.17
* 내용: 시간 문자열이 유효한 시간인지 확인하는 check_time_str 함수를 작성.
* 예를 들어 "120000"는 12:00:00에 해당하는 유효한 시간문자열이지만 "327892"는 유효한 시간 문자열이 아니다.
* check_time_str 함수를 이용해서 입력된 문자열이 올바른 시간 문자열인지 검사해서 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
int check_time_str(TEXT input);
void printResult(int result, TEXT input);

int main()
{
    TEXT input = { "" };

    while (1)
    {
        input = scanString(input);

        if (strcmp(input.str, ".") == 0)
            break;

        int result = check_time_str(input);

        printResult(result, input);
    }

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("시간(.입력 시 종료)? ");
    scanf(" %s", input.str);
    return input;
}

int check_time_str(TEXT input)
{
    if (strlen(input.str) != 6)
        return 0;

    for (int i = 0; i < 6; i++) {
        if (!isdigit(input.str[i]))
            return 0;
    }

    int hour = (input.str[0] - '0') * 10 + (input.str[1] - '0');
    int minute = (input.str[2] - '0') * 10 + (input.str[3] - '0');
    int second = (input.str[4] - '0') * 10 + (input.str[5] - '0');

    if (hour < 0 || hour > 23) return 0;
    if (minute < 0 || minute > 59) return 0;
    if (second < 0 || second > 59) return 0;

    return 1;
}

void printResult(int result, TEXT input)
{
    if (result)
        printf("%s는 유효한 시간입니다.\n", input.str);
    else
        printf("잘못 입력했습니다. hhmmss형식으로 입력하세요.\n");
    return;
}