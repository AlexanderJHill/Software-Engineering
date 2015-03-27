/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Documents/Software-Engineering/CrowdAnalysys/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_fishers_valueChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "value"
QT_MOC_LITERAL(4, 42, 25), // "on_locations_valueChanged"
QT_MOC_LITERAL(5, 68, 25), // "on_fishtypes_valueChanged"
QT_MOC_LITERAL(6, 94, 23), // "on_fishpop_valueChanged"
QT_MOC_LITERAL(7, 118, 23), // "on_runtime_valueChanged"
QT_MOC_LITERAL(8, 142, 24), // "on_lineEdit_0_textEdited"
QT_MOC_LITERAL(9, 167, 4), // "arg1"
QT_MOC_LITERAL(10, 172, 24), // "on_lineEdit_1_textEdited"
QT_MOC_LITERAL(11, 197, 24), // "on_lineEdit_2_textEdited"
QT_MOC_LITERAL(12, 222, 24), // "on_lineEdit_3_textEdited"
QT_MOC_LITERAL(13, 247, 24), // "on_lineEdit_4_textEdited"
QT_MOC_LITERAL(14, 272, 18), // "on_weather_clicked"
QT_MOC_LITERAL(15, 291, 23), // "on_reportButton_clicked"
QT_MOC_LITERAL(16, 315, 25) // "on_simulateButton_clicked"

    },
    "MainWindow\0on_fishers_valueChanged\0\0"
    "value\0on_locations_valueChanged\0"
    "on_fishtypes_valueChanged\0"
    "on_fishpop_valueChanged\0on_runtime_valueChanged\0"
    "on_lineEdit_0_textEdited\0arg1\0"
    "on_lineEdit_1_textEdited\0"
    "on_lineEdit_2_textEdited\0"
    "on_lineEdit_3_textEdited\0"
    "on_lineEdit_4_textEdited\0on_weather_clicked\0"
    "on_reportButton_clicked\0"
    "on_simulateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    1,   91,    2, 0x08 /* Private */,
       8,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_fishers_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_locations_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_fishtypes_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_fishpop_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_runtime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_0_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_1_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_4_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_weather_clicked(); break;
        case 11: _t->on_reportButton_clicked(); break;
        case 12: _t->on_simulateButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "UserSettings"))
        return static_cast< UserSettings*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
