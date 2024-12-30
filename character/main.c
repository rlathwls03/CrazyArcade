#include "ca.h"

#define WIDTH 120
#define HEIGHT 30

void TitleScreen();
int winner = 0;

//2�� ����, 3�� �Ķ�, 4�� �ʷ�, -1�� ����, 0�� p1, 1�� p2
int map1[MAP1_SIZE_Y][MAP1_SIZE_X] = {
    2,2,3,99,3,3,2,2,2,3,3,99,3,2,2,
    2,4,-1,4,3,4,2,4,2,4,3,4,3,4,2,
    3,-1,0,-1,3,3,3,3,3,3,3,3,3,3,3,
    99,4,-1,4,3,4,3,4,3,4,3,4,3,4,99,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    2,4,3,4,3,4,3,4,3,4,3,4,3,4,2,
    2,2,3,3,3,3,3,3,3,3,3,3,3,2,2,
    2,4,3,4,3,4,3,4,3,4,3,4,3,4,2,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    99,4,3,4,3,4,3,4,3,4,3,4,-1,4,99,
    3,3,3,3,3,3,3,3,3,3,3,-1,1,-1,3,
    2,4,3,4,3,4,2,4,2,4,3,4,-1,4,2,
    2,2,3,99,3,3,2,2,2,3,3,99,3,2,2,
};
 
//3�� ����, 2�� ���, -1 ����, 4�� �Ķ�, 0�� p1, 1�� p2
int map2[MAP2_SIZE_Y][MAP2_SIZE_X] = {
    3,2,3,2,3,2,4,-1,4,2,3,2,3,2,3,
    3,2,3,2,3,2,4,-1,4,2,3,2,3,2,3,
    3,2,2,2,3,3,4,-1,4,3,3,2,2,2,3,
    3,2,2,2,3,3,4,-1,4,3,3,2,2,2,3,
    3,2,3,3,2,3,3,-1,3,3,2,3,3,2,3,
    3,3,2,2,3,3,4,-1,4,3,3,2,2,3,3,
    3,4,4,3,2,3,3,-1,3,3,4,3,4,2,3,
    3,3,2,2,2,3,3,-1,3,3,4,2,2,3,3,
    3,2,2,2,3,3,4,-1,4,3,3,2,2,2,3,
    3,3,4,4,2,3,4,-1,4,3,2,4,4,3,3,
    3,3,-1,3,2,3,4,-1,4,3,2,3,-1,3,3,
    3,-1,0,-1,4,3,4,-1,4,3,2,-1,1,-1,3,
    3,3,-1,2,2,3,3,-1,3,3,3,2,-1,2,3,
};

int tmp1[MAP2_SIZE_Y][MAP2_SIZE_X]; 
int tmp2[MAP2_SIZE_Y][MAP2_SIZE_X]; 

void init() { // ���� ���� �� �����ص� �� �迭 ��������
    memcpy(map1, tmp1, sizeof(map1)); // �޸��� ���� �����ϴ� ����� �ϴ� �Լ�
    memcpy(map2, tmp2, sizeof(map2));
}

