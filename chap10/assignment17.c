/*
 * �ۼ���: �����
 * ���ϸ�: assignment10
 * �ۼ���: 2025.07.24
 * ����: �뷡 ���� ���� ���α׷��� �˻� ����� �߰��Ϸ��� �Ѵ�.
 * ��� �Ǵ� �������� �Է¹޾Ƽ� �ش� �뷡 ������ ã�Ƽ� ����Ѵ�.
 * ����̳� �������� ��ġ�ϰų� �κ� ��ġ�ϴ� �뷡�� ���� ���� ��� ����Ѵ�.
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
        {"�� ���� ����", "�ں���",     ballad, 316},
        {"Awake",        "��ź�ҳ��", ballad, 226},
        {"I'm Fine",     "��ź�ҳ��", ballad, 209},
        {"�Ƴ���",        "MINO",       hiphop, 241}
    };

    char query[NAME_LEN];

    printf("�˻��� ��� �Ǵ� ������? ");
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
        "����", "��Ƽ��Ʈ", "�帣", "����ð�(��)");
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
        printf("�˻��� �뷡�� �����ϴ�.\n");
    }
}