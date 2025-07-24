/*
* 작성자: 김수경
* 파일명: assignment02
* 작성일: 2025.07.19
* 내용: 1번 프로그램의 아이디와 패스워드를 항상 소문자로만 저장하도록 처리하려고 한다.
* LOGIN 구조체를 매개변수로 전달받아 구조체에 저장된 아이디와 패스워드를 모두 소문자로 만드는 make_lower 함수와 
* 아이디와 패스워드를 출력하는 print_login 함수를 정의하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct {
    char id[20];
    char pw[20];
} LOGIN;

LOGIN scanLogin(LOGIN data);
LOGIN make_lower(LOGIN data);
void printLogin(LOGIN data);

int main()
{
    LOGIN user = { "", "" };

    user = scanLogin(user);
    user = make_lower(user);
    printLogin(user);

    return 0;
}

LOGIN scanLogin(LOGIN data)
{
    printf("ID? ");
    scanf(" %19s", data.id);

    printf("PW: ");
    scanf(" %19s", data.pw);

    return data;
}

LOGIN make_lower(LOGIN data)
{
    int i;

    for (i = 0; data.id[i] != '\0'; i++)
        data.id[i] = tolower(data.id[i]);

    for (i = 0; data.pw[i] != '\0'; i++)
        data.pw[i] = tolower(data.pw[i]);

    return data;
}

void printLogin(LOGIN data)
{
    int i;

    printf("ID: %s\n", data.id);
    printf("PW: ");
    for (i = 0; data.pw[i] != '\0'; i++)
        printf("*");
    printf("\n");
}