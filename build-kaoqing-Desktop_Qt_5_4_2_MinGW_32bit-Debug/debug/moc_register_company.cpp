/****************************************************************************
** Meta object code from reading C++ file 'register_company.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kaoqing/register_company.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register_company.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_register_company_t {
    QByteArrayData data[9];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_register_company_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_register_company_t qt_meta_stringdata_register_company = {
    {
QT_MOC_LITERAL(0, 0, 16), // "register_company"
QT_MOC_LITERAL(1, 17, 17), // "dealfailure_login"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 31), // "on_register_new_company_clicked"
QT_MOC_LITERAL(4, 68, 25), // "on_register_login_clicked"
QT_MOC_LITERAL(5, 94, 7), // "dealmsg"
QT_MOC_LITERAL(6, 102, 18), // "deal_succeed_login"
QT_MOC_LITERAL(7, 121, 16), // "deal_pwd_correct"
QT_MOC_LITERAL(8, 138, 39) // "on_register_forget_company_na..."

    },
    "register_company\0dealfailure_login\0\0"
    "on_register_new_company_clicked\0"
    "on_register_login_clicked\0dealmsg\0"
    "deal_succeed_login\0deal_pwd_correct\0"
    "on_register_forget_company_name_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_register_company[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void register_company::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        register_company *_t = static_cast<register_company *>(_o);
        switch (_id) {
        case 0: _t->dealfailure_login(); break;
        case 1: _t->on_register_new_company_clicked(); break;
        case 2: _t->on_register_login_clicked(); break;
        case 3: _t->dealmsg(); break;
        case 4: _t->deal_succeed_login(); break;
        case 5: _t->deal_pwd_correct(); break;
        case 6: _t->on_register_forget_company_name_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject register_company::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_register_company.data,
      qt_meta_data_register_company,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *register_company::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *register_company::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_register_company.stringdata))
        return static_cast<void*>(const_cast< register_company*>(this));
    return QWidget::qt_metacast(_clname);
}

int register_company::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
