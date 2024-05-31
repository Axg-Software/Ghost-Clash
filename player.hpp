#include <raylib.h>
#include <iostream>

typedef struct
{
    float x, y;
    int speed_x, speed_y, radius;
}PlayerInfo;

void Draw(PlayerInfo playerInfo);
void Update(PlayerInfo* playerInfo);

// Boards
void DrawBoardOne(PlayerInfo playerInfoBoard1);
void DrawBoardTwo(PlayerInfo playerInfoBoard2);
void DrawBoardThree(PlayerInfo playerInfoBoard3);
void DrawBoardFour(PlayerInfo playerInfoBoard4);