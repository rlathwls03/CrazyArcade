#include "ca.h"

#define WIDTH 120
#define HEIGHT 30

void TitleScreen();
int winner = 0;

//2는 빨강, 3은 파랑, 4는 초록, -1은 공백, 0은 p1, 1은 p2
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
 
//3은 빨강, 2는 노랑, -1 공백, 4는 파랑, 0은 p1, 1은 p2
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

void init() { // 게임 시작 전 복사해둔 맵 배열 가져오기
    memcpy(map1, tmp1, sizeof(map1)); // 메모리의 값을 복사하는 기능을 하는 함수
    memcpy(map2, tmp2, sizeof(map2));
}

void draw_smallMap() //2는 빨강, 3은 파랑, 4는 초록, -1은 공백
{
    int x, y;
    int posX = SMALL_MAP_START_X;
    int posY = SMALL_MAP_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + y * 2; // 블록 크기가 y로 2칸, x로 4칸
        for (x = 0; x < 15; x++) {
            offsetX = posX + x * 4; 
            // 물폭탄이 숨겨져 있는 블록
            if (map1[y][x] == ITEM_BOMB) {
                draw_small_block(offsetX, offsetY, WHITE, RED2); 
            }
            // 일반 블록
            else if (map1[y][x] == NORMAL) {
                draw_small_block(offsetX, offsetY, WHITE, BLUE2);
            }
            // 파괴 불가능한 블록
            else if (map1[y][x] == SOLID) {
                draw_small_block(offsetX, offsetY, WHITE, GREEN2);
            }
            // 바늘이 숨겨져 있는 블록
            else if (map1[y][x] == ITEM_NEEDLE) {
                draw_small_block(offsetX, offsetY, WHITE, YELLOW2);
            }
            // player1 그리기
            else if (map1[y][x] == PLAYER1) {
                draw_small_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player2 그리기
            else if (map1[y][x] == PLAYER2) {
                draw_small_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else {
                continue; 
            }
        }
    }
}
void draw_smallMap2()  //1은 빨강, 0은 노랑, 99는 공백, 2는 파랑 
{
    int x, y;
    int posX = SMALL_MAP_START_X + 70;
    int posY = SMALL_MAP_START_Y;
    int offsetX, offsetY;

    for (y = 0; y < 13; y++) {
        offsetY = posY + y * 2;
        for (x = 0; x < 15; x++) {
            offsetX = posX + x * 4;
            if (map2[y][x] == 3) { //빨강
                draw_small_block(offsetX, offsetY, WHITE, RED2);
            }
            else if (map2[y][x] == 4) { //파랑
                draw_small_block(offsetX, offsetY, WHITE, BLUE2);
            } 
            else if (map2[y][x] == BLANK) { //공백
            }
            // player_1 그리기
            else if (map2[y][x] == PLAYER_1) { //p1
                draw_small_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player_2 그리기
            else if (map2[y][x] == PLAYER_2) { //p2
                draw_small_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else { //2는 노랑
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
        offsetY = posY + ArraytoMapY(y); //배열을 맵으로
        for (x = 0; x < 15; x++) {
            offsetX = posX + ArraytoMapX(x);
            // 물폭탄이 숨겨져 있는 블록
            if (map1[y][x] == ITEM_BOMB) {
                draw_block(offsetX, offsetY, WHITE, RED2);
            }
            // 일반 블록
            else if (map1[y][x] == NORMAL) {
                draw_block(offsetX, offsetY, WHITE, BLUE2);
            }
            // 파괴 불가능한 블록
            else if (map1[y][x] == SOLID) {
                draw_block(offsetX, offsetY, WHITE, GREEN2);
            }
            // 바늘이 숨겨져 있는 블록
            else if (map1[y][x] == ITEM_NEEDLE) {
                draw_block(offsetX, offsetY, WHITE, YELLOW2);
            }
            // player1 그리기
            else if (map1[y][x] == PLAYER1) {
                draw_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player2 그리기
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
            if (map2[y][x] == 3) { //빨강
                draw_block(offsetX, offsetY, WHITE, RED2);
            }
            else if (map2[y][x] == 4) { //파랑
                draw_block(offsetX, offsetY, WHITE, BLUE2);
            }
            else if (map2[y][x] == BLANK) { //공백
                //draw_character(offsetX, offsetY, WHITE, GRAY2, 0);
                //erase_character(offsetX, offsetY);
            }
            // player_1 그리기
            else if (map2[y][x] == PLAYER_1) { //p1
                draw_character(offsetX, offsetY, WHITE, BLACK, 0);
            }
            // player_2 그리기
            else if (map2[y][x] == PLAYER_2) { //p2
                draw_character(offsetX, offsetY, RED1, BLACK, 1);
            }
            else { //2은 노랑
                draw_block(offsetX, offsetY, WHITE, YELLOW2);
            }
        }
    }
}

void detonate_bomb(int x, int y, int time) // 물폭탄 터지는 함수
{
    // 배열에서 맵 좌표로 변환
    int xPos = MAP1_START_X + ArraytoMapX(x);
    int yPos = MAP1_START_Y + ArraytoMapY(y);

    // 상하좌우에 대한 일반 블록 판정
    int up = 0, down = 0, left = 0, right = 0;

    // 상하좌우에 대한 아이템 폭탄 블록 판정
    int up_bomb = 0, down_bomb = 0, left_bomb = 0, right_bomb = 0;

    // 상하좌우에 대한 아이템 바늘 블록 판정
    int up_needle = 0, down_needle = 0, left_needle = 0, right_needle = 0;

    int on_bomb = 0; // 물폭탄 위에 있는 경우
    // 캐릭터가 물폭탄 위에 있는 경우에 대한 판정
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

    // 좌
    if (x - 1 >= 0) { 
        // 적인 경우 물방울에 갇힌다.
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map1[y][x - 1] == ITEM_BOMB) {
            map1[y][x - 1] = ITEM_BOMB_SHOW;
            left_bomb = 1;
        }
        // 바늘
        else if (map1[y][x - 1] == ITEM_NEEDLE) {
            map1[y][x - 1] = ITEM_NEEDLE_SHOW;
            left_needle = 1;
        }
        // 일반 블록
        else if(map1[y][x - 1] == NORMAL) {
            map1[y][x - 1] = BLANK;
            left = 1;
        }
    }
    // 우
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map1[y][x + 1] == ITEM_BOMB) {
            map1[y][x + 1] = ITEM_BOMB_SHOW;
            right_bomb = 1;
        }
        // 바늘
        else if (map1[y][x + 1] == ITEM_NEEDLE) {
            map1[y][x + 1] = ITEM_NEEDLE_SHOW;
            right_needle = 1;
        }
        // 일반 블록
        else if(map1[y][x + 1] == NORMAL) {
            map1[y][x + 1] = BLANK;
            right = 1;
        }
    }
    // 상
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map1[y - 1][x] == ITEM_BOMB) {
            map1[y - 1][x] = ITEM_BOMB_SHOW;
            up_bomb = 1;
        }
        // 바늘
        else if (map1[y - 1][x] == ITEM_NEEDLE) {
            map1[y - 1][x] = ITEM_NEEDLE_SHOW;
            up_needle = 1;
        }
        // 일반 블록
        else if(map1[y - 1][x] == NORMAL) {
            map1[y - 1][x] = BLANK;
            up = 1;
        }
    }
    // 하
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map1[y + 1][x] == ITEM_BOMB) {
            map1[y + 1][x] = ITEM_BOMB_SHOW;
            down_bomb = 1;
        }
        // 바늘
        else if (map1[y + 1][x] == ITEM_NEEDLE) {
            map1[y + 1][x] = ITEM_NEEDLE_SHOW;
            down_needle = 1;
        }
        // 일반 블록
        else if (map1[y + 1][x] == NORMAL) {
            map1[y + 1][x] = BLANK;
            down = 1;
        }
    }

    // 물줄기 그리기
    if (up) draw_block(xPos, yPos - 3, CYAN1, CYAN1);
    if (down) draw_block(xPos, yPos + 3, CYAN1, CYAN1);
    if (left) draw_block(xPos - 7, yPos, CYAN1, CYAN1);
    if (right) draw_block(xPos + 7, yPos, CYAN1, CYAN1);
    if (!on_bomb) {
        map1[y][x] = BLANK;
        erase_block(xPos, yPos);
    }

    // 잠시 대기 후 물줄기 지우기
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
    // 배열에서 맵 좌표로 변환
    int xPos = MAP2_START_X + ArraytoMapX(x);
    int yPos = MAP2_START_Y + ArraytoMapY(y);

    // 상하좌우에 대한 일반 블록 판정
    int up = 0, down = 0, left = 0, right = 0;

    // 상하좌우에 대한 아이템 폭탄 블록 판정
    int up_bomb = 0, down_bomb = 0, left_bomb = 0, right_bomb = 0;

    // 상하좌우에 대한 아이템 바늘 블록 판정
    int up_needle = 0, down_needle = 0, left_needle = 0, right_needle = 0;

    int on_bomb = 0;
    // 캐릭터가 물폭탄 위에 있는 경우에 대한 판정
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

    // 좌
    if (x - 1 >= 0) {
        // 적인 경우 물방울에 갇힌다.
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map2[y][x - 1] == ITEM_BOMB) {
            map2[y][x - 1] = ITEM_BOMB_SHOW;
            left_bomb = 1;
        }
        // 바늘
        else if (map2[y][x - 1] == ITEM_NEEDLE) {
            map2[y][x - 1] = ITEM_NEEDLE_SHOW;
            left_needle = 1;
        }
        // 일반 블록
        else if (map2[y][x - 1] == NORMAL) {
            map2[y][x - 1] = BLANK;
            left = 1;
        }
    }
    // 우
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map2[y][x + 1] == ITEM_BOMB) {
            map2[y][x + 1] = ITEM_BOMB_SHOW;
            right_bomb = 1;
        }
        // 바늘
        else if (map2[y][x + 1] == ITEM_NEEDLE) {
            map2[y][x + 1] = ITEM_NEEDLE_SHOW;
            right_needle = 1;
        }
        // 일반 블록
        else if (map2[y][x + 1] == NORMAL) {
            map2[y][x + 1] = BLANK;
            right = 1;
        }
    }
    // 상
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map2[y - 1][x] == ITEM_BOMB) {
            map2[y - 1][x] = ITEM_BOMB_SHOW;
            up_bomb = 1;
        }
        // 바늘
        else if (map2[y - 1][x] == ITEM_NEEDLE) {
            map2[y - 1][x] = ITEM_NEEDLE_SHOW;
            up_needle = 1;
        }
        // 일반 블록
        else if (map2[y - 1][x] == NORMAL) {
            map2[y - 1][x] = BLANK;
            up = 1;
        }
    }
    // 하
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
        // 아닌 경우 블록을 깬다
        // 물폭탄 
        else if (map2[y + 1][x] == ITEM_BOMB) {
            map2[y + 1][x] = ITEM_BOMB_SHOW;
            down_bomb = 1;
        }
        // 바늘
        else if (map2[y + 1][x] == ITEM_NEEDLE) {
            map2[y + 1][x] = ITEM_NEEDLE_SHOW;
            down_needle = 1;
        }
        // 일반 블록
        else if (map2[y + 1][x] == NORMAL) {
            map2[y + 1][x] = BLANK;
            down = 1;
        }
    }

    // 물줄기 그리기
    if (up) draw_block(xPos, yPos - 3, CYAN1, CYAN1);
    if (down) draw_block(xPos, yPos + 3, CYAN1, CYAN1);
    if (left) draw_block(xPos - 7, yPos, CYAN1, CYAN1);
    if (right) draw_block(xPos + 7, yPos, CYAN1, CYAN1);
    if (!on_bomb) {
        map2[y][x] = BLANK;
        erase_block(xPos, yPos);
    }

    // 잠시 대기 후 물줄기 지우기
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

