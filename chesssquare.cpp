#include "chesssquare.h"

chessSquare::chessSquare(int col, int row)
{
    setFixedSize(100,100);
    setScaledContents(true);
    this->column = col;
    this->row = row;
    this->chesspiece = nullptr;
    //this->selected = false;
    //this->enabled = false;
    this->active = false;

    //Ustawiamy kolor
    if (col%2==0) {
        if (row%2==0) {
           setColor(1);
           defaultColor = "grey";
        } else {
           setColor(0);
           defaultColor = "white";
        }
    } else {
        if (row%2==0) {
           setColor(0);
           defaultColor = "white";
        } else {
           setColor(1);
           defaultColor = "grey";
        }
    }
    qDebug() << "Chess square " << col << " " << row << " created.";
}

void chessSquare::setActive(bool active)
{
    this->active = active;
    setStyleSheet("QLabel { background-color : " + defaultColor + "; }");
}

void chessSquare::setActive(QString color)
{
    this->active = true;
    setStyleSheet("QLabel { background-color : " + color + "; }");
}

bool chessSquare::isPiece()
{
    if (chesspiece!=nullptr) {
        return true;
    } else {
        return false;
    }
}

chessPiece* chessSquare::getPiece()
{
    return chesspiece;
}

void chessSquare::setPiece(chessPiece *piece)
{
    this->chesspiece = piece;
    setPixmap(chesspiece->get_image());
}

void chessSquare::removePiece()
{
    chesspiece = nullptr;
    QPixmap empty(0,0);
    setPixmap(empty);
}

chessSquare::~chessSquare()
{
    qDebug() << "Chess square " << column << row << " deleted.";
}

void chessSquare::mousePressEvent(QMouseEvent* event) {
    if (active==true) {
        emit clicked(column, row);
    }
}

void chessSquare::setColor(int color)
{
    switch (color) {
    case 0:
        setStyleSheet("QLabel { background-color : white; }");
        break;
    case 1:
        setStyleSheet("QLabel { background-color : grey; }");
        break;
    default:
        throw QString("Incorrect chess square color");
        break;
    }
    this->color = color;
}
