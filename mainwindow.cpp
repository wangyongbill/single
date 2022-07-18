#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include <QAxObject>
#include <QProgressBar>
#include "QStackedWidget"
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QtCharts>
#include <QStringLiteral>
using namespace QtCharts;

// 防止字体乱码
#if _MSC_VER >= 1600 // MSVC2015 > 1899, MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

///mingw使用QStringLiteral 会有问题
/// 没有_MSC_VER这个宏 我们就认为他用的是mingw编译器

#ifndef _MSC_VER
#define MINGW
#endif

#if defined(WIN32) && !defined(MINGW)

#else
#define QStringLiteral QString
#endif
MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //构造函数中添加以下代码，实现在不同分辨率大小下等比缩放
    //自缩放基于AutoResize，你只需要将AutoResize实例出来
    Qstyle= ui->widget_5->styleSheet();

    initUi();

    //    for (int i=0;i< 30;i++) {
    //        doublelist.append(i);


    //    }

    //    localCreatLineChart = creatLineChart(doublelist,"","米/秒","时间/秒");
    //    localCreatLineChart2 = creatLineChart(doublelist,"","米/秒","时间/秒");
    //    localCreatLineChart->setParent(ui->widget_time);

    //    localCreatLineChart2->setParent(ui->widget_frquency);
    //    localCreatLineChart->resize(910,320);
    //    localCreatLineChart2->resize(910,320);

    m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
    m_autoResizeHandler->setAutoResizeFlag(
                AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
                AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL
                );


    //如果有放在widget、stack、tab、frame等容器下面的控件，那么这个容器也要通过addOtherItem添加到缩放对象中
    //m_autoResizeHandler->addOtherItem(ui->frame);


    adaptiveConfiguration();

    m_autoResizeHandler->pushAllResizeItem();
    this->setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏,去掉任务栏显示，窗口置顶


    //曲线显示
    ui->widget_time->addGraph();
    ui->widget_time->graph()->setPen(QPen(Qt::blue));

    ui->widget_time->xAxis2->setVisible(true);
    ui->widget_time->xAxis2->setTickLabels(false);
    ui->widget_time->yAxis2->setVisible(true);
    ui->widget_time->yAxis2->setTickLabels(false);
    //ui->widget_time->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    //ui->widget_time->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    ui->widget_time->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);

    ui->widget_time->xAxis->setRange(0, 0.002);//设置x轴的范围


    ui->widget_time->graph(0)->rescaleAxes();
    ui->widget_time->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                     QCP::iSelectLegend | QCP::iSelectPlottables);

    //设置背景颜色
    QBrush backRole;
    backRole.setColor("white");
    backRole.setStyle(Qt::SolidPattern);
    ui->widget_time->setBackground(backRole);
    //ui->widget_time->setOpenGl(true);
    qDebug()<<"opengl:"<<ui->widget_time->openGl();
    ui->widget_time->replot();
    //*******************

    ui->widget_frquency->addGraph();
    ui->widget_frquency->graph()->setPen(QPen(Qt::green));

    ui->widget_frquency->xAxis2->setVisible(true);
    ui->widget_frquency->xAxis2->setTickLabels(false);
    ui->widget_frquency->yAxis2->setVisible(true);
    ui->widget_frquency->yAxis2->setTickLabels(false);

    //ui->widget_frquency->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    //ui->widget_frquency->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    ui->widget_frquency->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);

    ui->widget_frquency->xAxis->setRange(0, 25000000);//设置x轴的范围

    ui->widget_frquency->graph(0)->rescaleAxes();
    ui->widget_frquency->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);

    QBrush backRole2;
    backRole2.setColor("white");
    backRole2.setStyle(Qt::SolidPattern);
    ui->widget_frquency->setBackground(backRole2);
    //ui->widget_frquency->setOpenGl(true);
    qDebug()<<"opengl:"<<ui->widget_frquency->openGl();
    ui->widget_frquency->replot();

    //time单位
    ui->lab_time_x->setText("时间/秒");
    ui->lab_time_y->setText("米/秒");

    //frquecy单位
    ui->lab_fr_x->setText("时间/秒");
    ui->lab_fr_y->setText("米/秒");


    //功能部分
    Initialize_function();
}




void MainWindow::Initialize_function()
{
    filter = new Dialog_filter();   // 初始化滤波器类

    caijika_set=new Dialog_caijika();//先设置软件参数
    dianji_set=new Dialog_dianji();//先设置软件参数
    measure_set=new Dialog_measure_set();//先设置软件参数
    getdata=new get_measure_thread();
    processdata=new processthread();
    //电机相关操作
    machinery=new ele_machinery();
    math_process=new mathprocess();//数学的计算

    if_danci_measure=false;
    if_Kuangxuan=false;
    if_in_measure=false;
    if_pinlvxianshi=true;//默认频率显示
    //ui->radioButton->clicked(true);
    xianshi_gain=1;//默认米每秒，不增益
    cala_num=0;

    connect(&rePlotTimer, SIGNAL(timeout()), this, SLOT(timeToRePlot()));
    //控制默认不可放大缩小操作
    ui->widget_frquency->if_able=false;
    ui->widget_time->if_able=false;
    connect(ui->widget_frquency, SIGNAL(zuobiao_over(QPoint,QPoint)), this, SLOT(Get_fftPoint(QPoint,QPoint)));
    connect(ui->widget_time, SIGNAL(zuobiao_over(QPoint,QPoint)), this, SLOT(Get_timePoint(QPoint,QPoint)));



    QObject::connect(measure_set, SIGNAL(Setting_changed(bool)), this, SLOT(receive_setting(bool)));//两个线程之间数据交互
    QObject::connect(getdata, SIGNAL(sent_capture_data(double*,int,int)), processdata, SLOT(receive_data(double*,int,int)),Qt::DirectConnection);//两个线程之间数据交互
    QObject::connect(processdata, SIGNAL(save_data_over(bool )), this, SLOT(save_wav_over(bool)));//是否已经存完数据了
    QObject::connect(processdata, SIGNAL(sent_RMS_value(double )), this, SLOT(show_RMS_value(double)));

    //测量结果数据传递
    QObject::connect(getdata, SIGNAL(clear_data(bool)), this, SLOT(if_clear_data(bool)));//两个线程之间数据交互
    //QObject::connect(getdata, SIGNAL(sent_neicun(int)), this, SLOT(receive_neicun(int)));//两个线程之间数据交互
    QObject::connect(getdata, SIGNAL(danci_over()), this, SLOT(stop_timer()));//两个线程之间数据交互

    QObject::connect(processdata, SIGNAL(sent_time_data(double  *,int ,int)), this, SLOT(show_Time(double  *,int ,int)));//两个线程之间数据交互
    QObject::connect(processdata, SIGNAL(sent_fft_data(double  *,int )), this, SLOT(show_FFT(double  *,int )));


    //判断是否成功的变量

    save_date=new double[measure_set->default_measure_num+2*getdata->sent_capture_num];
    save_fft_date=new double[measure_set->default_measure_num+2*getdata->sent_capture_num];


    connect(machinery->m_serialPort, SIGNAL(readyRead()), this, SLOT(serialPortRead_Slot()));
    step=0;
    step_best=0;
    last_energy=-100;
    panduan="";
    timSend = new QTimer(this);
    //设置为单次触发
    connect(timSend,SIGNAL(timeout()),this,SLOT(sent_instruction()));     //设置槽
    //自动连接设备
    on_connection();


}
void MainWindow:: on_connection()
{
    bool if_usb_capture=measure_set->if_USB;//从设置中查看是否连接USB
    getdata->if_connect= getdata->on_connection(if_usb_capture);

    dianji_name=machinery->on_open();//打开电机

}
void MainWindow::paintEvent(QPaintEvent*e)
{

    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
//下列主要是对窗体的移动, 其实可以移动到标题栏中
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        m_bMousePressed = true;
        m_startPoint = event->globalPos();
    }

    return QWidget::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMousePressed = false;
    return QWidget::mouseReleaseEvent(event);
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMousePressed) {
        QPoint point = event->globalPos()  - m_startPoint;
        m_startPoint = event->globalPos();
        move(x() + point.x(), y() + point.y());
    }

    return QWidget::mouseMoveEvent(event);
}
void MainWindow::ReloadTable(){



    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setVisible(false);//隐藏列表头
    //QStandardItemModel*
    model = new QStandardItemModel(this);



    /*设置列字段名*/
    model->setColumnCount(5);

    model->setHeaderData(0,Qt::Horizontal, "次数");
    model->setHeaderData(1,Qt::Horizontal, "（起始坐标，幅值）");
    model->setHeaderData(2,Qt::Horizontal, "（终止坐标，福值）");
    model->setHeaderData(3,Qt::Horizontal, "（最大值坐标，福值）");
    model->setHeaderData(4,Qt::Horizontal, "（框数数值）");

    model->setRowCount(0);

    /*设置一条数据*/
    for(int i=0;i<20;i++){

        for(int j=0;j<4;j++){
            model->setItem(i, j, new QStandardItem(""));


        }


    }

    for(int i=0;i<20;i++){
        model->setItem(i, 1, new QStandardItem(i+1));


    }

    ui->tableView->setModel(model);


    //    double localHeight = ui->tableView->height();
    double localWidth = ui->tableView->width();

    localWidth= localWidth-30;

    double wid=localWidth/4;
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //列宽
    ui->tableView->setColumnWidth(0,30);
    for(int i=1;i<5;i++){

        ui->tableView->setColumnWidth(i,wid);
    }

    for(int i=0;i<20;i++){
        ui->tableView->setRowHeight(i,29);//设置5行高度为20
    }


}



