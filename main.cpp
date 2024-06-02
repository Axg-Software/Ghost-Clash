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
        Texture2D paddleDown = LoadTexture("assets/images/player1/p1wallUD.png");
        DrawTexture(paddleDown, x, y, WHITE);
    }

    void DrawPaddleLEFT()
    {
        Texture2D paddleLeft = LoadTexture("assets/images/player1/p1wallLR.png");
        DrawTexture(paddleLeft, x, y, WHITE);
    }

    void DrawPaddleRIGHT()
    {
        Texture2D paddleRight = LoadTexture("assets/images/player1/p1wallLR.png");
        DrawTexture(paddleRight, x, y, WHITE);
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
        Texture2D paddleDown = LoadTexture("assets/images/player2/p2wallUD.png");
        DrawTexture(paddleDown, x, y, WHITE);
    }

    void DrawPaddleLEFT()
    {
        Texture2D paddleLeft = LoadTexture("assets/images/player2/p2wallLR.png");
        DrawTexture(paddleLeft, x, y, WHITE);
    }

    void DrawPaddleRIGHT()
    {
        Texture2D paddleRight = LoadTexture("assets/images/player2/p2wallLR.png");
        DrawTexture(paddleRight, x, y, WHITE);
    }
};

class Player1Bullets
{
    public:
    float x, y;
    int width, height, speed_x, speed_y;

    void DrawP1Bullet()
    {
        Texture2D bullet = LoadTexture("assets/images/player1/p1bullet.png");
        DrawTexture(bullet, x, y, WHITE);
    }

    void UpdateP1Bullet()
    {
        x = x - speed_x;
        // 3==D
    }
};

Player1Paddles player1paddles;
Player2Paddles player2paddles;
Player1Bullets player1bullets;

int main () 
{
    const int screenWidth = 580;
    const int screenHeight = 580;
    bool shot = false;
    std::string state = "game";

    InitWindow(screenWidth, screenHeight, "Ghost Clash"); // Idk fully about the name yet but we will see :)
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

            Player1Bullets player1bullets;
            player1bullets.speed_x = 16;
            player1bullets.speed_y = 16;
            player1bullets.width = 81;
            player1bullets.height = 27;

            Draw(playerinfo2);
            Update(&playerinfo2);
            Draw(playerInfo);
            Update(&playerInfo);

            // Player one shooting shi
            if (IsKeyPressed(KEY_LEFT_SHIFT))
            {
                shot = true;
            }
            if (shot == true)
            {
                player1bullets.DrawP1Bullet();
                player1bullets.UpdateP1Bullet();
            }

            if (player1bullets.x <= 0)
            {
                shot = false;
                player1bullets.x = playerInfo.x - 20;
                player1bullets.y = playerInfo.y + 40;
            }

            // Player one paddle shit
            if (IsKeyDown(KEY_Z))
            {
                player1paddles.x = playerInfo.x - 70;
                player1paddles.y = playerInfo.y;
                player1paddles.width = 40;
                player1paddles.height = 153;
                player1paddles.DrawPaddleLEFT();
            }
            else if (IsKeyDown(KEY_X))
            {
                player1paddles.x = playerInfo.x + 140;
                player1paddles.y = playerInfo.y;
                player1paddles.width = 40;
                player1paddles.height = 153;
                player1paddles.DrawPaddleRIGHT();
            }
            else if (IsKeyDown(KEY_C))
            {
                player1paddles.x = playerInfo.x - 10;
                player1paddles.y = playerInfo.y - 50;
                player1paddles.width = 153;
                player1paddles.height = 40;
                player1paddles.DrawPaddleUP();
            }
            else if (IsKeyDown(KEY_V))
            {
                player1paddles.x = playerInfo.x - 10;
                player1paddles.y = playerInfo.y + 140;
                player1paddles.width = 153;
                player1paddles.height = 40;
                player1paddles.DrawPaddleDOWN();
            }

            // Player two paddle shit
            if (IsKeyDown(KEY_N))
            {
                player2paddles.x = playerinfo2.x2 - 70;
                player2paddles.y = playerinfo2.y2;
                player2paddles.width = 40;
                player2paddles.height = 153;
                player2paddles.DrawPaddleLEFT();
            }
            else if (IsKeyDown(KEY_M))
            {
                player2paddles.x = playerinfo2.x2 + 140;
                player2paddles.y = playerinfo2.y2;
                player2paddles.width = 40;
                player2paddles.height = 153;
                player2paddles.DrawPaddleRIGHT();
            }
            else if (IsKeyDown(KEY_COMMA))
            {
                player2paddles.x = playerinfo2.x2 - 10;
                player2paddles.y = playerinfo2.y2 - 50;
                player2paddles.width = 153;
                player2paddles.height = 40;
                player2paddles.DrawPaddleUP();
            }
            else if (IsKeyDown(KEY_PERIOD))
            {
                player2paddles.x = playerinfo2.x2 - 10;
                player2paddles.y = playerinfo2.y2 + 140;
                player2paddles.width = 153;
                player2paddles.height = 40;
                player2paddles.DrawPaddleDOWN();
            }
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}