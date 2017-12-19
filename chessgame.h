#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include "chesspanel.h"
#include "chesssettings.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QStatusBar>
#include <QApplication>
#include <QFileDialog>

class chessGame : public QMainWindow
{
    Q_OBJECT

public:
    chessGame(QWidget *parent = 0);
    ~chessGame();

public slots:
    void new_game();
    void save_game();
    void saveAs_game();
    void open_game();
    void close_window();
    void open_settings();
    void about_qt();
    void about_game();
    void game_over(int player);
    void setNotSaved();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createMenus();
    QString currentFile;
    bool saved;
    chessBoard *chessboard;
    chessPanel *panel;
};

#endif // CHESSGAME_H