void MainWindow::initUi()
{
    initProperty();
    cOneStyle();
    cTwoStyle();

    ReloadTable();
}
QChartView *MainWindow::creatLineChart(QList<double> doublelist,QString titleName,QString titleText_x,QString titleText_y)
{
    QChartView * chartView=new QChartView ();
    chartView->setParent(ui->widget_time);
    doublelist= utils.sortDouble(doublelist);

    QChart *chart=new QChart();


    QLineSeries *series=new QLineSeries();
    //    series->setName(titleName);
    for (int i=0; i<doublelist.size(); i++)
    {
        double localAt = doublelist.at(i);

        double mun1=(double)i+(double)1;
        double mun2=(double)doublelist.size();

        double dbe=mun1/mun2;
        dbe = utils.getDecimalPlaces(dbe,3);

        series->append(localAt,dbe);
    }


    /**
     * @brief localLegend
     * 图例
     */
    chart->legend()->hide();


    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(titleName);
    //    chart->setTheme(QChart::ChartThemeBlueCerulean);//主题颜色设置为天然色
    QAbstractAxis *localAxisX = chart->axisX();
    QAbstractAxis *localAxisY = chart->axisY();
    localAxisY->setRange(0,1);

    if(!utils.equals("",titleText_x)){

        localAxisX->setTitleText("("+titleText_x+")");
        //        localAxisX->titleText();
        //        localAxisX->labelsVisible();
        //        localAxisX->setTitleBrush()
    }
    if(!utils.equals("",titleText_y)){

        localAxisY->setTitleText("("+titleText_y+")");
    }

    chartView->setChart(chart);

    chartView->move(0,0);

    return chartView;

}



/**
 * @brief MainWindow::initProperty
 * 初始化属性
 */
void MainWindow::initProperty()
{
    one_menu_btn_style=ui->equipment_btn_widget->styleSheet();
    two_menu_btn_style=ui->motor_tool_widget->styleSheet();


}
/**
 * @brief MainWindow::adaptiveConfiguration
 * 自适应配置
 */
void MainWindow::adaptiveConfiguration()
{
    //参数里所有的widgets框
    QList<QWidget *> widgets = ui->centralwidget->findChildren<QWidget *>();
    QList<QStackedWidget *> qws =  ui->centralwidget->findChildren<QStackedWidget *>();

    for (int i=0;i< widgets.size();i++) {
        QWidget *  localAt = widgets.at(i);
        m_autoResizeHandler->addOtherItem(localAt);

    }
    for (int i=0;i< qws.size();i++) {
        QStackedWidget * const localAt = qws.at(i);
        m_autoResizeHandler->addOtherItem(localAt);


    }
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "event:"<<event;

    //这一段不可省去，当界面size发生改变时，就会调用此函数重新计算各控件大小
    m_autoResizeHandler->doAutoResize();
    ReloadTable();


    m_autoResizeHandler->addOtherItem(ui->rad_power);
    m_autoResizeHandler->addOtherItem(ui->rad_spectrum);
}
MainWindow::~MainWindow()
{
    delete ui;
}






/**
 * @brief MainWindow::on_home_close_clicked
 * 关闭软件
 */
void MainWindow::on_home_close_clicked()
{
    this->close();
}

/**
 * @brief MainWindow::on_home_minimize_clicked
 * 最小化
 */
void MainWindow::on_home_minimize_clicked()
{
    this->showMinimized();
}
/**
 * @brief MainWindow::on_equipment_btn_clicked
 * 点击设备
 */
void MainWindow::on_equipment_btn_clicked()
{
    cOneStyle();
    ui->equipment_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(0);

}
/**
 * @brief MainWindow::dtyle
 * 一级菜单默认样式
 */
void MainWindow::cOneStyle()
{
    ui->equipment_btn_widget->setStyleSheet("");
    ui->config_btn_widget->setStyleSheet("");
    ui->focus_btn_widget->setStyleSheet("");

    ui->measure_btn_widget->setStyleSheet("");
    ui->analyse_btn_widget->setStyleSheet("");
    ui->file_btn_widget->setStyleSheet("");

}
/**
 * @brief MainWindow::dtyle
 * 二级菜单默认样式
 */
