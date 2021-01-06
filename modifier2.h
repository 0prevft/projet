#ifndef MODIFIER2_H
#define MODIFIER2_H

#include <QDialog>

namespace Ui {
class modifier2;
}

class modifier2 : public QDialog
{
    Q_OBJECT

public:
    explicit modifier2(QWidget *parent = nullptr);
    ~modifier2();

private slots:
    void on_buttonBox_2_accepted();

private:
    Ui::modifier2 *ui;
};

#endif // MODIFIER2_H
