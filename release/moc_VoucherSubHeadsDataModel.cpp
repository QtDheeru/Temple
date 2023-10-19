/****************************************************************************
** Meta object code from reading C++ file 'VoucherSubHeadsDataModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../VoucherData/SubHead/VoucherSubHeadsDataModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherSubHeadsDataModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherSubHeadsDataModel_t {
    QByteArrayData data[18];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherSubHeadsDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherSubHeadsDataModel_t qt_meta_stringdata_VoucherSubHeadsDataModel = {
    {
QT_MOC_LITERAL(0, 0, 24), // "VoucherSubHeadsDataModel"
QT_MOC_LITERAL(1, 25, 14), // "subcat_Changed"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "subname_Changed"
QT_MOC_LITERAL(4, 57, 12), // "updated_data"
QT_MOC_LITERAL(5, 70, 13), // "mySignalVouch"
QT_MOC_LITERAL(6, 84, 7), // "my_data"
QT_MOC_LITERAL(7, 92, 15), // "addToTableModel"
QT_MOC_LITERAL(8, 108, 13), // "toTableDialog"
QT_MOC_LITERAL(9, 122, 16), // "onUpdated_Failed"
QT_MOC_LITERAL(10, 139, 17), // "onDeletion_Failed"
QT_MOC_LITERAL(11, 157, 17), // "onUpdated_Success"
QT_MOC_LITERAL(12, 175, 18), // "onDeletion_Success"
QT_MOC_LITERAL(13, 194, 16), // "onInsert_Success"
QT_MOC_LITERAL(14, 211, 13), // "onModelDialog"
QT_MOC_LITERAL(15, 225, 11), // "onSelectAll"
QT_MOC_LITERAL(16, 237, 9), // "my_subCat"
QT_MOC_LITERAL(17, 247, 10) // "my_subName"

    },
    "VoucherSubHeadsDataModel\0subcat_Changed\0"
    "\0subname_Changed\0updated_data\0"
    "mySignalVouch\0my_data\0addToTableModel\0"
    "toTableDialog\0onUpdated_Failed\0"
    "onDeletion_Failed\0onUpdated_Success\0"
    "onDeletion_Success\0onInsert_Success\0"
    "onModelDialog\0onSelectAll\0my_subCat\0"
    "my_subName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherSubHeadsDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  118, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    2,   86,    2, 0x06 /* Public */,
       5,    0,   91,    2, 0x06 /* Public */,
       6,    3,   92,    2, 0x06 /* Public */,
       7,    2,   99,    2, 0x06 /* Public */,
       8,    0,  104,    2, 0x06 /* Public */,
       9,    0,  105,    2, 0x06 /* Public */,
      10,    0,  106,    2, 0x06 /* Public */,
      11,    0,  107,    2, 0x06 /* Public */,
      12,    0,  108,    2, 0x06 /* Public */,
      13,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  110,    2, 0x0a /* Public */,
      15,    3,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // properties: name, type, flags
      16, QMetaType::QString, 0x00495003,
      17, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void VoucherSubHeadsDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherSubHeadsDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->subcat_Changed(); break;
        case 1: _t->subname_Changed(); break;
        case 2: _t->updated_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->mySignalVouch(); break;
        case 4: _t->my_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->addToTableModel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->toTableDialog(); break;
        case 7: _t->onUpdated_Failed(); break;
        case 8: _t->onDeletion_Failed(); break;
        case 9: _t->onUpdated_Success(); break;
        case 10: _t->onDeletion_Success(); break;
        case 11: _t->onInsert_Success(); break;
        case 12: _t->onModelDialog(); break;
        case 13: _t->onSelectAll((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::subcat_Changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::subname_Changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::updated_data)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::mySignalVouch)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::my_data)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::addToTableModel)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::toTableDialog)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::onUpdated_Failed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::onDeletion_Failed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::onUpdated_Success)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::onDeletion_Success)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (VoucherSubHeadsDataModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherSubHeadsDataModel::onInsert_Success)) {
                *result = 11;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherSubHeadsDataModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getSub_cat_id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getSub_name(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherSubHeadsDataModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSub_cat_id(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setSub_name(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VoucherSubHeadsDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherSubHeadsDataModel.data,
    qt_meta_data_VoucherSubHeadsDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherSubHeadsDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherSubHeadsDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherSubHeadsDataModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherSubHeadsDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
void VoucherSubHeadsDataModel::subcat_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherSubHeadsDataModel::subname_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VoucherSubHeadsDataModel::updated_data(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VoucherSubHeadsDataModel::mySignalVouch()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VoucherSubHeadsDataModel::my_data(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VoucherSubHeadsDataModel::addToTableModel(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VoucherSubHeadsDataModel::toTableDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VoucherSubHeadsDataModel::onUpdated_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VoucherSubHeadsDataModel::onDeletion_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VoucherSubHeadsDataModel::onUpdated_Success()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VoucherSubHeadsDataModel::onDeletion_Success()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void VoucherSubHeadsDataModel::onInsert_Success()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
