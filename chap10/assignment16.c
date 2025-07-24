/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.24
* ����: ���� ����Ʈ�� ��ϵ� �뷡 ������ �����ϱ� ���� ���α׷��� �ۼ��Ͻÿ�.
* �뷡���� ���, ����, �帣, ����ð��� ������ �� �ְ� SONG ����ü�� �����Ѵ�.
* �帣�� ����ü�� ���� ����� �̿��ؼ� ��Ÿ���ÿ�.
* SONG ����ü �迭�� �����ϰ� ������ �ʱ�ȭ�� ���� ��ü �뷡 ����� �帣���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
        "����", "��Ƽ��Ʈ", "�帣", "����ð�");

    for (int i = 0; i < count; i++) {
        printf("%-20s  %-20s  %-8s  %d��\n",
            songs[i].title,
            songs[i].artist,
            GetGenreName(songs[i].genre),
            songs[i].playTime);
    }
}

int main(void)
{
    Song songs[] = {
        {"�� ���� ����",   "�ں���",       ballad, 316},
        {"Awake",         "��ź�ҳ��",   ballad, 226},
        {"I'm Fine",      "��ź�ҳ��",   ballad, 209},
        {"�Ƴ���",         "MINO",         hiphop, 241}
    };

    int count = sizeof(songs) / sizeof(songs[0]);
    PrintSongsByGenre(songs, count);

    return 0;
}