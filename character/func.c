#include "ca.h"


void cls(int text_color, int bg_color) //화면 지우기
{
    char cmd[100];
    system("cls");
    sprintf(cmd, "COLOR %x%x", bg_color, text_color);
    system(cmd);
}

void removeCursor(void) { // 커서를 안보이게 한다

    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}

void textcolor(int fg_color, int bg_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// 맵에서 배열 좌표로 변환해주는 함수
int MaptoArrayX(int x)
{
    return x / 7;
}
int MaptoArrayY(int y)
{
    return y / 3;
}

// 배열에서 맵으로 변환해주는 함수
int ArraytoMapX(int x)
{
    return x * 7;
}
int ArraytoMapY(int y)
{
    return y * 3;
}


