/*
* 작성자: 김수경
* 파일명: assignment08
* 작성일: 2025.07.17
* 내용: 문자열과 키 값(치환할 문자의 이동 거리)를 입력받아서 시저암호로 암호화된 문자열을 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
    int key;
} CIPHER;

CIPHER scanInput(CIPHER input);
CIPHER caesarEncrypt(CIPHER input);
void printResult(CIPHER result);

int main()
{
    CIPHER input = { "", 0 };
    CIPHER result;

    while (1)
    {
        input = scanInput(input);

        if (strcmp(input.str, ".") == 0)
            break;

        result = caesarEncrypt(input);
        printResult(result);
    }

    return 0;
}

CIPHER scanInput(CIPHER input)
{
    printf("문자열? ");
    scanf(" %[^\n]", input.str);

    if (strcmp(input.str, ".") != 0) {

        getchar();

        printf("암호 키(정수)? ");
        scanf("%d", &input.key);

        getchar();
    }

    return input;
}

CIPHER caesarEncrypt(CIPHER input)
{
    CIPHER output = { "", input.key };
    int i = 0;

    while (input.str[i] != '\0') {
        char c = input.str[i];

        if (c >= 'A' && c <= 'Z') {
            output.str[i] = ((c - 'A' + input.key) % 26) + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            output.str[i] = ((c - 'a' + input.key) % 26) + 'a';
        }
        else {
            output.str[i] = c;
        }

        i++;
    }

    output.str[i] = '\0';
    return output;
}

void printResult(CIPHER result)
{
    printf("암호화된 문자열: %s\n", result.str);
    return;
}