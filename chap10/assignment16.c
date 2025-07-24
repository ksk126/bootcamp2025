/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.24
* 내용: 음원 사이트에 등록된 노래 정보를 관리하기 위한 프로그램을 작성하시오.
* 노래마다 곡명, 가수, 장르, 재생시간을 저장할 수 있게 SONG 구조체를 정의한다.
* 장르는 열거체와 열거 상수를 이용해서 나타내시오.
* SONG 구조체 배열을 선언하고 적절히 초기화한 다음 전체 노래 목록을 장르별로 출력하는 프로그램을 작성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum {
    pop = 0,
    ballad,
    hiphop,
    GenreCount
} Genre;

typedef struct {
    char   title[50];
    char   artist[50];
    Genre  genre;
    int    playTime;
} Song;

const char* GetGenreName(Genre g)
{
    static const char* names[GenreCount] = { "pop", "ballad", "hiphop" };
    return names[g];
}

void PrintSongsByGenre(const Song songs[], int count)
{
    printf("%-20s  %-20s  %-8s  %s\n",
        "제목", "아티스트", "장르", "재생시간");

    for (int i = 0; i < count; i++) {
        printf("%-20s  %-20s  %-8s  %d초\n",
            songs[i].title,
            songs[i].artist,
            GetGenreName(songs[i].genre),
            songs[i].playTime);
    }
}

int main(void)
{
    Song songs[] = {
        {"별 보러 가자",   "박보검",       ballad, 316},
        {"Awake",         "방탄소년단",   ballad, 226},
        {"I'm Fine",      "방탄소년단",   ballad, 209},
        {"아낙네",         "MINO",         hiphop, 241}
    };

    int count = sizeof(songs) / sizeof(songs[0]);
    PrintSongsByGenre(songs, count);

    return 0;
}