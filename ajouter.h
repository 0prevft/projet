#ifndef AJOUTER_H
#define AJOUTER_H

#include <QDialog>

namespace Ui {
class ajouter;
}

class ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter(QWidget *parent = nullptr);
    ~ajouter();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ajouter *ui;
};

#endif // AJOUTER_H
