/****************************************************************************
** Meta object code from reading C++ file 'SevaDetailsTableViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/Reports/SevaDetailsTableViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SevaDetailsTableViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SevaDetailsTableView_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SevaDetailsTableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SevaDetailsTableView_t qt_meta_stringdata_SevaDetailsTableView = {
    {
QT_MOC_LITERAL(0, 0, 20), // "SevaDetailsTableView"
QT_MOC_LITERAL(1, 21, 7), // "getData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14) // "QList<QString>"

    },
    "SevaDetailsTableView\0getData\0\0"
    "QList<QString>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SevaDetailsTableView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,   23,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,

       0        // eod
};

void SevaDetailsTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SevaDetailsTableView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getData((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4])),(*reinterpret_cast< QList<QString>(*)>(_a[5])),(*reinterpret_cast< QList<QString>(*)>(_a[6])),(*reinterpret_cast< QList<QString>(*)>(_a[7])),(*reinterpret_cast< QList<QString>(*)>(_a[8])),(*reinterpret_cast< QList<QString>(*)>(_a[9])),(*reinterpret_cast< QList<QString>(*)>(_a[10])),(*reinterpret_cast< QList<QString>(*)>(_a[11])),(*reinterpret_cast< QList<QString>(*)>(_a[12])),(*reinterpret_cast< QList<QString>(*)>(_a[13])),(*reinterpret_cast< QList<QString>(*)>(_a[14])),(*reinterpret_cast< QList<QString>(*)>(_a[15])),(*reinterpret_cast< QList<QString>(*)>(_a[16])),(*reinterpret_cast< QList<QString>(*)>(_a[17])),(*reinterpret_cast< QList<QString>(*)>(_a[18])),(*reinterpret_cast< QList<QString>(*)>(_a[19])),(*reinterpret_cast< QList<QString>(*)>(_a[20])),(*reinterpret_cast< QList<QString>(*)>(_a[21])),(*reinterpret_cast< QList<QString>(*)>(_a[22])),(*reinterpret_cast< QList<QString>(*)>(_a[23]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 22:
            case 21:
            case 20:
            case 19:
            case 18:
            case 17:
            case 16:
            case 15:
            case 14:
            case 13:
            case 12:
            case 11:
            case 10:
            case 9:
            case 8:
            case 7:
            case 6:
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SevaDetailsTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_SevaDetailsTableView.data,
    qt_meta_data_SevaDetailsTableView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SevaDetailsTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SevaDetailsTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SevaDetailsTableView.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int SevaDetailsTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
