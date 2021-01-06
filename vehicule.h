#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qdatetimeedit.h>
#include <qdatetime.h>
#include <QVariant>
#include <QComboBox>

class Vehicule
{
    QString ID,Marque,Numserie,Livreur, Duree;
    QDate Date_D;
public:
    Vehicule(){};
    Vehicule(QString,QString,QString,QString,QDate);

    QString getID(){return ID;}
    QString getMarque(){return Marque;};
    QString getNumserie(){return Numserie;}
    QString getLivreur(){return Livreur;}
    QString getDuree(){return Duree;}

    void setID(QString c ){ID=c;}
    void setMarque(QString n){Marque=n;}
    void setNumserie(QString p){Numserie=p;}
    void setLivreur(QString m){Livreur=m;}
    void setDuree(QString a){Duree=a;}

    bool ajouter_2();
    QSqlQueryModel * afficher();
    bool modifier_2(QString,QString,QString,QString); //added 1 here
    bool supprimer_2(QString);
};

#endif // VEHICULE_H
