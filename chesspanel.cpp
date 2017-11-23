#include "chesspanel.h"

chessPanel::chessPanel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addStretch();

    player1 = "Gracz 1";
    player2 = "Gracz 2";

    QLabel *image1 = new QLabel;
    image1->setFixedSize(200,200);
    image1->setScaledContents(true);
    image1->setPixmap(QPixmap(":/pieces/Images/pawn_black.svg"));
    layout->addWidget(image1);

    QLabel *name1 = new QLabel(player1);
    name1->setFixedWidth(200);
    name1->setAlignment(Qt::AlignHCenter);
    name1->setFont(QFont("Times", 16, QFont::Bold));
    layout->addWidget(name1);

    layout->addStretch();

    QLabel *image2 = new QLabel;
    image2->setFixedSize(200,200);
    image2->setScaledContents(true);
    image2->setPixmap(QPixmap(":/pieces/Images/pawn_white.svg"));
    layout->addWidget(image2);

    QLabel *name2 = new QLabel(player2);
    name2->setFixedWidth(200);
    name2->setAlignment(Qt::AlignHCenter);
    name2->setFont(QFont("Times", 16, QFont::Bold));
    layout->addWidget(name2);

    layout->addStretch();

    this->setLayout(layout);
    qDebug() << "Tets";
}
