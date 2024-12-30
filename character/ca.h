// 컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다.
// 해당 헤더파일이 여러번 include 되는 것을 막아준다.
// 여러곳에서 include 되면 그때마가 각각 정의가 추가되어 중첩되는 경우가 생기기 때문이다.
// 즉 중복된 내용이 여러번 빌드되는 것을 막기 위해 #pragma once를 사용한다
#pragma once

#include <stdio.h>
#include <conio.h> //kbhit, getch
#include <Windows.h>
#include <string.h>

// 색상 정의
#define BLACK   0
#define BLUE1   1
#define GREEN1   2
#define CYAN1   3
#define RED1   4
#define MAGENTA1 5
#define YELLOW1   6
#define GRAY1   7
#define GRAY2   8
#define BLUE2   9
#define GREEN2   10
#define CYAN2   11
#define RED2   12
#define MAGENTA2 13
#define YELLOW2   14
#define WHITE   15

#define ESC 0x1b
#define ENTER 0x0d
#define SPACE 0x20
#define CTRL 0x11
#define BACKSPACE 0x08

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2      'w'
#define DOWN2   's'
#define LEFT2   'a'
#define RIGHT2   'd'

// 맵1이 시작하는 좌표
#define MAP1_START_X 4
#define MAP1_START_Y 2
#define MAP1_FINISH_X 106
#define MAP1_FINISH_Y 38

// 맵2이 시작하는 좌표
#define MAP2_START_X 4
#define MAP2_START_Y 2
#define MAP2_FINISH_X 106
#define MAP2_FINISH_Y 38

// 맵 선택화면에서 그려지는 맵 시작 좌표
#define SMALL_MAP_START_X 20
#define SMALL_MAP_START_Y 10

// map1 배열 기준으로 캐릭터 좌표
#define PLAYER1_POS_X 2;
#define PLAYER1_POS_Y 2;
#define PLAYER2_POS_X 12;
#define PLAYER2_POS_Y 10;

// map2 배열 기준으로 캐릭터 좌표
#define PLAYER1_POS_X_m2 2;
#define PLAYER1_POS_Y_m2 11;
#define PLAYER2_POS_X_m2 12;
#define PLAYER2_POS_Y_m2 11;

#define MAP1_SIZE_X 15 
#define MAP1_SIZE_Y 13
#define MAP2_SIZE_X 15 
#define MAP2_SIZE_Y 13

// 블록 값에 대한 정의
#define BLANK -1
//small map 1
#define PLAYER1 0
#define PLAYER2 1
#define ITEM_BOMB 2
#define ITEM_BOMB_SHOW 22
#define NORMAL 3
#define SOLID 4
#define IS_BOMB 44
#define PLAYER1_BOMB 50
#define PLAYER2_BOMB 51
#define ITEM_NEEDLE 99
#define ITEM_NEEDLE_SHOW 88

//small map 2
#define PLAYER_1 0
#define PLAYER_2 1
#define RED_2 3
#define YELLOW_2 2
#define BLANK_2 99
#define BLUE_2 4

typedef struct Bomb { //폭탄 하나에 대한 구조체
    int x, y; //배열상 물폭탄 위치
    int time; //물폭탄 설치한 시간
}Bomb;

typedef struct Player { //캐릭터 하나에 대한 구조체
    int x, y; // 배열 기준 위치

    int bombCnt; // 현재 설치한 폭탄 수
    int maxBombCnt; // 최대 보유 폭탄 수, 아이템을 먹으면 늘어남, 물폭탄이 터지면 줄어들음
    struct Bomb bombs[10]; // 설치된 폭탄 정보를 담은 배열
    int needle; // 보유한 바늘 수, 최대 1

    int isBubbled; // 물줄기 맞은 여부, 1일 때 물폭탄에 갇힘
    int bubbledTime; // 물폭탄에 갇힌 시작 시간
    int setBomb; // 폭탄 설치 직후 그 폭탄 위에 서 있는 경우
}Player;


Player p1, p2;


// main.c
int collision_detection(int x, int y, int player);
void detonate_bomb(int x, int y, int time);
void draw_end(int);
void draw_cursor(int, int);
void UpdateInBubble(time);

// draw.c
void draw_block(int x, int y, int fgColor, int bgColor);
void erase_block(int x, int y);
void draw_small_block(int x, int y, int fgColor, int bgColor);
void draw_character(int x, int y, int fgColor, int bgColor);
void erase_character(int x, int y);
void draw_small_character(int x, int y, int fgColor, int bgColor, int player);
void draw_bomb(int x, int y);
void erase_bomb(int x, int y);
void draw_item_bomb(int x, int y);
void draw_item_needle(int x, int y);

void draw_1(int, int);
void draw_2(int, int);
void draw_3(int, int);
void draw_4(int, int);
void draw_5(int, int);
void draw_6(int, int);
void draw_7(int, int);
void draw_8(int, int);
void draw_9(int, int);
void draw_0(int, int);
void draw_time(int, int, int);

// func.c
void cls(int, int);
void removeCursor();
void gotoxy(int x, int y);
void textcolor(int fg_color, int bg_color);
void move_character(unsigned char ch, int time);
int MaptoArrayX(int x);
int MaptoArrayY(int y);
int ArraytoMapX(int x);
int ArraytoMapY(int y);

