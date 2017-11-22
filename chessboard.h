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
    void setCurrentPlayer(int player);
    void move();
    bool checkActive(int x, int y);
    void generateChessPieces();
    ~chessBoard();

signals:
    void selectedPiece(int x, int y, chessPiece* piece);
    void selectedMove(int x, int y);

public slots:
    void validateClick(int x, int y);

private:
    void resetSquares();    //Funkcja aktywująca tylko te pola na których znajdują się figury należące do currentPlayer.
    int currentPlayer;
    int sx;
    int sy;
    int dx;
    int dy;
    QString whiteColor;
    QString blackColor;
    QString selectColor;
    QString attackColor;
    chessSquare ***chesssquares;
    QList<chessPiece*> lost;
};

#endif // CHESSBOARD_H
