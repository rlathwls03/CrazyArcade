#include "ca.h"


// 5x10 (y축으로 5칸, x축으로 10칸)
void draw_block(int x, int y, int fgColor, int bgColor)
{
    textcolor(fgColor, bgColor);

    int i = 0;
    for (i = 0; i < 2; i++) { // 세로줄
        gotoxy(x, y + i);
        for (int j = 0; j < 6; j++) { // 가로줄
            printf(" ");
        }
    }

    // 마지막 줄을 동일한 색상에서 조금 더 짙은 색으로 주어 그림자 효과
    textcolor(fgColor, bgColor - 8);

    gotoxy(x, y + i);
    for (int j = 0; j < 6; j++) { // 가로줄
        printf(" ");
    }
}

void draw_small_block(int x, int y, int fgColor, int bgColor)
{
    textcolor(fgColor, bgColor);

    int i = 0;
    for (i = 0; i < 1; i++) { // 세로줄
        gotoxy(x, y + i);
        for (int j = 0; j < 3; j++) { // 가로줄
            printf(" ");
        }
    }

    // 마지막 줄을 동일한 색상에서 조금 더 짙은 색으로 주어 그림자 효과를 준다.
    textcolor(fgColor, bgColor - 8);

    gotoxy(x, y + i);
    for (int j = 0; j < 3; j++) { // 가로줄
        printf(" ");
    }
}

void erase_block(int x, int y)
{
    textcolor(WHITE, BLACK);

    int i = 0;
    for (i = 0; i < 2; i++) { // 세로줄
        gotoxy(x, y + i);
        for (int j = 0; j < 6; j++) { // 가로줄
            printf(" ");
        }
    }

    // 마지막 줄을 동일한 색상에서 조금 더 짙은 색으로 주어 그림자 효과를 준다.
    textcolor(WHITE, BLACK);

    gotoxy(x, y + i);
    for (int j = 0; j < 6; j++) { // 가로줄
        printf(" ");
    }
}

void draw_character(int x, int y, int fgColor, int bgColor)
{
    char character[3][8] = {
        "▶  ◀",
        " ⊙⊙ ",
        "  º  ",
    };

    textcolor(fgColor, bgColor);

    int i, j;
    for (i = 0; i < 3; i++) { // 세로줄
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) { // 가로줄
            printf("%c", character[i][j]);
        }
    }
    gotoxy(0, 0);
}

void erase_character(int x, int y)
{
    char character[3][8] = {
        "      ",
        "      ",
        "      ",
    };

    textcolor(BLACK, BLACK);

    int i, j;
    for (i = 0; i < 3; i++) { // 세로줄
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) { // 가로줄
            printf("%c", character[i][j]);
        }
    }
    gotoxy(0, 0);
}

void draw_small_character(int x, int y, int fgColor, int bgColor, int player) 
{
    char character1[2][4] = {
        "P 1",
        "   ",
    };

    char character2[2][4] = {
        "P 2",
        "   ",
    };

    textcolor(fgColor, bgColor);

    int i, j;
    for (i = 0; i < 2; i++) { // 세로줄
        gotoxy(x, y + i);
        if(!player) printf("%s", character1[i]);
        else printf("%s", character2[i]);
    }
}

void draw_bomb(int x, int y)
{
    char bomb[3][7] = {
    " ◆   ",
    "      ",
    "      "
    };

    textcolor(WHITE, CYAN2);

    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    int i, j;
    for (i = 0; i < 3; i++) {
        gotoxy(xPos, yPos + i);
        printf("%s", bomb[i]);
    }

    // 꼭짓점 제거
    textcolor(BLACK, BLACK);
    gotoxy(xPos, yPos); printf(" ");
    gotoxy(xPos + 5, yPos); printf(" ");
    gotoxy(xPos, yPos + 2); printf(" ");
    gotoxy(xPos + 5, yPos + 2); printf(" ");
}

void erase_bomb(int x, int y)
{
    char bomb[3][7] = {
    "      ",
    "      ",
    "      "
    };

    textcolor(BLACK, BLACK);

    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    int i, j;
    for (i = 0; i < 3; i++) {
        gotoxy(xPos, yPos + i);
        printf("%s", bomb[i]);
    }
}

void draw_cursor(int xPos, int yPos) {
    int x = xPos - 4;
    int y = yPos - 2;
    int i, j;

    textcolor(CYAN2, CYAN2);
    
    // 왼쪽 세로
    for (i = 0; i < 10; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 10; i++) {
        gotoxy(x, y + i + 20);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }

    // 오른쪽 세로
    for (i = 0; i < 10; i++) {
        gotoxy(x + 65, y + i);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 10; i++) {
        gotoxy(x + 65, y + i + 20);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }

    // 왼쪽 가로
    for (i = 0; i < 1; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 1; i++) {
        gotoxy(x + 44, y + i);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }

    // 오른쪽 가로
    for (i = 0; i < 1; i++) {
        gotoxy(x + i, y + 29);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 1; i++) {
        gotoxy(x + i + 44, y + 29);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }

    textcolor(WHITE, BLACK);
}

