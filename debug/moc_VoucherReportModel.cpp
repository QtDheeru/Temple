/****************************************************************************
** Meta object code from reading C++ file 'VoucherReportModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/voucher/VoucherReportModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherReportModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherReportModel_t {
    QByteArrayData data[17];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherReportModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherReportModel_t qt_meta_stringdata_VoucherReportModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "VoucherReportModel"
QT_MOC_LITERAL(1, 19, 17), // "grandTotalChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "sendVoucherReportList"
QT_MOC_LITERAL(4, 60, 22), // "QList<VoucherElement*>"
QT_MOC_LITERAL(5, 83, 14), // "successMessage"
QT_MOC_LITERAL(6, 98, 9), // "exportmsg"
QT_MOC_LITERAL(7, 108, 21), // "generateVoucherReport"
QT_MOC_LITERAL(8, 130, 22), // "VoucherFilterElements*"
QT_MOC_LITERAL(9, 153, 16), // "insertVoucherRow"
QT_MOC_LITERAL(10, 170, 15), // "VoucherElement*"
QT_MOC_LITERAL(11, 186, 13), // "resetVouModel"
QT_MOC_LITERAL(12, 200, 27), // "getVoucherReportQryListSize"
QT_MOC_LITERAL(13, 228, 18), // "getVoucherReportAt"
QT_MOC_LITERAL(14, 247, 4), // "indx"
QT_MOC_LITERAL(15, 252, 24), // "generateVoucherReportCSV"
QT_MOC_LITERAL(16, 277, 10) // "grandTotal"

    },
    "VoucherReportModel\0grandTotalChanged\0"
    "\0sendVoucherReportList\0QList<VoucherElement*>\0"
    "successMessage\0exportmsg\0generateVoucherReport\0"
    "VoucherFilterElements*\0insertVoucherRow\0"
    "VoucherElement*\0resetVouModel\0"
    "getVoucherReportQryListSize\0"
    "getVoucherReportAt\0indx\0"
    "generateVoucherReportCSV\0grandTotal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherReportModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    0,   73,    2, 0x02 /* Public */,
      13,    1,   74,    2, 0x02 /* Public */,
      15,    0,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    0x80000000 | 10, QMetaType::Int,   14,
    QMetaType::Void,

 // properties: name, type, flags
      16, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void VoucherReportModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherReportModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grandTotalChanged(); break;
        case 1: _t->sendVoucherReportList((*reinterpret_cast< QList<VoucherElement*>(*)>(_a[1]))); break;
        case 2: _t->successMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->generateVoucherReport((*reinterpret_cast< VoucherFilterElements*(*)>(_a[1]))); break;
        case 4: _t->insertVoucherRow((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 5: _t->resetVouModel(); break;
        case 6: { int _r = _t->getVoucherReportQryListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { VoucherElement* _r = _t->getVoucherReportAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< VoucherElement**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->generateVoucherReportCSV(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<VoucherElement*> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherFilterElements* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherElement* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherReportModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherReportModel::grandTotalChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherReportModel::*)(QList<VoucherElement*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherReportModel::sendVoucherReportList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherReportModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherReportModel::successMessage)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->iGrandTotal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIGrandTotal(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VoucherReportModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_VoucherReportModel.data,
    qt_meta_data_VoucherReportModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherReportModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherReportModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherReportModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int VoucherReportModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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
void VoucherReportModel::grandTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherReportModel::sendVoucherReportList(QList<VoucherElement*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VoucherReportModel::successMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
