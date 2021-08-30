#include "model.h"
#include <cmath>

struct Ball balls[NUMBALLS];
static int sceneWidth = 800;    // Ширина области моделирования
static int sceneHeight = 800;   // Высота области моделирования

void initBalls(void)
{
    int i;

    for (i = 0; i < 3; ++i)
    {
        balls[i].x = 70 + i * 100;
        balls[i].y = 60 + i * 100;
        balls[i].xdelta = 2 + i * 2;
        balls[i].ydelta = 2 + i * 2;
        balls[i].w = 40;
        balls[i].h = 40;
    }

    for (i = 3; i < NUMBALLS; ++i)
    {
        balls[i].x = 480 + (i - 3) * 100;
        balls[i].y = 100 + (i - 3)* 100;
        balls[i].xdelta = - 2;
        balls[i].ydelta = - 2;
        balls[i].w = 40;
        balls[i].h = 40;
    }

    // Постусловие:
    // 1. Все мячики в пределах области моделирования
    // 2. Нет пересекающихся мячиков
}

void setSceneArea(int width, int height)
{
    sceneWidth = width;
    sceneHeight = height;
}

int getSceneWidth()
{
    return sceneWidth;
}

int getSceneHeight()
{
    return sceneHeight;
}

void swap(int* v1, int* v2)
{
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
}

void moveBalls(void)
{
    int j;
    int i;
    int collisionx = 0;
    int collisiony = 0;

    // Предусловие алгоритма:
    // 1. Все мячики в пределах области моделирования
    // 2. Нет пересекающихся мячиков

    // Шаг 1. Изменение положения каждого мячика
    for (i = 0; i < NUMBALLS; ++i)
    {
        balls[i].x += balls[i].xdelta;
        balls[i].y += balls[i].ydelta;
    }

    // Шаг 2. Проверка столкновения со стеной
    for (i = 0; i < NUMBALLS; ++i)
    {
        // Шаг 2.1. Проверяем столкновение с правой стеной
        if (balls[i].x + balls[i].w >= sceneWidth)
        {
            balls[i].x -= balls[i].xdelta;
            balls[i].xdelta = - balls[i].xdelta;
        }

        // Шаг 2.2. Проверка столкнования с левой стеной
        if (balls[i].x <= 0)
        {
            balls[i].x -= balls[i].xdelta;
            balls[i].xdelta = - balls[i].xdelta;
        }

        // Шаг 2.3. Проверяем столкновение с нижней стеной
        if (balls[i].y + balls[i].h >= sceneHeight)
        {
            balls[i].y -= balls[i].ydelta;
            balls[i].ydelta = - balls[i].ydelta;
        }

        // Шаг 2.4. Проверяем столкновение с верхней стеной
        if (balls[i].y <= 0)
        {
            balls[i].y -= balls[i].ydelta;
            balls[i].ydelta = - balls[i].ydelta;
        }
    }

    // Шаг 3. Проверка попарного столкнования мячиков
    for (i = 0; i < NUMBALLS; ++i)
    {
        for (j = i; j < NUMBALLS; ++j)
        {
            collisionx = (abs(balls[i].x - balls[j].x) <= (balls[i].w + balls[j].w) / 2) ? 1 : 0;
            collisiony = (abs(balls[i].y - balls[j].y) <= (balls[i].h + balls[j].h) / 2) ? 1 : 0;

            if (collisionx == 1 && collisiony == 1)
            {
                swap(&(balls[i].xdelta), &(balls[j].xdelta));
                swap(&(balls[i].ydelta), &(balls[j].ydelta));
            }
        }
    }
}
