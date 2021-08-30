/** Модель системы шаров. */
#pragma once

const int NUMBALLS = 5;

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

extern void initBalls(void);
extern void moveBalls(void);
extern void setSceneArea(int width, int height);
extern int getSceneWidth();
extern int getSceneHeight();
