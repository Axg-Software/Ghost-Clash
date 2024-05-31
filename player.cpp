#include "player.hpp"

void Draw(PlayerInfo playerInfo)
{
    Texture2D playerSprite = LoadTexture("assets/images/player1/player1.png");
    DrawTexture(playerSprite, playerInfo.x, playerInfo.y, WHITE);
}

void DrawBoardOne(PlayerInfo playerInfoBoard) //I already know this looks like shit but its aight for now [5-31-24]
{
    Texture2D boardOne = LoadTexture("assets/images/player1/p1wallLR.png");
    DrawTexture(boardOne, playerInfoBoard.x - 20, playerInfoBoard.y, WHITE);
}

void DrawBoardTwo(PlayerInfo playerInfoBoard2)
{
    Texture2D boardOne = LoadTexture("assets/images/player1/p1wallLR.png");
    DrawTexture(boardOne, playerInfoBoard2.x + 20, playerInfoBoard2.y, WHITE);
}

void DrawBoardThree(PlayerInfo playerInfoBoard3)
{
    Texture2D boardOne = LoadTexture("assets/images/player1/p1wallUD.png");
    DrawTexture(boardOne, playerInfoBoard3.x, playerInfoBoard3.y - 20, WHITE);
}

void DrawBoardFour(PlayerInfo playerInfoBoard4)
{
    Texture2D boardOne = LoadTexture("assets/images/player1/p1wallUD.png");
    DrawTexture(boardOne, playerInfoBoard4.x, playerInfoBoard4.y + 20, WHITE);
}

void Update(PlayerInfo* playerInfo)
{
    // Movement
    if (IsKeyDown(KEY_W))
    {
        playerInfo->y -= playerInfo->speed_y;
    }
    if (IsKeyDown(KEY_S))
    {
        playerInfo->y += playerInfo->speed_y;
    }
    if (IsKeyDown(KEY_A))
    {
        playerInfo->x -= playerInfo->speed_x;
    }
    if (IsKeyDown(KEY_D))
    {
        playerInfo->x += playerInfo->speed_x;
    }
}