/****************************************************************************
** Meta object code from reading C++ file 'VoucherFilterElements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/voucher/VoucherFilterElements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherFilterElements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherFilterElements_t {
    QByteArrayData data[18];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherFilterElements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherFilterElements_t qt_meta_stringdata_VoucherFilterElements = {
    {
QT_MOC_LITERAL(0, 0, 21), // "VoucherFilterElements"
QT_MOC_LITERAL(1, 22, 19), // "sVoucherTypeChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 19), // "sPaymentModeChanged"
QT_MOC_LITERAL(4, 63, 18), // "sSingleDateChanged"
QT_MOC_LITERAL(5, 82, 17), // "sStartDateChanged"
QT_MOC_LITERAL(6, 100, 15), // "sEndDateChanged"
QT_MOC_LITERAL(7, 116, 13), // "sMonthChanged"
QT_MOC_LITERAL(8, 130, 12), // "sYearChanged"
QT_MOC_LITERAL(9, 143, 20), // "iSelectedTypeChanged"
QT_MOC_LITERAL(10, 164, 12), // "sVoucherType"
QT_MOC_LITERAL(11, 177, 12), // "sPaymentMode"
QT_MOC_LITERAL(12, 190, 11), // "sSingleDate"
QT_MOC_LITERAL(13, 202, 10), // "sStartDate"
QT_MOC_LITERAL(14, 213, 8), // "sEndDate"
QT_MOC_LITERAL(15, 222, 6), // "sMonth"
QT_MOC_LITERAL(16, 229, 5), // "sYear"
QT_MOC_LITERAL(17, 235, 13) // "iSelectedType"

    },
    "VoucherFilterElements\0sVoucherTypeChanged\0"
    "\0sPaymentModeChanged\0sSingleDateChanged\0"
    "sStartDateChanged\0sEndDateChanged\0"
    "sMonthChanged\0sYearChanged\0"
    "iSelectedTypeChanged\0sVoucherType\0"
    "sPaymentMode\0sSingleDate\0sStartDate\0"
    "sEndDate\0sMonth\0sYear\0iSelectedType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherFilterElements[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void VoucherFilterElements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherFilterElements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sVoucherTypeChanged(); break;
        case 1: _t->sPaymentModeChanged(); break;
        case 2: _t->sSingleDateChanged(); break;
        case 3: _t->sStartDateChanged(); break;
        case 4: _t->sEndDateChanged(); break;
        case 5: _t->sMonthChanged(); break;
        case 6: _t->sYearChanged(); break;
        case 7: _t->iSelectedTypeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sVoucherTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sPaymentModeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sSingleDateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sStartDateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sEndDateChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sMonthChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::sYearChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoucherFilterElements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherFilterElements::iSelectedTypeChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherFilterElements *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sVoucherType(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->sPaymentMode(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->sSingleDate(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->sStartDate(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->sEndDate(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->sMonth(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->sYear(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->iSelectedType(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherFilterElements *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSVoucherType(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setSPaymentMode(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSSingleDate(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setSStartDate(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setSEndDate(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setSMonth(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setSYear(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setISelectedType(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject VoucherFilterElements::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherFilterElements.data,
    qt_meta_data_VoucherFilterElements,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherFilterElements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherFilterElements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherFilterElements.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherFilterElements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VoucherFilterElements::sVoucherTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherFilterElements::sPaymentModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VoucherFilterElements::sSingleDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VoucherFilterElements::sStartDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VoucherFilterElements::sEndDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VoucherFilterElements::sMonthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VoucherFilterElements::sYearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VoucherFilterElements::iSelectedTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
