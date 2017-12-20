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
    void new_game();        //!<Tworzy nową sesję gry.
    void save_game();       //!<Zapisuje obecny stan gry do pliku
    void saveAs_game();     //!<Zapisuje obecny stan gry do nowego pliku
    void open_game();       //!<Otwiera i odczytuje stan gry z pliku
    void close_window();    //!<Zamyka grę
    void open_settings();   //!<Otwiera okno ustawień
    void about_qt();        //!<Otwiera okno "About Qt"
    void about_game();      //!<Otwiera okno "O grze"
    void game_over(int player); //!<Kończy aktualną grę i wyświetla komunikat o zwycięstwie.
    void setNotSaved();     //!<Ustawia stan gry na niezapisany

protected:
    void closeEvent(QCloseEvent *event);    ///Definiuje działanie w przypadku zamknięcia okna.

private:
    void createMenus();
    QString currentFile;
    bool saved;
    chessBoard *chessboard;
    chessPanel *panel;
};

#endif // CHESSGAME_H
