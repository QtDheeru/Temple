/****************************************************************************
** Meta object code from reading C++ file 'BookingReportDateRangeElement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/BookingReportDateRangeElement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BookingReportDateRangeElement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BookingReportDateRangeElement_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BookingReportDateRangeElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BookingReportDateRangeElement_t qt_meta_stringdata_BookingReportDateRangeElement = {
    {
QT_MOC_LITERAL(0, 0, 29), // "BookingReportDateRangeElement"
QT_MOC_LITERAL(1, 30, 11), // "dateChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 21), // "totalSevaCountChanged"
QT_MOC_LITERAL(4, 65, 18), // "totalAmountChanged"
QT_MOC_LITERAL(5, 84, 4), // "date"
QT_MOC_LITERAL(6, 89, 14) // "totalSevaCount"

    },
    "BookingReportDateRangeElement\0dateChanged\0"
    "\0totalSevaCountChanged\0totalAmountChanged\0"
    "date\0totalSevaCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BookingReportDateRangeElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495103,
       6, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void BookingReportDateRangeElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BookingReportDateRangeElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateChanged(); break;
        case 1: _t->totalSevaCountChanged(); break;
        case 2: _t->totalAmountChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BookingReportDateRangeElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookingReportDateRangeElement::dateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BookingReportDateRangeElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookingReportDateRangeElement::totalSevaCountChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BookingReportDateRangeElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookingReportDateRangeElement::totalAmountChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BookingReportDateRangeElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->date(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->totalSevaCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BookingReportDateRangeElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDate(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTotalSevaCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BookingReportDateRangeElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BookingReportDateRangeElement.data,
    qt_meta_data_BookingReportDateRangeElement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BookingReportDateRangeElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BookingReportDateRangeElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BookingReportDateRangeElement.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BookingReportDateRangeElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BookingReportDateRangeElement::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BookingReportDateRangeElement::totalSevaCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BookingReportDateRangeElement::totalAmountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
