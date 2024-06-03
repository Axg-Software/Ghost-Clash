#include <raylib.h>
#include <iostream>

typedef struct
{
    float x, y, width, height;
    int speed_x, speed_y;
    Rectangle hitbox = Rectangle{x, y, width, height};
}PlayerInfo;

void Draw(PlayerInfo playerInfo);
void Update(PlayerInfo* playerInfo);