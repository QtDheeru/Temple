/****************************************************************************
** Meta object code from reading C++ file 'TrustListModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TrustListModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrustListModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrustListModel_t {
    QByteArrayData data[15];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrustListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrustListModel_t qt_meta_stringdata_TrustListModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TrustListModel"
QT_MOC_LITERAL(1, 15, 28), // "currentConfigLocationChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 26), // "currentDataLocationChanged"
QT_MOC_LITERAL(4, 72, 19), // "currentTrustChanged"
QT_MOC_LITERAL(5, 92, 25), // "showCurrentConfigLocation"
QT_MOC_LITERAL(6, 118, 23), // "showCurrentDataLocation"
QT_MOC_LITERAL(7, 142, 15), // "getDataLocation"
QT_MOC_LITERAL(8, 158, 17), // "getConfigLocation"
QT_MOC_LITERAL(9, 176, 16), // "getTrustListSize"
QT_MOC_LITERAL(10, 193, 18), // "trustCodeForConfig"
QT_MOC_LITERAL(11, 212, 16), // "trustCodeForData"
QT_MOC_LITERAL(12, 229, 12), // "currentTrust"
QT_MOC_LITERAL(13, 242, 9), // "trustList"
QT_MOC_LITERAL(14, 252, 13) // "QList<Trust*>"

    },
    "TrustListModel\0currentConfigLocationChanged\0"
    "\0currentDataLocationChanged\0"
    "currentTrustChanged\0showCurrentConfigLocation\0"
    "showCurrentDataLocation\0getDataLocation\0"
    "getConfigLocation\0getTrustListSize\0"
    "trustCodeForConfig\0trustCodeForData\0"
    "currentTrust\0trustList\0QList<Trust*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrustListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x02 /* Public */,
       8,    0,   60,    2, 0x02 /* Public */,
       9,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Int,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00495003,
      11, QMetaType::QString, 0x00495003,
      12, QMetaType::QString, 0x00495103,
      13, 0x80000000 | 14, 0x00095409,

 // properties: notify_signal_id
       0,
       1,
       2,
       0,

       0        // eod
};

void TrustListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrustListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentConfigLocationChanged(); break;
        case 1: _t->currentDataLocationChanged(); break;
        case 2: _t->currentTrustChanged(); break;
        case 3: _t->showCurrentConfigLocation(); break;
        case 4: _t->showCurrentDataLocation(); break;
        case 5: { QString _r = _t->getDataLocation();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getConfigLocation();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->getTrustListSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrustListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrustListModel::currentConfigLocationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrustListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrustListModel::currentDataLocationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrustListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrustListModel::currentTrustChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Trust*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TrustListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentConfigLocation(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentDataLocation(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->currentTrust(); break;
        case 3: *reinterpret_cast< QList<Trust*>*>(_v) = _t->trustList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TrustListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentConfigLocation(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setCurrentDataLocation(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCurrentTrust(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TrustListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_TrustListModel.data,
    qt_meta_data_TrustListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TrustListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrustListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrustListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int TrustListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TrustListModel::currentConfigLocationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TrustListModel::currentDataLocationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TrustListModel::currentTrustChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
