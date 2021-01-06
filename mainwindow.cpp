#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "ajouter.h"
#include "ajouter_2.h"
#include "modifier.h"
#include "modifier2.h"
#include "supprimer.h"
#include "supprimer_2.h"

#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>

Connection::Connection(){}

bool Connection::createconnection()
{
    mydb = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    mydb.setDatabaseName("Projet_CPP_G5");
    mydb.setUserName("system");
    mydb.setPassword("p8yn1x9292");
if (mydb.open()) test=true;

return test;
}

void Connection::closeconnection(){mydb.close();}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajout_clicked()
{
    ajouter ajouter;
    ajouter.setModal(true);
    ajouter.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_pushButton_livraison_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_pushButton_modif_clicked()
{
    modifier modi;
    modi.setModal(true);
    modi.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_pushButton_supp_clicked()
{
    supprimer supp;
    supp.setModal(true);
    supp.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_radioButton_4_clicked()
{
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison ORDER BY ID");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_radioButton_5_clicked()
{
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison ORDER BY Nom ASC");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_radioButton_6_clicked()
{
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Livraison ORDER BY Prenom");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void MainWindow::on_pushButton_printCl_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}

void MainWindow::on_pushButton_vehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_pushButton_ajout_4_clicked()
{
    ajouter_2 ajouter;
    ajouter.setModal(true);
    ajouter.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_pushButton_modif_4_clicked()
{
    modifier2 modi;
    modi.setModal(true);
    modi.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_pushButton_supp_4_clicked()
{
    supprimer_2 supp;
    supp.setModal(true);
    supp.exec();

    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_radioButton_10_clicked()
{
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule ORDER BY ID");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_radioButton_11_clicked()
{
    Connection conn;
    QSqlQueryModel * modal = new QSqlQueryModel;

    QSqlQuery * qry=new QSqlQuery(conn.mydb);
    qry->prepare("select * from Vehicule ORDER BY Marque ASC");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_pushButton_printC_2_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}
