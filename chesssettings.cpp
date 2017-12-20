#include "chesssettings.h"
#include "ui_chesssettings.h"

/*!
    \class chessSettings
    \brief Odpowiada za prawidłowe wyświetlanie i działanie okna ustawień.

    Tworzy nowe okno ustawień korzystając z klasy bazowej QDialog. Oferuje zmianę kolorów szachownicy.
*/

chessSettings::chessSettings(chessBoard *board, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chessSettings)
{
    tempSelect = board->selectColor;
    tempAttack= board->attackColor;
    tempBlack = board->blackColor;
    tempWhite = board->whiteColor;

    ui->setupUi(this);
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
    ui->pushButtonSelect->setStyleSheet("QPushButton { background-color : " + tempSelect + "; }");
    ui->pushButtonAttack->setStyleSheet("QPushButton { background-color : " + tempAttack + "; }");
}

chessSettings::~chessSettings()
{
    delete ui;
}

void chessSettings::on_pushButtonWhite_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempWhite), this, "Wybierz kolor", QColorDialog::DontUseNativeDialog);
    if (newColor.isValid()==true) {
        ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempWhite = newColor.name();
        uncheckColorLayouts();
    }
}

void chessSettings::on_pushButtonBlack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempBlack), this, "Wybierz kolor", QColorDialog::DontUseNativeDialog);
    if (newColor.isValid()==true) {
        ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempBlack = newColor.name();
        uncheckColorLayouts();
    }
}

void chessSettings::on_pushButtonSelect_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempSelect), this, "Wybierz kolor", QColorDialog::DontUseNativeDialog);
    if (newColor.isValid()==true) {
        ui->pushButtonSelect->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempSelect = newColor.name();
    }
}

void chessSettings::on_pushButtonAttack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempAttack), this, "Wybierz kolor", QColorDialog::DontUseNativeDialog);
    if (newColor.isValid()==true) {
        ui->pushButtonAttack->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempAttack = newColor.name();
    }
}

void chessSettings::on_radioButtonBlue_clicked()
{
    tempWhite = "#a7b9e7";
    tempBlack = "#5a69aa";
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
}

void chessSettings::on_radioButtonDefault_clicked()
{
    tempWhite = "white";
    tempBlack = "grey";
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
}

void chessSettings::on_radioButtonOrange_clicked()
{
    tempWhite = "#ffce9e";
    tempBlack = "#d18b47";
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
}

void chessSettings::on_radioButtonGreen_clicked()
{
    tempWhite = "#e7e7c6";
    tempBlack = "#4aa54a";
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
}

void chessSettings::uncheckColorLayouts()
{
    ui->radioButtonDefault->setAutoExclusive(false);
    ui->radioButtonBlue->setAutoExclusive(false);
    ui->radioButtonOrange->setAutoExclusive(false);
    ui->radioButtonGreen->setAutoExclusive(false);

    ui->radioButtonDefault->setChecked(false);
    ui->radioButtonBlue->setChecked(false);
    ui->radioButtonOrange->setChecked(false);
    ui->radioButtonGreen->setChecked(false);

    ui->radioButtonDefault->setAutoExclusive(true);
    ui->radioButtonBlue->setAutoExclusive(true);
    ui->radioButtonOrange->setAutoExclusive(true);
    ui->radioButtonGreen->setAutoExclusive(true);
}
