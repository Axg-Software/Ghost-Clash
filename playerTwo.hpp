#include <raylib.h>
#include <iostream>

typedef struct
{
    float x2, y2;
    int speed_x2, speed_y2, width, height;
}PlayerInfo2;

void Draw(PlayerInfo2 playerInfo2);
void Update(PlayerInfo2* playerInfo2);