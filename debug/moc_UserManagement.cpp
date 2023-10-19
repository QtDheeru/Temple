/****************************************************************************
** Meta object code from reading C++ file 'UserManagement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/UserManagement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserManagement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserManagement_t {
    QByteArrayData data[19];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserManagement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserManagement_t qt_meta_stringdata_UserManagement = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserManagement"
QT_MOC_LITERAL(1, 15, 9), // "userAdded"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "msg"
QT_MOC_LITERAL(4, 30, 14), // "rolenumchanged"
QT_MOC_LITERAL(5, 45, 18), // "signIn_NameChanged"
QT_MOC_LITERAL(6, 64, 13), // "user_Recieved"
QT_MOC_LITERAL(7, 78, 7), // "rolenum"
QT_MOC_LITERAL(8, 86, 10), // "signInName"
QT_MOC_LITERAL(9, 97, 7), // "addUser"
QT_MOC_LITERAL(10, 105, 4), // "name"
QT_MOC_LITERAL(11, 110, 8), // "lastname"
QT_MOC_LITERAL(12, 119, 6), // "userid"
QT_MOC_LITERAL(13, 126, 8), // "password"
QT_MOC_LITERAL(14, 135, 8), // "userRole"
QT_MOC_LITERAL(15, 144, 4), // "date"
QT_MOC_LITERAL(16, 149, 9), // "authorize"
QT_MOC_LITERAL(17, 159, 8), // "username"
QT_MOC_LITERAL(18, 168, 11) // "signIn_Name"

    },
    "UserManagement\0userAdded\0\0msg\0"
    "rolenumchanged\0signIn_NameChanged\0"
    "user_Recieved\0rolenum\0signInName\0"
    "addUser\0name\0lastname\0userid\0password\0"
    "userRole\0date\0authorize\0username\0"
    "signIn_Name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserManagement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   49,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    6,   54,    2, 0x02 /* Public */,
      16,    2,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,    8,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   13,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00495003,
      18, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void UserManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserManagement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->rolenumchanged(); break;
        case 2: _t->signIn_NameChanged(); break;
        case 3: _t->user_Recieved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->addUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 5: _t->authorize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserManagement::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManagement::userAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserManagement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManagement::rolenumchanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserManagement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserManagement::signIn_NameChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UserManagement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getCurrentRole(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getSignIn_Name(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UserManagement *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentRole(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setSignIn_Name(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UserManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UserManagement.data,
    qt_meta_data_UserManagement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserManagement.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UserManagement::userAdded(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserManagement::rolenumchanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserManagement::signIn_NameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
