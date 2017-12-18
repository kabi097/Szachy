#ifndef CHESSPANEL_H
#define CHESSPANEL_H

#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include "chessboard.h"

class chessPanel : public QWidget
{
    Q_OBJECT
public:
    explicit chessPanel(chessBoard *board, QWidget *parent = nullptr);

public slots:
    void updateLost();
    void updateCurrentPlayer();

private:
    chessBoard *chessboard;
    QGridLayout *lostWhiteLayout;
    QGridLayout *lostBlackLayout;
    QLabel *arrowwhite;
    QLabel *arrowblack;
    QString player1;
    QString player2;

public slots:
};

#endif // CHESSPANEL_H
