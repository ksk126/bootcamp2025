/*
* 작성자: 김수경
* 파일명: assignment03
* 작성일: 2025.07.17
* 내용: 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT convertCase(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = convertCase(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("문자열을 입력하세요: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT convertCase(TEXT input)
{
    TEXT output = { "" };
    int i = 0;
    while (input.str[i] != '\0') {
        char c = input.str[i];
        if (c >= 'a' && c <= 'z') {
            output.str[i] = c - 'a' + 'A';
        }
        else if (c >= 'A' && c <= 'Z') {
            output.str[i] = c - 'A' + 'a';
        }
        else {
            output.str[i] = c;
        }
        i++;
    }
    output.str[i] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("변환된 문자열: %s\n", input.str);
    return;
}