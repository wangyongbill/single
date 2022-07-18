#ifndef DIALOG_FILTER_H
#define DIALOG_FILTER_H
#include "qcustomplot.h"
#ifndef USE_FLOAT
    typedef double float_type;
#else
    typedef float float_type;
#endif

#include <QDialog>
#include<QVector>
namespace Ui {
class Dialog_filter;
}

class Dialog_filter : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_filter(QWidget *parent = nullptr);
    ~Dialog_filter();

public:

    QCustomPlot* filter_plot = new QCustomPlot(this);

    double fs;
    double fedge1;
    double fedge2;
    double ripple_dB;
    double atten_dB;

    int coeff_Len;
    QVector<double> coeff;

public:
    double remez_estimate_weight(double, double);
    size_t remez_estimate_num_taps(double,double,double,double);
    QVector<double> design_fir(const std::string&,
                                   const std::string&,
                                   int,
                                   float_type,
                                   float_type,
                                   float_type,
                                   float_type);

    void set_filter_ui();
private slots:
    void on_design_filter_pushButton_clicked();

    void on_respone_Box_activated(const QString &arg1);



private:
    Ui::Dialog_filter *ui;
};

#endif // DIALOG_FILTER_H
