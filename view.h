#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtCore/QTimer>

class View : public QWidget
{
    Q_OBJECT
public:
    View();
    void paintEvent(QPaintEvent *event) override;
public slots:
    void onTimeout();
    void onStart();
    void onStop();
private:
    QTimer m_timer;
    QPushButton* m_startBut;
    QPushButton* m_stopBut;
};