void MainWindow::cTwoStyle()
{
    ui->motor_tool_widget->setStyleSheet("");
    ui->capture_card_tool_widget->setStyleSheet("");
    ui->config_tool_widget->setStyleSheet("");
    ui->auto_focus_tool_widget->setStyleSheet("");
    ui->focus_distance_tool_widget->setStyleSheet("");

    ui->close_focus_tool_widget->setStyleSheet("");
    ui->stop_focusing_tool_widget->setStyleSheet("");
    ui->single_measurement_tool_widget->setStyleSheet("");
    ui->continuous_measurement_tool_widget->setStyleSheet("");
    ui->stop_focusing_tool_widget_2->setStyleSheet("");
    ui->mouse_arrow_tool_widget->setStyleSheet("");
    ui->zoom_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet("");
    ui->open_file_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet("");

}
/**
 * @brief MainWindow::on_config_btn_clicked
 * 点击设置
 */
void MainWindow::on_config_btn_clicked()
{
    cOneStyle();
    qDebug() << "one_menu_btn_style："; qDebug() << one_menu_btn_style;
    ui->config_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(1);

}
/**
 * @brief MainWindow::on_focus_btn_clicked
 * 点击对焦
 */
void MainWindow::on_focus_btn_clicked()
{
    cOneStyle();
    ui->focus_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(2);
}
/**
 * @brief MainWindow::on_measure_btn_clicked
 * 测量
 */
void MainWindow::on_measure_btn_clicked()
{
    cOneStyle();
    ui->measure_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(3);
}
/**
 * @brief MainWindow::on_file_btn_clicked
 *     文件
 */
void MainWindow::on_file_btn_clicked()
{
    cOneStyle();
    ui->file_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(5);
}
/**
 * @brief MainWindow::on_analyse_btn_clicked
 * 分析
 */
void MainWindow::on_analyse_btn_clicked()
{
    cOneStyle();
    ui->analyse_btn_widget->setStyleSheet(one_menu_btn_style);
    ui->submenu->setCurrentIndex(4);
}

/**
 * @brief MainWindow::on_motor_tool_clicked
 * 点击电机
 */
void MainWindow::on_motor_tool_clicked()
{
    ui->capture_card_tool_widget->setStyleSheet("");

    ui->motor_tool_widget->setStyleSheet(two_menu_btn_style);
    //电机的信号
    //读取电机的信息并显示
    dianji_set->ui->lineEdit->setText(dianji_name);
    dianji_set->show();

}

/**
 * @brief MainWindow::on_capture_card_tool_clicked
 * 采集卡
 */
void MainWindow::on_capture_card_tool_clicked()
{
    ui->motor_tool_widget->setStyleSheet("");


    ui->capture_card_tool_widget->setStyleSheet(two_menu_btn_style);
    if(getdata->if_connect)
    {
        caijika_set->ui->lineEdit->setText("1");
    }
    //采集卡的信号
    //读取采集卡的信息并显示
    caijika_set->show();

}
/**
 * @brief MainWindow::on_config_tool_clicked
 * 二级设置
 */
void MainWindow::on_config_tool_clicked()
{
    cTwoStyle();
    ui->config_tool_widget->setStyleSheet(two_menu_btn_style);
    measure_set->show();
}
/**
 * @brief MainWindow::on_auto_focus_tool_clicked
 * 自动对焦
 */
void MainWindow::on_auto_focus_tool_clicked()
{
    //    cTwoStyle();

    ui->focus_distance_tool_widget->setStyleSheet("");
    ui->close_focus_tool_widget->setStyleSheet("");
    ui->stop_focusing_tool_widget->setStyleSheet("");


    ui->auto_focus_tool_widget->setStyleSheet(two_menu_btn_style);
    if(machinery->ele_state)
    {
        ui->auto_focus_tool->setEnabled(false);
        //先向前走，远对焦
        machinery->on_foreward();
        machinery->on_star();
        //开启查询线程，看是否到了限位
        timSend->start(1000);

    }
    else
    {

        QMessageBox::information(NULL, "异常", "电机未连接，无法对焦",
                                 QMessageBox::Yes , QMessageBox::Yes);
    }
}

/**
 * @brief MainWindow::on_focus_distance_tool_clicked
 * 远处对焦
 */
void MainWindow::on_focus_distance_tool_clicked()
{
    //    cTwoStyle();
    ui->auto_focus_tool_widget->setStyleSheet("");
    ui->close_focus_tool_widget->setStyleSheet("");

    ui->stop_focusing_tool_widget->setStyleSheet("");
    ui->focus_distance_tool_widget->setStyleSheet(two_menu_btn_style);
    //远对焦就是向前
    machinery->on_foreward();
    machinery->on_star();
}


/**
 * @brief MainWindow::on_close_focus_tool_clicked
 * 近处对焦
 */
void MainWindow::on_close_focus_tool_clicked()
{
    ui->auto_focus_tool_widget->setStyleSheet("");
    ui->focus_distance_tool_widget->setStyleSheet("");

    ui->stop_focusing_tool_widget->setStyleSheet("");
    ui->close_focus_tool_widget->setStyleSheet(two_menu_btn_style);
    //近对焦就是向后
    machinery->on_inversion();
    machinery->on_star();
}
/**
 * @brief MainWindow::on_stop_focusing_tool_clicked
 * 停止对焦
 */
void MainWindow::on_stop_focusing_tool_clicked()
{  ui->auto_focus_tool_widget->setStyleSheet("");
    ui->focus_distance_tool_widget->setStyleSheet("");
    ui->close_focus_tool_widget->setStyleSheet("");

    ui->stop_focusing_tool_widget->setStyleSheet(two_menu_btn_style);
    machinery->on_stop();

}


/**
 * @brief MainWindow::on_single_measurement_tool_clicked
 * 单次测量
 */
void MainWindow::on_single_measurement_tool_clicked()
{
    ui->continuous_measurement_tool_widget->setStyleSheet("");
    ui->stop_focusing_tool_widget_2->setStyleSheet("");

    ui->single_measurement_tool_widget->setStyleSheet(two_menu_btn_style);
    //清空界面上现有的数据
    ui->widget_time->graph(0)->data()->clear();
    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);
    ui->widget_frquency->graph(0)->data()->clear();
    ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);

    if_danci_measure=true;
    if(getdata->if_connect)
    {
        getdata->if_danci_celiang=true;
        getdata->if_lianxu_celiang=false;


        getdata->start();
        rePlotTimer.start(200); // 间隔200ms刷新一次
    }
    else
    {
        QMessageBox::information(NULL,"设备未连接", "请检查设备上电和USB连接情况",
                                 QMessageBox::Yes , QMessageBox::Yes);

    }
}
/**
 * @brief MainWindow::on_continuous_measurement_tool_clicked
 * 连续测量
 */
