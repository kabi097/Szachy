#include "chesspanel.h"

chessPanel::chessPanel(chessBoard *board, QWidget *parent) : QWidget(parent)
{
    chessboard = board;

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addStretch();
    player1 = "Gracz czarny";
    player2 = "Gracz biały";

    //Obrazek 1
    QHBoxLayout *horizontal1 = new QHBoxLayout;
    horizontal1->addStretch();
    QLabel *image1 = new QLabel(this);
    image1->setAlignment(Qt::AlignCenter);
    image1->setFixedSize(100,100);
    image1->setScaledContents(true);
    image1->setPixmap(QPixmap(":/pieces/Images/profile_black.png"));
    horizontal1->addWidget(image1);
    horizontal1->addStretch();
    layout->addLayout(horizontal1);

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

    //Obrazek 2
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    horizontal2->addStretch();
    QLabel *image2 = new QLabel(this);
    image2->setFixedSize(100,100);
    image2->setScaledContents(true);
    image2->setPixmap(QPixmap(":/pieces/Images/profile_white.png"));
    horizontal2->addWidget(image2);
    horizontal2->addStretch();
    layout->addLayout(horizontal2);

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
}

void chessPanel::updateLost()
{
    QList<chessPiece*> lostList = chessboard->lost;
    QLabel *piece = new QLabel(this);
    piece->setFixedSize(30,30);
    piece->setScaledContents(true);
    piece->setPixmap(lostList.last()->get_image());
    int i;
    if (lostList.last()->get_player()==0) {
        i = lostWhiteLayout->count();
        lostWhiteLayout->addWidget(piece, i/4, i%4);
    } else {
        i = lostBlackLayout->count();
        lostBlackLayout->addWidget(piece, i/4, i%4);
    }
}
