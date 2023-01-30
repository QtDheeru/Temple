/****************************************************************************
** Meta object code from reading C++ file 'SevaTypeNamesDataModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Seva/SevaTypeNamesDataModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SevaTypeNamesDataModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SevaTypeNamesDataModel_t {
    QByteArrayData data[6];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaTypeNamesDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaTypeNamesDataModel_t qt_meta_stringdata_SevaTypeNamesDataModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SevaTypeNamesDataModel"
QT_MOC_LITERAL(1, 23, 16), // "processSevaTypes"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "SevaType*"
QT_MOC_LITERAL(4, 51, 35), // "getSevaBookingConformationDat..."
QT_MOC_LITERAL(5, 87, 33) // "SevaBookingConformationDataMo..."

    },
    "SevaTypeNamesDataModel\0processSevaTypes\0"
    "\0SevaType*\0getSevaBookingConformationDataModel\0"
    "SevaBookingConformationDataModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaTypeNamesDataModel[] = {

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

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    2,

 // methods: parameters
    0x80000000 | 5,

       0        // eod
};

void SevaTypeNamesDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaTypeNamesDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->processSevaTypes((*reinterpret_cast< SevaType*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { SevaBookingConformationDataModel* _r = _t->getSevaBookingConformationDataModel();
            if (_a[0]) *reinterpret_cast< SevaBookingConformationDataModel**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SevaTypeNamesDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SevaTypeNamesDataModel.data,
    qt_meta_data_SevaTypeNamesDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SevaTypeNamesDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SevaTypeNamesDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SevaTypeNamesDataModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SevaTypeNamesDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
