#ifndef CHESSPLAYER_H
#define CHESSPLAYER_H

#include <QString>
#include <QList>
#include "chesspiece.h"

class chessPlayer
{
public:
    chessPlayer();
    virtual ~chessPlayer();

public slots:
    void addLostPiece(chessPiece* piece);
    int getNumber();

private:
    QString name;
    int number;
    QList<chessPiece*> lostPieces;

};

#endif // CHESSPLAYER_H
