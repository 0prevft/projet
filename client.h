#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qdatetimeedit.h>
#include <qdatetime.h>
#include <QVariant>
#include <QComboBox>

class Client
{
    QString ID,Nom,Prenom,Adresse,Prix,Tel;
public:
    Client(){};
    Client(QString,QString,QString,QString,QString, QString);

    QString getID(){return ID;}
    QString getNom(){return Nom;};
    QString getPrenom(){return Prenom;}
    QString getPrix(){return Prix;}
    QString getAdresse(){return Adresse;}
    QString getTel(){return Tel;}

    void setID(QString c ){ID=c;}
    void setNom(QString n){Nom=n;}
    void setPrenom(QString p){Prenom=p;}
    void setPrix(QString m){Prix=m;}
    void setAdresse(QString a){Adresse=a;}
    void setTel(QString t){Tel=t;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(QString,QString,QString,QString,QString,QString);
    bool supprimer(QString);
};

#endif // CLIENT_H
