/****************************************************************************
** Meta object code from reading C++ file 'VoucherSubHead.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../VoucherData/SubHead/VoucherSubHead.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherSubHead.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherSubHead_t {
    QByteArrayData data[6];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherSubHead_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherSubHead_t qt_meta_stringdata_VoucherSubHead = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VoucherSubHead"
QT_MOC_LITERAL(1, 15, 12), // "vsub_Changed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "vscn_Changed"
QT_MOC_LITERAL(4, 42, 8), // "my_subid"
QT_MOC_LITERAL(5, 51, 7) // "my_vscn"

    },
    "VoucherSubHead\0vsub_Changed\0\0vscn_Changed\0"
    "my_subid\0my_vscn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherSubHead[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00495003,
       5, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void VoucherSubHead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherSubHead *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->vsub_Changed(); break;
        case 1: _t->vscn_Changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherSubHead::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHead::vsub_Changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherSubHead::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHead::vscn_Changed)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherSubHead *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getVSubid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getVscn(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherSubHead *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVSubid(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setVscn(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject VoucherSubHead::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherSubHead.data,
    qt_meta_data_VoucherSubHead,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherSubHead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherSubHead::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherSubHead.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherSubHead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
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
void VoucherSubHead::vsub_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherSubHead::vscn_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE