#include "model.h"
#include <cmath>

struct Ball balls[NUMBALLS];
//struct Wall wall;

void initBalls(void)
{
    int i;

    for (i = 0; i < 3; ++i)
    {
        balls[i].x = 70 + i * 100;
        balls[i].y = 60 + i * 100;
        balls[i].xdelta = 2;
        balls[i].ydelta = 2;
        balls[i].w = 40;
        balls[i].h = 40;
    }

    for (i = 3; i < NUMBALLS; ++i)
    {
        // balls[i].x = 60 + i * 50;
        balls[i].x = 480 + i * 100;
        //balls[i].y = 479;
        balls[i].y = -140 + i * 100;
        balls[i].xdelta = - 2;
        balls[i].ydelta = 2;
        balls[i].w = 40;
        balls[i].h = 40;
    }
}

//void initWall(void)
//{
//    wall.x1 = 50;
//    wall.y1 = 50;
//    wall.x2 = 500;
//    wall.y2 = 500;
//}

void moveBalls(void)
{
    int j;
    int i;

    for (i = 0; i < 3; ++i)
    {
        if (balls[i].x > 490 || balls[i].x < 65)
            balls[i].xdelta = - balls[i].xdelta;

        if (balls[i].y > 490 || balls[i].y < 65)
            balls[i].ydelta = - balls[i].ydelta;

        for (j = 3; j < 5; ++j)
        {
            int delta = abs(balls[j].x - balls[i].x);
            int ydelta = abs(balls[j].y - balls[i].y);
            if (balls[j].x > 490 || balls[j].x < 65)
            {
                balls[j].xdelta = - balls[j].xdelta;
            }
            else if (delta < 25 && ydelta <  40)
            {
                balls[j].xdelta = - balls[j].xdelta;
                balls[i].xdelta = - balls[i].xdelta;
            }

            //balls[j].y -= balls[j].ydelta;
            balls[j].x -= balls[j].xdelta;
            balls[i].x += balls[i].xdelta;
        }
    }
}
