#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QLabel>
#include <QDebug>
#include "chesspiece.h"

class chessSquare : public QLabel
{
    Q_OBJECT
public:
    chessSquare(int col, int row);
    void setActive(bool active);
    void setActive(QString color);
    bool isPiece();
    chessPiece* getPiece();
    void setPiece(chessPiece* piece);
    void removePiece();
    void setBackgroundColor(QString color);
    QString toChessNotation();      //Funkcja konwertuje współrzędne liczbowe pola na współrzędne w notacji szachowej
    ~chessSquare();

signals:
    void clicked(int x, int y);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    bool active;
    QString backgroundColor;
    int color;
    int column;
    int row;
    chessPiece* chesspiece;
    void setColor(int color);
};

#endif // CHESSSQUARE_H
