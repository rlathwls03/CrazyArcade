#include "ca.h"


void cls(int text_color, int bg_color) //ȭ�� �����
{
    char cmd[100];
    system("cls");
    sprintf(cmd, "COLOR %x%x", bg_color, text_color);
    system(cmd);
}

void removeCursor(void) { // Ŀ���� �Ⱥ��̰� �Ѵ�

    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void gotoxy(int x, int y) //���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}

void textcolor(int fg_color, int bg_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// �ʿ��� �迭 ��ǥ�� ��ȯ���ִ� �Լ�
int MaptoArrayX(int x)
{
    return x / 7;
}
int MaptoArrayY(int y)
{
    return y / 3;
}

// �迭���� ������ ��ȯ���ִ� �Լ�
int ArraytoMapX(int x)
{
    return x * 7;
}
int ArraytoMapY(int y)
{
    return y * 3;
}


