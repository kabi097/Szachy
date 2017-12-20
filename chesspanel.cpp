#include "chesspanel.h"

/*!
    \class chessPanel
    \brief Odpowiada za prawidłowe wyświetlanie i działanie panelu bocznego.

    Klasa ta dziedziczy po QWidget. Tworzy nowe panel na którym widoczne są ikony użytkowników oraz ich nazwy.
    Dodatkowo wyświetla listę straconych figur dla każdego gracza.
    Klasa ta korzysta z zaprzyjaźnienia z klasą chessSquares w celu dostępu do listy straconych pionków.
*/

chessPanel::chessPanel(chessBoard *board, QWidget *parent) : QWidget(parent)
{
    chessboard = board;

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addStretch();
    player1 = "Gracz czarny";
    player2 = "Gracz biały";

    //Strzałka 1
    QHBoxLayout *horizontal1 = new QHBoxLayout;
    horizontal1->addStretch();
    arrowblack = new QLabel(this);
    arrowblack->setFixedSize(20,20);
    arrowblack->setScaledContents(true);
    horizontal1->addWidget(arrowblack);
    horizontal1->addStretch();
    layout->addLayout(horizontal1);

    //Obrazek 1
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    horizontal2->addStretch();
    QLabel *image1 = new QLabel(this);
    image1->setAlignment(Qt::AlignCenter);
    image1->setFixedSize(100,100);
    image1->setScaledContents(true);
    image1->setPixmap(QPixmap(":/pieces/Images/profile_black.png"));
    horizontal2->addWidget(image1);
    horizontal2->addStretch();
    layout->addLayout(horizontal2);

    //Nazwa gracza 1
    QLabel *name1 = new QLabel(player1, this);
    //name1->setFixedWidth(100);
    name1->setAlignment(Qt::AlignCenter);
    name1->setFont(QFont("Times", 14, QFont::Bold));
    layout->addWidget(name1);

    //Figury stracone przez Gracza 1

    lostWhiteLayout = new QGridLayout;
    layout->addLayout(lostWhiteLayout);

    layout->addStretch();

    //Strzałka 2
    QHBoxLayout *horizontal3 = new QHBoxLayout;
    horizontal3->addStretch();
    arrowwhite = new QLabel(this);
    arrowwhite->setFixedSize(20,20);
    arrowwhite->setScaledContents(true);
    horizontal3->addWidget(arrowwhite);
    horizontal3->addStretch();
    layout->addLayout(horizontal3);

    //Obrazek 2
    QHBoxLayout *horizontal4 = new QHBoxLayout;
    horizontal4->addStretch();
    QLabel *image2 = new QLabel(this);
    image2->setFixedSize(100,100);
    image2->setScaledContents(true);
    image2->setPixmap(QPixmap(":/pieces/Images/profile_white.png"));
    horizontal4->addWidget(image2);
    horizontal4->addStretch();
    layout->addLayout(horizontal4);

    //Nazwa gracza 2
    QLabel *name2 = new QLabel(player2, this);
    name2->setAlignment(Qt::AlignCenter);
    name2->setFont(QFont("Times", 14, QFont::Bold));
    layout->addWidget(name2);

    //Figury stracone przez Gracza 2

    lostBlackLayout = new QGridLayout;
    layout->addLayout(lostBlackLayout);


    layout->addStretch();

    this->setLayout(layout);
    updateCurrentPlayer();
}

void chessPanel::updateLost()
{
    QList<chessPiece*> lostList = chessboard->lost;
    QLabel *piece = new QLabel(this);
    piece->setFixedSize(30,30);
    piece->setScaledContents(true);
    piece->setPixmap(lostList.last()->getImage());
    int i;
    if (lostList.last()->getPlayer()==0) {
        i = lostWhiteLayout->count();
        lostWhiteLayout->addWidget(piece, i/4, i%4);
    } else {
        i = lostBlackLayout->count();
        lostBlackLayout->addWidget(piece, i/4, i%4);
    }
}

void chessPanel::clearLost()
{
    QLayoutItem *oldpiece;
    while ((oldpiece = lostWhiteLayout->takeAt(0)) != 0) {
        oldpiece->widget()->setParent(0);
      delete oldpiece;
    }

    while ((oldpiece = lostBlackLayout->takeAt(0)) != 0) {
      oldpiece->widget()->setParent(0);
      delete oldpiece;
    }
}

chessPanel::~chessPanel()
{
    clearLost();
}

void chessPanel::updateCurrentPlayer()
{
    QPixmap empty(0,0);
    QPixmap arrow(":/others/Images/arrow.png");
    if (chessboard->currentPlayer==0) {
        arrowwhite->setPixmap(arrow);
        arrowblack->setPixmap(empty);
    } else {
        arrowblack->setPixmap(arrow);
        arrowwhite->setPixmap(empty);
    }
}
