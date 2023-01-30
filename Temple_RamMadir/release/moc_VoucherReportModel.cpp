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
    QByteArrayData data[12];
    char stringdata0[193];
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
QT_MOC_LITERAL(3, 38, 21), // "generateVoucherReport"
QT_MOC_LITERAL(4, 60, 22), // "VoucherFilterElements*"
QT_MOC_LITERAL(5, 83, 16), // "insertVoucherRow"
QT_MOC_LITERAL(6, 100, 15), // "VoucherElement*"
QT_MOC_LITERAL(7, 116, 13), // "resetVouModel"
QT_MOC_LITERAL(8, 130, 27), // "getVoucherReportQryListSize"
QT_MOC_LITERAL(9, 158, 18), // "getVoucherReportAt"
QT_MOC_LITERAL(10, 177, 4), // "indx"
QT_MOC_LITERAL(11, 182, 10) // "grandTotal"

    },
    "VoucherReportModel\0grandTotalChanged\0"
    "\0generateVoucherReport\0VoucherFilterElements*\0"
    "insertVoucherRow\0VoucherElement*\0"
    "resetVouModel\0getVoucherReportQryListSize\0"
    "getVoucherReportAt\0indx\0grandTotal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherReportModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x02 /* Public */,
       9,    1,   53,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    0x80000000 | 6, QMetaType::Int,   10,

 // properties: name, type, flags
      11, QMetaType::Int, 0x00495003,

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
        case 1: _t->generateVoucherReport((*reinterpret_cast< VoucherFilterElements*(*)>(_a[1]))); break;
        case 2: _t->insertVoucherRow((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 3: _t->resetVouModel(); break;
        case 4: { int _r = _t->getVoucherReportQryListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { VoucherElement* _r = _t->getVoucherReportAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< VoucherElement**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherFilterElements* >(); break;
            }
            break;
        case 2:
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
void VoucherReportModel::grandTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
