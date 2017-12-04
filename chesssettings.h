#ifndef CHESSSETTINGS_H
#define CHESSSETTINGS_H

#include <QDialog>
#include <QColorDialog>

namespace Ui {
class chessSettings;
}

class chessSettings : public QDialog
{
    Q_OBJECT

public:
    explicit chessSettings(QWidget *parent = 0);
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

private:
    Ui::chessSettings *ui;
};

#endif // CHESSSETTINGS_H