void MainWindow::on_continuous_measurement_tool_clicked()
{
    ui->stop_focusing_tool_widget_2->setStyleSheet("");
    ui->single_measurement_tool_widget->setStyleSheet("");

    ui->continuous_measurement_tool_widget->setStyleSheet(two_menu_btn_style);
    //连续测试
    //清空界面上现有的数据
    ui->widget_time->graph(0)->data()->clear();
    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);
    ui->widget_frquency->graph(0)->data()->clear();
    ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);

    if_danci_measure=false;
    if(getdata->if_connect)
    {

        getdata->if_lianxu_celiang=true;
        getdata->if_danci_celiang=false;

        getdata->start();
        rePlotTimer.start(200); // 间隔200ms刷新一次

    }
    else
    {
        QMessageBox::information(NULL, "设备未连接", "请检查设备上电和USB连接情况",
                                 QMessageBox::Yes , QMessageBox::Yes);

    }
}
/**
 * @brief MainWindow::on_stop_focusing_tool_2_clicked
 * 暂停
 */
void MainWindow::on_stop_focusing_tool_2_clicked()
{
    ui->continuous_measurement_tool_widget->setStyleSheet("");
    ui->single_measurement_tool_widget->setStyleSheet("");

    ui->stop_focusing_tool_widget_2->setStyleSheet(two_menu_btn_style);
    //暂停测量
    if(if_danci_measure)
    {

        QMessageBox::information(NULL, "错误", "单次测量无法暂停",
                                 QMessageBox::Yes , QMessageBox::Yes);

    }
    else
    {
        getdata-> threadStop();
        rePlotTimer.stop();
    }
}

/**
 * @brief MainWindow::on_mouse_arrow_tool_clicked
 * 鼠标箭头
 */
void MainWindow::on_mouse_arrow_tool_clicked()
{
    //    cTwoStyle();
    ui->mouse_arrow_tool_widget->setStyleSheet("");
    ui->zoom_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet("");

    ui->mouse_arrow_tool_widget->setStyleSheet(two_menu_btn_style);
    //界面回归到普通模式，无法放大缩小和框选极值
    this->setCursor(Qt::ArrowCursor );
    ui->widget_frquency->if_able=false;
    ui->widget_time->if_able=false;
    ui->widget_frquency->if_fangda=false;
    ui->widget_time->if_fangda=false;
    if_Kuangxuan=false;
}

/**
 * @brief MainWindow::on_zoom_tool_clicked
 * 缩放
 */
void MainWindow::on_zoom_tool_clicked()
{
    ui->mouse_arrow_tool_widget->setStyleSheet("");
    ui->zoom_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet("");

    ui->zoom_tool_widget->setStyleSheet(two_menu_btn_style);
    //鼠标变为放大
    ui->widget_frquency->if_able=true;
    ui->widget_time->if_able=true;
    this->setCursor(Qt::PointingHandCursor);
    ui->widget_frquency->if_fangda=true;
    ui->widget_time->if_fangda=true;
    if_Kuangxuan=false;
}


/**
 * @brief MainWindow::on_recovery_tool_clicked
 * 复原
 */
void MainWindow::on_recovery_tool_clicked()
{
    ui->mouse_arrow_tool_widget->setStyleSheet("");
    ui->zoom_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet(two_menu_btn_style);
    //需要获得各个模块的坐标值
    //鼠标变为放大
    this->setCursor(Qt::ArrowCursor );
    ui->widget_time->xAxis->setRange(0, measure_set->capture_time);//设置x轴的范围
    ui->widget_time->graph(0)->rescaleValueAxis();
    ui->widget_time->replot();//replot(QCustomPlot::rpQueuedReplot);
    ui->widget_frquency->xAxis->setRange(0, measure_set->daikuan);//设置x轴的范围
    ui->widget_frquency->graph(0)->rescaleValueAxis();
    ui->widget_frquency->replot();//->replot(QCustomPlot::rpQueuedReplot);
}
/**
 * @brief MainWindow::on_box_select_extrema_tool_clicked
 * 框选极值
 */
void MainWindow::on_box_select_extrema_tool_clicked()
{
    ui->mouse_arrow_tool_widget->setStyleSheet("");
    ui->zoom_tool_widget->setStyleSheet("");
    ui->recovery_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet("");
    ui->box_select_extrema_tool_widget->setStyleSheet(two_menu_btn_style);
    //鼠标变为放大
    ui->widget_frquency->if_able=true;
    ui->widget_time->if_able=true;
    this->setCursor(Qt::CrossCursor );
    ui->widget_frquency->if_fangda=false;
    ui->widget_time->if_fangda=false;
    if_Kuangxuan=true;
}

/**
 * @brief MainWindow::on_open_file_tool_clicked
 * 打开文件
 */
void MainWindow::on_open_file_tool_clicked()
{
    ui->open_file_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet("");
    ui->open_file_tool_widget->setStyleSheet(two_menu_btn_style);
    //对打开的文件显示FFT
    if(if_in_measure)
    {
        QMessageBox::information(NULL, "提示", "正在测量，请稍后操作",
                                 QMessageBox::Yes , QMessageBox::Yes);
    }
    else
    {
        //打开文件
        QString fileName;
        fileName = QFileDialog::getOpenFileName(this,"打开文件",tr(""),tr("Text File (*.txt)"));
        if(fileName == "")                  //如果用户直接关闭了文件浏览对话框，那么文件名就为空值，直接返回
        {
            return;
        }
        else
        {
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
                return;
            }
            else
            {
                if(!file.isReadable())
                {
                    QMessageBox::warning(this,tr("错误"),tr("该文件不可读"));
                }
                else
                {
                    QTextStream textStream(&file);       //读取文件，使用QTextStream

                    while(!textStream.atEnd())
                    {
                        read_list=textStream.readAll().split("@");

                    }
                    QListIterator<QString> li(read_list);
                    int readlen=read_list.size();

                    int fs=li.next().toDouble();
                    int save_puxianshu=li.next().toDouble();
                    int save_time_num=li.next().toDouble();
                    int n=floor(readlen);
                    double *read_date=new double[n];
                    double *read_time_date=new double[save_time_num];
                    double *read_fft_date=new double[save_puxianshu];
                    int i=0;
                    while(li.hasNext())
                    {
                        read_date[i]=li.next().toDouble();

                        i=i+1;
                    }
                    //把数据切分

                    for(int i=0;i<save_time_num;i++)
                    {


                        read_time_date[i]=read_date[i];
                    }
                    for(int i=0;i<save_puxianshu;i++)
                    {


                        read_fft_date[i]=read_date[i+save_time_num];
                    }
                    //把数据展示
                    ui->widget_time->graph(0)->data().data()->clear();

                    show_save_Time(read_time_date, save_time_num, fs);//显示本地的时域数据

                    ui->widget_frquency->graph(0)->data().data()->clear();
                    show_save_FFT(read_fft_date,save_puxianshu,fs,save_time_num);//显示本地的频域数据
                }
            }

        }
    }
}
/**
 * @brief MainWindow::on_export_table_tool_clicked
 * 导出表格
 */
