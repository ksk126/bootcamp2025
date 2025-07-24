/*
 * 작성자: 김수경
 * 파일명: assignment10
 * 작성일: 2025.07.24
 * 내용: 노래 정보 관리 프로그램에 검색 기능을 추가하려고 한다.
 * 곡명 또는 가수명을 입력받아서 해당 노래 정보를 찾아서 출력한다.
 * 곡명이나 가수명이 일치하거나 부분 일치하는 노래가 여러 개면 모두 출력한다.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SONG_COUNT 4
#define NAME_LEN   50

typedef enum {
    pop = 0,
    ballad,
    hiphop,
    GenreCount
} Genre;

typedef struct {
    char  title[NAME_LEN];
    char  artist[NAME_LEN];
    Genre genre;
    int   playTime;
} Song;

const char* GetGenreName(Genre g);
void        PrintSongHeader(void);
void        SearchSongs(const Song songs[], int count, const char query[]);

int main(void)
{
    Song songs[SONG_COUNT] = {
        {"별 보러 가자", "박보검",     ballad, 316},
        {"Awake",        "방탄소년단", ballad, 226},
        {"I'm Fine",     "방탄소년단", ballad, 209},
        {"아낙네",        "MINO",       hiphop, 241}
    };

    char query[NAME_LEN];

    printf("검색할 곡명 또는 가수명? ");
    scanf(" %49[^\n]", query);

    SearchSongs(songs, SONG_COUNT, query);
    return 0;
}

const char* GetGenreName(Genre g)
{
    static const char* names[GenreCount] = {
        "pop", "ballad", "hiphop"
    };
    return (g >= 0 && g < GenreCount) ? names[g] : "Unknown";
}

void PrintSongHeader(void)
{
    printf("%-20s %-20s %-10s %s\n",
        "제목", "아티스트", "장르", "재생시간(초)");
}

void SearchSongs(const Song songs[], int count, const char query[])
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(songs[i].title, query) != NULL ||
            strstr(songs[i].artist, query) != NULL)
        {
            if (!found) {
                PrintSongHeader();
                found = 1;
            }
            printf("%-20s %-20s %-10s %d\n",
                songs[i].title,
                songs[i].artist,
                GetGenreName(songs[i].genre),
                songs[i].playTime);
        }
    }

    if (!found) {
        printf("검색된 노래가 없습니다.\n");
    }
}