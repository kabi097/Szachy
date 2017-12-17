#ifndef CHESSSETTINGS_H
#define CHESSSETTINGS_H

#include <QDialog>
#include <QColorDialog>
#include "chessboard.h"

namespace Ui {
class chessSettings;
}

class chessSettings : public QDialog
{
    Q_OBJECT

public:
    explicit chessSettings(chessBoard *board, QWidget *parent = 0);
    QString tempWhite;
    QString tempBlack;
    QString tempSelect;
    QString tempAttack;
    ~chessSettings();

private slots:
    void on_pushButtonWhite_clicked();
    void on_pushButtonBlack_clicked();
    void on_pushButtonSelect_clicked();
    void on_pushButtonAttack_clicked();
    void on_radioButtonBlue_clicked();
    void on_radioButtonDefault_clicked();
    void on_radioButtonOrange_clicked();
    void on_radioButtonGreen_clicked();

private:
    Ui::chessSettings *ui;
    void uncheckColorLayouts();         //Odznacza wszystkie przyciski z zestawu kolorów
};

#endif // CHESSSETTINGS_H
