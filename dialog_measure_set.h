#ifndef DIALOG_MEASURE_SET_H
#define DIALOG_MEASURE_SET_H

#include <QDialog>

namespace Ui {
class Dialog_measure_set;
}

class Dialog_measure_set : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_measure_set(QWidget *parent = nullptr);
    ~Dialog_measure_set();

    bool if_lvbo;

    bool if_USB;
    bool if_NET;
    bool if_A;
    bool if_D;
    bool if_S;
    bool if_O;
    int measure_num;
    double capture_time;
    int daikuan;
    int puxianshu;
    int caiyanglv;
    int lvbo_type;
    int DA_type;
    int FFT_line;
    int default_measure_num;
    int lowflg;   // 0,1,2,3分别表示不滤波，2k(200k、1.6M)，10k(1M、1.5M),15k(8M、12M)的低通
    int highflg; // 0,1,2,3分别表示不滤波，5、10(160M的采样时)，20,80的高通
    int trackflg; // 0,1分别表示不追踪，追踪滤波
private slots:

    void on_checkBox_15_clicked();

    void on_checkBox_16_clicked();

    void on_checkBox_17_clicked();

    void on_fft_1_clicked();
    void on_fft_2_clicked();
    void on_fft_3_clicked();
    void on_fft_4_clicked();

    void on_hf_1_clicked();
    void on_hf_2_clicked();
    void on_hf_3_clicked();
    void on_hf_4_clicked();
    void on_hf_5_clicked();

    void on_lf_1_clicked();
    void on_lf_2_clicked();
    void on_lf_3_clicked();
    void on_lf_4_clicked();
    void on_lf_5_clicked();
    void on_lf_6_clicked();
    void on_lf_7_clicked();
    void on_lf_8_clicked();
    void on_lf_9_clicked();
    void on_lf_10_clicked();



    void on_tf_1_clicked();
    void on_tf_2_clicked();

    void on_set_ok_clicked();


    void on_NET_clicked();

    void on_USB_clicked();

    void on_if_A_clicked();

    void on_if_D_clicked();

    void on_if_S_clicked();

    void on_fft_5_clicked();


    void on_fft_7_clicked();

    void on_fft_6_clicked();

    void on_if_O_clicked();

    void on_horizontalSlider_valueChanged(int value);

signals:
    void Setting_changed(bool);//type


private:

    Ui::Dialog_measure_set *ui;
};

#endif // DIALOG_MEASURE_SET_H
