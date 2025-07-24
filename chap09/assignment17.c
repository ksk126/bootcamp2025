/*
* 작성자: 김수경
* 파일명: assignment17
* 작성일: 2025.07.17
* 내용: 입력받은 노래 제목을 최대 20개 저장하고 관리하는 프로그램을 작성하시오.
* 노래 제목의 길이는 최대 40글자라고 가정한다.
* 간단한 메뉴로 노래 제목을 추가하는 기능, 노래 제목을 수정하는 기능, 노래 목록을 출력하는 기능을 처리한다.
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
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
    }

    return 0;
}

void printMenu()
{
    printf("[ 0.종료 1.추가 2.수정 3.목록 ] 선택? ");

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
        printf("최대 %d곡만 추가할 수 있습니다.\n", MAX_SONGS);
        return pl;
    }

    printf("노래 제목? ");
    scanf(" %[^\n]", pl.titles[pl.count]);
    pl.count++;

    return pl;
}

PLAYLIST modifySong(PLAYLIST pl)
{
    char searchTitle[MAX_TITLE_LEN];
    int found = -1;

    printf("찾을 노래 제목? ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < pl.count; i++) {
        if (strcmp(pl.titles[i], searchTitle) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("'%s' 제목의 노래를 찾을 수 없습니다.\n", searchTitle);
        return pl;
    }

    printf("수정할 제목? ");
    scanf(" %[^\n]", pl.titles[found]);

    return pl;
}

void listSongs(const PLAYLIST pl)
{

    printf("\n<< 노래 목록 >>\n");
    for (int i = 0; i < pl.count; i++) {
        printf("%s\n", pl.titles[i]);
    }

    return;
}