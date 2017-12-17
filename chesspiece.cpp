#include "chesspiece.h"

chessPiece::chessPiece(int player_number, char sign, QString name)
{
    sign = sign;
    player = player_number;
    name = name;
    moveNumber = 0;

    QString player_name;
    if (player==1) {
        player_name = "black";
    } else {
        player_name = "white";
    }

    switch (sign) {
    case 'K':
        image_url = ":/pieces/Images/king_" + player_name + ".svg";
        break;
    case 'B':
        image_url = ":/pieces/Images/bishop_" + player_name + ".svg";
        break;
    case 'N':
        image_url = ":/pieces/Images/knight_" + player_name + ".svg";
        break;
    case 'Q':
        image_url = ":/pieces/Images/queen_" + player_name + ".svg";
        break;
    case 'R':
        image_url = ":/pieces/Images/rook_" + player_name + ".svg";
        break;
    default:
        image_url = ":/pieces/Images/pawn_" + player_name + ".svg";
        break;
    }
}

QPixmap chessPiece::get_image()
{
    image = QPixmap(image_url);
    return image;
}

char chessPiece::get_sign()
{
    return sign;
}

int chessPiece::get_player()
{
    return player;
}

int chessPiece::get_moveNumber()
{
    return moveNumber;
}

void chessPiece::nextMove()
{
    moveNumber++;
}

chessPiece::~chessPiece()
{
    qDebug() << "Chess piece " << name << " deleted.";
}
