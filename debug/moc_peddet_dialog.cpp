/****************************************************************************
** Meta object code from reading C++ file 'peddet_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../peddet_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'peddet_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_peddet_dialog_t {
    QByteArrayData data[8];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_peddet_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_peddet_dialog_t qt_meta_stringdata_peddet_dialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 6),
QT_MOC_LITERAL(4, 37, 14),
QT_MOC_LITERAL(5, 52, 6),
QT_MOC_LITERAL(6, 59, 29),
QT_MOC_LITERAL(7, 89, 28)
    },
    "peddet_dialog\0PeddetDataSend\0\0Peddet\0"
    "PeddetDataInit\0peddet\0"
    "on_pushButton_confirm_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_peddet_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void peddet_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        peddet_dialog *_t = static_cast<peddet_dialog *>(_o);
        switch (_id) {
        case 0: _t->PeddetDataSend((*reinterpret_cast< Peddet(*)>(_a[1]))); break;
        case 1: _t->PeddetDataInit((*reinterpret_cast< Peddet(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_confirm_clicked(); break;
        case 3: _t->on_pushButton_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (peddet_dialog::*_t)(Peddet );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&peddet_dialog::PeddetDataSend)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject peddet_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_peddet_dialog.data,
      qt_meta_data_peddet_dialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *peddet_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *peddet_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_peddet_dialog.stringdata))
        return static_cast<void*>(const_cast< peddet_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int peddet_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void peddet_dialog::PeddetDataSend(Peddet _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
