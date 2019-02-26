/****************************************************************************
** Meta object code from reading C++ file 'register.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kaoqing/register.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Register_t {
    QByteArrayData data[14];
    char stringdata[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Register_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Register_t qt_meta_stringdata_Register = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Register"
QT_MOC_LITERAL(1, 9, 12), // "zhuce_cancel"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "dealRegister_fail"
QT_MOC_LITERAL(4, 41, 19), // "on_pb_zhuce_clicked"
QT_MOC_LITERAL(5, 61, 20), // "on_pb_quxiao_clicked"
QT_MOC_LITERAL(6, 82, 16), // "deal_register_ok"
QT_MOC_LITERAL(7, 99, 32), // "on_company_email_editingFinished"
QT_MOC_LITERAL(8, 132, 39), // "on_company_queren_email_editi..."
QT_MOC_LITERAL(9, 172, 35), // "on_company_xingming_editingFi..."
QT_MOC_LITERAL(10, 208, 23), // "on_pb_isVersion_clicked"
QT_MOC_LITERAL(11, 232, 30), // "on_company_pwd_editingFinished"
QT_MOC_LITERAL(12, 263, 37), // "on_company_queren_pwd_editing..."
QT_MOC_LITERAL(13, 301, 30) // "on_pb_isVersion_queren_clicked"

    },
    "Register\0zhuce_cancel\0\0dealRegister_fail\0"
    "on_pb_zhuce_clicked\0on_pb_quxiao_clicked\0"
    "deal_register_ok\0on_company_email_editingFinished\0"
    "on_company_queren_email_editingFinished\0"
    "on_company_xingming_editingFinished\0"
    "on_pb_isVersion_clicked\0"
    "on_company_pwd_editingFinished\0"
    "on_company_queren_pwd_editingFinished\0"
    "on_pb_isVersion_queren_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Register[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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

       0        // eod
};

void Register::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Register *_t = static_cast<Register *>(_o);
        switch (_id) {
        case 0: _t->zhuce_cancel(); break;
        case 1: _t->dealRegister_fail(); break;
        case 2: _t->on_pb_zhuce_clicked(); break;
        case 3: _t->on_pb_quxiao_clicked(); break;
        case 4: _t->deal_register_ok(); break;
        case 5: _t->on_company_email_editingFinished(); break;
        case 6: _t->on_company_queren_email_editingFinished(); break;
        case 7: _t->on_company_xingming_editingFinished(); break;
        case 8: _t->on_pb_isVersion_clicked(); break;
        case 9: _t->on_company_pwd_editingFinished(); break;
        case 10: _t->on_company_queren_pwd_editingFinished(); break;
        case 11: _t->on_pb_isVersion_queren_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Register::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Register::zhuce_cancel)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Register::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Register.data,
      qt_meta_data_Register,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Register::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Register::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Register.stringdata))
        return static_cast<void*>(const_cast< Register*>(this));
    return QWidget::qt_metacast(_clname);
}

int Register::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Register::zhuce_cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