void MainWindow::on_export_table_tool_clicked()
{
    ui->open_file_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet(two_menu_btn_style);

    //保存测量表格结果
    QString fileName = QFileDialog::getSaveFileName(ui->tableView, "保存",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                    "Excel (*.xls *.xlsx)");
    if (fileName!="")
    {
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")) //连接Excel控件
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            int i,j,colcount=model->columnCount();
            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", QString::fromLocal8Bit("历史测量记录"));
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter
            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", ui->tableView->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                columnName=model->horizontalHeaderItem(i)->text();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }
            //数据区
            for(i=0;i<model->rowCount();i++){
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", model->item(i,j)?model->item(i,j)->text():"");
                }
            }
            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(model->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(model->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,QString::fromLocal8Bit("完成"),QString::fromLocal8Bit("文件已经导出，是否现在打开？"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }
        }
        else
        {
            QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel",QMessageBox::Apply);
        }
    }
}
/**
 * @brief MainWindow::on_save_data_tool_clicked
 * 保存数据
 *
 */
void MainWindow::on_save_data_tool_clicked()
{
    ui->open_file_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet(two_menu_btn_style);
    if(!if_danci_measure)
    {        QMessageBox::information(this,"提示","单次测量才可导出数据",QMessageBox::Ok);

        return;
    }
    else
    {
        //二进制编码保存
        QString fileName;
        QFileDialog fileDialog;
        QString str = fileDialog.getSaveFileName(this,"打开文件","measure",tr("Text File(*.txt)"));
        if(str == "")
        {
            return;
        }
        QFile filename(str);
        if(!filename.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,"错误","打开文件失败",QMessageBox::Ok);
            return;
        }
        else
        {
            QTextStream textStream(&filename);


            textStream<<double(measure_set->caiyanglv)<<"@";//先添加采样率
            textStream<<double(measure_set->puxianshu)<<"@";//先添加谱线数
            textStream<<double(measure_set->default_measure_num)<<"@";//再添加保存的时域数据点
            //先添加时域测量数据

            for(int r=0;r<measure_set->default_measure_num;r++)
            {

                textStream<<double(save_date[r])<<"@";

            }
            for(int r=0;r<measure_set->puxianshu;r++)
            {


                textStream<<double(save_fft_date[r])<<"@";
            }

            QMessageBox::information(this,"保存文件","保存文件成功",QMessageBox::Ok);
            filename.close();
        }

    }
}
/**
 * @brief MainWindow::on_print_tool_clicked
 * 打印
 */
void MainWindow::on_print_tool_clicked()
{
    ui->open_file_tool_widget->setStyleSheet("");
    ui->export_table_tool_widget->setStyleSheet("");
    ui->save_data_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet("");
    ui->print_tool_widget->setStyleSheet(two_menu_btn_style);
    //打印
    QString fileName = QFileDialog::getSaveFileName(this, "保存PDF", "", tr("save Files (*.PDF)"));

    if(fileName.isEmpty())
        return;
    else

    {
        QPrinter printer_pixmap(QPrinter::HighResolution);
        printer_pixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
        printer_pixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf


        printer_pixmap.setOutputFileName(fileName);  //设置输出路径

        QPixmap pixmap = QPixmap::grabWidget(ui->widget_time,ui->widget_time->rect());   //获取界面的图片
        //获取频域图像
        QPixmap pixmapfft = QPixmap::grabWidget(ui->widget_frquency,ui->widget_frquency->rect());   //获取界面的图片
        QPainter painter_pixmap;
        painter_pixmap.begin(&printer_pixmap);
        //先写一段文字
        //QFont m_font("New timer",15,QFont::Bold,true);
        //painter_pixmap.setFont(m_font);
        painter_pixmap.setPen(QColor(255,143,36));
        //painter.drawText(const QRectF(fmt.width(text), fmt.height()),Qt::AlignLeft, text);
        //QString xianshi=ui-> textEdit_lishi->toPlainText();
        painter_pixmap.drawText(0,0,"lishi");
        //写文字




        QRect rect = painter_pixmap.viewport();
        int multiple = rect.width()/pixmap.width();
        painter_pixmap.scale(multiple, multiple);//将图像(所有要画的东西)在pdf上放大multiple-1倍
        painter_pixmap.drawPixmap(0, 10, pixmap);  //画图
        painter_pixmap.drawPixmap(0, pixmap.height()+10, pixmapfft);  //画图
        //    QRect rectfft = painter_pixmap.viewport();
        //    int multiplefft = rectfft.width()/pixmapfft.width();
        //    painter_pixmap.scale(multiplefft, multiplefft);//将图像(所有要画的东西)在pdf上放大multiple-1倍
        //    painter_pixmap.drawPixmap(0, 0, pixmapfft);  //画图

        painter_pixmap.end();
        QMessageBox::about(this, "提示", "测量结果导出成功");

    }
}

