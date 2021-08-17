#include "model.h"

struct Ball balls[5];
struct Wall wall;

void initBalls(void)
{
    int i;

    for (i = 0; i < 5; ++i)
    {
        balls[i].x = 100 + i * 50;
        balls[i].y = 100 + i * 50;
        balls[i].xdelta = 10;
        balls[i].ydelta = 0;
        balls[i].w = 40;
        balls[i].h = 40;
    }
}

void initWall(void)
{
    wall.x1 = 50;
    wall.y1 = 50;
    wall.x2 = 500;
    wall.y2 = 500;
}

void moveBalls(void)
{
    int i;

    for (i = 0; i < 5; ++i)
    {
        balls[i].x += balls[i].xdelta;
    }
}
