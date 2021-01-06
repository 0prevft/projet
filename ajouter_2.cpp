#include "ajouter_2.h"
#include "ui_ajouter_2.h"
#include "vehicule.h"

#include <QMessageBox>

ajouter_2::ajouter_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter_2)
{
    ui->setupUi(this);
}

ajouter_2::~ajouter_2()
{
    delete ui;
}

void ajouter_2::on_buttonBox_2_accepted()
{
    QString ID = ui->lineEdit_id->text();
    QString Marque = ui->lineEdit_marque->text();
    QString Numserie = ui->lineEdit_numserie->text();
    QString Livreur = ui->lineEdit_livreur->text();
    QDate Duree = ui->duree->date();

    Vehicule C(ID,Marque,Numserie,Livreur,Duree);
    bool test = C.ajouter_2();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Ajout non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    hide();
}
