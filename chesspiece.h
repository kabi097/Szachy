#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QString>
#include <QPixmap>
#include <QDebug>

class chessPiece
{
public:
    chessPiece(int player_number, char sign, QString name = "");
    QPixmap getImage();
    char getSign();
    QString getName();
    int getPlayer();
    int getMoveNumber();
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
