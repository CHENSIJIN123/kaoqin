/****************************************************************************
** Meta object code from reading C++ file 'forgetcompanyname.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kaoqing/forgetcompanyname.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'forgetcompanyname.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_forgetcompanyname_t {
    QByteArrayData data[8];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_forgetcompanyname_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_forgetcompanyname_t qt_meta_stringdata_forgetcompanyname = {
    {
QT_MOC_LITERAL(0, 0, 17), // "forgetcompanyname"
QT_MOC_LITERAL(1, 18, 12), // "close_forget"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "on_pb_ok_clicked"
QT_MOC_LITERAL(4, 49, 13), // "deal_com_name"
QT_MOC_LITERAL(5, 63, 1), // "s"
QT_MOC_LITERAL(6, 65, 20), // "on_pb_cancel_clicked"
QT_MOC_LITERAL(7, 86, 27) // "on_le_email_editingFinished"

    },
    "forgetcompanyname\0close_forget\0\0"
    "on_pb_ok_clicked\0deal_com_name\0s\0"
    "on_pb_cancel_clicked\0on_le_email_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_forgetcompanyname[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void forgetcompanyname::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        forgetcompanyname *_t = static_cast<forgetcompanyname *>(_o);
        switch (_id) {
        case 0: _t->close_forget(); break;
        case 1: _t->on_pb_ok_clicked(); break;
        case 2: _t->deal_com_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pb_cancel_clicked(); break;
        case 4: _t->on_le_email_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (forgetcompanyname::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&forgetcompanyname::close_forget)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject forgetcompanyname::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_forgetcompanyname.data,
      qt_meta_data_forgetcompanyname,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *forgetcompanyname::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *forgetcompanyname::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_forgetcompanyname.stringdata))
        return static_cast<void*>(const_cast< forgetcompanyname*>(this));
    return QWidget::qt_metacast(_clname);
}

int forgetcompanyname::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void forgetcompanyname::close_forget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
