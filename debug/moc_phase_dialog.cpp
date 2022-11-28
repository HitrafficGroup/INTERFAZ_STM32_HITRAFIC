/****************************************************************************
** Meta object code from reading C++ file 'phase_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../phase_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phase_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_phase_dialog_t {
    QByteArrayData data[13];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_phase_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_phase_dialog_t qt_meta_stringdata_phase_dialog = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 13),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 5),
QT_MOC_LITERAL(4, 34, 14),
QT_MOC_LITERAL(5, 49, 13),
QT_MOC_LITERAL(6, 63, 13),
QT_MOC_LITERAL(7, 77, 5),
QT_MOC_LITERAL(8, 83, 17),
QT_MOC_LITERAL(9, 101, 11),
QT_MOC_LITERAL(10, 113, 29),
QT_MOC_LITERAL(11, 143, 28),
QT_MOC_LITERAL(12, 172, 38)
    },
    "phase_dialog\0PhaseDataSend\0\0Phase\0"
    "ChooseDataSend\0ChooseDataGet\0PhaseDataInit\0"
    "phase\0ChooseDataReceive\0choose_data\0"
    "on_pushButton_confirm_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_phaseConcurrency_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_phase_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   61,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void phase_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        phase_dialog *_t = static_cast<phase_dialog *>(_o);
        switch (_id) {
        case 0: _t->PhaseDataSend((*reinterpret_cast< Phase(*)>(_a[1]))); break;
        case 1: _t->ChooseDataSend((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->ChooseDataGet(); break;
        case 3: _t->PhaseDataInit((*reinterpret_cast< Phase(*)>(_a[1]))); break;
        case 4: _t->ChooseDataReceive((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_confirm_clicked(); break;
        case 6: _t->on_pushButton_cancel_clicked(); break;
        case 7: _t->on_pushButton_phaseConcurrency_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (phase_dialog::*_t)(Phase );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&phase_dialog::PhaseDataSend)) {
                *result = 0;
            }
        }
        {
            typedef void (phase_dialog::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&phase_dialog::ChooseDataSend)) {
                *result = 1;
            }
        }
        {
            typedef void (phase_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&phase_dialog::ChooseDataGet)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject phase_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_phase_dialog.data,
      qt_meta_data_phase_dialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *phase_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *phase_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_phase_dialog.stringdata))
        return static_cast<void*>(const_cast< phase_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int phase_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void phase_dialog::PhaseDataSend(Phase _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void phase_dialog::ChooseDataSend(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void phase_dialog::ChooseDataGet()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
