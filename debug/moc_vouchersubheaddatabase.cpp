/****************************************************************************
** Meta object code from reading C++ file 'vouchersubheaddatabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../VoucherData/SubHead/vouchersubheaddatabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vouchersubheaddatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherSubheadDatabase_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherSubheadDatabase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherSubheadDatabase_t qt_meta_stringdata_VoucherSubheadDatabase = {
    {
QT_MOC_LITERAL(0, 0, 22), // "VoucherSubheadDatabase"
QT_MOC_LITERAL(1, 23, 14), // "mySelectSignal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 13), // "toModelDialog"
QT_MOC_LITERAL(4, 53, 13), // "update_Failed"
QT_MOC_LITERAL(5, 67, 15) // "deletion_Failed"

    },
    "VoucherSubheadDatabase\0mySelectSignal\0"
    "\0toModelDialog\0update_Failed\0"
    "deletion_Failed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherSubheadDatabase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       3,    0,   41,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VoucherSubheadDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherSubheadDatabase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mySelectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->toModelDialog(); break;
        case 2: _t->update_Failed(); break;
        case 3: _t->deletion_Failed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherSubheadDatabase::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubheadDatabase::mySelectSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherSubheadDatabase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubheadDatabase::toModelDialog)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherSubheadDatabase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubheadDatabase::update_Failed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherSubheadDatabase::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubheadDatabase::deletion_Failed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VoucherSubheadDatabase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherSubheadDatabase.data,
    qt_meta_data_VoucherSubheadDatabase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherSubheadDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherSubheadDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherSubheadDatabase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherSubheadDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VoucherSubheadDatabase::mySelectSignal(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VoucherSubheadDatabase::toModelDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VoucherSubheadDatabase::update_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VoucherSubheadDatabase::deletion_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
