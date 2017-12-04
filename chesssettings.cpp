#include "chesssettings.h"
#include "ui_chesssettings.h"

chessSettings::chessSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chessSettings)
{
    ui->setupUi(this);
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + tempWhite + "; }");
    ui->pushButtonWhite->setAutoFillBackground(true);
    ui->pushButtonWhite->setFlat(true);

    ui->pushButtonBlack->setStyleSheet("QPushButton { background-color : " + tempBlack + "; }");
    ui->pushButtonBlack->setAutoFillBackground(true);
    ui->pushButtonBlack->setFlat(true);

    ui->pushButtonSelect->setStyleSheet("QPushButton { background-color : " + tempSelect + "; }");
    ui->pushButtonSelect->setAutoFillBackground(true);
    ui->pushButtonSelect->setFlat(true);

    ui->pushButtonAttack->setStyleSheet("QPushButton { background-color : " + tempAttack + "; }");
    ui->pushButtonAttack->setAutoFillBackground(true);
    ui->pushButtonAttack->setFlat(true);
}

chessSettings::~chessSettings()
{
    delete ui;
}

void chessSettings::on_pushButtonWhite_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempWhite));
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
    tempWhite = newColor.name();
}

void chessSettings::on_pushButtonBlack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempBlack));
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
    tempBlack = newColor.name();
}

void chessSettings::on_pushButtonSelect_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempSelect));
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
    tempSelect = newColor.name();
}

void chessSettings::on_pushButtonAttack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempAttack));
    ui->pushButtonWhite->setStyleSheet("QPushButton { background-color : " + newColor.name() + "; }");
    tempAttack = newColor.name();
}
