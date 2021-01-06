#ifndef SUPPRIMER_2_H
#define SUPPRIMER_2_H

#include "vehicule.h"

#include <QDialog>

namespace Ui {
class supprimer_2;
}

class supprimer_2 : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_2(QWidget *parent = nullptr);
    ~supprimer_2();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::supprimer_2 *ui;
    Vehicule temp;
};

#endif // SUPPRIMER_2_H
