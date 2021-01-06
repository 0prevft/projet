#include "client.h"

Client::Client(QString ID, QString Nom, QString Prenom, QString Prix, QString Adresse, QString Tel)
{
    this->ID = ID;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Prix = Prix;
    this->Adresse = Adresse;
    this->Tel = Tel;
}

bool Client::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into Livraison (ID, Nom, Prenom, Adresse, Tel, Prix)" "values (:ID, :Nom, :Prenom, :Adresse, :Tel, :Prix)");

    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Tel",Tel);
    query.bindValue(":Prix",Prix);
    query.bindValue(":Adresse",Adresse);

    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from Livraison");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Prix"));

    return model;
}

bool Client::modifier(QString ID, QString Nom, QString Prenom, QString Adresse, QString Tel, QString Prix)
{
    QSqlQuery query;
    query.prepare("UPDATE Livraison SET ID= :ID,Nom= :Nom,Prenom= :Prenom,Prix= :Prix,Adresse= :Adresse,Tel= :Tel Where ID= :ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Prix",Prix);
    query.bindValue(":Adresse",Adresse);
    query.bindValue(":Tel",Tel);
    return query.exec();
}

bool Client::supprimer(QString ID)
{
    QSqlQuery query;
    query.prepare("Delete from Livraison where ID= :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}
