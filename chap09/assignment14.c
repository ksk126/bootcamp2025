/*
* 작성자: 김수경
* 파일명: assignment14
* 작성일: 2025.07.17
* 내용: 인터넷 사이트에 회원가입을 하려는 사용자로부터 아이디를 입력받아 유효한 아이디인지 검사하는 프로그램을 작성.
* 아이디는 영문자로 시작해야하고, 영문자와 숫자로만 구성되며 최소 8자가 되어야한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanID(TEXT input);
int checkID(const TEXT input);
void printResult(const TEXT input, int code);

enum {
    ID_OK,
    ID_TOO_SHORT,
    ID_NOT_ALPHA_START,
    ID_INVALID_CHAR
};

int main()
{
    TEXT input = { "" };
    int code;

    do {
        input = scanID(input);
        code = checkID(input);
        printResult(input, code);
    } while (code != ID_OK);

    return 0;
}

TEXT scanID(TEXT input)
{
    printf("아이디 입력: ");
    scanf(" %999s", input.str);
    return input;
}

int checkID(const TEXT input)
{
    int len = (int)strlen(input.str);

    if (len < 8)
        return ID_TOO_SHORT;

    if (!isalpha((unsigned char)input.str[0]))
        return ID_NOT_ALPHA_START;

    for (int i = 0; i < len; i++) {
        if (!isalnum((unsigned char)input.str[i]))
            return ID_INVALID_CHAR;
    }

    return ID_OK;
}

void printResult(const TEXT input, int code)
{
    switch (code) {
    case ID_TOO_SHORT:
        printf("ID는 8자 이상이어야합니다.\n");
        break;
    case ID_NOT_ALPHA_START:
        printf("ID는 영문자로 시작해야합니다.\n");
        break;
    case ID_INVALID_CHAR:
        printf("ID는 영문자와 숫자로만 구성되어야 합니다.\n");
        break;
    case ID_OK:
        printf("%s는 ID로 사용할 수 있습니다.\n", input.str);
        break;
    }
}