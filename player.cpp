#include "player.hpp"

void Draw(PlayerInfo playerInfo)
{
    Texture2D playerSprite = LoadTexture("assets/images/player1/player1.png");
    DrawTexture(playerSprite, playerInfo.x, playerInfo.y, WHITE);
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