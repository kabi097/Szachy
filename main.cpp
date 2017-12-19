#include "chessgame.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chessGame w;
    w.show();

    return a.exec();
}
