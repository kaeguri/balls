#include "main_window.h"
#include "model.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_OpaquePaintEvent);
    m_view = new View(this);
    m_view->setFixedWidth(getSceneWidth());
    m_view->setFixedHeight(getSceneHeight());
    m_view->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

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

    text = new QLabel(this);
    text->setText("Ось Х: ");

    QHBoxLayout* mainLay = new QHBoxLayout(this);
    mainLay->addWidget(m_view, 0, Qt::AlignTop | Qt::AlignLeft);

    number = new QLineEdit;
    number->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    number->setValidator(new QIntValidator (0, 100, this));

    QVBoxLayout* buttonLay = new QVBoxLayout;
    QVBoxLayout* settingsLay = new QVBoxLayout;

    settingsLay->addWidget(text);
    settingsLay->addWidget(number);
    settingsLay->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));

    buttonLay->addWidget(m_startBut);
    buttonLay->addWidget(m_stopBut);
    buttonLay->addItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));

    mainLay->addLayout(settingsLay);
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
