#pragma once
#include <QWidget>
#include <QPushButton>
#include "view.h"
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void onStart();
    void onStop();

private:
    View* m_view;
    QPushButton* m_startBut;
    QPushButton* m_stopBut;
    QLineEdit* number;
    QLabel* text;
};
