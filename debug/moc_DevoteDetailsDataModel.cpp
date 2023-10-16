/****************************************************************************
** Meta object code from reading C++ file 'DevoteDetailsDataModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/DevoteeManager/DevoteDetailsDataModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DevoteDetailsDataModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DevoteDetailsDataModel_t {
    QByteArrayData data[19];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DevoteDetailsDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DevoteDetailsDataModel_t qt_meta_stringdata_DevoteDetailsDataModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "DevoteDetailsDataModel"
QT_MOC_LITERAL(1, 23, 12), // "devoteeAdded"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "devoteeUpdated"
QT_MOC_LITERAL(4, 52, 12), // "updatedIndex"
QT_MOC_LITERAL(5, 65, 14), // "devoteeDeleted"
QT_MOC_LITERAL(6, 80, 10), // "getDevotee"
QT_MOC_LITERAL(7, 91, 21), // "DevotePersnalDetails*"
QT_MOC_LITERAL(8, 113, 5), // "index"
QT_MOC_LITERAL(9, 119, 10), // "addDevotee"
QT_MOC_LITERAL(10, 130, 7), // "devotee"
QT_MOC_LITERAL(11, 138, 18), // "addDevoteeJSObject"
QT_MOC_LITERAL(12, 157, 3), // "map"
QT_MOC_LITERAL(13, 161, 21), // "updateDevoteeJSObject"
QT_MOC_LITERAL(14, 183, 21), // "deleteDevoteeJSObject"
QT_MOC_LITERAL(15, 205, 13), // "updateDevotee"
QT_MOC_LITERAL(16, 219, 13), // "deleteDevotee"
QT_MOC_LITERAL(17, 233, 9), // "lastError"
QT_MOC_LITERAL(18, 243, 8) // "printAll"

    },
    "DevoteDetailsDataModel\0devoteeAdded\0"
    "\0devoteeUpdated\0updatedIndex\0"
    "devoteeDeleted\0getDevotee\0"
    "DevotePersnalDetails*\0index\0addDevotee\0"
    "devotee\0addDevoteeJSObject\0map\0"
    "updateDevoteeJSObject\0deleteDevoteeJSObject\0"
    "updateDevotee\0deleteDevotee\0lastError\0"
    "printAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevoteDetailsDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   81,    2, 0x02 /* Public */,
       9,    1,   84,    2, 0x02 /* Public */,
      11,    1,   87,    2, 0x02 /* Public */,
      13,    1,   90,    2, 0x02 /* Public */,
      14,    1,   93,    2, 0x02 /* Public */,
      15,    1,   96,    2, 0x02 /* Public */,
      16,    1,   99,    2, 0x02 /* Public */,
      17,    0,  102,    2, 0x02 /* Public */,
      18,    0,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

 // methods: parameters
    0x80000000 | 7, QMetaType::Int,    8,
    QMetaType::Bool, 0x80000000 | 7,   10,
    QMetaType::Bool, QMetaType::QVariantMap,   12,
    QMetaType::Bool, QMetaType::QVariantMap,   12,
    QMetaType::Bool, QMetaType::QVariantMap,   12,
    QMetaType::Bool, 0x80000000 | 7,   10,
    QMetaType::Bool, 0x80000000 | 7,   10,
    QMetaType::QString,
    QMetaType::Bool,

       0        // eod
};

void DevoteDetailsDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DevoteDetailsDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->devoteeAdded(); break;
        case 1: _t->devoteeUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->devoteeDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { DevotePersnalDetails* _r = _t->getDevotee((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DevotePersnalDetails**>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->addDevotee((*reinterpret_cast< DevotePersnalDetails*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->addDevoteeJSObject((*reinterpret_cast< QVariantMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->updateDevoteeJSObject((*reinterpret_cast< QVariantMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->deleteDevoteeJSObject((*reinterpret_cast< QVariantMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->updateDevotee((*reinterpret_cast< DevotePersnalDetails*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->deleteDevotee((*reinterpret_cast< DevotePersnalDetails*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->lastError();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->printAll();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevotePersnalDetails* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevotePersnalDetails* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevotePersnalDetails* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DevoteDetailsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteDetailsDataModel::devoteeAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DevoteDetailsDataModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteDetailsDataModel::devoteeUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DevoteDetailsDataModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteDetailsDataModel::devoteeDeleted)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DevoteDetailsDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DevoteDetailsDataModel.data,
    qt_meta_data_DevoteDetailsDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DevoteDetailsDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DevoteDetailsDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DevoteDetailsDataModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DevoteDetailsDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void DevoteDetailsDataModel::devoteeAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DevoteDetailsDataModel::devoteeUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DevoteDetailsDataModel::devoteeDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
