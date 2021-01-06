#include "modifier.h"
#include "ui_modifier.h"
#include "client.h"
#include <QMessageBox>

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_buttonBox_accepted()
{
    QString ID = ui->lineEdit_ID->text();
    QString Nom = ui->lineEdit_nom->text();
    QString Prenom = ui->lineEdit_prenom->text();
    QString Adresse = ui->lineEdit_adresse->text();
    QString Tel = ui->lineEdit_tel->text();
    QString Prix = ui->lineEdit_prix->text();


    Client C(ID,Nom,Prenom,Adresse,Tel,Prix);
    bool test=C.modifier(ID,Nom,Prenom,Adresse,Tel,Prix);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un evenement !"),
                                 QObject::tr(" evenement modifiée ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier un evenement"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
