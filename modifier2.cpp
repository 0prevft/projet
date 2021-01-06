#include "modifier2.h"
#include "ui_modifier2.h"
#include "vehicule.h"

#include <QMessageBox>

modifier2::modifier2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier2)
{
    ui->setupUi(this);
}

modifier2::~modifier2()
{
    delete ui;
}

void modifier2::on_buttonBox_2_accepted()
{
    QString ID = ui->lineEdit_id->text();
    QString Marque = ui->lineEdit_marque->text();
    QString Numserie = ui->lineEdit_numserie->text();
    QString Livreur = ui->lineEdit_livreur->text();
    QDate Duree = ui->duree->date();

    Vehicule C(ID,Marque,Numserie,Livreur,Duree);
    bool test = C.modifier_2(ID,Marque,Numserie,Livreur);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Modification non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    hide();
}
