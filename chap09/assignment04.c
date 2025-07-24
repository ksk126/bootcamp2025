/*
* 작성자: 김수경
* 파일명: assignment04
* 작성일: 2025.07.17
* 내용: 문자열을 역순으로 만드는 reverse_string 함수 작성 후
* reverse_string 함수를 이용해서 입력받은 한 줄의 문자열을 역순으로 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input);
TEXT reverse_string(TEXT input);
void printString(TEXT input);

int main()
{
    TEXT input = { "" };

    input = scanString(input);
    TEXT result = reverse_string(input);
    printString(result);

    return 0;
}

TEXT scanString(TEXT input)
{
    printf("문자열을 입력하세요: ");
    scanf(" %[^\n]", input.str);
    return input;
}

TEXT reverse_string(TEXT input)
{
    TEXT output = { "" };
    int len = 0;
    while (input.str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        output.str[i] = input.str[len - 1 - i];
    }
    output.str[len] = '\0';
    return output;
}

void printString(TEXT input)
{
    printf("역순 문자열: %s\n", input.str);
    return;
}