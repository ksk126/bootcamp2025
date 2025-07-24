/*
* �ۼ���: �����
* ���ϸ�: assignment17
* �ۼ���: 2025.07.17
* ����: �Է¹��� �뷡 ������ �ִ� 20�� �����ϰ� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* �뷡 ������ ���̴� �ִ� 40���ڶ�� �����Ѵ�.
* ������ �޴��� �뷡 ������ �߰��ϴ� ���, �뷡 ������ �����ϴ� ���, �뷡 ����� ����ϴ� ����� ó���Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SONGS      20
#define MAX_TITLE_LEN  41

typedef struct {
    char titles[MAX_SONGS][MAX_TITLE_LEN];
    int  count;
} PLAYLIST;

void printMenu();
int  scanChoice();
PLAYLIST addSong(PLAYLIST pl);
PLAYLIST modifySong(PLAYLIST pl);
void listSongs(const PLAYLIST pl);

int main()
{
    PLAYLIST pl = { { {0} }, 0 };
    int choice;

    while (1)
    {
        printMenu();
        choice = scanChoice();

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            pl = addSong(pl);
            break;
        case 2:
            pl = modifySong(pl);
            break;
        case 3:
            listSongs(pl);
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        }
    }

    return 0;
}

void printMenu()
{
    printf("[ 0.���� 1.�߰� 2.���� 3.��� ] ����? ");

    return;
}

int scanChoice()
{
    int ch;
    scanf("%d", &ch);
    getchar();
    return ch;
}

PLAYLIST addSong(PLAYLIST pl)
{
    if (pl.count >= MAX_SONGS) {
        printf("�ִ� %d� �߰��� �� �ֽ��ϴ�.\n", MAX_SONGS);
        return pl;
    }

    printf("�뷡 ����? ");
    scanf(" %[^\n]", pl.titles[pl.count]);
    pl.count++;

    return pl;
}

PLAYLIST modifySong(PLAYLIST pl)
{
    char searchTitle[MAX_TITLE_LEN];
    int found = -1;

    printf("ã�� �뷡 ����? ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < pl.count; i++) {
        if (strcmp(pl.titles[i], searchTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("'%s' ������ �뷡�� ã�� �� �����ϴ�.\n", searchTitle);
        return pl;
    }

    printf("������ ����? ");
    scanf(" %[^\n]", pl.titles[found]);

    return pl;
}

void listSongs(const PLAYLIST pl)
{

    printf("\n<< �뷡 ��� >>\n");
    for (int i = 0; i < pl.count; i++) {
        printf("%s\n", pl.titles[i]);
    }

    return;
}