#include "model.h"

struct Ball balls[5];
struct Wall wall;

void initBalls(void)
{
    int i;

    for (i = 0; i < 3; ++i)
    {
        balls[i].x = 70;
        balls[i].y = 60 + i * 50;
        balls[i].xdelta = 10;
        balls[i].ydelta = 0;
        balls[i].w = 40;
        balls[i].h = 40;
    }

    for (i = 3; i < 6; ++i){

        balls[i].x = 60 + i * 50;
        balls[i].y = 479;
        balls[i].xdelta = 0;
        balls[i].ydelta = 10;
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

    for (i = 0; i < 3; ++i) {

        if (balls[i].x > 490 or balls[i].x < 65) balls[i].xdelta = - balls[i].xdelta;


        balls[i].x += balls[i].xdelta;

    }

    for (i = 3; i < 5; ++i)  {

        if (balls[i].y < 60 or balls[i].y > 490) balls[i].ydelta = - balls[i].ydelta;


        balls[i].y -= balls[i].ydelta;

    }




}
