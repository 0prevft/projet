#include "ajouter.h"
#include "ui_ajouter.h"
#include "client.h"
#include <QMessageBox>

ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_buttonBox_accepted()
{
    QString ID = ui->lineEdit_cin->text();
    QString Nom = ui->lineEdit_nom->text();
    QString Prenom = ui->lineEdit_prenom->text();
    QString Adresse = ui->lineEdit_adresse->text();
    QString Prix = ui->lineEdit_prix->text();
    QString Tel = ui->lineEdit_tel->text();

    Client C(ID,Nom,Prenom,Prix,Adresse,Tel);
    bool test = C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                 QObject::tr("Ajout non effectuer\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void ajouter::on_buttonBox_rejected()
{
    this->hide();
}
