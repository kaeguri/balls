#include <QtWidgets/QApplication>
#include "main_window.h"
#include "model.h"

int main(int argc, char* argv[])
{
    loadBallsFromFile("C:\\s\\kristina\\balls\\balls.txt");
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
