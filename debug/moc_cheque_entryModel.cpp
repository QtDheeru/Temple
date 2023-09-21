/****************************************************************************
** Meta object code from reading C++ file 'cheque_entryModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/BankRegistration_m/cheque_entryModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cheque_entryModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cheque_EntryModel_t {
    QByteArrayData data[18];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cheque_EntryModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cheque_EntryModel_t qt_meta_stringdata_Cheque_EntryModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Cheque_EntryModel"
QT_MOC_LITERAL(1, 18, 16), // "checklistChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "addedToDataBase"
QT_MOC_LITERAL(4, 52, 23), // "listOfNumToAddDBChanged"
QT_MOC_LITERAL(5, 76, 13), // "addtoListMain"
QT_MOC_LITERAL(6, 90, 8), // "bankname"
QT_MOC_LITERAL(7, 99, 13), // "receiptNumber"
QT_MOC_LITERAL(8, 113, 11), // "receiptDate"
QT_MOC_LITERAL(9, 125, 6), // "amount"
QT_MOC_LITERAL(10, 132, 10), // "chequeDate"
QT_MOC_LITERAL(11, 143, 9), // "addToList"
QT_MOC_LITERAL(12, 153, 14), // "removeFromList"
QT_MOC_LITERAL(13, 168, 12), // "submitToBank"
QT_MOC_LITERAL(14, 181, 9), // "emptyList"
QT_MOC_LITERAL(15, 191, 29), // "removeDbAddedElementsFromList"
QT_MOC_LITERAL(16, 221, 17), // "onClearChequeList"
QT_MOC_LITERAL(17, 239, 17) // "fetchFromDataBase"

    },
    "Cheque_EntryModel\0checklistChanged\0\0"
    "addedToDataBase\0listOfNumToAddDBChanged\0"
    "addtoListMain\0bankname\0receiptNumber\0"
    "receiptDate\0amount\0chequeDate\0addToList\0"
    "removeFromList\0submitToBank\0emptyList\0"
    "removeDbAddedElementsFromList\0"
    "onClearChequeList\0fetchFromDataBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cheque_EntryModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    5,   72,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cheque_EntryModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cheque_EntryModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checklistChanged(); break;
        case 1: _t->addedToDataBase(); break;
        case 2: _t->listOfNumToAddDBChanged(); break;
        case 3: _t->addtoListMain((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 4: _t->addToList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->removeFromList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->submitToBank(); break;
        case 7: _t->emptyList(); break;
        case 8: _t->removeDbAddedElementsFromList(); break;
        case 9: _t->onClearChequeList(); break;
        case 10: _t->fetchFromDataBase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cheque_EntryModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cheque_EntryModel::checklistChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cheque_EntryModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cheque_EntryModel::addedToDataBase)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cheque_EntryModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cheque_EntryModel::listOfNumToAddDBChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cheque_EntryModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_Cheque_EntryModel.data,
    qt_meta_data_Cheque_EntryModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cheque_EntryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cheque_EntryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cheque_EntryModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int Cheque_EntryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Cheque_EntryModel::checklistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cheque_EntryModel::addedToDataBase()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cheque_EntryModel::listOfNumToAddDBChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
