/****************************************************************************
** Meta object code from reading C++ file 'person.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kaoqing/person.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'person.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_person_t {
    QByteArrayData data[18];
    char stringdata[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_person_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_person_t qt_meta_stringdata_person = {
    {
QT_MOC_LITERAL(0, 0, 6), // "person"
QT_MOC_LITERAL(1, 7, 5), // "state"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 1), // "s"
QT_MOC_LITERAL(4, 16, 21), // "dealsetchangepsw_true"
QT_MOC_LITERAL(5, 38, 1), // "i"
QT_MOC_LITERAL(6, 40, 21), // "dealsucceed_changepwd"
QT_MOC_LITERAL(7, 62, 27), // "dealApplyBudakaWatchEmloyee"
QT_MOC_LITERAL(8, 90, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(9, 117, 5), // "index"
QT_MOC_LITERAL(10, 123, 26), // "on_pb_apply_budaka_clicked"
QT_MOC_LITERAL(11, 150, 28), // "on_pb_apply_vacation_clicked"
QT_MOC_LITERAL(12, 179, 26), // "on_pb_apply_jiaban_clicked"
QT_MOC_LITERAL(13, 206, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(14, 226, 29), // "on_currentpsw_editingFinished"
QT_MOC_LITERAL(15, 256, 28), // "on_querenpsw_editingFinished"
QT_MOC_LITERAL(16, 285, 20), // "on_pb_return_clicked"
QT_MOC_LITERAL(17, 306, 18) // "on_pb_save_clicked"

    },
    "person\0state\0\0s\0dealsetchangepsw_true\0"
    "i\0dealsucceed_changepwd\0"
    "dealApplyBudakaWatchEmloyee\0"
    "on_tabWidget_tabBarClicked\0index\0"
    "on_pb_apply_budaka_clicked\0"
    "on_pb_apply_vacation_clicked\0"
    "on_pb_apply_jiaban_clicked\0"
    "on_checkBox_clicked\0on_currentpsw_editingFinished\0"
    "on_querenpsw_editingFinished\0"
    "on_pb_return_clicked\0on_pb_save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_person[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   82,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    1,   89,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    9,
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

void person::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        person *_t = static_cast<person *>(_o);
        switch (_id) {
        case 0: _t->state((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dealsetchangepsw_true((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dealsucceed_changepwd(); break;
        case 3: _t->dealApplyBudakaWatchEmloyee((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pb_apply_budaka_clicked(); break;
        case 6: _t->on_pb_apply_vacation_clicked(); break;
        case 7: _t->on_pb_apply_jiaban_clicked(); break;
        case 8: _t->on_checkBox_clicked(); break;
        case 9: _t->on_currentpsw_editingFinished(); break;
        case 10: _t->on_querenpsw_editingFinished(); break;
        case 11: _t->on_pb_return_clicked(); break;
        case 12: _t->on_pb_save_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (person::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&person::state)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject person::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_person.data,
      qt_meta_data_person,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *person::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *person::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_person.stringdata))
        return static_cast<void*>(const_cast< person*>(this));
    return QWidget::qt_metacast(_clname);
}

int person::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void person::state(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
