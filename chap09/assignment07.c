/*
* 작성자: 김수경
* 파일명: assignment07
* 작성일: 2025.07.17
* 내용: 전화번호 문자열이 올바른 형식의 전화번호인지 검사하는 check_phone_str 함수를 작성.
* 전화번호는 "01012345678" 형식으로 입력받는다. 국번은"010"만 가능하다고 가정한다.
* check_phone_str 함수를 이용해서 입력된 문자열이 올바른 전화번호 문자열인지 검사해서 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
int check_phone_str(TEXT input);
void printResult(int result, TEXT input);

int main()
{
    TEXT input = { "" };

    while (1)
    {
        input = scanString(input);

        if (strcmp(input.str, ".") == 0)
            break;

        int result = check_phone_str(input);

        printResult(result, input);
    }

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("전화번호(.입력 시 종료)? ");
    scanf(" %s", input.str);
    return input;
}

int check_phone_str(TEXT input)
{

    if (strlen(input.str) != 11)
        return 0;

    if (input.str[0] != '0' || input.str[1] != '1' || input.str[2] != '0')
        return 0;

    for (int i = 0; i < 11; i++) {
        if (!isdigit(input.str[i]))
            return 0;
    }

    return 1;
}

void printResult(int result, TEXT input)
{
    if (result)
        printf("%s는 유효한 전화번호입니다.\n", input.str);
    else
        printf("잘못 입력했습니다. 01012345678 형식으로 입력하세요.\n");
    return;
}