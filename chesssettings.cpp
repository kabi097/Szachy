#include "chesssettings.h"
#include "ui_chesssettings.h"

chessSettings::chessSettings(chessBoard *board, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chessSettings)
{
    setWindowTitle("Ustawienia gry");
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
    QColor newColor = QColorDialog::getColor(QColor(tempWhite));
    if (newColor.isValid()==true) {
        ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempWhite = newColor.name();
    }
}

void chessSettings::on_pushButtonBlack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempBlack));
    if (newColor.isValid()==true) {
        ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempBlack = newColor.name();
    }
}

void chessSettings::on_pushButtonSelect_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempSelect));
    if (newColor.isValid()==true) {
        ui->pushButtonSelect->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempSelect = newColor.name();
    }
}

void chessSettings::on_pushButtonAttack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempAttack));
    if (newColor.isValid()==true) {
        ui->pushButtonAttack->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
        tempAttack = newColor.name();
    }
}

void chessSettings::on_radioButtonBlue_clicked()
{
    tempWhite =
}
