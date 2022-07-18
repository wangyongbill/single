/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <myplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *tool_widget;
    QPushButton *home_minimize;
    QPushButton *home_maximize;
    QPushButton *home_close;
    QWidget *title_widget;
    QLabel *home_title;
    QLabel *home_title_2;
    QWidget *tool_btn_widget;
    QWidget *equipment_btn_widget;
    QToolButton *equipment_btn;
    QWidget *config_btn_widget;
    QToolButton *config_btn;
    QWidget *focus_btn_widget;
    QToolButton *focus_btn;
    QWidget *measure_btn_widget;
    QToolButton *measure_btn;
    QWidget *analyse_btn_widget;
    QToolButton *analyse_btn;
    QWidget *file_btn_widget;
    QToolButton *file_btn;
    QStackedWidget *submenu;
    QWidget *equipment_btn_page;
    QWidget *motor_tool_widget;
    QToolButton *motor_tool;
    QWidget *capture_card_tool_widget;
    QToolButton *capture_card_tool;
    QToolButton *filter_toolButton;
    QWidget *config_btn_page;
    QWidget *config_tool_widget;
    QToolButton *config_tool;
    QWidget *focus_btn_page;
    QWidget *auto_focus_tool_widget;
    QToolButton *auto_focus_tool;
    QWidget *focus_distance_tool_widget;
    QToolButton *focus_distance_tool;
    QWidget *close_focus_tool_widget;
    QToolButton *close_focus_tool;
    QWidget *stop_focusing_tool_widget;
    QToolButton *stop_focusing_tool;
    QWidget *measure_btn_page;
    QWidget *continuous_measurement_tool_widget;
    QToolButton *continuous_measurement_tool;
    QWidget *single_measurement_tool_widget;
    QToolButton *single_measurement_tool;
    QWidget *stop_focusing_tool_widget_2;
    QToolButton *stop_focusing_tool_2;
    QWidget *analyse_btn_page;
    QWidget *zoom_tool_widget;
    QToolButton *zoom_tool;
    QWidget *box_select_extrema_tool_widget;
    QToolButton *box_select_extrema_tool;
    QWidget *mouse_arrow_tool_widget;
    QToolButton *mouse_arrow_tool;
    QWidget *recovery_tool_widget;
    QToolButton *recovery_tool;
    QWidget *file_btn_page;
    QWidget *print_tool_widget;
    QToolButton *print_tool;
    QWidget *open_file_tool_widget;
    QToolButton *open_file_tool;
    QWidget *save_data_tool_widget;
    QToolButton *save_data_tool;
    QWidget *export_table_tool_widget;
    QToolButton *export_table_tool;
    QStackedWidget *sw;
    QWidget *page;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_9;
    QLabel *label;
    QWidget *plot2;
    MyPlot *widget_time;
    QLabel *lab_time_x;
    QLabel *lab_time_y;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_10;
    QWidget *widget_11;
    QLabel *label_2;
    QWidget *plot;
    MyPlot *widget_frquency;
    QLabel *lab_fr_x;
    QLabel *lab_fr_y;
    QWidget *widget_5;
    QRadioButton *rad_spectrum;
    QRadioButton *rad_power;
    QLineEdit *lineEdit_RMS;
    QLabel *label_3;
    QLineEdit *lineEdit_MAX;
    QLabel *label_4;
    QWidget *widget_6;
    QWidget *widget_7;
    QPlainTextEdit *txtRec;
    QWidget *widget_8;
    QTableView *tableView;
    QWidget *widget_12;
    QWidget *widget_13;
    QLabel *label_5;
    QWidget *page2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        tool_widget = new QWidget(centralwidget);
        tool_widget->setObjectName(QString::fromUtf8("tool_widget"));
        tool_widget->setGeometry(QRect(1780, 10, 126, 23));
        home_minimize = new QPushButton(tool_widget);
        home_minimize->setObjectName(QString::fromUtf8("home_minimize"));
        home_minimize->setGeometry(QRect(0, 0, 23, 23));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(57);
        sizePolicy.setVerticalStretch(57);
        sizePolicy.setHeightForWidth(home_minimize->sizePolicy().hasHeightForWidth());
        home_minimize->setSizePolicy(sizePolicy);
        home_minimize->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/img/btn/minimum_btn.png);\n"
"}\n"
"\n"
"QPushButton:hover	 {\n"
"border-image: url(:/img/btn/minimum_btn2.png);\n"
"}\n"
"\n"
"QPushButton:pressed{url(:/img/btn/minimum_btn.png);\n"
"}\n"
""));
        home_maximize = new QPushButton(tool_widget);
        home_maximize->setObjectName(QString::fromUtf8("home_maximize"));
        home_maximize->setGeometry(QRect(48, 0, 23, 23));
        home_maximize->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#home_maximize{\n"
"border-image: url(:/img/btn/maximize.png);\n"
"}\n"
"\n"
"QPushButton#home_maximize:hover	 {\n"
"border-image: url(:/img/btn/maximize2.png);\n"
"}\n"
"\n"
"QPushButton#home_maximize:pressed{url(:/img/btn/maximize2.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        home_close = new QPushButton(tool_widget);
        home_close->setObjectName(QString::fromUtf8("home_close"));
        home_close->setGeometry(QRect(100, 0, 23, 23));
        home_close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/img/btn/closure.png);\n"
"}\n"
"\n"
"QPushButton:hover	 {\n"
"border-image: url(:/img/btn/closure2.png);\n"
"}\n"
"\n"
"QPushButton:pressed{url(:/img/btn/closure2.png);\n"
"}\n"
""));
        title_widget = new QWidget(centralwidget);
        title_widget->setObjectName(QString::fromUtf8("title_widget"));
        title_widget->setGeometry(QRect(0, 0, 1920, 60));
        title_widget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"#title_widget{\n"
