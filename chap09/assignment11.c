/*
* �ۼ���: �����
* ���ϸ�: assignment11
* �ۼ���: 2025.07.17
* ����: ���� �ܾ �Է¹޾� �����ձ� ������ �Ϸ��� �Ѵ�.
* ���� �����ڰ� �Է��� �ܾ ������ �Է��� �ܾ��� ������ ���ڷ� �����ϴ��� �˻��ؼ� ������ ����� �� �ְ� �Ѵ�.
* �߸��� �ܾ �ԷµǸ� ���ݱ��� �����ձ⸦ �� �� ���� �����ߴ��� ����Ѵ�.
* ������ ������ ���ؼ� �Էµ� �ܾ �ùٸ� �ܾ����� �˻����� �ʴ´�.
* ���� ��� "abc"�� �ùٸ� �ܾ�� �����Ѵ�. �Էµ� �ܾ�� �ݵ�� 3���� �̻��̾�� �Ѵ�.
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