int collision_detection(int x, int y, int player) // 충돌인지
{
    // 범위를 벗어나는 경우 예외처리
    if (x < 0 || y < 0 || x > MAP1_SIZE_X - 1 || y > MAP1_SIZE_Y - 1) return 1;

    // 빈 칸
    if (map1[y][x] == BLANK) return 0;
    
    // 물폭탄 아이템 먹은 경우
    if (map1[y][x] == ITEM_BOMB_SHOW) {
        map1[y][x] = BLANK;
        if (!player) p1.maxBombCnt++; // 물폭탄을 먹어서 늘어남
        else p2.maxBombCnt++;
        return 0;
    }

    // 바늘 아이템 먹은 경우
    if (map1[y][x] == ITEM_NEEDLE_SHOW) {
        map1[y][x] = BLANK;
        if (!player) p1.needle = 1; // 보유한 바늘 수, 최대 1
        else p2.needle = 1; 
        return 0;
    }

    // 물방울에 갇힌 Player에 대한 충돌 (게임 종료)
    if (map1[y][x] == !player) {
        // 플레이어 1
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
int collision_detection2(int x, int y, int player) // 충돌인지
{
    // 범위를 벗어나는 경우 예외처리
    if (x < 0 || y < 0 || x > MAP2_SIZE_X - 1 || y > MAP2_SIZE_Y - 1) return 1;

    // 빈 칸
    if (map2[y][x] == BLANK) return 0;

    // 폭탄 아이템 먹은 경우
    if (map2[y][x] == ITEM_BOMB_SHOW) {
        map2[y][x] = BLANK;
        if (!player) p1.maxBombCnt++;
        else p2.maxBombCnt++;
        return 0;
    }

    // 바늘 아이템 먹은 경우
    if (map2[y][x] == ITEM_NEEDLE_SHOW) {
        map2[y][x] = BLANK;
        if (!player) p1.needle = 1;
        else p2.needle = 1;
        return 0;
    }

    // 물방울에 갇힌 Player에 대한 충돌 (게임 종료)
    if (map2[y][x] == !player) {
        // 플레이어 1
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
    int isItem = 0; // 이동인 경우 0, 1이 폭탄, 2가 바늘

    // 캐릭터 현재 위치
    int oldx1 = p1.x;
    int oldy1 = p1.y;
    int newx1 = p1.x;
    int newy1 = p1.y;

    int oldx2 = p2.x;
    int oldy2 = p2.y;
    int newx2 = p2.x;
    int newy2 = p2.y;

    int keep_moving = 0; // 멈춘다

    if (ch == SPECIAL1 || ch == SPECIAL2) {
        ch = getch();
        switch (ch) { //player2
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
            keep_moving = 1; // 움직인다.
            player = PLAYER2;
            // 물방울에 갇혀있으면 이동 불가
            if (p2.isBubbled) return;
            break;
        default: // 방향키가 아니면 멈춘다
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
            // 물방울에 갇혀있으면 이동 불가
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

        default: // 방향키가 아니면 멈춘다
            keep_moving = 0;
        }
    }

    if (keep_moving) { // 움직이고 있으면
        switch (ch) {
        // player 2
        case UP:
            if (oldy2 > 0)
                newy2 = oldy2 - 1; // 배열상 위치 기준이어서 -1
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
            isItem = 1; //폭탄
            break;
        case BACKSPACE:
            isItem = 2; //바늘
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

        // 이동
        if (!isItem) {
            // 1P
            if (!player) {
                // 충돌 처리
                if (!collision_detection(newx1, newy1, player)) {
                    // 배열에서 캐릭터 위치 수정
                    map1[newy1][newx1] = PLAYER1;
                    map1[oldy1][oldx1] = BLANK;

                    int newPosX = MAP1_START_X + ArraytoMapX(newx1); //배열을 맵으로
                    int newPosY = MAP1_START_Y + ArraytoMapY(newy1);
                    int oldPosX = MAP1_START_X + ArraytoMapX(oldx1);
                    int oldPosY = MAP1_START_Y + ArraytoMapY(oldy1);

                    draw_character(newPosX, newPosY, WHITE, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // 직전 동작이 폭탄을 설치한 경우 폭탄이 지워지지 않도록 설정
                    if (p1.setBomb) {
                        draw_bomb(oldx1, oldy1);
                        p1.setBomb = 0;
                        map1[oldy1][oldx1] = IS_BOMB;
                    }

                    // player 위치를 갱신
                    p1.x = newx1;
                    p1.y = newy1;

                    keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
                }
            }
            // 2P
            else {
                // 충돌 처리
                if (!collision_detection(newx2, newy2, player)) {
                    // 배열에서 캐릭터 위치 수정
                    map1[newy2][newx2] = PLAYER2;
                    map1[oldy2][oldx2] = BLANK;
                    
                    int newPosX = MAP1_START_X + ArraytoMapX(newx2);
                    int newPosY = MAP1_START_Y + ArraytoMapY(newy2);
                    int oldPosX = MAP1_START_X + ArraytoMapX(oldx2);
                    int oldPosY = MAP1_START_Y + ArraytoMapY(oldy2);
                    
                    draw_character(newPosX, newPosY, RED1, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // 직전 동작이 폭탄을 설치한 경우 폭탄이 지워지지 않도록 설정
                    if (p2.setBomb) {
                        draw_bomb(oldx2, oldy2);
                        p2.setBomb = 0;
                        map1[oldy2][oldx2] = IS_BOMB;
                    }

                    p2.x = newx2;
                    p2.y = newy2;

                    keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
                }
            }
        }
        else {
            // 폭탄 설치
            if (isItem == 1) {
                switch (ch) {
                    // 1p
                case SPACE:
                    if (p1.bombCnt < p1.maxBombCnt) {
                        draw_bomb(oldx1, oldy1);
                        // 폭탄 위치 설정
                        p1.bombs[p1.bombCnt].x = oldx1;
                        p1.bombs[p1.bombCnt].y = oldy1;
                        p1.bombs[p1.bombCnt].time = time; // 폭탄 설치 시간
                        p1.bombCnt++; // 폭탄을 설치
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

            // 바늘 사용
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

    // 캐릭터 현재 위치
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
            // 물방울에 갇혀있으면 이동 불가
            if (p2.isBubbled) return;
            break;
        default: // 방향키가 아니면 멈춘다
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
            // 물방울에 갇혀있으면 이동 불가
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

        default: // 방향키가 아니면 멈춘다
            keep_moving = 0;
        }
    }

    if (keep_moving) { // 움직이고 있으면
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

        // 이동
        if (!isItem) {
            // 1P
            if (!player) {
                // 충돌 처리
                if (!collision_detection2(newx1, newy1, player)) {
                    // 배열에서 캐릭터 위치 수정
                    map2[newy1][newx1] = PLAYER_1;
                    map2[oldy1][oldx1] = BLANK;

                    int newPosX = MAP2_START_X + ArraytoMapX(newx1);
                    int newPosY = MAP2_START_Y + ArraytoMapY(newy1);
                    int oldPosX = MAP2_START_X + ArraytoMapX(oldx1);
                    int oldPosY = MAP2_START_Y + ArraytoMapY(oldy1);

                    draw_character(newPosX, newPosY, WHITE, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // 직전 동작이 폭탄을 설치한 경우 폭탄이 지워지지 않도록 설정
                    if (p1.setBomb) {
                        draw_bomb(oldx1, oldy1);
                        p1.setBomb = 0;
                        map2[oldy1][oldx1] = IS_BOMB;
                    }

                    // player 위치를 갱신
                    p1.x = newx1;
                    p1.y = newy1;

                    keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
                }
            }
            // 2P
            else {
                // 충돌 처리
                if (!collision_detection2(newx2, newy2, player)) {
                    // 배열에서 캐릭터 위치 수정
                    map2[newy2][newx2] = PLAYER_2;
                    map2[oldy2][oldx2] = BLANK;

                    int newPosX = MAP2_START_X + ArraytoMapX(newx2);
                    int newPosY = MAP2_START_Y + ArraytoMapY(newy2);
                    int oldPosX = MAP2_START_X + ArraytoMapX(oldx2);
                    int oldPosY = MAP2_START_Y + ArraytoMapY(oldy2);

                    draw_character(newPosX, newPosY, RED1, BLACK, 0);
                    erase_character(oldPosX, oldPosY);

                    // 직전 동작이 폭탄을 설치한 경우 폭탄이 지워지지 않도록 설정
                    if (p2.setBomb) {
                        draw_bomb(oldx2, oldy2);
                        p2.setBomb = 0;
                        map2[oldy2][oldx2] = IS_BOMB;
                    }

                    p2.x = newx2;
                    p2.y = newy2;

                    keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
                }
            }
        }
        else {
            // 폭탄 설치
            if (isItem == 1) {
                switch (ch) {
                    // 1p
                case SPACE:
                    if (p1.bombCnt < p1.maxBombCnt) {
                        draw_bomb(oldx1, oldy1);
                        // 폭탄 위치 설정
                        p1.bombs[p1.bombCnt].x = oldx1;
                        p1.bombs[p1.bombCnt].y = oldy1;
                        p1.bombs[p1.bombCnt].time = time; // 폭탄 설치 시간
                        p1.bombCnt++; // 폭탄을 설치
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

            // 바늘 사용
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
    // 배열 기준 위치
    p1.x = PLAYER1_POS_X;
    p1.y = PLAYER1_POS_Y;

    p1.bombCnt = 0; //현재 설치한 폭탄 수
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
    // 배열 기준 위치
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
        if (time - p1.bombs[i].time > 30) { //3초가 지나면
            // 폭탄 터지는 함수
            detonate_bomb(p1.bombs[i].x, p1.bombs[i].y, time);
            p1.bombCnt--; //현재 설치한 폭탄 수는 줄어듦
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
            // 폭탄 터지는 함수
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
    if (time - p1.bubbledTime > 50) { //물폭탄에 갇힌지 5초가 지나면 상대가 이김
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

    unsigned int cnt = 1; //시간 세기
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

        // 1초가 지날때마다 갱신되는 것들
        if (cnt % 10 == 0) {
            time++;
            textcolor(WHITE, BLACK);
            if (time == 9) {
                printf("");
            }
            draw_time(125, 5, time);
        }

        if (winner != 0) break;

        cnt += 1; // cnt의 값이 10 증가할 때마다 1초가 지나갔다는 의미
        Sleep(100); // Delay를 줄이면 속도가 빨라진다.
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

        // 1초가 지날때마다 갱신되는 것들
        if (cnt % 10 == 0) {
            time++;
            textcolor(WHITE, BLACK);
            if (time == 9) {
                printf("");
            }
            draw_time(125, 5, time);
        }

        if (winner != 0) break;

        cnt += 1; // cnt의 값이 10 증가할 때마다 1초가 지나갔다는 의미
        Sleep(100); // Delay를 줄이면 속도가 빨라진다.
    }

    draw_end(winner);
    TitleScreen();
}

void SelectMap()
{
    cls(WHITE, BLACK);

    draw_smallMap(); // 왼쪽 맵
    draw_smallMap2(); // 오른쪽 맵
    int xPos = SMALL_MAP_START_X, yPos = SMALL_MAP_START_Y; //xPOS는 왼쪽 상단 꼭짓점
    draw_cursor(xPos, yPos); // 선택 커서 그리기
    
    unsigned char ch; //방향키 입력할 때

    while (1)
    {
        if (kbhit() == 1) {
            ch = getch();
            if (ch == SPECIAL1 || ch == SPECIAL2) {
                ch = getch();
                switch (ch) {
                case LEFT:
                    if (xPos > SMALL_MAP_START_X) { // 커서가 이탈하는 것을 방지
                        erase_cursor(xPos, yPos);
                        xPos -= 70; // 왼쪽으로 갈수록 값이 작아지기 때문
                        draw_cursor(xPos, yPos);
                    }
                    break;
                case RIGHT:
                    if (xPos < SMALL_MAP_START_X + 70) { //커서가 이탈하는 것을 방지
                        erase_cursor(xPos, yPos);
                        xPos += 70; // 오른쪽으로 갈수록 값이 커지기 때문
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
                    if (xPos == SMALL_MAP_START_X) GameStart(); // map1에 대한 게임을 실행
                    else GameStart2(); // map2에 대한 게임을 실행 
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
        //윗 가로줄
        for (x = x1; x < x2; x++) {
            gotoxy(x, y1);
            printf(" ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(1);
        }

        //오른쪽 세로줄
        for (y = y1; y < y2; y++) {
            gotoxy(x2 - 1, y);
            printf("  ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(15);
        }

        //아래 가로줄
        for (x = x2; x > x1; x--) {
            gotoxy(x, y2);
            printf(" ");
            if (kbhit()) {
                ch = getch();
                screenchange(ch);
            }
            Sleep(1);
        }

        //왼쪽 세로줄
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
    //메뉴
    textcolor(WHITE, BLACK);
    gotoxy(15, 20);
    printf("1 > Play");

    gotoxy(15, 22);
    printf("ESC > Quit");

    //메뉴 선택 
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
    winner = 0; //0이면 아직 승자 없음, 1이면 1p 승리, 2면 2p 승리
    system("cls");
    textcolor(BLACK, WHITE);

    //CRAZY ARCADE 출력
    draw_title();

    //메뉴 그리기
    draw_menu();

    draw_box(0, 0, WIDTH - 1, HEIGHT - 1);
    textcolor(BLACK, WHITE);
}

//종료화면에 winner 그리기
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

//종료화면 
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
    system("mode con cols=170 lines=50"); //처음 창 크기 지정
    removeCursor(); 
    TitleScreen();
}