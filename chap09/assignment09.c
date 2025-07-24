/*
* 작성자: 김수경
* 파일명: assignment09
* 작성일: 2025.07.17
* 내용: 파일 이름과 확장자를 입력으로 받아서 확장자를 포함한 파일명을 출력하는 프로그램.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[1000];
    char ext[100];
    char full[1100];
} FILEINFO;

FILEINFO scanInput(FILEINFO input);
FILEINFO buildFullName(FILEINFO input);
void printResult(FILEINFO input);

int main()
{
    FILEINFO file = { "", "", "" };
    file = scanInput(file);
    file = buildFullName(file);
    printResult(file);
    return 0;
}

FILEINFO scanInput(FILEINFO input)
{
    printf("파일명? ");
    scanf(" %999s", input.name);
    printf("확장자? ");
    scanf(" %99s", input.ext);
    return input;
}

FILEINFO buildFullName(FILEINFO input)
{
    strcpy(input.full, input.name);
    strcat(input.full, ".");
    strcat(input.full, input.ext);
    return input;
}

void printResult(FILEINFO input)
{
    printf("전체 파일명: %s\n", input.full);
    return;
}