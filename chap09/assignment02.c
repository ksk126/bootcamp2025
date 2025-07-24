/*
* 작성자: 김수경
* 파일명: assignment02
* 작성일: 2025.07.17
* 내용: 한 줄의 문자열을 입력받아서 공백 문자(' ', '\n', '\t', '\f', '\r', '\v')를 모두 제거하는 remove_space 함수를
* 작성 후 remove_space 함수를 이용해서 입력받은 문자열에서 빈칸을 모두 제거하고 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT remove_space(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = remove_space(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("문자열을 입력하세요: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT remove_space(TEXT input)
{
    TEXT output = { "" };
    int j = 0;
    for (int i = 0; input.str[i] != '\0'; i++) {
        switch (input.str[i]) {
        case ' ':
        case '\t':
        case '\f':
        case '\r':
        case '\v':
            continue;
        default:
            output.str[j++] = input.str[i];
            break;
        }
    }
    output.str[j] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("결과 문자열: %s\n", input.str);
    return;
}