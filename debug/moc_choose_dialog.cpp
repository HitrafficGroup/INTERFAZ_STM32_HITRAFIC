/****************************************************************************
** Meta object code from reading C++ file 'choose_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../choose_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choose_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_choose_dialog_t {
    QByteArrayData data[12];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_choose_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_choose_dialog_t qt_meta_stringdata_choose_dialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 20),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 29),
QT_MOC_LITERAL(4, 66, 28),
QT_MOC_LITERAL(5, 95, 14),
QT_MOC_LITERAL(6, 110, 11),
QT_MOC_LITERAL(7, 122, 24),
QT_MOC_LITERAL(8, 147, 5),
QT_MOC_LITERAL(9, 153, 24),
QT_MOC_LITERAL(10, 178, 24),
QT_MOC_LITERAL(11, 203, 24)
    },
    "choose_dialog\0ChooseDataSendSignal\0\0"
    "on_pushButton_confirm_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "ChooseDataInit\0choose_data\0"
    "checkBoxCol1StateChanged\0state\0"
    "checkBoxCol2StateChanged\0"
    "checkBoxCol3StateChanged\0"
    "checkBoxCol4StateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_choose_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x0a /* Public */,
       4,    0,   58,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       9,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void choose_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        choose_dialog *_t = static_cast<choose_dialog *>(_o);
        switch (_id) {
        case 0: _t->ChooseDataSendSignal((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_confirm_clicked(); break;
        case 2: _t->on_pushButton_cancel_clicked(); break;
        case 3: _t->ChooseDataInit((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->checkBoxCol1StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->checkBoxCol2StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->checkBoxCol3StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->checkBoxCol4StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (choose_dialog::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&choose_dialog::ChooseDataSendSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject choose_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_choose_dialog.data,
      qt_meta_data_choose_dialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *choose_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *choose_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_choose_dialog.stringdata))
        return static_cast<void*>(const_cast< choose_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int choose_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void choose_dialog::ChooseDataSendSignal(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