void MainWindow::on_home_maximize_clicked(bool checked)
{
    qDebug() << "checked："; qDebug() << checked;

    QSize localSize = this->size();
    int width = localSize.width();
    int height = localSize.height();
    qDebug() << "width："; qDebug() << width;
    qDebug() << "height："; qDebug() << height;

    if(width==1920&&height==1080){


        ui->home_maximize->setStyleSheet("QPushButton#home_maximize{border-image:url(:/img/btn/A1.png);}QPushButton#home_maximize:hover{border-image:url(:/img/btn/A2.png);}QPushButton#home_maximize:pressed{url(:/img/btn/A2.png);}");
        QString localStyleSheet = ui->widget_5->styleSheet();
        QString localReplaceStyle = utils.replaceStyle(localStyleSheet,"25px","15px");
        localReplaceStyle = utils.replaceStyle(localReplaceStyle,"25px","15px");
        qDebug() << "localReplaceStyle："; qDebug() << localReplaceStyle;

        ui->widget_5->setStyleSheet(localReplaceStyle);
        this->resize(1500,800);

    }else{
        this->move(0,0);
        ui->home_maximize->setStyleSheet("QPushButton#home_maximize{border-image:url(:/img/btn/maximize.png);}QPushButton#home_maximize:hover{border-image:url(:/img/btn/maximize2.png);}QPushButton#home_maximize:pressed{url(:/img/btn/maximize2.png);}");
        ui->widget_5->setStyleSheet(Qstyle);
        qDebug() << "当前："; qDebug() << "6286";
        this->resize(1920,1080);
        this->showMaximized();

    }
}
//不直接和按钮建立的函数
//电机相关
void MainWindow::on_far_one()
{
    machinery->on_foreward_one();
}
//向后走一步
void MainWindow::on_near_one()
{
    machinery->on_inversion_one();

}
//向前走一步
void MainWindow::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::sent_instruction()
{

    machinery->on_query();

}
void MainWindow::serialPortRead_Slot()
{
    /*QString recBuf;
    recBuf = QString(mySerialPort->readAll());*/

    QByteArray recBuf;
    recBuf = machinery->m_serialPort->readAll();



    // 判断是否为16进制接收，将以后接收的数据全部转换为16进制显示（先前接收的部分在多选框槽函数中进行转换。最好多选框和接收区组成一个自定义控件，方便以后调用）

    // 16进制显示，并转换为大写
    QString str1 = recBuf.toHex().toUpper();//.data();
    // 添加空格
    QString str2;
    for(int i = 0; i<str1.length (); i+=2)
    {
        str2 += str1.mid (i,2);
        str2 += " ";
    }
    //    ui->txtRec->insertPlainText(str2);

    //    // 移动光标到文本结尾
    //    ui->txtRec->moveCursor(QTextCursor::End);
    //    ui->txtRec->insertPlainText("\n");
    //加入判断
    QString jiaoyan;//校验位为最后一位

    QString jiaoyan1= str1.mid (0,2);
    QString jiaoyan2= str1.mid (str1.length ()-4,2);
    if(jiaoyan2=="01"&&jiaoyan1=="AA"&&str1.length()==14)
    {
        panduan="01";
        timSend->stop();

        //碰到了显微开关01,到另一边的头

    }
    else if(jiaoyan2=="02"&&jiaoyan1=="AA"&&str1.length()==14)
    {

        //碰到了显微开关02
        //停止向前走
        //单步到另一边
        timSend->stop();
        stop_return_best();
    }
    else
    {


    }
}
void MainWindow::stop_return_best()
{
    //停止返回
    machinery->on_stop();
    //    Delay_MSec(2000);//我要弹开开关

    //    //先走出限位
    //    machinery->on_inversion_one();
    //    Delay_MSec(100);
    //    machinery->on_inversion_one();
    //    Delay_MSec(100);
    //    //先走出限位
    //    //开启自动对焦

    //    timSend->start(1000);
    int i_num=0;
    while(i_num<70)//panduan!="01"
    {

        machinery->on_inversion_one();
        //Delay_MSec(50);
        step++;
        double energy=getdata->get_one_energy();
        QString show_step=QString::number(step);
        QString show_energy=QString::number(energy,'f',2);
        QString show_information="步数:"+show_step+"能量:"+show_energy;
        //        ui->txtRec->insertPlainText(show_information);

        //        // 移动光标到文本结尾
        //        ui->txtRec->moveCursor(QTextCursor::End);
        //        ui->txtRec->insertPlainText("\n");
        qDebug("步数%d,能量%f",step,energy);
        if(energy>last_energy)
        {
            step_best=step;
            last_energy=energy;
        }

        i_num++;
    }
    qDebug("最佳步数第%d步",step_best);
    //碰到限位才会跳出循环
    //回到最佳位置
    QString show_step=QString::number(step_best);
    QString show_energy=QString::number(last_energy,'f',6);
    QString show_information="最佳步数:"+show_step+"最大能量:"+show_energy;
    //    ui->txtRec->insertPlainText(show_information);
    //    // 移动光标到文本结尾
    //    ui->txtRec->moveCursor(QTextCursor::End);
    //    ui->txtRec->insertPlainText("\n");
    int return_step=step-step_best+1;
    machinery->on_num_foreward(return_step);
    QMessageBox::information(NULL, "right", QString::fromLocal8Bit("完成对焦"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    ui->auto_focus_tool->setEnabled(true);
}




void MainWindow::keyPressEvent(QKeyEvent * e)
{
    if (e->key() == Qt::Key_1)
    {

        //向前走一步
    }
    else if (e->key() == Qt::Key_2)
    {
        //电机向后走一步

    }

    else if (e->key() == Qt::Key_S)
    {

        //保存原始数据
    }


    else if (e->key() == Qt::Key_G)
    {

        //自动对焦

    }
}
void MainWindow::on_time_wait(int wait_time)
{

    QTime dieTime = QTime::currentTime().addMSecs(wait_time);//
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

void MainWindow::save_data_over(bool if_over)
{


    QMessageBox::critical(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("原始数据存储完毕"));
}

void MainWindow::timeToRePlot()
{

    ui->widget_time->graph(0)->rescaleValueAxis();
    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);

}
void MainWindow::stop_timer()
{
    on_time_wait(200);
    rePlotTimer.stop();

}
void MainWindow::receive_neicun(int lenght)
{
    QString show=QStringLiteral("内存长度:").toStdString().c_str()+QString::number(lenght);
    ui->txtRec->insertPlainText(show);

    // 移动光标到文本结尾
    ui->txtRec->moveCursor(QTextCursor::End);
    ui->txtRec->insertPlainText("\n");

}
//连接设备

void MainWindow::if_clear_data(bool if_clear)
{

    m_Mutex.lock();
    ui->widget_time->graph(0)->data()->clear();
    //ui->widget_time->replot(QCustomPlot::rpQueuedReplot);
    ui->widget_frquency->graph(0)->data()->clear();
    //ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);
    m_Mutex.unlock();

}
//显示时域
void MainWindow::show_Time(double  * showdate, int len, int measure_num)
{



    //    QString show= QStringLiteral("单次测量画线").toStdString().c_str();
    //    qDebug(show.toStdString().c_str());
    //    QString show_num=QString::number(measure_num);
    //    qDebug(show_num.toStdString().c_str());
    QVector<double> time(len),y(len); // initialize with entries 0..100
    //    double celiang_MAX=math_process->calc_MAX(showdate,len);
    //    if(10e-6<=celiang_MAX<10e-3)
    //    {
    //        xianshi_gain=10e3;
    //        //设置为毫米/s
    //        if(type==2)
    //        {
    //        ui->label_6->setText(QStringLiteral("毫米/秒").toStdString().c_str());
    //        ui->label_7->setText(QStringLiteral("毫米/秒").toStdString().c_str());
    //        }
    //        else if(type==1)
    //        {
    //            ui->label_6->setText(QStringLiteral("毫米").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("毫米").toStdString().c_str());

    //        }
    //        else
    //        {

    //            ui->label_6->setText(QStringLiteral("毫米/秒^2").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("毫米/秒^2").toStdString().c_str());

    //        }
    //    }
    //    else if(10e-9<=celiang_MAX<10e-6)
    //    {
    //        xianshi_gain=10e6;
    //        //设置为微米/s
    //        if(type==2)
    //        {
    //        ui->label_6->setText(QStringLiteral("微米/秒").toStdString().c_str());
    //        ui->label_7->setText(QStringLiteral("微米/秒").toStdString().c_str());
    //        }
    //        else if(type==1)
    //        {
    //            ui->label_6->setText(QStringLiteral("微米").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("微米").toStdString().c_str());

    //        }
    //        else
    //        {

    //            ui->label_6->setText(QStringLiteral("微米/秒^2").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("微米/秒^2").toStdString().c_str());

    //        }

    //    }
    //    else if(celiang_MAX<10e-9)
    //    {
    //        xianshi_gain=10e9;
    //        //设置为纳米/s
    //        if(type==2)
    //        {
    //        ui->label_6->setText(QStringLiteral("纳米/秒").toStdString().c_str());
    //        ui->label_7->setText(QStringLiteral("纳米/秒").toStdString().c_str());
    //        }
    //        else if(type==1)
    //        {
    //            ui->label_6->setText(QStringLiteral("纳米").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("纳米").toStdString().c_str());

    //        }
    //        else
    //        {

    //            ui->label_6->setText(QStringLiteral("纳米/秒^2").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("纳米/秒^2").toStdString().c_str());

    //        }


    //    }
    //    else
    //    {
    //        xianshi_gain=1;
    //        //设置为纳米/s
    //        if(type==2)
    //        {
    //        ui->label_6->setText(QStringLiteral("米/秒").toStdString().c_str());
    //        ui->label_7->setText(QStringLiteral("米/秒").toStdString().c_str());
    //        }
    //        else if(type==1)
    //        {
    //            ui->label_6->setText(QStringLiteral("米").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("米").toStdString().c_str());

    //        }
    //        else
    //        {

    //            ui->label_6->setText(QStringLiteral("米/秒^2").toStdString().c_str());
    //            ui->label_7->setText(QStringLiteral("米/秒^2").toStdString().c_str());

    //        }


    //    }
    for (unsigned int i=0; i<len;i++)
    {
        time [i] = double(i+(measure_num)*len)/double(measure_set->caiyanglv); // x goes from -1 to 1
        //判断数据的范围

        y[i]=showdate[i]*xianshi_gain;

        save_date[i+(measure_num)*len]=showdate[i];

    }
    ui->widget_time->graph(0)->addData(time, y);
    //求取最大值最小值
    //    timey_max = *(std::max_element(std::begin(y), std::end(y)));
    //    //最小值表示：
    //    timey_min =*(std::min_element(std::begin(y), std::end(y)));



    //    ui->widget_time->graph(0)->rescaleValueAxis();
    //    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);


    //    QString  data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss.zzz ");
    //    qDebug(QStringLiteral("频域刷新成功").toStdString().c_str());
    //    qDebug(data_time.toStdString().c_str());


}

//显示频域
void MainWindow::show_FFT(double  * FFT_date,int fft_len)
{

    QString show= QStringLiteral("画频域线").toStdString().c_str()+QString::number(fft_len);
    qDebug(show.toStdString().c_str());
    QVector<double> fft_time(fft_len),y_fft(fft_len); // initialize with entries 0..100
    if(if_pinlvxianshi)
    {
        for (unsigned int i=0; i<fft_len-100;i++)
        {
            fft_time [i] = double(i)*double(measure_set->caiyanglv)/double(measure_set->default_measure_num); // x goes from -1 to 1

            y_fft[i] =FFT_date[i]*xianshi_gain;
            save_fft_date[i]= y_fft[i];

        }
    }
    else
    {
        //计算功率谱
        for (unsigned int i=0; i<fft_len-100;i++)
        {
            fft_time [i] = double(i)*double(measure_set->caiyanglv)/double(measure_set->default_measure_num); // x goes from -1 to 1

            y_fft[i] =FFT_date[i]*xianshi_gain;
            save_fft_date[i]= y_fft[i];

        }

    }
    ui->widget_frquency->graph(0)->setData(fft_time, y_fft);

    ui->widget_frquency->graph(0)->rescaleValueAxis();

    ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);


    //求取频率的最大值和最大值的位置
    double* outmax=math_process->calcMAX(FFT_date,fft_len);


    QString zuida="("+QString::number((outmax[1])*double(measure_set->caiyanglv)/double(measure_set->default_measure_num))+","+QString::number(outmax[0])+")";

    ui->lineEdit_MAX->setText(zuida);

}
void MainWindow::show_save_Time(double  * showdate, int len, int fs)
{


    QString show= QStringLiteral("单次测量画线").toStdString().c_str();
    qDebug(show.toStdString().c_str());
    QVector<double> time(len),y(len); // initialize with entries 0..100

    for (unsigned int i=0; i<len;i++)
    {
        time [i] = double(i)/double(fs); // x goes from -1 to 1

        y[i] =showdate[i];


    }
    ui->widget_time->graph(0)->setData(time, y);
    //求取最大值最小值
    timey_max = *(std::max_element(std::begin(y), std::end(y)));
    //最小值表示：
    timey_min =*(std::min_element(std::begin(y), std::end(y)));

    timex_min=time [0];
    timex_max=time [len-1];
    ui->widget_time->xAxis->setRange(timex_min, timex_max);//实时调整X轴的显示范围


    ui->widget_time->graph(0)->rescaleValueAxis();

    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);



}
//显示频域
void MainWindow::show_save_FFT(double  * FFT_date,int fft_len, int fs, int all_num)
{

    QString show= QStringLiteral("画频域线").toStdString().c_str()+QString::number(fft_len);
    qDebug(show.toStdString().c_str());
    QVector<double> fft_time(fft_len),y_fft(fft_len); // initialize with entries 0..100

    for (unsigned int i=0; i<fft_len;i++)
    {
        fft_time [i] = double(i)*double(fs)/double(all_num); // x goes from -1 to 1

        y_fft[i] =FFT_date[i];

    }
    ui->widget_frquency->graph(0)->setData(fft_time, y_fft);

    //求取最大值最小值
    ffty_max = *(std::max_element(std::begin(y_fft), std::end(y_fft)));
    //最小值表示：
    ffty_min = *(std::min_element(std::begin(y_fft), std::end(y_fft)));

    fftx_min=fft_time [0] ;
    fftx_max=fft_time [fft_len-1];
    ui->widget_frquency->xAxis->setRange(fftx_min, fftx_max);//实时调整X轴的显示范围

    ui->widget_frquency->graph(0)->rescaleValueAxis();
    ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);



}
//显示RMS
void MainWindow::show_RMS_value(double rms)
{
    QString Show_rms=QString::number(rms);
    ui->lineEdit_RMS->setText(Show_rms);
}
//获得时域的坐标
void MainWindow::Get_timePoint(QPoint start_Pos ,QPoint end_Pos)
{

    int current_Rx = ui->widget_time->xAxis->pixelToCoord(start_Pos.x())*double(measure_set->caiyanglv);
    if(current_Rx<=0)
    {
        current_Rx<=0;
    }
    int end_Rx = ui->widget_time->xAxis->pixelToCoord(end_Pos.x())*double(measure_set->caiyanglv);
    if(end_Rx<=0)
    {
        end_Rx=0;
    }
    double current_Ry = ui->widget_time->yAxis->pixelToCoord(start_Pos.y());

    double end_Ry = ui->widget_time->yAxis->pixelToCoord(end_Pos.y());
    if(current_Rx>end_Rx)
    {
        int temp=end_Rx;

        end_Rx=current_Rx;
        current_Rx=temp;
    }


    int calcute_point_num=end_Rx-current_Rx;

    double *calcute=new double[calcute_point_num];
    int j=0;
    for(int i=current_Rx; i<end_Rx;i++)
    {
        double temp=save_date[i];
        calcute[j]=save_date[i];
        j++;
    }
    //计算数据的
    double time_STD=math_process->calcSTD(calcute,j);
    double* outmax=math_process->calcMAX(calcute,j);
    double* outmin=math_process->calcMIN(calcute,j);
    double outrms=math_process->calcRMS(calcute,j);

    //显示第几行
    model->setItem(cala_num,0,new QStandardItem(QString::number(cala_num)));
    QString qishidian="("+QString::number((current_Rx)/double(measure_set->caiyanglv))+","+QString::number(calcute[0])+")";
    model->setItem(cala_num,1,new QStandardItem(qishidian));
    QString zhongzhidian="("+QString::number((end_Rx)/double(measure_set->caiyanglv))+","+QString::number(calcute[j-1])+")";
    model->setItem(cala_num,2,new QStandardItem(zhongzhidian));
    QString zuida="("+QString::number((outmax[1]+current_Rx)/double(measure_set->caiyanglv))+","+QString::number(outmax[0])+")";
    model->setItem(cala_num,3,new QStandardItem(zuida));

    //计算RMS
    QString showrms=QString::number(outrms);
    model->setItem(cala_num,4,new QStandardItem(showrms));
    cala_num++;
    if(cala_num>=model->rowCount())
    {
        model->setRowCount(cala_num + 1);
    }


}

