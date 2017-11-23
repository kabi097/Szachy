#ifndef CHESSPANEL_H
#define CHESSPANEL_H

#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>

class chessPanel : public QWidget
{
    Q_OBJECT
public:
    explicit chessPanel(QWidget *parent = nullptr);

private:
    QString player1;
    QString player2;

public slots:
};

#endif // CHESSPANEL_H
