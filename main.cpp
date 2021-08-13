#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QTimer>
#include <iostream>

class MyWidget : public QWidget
{
    QTimer m_timer;
    int m_x = 200;
    int m_y = 200;
    int m_xdelta = 10;

public:
    MyWidget()
    {
        m_timer.setInterval(30);
        m_timer.start();
        connect(&m_timer, &QTimer::timeout, this, &MyWidget::onTimeout);
    }

    virtual void paintEvent(QPaintEvent *event)
    {
        QPainter pnt(this);

        pnt.drawRect(50, 50, width() - 200, height() - 100);

        QPen pen;
        pen.setColor(Qt::blue);
        pen.setWidth(5);
        pnt.setPen(pen);
        QBrush brush(Qt::SolidPattern);
        brush.setColor(QColor(255, 150, 150));
        pnt.setBrush(brush);

        if (m_x + m_xdelta > width() - 20)
            m_xdelta = -10;
        else if (m_x + m_xdelta < 20)
            m_xdelta = 10;

        m_x += m_xdelta;
        pnt.drawEllipse(m_x, m_y, 100, 100);
    }

public slots:
    void onTimeout()
    {
        // Перерисовка окна
        std::cout << "onTimeout" << std::endl;
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
