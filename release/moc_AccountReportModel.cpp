/****************************************************************************
** Meta object code from reading C++ file 'AccountReportModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/AccountReportModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountReportModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccountReportModel_t {
    QByteArrayData data[11];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccountReportModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccountReportModel_t qt_meta_stringdata_AccountReportModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AccountReportModel"
QT_MOC_LITERAL(1, 19, 17), // "grandTotalChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "sendAccountReportList"
QT_MOC_LITERAL(4, 60, 28), // "QList<AccountReportElement*>"
QT_MOC_LITERAL(5, 89, 14), // "successMessage"
QT_MOC_LITERAL(6, 104, 9), // "exportmsg"
QT_MOC_LITERAL(7, 114, 27), // "getAccountReportQryListSize"
QT_MOC_LITERAL(8, 142, 19), // "setGrandTotalToZero"
QT_MOC_LITERAL(9, 162, 18), // "generateAccountCSV"
QT_MOC_LITERAL(10, 181, 10) // "grandTotal"

    },
    "AccountReportModel\0grandTotalChanged\0"
    "\0sendAccountReportList\0"
    "QList<AccountReportElement*>\0"
    "successMessage\0exportmsg\0"
    "getAccountReportQryListSize\0"
    "setGrandTotalToZero\0generateAccountCSV\0"
    "grandTotal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountReportModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   51,    2, 0x02 /* Public */,
       8,    0,   52,    2, 0x02 /* Public */,
       9,    0,   53,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Float, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void AccountReportModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccountReportModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grandTotalChanged(); break;
        case 1: _t->sendAccountReportList((*reinterpret_cast< QList<AccountReportElement*>(*)>(_a[1]))); break;
        case 2: _t->successMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { int _r = _t->getAccountReportQryListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setGrandTotalToZero(); break;
        case 5: _t->generateAccountCSV(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<AccountReportElement*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AccountReportModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountReportModel::grandTotalChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AccountReportModel::*)(QList<AccountReportElement*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountReportModel::sendAccountReportList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AccountReportModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountReportModel::successMessage)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AccountReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->iGrandTotal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AccountReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIGrandTotal(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AccountReportModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AccountReportModel.data,
    qt_meta_data_AccountReportModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AccountReportModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountReportModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccountReportModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AccountReportModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AccountReportModel::grandTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AccountReportModel::sendAccountReportList(QList<AccountReportElement*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AccountReportModel::successMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
