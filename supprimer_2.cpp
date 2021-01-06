#include "supprimer_2.h"
#include "ui_supprimer_2.h"
#include "vehicule.h"

#include <QMessageBox>

supprimer_2::supprimer_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimer_2)
{
    ui->setupUi(this);
}

supprimer_2::~supprimer_2()
{
    delete ui;
}

void supprimer_2::on_buttonBox_accepted()
{
    QString ID = ui->lineEdit_idsup->text();
    bool test=temp.supprimer_2(ID);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Suppresion non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void supprimer_2::on_buttonBox_rejected()
{
    this->hide();
}
