#pragma once

#include <QtWidgets/QFrame>
#include <QtCore/QTimer>

class View : public QFrame
{
    Q_OBJECT
public:
    View(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
public:
    void startScene();
    void stopScene();
public slots:
    void onTimeout();
private:
    QTimer m_timer;
};
