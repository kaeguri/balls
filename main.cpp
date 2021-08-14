#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QTimer>
#include <iostream>
#include <QPixmap>

class MyWidget : public QWidget
{
    QTimer m_timer;
    //Параметры для 1 шара
    int b1_x = 200;
    int b1_y = 200;
    int b1_xdelta = 10;

    int leftWallx = 50;

    //Параметры для 2 шара
    int b2_x = 200;
    int b2_y = 200;
    int b2_ydelta = 10;
    //int b2_xdelta = 10;

    int wall_y = 50;


public:
    MyWidget()
    {
        m_timer.setInterval(20);
        m_timer.start();
        connect(&m_timer, &QTimer::timeout, this, &MyWidget::onTimeout);
    }

    virtual void paintEvent(QPaintEvent *event) //<- Вывелось вот тут
    {   //Вывелось Unused parameter event, поэтому добавила строку Q_UNUSED
        Q_UNUSED(event);

        //Создание поля, в котором будут двигаться объекты
        QPainter pnt(this);
                    //х,        у,      ширина окна,   высота окна
        pnt.drawRect(leftWallx, wall_y, width() - 200, height() - 100);

//1 шар
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

        if (b1_x + b1_xdelta > width() - 200)
            b1_xdelta = -5;
        else if (b1_x + b1_xdelta < leftWallx + 10)
            b1_xdelta = 5;

        b1_x += b1_xdelta;
        pnt.drawEllipse(b1_x, b1_y, 40, 40);

//2 шар

        QPen pen2;
        pen2.setColor(Qt:: yellow);
        pen2.setWidth(5);
        pnt.setPen(pen2);

        QBrush brush2(Qt:: SolidLine);
        brush2.setColor(Qt:: green);
        pnt.setBrush(brush2);

        if (b2_y + b2_ydelta > height() - 100)
            b2_ydelta = -5;
        else if (b2_y + b2_ydelta < wall_y + 10)
            b2_ydelta = 5;

        b2_y += b2_ydelta;
        pnt.drawEllipse(b2_x, b2_y, 40,40);

        /*QPixmap q;
        q.load("C:/projects/balls/cat.png");

        if(b2_y + b2_ydelta > height() - 120)
            b2_ydelta = -5;
        else if (b2_y + b2_ydelta < wall_y + 10)
            b2_ydelta = 5;

        pnt.drawPixmap(b2_x, b2_y, 64, 64, q);*/




    }

public slots:
    void onTimeout()
    {
        // Перерисовка окна
        // std::cout << "onTimeout" << std::endl;
        update();
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}
