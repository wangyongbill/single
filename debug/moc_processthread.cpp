/****************************************************************************
** Meta object code from reading C++ file 'processthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../processthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_processthread_t {
    QByteArrayData data[23];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_processthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_processthread_t qt_meta_stringdata_processthread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "processthread"
QT_MOC_LITERAL(1, 14, 14), // "sent_RMS_value"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "save_data_over"
QT_MOC_LITERAL(4, 45, 14), // "sent_save_data"
QT_MOC_LITERAL(5, 60, 13), // "QList<double>"
QT_MOC_LITERAL(6, 74, 14), // "sent_time_data"
QT_MOC_LITERAL(7, 89, 7), // "double*"
QT_MOC_LITERAL(8, 97, 4), // "Data"
QT_MOC_LITERAL(9, 102, 3), // "len"
QT_MOC_LITERAL(10, 106, 11), // "measure_num"
QT_MOC_LITERAL(11, 118, 13), // "sent_fft_data"
QT_MOC_LITERAL(12, 132, 12), // "receive_data"
QT_MOC_LITERAL(13, 145, 10), // "masterData"
QT_MOC_LITERAL(14, 156, 15), // "receive_setting"
QT_MOC_LITERAL(15, 172, 7), // "setting"
QT_MOC_LITERAL(16, 180, 2), // "fs"
QT_MOC_LITERAL(17, 183, 7), // "daikuan"
QT_MOC_LITERAL(18, 191, 6), // "puxian"
QT_MOC_LITERAL(19, 198, 6), // "lowflg"
QT_MOC_LITERAL(20, 205, 7), // "highflg"
QT_MOC_LITERAL(21, 213, 8), // "trackflg"
QT_MOC_LITERAL(22, 222, 19) // "default_measure_num"

    },
    "processthread\0sent_RMS_value\0\0"
    "save_data_over\0sent_save_data\0"
    "QList<double>\0sent_time_data\0double*\0"
    "Data\0len\0measure_num\0sent_fft_data\0"
    "receive_data\0masterData\0receive_setting\0"
    "setting\0fs\0daikuan\0puxian\0lowflg\0"
    "highflg\0trackflg\0default_measure_num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_processthread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,
       6,    3,   63,    2, 0x06 /* Public */,
      11,    2,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    3,   75,    2, 0x08 /* Private */,
      14,    1,   82,    2, 0x08 /* Private */,
      15,   10,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,   13,    9,   10,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    9,   16,   17,   18,   19,   20,   21,   22,    2,    2,

       0        // eod
};

void processthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<processthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sent_RMS_value((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->save_data_over((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sent_save_data((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 3: _t->sent_time_data((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->sent_fft_data((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->receive_data((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->receive_setting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (processthread::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&processthread::sent_RMS_value)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (processthread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&processthread::save_data_over)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (processthread::*)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&processthread::sent_save_data)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (processthread::*)(double * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&processthread::sent_time_data)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (processthread::*)(double * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&processthread::sent_fft_data)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject processthread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_processthread.data,
    qt_meta_data_processthread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *processthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *processthread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_processthread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int processthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void processthread::sent_RMS_value(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void processthread::save_data_over(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void processthread::sent_save_data(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void processthread::sent_time_data(double * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void processthread::sent_fft_data(double * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
