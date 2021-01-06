#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtWidgets/QMessageBox>
#include <QFileDialog>

class Connection
{
public:
    QSqlDatabase mydb;
public:
    Connection();
    bool createconnection();
    void closeconnection();
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_livraison_clicked();

    void on_pushButton_ajout_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_supp_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_printCl_clicked();

    void on_pushButton_vehicule_clicked();

    void on_pushButton_ajout_4_clicked();

    void on_pushButton_modif_4_clicked();

    void on_pushButton_supp_4_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

    void on_pushButton_printC_2_clicked();

private:
    Ui::MainWindow *ui;
    Client tmp;
    QStringList files;
};

#endif // MAINWINDOW_H
