#include <QtWidgets/QApplication>
#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
