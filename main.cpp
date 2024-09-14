#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "playerTwo.hpp"

using namespace std;

class Player1Paddles
{
    public:
    float x, y, width, height;
    Rectangle hitbox = Rectangle{x, y, width, height};
    bool active;

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
    float x, y, width, height;
    Rectangle hitbox = Rectangle{x, y, width, height};
    bool active;

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

// Bullets
class Player1Bullets
{
    public:
    float x, y, width, height;
    int speed_x, speed_y;
    Rectangle hitbox = Rectangle{x, y, width, height};
    bool active;
    bool left;
    bool right;
    bool up;
    bool down;

    void DrawP1Bullet()
    {
        Texture2D bullet; //= LoadTexture("assets/images/player1/p1bullet.png");
        if (left == true && active == true)
        {
            bullet = LoadTexture("assets/images/player1/p1bullet.png");
        }
        else if (right == true && active == true)
        {
            bullet = LoadTexture("assets/images/player1/p1bullet.png");
        }
        else if (up == true && active == true)
        {
            bullet = LoadTexture("assets/images/player1/p1bulletUD.png");
        }
        else if (down == true && active == true)
        {
            bullet = LoadTexture("assets/images/player1/p1bulletUD.png");
        }
        DrawTexture(bullet, x, y, WHITE);
    }

    void UpdateP1Bullet()
    {
        if (left == true && active == true)
        {
            x = x - speed_x;
        }
        else if (right == true && active == true)
        {
            x = x + speed_x;
        }
        else if (up == true && active == true)
        {
            y = y - speed_y;
        }
        else if (down == true && active == true)
        {
            y = y + speed_y;
        }
    }
};

class Player2Bullets
{
    public:
    float x, y, width, height;
    int speed_x, speed_y;
    Rectangle hitbox = Rectangle{x, y, width, height};
    bool active;
    bool left;
    bool right;
    bool up;
    bool down;

    void DrawP1Bullet()
    {
        Texture2D bullet; //= LoadTexture("assets/images/player2/p2bullet.png");
        if (left == true && active == true)
        {
            bullet = LoadTexture("assets/images/player2/p2bullet.png");
        }
        else if (right == true && active == true)
        {
            bullet = LoadTexture("assets/images/player2/p2bullet.png");
        }
        else if (up == true && active == true)
        {
            bullet = LoadTexture("assets/images/player2/p2bulletUD.png");
        }
        else if (down == true && active == true)
        {
            bullet = LoadTexture("assets/images/player2/p2bulletUD.png");
        }
        DrawTexture(bullet, x, y, WHITE);
    }