void erase_cursor(int xPos, int yPos) {
    int x = xPos - 4;
    int y = yPos - 2;
    int i, j;

    textcolor(BLACK, BLACK);

    // 왼쪽 세로
    for (i = 0; i < 10; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 10; i++) {
        gotoxy(x, y + i + 20);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }

    // 오른쪽 세로
    for (i = 0; i < 10; i++) {
        gotoxy(x + 65, y + i);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 10; i++) {
        gotoxy(x + 65, y + i + 20);
        for (j = 0; j < 2; j++) {
            printf(" ");
        }
    }

    // 왼쪽 가로
    for (i = 0; i < 1; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 1; i++) {
        gotoxy(x + 44, y + i);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }

    // 오른쪽 가로
    for (i = 0; i < 1; i++) {
        gotoxy(x + i, y + 29);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }
    for (i = 0; i < 1; i++) {
        gotoxy(x + i + 44, y + 29);
        for (j = 0; j < 23; j++) {
            printf(" ");
        }
    }

    textcolor(WHITE, BLACK);
}

void draw_item_bomb(int x, int y)
{
    char item_bomb[3][7] = {
    "◆    ",
    " ⊙⊙ ",
    "      "
    };

    textcolor(WHITE, CYAN1);

    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    int i, j;
    for (i = 0; i < 3; i++) {
        gotoxy(xPos, yPos + i);
        printf("%s", item_bomb[i]);
    }
}

void draw_item_needle(int x, int y)
{
    char item_needle[3][8] = {
    " ※※ ",
    "  ∥  ",
    "  ∥  "
    };

    textcolor(BLUE2, BLACK);

    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    int i, j;
    for (i = 0; i < 3; i++) {
        if (i != 0) textcolor(WHITE, BLACK);
        gotoxy(xPos, yPos + i);
        printf("%s", item_needle[i]);
    }
}

void draw_1(int x, int y)
{
    char num1[5][7] = {
        "001100",
        "001100",
        "001100",
        "001100",
        "001100"
    };

    int i, j;
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num1[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_2(int x, int y)
{
    char num2[5][7] = {
        "111111",
        "000011",
        "111111",
        "110000",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num2[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_3(int x, int y)
{
    char num3[5][7] = {
        "111111",
        "000011",
        "111111",
        "000011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num3[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_4(int x, int y)
{
    char num4[5][7] = {
        "110011",
        "110011",
        "111111",
        "000011",
        "000011"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num4[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_5(int x, int y)
{
    char num5[5][7] = {
        "111111",
        "110000",
        "111111",
        "000011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num5[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_6(int x, int y)
{
    char num6[5][7] = {
        "111111",
        "110000",
        "111111",
        "110011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num6[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_7(int x, int y)
{
    char num7[5][7] = {
        "111111",
        "000011",
        "000011",
        "000011",
        "000011"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num7[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_8(int x, int y)
{
    char num8[5][7] = {
        "111111",
        "110011",
        "111111",
        "110011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num8[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_9(int x, int y)
{
    char num9[5][7] = {
        "111111",
        "110011",
        "111111",
        "000011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num9[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}
void draw_0(int x, int y)
{
    char num0[5][7] = {
        "111111",
        "110011",
        "110011",
        "110011",
        "111111"
    };

    int i, j;
    textcolor(BLACK, WHITE);
    for (i = 0; i < 5; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            if (num0[i][j] == '1') {
                textcolor(BLACK, WHITE);
                printf(" ");
            }
            else {
                textcolor(BLACK, BLACK);
                printf(" ");
            }
        }
    }
}

void draw_time(int x, int y, int time) {
    int d1 = time / 100;
    int d2 = (time % 100) / 10;
    int d3 = time % 10;

    int posX = x, posY = y;

    switch (d1) {
    case 1:
        draw_1(posX, posY);
        break;
    case 2:
        draw_2(posX, posY);
        break;
    case 3:
        draw_3(posX, posY);
        break;
    case 4:
        draw_4(posX, posY);
        break;
    case 5:
        draw_5(posX, posY);
        break;
    case 6:
        draw_6(posX, posY);
        break;
    case 7:
        draw_7(posX, posY);
        break;
    case 8:
        draw_8(posX, posY);
        break;
    case 9:
        draw_9(posX, posY);
        break;
    case 0:
        draw_0(posX, posY);
        break;
    }

    posX += 8;
    switch (d2) {
    case 1:
        draw_1(posX, posY);
        break;
    case 2:
        draw_2(posX, posY);
        break;
    case 3:
        draw_3(posX, posY);
        break;
    case 4:
        draw_4(posX, posY);
        break;
    case 5:
        draw_5(posX, posY);
        break;
    case 6:
        draw_6(posX, posY);
        break;
    case 7:
        draw_7(posX, posY);
        break;
    case 8:
        draw_8(posX, posY);
        break;
    case 9:
        draw_9(posX, posY);
        break;
    case 0:
        draw_0(posX, posY);
        break;
    }

    posX += 8;
    switch (d3) {
    case 1:
        draw_1(posX, posY);
        break;
    case 2:
        draw_2(posX, posY);
        break;
    case 3:
        draw_3(posX, posY);
        break;
    case 4:
        draw_4(posX, posY);
        break;
    case 5:
        draw_5(posX, posY);
        break;
    case 6:
        draw_6(posX, posY);
        break;
    case 7:
        draw_7(posX, posY);
        break;
    case 8:
        draw_8(posX, posY);
        break;
    case 9:
        draw_9(posX, posY);
        break;
    case 0:
        draw_0(posX, posY);
        break;
    }
}
