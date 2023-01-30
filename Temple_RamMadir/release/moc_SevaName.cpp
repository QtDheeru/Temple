/****************************************************************************
** Meta object code from reading C++ file 'SevaName.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/SevaName.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SevaName.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SevaName_t {
    QByteArrayData data[13];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaName_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaName_t qt_meta_stringdata_SevaName = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SevaName"
QT_MOC_LITERAL(1, 9, 15), // "sevaNameChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "sevaTypeChanged"
QT_MOC_LITERAL(4, 42, 13), // "sevaIdChanged"
QT_MOC_LITERAL(5, 56, 15), // "sevaCostChanged"
QT_MOC_LITERAL(6, 72, 21), // "additionalCostChanged"
QT_MOC_LITERAL(7, 94, 5), // "print"
QT_MOC_LITERAL(8, 100, 8), // "sevaName"
QT_MOC_LITERAL(9, 109, 8), // "sevaType"
QT_MOC_LITERAL(10, 118, 6), // "sevaId"
QT_MOC_LITERAL(11, 125, 8), // "sevaCost"
QT_MOC_LITERAL(12, 134, 14) // "additionalCost"

    },
    "SevaName\0sevaNameChanged\0\0sevaTypeChanged\0"
    "sevaIdChanged\0sevaCostChanged\0"
    "additionalCostChanged\0print\0sevaName\0"
    "sevaType\0sevaId\0sevaCost\0additionalCost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaName[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::Int, 0x00495103,
      10, QMetaType::Int, 0x00495103,
      11, QMetaType::Double, 0x00495103,
      12, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void SevaName::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaName *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sevaNameChanged(); break;
        case 1: _t->sevaTypeChanged(); break;
        case 2: _t->sevaIdChanged(); break;
        case 3: _t->sevaCostChanged(); break;
        case 4: _t->additionalCostChanged(); break;
        case 5: _t->print(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SevaName::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaName::sevaNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SevaName::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaName::sevaTypeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SevaName::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaName::sevaIdChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SevaName::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaName::sevaCostChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SevaName::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SevaName::additionalCostChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SevaName *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sevaName(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->sevaType(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->sevaId(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->sevaCost(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->additionalCost(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SevaName *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSevaName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setSevaType(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setSevaId(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setSevaCost(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setAdditionalCost(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SevaName::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SevaName.data,
    qt_meta_data_SevaName,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SevaName::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SevaName::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SevaName.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SevaName::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SevaName::sevaNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SevaName::sevaTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SevaName::sevaIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SevaName::sevaCostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SevaName::additionalCostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
