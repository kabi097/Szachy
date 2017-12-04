#include "chesssettings.h"
#include "ui_chesssettings.h"

chessSettings::chessSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chessSettings)
{
    ui->setupUi(this);
    ui->pushButtonWhite->setBackgroundRole(tempWhite);
    ui->pushButtonWhite->setAutoFillBackground(true);
    ui->pushButtonWhite->setFlat(true);

    ui->pushButtonBlack->setBackgroundRole(tempBlack);
    ui->pushButtonBlack->setAutoFillBackground(true);
    ui->pushButtonBlack->setFlat(true);

    ui->pushButtonSelect->setBackgroundRole(tempSelect);
    ui->pushButtonSelect->setAutoFillBackground(true);
    ui->pushButtonSelect->setFlat(true);

    ui->pushButtonAttack->setBackgroundRole(tempAttack);
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
    ui->pushButtonWhite->setBackgroundRole(newColor);
    tempWhite = newColor;
}

void chessSettings::on_pushButtonBlack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempBlack));
    ui->pushButtonWhite->setBackgroundRole(newColor);
    tempBlack = newColor;
}

void chessSettings::on_pushButtonSelect_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempSelect));
    ui->pushButtonWhite->setBackgroundRole(newColor);
    tempSelect = newColor;
}

void chessSettings::on_pushButtonAttack_clicked()
{
    QColor newColor = QColorDialog::getColor(QColor(tempAttack));
    ui->pushButtonWhite->setBackgroundRole(newColor);
    tempAttack = newColor;
}
