/****************************************************************************
** Meta object code from reading C++ file 'VoucherSubHeadsTableModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../VoucherData/SubHead/VoucherSubHeadsTableModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherSubHeadsTableModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherSubHeadsTableModel_t {
    QByteArrayData data[15];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherSubHeadsTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherSubHeadsTableModel_t qt_meta_stringdata_VoucherSubHeadsTableModel = {
    {
QT_MOC_LITERAL(0, 0, 25), // "VoucherSubHeadsTableModel"
QT_MOC_LITERAL(1, 26, 10), // "row_Signal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "toMyProxy"
QT_MOC_LITERAL(4, 48, 13), // "toProxyDialog"
QT_MOC_LITERAL(5, 62, 14), // "toFailedUpdate"
QT_MOC_LITERAL(6, 77, 13), // "toTableDelete"
QT_MOC_LITERAL(7, 91, 18), // "UpdateSuccessProxy"
QT_MOC_LITERAL(8, 110, 21), // "deletion_SuccessProxy"
QT_MOC_LITERAL(9, 132, 19), // "Insert_SuccessProxy"
QT_MOC_LITERAL(10, 152, 8), // "row_Slot"
QT_MOC_LITERAL(11, 161, 6), // "fromTm"
QT_MOC_LITERAL(12, 168, 10), // "addToTable"
QT_MOC_LITERAL(13, 179, 17), // "onAddToTableModel"
QT_MOC_LITERAL(14, 197, 13) // "onTableDialog"

    },
    "VoucherSubHeadsTableModel\0row_Signal\0"
    "\0toMyProxy\0toProxyDialog\0toFailedUpdate\0"
    "toTableDelete\0UpdateSuccessProxy\0"
    "deletion_SuccessProxy\0Insert_SuccessProxy\0"
    "row_Slot\0fromTm\0addToTable\0onAddToTableModel\0"
    "onTableDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherSubHeadsTableModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       3,    3,   84,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   97,    2, 0x0a /* Public */,
      11,    3,  102,    2, 0x0a /* Public */,
      12,    3,  109,    2, 0x0a /* Public */,
      13,    2,  116,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void VoucherSubHeadsTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherSubHeadsTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->row_Signal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->toMyProxy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->toProxyDialog(); break;
        case 3: _t->toFailedUpdate(); break;
        case 4: _t->toTableDelete(); break;
        case 5: _t->UpdateSuccessProxy(); break;
        case 6: _t->deletion_SuccessProxy(); break;
        case 7: _t->Insert_SuccessProxy(); break;
        case 8: _t->row_Slot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->fromTm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->addToTable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->onAddToTableModel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->onTableDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherSubHeadsTableModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::row_Signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::toMyProxy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::toProxyDialog)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::toFailedUpdate)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::toTableDelete)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::UpdateSuccessProxy)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::deletion_SuccessProxy)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsTableModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsTableModel::Insert_SuccessProxy)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VoucherSubHeadsTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_VoucherSubHeadsTableModel.data,
    qt_meta_data_VoucherSubHeadsTableModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherSubHeadsTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherSubHeadsTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherSubHeadsTableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int VoucherSubHeadsTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void VoucherSubHeadsTableModel::row_Signal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VoucherSubHeadsTableModel::toMyProxy(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VoucherSubHeadsTableModel::toProxyDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VoucherSubHeadsTableModel::toFailedUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VoucherSubHeadsTableModel::toTableDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VoucherSubHeadsTableModel::UpdateSuccessProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VoucherSubHeadsTableModel::deletion_SuccessProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VoucherSubHeadsTableModel::Insert_SuccessProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
