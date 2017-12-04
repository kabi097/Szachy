#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QString>
#include <QPixmap>
#include <QDebug>

class chessPiece
{
public:
    chessPiece(int player_number, char sign, QString name = "");
    QPixmap get_image();
    char get_sign();
    int get_player();
    int get_moveNumber();
    void nextMove();
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
