#include "view.h"
#include "model.h"
#include <QtGui/QPainter>

View::View()
{
    m_startBut = new QPushButton(this);
    m_startBut->setText("Запуск");
    m_startBut->move(10, 10);
    connect(m_startBut, &QPushButton::clicked, this, &View::onStart);

    m_stopBut = new QPushButton(this);
    m_stopBut->setText("Оcтанов");
    m_stopBut->move(10, 40);
    connect(m_stopBut, &QPushButton::clicked, this, &View::onStop);

    initBalls();
    initWall();
    m_timer.setInterval(40);
    //m_timer.start();
    connect(&m_timer, &QTimer::timeout, this, &View::onTimeout);
}

void View::paintEvent(QPaintEvent*)
{
    int i;

    QPainter pnt(this);

    // Создание поля, в котором будут двигаться объекты
    pnt.drawRect(
                wall.x1, // leftWallx,      // x
                wall.y1, // wall_y,         // y
                wall.x2, // width() - 200,  // Ширина окна
                wall.y2  // height() - 100  // Высота окна
                );

    //Контур
    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);
    pnt.setPen(pen);

    //Заливка
    QBrush brush(Qt::SolidPattern);
    //brush.setColor(QColor(255, 150, 150));
    brush.setColor(Qt:: yellow);
    pnt.setBrush(brush);

    for (i = 0; i < 3; ++i)
    {
        pnt.drawEllipse(
                    balls[i].x,
                    balls[i].y,
                    balls[i].w,
                    balls[i].h);
    }

    brush.setColor(Qt:: blue);
    pnt.setBrush(brush);
    for (i = 3; i < 5; ++i)
    {
        pnt.drawEllipse(
                    balls[i].x,
                    balls[i].y,
                    balls[i].w,
                    balls[i].h);
    }
}

void View::onTimeout()
{
    // Перерисовка окна
    moveBalls();
    update();
}

void View::onStart()
{
    m_timer.start();
}

void View::onStop()
{
    m_timer.stop();
}
