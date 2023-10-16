/****************************************************************************
** Meta object code from reading C++ file 'BookingReportMonthWiseModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/BookingReportMonthWiseModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BookingReportMonthWiseModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BookingReportMonthWiseModel_t {
    QByteArrayData data[6];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BookingReportMonthWiseModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BookingReportMonthWiseModel_t qt_meta_stringdata_BookingReportMonthWiseModel = {
    {
QT_MOC_LITERAL(0, 0, 27), // "BookingReportMonthWiseModel"
QT_MOC_LITERAL(1, 28, 35), // "getBookingReportMonthRangeEle..."
QT_MOC_LITERAL(2, 64, 31), // "BookingReportMonthRangeElement*"
QT_MOC_LITERAL(3, 96, 0), // ""
QT_MOC_LITERAL(4, 97, 4), // "indx"
QT_MOC_LITERAL(5, 102, 36) // "getBookingReportMonthWiseQryL..."

    },
    "BookingReportMonthWiseModel\0"
    "getBookingReportMonthRangeElementAt\0"
    "BookingReportMonthRangeElement*\0\0indx\0"
    "getBookingReportMonthWiseQryListSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BookingReportMonthWiseModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    3, 0x02 /* Public */,
       5,    0,   27,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    QMetaType::Int,

       0        // eod
};

void BookingReportMonthWiseModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BookingReportMonthWiseModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { BookingReportMonthRangeElement* _r = _t->getBookingReportMonthRangeElementAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< BookingReportMonthRangeElement**>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->getBookingReportMonthWiseQryListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BookingReportMonthWiseModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_BookingReportMonthWiseModel.data,
    qt_meta_data_BookingReportMonthWiseModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BookingReportMonthWiseModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BookingReportMonthWiseModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BookingReportMonthWiseModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int BookingReportMonthWiseModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
