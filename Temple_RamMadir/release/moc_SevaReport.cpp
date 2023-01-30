/****************************************************************************
** Meta object code from reading C++ file 'SevaReport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/SevaReport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SevaReport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SevaReport_t {
    QByteArrayData data[44];
    char stringdata0[1096];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaReport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaReport_t qt_meta_stringdata_SevaReport = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SevaReport"
QT_MOC_LITERAL(1, 11, 24), // "ReportOnDateModelChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "AccReportModelChanged"
QT_MOC_LITERAL(4, 59, 21), // "reportElementsChanged"
QT_MOC_LITERAL(5, 81, 22), // "bookReportModelChanged"
QT_MOC_LITERAL(6, 104, 30), // "AccReportDateRangeModelChanged"
QT_MOC_LITERAL(7, 135, 31), // "AccReportMonthRangeModelChanged"
QT_MOC_LITERAL(8, 167, 34), // "BookingReportDateRangeModelCh..."
QT_MOC_LITERAL(9, 202, 35), // "BookingReportMonthRangeModelC..."
QT_MOC_LITERAL(10, 238, 14), // "onDateSelected"
QT_MOC_LITERAL(11, 253, 19), // "onDateRangeSelected"
QT_MOC_LITERAL(12, 273, 26), // "onDateSelectedAccountModel"
QT_MOC_LITERAL(13, 300, 31), // "onDateRangeSelectedAccountModel"
QT_MOC_LITERAL(14, 332, 17), // "generateAccReport"
QT_MOC_LITERAL(15, 350, 21), // "ReportFilterElements*"
QT_MOC_LITERAL(16, 372, 28), // "generateAccReportForEachDate"
QT_MOC_LITERAL(17, 401, 41), // "generateAccReportForEachDateF..."
QT_MOC_LITERAL(18, 443, 29), // "generateAccReportForEachMonth"
QT_MOC_LITERAL(19, 473, 18), // "generateBookReport"
QT_MOC_LITERAL(20, 492, 32), // "generateBookingReportForEachDate"
QT_MOC_LITERAL(21, 525, 45), // "generateBookingReportForEachD..."
QT_MOC_LITERAL(22, 571, 33), // "generateBookingReportForEachM..."
QT_MOC_LITERAL(23, 605, 13), // "resetAccModel"
QT_MOC_LITERAL(24, 619, 22), // "resetAccDateRangeModel"
QT_MOC_LITERAL(25, 642, 23), // "resetAccMonthRangeModel"
QT_MOC_LITERAL(26, 666, 17), // "resetBookingModel"
QT_MOC_LITERAL(27, 684, 26), // "resetBookingDateRangeModel"
QT_MOC_LITERAL(28, 711, 27), // "resetBookingMonthRangeModel"
QT_MOC_LITERAL(29, 739, 17), // "reportOnDateModel"
QT_MOC_LITERAL(30, 757, 23), // "SevaDetailsOnDateModel*"
QT_MOC_LITERAL(31, 781, 14), // "accReportModel"
QT_MOC_LITERAL(32, 796, 19), // "AccountReportModel*"
QT_MOC_LITERAL(33, 816, 15), // "bookReportModel"
QT_MOC_LITERAL(34, 832, 19), // "BookingReportModel*"
QT_MOC_LITERAL(35, 852, 27), // "accountReportDateRangeModel"
QT_MOC_LITERAL(36, 880, 28), // "AccountReportDateRangeModel*"
QT_MOC_LITERAL(37, 909, 28), // "accountReportMonthRangeModel"
QT_MOC_LITERAL(38, 938, 28), // "AccountReportMonthWiseModel*"
QT_MOC_LITERAL(39, 967, 14), // "reportElements"
QT_MOC_LITERAL(40, 982, 27), // "bookingReportDateRangeModel"
QT_MOC_LITERAL(41, 1010, 28), // "BookingReportDateRangeModel*"
QT_MOC_LITERAL(42, 1039, 27), // "bookingReportMonthWiseModel"
QT_MOC_LITERAL(43, 1067, 28) // "BookingReportMonthWiseModel*"

    },
    "SevaReport\0ReportOnDateModelChanged\0"
    "\0AccReportModelChanged\0reportElementsChanged\0"
    "bookReportModelChanged\0"
    "AccReportDateRangeModelChanged\0"
    "AccReportMonthRangeModelChanged\0"
    "BookingReportDateRangeModelChanged\0"
    "BookingReportMonthRangeModelChanged\0"
    "onDateSelected\0onDateRangeSelected\0"
    "onDateSelectedAccountModel\0"
    "onDateRangeSelectedAccountModel\0"
    "generateAccReport\0ReportFilterElements*\0"
    "generateAccReportForEachDate\0"
    "generateAccReportForEachDateForWholeMonth\0"
    "generateAccReportForEachMonth\0"
    "generateBookReport\0generateBookingReportForEachDate\0"
    "generateBookingReportForEachDateForWholeMonth\0"
    "generateBookingReportForEachMonth\0"
    "resetAccModel\0resetAccDateRangeModel\0"
    "resetAccMonthRangeModel\0resetBookingModel\0"
    "resetBookingDateRangeModel\0"
    "resetBookingMonthRangeModel\0"
    "reportOnDateModel\0SevaDetailsOnDateModel*\0"
    "accReportModel\0AccountReportModel*\0"
    "bookReportModel\0BookingReportModel*\0"
    "accountReportDateRangeModel\0"
    "AccountReportDateRangeModel*\0"
    "accountReportMonthRangeModel\0"
    "AccountReportMonthWiseModel*\0"
    "reportElements\0bookingReportDateRangeModel\0"
    "BookingReportDateRangeModel*\0"
    "bookingReportMonthWiseModel\0"
    "BookingReportMonthWiseModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaReport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       8,  198, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,
       5,    0,  147,    2, 0x06 /* Public */,
       6,    0,  148,    2, 0x06 /* Public */,
       7,    0,  149,    2, 0x06 /* Public */,
       8,    0,  150,    2, 0x06 /* Public */,
       9,    0,  151,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  152,    2, 0x0a /* Public */,
      11,    2,  155,    2, 0x0a /* Public */,
      12,    1,  160,    2, 0x0a /* Public */,
      13,    2,  163,    2, 0x0a /* Public */,
      14,    1,  168,    2, 0x0a /* Public */,
      16,    1,  171,    2, 0x0a /* Public */,
      17,    1,  174,    2, 0x0a /* Public */,
      18,    1,  177,    2, 0x0a /* Public */,
      19,    1,  180,    2, 0x0a /* Public */,
      20,    1,  183,    2, 0x0a /* Public */,
      21,    1,  186,    2, 0x0a /* Public */,
      22,    1,  189,    2, 0x0a /* Public */,
      23,    0,  192,    2, 0x0a /* Public */,
      24,    0,  193,    2, 0x0a /* Public */,
      25,    0,  194,    2, 0x0a /* Public */,
      26,    0,  195,    2, 0x0a /* Public */,
      27,    0,  196,    2, 0x0a /* Public */,
      28,    0,  197,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      29, 0x80000000 | 30, 0x00495009,
      31, 0x80000000 | 32, 0x00495009,
      33, 0x80000000 | 34, 0x00495009,
      35, 0x80000000 | 36, 0x00495009,
      37, 0x80000000 | 38, 0x00495009,
      39, 0x80000000 | 15, 0x00495009,
      40, 0x80000000 | 41, 0x00495009,
      42, 0x80000000 | 43, 0x00495009,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       5,
       2,
       6,
       7,

       0        // eod
};

