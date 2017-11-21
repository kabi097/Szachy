#include "chessboard.h"

chessBoard::chessBoard(QWidget *parent) : QWidget(parent)
{
    currentPlayer = 0;
    setFixedSize(800,800);
    QGridLayout *gridlayout = new QGridLayout();

    selectColor = "blue";
    attackColor = "orange";

    chesssquares = new chessSquare**[8];
    for (int i=0; i<8; i++) {
        chesssquares[i] = new chessSquare*[8];
        for(int j=0; j<8;j++) {
            chesssquares[i][j] = new chessSquare(i,j);
            gridlayout->addWidget(chesssquares[i][j],8-i,j);
            connect(chesssquares[i][j],SIGNAL(clicked(int,int)),this,SLOT(validateClick(int,int)));
        }
    }
    this->setLayout(gridlayout);
}

void chessBoard::validateClick(int x, int y)
{
    chessSquare *square = chesssquares[x][y];
    if (square->isPiece()==true && square->getPiece()->get_player()==currentPlayer) {
        resetSquares();
        square->setActive(selectColor);
        sx = x;
        sy = y;
        //Walidacja ruchów
        switch (square->getPiece()->get_sign()) {
        case 'K':
            if (currentPlayer==0) {

            } else {

            }
            break;
        case 'B':
            if (currentPlayer==0) {

            } else {

            }
            break;
        case 'N':
            if (currentPlayer==0) {

            } else {


            }
            break;
        case 'Q':
            if (currentPlayer==0) {

            } else {

            }
            break;
        case 'R':
            if (currentPlayer==0) {

            } else {

            }
            break;
        default:
            if (currentPlayer==0) {
                if (x+1<8) {
                    chesssquares[x+1][y]->setActive(selectColor);
                    if (y+1>8 && chesssquares[x+1][y+1]->isPiece()==true && chesssquares[x+1][y+1]->getPiece()->get_player()!=currentPlayer) {
                        chesssquares[x+1][y+1]->setActive(attackColor);
                    }
                    if (y-1>=0 && chesssquares[x+1][y-1]->isPiece()==true && chesssquares[x+1][y-1]->getPiece()->get_player()!=currentPlayer) {
                        chesssquares[x+1][y-1]->setActive(attackColor);
                    }
                }
                if (chesssquares[x][y]->getPiece()->get_moveNumber()==0) chesssquares[x+2][y]->setActive(selectColor);
            } else {
                if (x-1>=0) {
                    chesssquares[x-1][y]->setActive(selectColor);
                    if (y+1<8 && chesssquares[x-1][y+1]->isPiece()==true && chesssquares[x-1][y+1]->getPiece()->get_player()!=currentPlayer) {
                        chesssquares[x-1][y+1]->setActive(attackColor);
                    }
                    if (y-1>=0 && chesssquares[x-1][y-1]->isPiece()==true && chesssquares[x-1][y-1]->getPiece()->get_player()!=currentPlayer) {
                        chesssquares[x-1][y-1]->setActive(attackColor);
                    }
                }
                if (chesssquares[x][y]->getPiece()->get_moveNumber()==0) chesssquares[x-2][y]->setActive(selectColor);
            }
            break;
        }
    } else {
        dx = x;
        dy = y;
        move();
        resetSquares();
    }
}

void chessBoard::resetSquares()
{
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (chesssquares[i][j]->isPiece()==true && chesssquares[i][j]->getPiece()->get_player()==currentPlayer) {
                chesssquares[i][j]->setActive(true);
            } else {
                chesssquares[i][j]->setActive(false);
            }
        }
    }
}


void chessBoard::setCurrentPlayer(int player)
{
    currentPlayer = player;
}

void chessBoard::move()
{
    chessPiece *sourcePiece = chesssquares[sx][sy]->getPiece();
    chesssquares[sx][sy]->removePiece();
    if (chesssquares[dx][dy]->isPiece()==true) {
        lost << chesssquares[dx][dy]->getPiece();
        chesssquares[dx][dy]->removePiece();
    }
    chesssquares[dx][dy]->setPiece(sourcePiece);

    //Zmiana gracza
    if (currentPlayer==0) currentPlayer=1;
    else currentPlayer=0;

    sourcePiece->nextMove();

}

void chessBoard::generateChessBoard()
{
    chessPiece *wrook1 = new chessPiece(0,'R',"Wieża 1");
    chessPiece *wknight1 = new chessPiece(0,'N',"Koń 1");
    chessPiece *wbishop1 = new chessPiece(0,'B',"Goniec 1");
    chessPiece *wqueen = new chessPiece(0,'Q',"Królowa");
    chessPiece *wking = new chessPiece(0,'K',"Król");
    chessPiece *wrook2 = new chessPiece(0,'R',"Wieża 2");
    chessPiece *wknight2 = new chessPiece(0,'K',"Koń 2");
    chessPiece *wbishop2 = new chessPiece(0,'B',"Goniec 2");
    chessPiece **wpawns = new chessPiece*[8];
    for (int i=0; i<8;i++) {
        wpawns[i] = new chessPiece(0,'P',"Pionek");
        chesssquares[1][i]->setPiece(wpawns[i]);
        chesssquares[1][i]->setActive(true);
    }

    chesssquares[0][0]->setPiece(wrook1);
    chesssquares[0][1]->setPiece(wknight1);
    chesssquares[0][2]->setPiece(wbishop1);
    chesssquares[0][3]->setPiece(wqueen);
    chesssquares[0][4]->setPiece(wking);
    chesssquares[0][5]->setPiece(wbishop2);
    chesssquares[0][6]->setPiece(wknight2);
    chesssquares[0][7]->setPiece(wrook2);
    chessPiece **bpawns = new chessPiece*[8];
    for (int i=0; i<8;i++) {
        bpawns[i] = new chessPiece(1,'P',"Pionek");
        chesssquares[6][i]->setPiece(bpawns[i]);
    }

    chessPiece *brook1 = new chessPiece(1,'R',"Wieża 1");
    chessPiece *bknight1 = new chessPiece(1,'N',"Koń 1");
    chessPiece *bbishop1 = new chessPiece(1,'B',"Goniec 1");
    chessPiece *bqueen = new chessPiece(1,'Q',"Królowa 1");
    chessPiece *bking = new chessPiece(1,'K',"Król 1");
    chessPiece *bbishop2 = new chessPiece(1,'B',"Goniec 2");
    chessPiece *bknight2 = new chessPiece(1,'N',"Koń 2");
    chessPiece *brook2 = new chessPiece(1,'R',"Wieża 2");

    chesssquares[7][0]->setPiece(brook1);
    chesssquares[7][1]->setPiece(bknight1);
    chesssquares[7][2]->setPiece(bbishop1);
    chesssquares[7][3]->setPiece(bqueen);
    chesssquares[7][4]->setPiece(bking);
    chesssquares[7][5]->setPiece(bbishop2);
    chesssquares[7][6]->setPiece(bknight2);
    chesssquares[7][7]->setPiece(brook2);
}

chessBoard::~chessBoard()
{
    for (int i=0; i<8; i++) {
        for(int j=0; j<8;j++) {
            if (chesssquares[i][j]->isPiece()) {
                delete chesssquares[i][j]->getPiece();
            }
        }
    }
    qDebug() << "Chessboard object deleted.";

    //TODO: Destruktor chesssquares
}
