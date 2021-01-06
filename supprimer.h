#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include "client.h"

#include <QDialog>

namespace Ui {
class supprimer;
}

class supprimer : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer(QWidget *parent = nullptr);
    ~supprimer();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::supprimer *ui;
    Client temp;
};

#endif // SUPPRIMER_H