"border-bottom:1px solid #a8a8a8;\n"
"\n"
"background-color:rgb(225,225,225);\n"
"}\n"
""));
        home_title = new QLabel(title_widget);
        home_title->setObjectName(QString::fromUtf8("home_title"));
        home_title->setGeometry(QRect(50, 10, 220, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(home_title->sizePolicy().hasHeightForWidth());
        home_title->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN Regular"));
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        home_title->setFont(font);
        home_title->setStyleSheet(QString::fromUtf8(""));
        home_title->setAlignment(Qt::AlignCenter);
        home_title_2 = new QLabel(title_widget);
        home_title_2->setObjectName(QString::fromUtf8("home_title_2"));
        home_title_2->setGeometry(QRect(20, 13, 41, 31));
        sizePolicy1.setHeightForWidth(home_title_2->sizePolicy().hasHeightForWidth());
        home_title_2->setSizePolicy(sizePolicy1);
        home_title_2->setFont(font);
        home_title_2->setStyleSheet(QString::fromUtf8("border-image: url(:/img/btn/logo.png);"));
        home_title_2->setAlignment(Qt::AlignCenter);
        tool_btn_widget = new QWidget(centralwidget);
        tool_btn_widget->setObjectName(QString::fromUtf8("tool_btn_widget"));
        tool_btn_widget->setGeometry(QRect(0, 60, 1920, 60));
        tool_btn_widget->setStyleSheet(QString::fromUtf8("\n"
"#tool_btn_widget{\n"
"border-bottom:1px solid #a8a8a8;\n"
"background-color:rgb(225,225,225);\n"
"\n"
"\n"
"}\n"
"QToolButton{\n"
"padding-left: 25px;\n"
"\n"
"color:rgb(81,147,219);\n"
"\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"\n"
"}\n"
"\n"
"QToolButton:hover	 {\n"
"\n"
"padding-left: 25px;\n"
"color:rgb(81,147,219)\n"
"}\n"
"\n"
"QToolButton:pressed{\n"
"\n"
"padding-left: 25px;\n"
"color:rgb(81,147,219)\n"
"}\n"
""));
        equipment_btn_widget = new QWidget(tool_btn_widget);
        equipment_btn_widget->setObjectName(QString::fromUtf8("equipment_btn_widget"));
        equipment_btn_widget->setGeometry(QRect(45, 5, 140, 55));
        equipment_btn_widget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);"));
        equipment_btn = new QToolButton(equipment_btn_widget);
        equipment_btn->setObjectName(QString::fromUtf8("equipment_btn"));
        equipment_btn->setGeometry(QRect(0, 0, 140, 55));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(equipment_btn->sizePolicy().hasHeightForWidth());
        equipment_btn->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        equipment_btn->setFont(font1);
        equipment_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/btn/equipment.png"), QSize(), QIcon::Normal, QIcon::Off);
        equipment_btn->setIcon(icon);
        equipment_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        equipment_btn->setAutoRaise(true);
        config_btn_widget = new QWidget(tool_btn_widget);
        config_btn_widget->setObjectName(QString::fromUtf8("config_btn_widget"));
        config_btn_widget->setGeometry(QRect(230, 5, 140, 55));
        config_btn_widget->setStyleSheet(QString::fromUtf8("#config_btn_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);\n"
"}\n"
""));
        config_btn = new QToolButton(config_btn_widget);
        config_btn->setObjectName(QString::fromUtf8("config_btn"));
        config_btn->setGeometry(QRect(0, 0, 140, 55));
        sizePolicy2.setHeightForWidth(config_btn->sizePolicy().hasHeightForWidth());
        config_btn->setSizePolicy(sizePolicy2);
        config_btn->setFont(font1);
        config_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/btn/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        config_btn->setIcon(icon1);
        config_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        config_btn->setAutoRaise(true);
        focus_btn_widget = new QWidget(tool_btn_widget);
        focus_btn_widget->setObjectName(QString::fromUtf8("focus_btn_widget"));
        focus_btn_widget->setGeometry(QRect(420, 5, 140, 55));
        focus_btn_widget->setStyleSheet(QString::fromUtf8("#focus_btn_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);\n"
"}\n"
""));
        focus_btn = new QToolButton(focus_btn_widget);
        focus_btn->setObjectName(QString::fromUtf8("focus_btn"));
        focus_btn->setGeometry(QRect(0, 0, 140, 55));
        sizePolicy2.setHeightForWidth(focus_btn->sizePolicy().hasHeightForWidth());
        focus_btn->setSizePolicy(sizePolicy2);
        focus_btn->setFont(font1);
        focus_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/btn/focus.png"), QSize(), QIcon::Normal, QIcon::Off);
        focus_btn->setIcon(icon2);
        focus_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        focus_btn->setAutoRaise(true);
        measure_btn_widget = new QWidget(tool_btn_widget);
        measure_btn_widget->setObjectName(QString::fromUtf8("measure_btn_widget"));
        measure_btn_widget->setGeometry(QRect(610, 5, 140, 55));
        measure_btn_widget->setStyleSheet(QString::fromUtf8("#measure_btn_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);\n"
"}\n"
""));
        measure_btn = new QToolButton(measure_btn_widget);
        measure_btn->setObjectName(QString::fromUtf8("measure_btn"));
        measure_btn->setGeometry(QRect(0, 0, 140, 55));
        sizePolicy2.setHeightForWidth(measure_btn->sizePolicy().hasHeightForWidth());
        measure_btn->setSizePolicy(sizePolicy2);
        measure_btn->setFont(font1);
        measure_btn->setStyleSheet(QString::fromUtf8(""));
        measure_btn->setIcon(icon2);
        measure_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        measure_btn->setAutoRaise(true);
        analyse_btn_widget = new QWidget(tool_btn_widget);
        analyse_btn_widget->setObjectName(QString::fromUtf8("analyse_btn_widget"));
        analyse_btn_widget->setGeometry(QRect(800, 5, 140, 55));
        analyse_btn_widget->setStyleSheet(QString::fromUtf8("#analyse_btn_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);\n"
"}\n"
""));
        analyse_btn = new QToolButton(analyse_btn_widget);
        analyse_btn->setObjectName(QString::fromUtf8("analyse_btn"));
        analyse_btn->setGeometry(QRect(0, 0, 140, 55));
        sizePolicy2.setHeightForWidth(analyse_btn->sizePolicy().hasHeightForWidth());
        analyse_btn->setSizePolicy(sizePolicy2);
        analyse_btn->setFont(font1);
        analyse_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/btn/analyse.png"), QSize(), QIcon::Normal, QIcon::Off);
        analyse_btn->setIcon(icon3);
        analyse_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        analyse_btn->setAutoRaise(true);
        file_btn_widget = new QWidget(tool_btn_widget);
        file_btn_widget->setObjectName(QString::fromUtf8("file_btn_widget"));
        file_btn_widget->setGeometry(QRect(990, 5, 140, 55));
        file_btn_widget->setStyleSheet(QString::fromUtf8("#file_btn_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click.png);\n"
"}\n"
""));
        file_btn = new QToolButton(file_btn_widget);
        file_btn->setObjectName(QString::fromUtf8("file_btn"));
        file_btn->setGeometry(QRect(0, 0, 140, 55));
        sizePolicy2.setHeightForWidth(file_btn->sizePolicy().hasHeightForWidth());
        file_btn->setSizePolicy(sizePolicy2);
        file_btn->setFont(font1);
        file_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/btn/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        file_btn->setIcon(icon4);
        file_btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        file_btn->setAutoRaise(true);
        submenu = new QStackedWidget(centralwidget);
        submenu->setObjectName(QString::fromUtf8("submenu"));
        submenu->setGeometry(QRect(0, 120, 1920, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        submenu->setFont(font2);
        submenu->setStyleSheet(QString::fromUtf8("\n"
"#submenu{\n"
"background-color:rgb(225,225,225);\n"
"}\n"
"QToolButton{\n"
"\n"
"border:none;\n"
"\n"
"padding-top:35px;\n"
"margin-top:-25px;\n"
"\n"
"color:rgb(49,81,105)\n"
"}\n"
"\n"
"QToolButton:hover	 {\n"
"\n"
"color:rgb(49,81,105)\n"
"}\n"
"\n"
"QToolButton:pressed{\n"
"\n"
"\n"
"color:rgb(49,81,105)\n"
"}\n"
"\n"
"QWidget{\n"
"background-color: rgba(0, 0, 255, 0);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset\n"
"}"));
        equipment_btn_page = new QWidget();
        equipment_btn_page->setObjectName(QString::fromUtf8("equipment_btn_page"));
        motor_tool_widget = new QWidget(equipment_btn_page);
        motor_tool_widget->setObjectName(QString::fromUtf8("motor_tool_widget"));
        motor_tool_widget->setGeometry(QRect(45, 5, 100, 61));
        motor_tool_widget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image:url(:/img/btn/tool_click2_tool.png) ;\n"
""));
        motor_tool = new QToolButton(motor_tool_widget);
        motor_tool->setObjectName(QString::fromUtf8("motor_tool"));
        motor_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(motor_tool->sizePolicy().hasHeightForWidth());
        motor_tool->setSizePolicy(sizePolicy2);
        motor_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/btn/motor_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        motor_tool->setIcon(icon5);
        motor_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        motor_tool->setAutoRaise(true);
        capture_card_tool_widget = new QWidget(equipment_btn_page);
        capture_card_tool_widget->setObjectName(QString::fromUtf8("capture_card_tool_widget"));
        capture_card_tool_widget->setGeometry(QRect(190, 5, 100, 61));
        capture_card_tool_widget->setStyleSheet(QString::fromUtf8(""));
        capture_card_tool = new QToolButton(capture_card_tool_widget);
        capture_card_tool->setObjectName(QString::fromUtf8("capture_card_tool"));
        capture_card_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(capture_card_tool->sizePolicy().hasHeightForWidth());
        capture_card_tool->setSizePolicy(sizePolicy2);
        capture_card_tool->setFont(font2);
        capture_card_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/btn/capture_card_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        capture_card_tool->setIcon(icon6);
        capture_card_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        capture_card_tool->setAutoRaise(true);
        filter_toolButton = new QToolButton(equipment_btn_page);
        filter_toolButton->setObjectName(QString::fromUtf8("filter_toolButton"));
        filter_toolButton->setGeometry(QRect(1060, 10, 71, 51));
        submenu->addWidget(equipment_btn_page);
        config_btn_page = new QWidget();
        config_btn_page->setObjectName(QString::fromUtf8("config_btn_page"));
        config_tool_widget = new QWidget(config_btn_page);
        config_tool_widget->setObjectName(QString::fromUtf8("config_tool_widget"));
        config_tool_widget->setGeometry(QRect(45, 5, 100, 61));
        config_tool_widget->setStyleSheet(QString::fromUtf8(""));
        config_tool = new QToolButton(config_tool_widget);
        config_tool->setObjectName(QString::fromUtf8("config_tool"));
        config_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(config_tool->sizePolicy().hasHeightForWidth());
        config_tool->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        config_tool->setFont(font3);
        config_tool->setStyleSheet(QString::fromUtf8(""));
        config_tool->setIcon(icon5);
        config_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        config_tool->setAutoRaise(true);
        submenu->addWidget(config_btn_page);
        focus_btn_page = new QWidget();
        focus_btn_page->setObjectName(QString::fromUtf8("focus_btn_page"));
        auto_focus_tool_widget = new QWidget(focus_btn_page);
        auto_focus_tool_widget->setObjectName(QString::fromUtf8("auto_focus_tool_widget"));
        auto_focus_tool_widget->setGeometry(QRect(45, 5, 100, 61));
        auto_focus_tool_widget->setFont(font2);
        auto_focus_tool_widget->setStyleSheet(QString::fromUtf8("#auto_focus_tool{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        auto_focus_tool = new QToolButton(auto_focus_tool_widget);
        auto_focus_tool->setObjectName(QString::fromUtf8("auto_focus_tool"));
        auto_focus_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(auto_focus_tool->sizePolicy().hasHeightForWidth());
        auto_focus_tool->setSizePolicy(sizePolicy2);
        auto_focus_tool->setFont(font3);
        auto_focus_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/btn/auto_focus_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        auto_focus_tool->setIcon(icon7);
        auto_focus_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        auto_focus_tool->setAutoRaise(true);
        focus_distance_tool_widget = new QWidget(focus_btn_page);
        focus_distance_tool_widget->setObjectName(QString::fromUtf8("focus_distance_tool_widget"));
        focus_distance_tool_widget->setGeometry(QRect(190, 5, 100, 61));
        focus_distance_tool_widget->setStyleSheet(QString::fromUtf8("#focus_distance_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        focus_distance_tool = new QToolButton(focus_distance_tool_widget);
        focus_distance_tool->setObjectName(QString::fromUtf8("focus_distance_tool"));
        focus_distance_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(focus_distance_tool->sizePolicy().hasHeightForWidth());
        focus_distance_tool->setSizePolicy(sizePolicy2);
        focus_distance_tool->setFont(font2);
        focus_distance_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/btn/focus_distance_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        focus_distance_tool->setIcon(icon8);
        focus_distance_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        focus_distance_tool->setAutoRaise(true);
        close_focus_tool_widget = new QWidget(focus_btn_page);
        close_focus_tool_widget->setObjectName(QString::fromUtf8("close_focus_tool_widget"));
        close_focus_tool_widget->setGeometry(QRect(335, 5, 100, 61));
        close_focus_tool_widget->setStyleSheet(QString::fromUtf8("#close_focus_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        close_focus_tool = new QToolButton(close_focus_tool_widget);
        close_focus_tool->setObjectName(QString::fromUtf8("close_focus_tool"));
        close_focus_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(close_focus_tool->sizePolicy().hasHeightForWidth());
        close_focus_tool->setSizePolicy(sizePolicy2);
        close_focus_tool->setFont(font2);
        close_focus_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/btn/close_focus_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_focus_tool->setIcon(icon9);
        close_focus_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        close_focus_tool->setAutoRaise(true);
        stop_focusing_tool_widget = new QWidget(focus_btn_page);
        stop_focusing_tool_widget->setObjectName(QString::fromUtf8("stop_focusing_tool_widget"));
        stop_focusing_tool_widget->setGeometry(QRect(480, 5, 100, 55));
        stop_focusing_tool_widget->setStyleSheet(QString::fromUtf8("#stop_focusing_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        stop_focusing_tool = new QToolButton(stop_focusing_tool_widget);
        stop_focusing_tool->setObjectName(QString::fromUtf8("stop_focusing_tool"));
        stop_focusing_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(stop_focusing_tool->sizePolicy().hasHeightForWidth());
        stop_focusing_tool->setSizePolicy(sizePolicy2);
        stop_focusing_tool->setFont(font2);
        stop_focusing_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/btn/stop_focusing_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop_focusing_tool->setIcon(icon10);
        stop_focusing_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        stop_focusing_tool->setAutoRaise(true);
        submenu->addWidget(focus_btn_page);
        measure_btn_page = new QWidget();
        measure_btn_page->setObjectName(QString::fromUtf8("measure_btn_page"));
        continuous_measurement_tool_widget = new QWidget(measure_btn_page);
        continuous_measurement_tool_widget->setObjectName(QString::fromUtf8("continuous_measurement_tool_widget"));
        continuous_measurement_tool_widget->setGeometry(QRect(190, 5, 100, 61));
        continuous_measurement_tool_widget->setStyleSheet(QString::fromUtf8("#continuous_measurement_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        continuous_measurement_tool = new QToolButton(continuous_measurement_tool_widget);
        continuous_measurement_tool->setObjectName(QString::fromUtf8("continuous_measurement_tool"));
        continuous_measurement_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(continuous_measurement_tool->sizePolicy().hasHeightForWidth());
        continuous_measurement_tool->setSizePolicy(sizePolicy2);
        continuous_measurement_tool->setFont(font2);
        continuous_measurement_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/btn/continuous_measurement_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        continuous_measurement_tool->setIcon(icon11);
        continuous_measurement_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        continuous_measurement_tool->setAutoRaise(true);
        single_measurement_tool_widget = new QWidget(measure_btn_page);
        single_measurement_tool_widget->setObjectName(QString::fromUtf8("single_measurement_tool_widget"));
        single_measurement_tool_widget->setGeometry(QRect(45, 5, 100, 61));
        single_measurement_tool_widget->setStyleSheet(QString::fromUtf8("#single_measurement_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        single_measurement_tool = new QToolButton(single_measurement_tool_widget);
        single_measurement_tool->setObjectName(QString::fromUtf8("single_measurement_tool"));
        single_measurement_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(single_measurement_tool->sizePolicy().hasHeightForWidth());
        single_measurement_tool->setSizePolicy(sizePolicy2);
        single_measurement_tool->setFont(font2);
        single_measurement_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/btn/single_measurement_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        single_measurement_tool->setIcon(icon12);
        single_measurement_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        single_measurement_tool->setAutoRaise(true);
        stop_focusing_tool_widget_2 = new QWidget(measure_btn_page);
        stop_focusing_tool_widget_2->setObjectName(QString::fromUtf8("stop_focusing_tool_widget_2"));
        stop_focusing_tool_widget_2->setGeometry(QRect(335, 5, 100, 61));
        stop_focusing_tool_widget_2->setStyleSheet(QString::fromUtf8("#stop_focusing_tool_widget_2{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        stop_focusing_tool_2 = new QToolButton(stop_focusing_tool_widget_2);
        stop_focusing_tool_2->setObjectName(QString::fromUtf8("stop_focusing_tool_2"));
        stop_focusing_tool_2->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(stop_focusing_tool_2->sizePolicy().hasHeightForWidth());
        stop_focusing_tool_2->setSizePolicy(sizePolicy2);
        stop_focusing_tool_2->setFont(font2);
        stop_focusing_tool_2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/btn/pause_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop_focusing_tool_2->setIcon(icon13);
        stop_focusing_tool_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        stop_focusing_tool_2->setAutoRaise(true);
        submenu->addWidget(measure_btn_page);
        analyse_btn_page = new QWidget();
        analyse_btn_page->setObjectName(QString::fromUtf8("analyse_btn_page"));
        zoom_tool_widget = new QWidget(analyse_btn_page);
        zoom_tool_widget->setObjectName(QString::fromUtf8("zoom_tool_widget"));
        zoom_tool_widget->setGeometry(QRect(195, 5, 100, 61));
        zoom_tool_widget->setStyleSheet(QString::fromUtf8("#zoom_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        zoom_tool = new QToolButton(zoom_tool_widget);
        zoom_tool->setObjectName(QString::fromUtf8("zoom_tool"));
        zoom_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(zoom_tool->sizePolicy().hasHeightForWidth());
        zoom_tool->setSizePolicy(sizePolicy2);
        zoom_tool->setFont(font2);
        zoom_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/btn/zoom_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoom_tool->setIcon(icon14);
        zoom_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        zoom_tool->setAutoRaise(true);
        box_select_extrema_tool_widget = new QWidget(analyse_btn_page);
        box_select_extrema_tool_widget->setObjectName(QString::fromUtf8("box_select_extrema_tool_widget"));
        box_select_extrema_tool_widget->setGeometry(QRect(485, 5, 100, 61));
        box_select_extrema_tool_widget->setStyleSheet(QString::fromUtf8("#box_select_extrema_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        box_select_extrema_tool = new QToolButton(box_select_extrema_tool_widget);
        box_select_extrema_tool->setObjectName(QString::fromUtf8("box_select_extrema_tool"));
        box_select_extrema_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(box_select_extrema_tool->sizePolicy().hasHeightForWidth());
        box_select_extrema_tool->setSizePolicy(sizePolicy2);
        box_select_extrema_tool->setFont(font2);
        box_select_extrema_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/img/btn/box-select extrema_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        box_select_extrema_tool->setIcon(icon15);
        box_select_extrema_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        box_select_extrema_tool->setAutoRaise(true);
        mouse_arrow_tool_widget = new QWidget(analyse_btn_page);
        mouse_arrow_tool_widget->setObjectName(QString::fromUtf8("mouse_arrow_tool_widget"));
        mouse_arrow_tool_widget->setGeometry(QRect(50, 5, 100, 61));
        mouse_arrow_tool_widget->setStyleSheet(QString::fromUtf8("#mouse_arrow_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        mouse_arrow_tool = new QToolButton(mouse_arrow_tool_widget);
        mouse_arrow_tool->setObjectName(QString::fromUtf8("mouse_arrow_tool"));
        mouse_arrow_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(mouse_arrow_tool->sizePolicy().hasHeightForWidth());
        mouse_arrow_tool->setSizePolicy(sizePolicy2);
        mouse_arrow_tool->setFont(font2);
        mouse_arrow_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/img/btn/mouse_arrow_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        mouse_arrow_tool->setIcon(icon16);
        mouse_arrow_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mouse_arrow_tool->setAutoRaise(true);
        recovery_tool_widget = new QWidget(analyse_btn_page);
        recovery_tool_widget->setObjectName(QString::fromUtf8("recovery_tool_widget"));
        recovery_tool_widget->setGeometry(QRect(340, 5, 100, 61));
        recovery_tool_widget->setStyleSheet(QString::fromUtf8("#recovery_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        recovery_tool = new QToolButton(recovery_tool_widget);
        recovery_tool->setObjectName(QString::fromUtf8("recovery_tool"));
        recovery_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(recovery_tool->sizePolicy().hasHeightForWidth());
        recovery_tool->setSizePolicy(sizePolicy2);
        recovery_tool->setFont(font2);
        recovery_tool->setStyleSheet(QString::fromUtf8(""));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/btn/recovery_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        recovery_tool->setIcon(icon17);
        recovery_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        recovery_tool->setAutoRaise(true);
        submenu->addWidget(analyse_btn_page);
        file_btn_page = new QWidget();
        file_btn_page->setObjectName(QString::fromUtf8("file_btn_page"));
        print_tool_widget = new QWidget(file_btn_page);
        print_tool_widget->setObjectName(QString::fromUtf8("print_tool_widget"));
        print_tool_widget->setGeometry(QRect(480, 5, 100, 61));
        print_tool_widget->setStyleSheet(QString::fromUtf8("#box_select_extrema_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        print_tool = new QToolButton(print_tool_widget);
        print_tool->setObjectName(QString::fromUtf8("print_tool"));
        print_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(print_tool->sizePolicy().hasHeightForWidth());
        print_tool->setSizePolicy(sizePolicy2);
        print_tool->setStyleSheet(QString::fromUtf8("#motor_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/btn/print_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        print_tool->setIcon(icon18);
        print_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        print_tool->setAutoRaise(true);
        open_file_tool_widget = new QWidget(file_btn_page);
        open_file_tool_widget->setObjectName(QString::fromUtf8("open_file_tool_widget"));
        open_file_tool_widget->setGeometry(QRect(45, 5, 100, 61));
        open_file_tool_widget->setStyleSheet(QString::fromUtf8("#open_file_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        open_file_tool = new QToolButton(open_file_tool_widget);
        open_file_tool->setObjectName(QString::fromUtf8("open_file_tool"));
        open_file_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(open_file_tool->sizePolicy().hasHeightForWidth());
        open_file_tool->setSizePolicy(sizePolicy2);
        open_file_tool->setStyleSheet(QString::fromUtf8("#motor_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/img/btn/open_file_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_file_tool->setIcon(icon19);
        open_file_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        open_file_tool->setAutoRaise(true);
        save_data_tool_widget = new QWidget(file_btn_page);
        save_data_tool_widget->setObjectName(QString::fromUtf8("save_data_tool_widget"));
        save_data_tool_widget->setGeometry(QRect(335, 5, 100, 61));
        save_data_tool_widget->setStyleSheet(QString::fromUtf8("#recovery_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        save_data_tool = new QToolButton(save_data_tool_widget);
        save_data_tool->setObjectName(QString::fromUtf8("save_data_tool"));
        save_data_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(save_data_tool->sizePolicy().hasHeightForWidth());
        save_data_tool->setSizePolicy(sizePolicy2);
        save_data_tool->setStyleSheet(QString::fromUtf8("#motor_tool_widget{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/img/btn/save_data_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_data_tool->setIcon(icon20);
        save_data_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        save_data_tool->setAutoRaise(true);
        export_table_tool_widget = new QWidget(file_btn_page);
        export_table_tool_widget->setObjectName(QString::fromUtf8("export_table_tool_widget"));
        export_table_tool_widget->setGeometry(QRect(190, 5, 100, 61));
        export_table_tool_widget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
""));
        export_table_tool = new QToolButton(export_table_tool_widget);
        export_table_tool->setObjectName(QString::fromUtf8("export_table_tool"));
        export_table_tool->setGeometry(QRect(0, 0, 100, 61));
        sizePolicy2.setHeightForWidth(export_table_tool->sizePolicy().hasHeightForWidth());
        export_table_tool->setSizePolicy(sizePolicy2);
        export_table_tool->setStyleSheet(QString::fromUtf8("#focus_distance_tool{\n"
"background-color: rgba(0, 0, 255, 40);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/tool_click2.png);\n"
"}\n"
""));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/img/btn/export_table_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        export_table_tool->setIcon(icon21);
        export_table_tool->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        export_table_tool->setAutoRaise(true);
        submenu->addWidget(file_btn_page);
        sw = new QStackedWidget(centralwidget);
        sw->setObjectName(QString::fromUtf8("sw"));
        sw->setGeometry(QRect(0, 189, 1920, 891));
        sw->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"#sw{\n"
"background-color: rgb(245,245,245);\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"}\n"
"\n"
""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("#page{\n"
"background-color: rgb(245,245,245);\n"
"\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"}"));
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(45, 20, 910, 371));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-color:white;\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"}\n"
"\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 910, 40));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{\n"
"border-bottom:1px solid rgb(49, 175, 217);\n"
"border-top:1px solid rgb(49, 175, 217);\n"
"border-right:1px solid rgb(49, 175, 217);\n"
"background:transparent;\n"
"border-top-left-radius:25px;\n"
"border-top-right-radius:25px;\n"
"background-color:white;\n"
"}\n"
""));
        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(0, 0, 220, 50));
        widget_9->setStyleSheet(QString::fromUtf8("#widget_9{\n"
"border-top-left-radius:25px;\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:rgb(49, 175, 217);\n"
"}"));
        label = new QLabel(widget_9);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 130, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);"));
        plot2 = new QWidget(widget);
        plot2->setObjectName(QString::fromUtf8("plot2"));
        plot2->setGeometry(QRect(0, 40, 910, 320));
        plot2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"border-bottom-left-radius:25px;\n"
"border-bottom-right-radius:25px;"));
        widget_time = new MyPlot(plot2);
        widget_time->setObjectName(QString::fromUtf8("widget_time"));
        widget_time->setGeometry(QRect(40, 0, 871, 271));
        widget_time->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"border-bottom-left-radius:25px;\n"
"border-bottom-right-radius:25px;"));
        lab_time_x = new QLabel(plot2);
        lab_time_x->setObjectName(QString::fromUtf8("lab_time_x"));
        lab_time_x->setGeometry(QRect(430, 280, 101, 30));
        lab_time_x->setFont(font3);
        lab_time_x->setStyleSheet(QString::fromUtf8("color:rgb(37,72,132);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: none;\n"
"\n"
""));
        lab_time_x->setAlignment(Qt::AlignCenter);
        lab_time_y = new QLabel(plot2);
        lab_time_y->setObjectName(QString::fromUtf8("lab_time_y"));
        lab_time_y->setGeometry(QRect(-20, 120, 81, 30));
        lab_time_y->setFont(font3);
        lab_time_y->setStyleSheet(QString::fromUtf8("color:rgb(37,72,132);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: none;\n"
""));
        lab_time_y->setAlignment(Qt::AlignCenter);
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(45, 410, 910, 480));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 10, 910, 41));
        widget_10 = new QWidget(widget_4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setGeometry(QRect(0, 0, 910, 40));
        widget_10->setStyleSheet(QString::fromUtf8("#widget_10{\n"
"border-top-left-radius:25px;\n"
"border-top-right-radius:25px;\n"
"background:transparent;\n"
"border-bottom:1px solid rgb(49, 175, 217);\n"
"border-top:1px solid rgb(49, 175, 217);\n"
"border-right:1px solid rgb(49, 175, 217);\n"
"background-color:white;\n"
"}"));
        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(0, 0, 220, 50));
        widget_11->setStyleSheet(QString::fromUtf8("#widget_11{\n"
"border-top-left-radius:25px;\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:rgb(49, 175, 217);\n"
"}"));
        label_2 = new QLabel(widget_11);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 130, 21));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);"));
        plot = new QWidget(widget_3);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(0, 150, 910, 320));
        plot->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"border-bottom-left-radius:25px;\n"
"border-bottom-right-radius:25px;"));
        widget_frquency = new MyPlot(plot);
        widget_frquency->setObjectName(QString::fromUtf8("widget_frquency"));
        widget_frquency->setGeometry(QRect(50, 0, 861, 281));
        widget_frquency->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"border-bottom-left-radius:25px;\n"
"border-bottom-right-radius:25px;"));
        lab_fr_x = new QLabel(plot);
        lab_fr_x->setObjectName(QString::fromUtf8("lab_fr_x"));
        lab_fr_x->setGeometry(QRect(400, 280, 101, 30));
        lab_fr_x->setFont(font3);
        lab_fr_x->setStyleSheet(QString::fromUtf8("color:rgb(37,72,132);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: none;\n"
"\n"
""));
        lab_fr_x->setAlignment(Qt::AlignCenter);
        lab_fr_y = new QLabel(plot);
        lab_fr_y->setObjectName(QString::fromUtf8("lab_fr_y"));
        lab_fr_y->setGeometry(QRect(-30, 120, 101, 30));
        lab_fr_y->setFont(font3);
        lab_fr_y->setStyleSheet(QString::fromUtf8("color:rgb(37,72,132);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: none;\n"
""));
        lab_fr_y->setAlignment(Qt::AlignCenter);
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 50, 910, 101));
        widget_5->setStyleSheet(QString::fromUtf8("\n"
"#widget_5{\n"
"\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"}\n"
"QLabel{\n"
"	color:rgb(37,72,132);\n"
"\n"
"\n"
"}\n"
" \n"
" \n"
"QRadioButton{\n"
"/* \350\256\276\347\275\256\346\226\207\346\234\254\344\270\216\346\241\206\344\271\213\351\227\264\347\232\204\350\267\235\347\246\273*/\n"
"    spacing:15px;\n"
"  \n"
"	\n"
"color:rgb(37,72,132);\n"
"\n"
"    background: transparent;\n"
"}\n"
"QRadioButton::indicator{\n"
"width:25px;\n"
"height:25px;\n"
"}\n"
"/* \346\234\252\351\200\211\344\270\255\347\212\266\346\200\201*/\n"
"QRadioButton::indicator:unchecked \n"
"{\n"
"\n"
"border-image:url(:/img/btn/unselected.png);\n"
"}\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201*/\n"
"QRadioButton::indicator\n"
"{\n"
"\n"
"border-image:url(:/img/btn/checked.png);\n"
"}\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\344\270\213\347\232\204\347\202\271\345\207\273*/\n"
"QRadioButton::checked:pressed\n"
"{\n"
"\n"
"}\n"
"\n"
"/* \346\234"
                        "\252\351\200\211\344\270\255\347\212\266\346\200\201\344\270\213\347\232\204\347\202\271\345\207\273*/\n"
"QRadioButton::indicator:unchecked:pressed\n"
"{\n"
"border-image:url(:/img/btn/checked.png);\n"
"}\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\347\232\204\351\200\211\346\213\251\346\241\206*/\n"
"QCheckBox::indicator:checked\n"
"{\n"
"border-image:url(:/img/btn/checked.png);\n"
"}\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\344\270\213\347\232\204\351\274\240\346\240\207\346\202\254\345\201\234*/\n"
"QCheckBox::indicator:checked :hover\n"
"{\n"
"\n"
"}\n"
"/* \351\200\211\344\270\255\347\212\266\346\200\201\344\270\213\347\232\204\347\202\271\345\207\273*/\n"
"QRadioButton::indicator:checked:pressed\n"
"{\n"
"border-image:url(:/img/btn/unselected.png);\n"
"}"));
        rad_spectrum = new QRadioButton(widget_5);
        rad_spectrum->setObjectName(QString::fromUtf8("rad_spectrum"));
        rad_spectrum->setGeometry(QRect(30, 10, 120, 30));
        rad_spectrum->setFont(font4);
        rad_power = new QRadioButton(widget_5);
        rad_power->setObjectName(QString::fromUtf8("rad_power"));
        rad_power->setGeometry(QRect(30, 50, 121, 30));
        rad_power->setFont(font4);
        lineEdit_RMS = new QLineEdit(widget_5);
        lineEdit_RMS->setObjectName(QString::fromUtf8("lineEdit_RMS"));
        lineEdit_RMS->setGeometry(QRect(240, 50, 120, 30));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(199, 50, 51, 30));
        label_3->setFont(font3);
        lineEdit_MAX = new QLineEdit(widget_5);
        lineEdit_MAX->setObjectName(QString::fromUtf8("lineEdit_MAX"));
        lineEdit_MAX->setGeometry(QRect(500, 50, 120, 30));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 50, 91, 30));
        label_4->setFont(font3);
        widget_6 = new QWidget(page);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(990, 20, 901, 861));
        widget_6->setStyleSheet(QString::fromUtf8("#widget_6{\n"
"border-radius:25px;\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:white;\n"
"}"));
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(40, 700, 825, 141));
        widget_7->setStyleSheet(QString::fromUtf8("background-color:rgb(238,238,238);\n"
"border-radius:5px;"));
        txtRec = new QPlainTextEdit(widget_7);
        txtRec->setObjectName(QString::fromUtf8("txtRec"));
        txtRec->setGeometry(QRect(23, 20, 791, 101));
        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(0, 40, 891, 691));
        widget_8->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(widget_8);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(40, 24, 833, 607));
        tableView->setStyleSheet(QString::fromUtf8("\n"
"QHeaderView::section{\n"
"text-align:center;\n"
"background-color: rgb(255, 255, 255);\n"
"padding:3px;\n"
"\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QTableView{\n"
"		color: rgb(125, 128, 130);\n"
"	background-color: rgb(255, 255, 255);\n"
"	alternate-background-color:  rgb(255, 255, 255);;\n"
"}\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        widget_12 = new QWidget(widget_6);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(0, 0, 901, 40));
        widget_12->setStyleSheet(QString::fromUtf8("#widget_12{\n"
"border-bottom:1px solid rgb(49, 175, 217);\n"
"border-top:1px solid rgb(49, 175, 217);\n"
"border-right:1px solid rgb(49, 175, 217);\n"
"background:transparent;\n"
"border-top-left-radius:25px;\n"
"border-top-right-radius:25px;\n"
"background-color:white;\n"
"}\n"
""));
        widget_13 = new QWidget(widget_12);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setGeometry(QRect(0, 0, 220, 41));
        widget_13->setStyleSheet(QString::fromUtf8("#widget_13{\n"
"border-top-left-radius:25px;\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"background-color:rgb(49, 175, 217);\n"
"}"));
        label_5 = new QLabel(widget_13);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 10, 81, 21));
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);"));
        sw->addWidget(page);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        page2->setStyleSheet(QString::fromUtf8("\n"
"#centralwidget{\n"
"\n"
"background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-image: url(:/img/btn/bg.png);\n"
"}"));
        sw->addWidget(page2);
        MainWindow->setCentralWidget(centralwidget);
        tool_btn_widget->raise();
        title_widget->raise();
        tool_widget->raise();
        submenu->raise();
        sw->raise();

        retranslateUi(MainWindow);

        sw->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        home_minimize->setText(QString());
        home_maximize->setText(QString());
        home_close->setText(QString());
        home_title->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\202\271\346\265\213\346\214\257\344\273\252\350\275\257\344\273\266", nullptr));
        home_title_2->setText(QString());
        equipment_btn->setText(QCoreApplication::translate("MainWindow", "  \350\256\276   \345\244\207", nullptr));
        config_btn->setText(QCoreApplication::translate("MainWindow", "  \350\256\276   \347\275\256", nullptr));
        focus_btn->setText(QCoreApplication::translate("MainWindow", "  \345\257\271   \347\204\246", nullptr));
        measure_btn->setText(QCoreApplication::translate("MainWindow", "  \346\265\213   \351\207\217", nullptr));
        analyse_btn->setText(QCoreApplication::translate("MainWindow", "  \345\210\206   \346\236\220", nullptr));
        file_btn->setText(QCoreApplication::translate("MainWindow", "  \346\226\207   \344\273\266", nullptr));
        motor_tool->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272", nullptr));
        capture_card_tool->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\345\215\241", nullptr));
        filter_toolButton->setText(QCoreApplication::translate("MainWindow", "\346\273\244\346\263\242\345\231\250", nullptr));
        config_tool->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        auto_focus_tool->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\257\271\347\204\246", nullptr));
        focus_distance_tool->setText(QCoreApplication::translate("MainWindow", "\350\277\234\345\244\204\345\257\271\347\204\246", nullptr));
        close_focus_tool->setText(QCoreApplication::translate("MainWindow", "\350\277\221\345\244\204\345\257\271\347\204\246", nullptr));
        stop_focusing_tool->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\345\257\271\347\204\246", nullptr));
        continuous_measurement_tool->setText(QCoreApplication::translate("MainWindow", "\350\277\236\347\273\255\346\265\213\351\207\217", nullptr));
        single_measurement_tool->setText(QCoreApplication::translate("MainWindow", "\345\215\225\346\254\241\346\265\213\351\207\217", nullptr));
        stop_focusing_tool_2->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        zoom_tool->setText(QCoreApplication::translate("MainWindow", "\347\274\251\346\224\276", nullptr));
        box_select_extrema_tool->setText(QCoreApplication::translate("MainWindow", "\346\241\206\351\200\211\346\236\201\345\200\274", nullptr));
        mouse_arrow_tool->setText(QCoreApplication::translate("MainWindow", "\351\274\240\346\240\207\347\256\255\345\244\264", nullptr));
        recovery_tool->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\216\237", nullptr));
        print_tool->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
        open_file_tool->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        save_data_tool->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        export_table_tool->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\350\241\250\346\240\274", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\227\266\345\237\237\346\265\213\351\207\217\346\230\276\347\244\272", nullptr));
        lab_time_x->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        lab_time_y->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\242\221\345\237\237\346\265\213\351\207\217\346\230\276\347\244\272", nullptr));
        lab_fr_x->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        lab_fr_y->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        rad_spectrum->setText(QCoreApplication::translate("MainWindow", "\351\242\221\350\260\261", nullptr));
        rad_power->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\350\260\261", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "RMS", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\235\220\346\240\207\345\200\274", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\265\213\351\207\217\347\273\223\346\236\234\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
