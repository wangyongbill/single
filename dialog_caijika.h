#ifndef DIALOG_CAIJIKA_H
#define DIALOG_CAIJIKA_H

#include <QDialog>
#include "get_measure_thread.h"
namespace Ui {
class Dialog_caijika;
}

class Dialog_caijika : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_caijika(QWidget *parent = nullptr);
    ~Dialog_caijika();
 get_measure_thread *caijika_1;
private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

public:
    Ui::Dialog_caijika *ui;
};

#endif // DIALOG_CAIJIKA_H
