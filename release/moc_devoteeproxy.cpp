/****************************************************************************
** Meta object code from reading C++ file 'devoteeproxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/DevoteeManager/devoteeproxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devoteeproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DevoteeProxy_t {
    QByteArrayData data[11];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DevoteeProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DevoteeProxy_t qt_meta_stringdata_DevoteeProxy = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DevoteeProxy"
QT_MOC_LITERAL(1, 13, 24), // "devoteeTableModelChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "devoteeSearchModelChanged"
QT_MOC_LITERAL(4, 65, 23), // "devoteeDataModelChanged"
QT_MOC_LITERAL(5, 89, 17), // "devoteeTableModel"
QT_MOC_LITERAL(6, 107, 25), // "DevoteeDetailsTableModel*"
QT_MOC_LITERAL(7, 133, 18), // "devoteeSearchModel"
QT_MOC_LITERAL(8, 152, 26), // "DevoteeDetailsSearchModel*"
QT_MOC_LITERAL(9, 179, 16), // "devoteeDataModel"
QT_MOC_LITERAL(10, 196, 23) // "DevoteDetailsDataModel*"

    },
    "DevoteeProxy\0devoteeTableModelChanged\0"
    "\0devoteeSearchModelChanged\0"
    "devoteeDataModelChanged\0devoteeTableModel\0"
    "DevoteeDetailsTableModel*\0devoteeSearchModel\0"
    "DevoteeDetailsSearchModel*\0devoteeDataModel\0"
    "DevoteDetailsDataModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevoteeProxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0049510b,
       7, 0x80000000 | 8, 0x0049510b,
       9, 0x80000000 | 10, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void DevoteeProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DevoteeProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->devoteeTableModelChanged(); break;
        case 1: _t->devoteeSearchModelChanged(); break;
        case 2: _t->devoteeDataModelChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DevoteeProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteeProxy::devoteeTableModelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DevoteeProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteeProxy::devoteeSearchModelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DevoteeProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DevoteeProxy::devoteeDataModelChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevoteDetailsDataModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevoteeDetailsSearchModel* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DevoteeDetailsTableModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DevoteeProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< DevoteeDetailsTableModel**>(_v) = _t->getDevoteeTableModel(); break;
        case 1: *reinterpret_cast< DevoteeDetailsSearchModel**>(_v) = _t->getDevoteeSearchModel(); break;
        case 2: *reinterpret_cast< DevoteDetailsDataModel**>(_v) = _t->getDevoteeDataModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DevoteeProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDevoteeTableModel(*reinterpret_cast< DevoteeDetailsTableModel**>(_v)); break;
        case 1: _t->setDevoteeSearchModel(*reinterpret_cast< DevoteeDetailsSearchModel**>(_v)); break;
        case 2: _t->setDevoteeDataModel(*reinterpret_cast< DevoteDetailsDataModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DevoteeProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DevoteeProxy.data,
    qt_meta_data_DevoteeProxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DevoteeProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DevoteeProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DevoteeProxy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DevoteeProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DevoteeProxy::devoteeTableModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DevoteeProxy::devoteeSearchModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DevoteeProxy::devoteeDataModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
