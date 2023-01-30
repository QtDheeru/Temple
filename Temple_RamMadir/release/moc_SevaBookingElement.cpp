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
    QByteArrayData data[13];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaBookingElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaBookingElement_t qt_meta_stringdata_SevaBookingElement = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SevaBookingElement"
QT_MOC_LITERAL(1, 19, 3), // "sno"
QT_MOC_LITERAL(2, 23, 9), // "person_id"
QT_MOC_LITERAL(3, 33, 6), // "person"
QT_MOC_LITERAL(4, 40, 21), // "DevotePersnalDetails*"
QT_MOC_LITERAL(5, 62, 8), // "sevatype"
QT_MOC_LITERAL(6, 71, 8), // "sevaname"
QT_MOC_LITERAL(7, 80, 8), // "quantity"
QT_MOC_LITERAL(8, 89, 11), // "receiptDate"
QT_MOC_LITERAL(9, 101, 8), // "sevaDate"
QT_MOC_LITERAL(10, 110, 9), // "totalCost"
QT_MOC_LITERAL(11, 120, 4), // "cash"
QT_MOC_LITERAL(12, 125, 4) // "bank"

    },
    "SevaBookingElement\0sno\0person_id\0"
    "person\0DevotePersnalDetails*\0sevatype\0"
    "sevaname\0quantity\0receiptDate\0sevaDate\0"
    "totalCost\0cash\0bank"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaBookingElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      11,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, 0x80000000 | 4, 0x0009510b,
       5, QMetaType::QString, 0x00095103,
       6, QMetaType::QString, 0x00095103,
       7, QMetaType::QString, 0x00095103,
       8, QMetaType::QString, 0x00095103,
       9, QMetaType::QString, 0x00095103,
      10, QMetaType::QString, 0x00095103,
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::QString, 0x00095103,

       0        // eod
};

void SevaBookingElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
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
        case 8: *reinterpret_cast< QString*>(_v) = _t->totalCost(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->cash(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->bank(); break;
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
        case 8: _t->setTotalCost(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setCash(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setBank(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
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
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
