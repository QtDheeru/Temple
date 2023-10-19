/****************************************************************************
** Meta object code from reading C++ file 'SevaBookingElement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/SevaBookingElement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SevaBookingElement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SevaBookingElement_t {
    QByteArrayData data[20];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaBookingElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaBookingElement_t qt_meta_stringdata_SevaBookingElement = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SevaBookingElement"
QT_MOC_LITERAL(1, 19, 15), // "sevatimeChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "statusChanged"
QT_MOC_LITERAL(4, 50, 15), // "bankNameChanged"
QT_MOC_LITERAL(5, 66, 3), // "sno"
QT_MOC_LITERAL(6, 70, 9), // "person_id"
QT_MOC_LITERAL(7, 80, 6), // "person"
QT_MOC_LITERAL(8, 87, 21), // "DevotePersnalDetails*"
QT_MOC_LITERAL(9, 109, 8), // "sevatype"
QT_MOC_LITERAL(10, 118, 8), // "sevaname"
QT_MOC_LITERAL(11, 127, 8), // "quantity"
QT_MOC_LITERAL(12, 136, 11), // "receiptDate"
QT_MOC_LITERAL(13, 148, 8), // "sevaDate"
QT_MOC_LITERAL(14, 157, 8), // "sevatime"
QT_MOC_LITERAL(15, 166, 9), // "totalCost"
QT_MOC_LITERAL(16, 176, 4), // "cash"
QT_MOC_LITERAL(17, 181, 4), // "bank"
QT_MOC_LITERAL(18, 186, 6), // "status"
QT_MOC_LITERAL(19, 193, 8) // "bankName"

    },
    "SevaBookingElement\0sevatimeChanged\0\0"
    "statusChanged\0bankNameChanged\0sno\0"
    "person_id\0person\0DevotePersnalDetails*\0"
    "sevatype\0sevaname\0quantity\0receiptDate\0"
    "sevaDate\0sevatime\0totalCost\0cash\0bank\0"
    "status\0bankName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaBookingElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
      14,   32, // properties
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
       5, QMetaType::QString, 0x00095103,
       6, QMetaType::QString, 0x00095103,
       7, 0x80000000 | 8, 0x0009510b,
       9, QMetaType::QString, 0x00095103,
      10, QMetaType::QString, 0x00095103,
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::QString, 0x00095103,
      13, QMetaType::QString, 0x00095103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00095103,
      16, QMetaType::QString, 0x00095103,
      17, QMetaType::QString, 0x00095103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

void SevaBookingElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaBookingElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sevatimeChanged(); break;
        case 1: _t->statusChanged(); break;
        case 2: _t->bankNameChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SevaBookingElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaBookingElement::sevatimeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SevaBookingElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaBookingElement::statusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SevaBookingElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaBookingElement::bankNameChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevotePersnalDetails* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SevaBookingElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sno(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->person_id(); break;
        case 2: *reinterpret_cast< DevotePersnalDetails**>(_v) = _t->person(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->sevatype(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->sevaname(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->quantity(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->receiptDate(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->sevaDate(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->sevatime(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->totalCost(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->cash(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->bank(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->status(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->bankName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SevaBookingElement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSno(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPerson_id(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPerson(*reinterpret_cast< DevotePersnalDetails**>(_v)); break;
        case 3: _t->setSevatype(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setSevaname(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setQuantity(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setReceiptDate(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setSevaDate(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setSevatime(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setTotalCost(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setCash(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setBank(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->setStatus(*reinterpret_cast< QString*>(_v)); break;
        case 13: _t->setBankName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SevaBookingElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SevaBookingElement.data,
    qt_meta_data_SevaBookingElement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SevaBookingElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SevaBookingElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SevaBookingElement.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SevaBookingElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SevaBookingElement::sevatimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SevaBookingElement::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SevaBookingElement::bankNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
