/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[69];
    char stringdata0[1209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_home_close_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_home_minimize_clicked"
QT_MOC_LITERAL(4, 59, 24), // "on_equipment_btn_clicked"
QT_MOC_LITERAL(5, 84, 21), // "on_config_btn_clicked"
QT_MOC_LITERAL(6, 106, 20), // "on_focus_btn_clicked"
QT_MOC_LITERAL(7, 127, 22), // "on_measure_btn_clicked"
QT_MOC_LITERAL(8, 150, 19), // "on_file_btn_clicked"
QT_MOC_LITERAL(9, 170, 22), // "on_analyse_btn_clicked"
QT_MOC_LITERAL(10, 193, 21), // "on_motor_tool_clicked"
QT_MOC_LITERAL(11, 215, 28), // "on_capture_card_tool_clicked"
QT_MOC_LITERAL(12, 244, 22), // "on_config_tool_clicked"
QT_MOC_LITERAL(13, 267, 26), // "on_auto_focus_tool_clicked"
QT_MOC_LITERAL(14, 294, 30), // "on_focus_distance_tool_clicked"
QT_MOC_LITERAL(15, 325, 27), // "on_close_focus_tool_clicked"
QT_MOC_LITERAL(16, 353, 29), // "on_stop_focusing_tool_clicked"
QT_MOC_LITERAL(17, 383, 34), // "on_single_measurement_tool_cl..."
QT_MOC_LITERAL(18, 418, 38), // "on_continuous_measurement_too..."
QT_MOC_LITERAL(19, 457, 31), // "on_stop_focusing_tool_2_clicked"
QT_MOC_LITERAL(20, 489, 27), // "on_mouse_arrow_tool_clicked"
QT_MOC_LITERAL(21, 517, 20), // "on_zoom_tool_clicked"
QT_MOC_LITERAL(22, 538, 24), // "on_recovery_tool_clicked"
QT_MOC_LITERAL(23, 563, 34), // "on_box_select_extrema_tool_cl..."
QT_MOC_LITERAL(24, 598, 25), // "on_open_file_tool_clicked"
QT_MOC_LITERAL(25, 624, 28), // "on_export_table_tool_clicked"
QT_MOC_LITERAL(26, 653, 25), // "on_save_data_tool_clicked"
QT_MOC_LITERAL(27, 679, 21), // "on_print_tool_clicked"
QT_MOC_LITERAL(28, 701, 24), // "on_home_maximize_clicked"
QT_MOC_LITERAL(29, 726, 7), // "checked"
QT_MOC_LITERAL(30, 734, 19), // "Initialize_function"
QT_MOC_LITERAL(31, 754, 13), // "on_connection"
QT_MOC_LITERAL(32, 768, 12), // "timeToRePlot"
QT_MOC_LITERAL(33, 781, 10), // "stop_timer"
QT_MOC_LITERAL(34, 792, 15), // "receive_setting"
QT_MOC_LITERAL(35, 808, 6), // "if_set"
QT_MOC_LITERAL(36, 815, 13), // "if_clear_data"
QT_MOC_LITERAL(37, 829, 8), // "if_clear"
QT_MOC_LITERAL(38, 838, 9), // "show_Time"
QT_MOC_LITERAL(39, 848, 7), // "double*"
QT_MOC_LITERAL(40, 856, 9), // "time_date"
QT_MOC_LITERAL(41, 866, 3), // "len"
QT_MOC_LITERAL(42, 870, 11), // "measure_num"
QT_MOC_LITERAL(43, 882, 8), // "show_FFT"
QT_MOC_LITERAL(44, 891, 8), // "FFT_date"
QT_MOC_LITERAL(45, 900, 7), // "fft_len"
QT_MOC_LITERAL(46, 908, 14), // "show_save_Time"
QT_MOC_LITERAL(47, 923, 8), // "showdate"
QT_MOC_LITERAL(48, 932, 2), // "fs"
QT_MOC_LITERAL(49, 935, 13), // "show_save_FFT"
QT_MOC_LITERAL(50, 949, 12), // "Get_fftPoint"
QT_MOC_LITERAL(51, 962, 13), // "Get_timePoint"
QT_MOC_LITERAL(52, 976, 13), // "keyPressEvent"
QT_MOC_LITERAL(53, 990, 10), // "QKeyEvent*"
QT_MOC_LITERAL(54, 1001, 1), // "e"
QT_MOC_LITERAL(55, 1003, 12), // "on_time_wait"
QT_MOC_LITERAL(56, 1016, 9), // "wait_time"
QT_MOC_LITERAL(57, 1026, 14), // "save_data_over"
QT_MOC_LITERAL(58, 1041, 14), // "receive_neicun"
QT_MOC_LITERAL(59, 1056, 14), // "show_RMS_value"
QT_MOC_LITERAL(60, 1071, 19), // "serialPortRead_Slot"
QT_MOC_LITERAL(61, 1091, 16), // "sent_instruction"
QT_MOC_LITERAL(62, 1108, 16), // "stop_return_best"
QT_MOC_LITERAL(63, 1125, 10), // "Delay_MSec"
QT_MOC_LITERAL(64, 1136, 4), // "msec"
QT_MOC_LITERAL(65, 1141, 10), // "on_far_one"
QT_MOC_LITERAL(66, 1152, 11), // "on_near_one"
QT_MOC_LITERAL(67, 1164, 23), // "on_rad_spectrum_toggled"
QT_MOC_LITERAL(68, 1188, 20) // "on_rad_power_toggled"

    },
    "MainWindow\0on_home_close_clicked\0\0"
    "on_home_minimize_clicked\0"
    "on_equipment_btn_clicked\0on_config_btn_clicked\0"
    "on_focus_btn_clicked\0on_measure_btn_clicked\0"
    "on_file_btn_clicked\0on_analyse_btn_clicked\0"
    "on_motor_tool_clicked\0"
    "on_capture_card_tool_clicked\0"
    "on_config_tool_clicked\0"
    "on_auto_focus_tool_clicked\0"
    "on_focus_distance_tool_clicked\0"
    "on_close_focus_tool_clicked\0"
    "on_stop_focusing_tool_clicked\0"
    "on_single_measurement_tool_clicked\0"
    "on_continuous_measurement_tool_clicked\0"
    "on_stop_focusing_tool_2_clicked\0"
    "on_mouse_arrow_tool_clicked\0"
    "on_zoom_tool_clicked\0on_recovery_tool_clicked\0"
    "on_box_select_extrema_tool_clicked\0"
    "on_open_file_tool_clicked\0"
    "on_export_table_tool_clicked\0"
    "on_save_data_tool_clicked\0"
    "on_print_tool_clicked\0on_home_maximize_clicked\0"
    "checked\0Initialize_function\0on_connection\0"
    "timeToRePlot\0stop_timer\0receive_setting\0"
    "if_set\0if_clear_data\0if_clear\0show_Time\0"
    "double*\0time_date\0len\0measure_num\0"
    "show_FFT\0FFT_date\0fft_len\0show_save_Time\0"
    "showdate\0fs\0show_save_FFT\0Get_fftPoint\0"
    "Get_timePoint\0keyPressEvent\0QKeyEvent*\0"
    "e\0on_time_wait\0wait_time\0save_data_over\0"
    "receive_neicun\0show_RMS_value\0"
    "serialPortRead_Slot\0sent_instruction\0"
    "stop_return_best\0Delay_MSec\0msec\0"
    "on_far_one\0on_near_one\0on_rad_spectrum_toggled\0"
    "on_rad_power_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  274,    2, 0x08 /* Private */,
       3,    0,  275,    2, 0x08 /* Private */,
       4,    0,  276,    2, 0x08 /* Private */,
       5,    0,  277,    2, 0x08 /* Private */,
       6,    0,  278,    2, 0x08 /* Private */,
       7,    0,  279,    2, 0x08 /* Private */,
       8,    0,  280,    2, 0x08 /* Private */,
       9,    0,  281,    2, 0x08 /* Private */,
      10,    0,  282,    2, 0x08 /* Private */,
      11,    0,  283,    2, 0x08 /* Private */,
      12,    0,  284,    2, 0x08 /* Private */,
      13,    0,  285,    2, 0x08 /* Private */,
      14,    0,  286,    2, 0x08 /* Private */,
      15,    0,  287,    2, 0x08 /* Private */,
      16,    0,  288,    2, 0x08 /* Private */,
      17,    0,  289,    2, 0x08 /* Private */,
      18,    0,  290,    2, 0x08 /* Private */,
      19,    0,  291,    2, 0x08 /* Private */,
      20,    0,  292,    2, 0x08 /* Private */,
      21,    0,  293,    2, 0x08 /* Private */,
      22,    0,  294,    2, 0x08 /* Private */,
      23,    0,  295,    2, 0x08 /* Private */,
      24,    0,  296,    2, 0x08 /* Private */,
      25,    0,  297,    2, 0x08 /* Private */,
      26,    0,  298,    2, 0x08 /* Private */,
      27,    0,  299,    2, 0x08 /* Private */,
      28,    1,  300,    2, 0x08 /* Private */,
      30,    0,  303,    2, 0x08 /* Private */,
      31,    0,  304,    2, 0x08 /* Private */,
      32,    0,  305,    2, 0x08 /* Private */,
      33,    0,  306,    2, 0x08 /* Private */,
      34,    1,  307,    2, 0x08 /* Private */,
      36,    1,  310,    2, 0x08 /* Private */,
      38,    3,  313,    2, 0x08 /* Private */,
      43,    2,  320,    2, 0x08 /* Private */,
      46,    3,  325,    2, 0x08 /* Private */,
      49,    4,  332,    2, 0x08 /* Private */,
      50,    2,  341,    2, 0x08 /* Private */,
      51,    2,  346,    2, 0x08 /* Private */,
      52,    1,  351,    2, 0x08 /* Private */,
      55,    1,  354,    2, 0x08 /* Private */,
      57,    1,  357,    2, 0x08 /* Private */,
      58,    1,  360,    2, 0x08 /* Private */,
      59,    1,  363,    2, 0x08 /* Private */,
      60,    0,  366,    2, 0x08 /* Private */,
      61,    0,  367,    2, 0x08 /* Private */,
      62,    0,  368,    2, 0x08 /* Private */,
      63,    1,  369,    2, 0x08 /* Private */,
      65,    0,  372,    2, 0x08 /* Private */,
      66,    0,  373,    2, 0x08 /* Private */,
      67,    1,  374,    2, 0x08 /* Private */,
      68,    1,  377,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, 0x80000000 | 39, QMetaType::Int, QMetaType::Int,   40,   41,   42,
    QMetaType::Void, 0x80000000 | 39, QMetaType::Int,   44,   45,
    QMetaType::Void, 0x80000000 | 39, QMetaType::Int, QMetaType::Int,   47,   41,   48,
    QMetaType::Void, 0x80000000 | 39, QMetaType::Int, QMetaType::Int, QMetaType::Int,   44,   45,   48,   42,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,    2,    2,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,    2,    2,
    QMetaType::Void, 0x80000000 | 53,   54,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_close_clicked(); break;
        case 1: _t->on_home_minimize_clicked(); break;
        case 2: _t->on_equipment_btn_clicked(); break;
        case 3: _t->on_config_btn_clicked(); break;
        case 4: _t->on_focus_btn_clicked(); break;
        case 5: _t->on_measure_btn_clicked(); break;
        case 6: _t->on_file_btn_clicked(); break;
        case 7: _t->on_analyse_btn_clicked(); break;
        case 8: _t->on_motor_tool_clicked(); break;
        case 9: _t->on_capture_card_tool_clicked(); break;
        case 10: _t->on_config_tool_clicked(); break;
        case 11: _t->on_auto_focus_tool_clicked(); break;
        case 12: _t->on_focus_distance_tool_clicked(); break;
        case 13: _t->on_close_focus_tool_clicked(); break;
        case 14: _t->on_stop_focusing_tool_clicked(); break;
        case 15: _t->on_single_measurement_tool_clicked(); break;
        case 16: _t->on_continuous_measurement_tool_clicked(); break;
        case 17: _t->on_stop_focusing_tool_2_clicked(); break;
        case 18: _t->on_mouse_arrow_tool_clicked(); break;
        case 19: _t->on_zoom_tool_clicked(); break;
        case 20: _t->on_recovery_tool_clicked(); break;
        case 21: _t->on_box_select_extrema_tool_clicked(); break;
        case 22: _t->on_open_file_tool_clicked(); break;
        case 23: _t->on_export_table_tool_clicked(); break;
        case 24: _t->on_save_data_tool_clicked(); break;
        case 25: _t->on_print_tool_clicked(); break;
        case 26: _t->on_home_maximize_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->Initialize_function(); break;
        case 28: _t->on_connection(); break;
        case 29: _t->timeToRePlot(); break;
        case 30: _t->stop_timer(); break;
        case 31: _t->receive_setting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->if_clear_data((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->show_Time((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 34: _t->show_FFT((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->show_save_Time((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 36: _t->show_save_FFT((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 37: _t->Get_fftPoint((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 38: _t->Get_timePoint((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 39: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 40: _t->on_time_wait((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->save_data_over((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->receive_neicun((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->show_RMS_value((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->serialPortRead_Slot(); break;
        case 45: _t->sent_instruction(); break;
        case 46: _t->stop_return_best(); break;
        case 47: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 48: _t->on_far_one(); break;
        case 49: _t->on_near_one(); break;
        case 50: _t->on_rad_spectrum_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_rad_power_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 52;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
