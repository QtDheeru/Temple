/****************************************************************************
** Meta object code from reading C++ file 'VoucherProxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../VoucherProxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoucherProxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoucherProxy_t {
    QByteArrayData data[70];
    char stringdata0[1062];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoucherProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoucherProxy_t qt_meta_stringdata_VoucherProxy = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VoucherProxy"
QT_MOC_LITERAL(1, 13, 31), // "voucherSubHeadTableModelChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 29), // "voucherHeadsTableModelChanged"
QT_MOC_LITERAL(4, 76, 10), // "vouchToQml"
QT_MOC_LITERAL(5, 87, 11), // "a_serial_no"
QT_MOC_LITERAL(6, 99, 11), // "a_voucherId"
QT_MOC_LITERAL(7, 111, 12), // "a_vouch_name"
QT_MOC_LITERAL(8, 124, 9), // "my_update"
QT_MOC_LITERAL(9, 134, 5), // "subid"
QT_MOC_LITERAL(10, 140, 4), // "name"
QT_MOC_LITERAL(11, 145, 8), // "use_Data"
QT_MOC_LITERAL(12, 154, 6), // "subcat"
QT_MOC_LITERAL(13, 161, 7), // "subname"
QT_MOC_LITERAL(14, 169, 9), // "voucherId"
QT_MOC_LITERAL(15, 179, 14), // "serial_Changed"
QT_MOC_LITERAL(16, 194, 13), // "vname_Changed"
QT_MOC_LITERAL(17, 208, 9), // "qmlDialog"
QT_MOC_LITERAL(18, 218, 11), // "proxyUpdate"
QT_MOC_LITERAL(19, 230, 11), // "proxyDelete"
QT_MOC_LITERAL(20, 242, 17), // "addSucsessInProxy"
QT_MOC_LITERAL(21, 260, 17), // "updateFailInProxy"
QT_MOC_LITERAL(22, 278, 20), // "updateSuccessInProxy"
QT_MOC_LITERAL(23, 299, 14), // "listCountToQml"
QT_MOC_LITERAL(24, 314, 8), // "sigToQml"
QT_MOC_LITERAL(25, 323, 18), // "serialErrorInProxy"
QT_MOC_LITERAL(26, 342, 19), // "voucherErrorInProxy"
QT_MOC_LITERAL(27, 362, 20), // "removeSuccessInProxy"
QT_MOC_LITERAL(28, 383, 17), // "removeFailInProxy"
QT_MOC_LITERAL(29, 401, 9), // "updateQml"
QT_MOC_LITERAL(30, 411, 9), // "deleteQml"
QT_MOC_LITERAL(31, 421, 9), // "insertQml"
QT_MOC_LITERAL(32, 431, 14), // "addFailInProxy"
QT_MOC_LITERAL(33, 446, 23), // "voucherNameErrorInProxy"
QT_MOC_LITERAL(34, 470, 18), // "addVoucherMainType"
QT_MOC_LITERAL(35, 489, 20), // "updateVoucherInProxy"
QT_MOC_LITERAL(36, 510, 14), // "onVouchToProxy"
QT_MOC_LITERAL(37, 525, 20), // "removeVoucherInProxy"
QT_MOC_LITERAL(38, 546, 12), // "send_Voucher"
QT_MOC_LITERAL(39, 559, 8), // "set_data"
QT_MOC_LITERAL(40, 568, 10), // "from_Proxy"
QT_MOC_LITERAL(41, 579, 11), // "toDataModel"
QT_MOC_LITERAL(42, 591, 7), // "toMyQml"
QT_MOC_LITERAL(43, 599, 7), // "addToDb"
QT_MOC_LITERAL(44, 607, 10), // "clearProxy"
QT_MOC_LITERAL(45, 618, 10), // "deleteToDb"
QT_MOC_LITERAL(46, 629, 10), // "updateToDb"
QT_MOC_LITERAL(47, 640, 13), // "onProxyDialog"
QT_MOC_LITERAL(48, 654, 12), // "onSigToProxy"
QT_MOC_LITERAL(49, 667, 19), // "onAddSuccessInTable"
QT_MOC_LITERAL(50, 687, 19), // "onUpdateFailInTable"
QT_MOC_LITERAL(51, 707, 22), // "onUpdateSuccessInTable"
QT_MOC_LITERAL(52, 730, 18), // "onListCountToProxy"
QT_MOC_LITERAL(53, 749, 20), // "onSerialErrorInTable"
QT_MOC_LITERAL(54, 770, 21), // "onVoucherErrorInTable"
QT_MOC_LITERAL(55, 792, 22), // "onRemoveSuccessInTable"
QT_MOC_LITERAL(56, 815, 19), // "onRemoveFailInTable"
QT_MOC_LITERAL(57, 835, 17), // "loadTbViewInProxy"
QT_MOC_LITERAL(58, 853, 17), // "rowClickedInProxy"
QT_MOC_LITERAL(59, 871, 3), // "row"
QT_MOC_LITERAL(60, 875, 16), // "onAddFailInTable"
QT_MOC_LITERAL(61, 892, 25), // "onVoucherNameErrorInTable"
QT_MOC_LITERAL(62, 918, 15), // "listAppendProxy"
QT_MOC_LITERAL(63, 934, 9), // "proxyList"
QT_MOC_LITERAL(64, 944, 24), // "voucherSubHeadTableModel"
QT_MOC_LITERAL(65, 969, 26), // "VoucherSubHeadsTableModel*"
QT_MOC_LITERAL(66, 996, 22), // "voucherHeadsTableModel"
QT_MOC_LITERAL(67, 1019, 23), // "VoucherHeadsTableModel*"
QT_MOC_LITERAL(68, 1043, 9), // "my_serial"
QT_MOC_LITERAL(69, 1053, 8) // "my_vname"

    },
    "VoucherProxy\0voucherSubHeadTableModelChanged\0"
    "\0voucherHeadsTableModelChanged\0"
    "vouchToQml\0a_serial_no\0a_voucherId\0"
    "a_vouch_name\0my_update\0subid\0name\0"
    "use_Data\0subcat\0subname\0voucherId\0"
    "serial_Changed\0vname_Changed\0qmlDialog\0"
    "proxyUpdate\0proxyDelete\0addSucsessInProxy\0"
    "updateFailInProxy\0updateSuccessInProxy\0"
    "listCountToQml\0sigToQml\0serialErrorInProxy\0"
    "voucherErrorInProxy\0removeSuccessInProxy\0"
    "removeFailInProxy\0updateQml\0deleteQml\0"
    "insertQml\0addFailInProxy\0"
    "voucherNameErrorInProxy\0addVoucherMainType\0"
    "updateVoucherInProxy\0onVouchToProxy\0"
    "removeVoucherInProxy\0send_Voucher\0"
    "set_data\0from_Proxy\0toDataModel\0toMyQml\0"
    "addToDb\0clearProxy\0deleteToDb\0updateToDb\0"
    "onProxyDialog\0onSigToProxy\0"
    "onAddSuccessInTable\0onUpdateFailInTable\0"
    "onUpdateSuccessInTable\0onListCountToProxy\0"
    "onSerialErrorInTable\0onVoucherErrorInTable\0"
    "onRemoveSuccessInTable\0onRemoveFailInTable\0"
    "loadTbViewInProxy\0rowClickedInProxy\0"
    "row\0onAddFailInTable\0onVoucherNameErrorInTable\0"
    "listAppendProxy\0proxyList\0"
    "voucherSubHeadTableModel\0"
    "VoucherSubHeadsTableModel*\0"
    "voucherHeadsTableModel\0VoucherHeadsTableModel*\0"
    "my_serial\0my_vname"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoucherProxy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       4,  406, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  279,    2, 0x06 /* Public */,
       3,    0,  280,    2, 0x06 /* Public */,
       4,    3,  281,    2, 0x06 /* Public */,
       8,    2,  288,    2, 0x06 /* Public */,
      11,    3,  293,    2, 0x06 /* Public */,
      15,    0,  300,    2, 0x06 /* Public */,
      16,    0,  301,    2, 0x06 /* Public */,
      17,    0,  302,    2, 0x06 /* Public */,
      18,    0,  303,    2, 0x06 /* Public */,
      19,    0,  304,    2, 0x06 /* Public */,
      20,    0,  305,    2, 0x06 /* Public */,
      21,    0,  306,    2, 0x06 /* Public */,
      22,    0,  307,    2, 0x06 /* Public */,
      23,    1,  308,    2, 0x06 /* Public */,
      24,    0,  311,    2, 0x06 /* Public */,
      25,    0,  312,    2, 0x06 /* Public */,
      26,    0,  313,    2, 0x06 /* Public */,
      27,    0,  314,    2, 0x06 /* Public */,
      28,    0,  315,    2, 0x06 /* Public */,
      29,    0,  316,    2, 0x06 /* Public */,
      30,    0,  317,    2, 0x06 /* Public */,
      31,    0,  318,    2, 0x06 /* Public */,
      32,    0,  319,    2, 0x06 /* Public */,
      33,    0,  320,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      34,    3,  321,    2, 0x0a /* Public */,
      35,    3,  328,    2, 0x0a /* Public */,
      36,    3,  335,    2, 0x0a /* Public */,
      37,    1,  342,    2, 0x0a /* Public */,
      38,    1,  345,    2, 0x0a /* Public */,
      39,    1,  348,    2, 0x0a /* Public */,
      40,    2,  351,    2, 0x0a /* Public */,
      41,    0,  356,    2, 0x0a /* Public */,
      42,    3,  357,    2, 0x0a /* Public */,
      43,    3,  364,    2, 0x0a /* Public */,
      44,    0,  371,    2, 0x0a /* Public */,
      45,    3,  372,    2, 0x0a /* Public */,
      46,    3,  379,    2, 0x0a /* Public */,
      47,    0,  386,    2, 0x0a /* Public */,
      48,    0,  387,    2, 0x0a /* Public */,
      49,    0,  388,    2, 0x0a /* Public */,
      50,    0,  389,    2, 0x0a /* Public */,
      51,    0,  390,    2, 0x0a /* Public */,
      52,    1,  391,    2, 0x0a /* Public */,
      53,    0,  394,    2, 0x0a /* Public */,
      54,    0,  395,    2, 0x0a /* Public */,
      55,    0,  396,    2, 0x0a /* Public */,
      56,    0,  397,    2, 0x0a /* Public */,
      57,    0,  398,    2, 0x0a /* Public */,
      58,    1,  399,    2, 0x0a /* Public */,
      60,    0,  402,    2, 0x0a /* Public */,
      61,    0,  403,    2, 0x0a /* Public */,
      62,    0,  404,    2, 0x0a /* Public */,
      63,    0,  405,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      64, 0x80000000 | 65, 0x00495009,
      66, 0x80000000 | 67, 0x00495009,
      68, QMetaType::QString, 0x00495003,
      69, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       5,
       6,

       0        // eod
};

void VoucherProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoucherProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->voucherSubHeadTableModelChanged(); break;
        case 1: _t->voucherHeadsTableModelChanged(); break;
        case 2: _t->vouchToQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->my_update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->use_Data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->serial_Changed(); break;
        case 6: _t->vname_Changed(); break;
        case 7: _t->qmlDialog(); break;
        case 8: _t->proxyUpdate(); break;
        case 9: _t->proxyDelete(); break;
        case 10: _t->addSucsessInProxy(); break;
        case 11: _t->updateFailInProxy(); break;
        case 12: _t->updateSuccessInProxy(); break;
        case 13: _t->listCountToQml((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->sigToQml(); break;
        case 15: _t->serialErrorInProxy(); break;
        case 16: _t->voucherErrorInProxy(); break;
        case 17: _t->removeSuccessInProxy(); break;
        case 18: _t->removeFailInProxy(); break;
        case 19: _t->updateQml(); break;
        case 20: _t->deleteQml(); break;
        case 21: _t->insertQml(); break;
        case 22: _t->addFailInProxy(); break;
        case 23: _t->voucherNameErrorInProxy(); break;
        case 24: _t->addVoucherMainType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 25: _t->updateVoucherInProxy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 26: _t->onVouchToProxy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 27: _t->removeVoucherInProxy((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->send_Voucher((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->set_data((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->from_Proxy((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->toDataModel(); break;
        case 32: _t->toMyQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 33: _t->addToDb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 34: _t->clearProxy(); break;
        case 35: _t->deleteToDb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 36: _t->updateToDb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 37: _t->onProxyDialog(); break;
        case 38: _t->onSigToProxy(); break;
        case 39: _t->onAddSuccessInTable(); break;
        case 40: _t->onUpdateFailInTable(); break;
        case 41: _t->onUpdateSuccessInTable(); break;
        case 42: _t->onListCountToProxy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->onSerialErrorInTable(); break;
        case 44: _t->onVoucherErrorInTable(); break;
        case 45: _t->onRemoveSuccessInTable(); break;
        case 46: _t->onRemoveFailInTable(); break;
        case 47: _t->loadTbViewInProxy(); break;
        case 48: _t->rowClickedInProxy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->onAddFailInTable(); break;
        case 50: _t->onVoucherNameErrorInTable(); break;
        case 51: _t->listAppendProxy(); break;
        case 52: _t->proxyList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::voucherSubHeadTableModelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::voucherHeadsTableModelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::vouchToQml)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::my_update)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::use_Data)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::serial_Changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::vname_Changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::qmlDialog)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::proxyUpdate)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::proxyDelete)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::addSucsessInProxy)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::updateFailInProxy)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::updateSuccessInProxy)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::listCountToQml)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::sigToQml)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::serialErrorInProxy)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::voucherErrorInProxy)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::removeSuccessInProxy)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::removeFailInProxy)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::updateQml)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::deleteQml)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::insertQml)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::addFailInProxy)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (VoucherProxy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoucherProxy::voucherNameErrorInProxy)) {
                *result = 23;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherHeadsTableModel* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherSubHeadsTableModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VoucherProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< VoucherSubHeadsTableModel**>(_v) = _t->voucherSubHeadsTableModel(); break;
        case 1: *reinterpret_cast< VoucherHeadsTableModel**>(_v) = _t->voucherHeadsTableModel(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getSerialno(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getVouchername(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VoucherProxy *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSerialno(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setVouchername(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VoucherProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VoucherProxy.data,
    qt_meta_data_VoucherProxy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VoucherProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoucherProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoucherProxy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VoucherProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
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
void VoucherProxy::voucherSubHeadTableModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VoucherProxy::voucherHeadsTableModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VoucherProxy::vouchToQml(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VoucherProxy::my_update(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VoucherProxy::use_Data(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VoucherProxy::serial_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VoucherProxy::vname_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VoucherProxy::qmlDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VoucherProxy::proxyUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VoucherProxy::proxyDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VoucherProxy::addSucsessInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void VoucherProxy::updateFailInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void VoucherProxy::updateSuccessInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void VoucherProxy::listCountToQml(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void VoucherProxy::sigToQml()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void VoucherProxy::serialErrorInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void VoucherProxy::voucherErrorInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void VoucherProxy::removeSuccessInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void VoucherProxy::removeFailInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void VoucherProxy::updateQml()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void VoucherProxy::deleteQml()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void VoucherProxy::insertQml()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void VoucherProxy::addFailInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void VoucherProxy::voucherNameErrorInProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
