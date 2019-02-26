/****************************************************************************
** Meta object code from reading C++ file 'increasemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kaoqing/increasemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'increasemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_increaseManager_t {
    QByteArrayData data[6];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_increaseManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_increaseManager_t qt_meta_stringdata_increaseManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "increaseManager"
QT_MOC_LITERAL(1, 16, 18), // "show_departmentMsg"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "tianjia_event"
QT_MOC_LITERAL(4, 50, 20), // "dealinsertDepartment"
QT_MOC_LITERAL(5, 71, 22) // "on_pb_increase_clicked"

    },
    "increaseManager\0show_departmentMsg\0\0"
    "tianjia_event\0dealinsertDepartment\0"
    "on_pb_increase_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_increaseManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void increaseManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        increaseManager *_t = static_cast<increaseManager *>(_o);
        switch (_id) {
        case 0: _t->show_departmentMsg(); break;
        case 1: _t->tianjia_event(); break;
        case 2: _t->dealinsertDepartment(); break;
        case 3: _t->on_pb_increase_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (increaseManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&increaseManager::show_departmentMsg)) {
                *result = 0;
            }
        }
        {
            typedef void (increaseManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&increaseManager::tianjia_event)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject increaseManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_increaseManager.data,
      qt_meta_data_increaseManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *increaseManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *increaseManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_increaseManager.stringdata))
        return static_cast<void*>(const_cast< increaseManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int increaseManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void increaseManager::show_departmentMsg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void increaseManager::tianjia_event()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
