#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QString>
#include <QPixmap>
#include <QDebug>

class chessPiece
{
public:
    chessPiece(int player_number, char sign, QString name = "");    //!< Konstruktor klasy chessPiece
    QPixmap getImage();     //!< Zwraca obrazek figury w postaci obiektu QPixmap
    char getSign();         //!< Zwraca znak figury
    QString getName();      //!< Zwraca słowną nazwę figury
    int getPlayer();        //!< Zwraca numer gracza do którego należy figura
    int getMoveNumber();    //!< Zwraca liczbę wykonanych ruchów figury
    void nextMove();        //!< Zwiększa licznik wykonanych ruchów o 1
    ~chessPiece();

private:
    char sign;
    QString name;
    QPixmap image;
    QString image_url;
    int moveNumber;
    int player;
};

#endif // CHESSPIECE_H
