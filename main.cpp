#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "playerTwo.hpp"

using namespace std;

int main () 
{

    const int screenWidth = 580;
    const int screenHeight = 580;
    std::string state = "menu";

    InitWindow(screenWidth, screenHeight, "Dodge the ball 2");
    InitAudioDevice();
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Texture2D backGround = LoadTexture("assets/images/backGround.png");
        DrawTexture(backGround, -16, -19, WHITE);

        // Player one shit
        PlayerInfo playerInfo;
        playerInfo.speed_x = 7;
        playerInfo.speed_y = 7;
        playerInfo.radius = 46;

        Draw(playerInfo);
        Update(&playerInfo);

        /*if (IsKeyDown(KEY_Z))
        {
            DrawBoardOne(playerInfo);
        }*/

        // Player two shit
        PlayerInfo2 playerinfo2;
        playerinfo2.speed_x2 = 7;
        playerinfo2.speed_y2 = 7;
        playerinfo2.radius2 = 46;

        Draw(playerinfo2);
        Update(&playerinfo2);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}