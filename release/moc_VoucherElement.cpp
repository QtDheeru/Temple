/****************************************************************************
** Meta object code from reading C++ file 'VoucherElement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/voucher/VoucherElement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherElement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherElement_t {
    QByteArrayData data[22];
    char stringdata0[340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherElement_t qt_meta_stringdata_VoucherElement = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VoucherElement"
QT_MOC_LITERAL(1, 15, 18), // "voucherDateChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "voucherNoChanged"
QT_MOC_LITERAL(4, 52, 18), // "voucherNameChanged"
QT_MOC_LITERAL(5, 71, 15), // "mobileNoChanged"
QT_MOC_LITERAL(6, 87, 18), // "voucherTypeChanged"
QT_MOC_LITERAL(7, 106, 18), // "voucherItemChanged"
QT_MOC_LITERAL(8, 125, 18), // "voucherNoteChanged"
QT_MOC_LITERAL(9, 144, 18), // "voucherCostChanged"
QT_MOC_LITERAL(10, 163, 25), // "voucherPaymentModeChanged"
QT_MOC_LITERAL(11, 189, 23), // "PaymentReferenceChanged"
QT_MOC_LITERAL(12, 213, 11), // "voucherDate"
QT_MOC_LITERAL(13, 225, 9), // "voucherNo"
QT_MOC_LITERAL(14, 235, 11), // "voucherName"
QT_MOC_LITERAL(15, 247, 8), // "mobileNo"
QT_MOC_LITERAL(16, 256, 11), // "voucherType"
QT_MOC_LITERAL(17, 268, 11), // "voucherItem"
QT_MOC_LITERAL(18, 280, 11), // "voucherNote"
QT_MOC_LITERAL(19, 292, 11), // "voucherCost"
QT_MOC_LITERAL(20, 304, 18), // "voucherPaymentMode"
QT_MOC_LITERAL(21, 323, 16) // "paymentReference"

    },
    "VoucherElement\0voucherDateChanged\0\0"
    "voucherNoChanged\0voucherNameChanged\0"
    "mobileNoChanged\0voucherTypeChanged\0"
    "voucherItemChanged\0voucherNoteChanged\0"
    "voucherCostChanged\0voucherPaymentModeChanged\0"
    "PaymentReferenceChanged\0voucherDate\0"
    "voucherNo\0voucherName\0mobileNo\0"
    "voucherType\0voucherItem\0voucherNote\0"
    "voucherCost\0voucherPaymentMode\0"
    "paymentReference"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      10,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
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

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,

       0        // eod
};

void VoucherElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->voucherDateChanged(); break;
        case 1: _t->voucherNoChanged(); break;
        case 2: _t->voucherNameChanged(); break;
        case 3: _t->mobileNoChanged(); break;
        case 4: _t->voucherTypeChanged(); break;
        case 5: _t->voucherItemChanged(); break;
        case 6: _t->voucherNoteChanged(); break;
        case 7: _t->voucherCostChanged(); break;
        case 8: _t->voucherPaymentModeChanged(); break;
        case 9: _t->PaymentReferenceChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherDateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherNoChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherNameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::mobileNoChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherTypeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherItemChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherNoteChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherCostChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::voucherPaymentModeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VoucherElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherElement::PaymentReferenceChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->voucherDate(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->voucherNo(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->voucherName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->mobileNo(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->voucherType(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->voucherItem(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->voucherNote(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->voucherCost(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->voucherPaymentMode(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->PaymentReference(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVoucherDate(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setVoucherNo(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setVoucherName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setMobileNo(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setVoucherType(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setVoucherItem(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setVoucherNote(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setVoucherCost(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setVoucherPaymentMode(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setPaymentReference(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject VoucherElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherElement.data,
    qt_meta_data_VoucherElement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherElement.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VoucherElement::voucherDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherElement::voucherNoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VoucherElement::voucherNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VoucherElement::mobileNoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VoucherElement::voucherTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VoucherElement::voucherItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VoucherElement::voucherNoteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VoucherElement::voucherCostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VoucherElement::voucherPaymentModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VoucherElement::PaymentReferenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