void draw_smallMap() //2�� ����, 3�� �Ķ�, 4�� �ʷ�, -1�� ����
{
    int x, y;
    int posX = SMALL_MAP_START_X;
    int posY = SMALL_MAP_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + y * 2; // ��� ũ�Ⱑ y�� 2ĭ, x�� 4ĭ
        for (x = 0; x < 15; x++) {
            offsetX = posX + x * 4; 
            // ����ź�� ������ �ִ� ���
            if (map1[y][x] == ITEM_BOMB) {
                draw_small_block(offsetX, offsetY, WHITE, RED2); 
            }
            // �Ϲ� ���
            else if (map1[y][x] == NORMAL) {
                draw_small_block(offsetX, offsetY, WHITE, BLUE2);
            }
            // �ı� �Ұ����� ���
            else if (map1[y][x] == SOLID) {
                draw_small_block(offsetX, offsetY, WHITE, GREEN2);
            }
            // �ٴ��� ������ �ִ� ���
            else if (map1[y][x] == ITEM_NEEDLE) {
                draw_small_block(offsetX, offsetY, WHITE, YELLOW2);
            }
            // player1 �׸���
            else if (map1[y][x] == PLAYER1) {
                draw_small_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player2 �׸���
            else if (map1[y][x] == PLAYER2) {
                draw_small_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else {
                continue; 
            }
        }
    }
}
void draw_smallMap2()  //1�� ����, 0�� ���, 99�� ����, 2�� �Ķ� 
{
    int x, y;
    int posX = SMALL_MAP_START_X + 70;
    int posY = SMALL_MAP_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + y * 2;
        for (x = 0; x < 15; x++) {
            offsetX = posX + x * 4;
            if (map2[y][x] == 3) { //����
                draw_small_block(offsetX, offsetY, WHITE, RED2);
            }
            else if (map2[y][x] == 4) { //�Ķ�
                draw_small_block(offsetX, offsetY, WHITE, BLUE2);
            } 
            else if (map2[y][x] == BLANK) { //����
            }
            // player_1 �׸���
            else if (map2[y][x] == PLAYER_1) { //p1
                draw_small_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player_2 �׸���
            else if (map2[y][x] == PLAYER_2) { //p2
                draw_small_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else { //2�� ���
                draw_small_block(offsetX, offsetY, WHITE, YELLOW2);
            }
        }
    }
}

void draw_map()
{
    int x, y;
    int posX = MAP1_START_X;
    int posY = MAP1_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + ArraytoMapY(y); //�迭�� ������
        for (x = 0; x < 15; x++) {
            offsetX = posX + ArraytoMapX(x);
            // ����ź�� ������ �ִ� ���
            if (map1[y][x] == ITEM_BOMB) {
                draw_block(offsetX, offsetY, WHITE, RED2);
            }
            // �Ϲ� ���
            else if (map1[y][x] == NORMAL) {
                draw_block(offsetX, offsetY, WHITE, BLUE2);
            }
            // �ı� �Ұ����� ���
            else if (map1[y][x] == SOLID) {
                draw_block(offsetX, offsetY, WHITE, GREEN2);
            }
            // �ٴ��� ������ �ִ� ���
            else if (map1[y][x] == ITEM_NEEDLE) {
                draw_block(offsetX, offsetY, WHITE, YELLOW2);
            }
            // player1 �׸���
            else if (map1[y][x] == PLAYER1) {
                draw_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player2 �׸���
            else if (map1[y][x] == PLAYER2) {
                draw_character(offsetX, offsetY, RED1, BLACK, 0);
            }
            else {
                continue;
            }
        }
    }
}
void draw_map2()
{
    int x, y;
    int posX = MAP2_START_X;
    int posY = MAP2_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + ArraytoMapY(y);
        for (x = 0; x < 15; x++) {
            offsetX = posX + ArraytoMapX(x);
            if (map2[y][x] == 3) { //����
                draw_block(offsetX, offsetY, WHITE, RED2);
            }
            else if (map2[y][x] == 4) { //�Ķ�
                draw_block(offsetX, offsetY, WHITE, BLUE2);
            }
            else if (map2[y][x] == BLANK) { //����
                //draw_character(offsetX, offsetY, WHITE, GRAY2, 0);
                //erase_character(offsetX, offsetY);
            }
            // player_1 �׸���
            else if (map2[y][x] == PLAYER_1) { //p1
                draw_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player_2 �׸���
            else if (map2[y][x] == PLAYER_2) { //p2
                draw_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else { //2�� ���
                draw_block(offsetX, offsetY, WHITE, YELLOW2);
            }
        }
    }
}

void detonate_bomb(int x, int y, int time) // ����ź ������ �Լ�
{
    // �迭���� �� ��ǥ�� ��ȯ
    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    // �����¿쿡 ���� �Ϲ� ��� ����
    int up = 0, down = 0, left = 0, right = 0;

    // �����¿쿡 ���� ������ ��ź ��� ����
    int up_bomb = 0, down_bomb = 0, left_bomb = 0, right_bomb = 0;

    // �����¿쿡 ���� ������ �ٴ� ��� ����
    int up_needle = 0, down_needle = 0, left_needle = 0, right_needle = 0;

    int on_bomb = 0; // ����ź ���� �ִ� ���
    // ĳ���Ͱ� ����ź ���� �ִ� ��쿡 ���� ����
    if (map1[y][x] == PLAYER1_BOMB) {
        draw_character(xPos, yPos, CYAN2, CYAN1);
        p1.isBubbled = 1;
        p1.bubbledTime = time;
        on_bomb = 1;
    }
    if (map1[y][x] == PLAYER2_BOMB) {
        draw_character(xPos, yPos, CYAN2, CYAN1);
        p2.isBubbled = 1;
        p2.bubbledTime = time;
        on_bomb = 1;
    }

    // ��
    if (x - 1 >= 0) { 
        // ���� ��� ����￡ ������.
        if (map1[y][x - 1] == PLAYER1) {
            draw_character(xPos - 7, yPos, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map1[y][x - 1] == PLAYER2) {
            draw_character(xPos - 7, yPos, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map1[y][x - 1] == ITEM_BOMB) {
            map1[y][x - 1] = ITEM_BOMB_SHOW;
            left_bomb = 1;
        }
        // �ٴ�
        else if (map1[y][x - 1] == ITEM_NEEDLE) {
            map1[y][x - 1] = ITEM_NEEDLE_SHOW;
            left_needle = 1;
        }
        // �Ϲ� ���
        else if(map1[y][x - 1] == NORMAL) {
            map1[y][x - 1] = BLANK;
            left = 1;
        }
    }
    // ��
    if (x + 1 < MAP1_SIZE_X) {
        if (map1[y][x + 1] == PLAYER1) {
            draw_character(xPos + 7, yPos, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map1[y][x + 1] == PLAYER2) {
            draw_character(xPos + 7, yPos, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map1[y][x + 1] == ITEM_BOMB) {
            map1[y][x + 1] = ITEM_BOMB_SHOW;
            right_bomb = 1;
        }
        // �ٴ�
        else if (map1[y][x + 1] == ITEM_NEEDLE) {
            map1[y][x + 1] = ITEM_NEEDLE_SHOW;
            right_needle = 1;
        }
        // �Ϲ� ���
        else if(map1[y][x + 1] == NORMAL) {
            map1[y][x + 1] = BLANK;
            right = 1;
        }
    }
    // ��
    if (y - 1 >= 0) {
        if (map1[y - 1][x] == PLAYER1) {
            draw_character(xPos, yPos - 3, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map1[y - 1][x] == PLAYER2) {
            draw_character(xPos, yPos - 3, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map1[y - 1][x] == ITEM_BOMB) {
            map1[y - 1][x] = ITEM_BOMB_SHOW;
            up_bomb = 1;
        }
        // �ٴ�
        else if (map1[y - 1][x] == ITEM_NEEDLE) {
            map1[y - 1][x] = ITEM_NEEDLE_SHOW;
            up_needle = 1;
        }
        // �Ϲ� ���
        else if(map1[y - 1][x] == NORMAL) {
            map1[y - 1][x] = BLANK;
            up = 1;
        }
    }
    // ��
    if (y + 1 < MAP1_SIZE_Y) {
        if (map1[y + 1][x] == PLAYER1) {
            draw_character(xPos, yPos + 3, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map1[y + 1][x] == PLAYER2) {
            draw_character(xPos, yPos + 3, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map1[y + 1][x] == ITEM_BOMB) {
            map1[y + 1][x] = ITEM_BOMB_SHOW;
            down_bomb = 1;
        }
        // �ٴ�
        else if (map1[y + 1][x] == ITEM_NEEDLE) {
            map1[y + 1][x] = ITEM_NEEDLE_SHOW;
            down_needle = 1;
        }
        // �Ϲ� ���
        else if (map1[y + 1][x] == NORMAL) {
            map1[y + 1][x] = BLANK;
            down = 1;
        }
    }

    // ���ٱ� �׸���
    if (up) draw_block(xPos, yPos - 3, CYAN1, CYAN1);
    if (down) draw_block(xPos, yPos + 3, CYAN1, CYAN1);
    if (left) draw_block(xPos - 7, yPos, CYAN1, CYAN1);
    if (right) draw_block(xPos + 7, yPos, CYAN1, CYAN1);
    if (!on_bomb) {
        map1[y][x] = BLANK;
        erase_block(xPos, yPos);
    }

    // ��� ��� �� ���ٱ� �����
    Sleep(100);
    if (up) erase_block(xPos, yPos - 3);
    if (down) erase_block(xPos, yPos + 3);
    if (left) erase_block(xPos - 7, yPos);
    if (right) erase_block(xPos + 7, yPos);

    if (up_bomb) draw_item_bomb(x, y - 1);
    if (down_bomb) draw_item_bomb(x, y + 1);
    if (left_bomb) draw_item_bomb(x - 1, y);
    if (right_bomb) draw_item_bomb(x + 1, y);

    if (up_needle) draw_item_needle(x, y - 1);
    if (down_needle) draw_item_needle(x, y + 1);
    if (left_needle) draw_item_needle(x - 1, y);
    if (right_needle) draw_item_needle(x + 1, y);
}
void detonate_bomb2(int x, int y, int time)
{
    // �迭���� �� ��ǥ�� ��ȯ
    int xPos = MAP2_START_X + ArraytoMapX(x);
    int yPos = MAP2_START_Y + ArraytoMapY(y);

    // �����¿쿡 ���� �Ϲ� ��� ����
    int up = 0, down = 0, left = 0, right = 0;

    // �����¿쿡 ���� ������ ��ź ��� ����
    int up_bomb = 0, down_bomb = 0, left_bomb = 0, right_bomb = 0;

    // �����¿쿡 ���� ������ �ٴ� ��� ����
    int up_needle = 0, down_needle = 0, left_needle = 0, right_needle = 0;

    int on_bomb = 0;
    // ĳ���Ͱ� ����ź ���� �ִ� ��쿡 ���� ����
    if (map2[y][x] == PLAYER1_BOMB) {
        draw_character(xPos, yPos, CYAN2, CYAN1);
        p1.isBubbled = 1;
        p1.bubbledTime = time;
        on_bomb = 1;
    }
    if (map2[y][x] == PLAYER2_BOMB) {
        draw_character(xPos, yPos, CYAN2, CYAN1);
        p2.isBubbled = 1;
        p2.bubbledTime = time;
        on_bomb = 1;
    }

    // ��
    if (x - 1 >= 0) {
        // ���� ��� ����￡ ������.
        if (map2[y][x - 1] == PLAYER1) {
            draw_character(xPos - 7, yPos, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map2[y][x - 1] == PLAYER2) {
            draw_character(xPos - 7, yPos, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map2[y][x - 1] == ITEM_BOMB) {
            map2[y][x - 1] = ITEM_BOMB_SHOW;
            left_bomb = 1;
        }
        // �ٴ�
        else if (map2[y][x - 1] == ITEM_NEEDLE) {
            map2[y][x - 1] = ITEM_NEEDLE_SHOW;
            left_needle = 1;
        }
        // �Ϲ� ���
        else if (map2[y][x - 1] == NORMAL) {
            map2[y][x - 1] = BLANK;
            left = 1;
        }
    }
    // ��
    if (x + 1 < MAP1_SIZE_X) {
        if (map2[y][x + 1] == PLAYER1) {
            draw_character(xPos + 7, yPos, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map2[y][x + 1] == PLAYER2) {
            draw_character(xPos + 7, yPos, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map2[y][x + 1] == ITEM_BOMB) {
            map2[y][x + 1] = ITEM_BOMB_SHOW;
            right_bomb = 1;
        }
        // �ٴ�
        else if (map2[y][x + 1] == ITEM_NEEDLE) {
            map2[y][x + 1] = ITEM_NEEDLE_SHOW;
            right_needle = 1;
        }
        // �Ϲ� ���
        else if (map2[y][x + 1] == NORMAL) {
            map2[y][x + 1] = BLANK;
            right = 1;
        }
    }
    // ��
    if (y - 1 >= 0) {
        if (map2[y - 1][x] == PLAYER1) {
            draw_character(xPos, yPos - 3, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map2[y - 1][x] == PLAYER2) {
            draw_character(xPos, yPos - 3, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map2[y - 1][x] == ITEM_BOMB) {
            map2[y - 1][x] = ITEM_BOMB_SHOW;
            up_bomb = 1;
        }
        // �ٴ�
        else if (map2[y - 1][x] == ITEM_NEEDLE) {
            map2[y - 1][x] = ITEM_NEEDLE_SHOW;
            up_needle = 1;
        }
        // �Ϲ� ���
        else if (map2[y - 1][x] == NORMAL) {
            map2[y - 1][x] = BLANK;
            up = 1;
        }
    }
    // ��
    if (y + 1 < MAP1_SIZE_Y) {
        if (map2[y + 1][x] == PLAYER1) {
            draw_character(xPos, yPos + 3, CYAN2, CYAN1);
            p1.isBubbled = 1;
            p1.bubbledTime = time;
        }
        else if (map2[y + 1][x] == PLAYER2) {
            draw_character(xPos, yPos + 3, CYAN2, CYAN1);
            p2.isBubbled = 1;
            p2.bubbledTime = time;
        }
        // �ƴ� ��� ����� ����
        // ����ź 
        else if (map2[y + 1][x] == ITEM_BOMB) {
            map2[y + 1][x] = ITEM_BOMB_SHOW;
            down_bomb = 1;
        }
        // �ٴ�
        else if (map2[y + 1][x] == ITEM_NEEDLE) {
            map2[y + 1][x] = ITEM_NEEDLE_SHOW;
            down_needle = 1;
        }
        // �Ϲ� ���
        else if (map2[y + 1][x] == NORMAL) {
            map2[y + 1][x] = BLANK;
            down = 1;
        }
    }

    // ���ٱ� �׸���
    if (up) draw_block(xPos, yPos - 3, CYAN1, CYAN1);
    if (down) draw_block(xPos, yPos + 3, CYAN1, CYAN1);
    if (left) draw_block(xPos - 7, yPos, CYAN1, CYAN1);
    if (right) draw_block(xPos + 7, yPos, CYAN1, CYAN1);
    if (!on_bomb) {
        map2[y][x] = BLANK;
        erase_block(xPos, yPos);
    }

    // ��� ��� �� ���ٱ� �����
    Sleep(100);
    if (up) erase_block(xPos, yPos - 3);
    if (down) erase_block(xPos, yPos + 3);
    if (left) erase_block(xPos - 7, yPos);
    if (right) erase_block(xPos + 7, yPos);

    if (up_bomb) draw_item_bomb(x, y - 1);
    if (down_bomb) draw_item_bomb(x, y + 1);
    if (left_bomb) draw_item_bomb(x - 1, y);
    if (right_bomb) draw_item_bomb(x + 1, y);

    if (up_needle) draw_item_needle(x, y - 1);
    if (down_needle) draw_item_needle(x, y + 1);
    if (left_needle) draw_item_needle(x - 1, y);
    if (right_needle) draw_item_needle(x + 1, y);
}

int collision_detection(int x, int y, int player) // �浹����
{
    // ������ ����� ��� ����ó��
    if (x < 0 || y < 0 || x > MAP1_SIZE_X - 1 || y > MAP1_SIZE_Y - 1) return 1;

    // �� ĭ
    if (map1[y][x] == BLANK) return 0;
    
    // ����ź ������ ���� ���
    if (map1[y][x] == ITEM_BOMB_SHOW) {
        map1[y][x] = BLANK;
        if (!player) p1.maxBombCnt++; // ����ź�� �Ծ �þ
        else p2.maxBombCnt++;
        return 0;
    }

    // �ٴ� ������ ���� ���
    if (map1[y][x] == ITEM_NEEDLE_SHOW) {
        map1[y][x] = BLANK;
        if (!player) p1.needle = 1; // ������ �ٴ� ��, �ִ� 1
        else p2.needle = 1; 
        return 0;
    }

    // ����￡ ���� Player�� ���� �浹 (���� ����)
    if (map1[y][x] == !player) {
        // �÷��̾� 1
        if (!player) {
            if (p2.isBubbled) {
                winner = 1;
                return 0;
            }
            else return 1;
        }
        else {
            if (p1.isBubbled) {
                winner = 2;
                return 0;
            }
            else return 1;
        }
    }

    return 1;
}
int collision_detection2(int x, int y, int player) // �浹����
{
    // ������ ����� ��� ����ó��
    if (x < 0 || y < 0 || x > MAP2_SIZE_X - 1 || y > MAP2_SIZE_Y - 1) return 1;

    // �� ĭ
    if (map2[y][x] == BLANK) return 0;

    // ��ź ������ ���� ���
    if (map2[y][x] == ITEM_BOMB_SHOW) {
        map2[y][x] = BLANK;
        if (!player) p1.maxBombCnt++;
        else p2.maxBombCnt++;
        return 0;
    }

    // �ٴ� ������ ���� ���
    if (map2[y][x] == ITEM_NEEDLE_SHOW) {
        map2[y][x] = BLANK;
        if (!player) p1.needle = 1;
        else p2.needle = 1;
        return 0;
    }

    // ����￡ ���� Player�� ���� �浹 (���� ����)
    if (map2[y][x] == !player) {
        // �÷��̾� 1
        if (!player) {
            if (p2.isBubbled) {
                winner = 1;
                return 0;
            }
            else return 1;
        }
        else {
            if (p1.isBubbled) {
                winner = 2;
                return 0;
            }
            else return 1;
        }
    }

    return 1;
}

void move_character(unsigned char ch, int time)
{
    int player; //0, 1
    int isItem = 0; // �̵��� ��� 0, 1�� ��ź, 2�� �ٴ�

    // ĳ���� ���� ��ġ
    int oldx1 = p1.x;
    int oldy1 = p1.y;
    int newx1 = p1.x;
    int newy1 = p1.y;

    int oldx2 = p2.x;
    int oldy2 = p2.y;
    int newx2 = p2.x;
    int newy2 = p2.y;

    int keep_moving = 0; // �����

    if (ch == SPECIAL1 || ch == SPECIAL2) {
        ch = getch();
        switch (ch) { //player2
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
            keep_moving = 1; // �����δ�.
            player = PLAYER2;
            // ����￡ ���������� �̵� �Ұ�
            if (p2.isBubbled) return;
            break;
        default: // ����Ű�� �ƴϸ� �����
            keep_moving = 0;
        }
    }
    else { //player1
        switch (ch) {
        case UP2:
        case DOWN2:
        case LEFT2:
        case RIGHT2:
        case SPACE:
            keep_moving = 1;
            player = PLAYER1;
            // ����￡ ���������� �̵� �Ұ�
            if (p1.isBubbled) return;
            break;
        case ENTER: //player2
            keep_moving = 1;
            player = PLAYER2;
            if (p2.isBubbled) return;
            break;
        case CTRL: //player1
            keep_moving = 1;
            player = PLAYER1;
            break;
        case BACKSPACE: //player2
            keep_moving = 1;
            player = PLAYER2;
            break;

        default: // ����Ű�� �ƴϸ� �����
            keep_moving = 0;
        }
    }

    if (keep_moving) { // �����̰� ������
        switch (ch) {
        // player 2
        case UP:
            if (oldy2 > 0)
                newy2 = oldy2 - 1; // �迭�� ��ġ �����̾ -1
            break;
        case DOWN:
            if (oldy2 < MAP1_SIZE_Y)
                newy2 = oldy2 + 1;
            break;
        case LEFT:
            if (oldx2 > 0)
                newx2 = oldx2 - 1;
            break;
        case RIGHT:
            if (oldx2 < MAP1_SIZE_X)
                newx2 = oldx2 + 1;
            break;
        case ENTER:
            isItem = 1; //��ź
            break;
        case BACKSPACE:
            isItem = 2; //�ٴ�
            break;

        // player 1
        case UP2:
            if (oldy1 > 0)
                newy1 = oldy1 - 1;
            break;
        case DOWN2:
            if (oldy1 < MAP1_SIZE_Y)
                newy1 = oldy1 + 1;
            break;
        case LEFT2:
            if (oldx1 > 0)
                newx1 = oldx1 - 1;
            break;
        case RIGHT2:
            if (oldx1 < MAP1_SIZE_X)
                newx1 = oldx1 + 1;
            break;
        case SPACE:
            isItem = 1;
            break;
        case CTRL:
            isItem = 2;
            break;
        }

        // �̵�
        if (!isItem) {
            // 1P
            if (!player) {
                // �浹 ó��
                if (!collision_detection(newx1, newy1, player)) {
                    // �迭���� ĳ���� ��ġ ����
                    map1[newy1][newx1] = PLAYER1;
                    map1[oldy1][oldx1] = BLANK;

                    int newPosX = MAP1_START_X + ArraytoMapX(newx1); //�迭�� ������
                    int newPosY = MAP1_START_Y + ArraytoMapY(newy1);
                    int oldPosX = MAP1_START_X + ArraytoMapX(oldx1);
                    int oldPosY = MAP1_START_Y + ArraytoMapY(oldy1);

                    draw_character(newPosX, newPosY, WHITE, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // ���� ������ ��ź�� ��ġ�� ��� ��ź�� �������� �ʵ��� ����
                    if (p1.setBomb) {
                        draw_bomb(oldx1, oldy1);
                        p1.setBomb = 0;
                        map1[oldy1][oldx1] = IS_BOMB;
                    }

                    // player ��ġ�� ����
                    p1.x = newx1;
                    p1.y = newy1;

                    keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
                }
            }
            // 2P
            else {
                // �浹 ó��
                if (!collision_detection(newx2, newy2, player)) {
                    // �迭���� ĳ���� ��ġ ����
                    map1[newy2][newx2] = PLAYER2;
                    map1[oldy2][oldx2] = BLANK;
                    
                    int newPosX = MAP1_START_X + ArraytoMapX(newx2);
                    int newPosY = MAP1_START_Y + ArraytoMapY(newy2);
                    int oldPosX = MAP1_START_X + ArraytoMapX(oldx2);
                    int oldPosY = MAP1_START_Y + ArraytoMapY(oldy2);
                    
                    draw_character(newPosX, newPosY, RED1, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // ���� ������ ��ź�� ��ġ�� ��� ��ź�� �������� �ʵ��� ����
                    if (p2.setBomb) {
                        draw_bomb(oldx2, oldy2);
                        p2.setBomb = 0;
                        map1[oldy2][oldx2] = IS_BOMB;
                    }

                    p2.x = newx2;
                    p2.y = newy2;

                    keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
                }
            }
        }
        else {
            // ��ź ��ġ
            if (isItem == 1) {
                switch (ch) {
                    // 1p
                case SPACE:
                    if (p1.bombCnt < p1.maxBombCnt) {
                        draw_bomb(oldx1, oldy1);
                        // ��ź ��ġ ����
                        p1.bombs[p1.bombCnt].x = oldx1;
                        p1.bombs[p1.bombCnt].y = oldy1;
                        p1.bombs[p1.bombCnt].time = time; // ��ź ��ġ �ð�
                        p1.bombCnt++; // ��ź�� ��ġ
                        p1.setBomb = 1;
                        map1[oldy1][oldx1] = PLAYER1_BOMB;
                    }
                    break;

                    // 2p
                case ENTER:
                    if (p2.bombCnt < p2.maxBombCnt) {
                        draw_bomb(oldx2, oldy2);
                        p2.bombs[p2.bombCnt].x = oldx2;
                        p2.bombs[p2.bombCnt].y = oldy2;
                        p2.bombs[p2.bombCnt].time = time;
                        p2.bombCnt++;
                        p2.setBomb = 1;
                        map1[oldy2][oldx2] = PLAYER2_BOMB;
                    }
                    break;
                }
            }

            // �ٴ� ���
            else {
                switch (ch) {
                    // 1p
                case CTRL:
                    if (p1.isBubbled && p1.needle) {
                        int oldPosX = MAP1_START_X + ArraytoMapX(oldx1);
                        int oldPosY = MAP1_START_Y + ArraytoMapY(oldy1);

                        draw_character(oldPosX, oldPosY, WHITE, BLACK);
                        p1.isBubbled = 0;
                        p1.bubbledTime = 9999;
                        p1.needle = 0;
                    }
                    break;

                    // 2p
                case BACKSPACE:
                    if (p2.isBubbled && p2.needle) {
                        int oldPosX = MAP1_START_X + ArraytoMapX(oldx2);
                        int oldPosY = MAP1_START_Y + ArraytoMapY(oldy2);

                        draw_character(oldPosX, oldPosY, RED1, BLACK);
                        p2.isBubbled = 0;
                        p2.bubbledTime = 9999;
                        p2.needle = 0;
                    }
                    break;
                }
            }
        }
    }
}
void move_character2(unsigned char ch, int time)
{
    int player;
    int isItem = 0;

    // ĳ���� ���� ��ġ
    int oldx1 = p1.x;
    int oldy1 = p1.y;
    int newx1 = p1.x;
    int newy1 = p1.y;

    int oldx2 = p2.x;
    int oldy2 = p2.y;
    int newx2 = p2.x;
    int newy2 = p2.y;

    int keep_moving = 0;

    if (ch == SPECIAL1 || ch == SPECIAL2) {
        ch = getch();
        switch (ch) {
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
            keep_moving = 1;
            player = PLAYER2;
            // ����￡ ���������� �̵� �Ұ�
            if (p2.isBubbled) return;
            break;
        default: // ����Ű�� �ƴϸ� �����
            keep_moving = 0;
        }
    }
    else {
        switch (ch) {
        case UP2:
        case DOWN2:
        case LEFT2:
        case RIGHT2:
        case SPACE:
            keep_moving = 1;
            player = PLAYER1;
            // ����￡ ���������� �̵� �Ұ�
            if (p1.isBubbled) return;
            break;
        case ENTER:
            keep_moving = 1;
            player = PLAYER2;
            if (p2.isBubbled) return;
            break;

        case CTRL:
            keep_moving = 1;
            player = PLAYER1;
            break;
        case BACKSPACE:
            keep_moving = 1;
            player = PLAYER2;
            break;

        default: // ����Ű�� �ƴϸ� �����
            keep_moving = 0;
        }
    }

    if (keep_moving) { // �����̰� ������
        switch (ch) {
            // player 2
        case UP:
            if (oldy2 > 0)
                newy2 = oldy2 - 1;
            break;
        case DOWN:
            if (oldy2 < MAP2_SIZE_Y)
                newy2 = oldy2 + 1;
            break;
        case LEFT:
            if (oldx2 > 0)
                newx2 = oldx2 - 1;
            break;
        case RIGHT:
            if (oldx2 < MAP2_SIZE_X)
                newx2 = oldx2 + 1;
            break;
        case ENTER:
            isItem = 1;
            break;
        case BACKSPACE:
            isItem = 2;
            break;

            // player 1
        case UP2:
            if (oldy1 > 0)
                newy1 = oldy1 - 1;
            break;
        case DOWN2:
            if (oldy1 < MAP2_SIZE_Y)
                newy1 = oldy1 + 1;
            break;
        case LEFT2:
            if (oldx1 > 0)
                newx1 = oldx1 - 1;
            break;
        case RIGHT2:
            if (oldx1 < MAP2_SIZE_X)
                newx1 = oldx1 + 1;
            break;
        case SPACE:
            isItem = 1;
            break;
        case CTRL:
            isItem = 2;
            break;
        }

        // �̵�
        if (!isItem) {
            // 1P
            if (!player) {
                // �浹 ó��
                if (!collision_detection2(newx1, newy1, player)) {
                    // �迭���� ĳ���� ��ġ ����
                    map2[newy1][newx1] = PLAYER_1;
                    map2[oldy1][oldx1] = BLANK;

                    int newPosX = MAP2_START_X + ArraytoMapX(newx1);
                    int newPosY = MAP2_START_Y + ArraytoMapY(newy1);
                    int oldPosX = MAP2_START_X + ArraytoMapX(oldx1);
                    int oldPosY = MAP2_START_Y + ArraytoMapY(oldy1);

                    draw_character(newPosX, newPosY, WHITE, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // ���� ������ ��ź�� ��ġ�� ��� ��ź�� �������� �ʵ��� ����
                    if (p1.setBomb) {
                        draw_bomb(oldx1, oldy1);
                        p1.setBomb = 0;
                        map2[oldy1][oldx1] = IS_BOMB;
                    }

                    // player ��ġ�� ����
                    p1.x = newx1;
                    p1.y = newy1;

                    keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
                }
            }
            // 2P
            else {
                // �浹 ó��
                if (!collision_detection2(newx2, newy2, player)) {
                    // �迭���� ĳ���� ��ġ ����
                    map2[newy2][newx2] = PLAYER_2;
                    map2[oldy2][oldx2] = BLANK;

                    int newPosX = MAP2_START_X + ArraytoMapX(newx2);
                    int newPosY = MAP2_START_Y + ArraytoMapY(newy2);
                    int oldPosX = MAP2_START_X + ArraytoMapX(oldx2);
                    int oldPosY = MAP2_START_Y + ArraytoMapY(oldy2);

                    draw_character(newPosX, newPosY, RED1, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // ���� ������ ��ź�� ��ġ�� ��� ��ź�� �������� �ʵ��� ����
                    if (p2.setBomb) {
                        draw_bomb(oldx2, oldy2);
                        p2.setBomb = 0;
                        map2[oldy2][oldx2] = IS_BOMB;
                    }

                    p2.x = newx2;
                    p2.y = newy2;

                    keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
                }
            }
        }
        else {
            // ��ź ��ġ
            if (isItem == 1) {
                switch (ch) {
                    // 1p
                case SPACE:
                    if (p1.bombCnt < p1.maxBombCnt) {
                        draw_bomb(oldx1, oldy1);
                        // ��ź ��ġ ����
                        p1.bombs[p1.bombCnt].x = oldx1;
                        p1.bombs[p1.bombCnt].y = oldy1;
                        p1.bombs[p1.bombCnt].time = time; // ��ź ��ġ �ð�
                        p1.bombCnt++; // ��ź�� ��ġ
                        p1.setBomb = 1;
                        map2[oldy1][oldx1] = PLAYER1_BOMB;
                    }
                    break;

                    // 2p
                case ENTER:
                    if (p2.bombCnt < p2.maxBombCnt) {
                        draw_bomb(oldx2, oldy2);
                        p2.bombs[p2.bombCnt].x = oldx2;
                        p2.bombs[p2.bombCnt].y = oldy2;
                        p2.bombs[p2.bombCnt].time = time;
                        p2.bombCnt++;
                        p2.setBomb = 1;
                        map2[oldy2][oldx2] = PLAYER2_BOMB;
                    }
                    break;
                }
            }

            // �ٴ� ���
            else {
                switch (ch) {
                    // 1p
                case CTRL:
                    if (p1.isBubbled && p1.needle) {
                        int oldPosX = MAP2_START_X + ArraytoMapX(oldx1);
                        int oldPosY = MAP2_START_Y + ArraytoMapY(oldy1);

                        draw_character(oldPosX, oldPosY, WHITE, BLACK);
                        p1.isBubbled = 0;
                        p1.bubbledTime = 9999;
                        p1.needle = 0;
                    }
                    break;

                    // 2p
                case BACKSPACE:
                    if (p2.isBubbled && p2.needle) {
                        int oldPosX = MAP2_START_X + ArraytoMapX(oldx2);
                        int oldPosY = MAP2_START_Y + ArraytoMapY(oldy2);

                        draw_character(oldPosX, oldPosY, RED1, BLACK);
                        p2.isBubbled = 0;
                        p2.bubbledTime = 9999;
                        p2.needle = 0;
                    }
                    break;
                }
            }
        }
    }
}


void initPlayer1()
{
    // �迭 ���� ��ġ
    p1.x = PLAYER1_POS_X;
    p1.y = PLAYER1_POS_Y;

    p1.bombCnt = 0; //���� ��ġ�� ��ź ��
    p1.maxBombCnt = 1;
    
    int i;
    for (int i = 0; i < 5; i++) {
        p1.bombs[i].x = 0;
        p1.bombs[i].y = 0;
        p1.bombs[i].time = 9999;
    }

    p1.needle = 0;
    p1.isBubbled = 0;
    p1.bubbledTime = 9999;
    p1.setBomb = 0;
}
void initPlayer2()
{
    p2.x = PLAYER2_POS_X;
    p2.y = PLAYER2_POS_Y;

    p2.bombCnt = 0;
    p2.maxBombCnt = 1;

    int i;
    for (int i = 0; i < 5; i++) {
        p2.bombs[i].x = 0;
        p2.bombs[i].y = 0;
        p2.bombs[i].time = 9999;
    }

    p2.needle = 0;
    p2.isBubbled = 0;
    p2.bubbledTime = 9999;
    p2.setBomb = 0;
}

void initPlayer1_m2()
{
    // �迭 ���� ��ġ
    p1.x = PLAYER1_POS_X_m2;
    p1.y = PLAYER1_POS_Y_m2;

    p1.bombCnt = 0;
    p1.maxBombCnt = 1;

    int i;
    for (int i = 0; i < 5; i++) {
        p1.bombs[i].x = 0;
        p1.bombs[i].y = 0;
        p1.bombs[i].time = 9999;
    }

    p1.needle = 0;
    p1.isBubbled = 0;
    p1.bubbledTime = 9999;
    p1.setBomb = 0;
}
void initPlayer2_m2()
{
    p2.x = PLAYER2_POS_X_m2;
    p2.y = PLAYER2_POS_Y_m2;

    p2.bombCnt = 0;
    p2.maxBombCnt = 1;

    int i;
    for (int i = 0; i < 5; i++) {
        p2.bombs[i].x = 0;
        p2.bombs[i].y = 0;
        p2.bombs[i].time = 9999;
    }

    p2.needle = 0;
    p2.isBubbled = 0;
    p2.bubbledTime = 9999;
    p2.setBomb = 0;
}

void UpdateBombs(int time)
{
    int i;

    // 1p
    for (i = 0; i < p1.maxBombCnt; i++) {
        if (time - p1.bombs[i].time > 30) { //3�ʰ� ������
            // ��ź ������ �Լ�
            detonate_bomb(p1.bombs[i].x, p1.bombs[i].y, time);
            p1.bombCnt--; //���� ��ġ�� ��ź ���� �پ��
            p1.bombs[i].time = 9999;
        }
    }

    // 2p
    for (i = 0; i < p2.maxBombCnt; i++) {
        if (time - p2.bombs[i].time > 30) {
            detonate_bomb(p2.bombs[i].x, p2.bombs[i].y, time);
            p2.bombCnt--;
            p2.bombs[i].time = 9999;
        }
    }
}
void UpdateBombs2(int time)
{
    int i;

    // 1p
    for (i = 0; i < p1.maxBombCnt; i++) {
        if (time - p1.bombs[i].time > 30) {
            // ��ź ������ �Լ�
            detonate_bomb2(p1.bombs[i].x, p1.bombs[i].y, time);
            p1.bombCnt--;
            p1.bombs[i].time = 9999;
        }
    }

    // 2p
    for (i = 0; i < p2.maxBombCnt; i++) {
        if (time - p2.bombs[i].time > 30) {
            detonate_bomb2(p2.bombs[i].x, p2.bombs[i].y, time);
            p2.bombCnt--;
            p2.bombs[i].time = 9999;
        }
    }
}
void UpdateInBubble(int time) {
    if (time - p1.bubbledTime > 50) { //����ź�� ������ 5�ʰ� ������ ��밡 �̱�
        winner = 2;
    }
    if (time - p2.bubbledTime > 50) {
        winner = 1;
    }
}

void GameStart()
{
    cls(WHITE, BLACK);
    draw_map();

    initPlayer1();
    initPlayer2();

    unsigned int cnt = 1; //�ð� ����
    unsigned int time = 0;
    draw_time(125, 5, time);

    while (1)
    {
        unsigned char ch;

        if (kbhit() == 1)
        {
            ch = getch();
            if (ch == ESC)
                break;

            // player
            move_character(ch, cnt);
        }

        UpdateBombs(cnt);
        UpdateInBubble(cnt);

        // 1�ʰ� ���������� ���ŵǴ� �͵�
        if (cnt % 10 == 0) {
            time++;
            textcolor(WHITE, BLACK);
            if (time == 9) {
                printf("");
            }
            draw_time(125, 5, time);
        }

        if (winner != 0) break;

        cnt += 1; // cnt�� ���� 10 ������ ������ 1�ʰ� �������ٴ� �ǹ�
        Sleep(100); // Delay�� ���̸� �ӵ��� ��������.
    }
    
    draw_end(winner);
    TitleScreen();
}

void GameStart2()
{
    cls(WHITE, BLACK);
    draw_map2();

    initPlayer1_m2();
    initPlayer2_m2();

    unsigned int cnt = 1;
    unsigned int time = 0;
    draw_time(125, 5, time);

    while (1)
    {
        unsigned char ch;

        if (kbhit() == 1)
        {
            ch = getch();
            if (ch == ESC)
                break;

            // player
            move_character2(ch, cnt);
        }

        UpdateBombs2(cnt);
        UpdateInBubble(cnt);

        // 1�ʰ� ���������� ���ŵǴ� �͵�
        if (cnt % 10 == 0) {
            time++;
            textcolor(WHITE, BLACK);
            if (time == 9) {
                printf("");
            }
            draw_time(125, 5, time);
        }

        if (winner != 0) break;

        cnt += 1; // cnt�� ���� 10 ������ ������ 1�ʰ� �������ٴ� �ǹ�
        Sleep(100); // Delay�� ���̸� �ӵ��� ��������.
    }

    draw_end(winner);
    TitleScreen();
}

void SelectMap()
{
    cls(WHITE, BLACK);

    draw_smallMap(); // ���� ��
    draw_smallMap2(); // ������ ��
    int xPos = SMALL_MAP_START_X, yPos = SMALL_MAP_START_Y; //xPOS�� ���� ��� ������
    draw_cursor(xPos, yPos); // ���� Ŀ�� �׸���
    
    unsigned char ch; //����Ű �Է��� ��

    while (1)
    {
        if (kbhit() == 1) {
            ch = getch();
            if (ch == SPECIAL1 || ch == SPECIAL2) {
                ch = getch();
                switch (ch) {
                case LEFT:
                    if (xPos > SMALL_MAP_START_X) { // Ŀ���� ��Ż�ϴ� ���� ����
                        erase_cursor(xPos, yPos);
                        xPos -= 70; // �������� ������ ���� �۾����� ����
                        draw_cursor(xPos, yPos);
                    }
                    break;
                case RIGHT:
                    if (xPos < SMALL_MAP_START_X + 70) { //Ŀ���� ��Ż�ϴ� ���� ����
                        erase_cursor(xPos, yPos);
                        xPos += 70; // ���������� ������ ���� Ŀ���� ����
                        draw_cursor(xPos, yPos);
                    }
                    break;
                }
            }
            else {
                switch (ch) {
                case LEFT2:
                    if (xPos > SMALL_MAP_START_X) {
                        erase_cursor(xPos, yPos);
                        xPos -= 70;
                        draw_cursor(xPos, yPos);
                    }
                    break;
                case RIGHT2:
                    if (xPos < SMALL_MAP_START_X + 70) {
                        erase_cursor(xPos, yPos);
                        xPos += 70;
                        draw_cursor(xPos, yPos);
                    }
                    break;
                case ENTER: case SPACE:
                    if (xPos == SMALL_MAP_START_X) GameStart(); // map1�� ���� ������ ����
                    else GameStart2(); // map2�� ���� ������ ���� 
                    break;
                case ESC:
                    exit(1);
                    break;
                }
            }
        }
    }
}

void screenchange(unsigned char m) {
    switch (m) {
    case '1':
        SelectMap();
        break;
    case ESC:
        exit(1);
        break;
    }
}

void draw_box(int x1, int y1, int x2, int y2) {
    int x, y;
    unsigned char ch;

    while (1) {
        textcolor(rand() % 16, rand() % 16);
        //�� ������
        for (x = x1; x < x2; x++) {
            gotoxy(x, y1);
            printf(" ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(1);
        }

        //������ ������
        for (y = y1; y < y2; y++) {
            gotoxy(x2 - 1, y);
            printf("  ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(15);
        }

        //�Ʒ� ������
        for (x = x2; x > x1; x--) {
            gotoxy(x, y2);
            printf(" ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(1);
        }

        //���� ������
        for (y = y2; y > y1; y--) {
            gotoxy(x1, y);
            printf("  ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(15);
        }
    }
}

void draw_menu()
{
    //�޴�
    textcolor(WHITE, BLACK);
    gotoxy(15, 20);
    printf("1 > Play");

    gotoxy(15, 22);
    printf("ESC > Quit");

    //�޴� ���� 
    textcolor(WHITE, BLACK);
    gotoxy(42, 24);
    printf("SELECT MENU : ");
}

void draw_title()
{
    char title[7][60] = {
"    111     11111       1111    111111    1  11   ",
"  111111    111111     11111   111  11    11  11   ",
" 11         11  11    11  11        11    1   11   ",
" 11         11111     11  11      111     11 11    ",
" 11   11    1111     11  111    111        111     ",
" 11  111    11 11    1111111   1111        11      ",
"  1111      11  11   11   11   1111111    111      ",
    };

    char title2[7][60] = {
    "    1111   11111      111      1111   111        111   ",
    "   11111   111111   111111    11111   11 11     11111  ",
    "  11  11   11  11   11       11  11  11   11   11      ",
    "  11  11   11111   11        11  11  11    11 1111     ",
    " 11  111   1111    11   11  11  111  11    11 11   11  ",
    " 1111111   11 11   11  111  1111111  11    11 11  111  ",
    " 11   11   11  11   1111    11   11  1111111  111111   ",
    };

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 60; j++) {
            if (title[i][j] == '1') {
                textcolor(RED1, YELLOW1);
                gotoxy(j + 20, i + 5);
                printf(" ");
            }
            if (title2[i][j] == '1') {
                textcolor(RED1, GREEN1);
                gotoxy(j + 50, i + 15);
                printf(" ");
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 60; j++) {
            if (title[i][j] == '1') {
                textcolor(RED2, YELLOW2);
                gotoxy(j + 21, i + 6);
                printf(" ");
            }
            if (title2[i][j] == '1') {
                textcolor(RED2, GREEN2);
                gotoxy(j + 51, i + 16);
                printf(" ");
            }
        }
    }
}

void TitleScreen()
{
    init();
    winner = 0; //0�̸� ���� ���� ����, 1�̸� 1p �¸�, 2�� 2p �¸�
    system("cls");
    textcolor(BLACK, WHITE);

    //CRAZY ARCADE ���
    draw_title();

    //�޴� �׸���
    draw_menu();

    draw_box(0, 0, WIDTH - 1, HEIGHT - 1);
    textcolor(BLACK, WHITE);
}

//����ȭ�鿡 winner �׸���
void draw_winner()
{
    char end[7][55] = {
     "111  11   1111    11   11  11   11  1111111  11 111   ",
     "11   11    11     111  11  111  11   11   1  111  11  ",
     "11   11    11     1111 11  1111 11   11      11   11  ",
     "11 1 11    11     11 1111  11 1111   1111    111111   ",
     "1111111    11     11  111  11  111   11      11 11    ",
     "111 111    11     11   11  11   11   11   1  11  111  ",
     "11   11   1111    11   11  11   11  1111111  11   11  ",
    };

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 55; j++) {
            if (end[i][j] == '1') {
                textcolor(RED1, YELLOW1);
                gotoxy(j + 58, i + 15);
                printf(" ");
            }
        }
    }
}

//����ȭ�� 
void draw_end(int winner) {
    cls(WHITE, BLACK);

    int x = 48;
    int y = 10;
    for (int i = 0; i < 10; i++) {
        if (winner == 2) {
            draw_character(x + i * 7, y, RED2, BLACK, 0);
            draw_character(x + i * 7, y + 15, RED2, BLACK, 0);
        }
        else {
            draw_character(x + i * 7, y, WHITE, BLACK, 0);
            draw_character(x + i * 7, y + 15, WHITE, BLACK, 0);
        }
    }
    draw_winner();

    gotoxy(70, 35);
    textcolor(WHITE, BLACK);
    printf("Press Enter to Continue");
    while (1) {
        if (kbhit()) {
            if (getch() == 13) {
                return;
            }
            else if (getch() == ESC) {
                exit(1);
            }
        }
        Sleep(1);
    }
}

void main()
{
    memcpy(tmp1, map1, sizeof(map1));
    memcpy(tmp2, map2, sizeof(map2)); 
    system("mode con cols=170 lines=50"); //ó�� â ũ�� ����
    removeCursor(); 
    TitleScreen();
}