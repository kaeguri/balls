#include "view.h"
#include "model.h"
#include <QtGui/QPainter>

View::View(QWidget* parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::StyledPanel);
    initBalls(20);
   // initWall();
    m_timer.setInterval(10);
    //m_timer.start();
    connect(&m_timer, &QTimer::timeout, this, &View::onTimeout);
}

View::~View()
{
    destroyBalls();
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
     QBrush brush(Qt::SolidPattern);
    for (i = 0; i < getNumBalls(); ++i)
    {
        pen.setColor(QColor(97, 37, 128));
        brush.setColor(QColor(161, 61, 213));
        pen.setWidth(3);
        pnt.setFont(QFont("Arial", 16));

        if (i % 2 == 0)
        {
            pen.setColor(QColor(132, 178, 45));
            brush.setColor(QColor(182, 246, 62));
        }

        pnt.setBrush(brush);
        pnt.setPen(pen);

        pnt.drawEllipse(
                    balls[i].x,
                    balls[i].y,
                    balls[i].w,
                    balls[i].h);
       // pnt.drawText(balls[i].x + 10, balls[i].y + balls[i].h, QString::number(i));
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
