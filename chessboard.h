#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDebug>
#include "chesssquare.h"
#include <QGridLayout>
#include <QList>


class chessBoard : public QWidget
{
    Q_OBJECT
    friend class chessSettings;
    friend class chessPanel;

public:
    chessBoard(QWidget *parent = 0);
    void generateChessPieces();         //Generuje pionki na szachownicy
    void updateColors(QString newblack, QString newwhite, QString newselect, QString newattack);
                                        //Ustawia nowy zestaw kolorów na szachownicy
    void resetChessboard();             //Czyści szachownicę - usuwa wszystkie pionki (również z listy), resetuje numer gracza
    void blockAllSquares();             //Funkcja ustawia wszystkie pola na nieaktywne
    void readFromText(QString line);

    QStringList history;                //Lista stringów przechowująca historię ruchów w notacji szachowej
    ~chessBoard();

signals:
    void checkMate(int player);         //Szach mat
    void nextMove();                    //Sygnał wysyłany każdorazowo po wykonaniu ruchu (w celu kontroli zmiennej saved)

public slots:
    void validateClick(int x, int y);

private:
    void updateSquares();               //Funkcja aktywująca tylko te pola na których znajdują się figury należące do currentPlayer.
    void move();                        //Przemieszczanie figur
    void setCurrentPlayer(int player);  //Ustawia numer aktualnego gracza
    bool checkActive(int x, int y);     //Funkcja sprawdza czy dane pola można zaznaczyć i jeśli tak - zaznacza
    void setDefaultColors();            //Odświeża kolory na szachownicy (na podstawie zmiennych whiteColor, blackColor itp.)
    int currentPlayer;
    int sx;
    int sy;
    int dx;
    int dy;
    QString whiteColor;
    QString blackColor;
    QString selectColor;
    QString attackColor;
    chessSquare ***chesssquares;    //Szachownica
    QList<chessPiece*> lost;        //Lista ze straconymi pionkami
};

#endif // CHESSBOARD_H
