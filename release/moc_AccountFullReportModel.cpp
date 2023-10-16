/****************************************************************************
** Meta object code from reading C++ file 'AccountFullReportModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/AccountFullReportModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountFullReportModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccountFullReportModel_t {
    QByteArrayData data[24];
    char stringdata0[524];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccountFullReportModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccountFullReportModel_t qt_meta_stringdata_AccountFullReportModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AccountFullReportModel"
QT_MOC_LITERAL(1, 23, 18), // "iGrandTotalChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 32), // "sendAccountFullreportElementList"
QT_MOC_LITERAL(4, 76, 32), // "QList<AccountFullreportElement*>"
QT_MOC_LITERAL(5, 109, 26), // "accountCSVProcessorChanged"
QT_MOC_LITERAL(6, 136, 14), // "successMessage"
QT_MOC_LITERAL(7, 151, 9), // "exportmsg"
QT_MOC_LITERAL(8, 161, 10), // "insertrows"
QT_MOC_LITERAL(9, 172, 25), // "AccountFullreportElement*"
QT_MOC_LITERAL(10, 198, 21), // "generateAccountReport"
QT_MOC_LITERAL(11, 220, 21), // "ReportFilterElements*"
QT_MOC_LITERAL(12, 242, 33), // "generateFullAccountReportEach..."
QT_MOC_LITERAL(13, 276, 37), // "generateFullAccountReportForD..."
QT_MOC_LITERAL(14, 314, 33), // "generateFullAccountReportForM..."
QT_MOC_LITERAL(15, 348, 35), // "getaccountFullreportElementLi..."
QT_MOC_LITERAL(16, 384, 10), // "FormatDate"
QT_MOC_LITERAL(17, 395, 8), // "unformat"
QT_MOC_LITERAL(18, 404, 19), // "setGrandTotalToZero"
QT_MOC_LITERAL(19, 424, 13), // "resetAccModel"
QT_MOC_LITERAL(20, 438, 26), // "generateFullAccountDataCSV"
QT_MOC_LITERAL(21, 465, 11), // "iGrandTotal"
QT_MOC_LITERAL(22, 477, 19), // "accountCSVProcessor"
QT_MOC_LITERAL(23, 497, 26) // "AccountReportCSVProcessor*"

    },
    "AccountFullReportModel\0iGrandTotalChanged\0"
    "\0sendAccountFullreportElementList\0"
    "QList<AccountFullreportElement*>\0"
    "accountCSVProcessorChanged\0successMessage\0"
    "exportmsg\0insertrows\0AccountFullreportElement*\0"
    "generateAccountReport\0ReportFilterElements*\0"
    "generateFullAccountReportEachdate\0"
    "generateFullAccountReportForDateRange\0"
    "generateFullAccountReportForMonth\0"
    "getaccountFullreportElementListSize\0"
    "FormatDate\0unformat\0setGrandTotalToZero\0"
    "resetAccModel\0generateFullAccountDataCSV\0"
    "iGrandTotal\0accountCSVProcessor\0"
    "AccountReportCSVProcessor*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountFullReportModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   92,    2, 0x0a /* Public */,
      10,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    1,  108,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      19,    0,  112,    2, 0x02 /* Public */,
      20,    0,  113,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Int,
    QMetaType::QString, QMetaType::QString,   17,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      21, QMetaType::Int, 0x00495103,
      22, 0x80000000 | 23, 0x0049510b,

 // properties: notify_signal_id
       0,
       2,

       0        // eod
};

void AccountFullReportModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccountFullReportModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iGrandTotalChanged(); break;
        case 1: _t->sendAccountFullreportElementList((*reinterpret_cast< QList<AccountFullreportElement*>(*)>(_a[1]))); break;
        case 2: _t->accountCSVProcessorChanged(); break;
        case 3: _t->successMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->insertrows((*reinterpret_cast< AccountFullreportElement*(*)>(_a[1]))); break;
        case 5: _t->generateAccountReport((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 6: _t->generateFullAccountReportEachdate((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 7: _t->generateFullAccountReportForDateRange((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 8: _t->generateFullAccountReportForMonth((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 9: { int _r = _t->getaccountFullreportElementListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->FormatDate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setGrandTotalToZero(); break;
        case 12: _t->resetAccModel(); break;
        case 13: _t->generateFullAccountDataCSV(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<AccountFullreportElement*> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountFullreportElement* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AccountFullReportModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountFullReportModel::iGrandTotalChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AccountFullReportModel::*)(QList<AccountFullreportElement*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountFullReportModel::sendAccountFullreportElementList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AccountFullReportModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountFullReportModel::accountCSVProcessorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AccountFullReportModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AccountFullReportModel::successMessage)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportCSVProcessor* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AccountFullReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->iGrandTotal(); break;
        case 1: *reinterpret_cast< AccountReportCSVProcessor**>(_v) = _t->getAccountCSVProcessor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AccountFullReportModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIGrandTotal(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setAccountCSVProcessor(*reinterpret_cast< AccountReportCSVProcessor**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AccountFullReportModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AccountFullReportModel.data,
    qt_meta_data_AccountFullReportModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AccountFullReportModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountFullReportModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccountFullReportModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AccountFullReportModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AccountFullReportModel::iGrandTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AccountFullReportModel::sendAccountFullreportElementList(QList<AccountFullreportElement*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AccountFullReportModel::accountCSVProcessorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AccountFullReportModel::successMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
