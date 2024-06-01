#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "playerTwo.hpp"

using namespace std;

class Player1Paddles
{
    public:
    float x, y;
    int width, height;

    // All paddles for player 1
    void DrawPaddleUP()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player1/p1wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleDOWN()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player1/p1wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleLEFT()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player1/p1wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleRIGHT()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player1/p1wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }
};

class Player2Paddles
{
    public:
    float x, y;
    int width, height;

    // All paddles for player 2
    void DrawPaddleUP()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player2/p2wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleDOWN()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player2/p2wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleLEFT()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player2/p2wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }

    void DrawPaddleRIGHT()
    {
        Texture2D paddleUP = LoadTexture("assets/images/player2/p2wallUD.png");
        DrawTexture(paddleUP, x, y, WHITE);
    }
};

Player1Paddles player1paddles;
Player2Paddles player2paddles;

int main () 
{
    const int screenWidth = 580;
    const int screenHeight = 580;
    std::string state = "game";

    InitWindow(screenWidth, screenHeight, "Dodge the ball 2");
    InitAudioDevice();
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (state == "game")
        {
            Texture2D backGround = LoadTexture("assets/images/backGround.png");
            DrawTexture(backGround, -16, -19, WHITE);

            // Player one shit
            PlayerInfo playerInfo;
            playerInfo.speed_x = 7;
            playerInfo.speed_y = 7;
            playerInfo.width = 124;
            playerInfo.height = 148;

            // Player two shit
            PlayerInfo2 playerinfo2;
            playerinfo2.speed_x2 = 7;
            playerinfo2.speed_y2 = 7;
            playerinfo2.width = 124;
            playerinfo2.height = 148;

            // Establish paddle shit 
            player1paddles.x = playerInfo.x - 30;

            Draw(playerinfo2);
            Update(&playerinfo2);
            Draw(playerInfo);
            Update(&playerInfo);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}