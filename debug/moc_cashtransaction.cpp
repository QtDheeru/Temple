/****************************************************************************
** Meta object code from reading C++ file 'cashtransaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/BankRegistration_m/cashtransaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cashtransaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CashTransaction_t {
    QByteArrayData data[29];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CashTransaction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CashTransaction_t qt_meta_stringdata_CashTransaction = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CashTransaction"
QT_MOC_LITERAL(1, 16, 16), // "banksListChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "receiptNumberChanged"
QT_MOC_LITERAL(4, 55, 17), // "cashInHandChanged"
QT_MOC_LITERAL(5, 73, 11), // "toBankEmpty"
QT_MOC_LITERAL(6, 85, 9), // "addedData"
QT_MOC_LITERAL(7, 95, 10), // "lowBalance"
QT_MOC_LITERAL(8, 106, 11), // "dataFromQml"
QT_MOC_LITERAL(9, 118, 6), // "a_date"
QT_MOC_LITERAL(10, 125, 10), // "a_lastreci"
QT_MOC_LITERAL(11, 136, 12), // "a_cashinhand"
QT_MOC_LITERAL(12, 149, 8), // "a_tobank"
QT_MOC_LITERAL(13, 158, 11), // "a_transType"
QT_MOC_LITERAL(14, 170, 6), // "a_bank"
QT_MOC_LITERAL(15, 177, 8), // "a_person"
QT_MOC_LITERAL(16, 186, 7), // "a_notes"
QT_MOC_LITERAL(17, 194, 25), // "onSignalToCashTransaction"
QT_MOC_LITERAL(18, 220, 15), // "a_recieptNumber"
QT_MOC_LITERAL(19, 236, 12), // "a_cashInHand"
QT_MOC_LITERAL(20, 249, 8), // "a_toBank"
QT_MOC_LITERAL(21, 258, 17), // "a_TransactionType"
QT_MOC_LITERAL(22, 276, 19), // "onSignalToCashEntry"
QT_MOC_LITERAL(23, 296, 6), // "a_cash"
QT_MOC_LITERAL(24, 303, 10), // "a_cashType"
QT_MOC_LITERAL(25, 314, 7), // "initial"
QT_MOC_LITERAL(26, 322, 9), // "banksList"
QT_MOC_LITERAL(27, 332, 13), // "receiptNumber"
QT_MOC_LITERAL(28, 346, 10) // "cashInHand"

    },
    "CashTransaction\0banksListChanged\0\0"
    "receiptNumberChanged\0cashInHandChanged\0"
    "toBankEmpty\0addedData\0lowBalance\0"
    "dataFromQml\0a_date\0a_lastreci\0"
    "a_cashinhand\0a_tobank\0a_transType\0"
    "a_bank\0a_person\0a_notes\0"
    "onSignalToCashTransaction\0a_recieptNumber\0"
    "a_cashInHand\0a_toBank\0a_TransactionType\0"
    "onSignalToCashEntry\0a_cash\0a_cashType\0"
    "initial\0banksList\0receiptNumber\0"
    "cashInHand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CashTransaction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    8,   70,    2, 0x0a /* Public */,
      17,    4,   87,    2, 0x0a /* Public */,
      22,    3,   96,    2, 0x0a /* Public */,
      25,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   23,   24,
    QMetaType::Void,

 // properties: name, type, flags
      26, QMetaType::QStringList, 0x00495103,
      27, QMetaType::QString, 0x00495103,
      28, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void CashTransaction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CashTransaction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->banksListChanged(); break;
        case 1: _t->receiptNumberChanged(); break;
        case 2: _t->cashInHandChanged(); break;
        case 3: _t->toBankEmpty(); break;
        case 4: _t->addedData(); break;
        case 5: _t->lowBalance(); break;
        case 6: _t->dataFromQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 7: _t->onSignalToCashTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 8: _t->onSignalToCashEntry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->initial(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::banksListChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::receiptNumberChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::cashInHandChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::toBankEmpty)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::addedData)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CashTransaction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CashTransaction::lowBalance)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CashTransaction *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->getBanksList(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->receiptNumber(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->cashInHand(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CashTransaction *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBanksList(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: _t->setReceiptNumber(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCashInHand(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CashTransaction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CashTransaction.data,
    qt_meta_data_CashTransaction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CashTransaction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CashTransaction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CashTransaction.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CashTransaction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CashTransaction::banksListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CashTransaction::receiptNumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CashTransaction::cashInHandChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CashTransaction::toBankEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CashTransaction::addedData()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CashTransaction::lowBalance()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
