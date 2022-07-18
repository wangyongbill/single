#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AutoResize.h"
#include "qcustomplot.h"
#include "utils.h"
#include "dialog_measure_set.h"
#include "dialog_dianji.h"
#include "ui_dialog_dianji.h"
#include "ui_dialog_caijika.h"
#include "dialog_caijika.h"
#include "myplot.h"
#include "get_measure_thread.h"
#include "processthread.h"
#include "mathprocess.h"
#include "ele_machinery.h"
#include "dialog_filter.h"

#include <glut.h>
#include <QTimer>
#include <QMainWindow>
#include <QtCharts>
using namespace QtCharts;
QT_BEGIN_NAMESPACE
enum ResizeRegion
{
    Default,
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest,
    Arrow
};
enum EdgeStatus{
    Eg_normal,
    Eg_top,
    Eg_left,
    Eg_right,
    Eg_bottom


};

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();


public:
    void updateTopLevelWidget();
    QStandardItemModel* model;
    ResizeRegion resizeregion;
    QPoint p;
    QPoint dragPos;
    QRect r;
    int d;
    Qt::Corner m_corner;
    Qt::Edge m_edge;
    int resizeBorderWidth=10;
    Qt::Corner corner(QWidget*q,QMouseEvent*qe) const;
    Qt::Edge edge()const;
    void hideWidget(QWidget*q,EdgeStatus es);//窗口隐藏
    void showWidget(QWidget*q,EdgeStatus es);//窗口显示
    EdgeStatus isDirection(QWidget *q);//判断窗口位置状态



    void adaptiveConfiguration();
    void cOneStyle();
    void initUi();
    void initProperty();
    void cTwoStyle();

    void ReloadTable();

    QString replaceStyle(QString str1 ,QString str2,QString str3);

    QChartView *creatLineChart(QList<double> doublelist, QString titleName, QString titleText_x, QString titleText_y);
protected:
    bool winEvent(MSG *message, long *result);

private slots:
    void on_home_close_clicked();

    //    void on_home_maximize_clicked();

    void on_home_minimize_clicked();

    void on_equipment_btn_clicked();

    void on_config_btn_clicked();

    void on_focus_btn_clicked();


    void on_measure_btn_clicked();

    void on_file_btn_clicked();

    void on_analyse_btn_clicked();

    void on_motor_tool_clicked();

    void on_capture_card_tool_clicked();

    void on_config_tool_clicked();

    void on_auto_focus_tool_clicked();

    void on_focus_distance_tool_clicked();

    void on_close_focus_tool_clicked();

    void on_stop_focusing_tool_clicked();

    void on_single_measurement_tool_clicked();

    void on_continuous_measurement_tool_clicked();

    void on_stop_focusing_tool_2_clicked();

    void on_mouse_arrow_tool_clicked();

    void on_zoom_tool_clicked();

    void on_recovery_tool_clicked();

    void on_box_select_extrema_tool_clicked();

    void on_open_file_tool_clicked();

    void on_export_table_tool_clicked();

    void on_save_data_tool_clicked();

    void on_print_tool_clicked();

    void on_home_maximize_clicked(bool checked);
    //初始化功能部分
    void Initialize_function();
    void on_connection();

    void timeToRePlot();//定时重绘曲线
    void stop_timer();


    void receive_setting(bool if_set);//接收用户的设置

    void if_clear_data(bool if_clear);
    void show_Time(double * time_date, int len, int measure_num); //画时域数据
    void show_FFT(double  * FFT_date,  int fft_len);//画频域数据
    void show_save_Time(double  * showdate, int len, int fs);
    void show_save_FFT(double  * FFT_date,int fft_len, int fs,int measure_num );//第二个数据是显示点数，最后一个是总点数

    void Get_fftPoint(QPoint,QPoint);
    void Get_timePoint(QPoint,QPoint);

    void keyPressEvent(QKeyEvent * e);//软件使用中的快捷键

    void on_time_wait(int wait_time);



    void save_data_over(bool);//保存原始数据
    void receive_neicun(int);
    void show_RMS_value( double);
    //电机的相关操作
    void serialPortRead_Slot();
    void sent_instruction();
    void stop_return_best();
    void Delay_MSec(unsigned int msec);
    void on_far_one();
    void on_near_one();









    void on_rad_spectrum_toggled(bool checked);

    void on_rad_power_toggled(bool checked);

    void on_filter_toolButton_clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent*e);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private:
    Ui::MainWindow *ui;
    AutoResize *m_autoResizeHandler;
    void resizeEvent(QResizeEvent * event);


    Utils utils;
    QString Qstyle="";
    QString one_menu_btn_style="";
    QString two_menu_btn_style="";

    bool m_bMousePressed;

    //窗口大小是否变化
    bool m_windowMax; //最大化时为真
    QPoint m_startPoint;

    //与缩放相关的变量
    bool mZoom;
    QRect mZoomLocation;
    QRect mZoomChanged;
    QPoint mZoomPos;


public:
    Dialog_filter *filter;
    Dialog_measure_set  *measure_set;
    Dialog_dianji  *dianji_set;
    Dialog_caijika *caijika_set;

    get_measure_thread *getdata;
    processthread *processdata;
    mathprocess* math_process;
    QTimer rePlotTimer;//控制时域显示的timer
    bool if_danci_measure;
    bool if_Kuangxuan;
    bool if_pinlvxianshi;
    int celiang_int;
    double *save_date;
    double *save_fft_date;
    int default_measure_num;//默认和设置的测量次数
    int default_measure_line;//默认和设置的测量谱线数
    int type;//测量的是速度、位移还是加速度

    //对焦的相关操作
    ele_machinery*machinery;//电机
    QTimer *timSend;//控制点击对焦的timer
    QString panduan;
    int step;
    int step_best;
    double last_energy;
    QString dianji_name;

    QString caijika_name;





private:

    //曲线的起始点坐标
    double timex_max;
    double timex_min;
    double timey_max;
    double timey_min;
    double ffty_max ;
    double ffty_min;
    double fftx_max ;
    double fftx_min;
    int cala_num;
    double xianshi_gain;
    bool if_in_measure;
    QStringList read_list;
    QMutex m_Mutex;
    QChartView *localCreatLineChart;
    QChartView *localCreatLineChart2;
    QList<double> doublelist;

};
#endif // MAINWINDOW_H