    void UpdateP1Bullet()
    {
        if (left == true && active == true)
        {
            x = x - speed_x;
        }
        else if (right == true && active == true)
        {
            x = x + speed_x;
        }
        else if (up == true && active == true)
        {
            y = y - speed_y;
        }
        else if (down == true && active == true)
        {
            y = y + speed_y;
        }
        // 3==D
    }
};

Player1Paddles player1paddles;
Player2Paddles player2paddles;
Player1Bullets player1bullets;
Player2Bullets player2bullets;

int main () 
{
    const int screenWidth = 580;
    const int screenHeight = 580;
    bool shot = false;
    bool shot2 = false;
    std::string state = "menu";

    InitWindow(screenWidth, screenHeight, "Ghost Clash V1.0"); // Idk fully about the name yet but we will see :)
    InitAudioDevice();

    Sound select = LoadSound("assets/sounds/pickupCoin.wav");
    Sound dead = LoadSound("assets/sounds/explosion.wav");
    Sound shoot = LoadSound("assets/sounds/laserShoot.wav");

    SetTargetFPS(120);

    PlayerInfo playerInfo;
    playerInfo.speed_x = 7;
    playerInfo.speed_y = 7;
    playerInfo.width = 124;
    playerInfo.height = 148;
    playerInfo.score = 0;
    playerInfo.hitbox = Rectangle{playerInfo.x, playerInfo.y, playerInfo.width, playerInfo.y};

    PlayerInfo2 playerinfo2;
    playerinfo2.x2 = 350;
    playerinfo2.y2 = 250;
    playerinfo2.speed_x2 = 7;
    playerinfo2.speed_y2 = 7;
    playerinfo2.width = 124;
    playerinfo2.height = 148;
    playerinfo2.score = 0;
    playerinfo2.hitbox = Rectangle{playerinfo2.x2, playerinfo2.y2, playerinfo2.width, playerinfo2.height};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        if (state == "game")
        {
            Texture2D backGround = LoadTexture("assets/images/backGround.png");
            DrawTexture(backGround, -16, -19, WHITE);

            // Player one 
            Draw(playerInfo);
            Update(&playerInfo);

            // Player two 
            Draw(playerinfo2);
            Update(&playerinfo2);

            // Establish player vars
            Player1Bullets player1bullets;
            player1bullets.speed_x = 16;
            player1bullets.speed_y = 16;
            player1bullets.width = 81;
            player1bullets.height = 27;

            Player2Bullets player2bullets;
            player2bullets.speed_x = 16;
            player2bullets.speed_y = 16;
            player2bullets.width = 81;
            player2bullets.height = 27;
            // Player one shooting shi

            DrawText(TextFormat("Plr1 Score: %i", playerInfo.score), 30, 0, 32, BLACK);
            DrawText(TextFormat("Plr 2 Score: %i", playerinfo2.score), 270, 0, 32, BLACK);

            if (IsKeyPressed(KEY_LEFT_SHIFT))
            {
                shot = true;
                PlaySound(shoot);
            }
            if (shot == true)
            {
                player1bullets.active = true;
                player1bullets.DrawP1Bullet();
                player1bullets.UpdateP1Bullet();
            }

            if (player1bullets.x <= 0 || CheckCollisionRecs(player2paddles.hitbox, player1bullets.hitbox) && player2paddles.active == true || player1bullets.y <= 0
            || player1bullets.y >= 590 || player1bullets.x >= 590 && state == "game")
            {
                shot = false;
                player1bullets.active = false;
                player1bullets.x = playerInfo.x - 20;
                player1bullets.y = playerInfo.y + 40;
            }

            // Player two shooting
            if (IsKeyPressed(KEY_RIGHT_SHIFT))
            {
                shot2 = true;
                PlaySound(shoot);
            }
            if (shot2 == true)
            {
                player2bullets.active = true;
                player2bullets.DrawP1Bullet();
                player2bullets.UpdateP1Bullet();
            }

            if (player2bullets.x <= 0 || CheckCollisionRecs(player1paddles.hitbox, player2bullets.hitbox) && player1paddles.active == true || player2bullets.y <= 0
            || player2bullets.y >= 590 || player2bullets.x >= 590 && state == "game") // reset bullet
            {
                shot2 = false;
                player2bullets.active = false;
                player2bullets.x = playerinfo2.x2 - 20;
                player2bullets.y = playerinfo2.y2 + 40;
            }

            // Player one paddle 
            if (IsKeyDown(KEY_Z))
            {
                player1paddles.x = playerInfo.x - 70;
                player1paddles.y = playerInfo.y;
                player1paddles.width = 40;
                player1paddles.height = 153;
                player1paddles.DrawPaddleLEFT();
                player1paddles.active = true;
            }
            else if (IsKeyDown(KEY_X))
            {
                player1paddles.x = playerInfo.x + 140;
                player1paddles.y = playerInfo.y;
                player1paddles.width = 40;
                player1paddles.height = 153;
                player1paddles.DrawPaddleRIGHT();
                player1paddles.active = true;
            }
            else if (IsKeyDown(KEY_C))
            {
                player1paddles.x = playerInfo.x - 10;
                player1paddles.y = playerInfo.y - 50;
                player1paddles.width = 153;
                player1paddles.height = 40;
                player1paddles.DrawPaddleUP();
                player1paddles.active = true;
            }
            else if (IsKeyDown(KEY_V))
            {
                player1paddles.x = playerInfo.x - 10;
                player1paddles.y = playerInfo.y + 140;
                player1paddles.width = 153;
                player1paddles.height = 40;
                player1paddles.DrawPaddleDOWN();
                player1paddles.active = true;
            }
            else
            {
                player1paddles.active = false;
            }

            // Player two paddle 
            if (IsKeyDown(KEY_N))
            {
                player2paddles.x = playerinfo2.x2 - 70;
                player2paddles.y = playerinfo2.y2;
                player2paddles.width = 40;
                player2paddles.height = 153;
                player2paddles.DrawPaddleLEFT();
                player2paddles.active = true;
            }
            else if (IsKeyDown(KEY_M))
            {
                player2paddles.x = playerinfo2.x2 + 140;
                player2paddles.y = playerinfo2.y2;
                player2paddles.width = 40;
                player2paddles.height = 153;
                player2paddles.DrawPaddleRIGHT();
                player2paddles.active = true;
            }
            else if (IsKeyDown(KEY_COMMA))
            {
                player2paddles.x = playerinfo2.x2 - 10;
                player2paddles.y = playerinfo2.y2 - 50;
                player2paddles.width = 153; 
                player2paddles.height = 40;
                player2paddles.DrawPaddleUP();
                player2paddles.active = true;
            }
            else if (IsKeyDown(KEY_PERIOD))
            {
                player2paddles.x = playerinfo2.x2 - 10;
                player2paddles.y = playerinfo2.y2 + 140;
                player2paddles.width = 153;
                player2paddles.height = 40;
                player2paddles.DrawPaddleDOWN();
                player2paddles.active = true;
            }
            else
            {
                player2paddles.active = false;
            }

            // Update bullet directions
            if (IsKeyPressed(KEY_W) && player1bullets.active == false)
            {
                player1bullets.up = true;
                player1bullets.down = false;
                player1bullets.left = false;
                player1bullets.right = false;
            }
            else if (IsKeyPressed(KEY_S) && player1bullets.active == false)
            {
                player1bullets.up = false;
                player1bullets.down = true;
                player1bullets.left = false;
                player1bullets.right = false;
            }
            else if (IsKeyPressed(KEY_A) && player1bullets.active == false)
            {
                player1bullets.up = false;
                player1bullets.down = false;
                player1bullets.left = true;
                player1bullets.right = false;
            }
            else if (IsKeyPressed(KEY_D) && player1bullets.active == false)
            {
                player1bullets.up = false;
                player1bullets.down = false;
                player1bullets.left = false;
                player1bullets.right = true;
            }

            if (IsKeyPressed(KEY_UP) && player2bullets.active == false)
            {
                player2bullets.up = true;
                player2bullets.down = false;
                player2bullets.left = false;
                player2bullets.right = false;
            }
            else if (IsKeyPressed(KEY_DOWN) && player2bullets.active == false)
            {
                player2bullets.up = false;
                player2bullets.down = true;
                player2bullets.left = false;
                player2bullets.right = false;
            }
            else if (IsKeyPressed(KEY_LEFT) && player2bullets.active == false)
            {
                player2bullets.up = false;
                player2bullets.down = false;
                player2bullets.left = true;
                player2bullets.right = false;
            }
            else if (IsKeyPressed(KEY_RIGHT) && player2bullets.active == false)
            {
                player2bullets.up = false;
                player2bullets.down = false;
                player2bullets.left = false;
                player2bullets.right = true;
            }

            // Update hitbox positions
            playerInfo.hitbox = { playerInfo.x, playerInfo.y, static_cast<float>(playerInfo.width), static_cast<float>(playerInfo.height) };
            playerinfo2.hitbox = { playerinfo2.x2, playerinfo2.y2, static_cast<float>(playerinfo2.width), static_cast<float>(playerinfo2.height) };
            player1paddles.hitbox = { player1paddles.x, player1paddles.y, static_cast<float>(player1paddles.width), static_cast<float>(player1paddles.height) };
            player2paddles.hitbox = { player2paddles.x, player2paddles.y, static_cast<float>(player2paddles.width), static_cast<float>(player2paddles.height) };
            player1bullets.hitbox = { player1bullets.x, player1bullets.y, static_cast<float>(player1bullets.width), static_cast<float>(player1bullets.height) };
            player2bullets.hitbox = { player2bullets.x, player2bullets.y, static_cast<float>(player2bullets.width), static_cast<float>(player2bullets.height) };

            if (CheckCollisionRecs(playerInfo.hitbox, player2bullets.hitbox) && player2bullets.active == true)
            {
                PlaySound(dead);
                player2bullets.active = false;
                player1bullets.x = 0;
                player2bullets.x = 0;
                player1bullets.y = 0;
                player2bullets.y = 0;
                state = "dead1";
            }
            else if (CheckCollisionRecs(playerinfo2.hitbox, player1bullets.hitbox) && player1bullets.active == true)
            {
                PlaySound(dead);
                player2bullets.active = false;
                player1bullets.x = 0;
                player2bullets.x = 0;
                player1bullets.y = 0;
                player2bullets.y = 0;
                state = "dead2";
            }

            // I wish collisons in raylib could be like collisions in HaxeFlixel :(
        }
        else if (state == "menu")
        {
            Texture2D backGround = LoadTexture("assets/images/backGround.png");
            DrawTexture(backGround, -16, -19, WHITE);
            Texture2D titleMenu = LoadTexture("assets/images/titleStuff/mainMenu.png");
            DrawTexture(titleMenu, 4, 135, WHITE);

            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(select);
                state = "game";
            }
        }
        else if (state == "dead1")
        {
            player1bullets.x = 0;
            player2bullets.x = 0;
            player1bullets.y = 0;
            player2bullets.y = 0;

            Texture2D backGround = LoadTexture("assets/images/backGround.png");
            DrawTexture(backGround, -16, -19, WHITE);
            Texture2D plr1Dead = LoadTexture("assets/images/deathScreen/plr1dead.png");
            DrawTexture(plr1Dead, 0, 191, WHITE);
            playerInfo.x = 300;
            playerInfo.y = 0;
            playerinfo2.x2 = 350;
            playerinfo2.y2 = 250;

            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(select);
                playerinfo2.score = playerinfo2.score + 1;
                state = "menu";
            }
        }
        else if (state == "dead2")
        {
            player1bullets.x = 0;
            player2bullets.x = 0;
            player1bullets.y = 0;
            player2bullets.y = 0;
            Texture2D backGround = LoadTexture("assets/images/backGround.png");
            DrawTexture(backGround, -16, -19, WHITE);
            Texture2D plr2Dead = LoadTexture("assets/images/deathScreen/plr2dead.png");
            DrawTexture(plr2Dead, 0, 191, WHITE);
            playerInfo.x = 300;
            playerInfo.y = 0;
            playerinfo2.x2 = 350;
            playerinfo2.y2 = 250;

            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(select);
                playerInfo.score = playerInfo.score + 1;
                state = "menu";
            }
        }

        if (IsKeyDown(KEY_ESCAPE)) // Procrastinating doing collision
        {
            CloseWindow();
            CloseAudioDevice();
        }

        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}