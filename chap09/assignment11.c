/*
* 작성자: 김수경
* 파일명: assignment11
* 작성일: 2025.07.17
* 내용: 영어 단어를 입력받아 끝말잇기 게임을 하려고 한다.
* 게임 참가자가 입력한 단어가 이전에 입력한 단어의 마지막 문자로 시작하는지 검사해서 게임을 계속할 수 있게 한다.
* 잘못된 단어가 입력되면 지금까지 끝말잇기를 몇 번 연속 성공했는지 출력한다.
* 간단한 구현을 위해서 입력된 단어가 올바른 단어인지 검사하지 않는다.
* 예를 들어 "abc"도 올바른 단어로 간주한다. 입력된 단어는 반드시 3글자 이상이어야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char str[1000];
} TEXT;

TEXT scanWord(TEXT input);
void printTooShort();
void printFailure(int count);

int main()
{
    TEXT prev = { "" };
    TEXT curr = { "" };
    int count = 1;

    prev = scanWord(prev);
    while (strlen(prev.str) < 3) {
        printTooShort();
        prev = scanWord(prev);
    }

    while (1) {
        curr = scanWord(curr);

        if (strlen(curr.str) < 3) {
            printTooShort();
            continue;
        }

        char last = prev.str[strlen(prev.str) - 1];
        if (curr.str[0] == last) {
            count++;
            prev = curr;
        }
        else {
            printFailure(count);
            break;
        }
    }

    return 0;
}

TEXT scanWord(TEXT input)
{
    printf("word? ");
    scanf(" %999s", input.str);
    return input;
}

void printTooShort()
{
    printf("too short, try again\n");
}

void printFailure(int count)
{
    printf("WRONG WORD!!! YOU FAILED!!!\n");
    printf("count: %d\n", count);
}