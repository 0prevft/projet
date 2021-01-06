#include "vehicule.h"

Vehicule::Vehicule(QString ID, QString Marque, QString Numserie,  QString Livreur, QDate Date_D)
{
    this->ID = ID;
    this->Marque = Marque;
    this->Numserie = Numserie;
    this->Livreur = Livreur;
    this->Date_D = Date_D;
}

bool Vehicule::ajouter_2()
{
    QSqlQuery query;

    query.prepare("insert into Vehicule (ID, Marque, Numserie, Livreur, Duree)" "values (:ID, :Marque, :Numserie, :Livreur, :Duree)");

    query.bindValue(":ID",ID);
    query.bindValue(":Marque",Marque);
    query.bindValue(":Numserie",Numserie);
    query.bindValue(":Livreur",Livreur);
    query.bindValue(":Duree",Duree);

    return query.exec();
}

QSqlQueryModel * Vehicule::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select * from Vehicule");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Marque"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Numserie"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Livreur"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Duree"));

    return model;
}

bool Vehicule::modifier_2(QString ID, QString Marque, QString Numserie, QString Livreur)
{
    QSqlQuery query;
    query.prepare("UPDATE Vehicule SET ID= :ID,Marque= :Marque,Numserie= :Numserie,Livreur= :Livreur Where ID= :ID");

    query.bindValue(":ID",ID);
    query.bindValue(":Marque",Marque);
    query.bindValue(":Numserie",Numserie);
    query.bindValue(":Livreur",Livreur);

    return query.exec();
}

bool Vehicule::supprimer_2(QString ID)
{
    QSqlQuery query;
    query.prepare("Delete from Vehicule where ID= :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}
