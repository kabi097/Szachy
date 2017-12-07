#include "chesspanel.h"

chessPanel::chessPanel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addStretch();
    player1 = "Gracz 1";
    player2 = "Gracz 2";

    //Obrazek 1
    QHBoxLayout *horizontal1 = new QHBoxLayout;
    horizontal1->addStretch();
    QLabel *image1 = new QLabel;
    image1->setAlignment(Qt::AlignCenter);
    image1->setFixedSize(100,100);
    image1->setScaledContents(true);
    image1->setPixmap(QPixmap(":/pieces/Images/pawn_black.svg"));
    horizontal1->addWidget(image1);
    horizontal1->addStretch();
    layout->addLayout(horizontal1);

    //Nazwa gracza 1
    QLabel *name1 = new QLabel(player1);
    //name1->setFixedWidth(100);
    name1->setAlignment(Qt::AlignCenter);
    name1->setFont(QFont("Times", 14, QFont::Bold));
    layout->addWidget(name1);

    layout->addStretch();

    //Obrazek 2
    QHBoxLayout *horizontal2 = new QHBoxLayout;
    horizontal2->addStretch();
    QLabel *image2 = new QLabel;
    image2->setFixedSize(100,100);
    image2->setScaledContents(true);
    image2->setPixmap(QPixmap(":/pieces/Images/pawn_white.svg"));
    horizontal2->addWidget(image2);
    horizontal2->addStretch();
    layout->addLayout(horizontal2);

    //Nazwa gracza 2
    QLabel *name2 = new QLabel(player2);
    name2->setAlignment(Qt::AlignCenter);
    name2->setFont(QFont("Times", 14, QFont::Bold));
    layout->addWidget(name2);

    layout->addStretch();


    this->setLayout(layout);
    qDebug() << "Tets";
}
