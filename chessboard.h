#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDebug>
#include "chesssquare.h"
#include <QGridLayout>
#include <QList>

class chessBoard : public QWidget
{
    Q_OBJECT
public:
    chessBoard(QWidget *parent = 0);
    void setCurrentPlayer(int player);  //Ustawia numer aktualnego gracza
    bool checkActive(int x, int y);     //Funkcja sprawdza czy dane pola można zaznaczyć i jeśli tak - zaznacza
    void generateChessPieces();         //Generuje pionki na szachownicy
    void blockAllSquares();
    ~chessBoard();

signals:
    void selectedPiece(int x, int y, chessPiece* piece);
    void selectedMove(int x, int y);
    void selectedPlayer(int player);
    void checkMate(int player);

public slots:
    void validateClick(int x, int y);

private:
    void resetSquares();    //Funkcja aktywująca tylko te pola na których znajdują się figury należące do currentPlayer.
    void move();            //Przemieszczanie figur
    int currentPlayer;
    int sx;
    int sy;
    int dx;
    int dy;
    QString whiteColor;
    QString blackColor;
    QString selectColor;
    QString attackColor;
    chessSquare ***chesssquares; //Szachownica
    QList<chessPiece*> lost;    //Lista ze straconymi pionkami
};

#endif // CHESSBOARD_H
