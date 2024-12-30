// �����Ϸ����� �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
// �ش� ��������� ������ include �Ǵ� ���� �����ش�.
// ���������� include �Ǹ� �׶����� ���� ���ǰ� �߰��Ǿ� ��ø�Ǵ� ��찡 ����� �����̴�.
// �� �ߺ��� ������ ������ ����Ǵ� ���� ���� ���� #pragma once�� ����Ѵ�
#pragma once

#include <stdio.h>
#include <conio.h> //kbhit, getch
#include <Windows.h>
#include <string.h>

// ���� ����
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

#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.

#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ���´�.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2      'w'
#define DOWN2   's'
#define LEFT2   'a'
#define RIGHT2   'd'

// ��1�� �����ϴ� ��ǥ
#define MAP1_START_X 4
#define MAP1_START_Y 2
#define MAP1_FINISH_X 106
#define MAP1_FINISH_Y 38

// ��2�� �����ϴ� ��ǥ
#define MAP2_START_X 4
#define MAP2_START_Y 2
#define MAP2_FINISH_X 106
#define MAP2_FINISH_Y 38

// �� ����ȭ�鿡�� �׷����� �� ���� ��ǥ
#define SMALL_MAP_START_X 20
#define SMALL_MAP_START_Y 10

// map1 �迭 �������� ĳ���� ��ǥ
#define PLAYER1_POS_X 2;
#define PLAYER1_POS_Y 2;
#define PLAYER2_POS_X 12;
#define PLAYER2_POS_Y 10;

// map2 �迭 �������� ĳ���� ��ǥ
#define PLAYER1_POS_X_m2 2;
#define PLAYER1_POS_Y_m2 11;
#define PLAYER2_POS_X_m2 12;
#define PLAYER2_POS_Y_m2 11;

#define MAP1_SIZE_X 15 
#define MAP1_SIZE_Y 13
#define MAP2_SIZE_X 15 
#define MAP2_SIZE_Y 13

// ��� ���� ���� ����
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

typedef struct Bomb { //��ź �ϳ��� ���� ����ü
    int x, y; //�迭�� ����ź ��ġ
    int time; //����ź ��ġ�� �ð�
}Bomb;

typedef struct Player { //ĳ���� �ϳ��� ���� ����ü
    int x, y; // �迭 ���� ��ġ

    int bombCnt; // ���� ��ġ�� ��ź ��
    int maxBombCnt; // �ִ� ���� ��ź ��, �������� ������ �þ, ����ź�� ������ �پ����
    struct Bomb bombs[10]; // ��ġ�� ��ź ������ ���� �迭
    int needle; // ������ �ٴ� ��, �ִ� 1

    int isBubbled; // ���ٱ� ���� ����, 1�� �� ����ź�� ����
    int bubbledTime; // ����ź�� ���� ���� �ð�
    int setBomb; // ��ź ��ġ ���� �� ��ź ���� �� �ִ� ���
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

