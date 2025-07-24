/*
* 작성자: 김수경
* 파일명: assignment05
* 작성일: 2025.07.17
* 내용: 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수를 작성 후, strcmp_ic(lhs, rhs) 합수의 리턴값은
* strcmp와 마찬가지로 lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0, lhs가 rhs보다 작으면 0보다 작은 값을
* 리턴하는 strcmp_ic 함수를 이용해서 입력받은 두 문자열을 비교하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanString(TEXT input, const char *msg);
int strcmp_ic(TEXT lhs, TEXT rhs);
void printResult(int result, TEXT lhs, TEXT rhs);

int main()
{
    TEXT lhs = { "" };
    TEXT rhs = { "" };
    int result;

    lhs = scanString(lhs, "첫 번째 문자열 ? ");
    rhs = scanString(rhs, "두 번째 문자열 ? ");

    result = strcmp_ic(lhs, rhs);

    printResult(result, lhs, rhs);

    return 0;
}

TEXT scanString(TEXT input, const char *msg)
{
    printf("%s", msg);
    scanf(" %[^\n]", input.str);
    return input;
}

int strcmp_ic(TEXT lhs, TEXT rhs)
{
    int i = 0;
    char a, b;

    while (lhs.str[i] != '\0' && rhs.str[i] != '\0') {
        a = lhs.str[i];
        b = rhs.str[i];

        if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
        if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';

        if (a != b) return a - b;
        i++;
    }

    a = lhs.str[i];
    b = rhs.str[i];
    if (a >= 'A' && a <= 'Z') a = a - 'A' + 'a';
    if (b >= 'A' && b <= 'Z') b = b - 'A' + 'a';

    return a - b;
}

void printResult(int result, TEXT lhs, TEXT rhs)
{
    if (result > 0)
    {
        printf("%s가 %s보다 큽니다.", lhs.str, rhs.str);
    }
    else if (result == 0)
    {
        printf("%s와 %s가 같습니다.", lhs.str, rhs.str);
    }
    else
    {
        printf("%s가 %s보다 작습니다.", lhs.str, rhs.str);
    }
    return;
}