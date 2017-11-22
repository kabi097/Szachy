#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

class chessGame : public QMainWindow
{
    Q_OBJECT

public:
    chessGame(QWidget *parent = 0);
    void play();

    ~chessGame();

public slots:
    void close_window();

private:
    void createMenus();
    bool saved;
    chessBoard *chessboard;
};

#endif // CHESSGAME_H
