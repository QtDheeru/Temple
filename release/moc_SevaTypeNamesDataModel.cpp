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
    QByteArrayData data[11];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaTypeNamesDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaTypeNamesDataModel_t qt_meta_stringdata_SevaTypeNamesDataModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SevaTypeNamesDataModel"
QT_MOC_LITERAL(1, 23, 5), // "error"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 39), // "SevaBookingConformationDataMo..."
QT_MOC_LITERAL(4, 70, 16), // "processSevaTypes"
QT_MOC_LITERAL(5, 87, 9), // "SevaType*"
QT_MOC_LITERAL(6, 97, 14), // "querySevaTypes"
QT_MOC_LITERAL(7, 112, 14), // "querySevaNames"
QT_MOC_LITERAL(8, 127, 35), // "getSevaBookingConformationDat..."
QT_MOC_LITERAL(9, 163, 33), // "SevaBookingConformationDataMo..."
QT_MOC_LITERAL(10, 197, 16) // "sevaBookingModel"

    },
    "SevaTypeNamesDataModel\0error\0\0"
    "SevaBookingConformationDataModelChanged\0"
    "processSevaTypes\0SevaType*\0querySevaTypes\0"
    "querySevaNames\0getSevaBookingConformationDataModel\0"
    "SevaBookingConformationDataModel*\0"
    "sevaBookingModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaTypeNamesDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   51,    2, 0x02 /* Public */,
       7,    0,   52,    2, 0x02 /* Public */,
       8,    0,   53,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 5,    2,

 // methods: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    0x80000000 | 9,

 // properties: name, type, flags
      10, 0x80000000 | 9, 0x0049500b,

 // properties: notify_signal_id
       1,

       0        // eod
};

void SevaTypeNamesDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaTypeNamesDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SevaBookingConformationDataModelChanged(); break;
        case 2: { bool _r = _t->processSevaTypes((*reinterpret_cast< SevaType*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->querySevaTypes();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->querySevaNames();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { SevaBookingConformationDataModel* _r = _t->getSevaBookingConformationDataModel();
            if (_a[0]) *reinterpret_cast< SevaBookingConformationDataModel**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SevaTypeNamesDataModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaTypeNamesDataModel::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SevaTypeNamesDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaTypeNamesDataModel::SevaBookingConformationDataModelChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaBookingConformationDataModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SevaTypeNamesDataModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SevaBookingConformationDataModel**>(_v) = _t->getSevaBookingConformationDataModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SevaTypeNamesDataModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSevaBookingConformationDataModel(*reinterpret_cast< SevaBookingConformationDataModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
void SevaTypeNamesDataModel::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SevaTypeNamesDataModel::SevaBookingConformationDataModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
