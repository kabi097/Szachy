#include "chesspiece.h"

/*!
    \class chessPiece
    \brief Klasa reprezentująca pojedynczą figurę

    Klasa zawierająca informacje o konkretnej figurze, takie jak nazwa, numer gracza - właściciela, adres obrazka itp.
*/

/*!
    \fn chessPiece::chessPiece(int player_number, char sign, QString name)
    \brief Konstruktor klasy chessPiece
    \param player_number Numer gracza-właściciela. 0 - biały,  1 - czarny
    \param sign Znak rezprezentujący figurę (np 'K' - król)
    \param name Słowny opis figury

    Konstruktor klasy chessPiece przypisuje zmiennym prywatnym wartości z argumentów oraz
    ustawia konkretny obraz na podstawie znaku sign.
*/

chessPiece::chessPiece(int player_number, char sign, QString name)
{
    this->sign = sign;
    this->name = name;
    this->player = player_number;
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

/*!
    \fn QPixmap chessPiece::getImage()

    Funkcja zwraca obrazek figury w postaci obiektu typu QPixmap.
*/

QPixmap chessPiece::getImage()
{
    image = QPixmap(image_url);
    return image;
}

char chessPiece::getSign()
{
    return sign;
}

QString chessPiece::getName()
{
    return name;
}

int chessPiece::getPlayer()
{
    return player;
}

int chessPiece::getMoveNumber()
{
    return moveNumber;
}

void chessPiece::nextMove()
{
    moveNumber++;
}

chessPiece::~chessPiece()
{
    //qDebug() << "Chess piece " << name << " deleted.";
}