//获得FFT的坐标
void MainWindow::Get_fftPoint(QPoint start_Pos ,QPoint end_Pos)
{

    double zuobiaozhuanhuan=double(measure_set->default_measure_num)/double(measure_set->caiyanglv);
    int current_Rx = ui->widget_frquency->xAxis->pixelToCoord(start_Pos.x())*zuobiaozhuanhuan;

    if(current_Rx<=0)
    {
        current_Rx=0;
    }
    int end_Rx = ui->widget_frquency->xAxis->pixelToCoord(end_Pos.x())*zuobiaozhuanhuan;
    if(end_Rx<=0)
    {
        end_Rx=0;
    }
    double current_Ry = ui->widget_frquency->yAxis->pixelToCoord(start_Pos.y());

    double end_Ry = ui->widget_frquency->yAxis->pixelToCoord(end_Pos.y());
    if(current_Rx>end_Rx)
    {
        int temp=end_Rx;

        end_Rx=current_Rx;
        current_Rx=temp;
    }


    int calcute_point_num=end_Rx-current_Rx;

    double *calcute=new double[calcute_point_num];
    int j=0;
    for(int i=current_Rx; i<end_Rx;i++)
    {
        double temp=save_fft_date[i];
        calcute[j]=save_fft_date[i];
        j++;
    }
    //计算数据的
    double time_STD=math_process->calcSTD(calcute,j);
    double* outmax=math_process->calcMAX(calcute,j);
    double* outmin=math_process->calcMIN(calcute,j);
    double outrms=math_process->calcRMS(calcute,j);

    //显示第几行
    model->setItem(cala_num,0,new QStandardItem(QString::number(cala_num)));
    //显示边界起始点
    QString qishidian="("+QString::number((current_Rx)/double(zuobiaozhuanhuan))+","+QString::number(calcute[0])+")";
    model->setItem(cala_num,1,new QStandardItem(qishidian));

    //显示边界终止点
    QString zhongzhidian="("+QString::number((end_Rx)/double(zuobiaozhuanhuan))+","+QString::number(calcute[j-1])+")";
    model->setItem(cala_num,2,new QStandardItem(zhongzhidian));

    //显示极值
    QString zuida="("+QString::number((outmax[1]+current_Rx)/zuobiaozhuanhuan)+","+QString::number(outmax[0])+")";
    model->setItem(cala_num,3,new QStandardItem(zuida));

    //计算RMS
    QString showrms=QString::number(outrms);
    model->setItem(cala_num,4,new QStandardItem(showrms));

    cala_num++;
    if(cala_num>=model->rowCount())
    {
        model->setRowCount(cala_num + 1);
    }



}
void MainWindow::receive_setting(bool if_set)
{
    measure_set->close();
    int fs=measure_set->caiyanglv;
    double capture_time=measure_set->capture_time;
    bool if_usb_capture=measure_set->if_USB;
    if(measure_set->if_O)
    {
        celiang_int=0;
        type=0;
        //time单位
        ui->lab_time_x->setText("V");
        ui->lab_time_y->setText("V");

        //frquecy单位
        ui->lab_fr_x->setText("V");
        ui->lab_fr_y->setText("V");
    }
    else if(measure_set->if_D)
    {
        celiang_int=2;
        type=2;
        //time单位
        ui->lab_time_x->setText("时间/秒");
        ui->lab_time_y->setText("米/秒");

        //frquecy单位
        ui->lab_fr_x->setText("频率/赫兹（Hz）");
        ui->lab_fr_y->setText("米/秒");

    }
    else if (measure_set->if_S)
    {
        celiang_int=1;

        type=1;
        //time单位
        ui->lab_time_x->setText("时间/秒");
        ui->lab_time_y->setText("米");

        //frquecy单位
        ui->lab_fr_x->setText("频率/赫兹（Hz）");
        ui->lab_fr_y->setText("米");
    }

    else if (measure_set->if_A)
    {
        celiang_int=3;
        type=2;
        ui->lab_time_x->setText("时间/秒");
        ui->lab_time_y->setText("米/秒^2");

        //frquecy单位
        ui->lab_fr_x->setText("频率/赫兹（Hz）");
        ui->lab_fr_y->setText("米/秒^2");

    }
    ui->widget_time->xAxis->setRange(0, capture_time);//设置x轴的范围
    ui->widget_time->replot(QCustomPlot::rpQueuedReplot);
    ui->widget_frquency->xAxis->setRange(0, measure_set->daikuan);//设置x轴的范围
    ui->widget_frquency->replot(QCustomPlot::rpQueuedReplot);
    getdata->setting(fs, capture_time,if_usb_capture,type,measure_set->DA_type);
    processdata->setting(getdata->sent_capture_num,fs,measure_set->daikuan,measure_set->puxianshu,measure_set->lowflg,measure_set->highflg,measure_set->trackflg,measure_set->default_measure_num,measure_set->if_lvbo,celiang_int);
    save_date=new double[measure_set->default_measure_num+2*getdata->sent_capture_num];
    save_fft_date=new double[measure_set->default_measure_num+2*getdata->sent_capture_num];


}

void MainWindow::on_rad_spectrum_toggled(bool checked)
{
    if(ui->rad_spectrum->isChecked())
    {
        if_pinlvxianshi=true;
        // ui->radioButton_2->clicked(false);
        ui->lab_fr_x->setText(QStringLiteral("频率/赫兹（Hz）").toStdString().c_str());
        processdata->spectrumflg=0;
        //频谱
    }
}

void MainWindow::on_rad_power_toggled(bool checked)
{
    if(ui->rad_power->isChecked())
    {
        //功率谱
        if_pinlvxianshi=false;
        //ui->radioButton->clicked(false);
        ui->lab_fr_x->setText(QStringLiteral("瓦特（W）/赫兹（Hz）").toStdString().c_str());
        processdata->spectrumflg=1;
    }
}

void MainWindow::on_filter_toolButton_clicked()
{
    filter->set_filter_ui();
    filter->setWindowTitle(QString("滤波器设计"));

    filter->show();

}