void SevaReport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaReport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReportOnDateModelChanged(); break;
        case 1: _t->AccReportModelChanged(); break;
        case 2: _t->reportElementsChanged(); break;
        case 3: _t->bookReportModelChanged(); break;
        case 4: _t->AccReportDateRangeModelChanged(); break;
        case 5: _t->AccReportMonthRangeModelChanged(); break;
        case 6: _t->BookingReportDateRangeModelChanged(); break;
        case 7: _t->BookingReportMonthRangeModelChanged(); break;
        case 8: _t->onDateSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onDateRangeSelected((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->onDateSelectedAccountModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onDateRangeSelectedAccountModel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->generateAccReport((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 13: _t->generateAccReportForEachDate((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 14: _t->generateAccReportForEachDateForWholeMonth((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 15: _t->generateAccReportForEachMonth((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 16: _t->generateBookReport((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 17: _t->generateBookingReportForEachDate((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 18: _t->generateBookingReportForEachDateForWholeMonth((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 19: _t->generateBookingReportForEachMonth((*reinterpret_cast< ReportFilterElements*(*)>(_a[1]))); break;
        case 20: _t->resetAccModel(); break;
        case 21: _t->resetAccDateRangeModel(); break;
        case 22: _t->resetAccMonthRangeModel(); break;
        case 23: _t->resetBookingModel(); break;
        case 24: _t->resetBookingDateRangeModel(); break;
        case 25: _t->resetBookingMonthRangeModel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
            }
            break;
        case 19:
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
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::ReportOnDateModelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::AccReportModelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::reportElementsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::bookReportModelChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::AccReportDateRangeModelChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::AccReportMonthRangeModelChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::BookingReportDateRangeModelChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SevaReport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaReport::BookingReportMonthRangeModelChanged)) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportDateRangeModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportModel* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportMonthWiseModel* >(); break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportDateRangeModel* >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportModel* >(); break;
        case 7:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportMonthWiseModel* >(); break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ReportFilterElements* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaDetailsOnDateModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SevaReport *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SevaDetailsOnDateModel**>(_v) = _t->sevaOnDateModel(); break;
        case 1: *reinterpret_cast< AccountReportModel**>(_v) = _t->accountreportModel(); break;
        case 2: *reinterpret_cast< BookingReportModel**>(_v) = _t->bookingReportModel(); break;
        case 3: *reinterpret_cast< AccountReportDateRangeModel**>(_v) = _t->accountReportDateRangeModel(); break;
        case 4: *reinterpret_cast< AccountReportMonthWiseModel**>(_v) = _t->accountReportMonthRangeModel(); break;
        case 5: *reinterpret_cast< ReportFilterElements**>(_v) = _t->getReportElements(); break;
        case 6: *reinterpret_cast< BookingReportDateRangeModel**>(_v) = _t->bookingReportDateRangeModel(); break;
        case 7: *reinterpret_cast< BookingReportMonthWiseModel**>(_v) = _t->bookingReportMonthWiseModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject SevaReport::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SevaReport.data,
    qt_meta_data_SevaReport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SevaReport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SevaReport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SevaReport.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SevaReport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SevaReport::ReportOnDateModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SevaReport::AccReportModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SevaReport::reportElementsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SevaReport::bookReportModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SevaReport::AccReportDateRangeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SevaReport::AccReportMonthRangeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SevaReport::BookingReportDateRangeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SevaReport::BookingReportMonthRangeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
