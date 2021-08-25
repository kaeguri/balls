#include "main_window.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_OpaquePaintEvent);
    m_view = new View(this);

    //m_view->move(50, 50);
    //m_view->resize(800, 800);

    m_startBut = new QPushButton(this);
    m_startBut->setText("Запуск");
    m_startBut->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //m_startBut->move(480, 570);
    connect(m_startBut, &QPushButton::clicked, this, &MainWindow::onStart);

    m_stopBut = new QPushButton(this);
    m_stopBut->setText("Оcтанов");
    m_stopBut->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //m_stopBut->move(400, 570);
    connect(m_stopBut, &QPushButton::clicked, this, &MainWindow::onStop);

    QHBoxLayout* mainLay = new QHBoxLayout(this);
    mainLay->addWidget(m_view);

    QVBoxLayout* buttonLay = new QVBoxLayout;
    buttonLay->addWidget(m_startBut);
    buttonLay->addWidget(m_stopBut);
    buttonLay->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));

    mainLay->addLayout(buttonLay);
}

void MainWindow::onStart()
{
    m_view->startScene();
}

void MainWindow::onStop()
{
    m_view->stopScene();
}
