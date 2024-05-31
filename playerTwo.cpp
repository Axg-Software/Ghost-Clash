#include "playerTwo.hpp"

void Draw(PlayerInfo2 playerInfo2)
{
    Texture2D playerSprite = LoadTexture("assets/images/player2/player2.png");
    DrawTexture(playerSprite, playerInfo2.x2, playerInfo2.y2, WHITE);
}

void Update(PlayerInfo2* playerInfo2)
{
    if (IsKeyDown(KEY_UP))
    {
        playerInfo2->y2 -= playerInfo2->speed_y2;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        playerInfo2->y2 += playerInfo2->speed_y2;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        playerInfo2->x2 -= playerInfo2->speed_x2;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        playerInfo2->x2 += playerInfo2->speed_x2;
    }
}