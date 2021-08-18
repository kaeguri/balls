/** Модель системы шаров. */
#pragma once

/** Объявление структуры, описывающей мяч. */
struct Ball
{
    int x;
    int y;
    int xdelta;
    int ydelta;
    int w;          // Ширина мячика
    int h;          // Высота мячика
};

extern struct Ball balls[5];

struct Wall
{
    int x1;
    int y1;
    int x2;
    int y2;
};

extern struct Wall wall;

extern void initBalls(void);
extern void initWall(void);
extern void moveBalls(void);
