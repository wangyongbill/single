/****************************************************************************
** Meta object code from reading C++ file 'get_measure_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../get_measure_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'get_measure_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_get_measure_thread_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_get_measure_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_get_measure_thread_t qt_meta_stringdata_get_measure_thread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "get_measure_thread"
QT_MOC_LITERAL(1, 19, 17), // "sent_capture_data"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "double*"
QT_MOC_LITERAL(4, 46, 4), // "Data"
QT_MOC_LITERAL(5, 51, 3), // "len"
QT_MOC_LITERAL(6, 55, 10), // "clear_data"
QT_MOC_LITERAL(7, 66, 11), // "sent_neicun"
QT_MOC_LITERAL(8, 78, 10) // "danci_over"

    },
    "get_measure_thread\0sent_capture_data\0"
    "\0double*\0Data\0len\0clear_data\0sent_neicun\0"
    "danci_over"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_get_measure_thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       6,    1,   41,    2, 0x06 /* Public */,
       7,    1,   44,    2, 0x06 /* Public */,
       8,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void get_measure_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<get_measure_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sent_capture_data((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->clear_data((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sent_neicun((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->danci_over(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (get_measure_thread::*)(double * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&get_measure_thread::sent_capture_data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (get_measure_thread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&get_measure_thread::clear_data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (get_measure_thread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&get_measure_thread::sent_neicun)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (get_measure_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&get_measure_thread::danci_over)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject get_measure_thread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_get_measure_thread.data,
    qt_meta_data_get_measure_thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *get_measure_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *get_measure_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_get_measure_thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int get_measure_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void get_measure_thread::sent_capture_data(double * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void get_measure_thread::clear_data(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void get_measure_thread::sent_neicun(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void get_measure_thread::danci_over()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
