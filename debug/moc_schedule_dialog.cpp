/****************************************************************************
** Meta object code from reading C++ file 'schedule_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../schedule_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schedule_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_schedule_dialog_t {
    QByteArrayData data[14];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_schedule_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_schedule_dialog_t qt_meta_stringdata_schedule_dialog = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 16),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 8),
QT_MOC_LITERAL(4, 43, 14),
QT_MOC_LITERAL(5, 58, 12),
QT_MOC_LITERAL(6, 71, 14),
QT_MOC_LITERAL(7, 86, 14),
QT_MOC_LITERAL(8, 101, 14),
QT_MOC_LITERAL(9, 116, 14),
QT_MOC_LITERAL(10, 131, 16),
QT_MOC_LITERAL(11, 148, 8),
QT_MOC_LITERAL(12, 157, 29),
QT_MOC_LITERAL(13, 187, 28)
    },
    "schedule_dialog\0ScheduleDataSend\0\0"
    "Schedule\0monthSelectAll\0daySelectAll\0"
    "date1SelectAll\0date2SelectAll\0"
    "date3SelectAll\0date4SelectAll\0"
    "ScheduleDataInit\0schedule\0"
    "on_pushButton_confirm_clicked\0"
    "on_pushButton_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_schedule_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void schedule_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        schedule_dialog *_t = static_cast<schedule_dialog *>(_o);
        switch (_id) {
        case 0: _t->ScheduleDataSend((*reinterpret_cast< Schedule(*)>(_a[1]))); break;
        case 1: _t->monthSelectAll(); break;
        case 2: _t->daySelectAll(); break;
        case 3: _t->date1SelectAll(); break;
        case 4: _t->date2SelectAll(); break;
        case 5: _t->date3SelectAll(); break;
        case 6: _t->date4SelectAll(); break;
        case 7: _t->ScheduleDataInit((*reinterpret_cast< Schedule(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_confirm_clicked(); break;
        case 9: _t->on_pushButton_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (schedule_dialog::*_t)(Schedule );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&schedule_dialog::ScheduleDataSend)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject schedule_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_schedule_dialog.data,
      qt_meta_data_schedule_dialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *schedule_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *schedule_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_schedule_dialog.stringdata))
        return static_cast<void*>(const_cast< schedule_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int schedule_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void schedule_dialog::ScheduleDataSend(Schedule _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
