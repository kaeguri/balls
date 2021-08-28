#include "view.h"
#include "model.h"
#include <QtGui/QPainter>

View::View(QWidget* parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::StyledPanel);
    initBalls();
   // initWall();
    m_timer.setInterval(40);
    //m_timer.start();
    connect(&m_timer, &QTimer::timeout, this, &View::onTimeout);
}

void View::paintEvent(QPaintEvent* e)
{
    QFrame::paintEvent(e);

    int i;

    QPainter pnt(this);

//    // Создание поля, в котором будут двигаться объекты
//    pnt.drawRect(
//                wall.x1, // leftWallx,      // x
//                wall.y1, // wall_y,         // y
//                wall.x2, // width() - 200,  // Ширина окна
//                wall.y2  // height() - 100  // Высота окна
//                );

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

void View::startScene()
{
    m_timer.start();
}

void View::stopScene()
{
    m_timer.stop();
}
