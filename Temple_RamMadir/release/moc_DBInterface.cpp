/****************************************************************************
** Meta object code from reading C++ file 'DBInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../model/DBInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBInterface_t {
    QByteArrayData data[153];
    char stringdata0[2805];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBInterface_t qt_meta_stringdata_DBInterface = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DBInterface"
QT_MOC_LITERAL(1, 12, 17), // "send_seva_details"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "seva_Name"
QT_MOC_LITERAL(4, 41, 14), // "modifying_seva"
QT_MOC_LITERAL(5, 56, 9), // "seva_type"
QT_MOC_LITERAL(6, 66, 14), // "QList<QString>"
QT_MOC_LITERAL(7, 81, 10), // "s_type_sig"
QT_MOC_LITERAL(8, 92, 11), // "get_data_db"
QT_MOC_LITERAL(9, 104, 14), // "forFUllDetails"
QT_MOC_LITERAL(10, 119, 17), // "forlasttenDetails"
QT_MOC_LITERAL(11, 137, 13), // "persondetails"
QT_MOC_LITERAL(12, 151, 11), // "sevadetails"
QT_MOC_LITERAL(13, 163, 17), // "seva_types_adding"
QT_MOC_LITERAL(14, 181, 8), // "sevaName"
QT_MOC_LITERAL(15, 190, 8), // "sevaname"
QT_MOC_LITERAL(16, 199, 13), // "mob_num_there"
QT_MOC_LITERAL(17, 213, 17), // "mob_num_Not_there"
QT_MOC_LITERAL(18, 231, 9), // "gotraList"
QT_MOC_LITERAL(19, 241, 8), // "bankList"
QT_MOC_LITERAL(20, 250, 19), // "variable_sevacharge"
QT_MOC_LITERAL(21, 270, 16), // "fixed_sevacharge"
QT_MOC_LITERAL(22, 287, 25), // "setting_fixed_seva_charge"
QT_MOC_LITERAL(23, 313, 17), // "get_receiptnumber"
QT_MOC_LITERAL(24, 331, 14), // "booking_report"
QT_MOC_LITERAL(25, 346, 21), // "BookingReportElement*"
QT_MOC_LITERAL(26, 368, 14), // "account_report"
QT_MOC_LITERAL(27, 383, 21), // "AccountReportElement*"
QT_MOC_LITERAL(28, 405, 25), // "account_report_Date_Range"
QT_MOC_LITERAL(29, 431, 30), // "AccountReportDateRangeElement*"
QT_MOC_LITERAL(30, 462, 25), // "booking_report_Date_Range"
QT_MOC_LITERAL(31, 488, 30), // "BookingReportDateRangeElement*"
QT_MOC_LITERAL(32, 519, 26), // "account_report_Month_Range"
QT_MOC_LITERAL(33, 546, 31), // "AccountReportMonthRangeElement*"
QT_MOC_LITERAL(34, 578, 26), // "booking_report_Month_Range"
QT_MOC_LITERAL(35, 605, 31), // "BookingReportMonthRangeElement*"
QT_MOC_LITERAL(36, 637, 14), // "voucher_report"
QT_MOC_LITERAL(37, 652, 15), // "VoucherElement*"
QT_MOC_LITERAL(38, 668, 16), // "correct_password"
QT_MOC_LITERAL(39, 685, 7), // "success"
QT_MOC_LITERAL(40, 693, 9), // "wrongCred"
QT_MOC_LITERAL(41, 703, 22), // "show_username_password"
QT_MOC_LITERAL(42, 726, 17), // "sucessfully_added"
QT_MOC_LITERAL(43, 744, 12), // "sendSevaType"
QT_MOC_LITERAL(44, 757, 9), // "SevaType*"
QT_MOC_LITERAL(45, 767, 12), // "sendSevaName"
QT_MOC_LITERAL(46, 780, 9), // "SevaName*"
QT_MOC_LITERAL(47, 790, 18), // "sendOneSevaBooking"
QT_MOC_LITERAL(48, 809, 19), // "SevaBookingElement*"
QT_MOC_LITERAL(49, 829, 23), // "sendoneByoneSevaBooking"
QT_MOC_LITERAL(50, 853, 19), // "setGrandTotalToZero"
QT_MOC_LITERAL(51, 873, 13), // "add_seva_type"
QT_MOC_LITERAL(52, 887, 9), // "seva_code"
QT_MOC_LITERAL(53, 897, 15), // "seva_adder_name"
QT_MOC_LITERAL(54, 913, 14), // "modify_db_type"
QT_MOC_LITERAL(55, 928, 9), // "delete_db"
QT_MOC_LITERAL(56, 938, 14), // "modify_db_seva"
QT_MOC_LITERAL(57, 953, 13), // "delete_sevadb"
QT_MOC_LITERAL(58, 967, 16), // "insertSevaBooked"
QT_MOC_LITERAL(59, 984, 8), // "sevaType"
QT_MOC_LITERAL(60, 993, 9), // "reference"
QT_MOC_LITERAL(61, 1003, 7), // "address"
QT_MOC_LITERAL(62, 1011, 7), // "momento"
QT_MOC_LITERAL(63, 1019, 19), // "insertVoucherIssued"
QT_MOC_LITERAL(64, 1039, 13), // "check_name_db"
QT_MOC_LITERAL(65, 1053, 8), // "check_db"
QT_MOC_LITERAL(66, 1062, 11), // "addsevaname"
QT_MOC_LITERAL(67, 1074, 19), // "to_persondetails_db"
QT_MOC_LITERAL(68, 1094, 28), // "check_sevaname_allreadyexist"
QT_MOC_LITERAL(69, 1123, 25), // "seva_modification_testing"
QT_MOC_LITERAL(70, 1149, 17), // "combobox_sevatype"
QT_MOC_LITERAL(71, 1167, 7), // "getdata"
QT_MOC_LITERAL(72, 1175, 12), // "dbtable_view"
QT_MOC_LITERAL(73, 1188, 9), // "getDbData"
QT_MOC_LITERAL(74, 1198, 16), // "getpersondetails"
QT_MOC_LITERAL(75, 1215, 14), // "getsevadetails"
QT_MOC_LITERAL(76, 1230, 27), // "canceleDatasevabookingentry"
QT_MOC_LITERAL(77, 1258, 4), // "note"
QT_MOC_LITERAL(78, 1263, 25), // "get_sevabooking_modifying"
QT_MOC_LITERAL(79, 1289, 9), // "seva_name"
QT_MOC_LITERAL(80, 1299, 27), // "table_view_forlast_ten_tran"
QT_MOC_LITERAL(81, 1327, 13), // "print_data_db"
QT_MOC_LITERAL(82, 1341, 9), // "seva_Type"
QT_MOC_LITERAL(83, 1351, 16), // "seva_type_adding"
QT_MOC_LITERAL(84, 1368, 16), // "seva_name_adding"
QT_MOC_LITERAL(85, 1385, 5), // "sevaT"
QT_MOC_LITERAL(86, 1391, 21), // "mobileNumberSearching"
QT_MOC_LITERAL(87, 1413, 21), // "DevotePersnalDetails*"
QT_MOC_LITERAL(88, 1435, 10), // "gotra_list"
QT_MOC_LITERAL(89, 1446, 19), // "Checking_sevacharge"
QT_MOC_LITERAL(90, 1466, 19), // "receipt_no_printing"
QT_MOC_LITERAL(91, 1486, 29), // "booking_report_cdate_function"
QT_MOC_LITERAL(92, 1516, 33), // "booking_report_dataRange_func..."
QT_MOC_LITERAL(93, 1550, 30), // "booking_report_cmonth_function"
QT_MOC_LITERAL(94, 1581, 41), // "booking_report_eachDateDataRa..."
QT_MOC_LITERAL(95, 1623, 49), // "booking_report_eachDateDataRa..."
QT_MOC_LITERAL(96, 1673, 33), // "booking_report_eachMonth_func..."
QT_MOC_LITERAL(97, 1707, 4), // "SEVA"
QT_MOC_LITERAL(98, 1712, 4), // "TYPE"
QT_MOC_LITERAL(99, 1717, 5), // "month"
QT_MOC_LITERAL(100, 1723, 4), // "year"
QT_MOC_LITERAL(101, 1728, 29), // "account_report_cdate_function"
QT_MOC_LITERAL(102, 1758, 33), // "account_report_dataRange_func..."
QT_MOC_LITERAL(103, 1792, 41), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(104, 1834, 30), // "account_report_cmonth_function"
QT_MOC_LITERAL(105, 1865, 33), // "account_report_eachMonth_func..."
QT_MOC_LITERAL(106, 1899, 49), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(107, 1949, 54), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(108, 2004, 29), // "voucher_report_cdate_function"
QT_MOC_LITERAL(109, 2034, 30), // "voucher_report_cmonth_function"
QT_MOC_LITERAL(110, 2065, 33), // "voucher_report_dataRange_func..."
QT_MOC_LITERAL(111, 2099, 14), // "signin_clicked"
QT_MOC_LITERAL(112, 2114, 12), // "old_password"
QT_MOC_LITERAL(113, 2127, 15), // "l_userfirstname"
QT_MOC_LITERAL(114, 2143, 14), // "l_userlastname"
QT_MOC_LITERAL(115, 2158, 22), // "add_new_signin_details"
QT_MOC_LITERAL(116, 2181, 20), // "geting_signInDetails"
QT_MOC_LITERAL(117, 2202, 21), // "QList<SigninDetails*>"
QT_MOC_LITERAL(118, 2224, 28), // "delete_selected_LoginDetails"
QT_MOC_LITERAL(119, 2253, 28), // "modify_selected_LoginDetails"
QT_MOC_LITERAL(120, 2282, 20), // "getMasterCredentials"
QT_MOC_LITERAL(121, 2303, 23), // "updateMasterCredentials"
QT_MOC_LITERAL(122, 2327, 9), // "bank_list"
QT_MOC_LITERAL(123, 2337, 21), // "modify_person_details"
QT_MOC_LITERAL(124, 2359, 22), // "printWithReceiptNumber"
QT_MOC_LITERAL(125, 2382, 21), // "QList<print_details*>"
QT_MOC_LITERAL(126, 2404, 13), // "receiptNumber"
QT_MOC_LITERAL(127, 2418, 12), // "NumberToWord"
QT_MOC_LITERAL(128, 2431, 6), // "number"
QT_MOC_LITERAL(129, 2438, 16), // "checkCredentials"
QT_MOC_LITERAL(130, 2455, 6), // "userID"
QT_MOC_LITERAL(131, 2462, 4), // "pass"
QT_MOC_LITERAL(132, 2467, 13), // "getNextSevaId"
QT_MOC_LITERAL(133, 2481, 12), // "qrySevaDates"
QT_MOC_LITERAL(134, 2494, 24), // "qrySevabookingBySevaDate"
QT_MOC_LITERAL(135, 2519, 25), // "qrySevabookingByDateRange"
QT_MOC_LITERAL(136, 2545, 13), // "querySevaType"
QT_MOC_LITERAL(137, 2559, 14), // "querySevaNames"
QT_MOC_LITERAL(138, 2574, 13), // "qryNakshatras"
QT_MOC_LITERAL(139, 2588, 10), // "qryGothras"
QT_MOC_LITERAL(140, 2599, 11), // "qryBankList"
QT_MOC_LITERAL(141, 2611, 21), // "readSevaNamesFromJson"
QT_MOC_LITERAL(142, 2633, 21), // "readSevaTypesFromJson"
QT_MOC_LITERAL(143, 2655, 16), // "getPersonDetails"
QT_MOC_LITERAL(144, 2672, 9), // "person_id"
QT_MOC_LITERAL(145, 2682, 8), // "saveData"
QT_MOC_LITERAL(146, 2691, 19), // "insertPersonDetails"
QT_MOC_LITERAL(147, 2711, 12), // "devoteMobile"
QT_MOC_LITERAL(148, 2724, 10), // "devoteName"
QT_MOC_LITERAL(149, 2735, 15), // "devoteNakshatra"
QT_MOC_LITERAL(150, 2751, 11), // "devoteGotra"
QT_MOC_LITERAL(151, 2763, 20), // "getLastReceiptNumber"
QT_MOC_LITERAL(152, 2784, 20) // "getLastVoucherNumber"

    },
    "DBInterface\0send_seva_details\0\0seva_Name\0"
    "modifying_seva\0seva_type\0QList<QString>\0"
    "s_type_sig\0get_data_db\0forFUllDetails\0"
    "forlasttenDetails\0persondetails\0"
    "sevadetails\0seva_types_adding\0sevaName\0"
    "sevaname\0mob_num_there\0mob_num_Not_there\0"
    "gotraList\0bankList\0variable_sevacharge\0"
    "fixed_sevacharge\0setting_fixed_seva_charge\0"
    "get_receiptnumber\0booking_report\0"
    "BookingReportElement*\0account_report\0"
    "AccountReportElement*\0account_report_Date_Range\0"
    "AccountReportDateRangeElement*\0"
    "booking_report_Date_Range\0"
    "BookingReportDateRangeElement*\0"
    "account_report_Month_Range\0"
    "AccountReportMonthRangeElement*\0"
    "booking_report_Month_Range\0"
    "BookingReportMonthRangeElement*\0"
    "voucher_report\0VoucherElement*\0"
    "correct_password\0success\0wrongCred\0"
    "show_username_password\0sucessfully_added\0"
    "sendSevaType\0SevaType*\0sendSevaName\0"
    "SevaName*\0sendOneSevaBooking\0"
    "SevaBookingElement*\0sendoneByoneSevaBooking\0"
    "setGrandTotalToZero\0add_seva_type\0"
    "seva_code\0seva_adder_name\0modify_db_type\0"
    "delete_db\0modify_db_seva\0delete_sevadb\0"
    "insertSevaBooked\0sevaType\0reference\0"
    "address\0momento\0insertVoucherIssued\0"
    "check_name_db\0check_db\0addsevaname\0"
    "to_persondetails_db\0check_sevaname_allreadyexist\0"
    "seva_modification_testing\0combobox_sevatype\0"
    "getdata\0dbtable_view\0getDbData\0"
    "getpersondetails\0getsevadetails\0"
    "canceleDatasevabookingentry\0note\0"
    "get_sevabooking_modifying\0seva_name\0"
    "table_view_forlast_ten_tran\0print_data_db\0"
    "seva_Type\0seva_type_adding\0seva_name_adding\0"
    "sevaT\0mobileNumberSearching\0"
    "DevotePersnalDetails*\0gotra_list\0"
    "Checking_sevacharge\0receipt_no_printing\0"
    "booking_report_cdate_function\0"
    "booking_report_dataRange_function\0"
    "booking_report_cmonth_function\0"
    "booking_report_eachDateDataRange_function\0"
    "booking_report_eachDateDataRangeForMonth_function\0"
    "booking_report_eachMonth_function\0"
    "SEVA\0TYPE\0month\0year\0account_report_cdate_function\0"
    "account_report_dataRange_function\0"
    "account_report_eachDateDataRange_function\0"
    "account_report_cmonth_function\0"
    "account_report_eachMonth_function\0"
    "account_report_eachDateDataRangeForMonth_function\0"
    "account_report_eachDateDataRangeForWholeMonth_function\0"
    "voucher_report_cdate_function\0"
    "voucher_report_cmonth_function\0"
    "voucher_report_dataRange_function\0"
    "signin_clicked\0old_password\0l_userfirstname\0"
    "l_userlastname\0add_new_signin_details\0"
    "geting_signInDetails\0QList<SigninDetails*>\0"
    "delete_selected_LoginDetails\0"
    "modify_selected_LoginDetails\0"
    "getMasterCredentials\0updateMasterCredentials\0"
    "bank_list\0modify_person_details\0"
    "printWithReceiptNumber\0QList<print_details*>\0"
    "receiptNumber\0NumberToWord\0number\0"
    "checkCredentials\0userID\0pass\0getNextSevaId\0"
    "qrySevaDates\0qrySevabookingBySevaDate\0"
    "qrySevabookingByDateRange\0querySevaType\0"
    "querySevaNames\0qryNakshatras\0qryGothras\0"
    "qryBankList\0readSevaNamesFromJson\0"
    "readSevaTypesFromJson\0getPersonDetails\0"
    "person_id\0saveData\0insertPersonDetails\0"
    "devoteMobile\0devoteName\0devoteNakshatra\0"
    "devoteGotra\0getLastReceiptNumber\0"
    "getLastVoucherNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     118,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      39,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  604,    2, 0x06 /* Public */,
       3,    8,  609,    2, 0x06 /* Public */,
       4,    9,  626,    2, 0x06 /* Public */,
       5,    1,  645,    2, 0x06 /* Public */,
       1,    3,  648,    2, 0x06 /* Public */,
       7,    1,  655,    2, 0x06 /* Public */,
       8,    4,  658,    2, 0x06 /* Public */,
       9,   23,  667,    2, 0x06 /* Public */,
      10,   17,  714,    2, 0x06 /* Public */,
      11,    6,  749,    2, 0x06 /* Public */,
      12,    2,  762,    2, 0x06 /* Public */,
      13,    1,  767,    2, 0x06 /* Public */,
      14,    1,  770,    2, 0x06 /* Public */,
      15,    9,  773,    2, 0x06 /* Public */,
      16,    4,  792,    2, 0x06 /* Public */,
      17,    0,  801,    2, 0x06 /* Public */,
      18,    1,  802,    2, 0x06 /* Public */,
      19,    1,  805,    2, 0x06 /* Public */,
      20,    0,  808,    2, 0x06 /* Public */,
      21,    1,  809,    2, 0x06 /* Public */,
      22,    1,  812,    2, 0x06 /* Public */,
      23,    1,  815,    2, 0x06 /* Public */,
      24,    1,  818,    2, 0x06 /* Public */,
      26,    1,  821,    2, 0x06 /* Public */,
      28,    1,  824,    2, 0x06 /* Public */,
      30,    1,  827,    2, 0x06 /* Public */,
      32,    1,  830,    2, 0x06 /* Public */,
      34,    1,  833,    2, 0x06 /* Public */,
      36,    1,  836,    2, 0x06 /* Public */,
      38,    1,  839,    2, 0x06 /* Public */,
      39,    0,  842,    2, 0x06 /* Public */,
      40,    0,  843,    2, 0x06 /* Public */,
      41,    2,  844,    2, 0x06 /* Public */,
      42,    0,  849,    2, 0x06 /* Public */,
      43,    1,  850,    2, 0x06 /* Public */,
      45,    1,  853,    2, 0x06 /* Public */,
      47,    1,  856,    2, 0x06 /* Public */,
      49,    1,  859,    2, 0x06 /* Public */,
      50,    0,  862,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      51,    3,  863,    2, 0x0a /* Public */,
      54,    5,  870,    2, 0x0a /* Public */,
      55,    1,  881,    2, 0x0a /* Public */,
      56,    9,  884,    2, 0x0a /* Public */,
      57,    2,  903,    2, 0x0a /* Public */,
      58,   20,  908,    2, 0x0a /* Public */,
      58,   19,  949,    2, 0x2a /* Public | MethodCloned */,
      58,   18,  988,    2, 0x2a /* Public | MethodCloned */,
      58,   17, 1025,    2, 0x2a /* Public | MethodCloned */,
      63,    1, 1060,    2, 0x0a /* Public */,
      64,    8, 1063,    2, 0x0a /* Public */,
      65,    3, 1080,    2, 0x0a /* Public */,
      66,    8, 1087,    2, 0x0a /* Public */,
      67,   10, 1104,    2, 0x0a /* Public */,
      68,    8, 1125,    2, 0x0a /* Public */,
      69,   11, 1142,    2, 0x0a /* Public */,
      70,    0, 1165,    2, 0x0a /* Public */,
      71,    0, 1166,    2, 0x0a /* Public */,
      72,    0, 1167,    2, 0x0a /* Public */,
      73,    0, 1168,    2, 0x0a /* Public */,
      74,    1, 1169,    2, 0x0a /* Public */,
      75,    1, 1172,    2, 0x0a /* Public */,
      76,    3, 1175,    2, 0x0a /* Public */,
      78,   11, 1182,    2, 0x0a /* Public */,
      80,    0, 1205,    2, 0x0a /* Public */,
      81,    1, 1206,    2, 0x0a /* Public */,
      83,    0, 1209,    2, 0x0a /* Public */,
      84,    1, 1210,    2, 0x0a /* Public */,
      86,    1, 1213,    2, 0x0a /* Public */,
      88,    0, 1216,    2, 0x0a /* Public */,
      89,    1, 1217,    2, 0x0a /* Public */,
      90,    0, 1220,    2, 0x0a /* Public */,
      91,    3, 1221,    2, 0x0a /* Public */,
      92,    4, 1228,    2, 0x0a /* Public */,
      93,    4, 1237,    2, 0x0a /* Public */,
      94,    4, 1246,    2, 0x0a /* Public */,
      95,    4, 1255,    2, 0x0a /* Public */,
      96,    4, 1264,    2, 0x0a /* Public */,
     101,    3, 1273,    2, 0x0a /* Public */,
     102,    4, 1280,    2, 0x0a /* Public */,
     103,    4, 1289,    2, 0x0a /* Public */,
     104,    4, 1298,    2, 0x0a /* Public */,
     105,    4, 1307,    2, 0x0a /* Public */,
     106,    4, 1316,    2, 0x0a /* Public */,
     107,    4, 1325,    2, 0x0a /* Public */,
     108,    3, 1334,    2, 0x0a /* Public */,
     109,    4, 1341,    2, 0x0a /* Public */,
     110,    4, 1350,    2, 0x0a /* Public */,
     111,    3, 1359,    2, 0x0a /* Public */,
     112,    2, 1366,    2, 0x0a /* Public */,
     115,    5, 1371,    2, 0x0a /* Public */,
     116,    0, 1382,    2, 0x0a /* Public */,
     118,    1, 1383,    2, 0x0a /* Public */,
     119,    6, 1386,    2, 0x0a /* Public */,
     120,    0, 1399,    2, 0x0a /* Public */,
     121,    4, 1400,    2, 0x0a /* Public */,
     122,    0, 1409,    2, 0x0a /* Public */,
     123,    5, 1410,    2, 0x0a /* Public */,
     124,    1, 1421,    2, 0x0a /* Public */,
     127,    1, 1424,    2, 0x0a /* Public */,
     129,    2, 1427,    2, 0x0a /* Public */,
     132,    0, 1432,    2, 0x0a /* Public */,
     133,    0, 1433,    2, 0x0a /* Public */,
     134,    1, 1434,    2, 0x0a /* Public */,
     135,    2, 1437,    2, 0x0a /* Public */,
     136,    0, 1442,    2, 0x0a /* Public */,
     137,    0, 1443,    2, 0x0a /* Public */,
     138,    0, 1444,    2, 0x0a /* Public */,
     139,    0, 1445,    2, 0x0a /* Public */,
     140,    0, 1446,    2, 0x0a /* Public */,
      51,    1, 1447,    2, 0x0a /* Public */,
      66,    1, 1450,    2, 0x0a /* Public */,
     141,    0, 1453,    2, 0x0a /* Public */,
     142,    0, 1454,    2, 0x0a /* Public */,
     143,    1, 1455,    2, 0x0a /* Public */,
     145,    1, 1458,    2, 0x0a /* Public */,
     146,    4, 1461,    2, 0x0a /* Public */,
     151,    0, 1470,    2, 0x0a /* Public */,
     152,    0, 1471,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void, 0x80000000 | 27,    2,
    QMetaType::Void, 0x80000000 | 29,    2,
    QMetaType::Void, 0x80000000 | 31,    2,
    QMetaType::Void, 0x80000000 | 33,    2,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 44,    2,
    QMetaType::Void, 0x80000000 | 46,    2,
    QMetaType::Void, 0x80000000 | 48,    2,
    QMetaType::Void, 0x80000000 | 48,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,   52,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,   59,   60,   61,   62,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,   59,   60,   61,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,   59,   60,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,   59,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,   15,   77,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,   79,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   85,
    0x80000000 | 87, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   97,   98,   99,  100,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   97,   98,   99,  100,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  113,  114,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    0x80000000 | 117,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    0x80000000 | 125, QMetaType::Int,  126,
    QMetaType::QString, QMetaType::UInt,  128,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  130,  131,
    QMetaType::Int,
    QMetaType::QStringList,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::Bool, 0x80000000 | 44,   59,
    QMetaType::Bool, 0x80000000 | 46,   14,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 87, QMetaType::QString,  144,
    QMetaType::Bool, QMetaType::QObjectStar,    2,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  147,  148,  149,  150,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void DBInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_seva_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->seva_Name((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->modifying_seva((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 3: _t->seva_type((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 4: _t->send_seva_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->s_type_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->get_data_db((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 7: _t->forFUllDetails((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4])),(*reinterpret_cast< QList<QString>(*)>(_a[5])),(*reinterpret_cast< QList<QString>(*)>(_a[6])),(*reinterpret_cast< QList<QString>(*)>(_a[7])),(*reinterpret_cast< QList<QString>(*)>(_a[8])),(*reinterpret_cast< QList<QString>(*)>(_a[9])),(*reinterpret_cast< QList<QString>(*)>(_a[10])),(*reinterpret_cast< QList<QString>(*)>(_a[11])),(*reinterpret_cast< QList<QString>(*)>(_a[12])),(*reinterpret_cast< QList<QString>(*)>(_a[13])),(*reinterpret_cast< QList<QString>(*)>(_a[14])),(*reinterpret_cast< QList<QString>(*)>(_a[15])),(*reinterpret_cast< QList<QString>(*)>(_a[16])),(*reinterpret_cast< QList<QString>(*)>(_a[17])),(*reinterpret_cast< QList<QString>(*)>(_a[18])),(*reinterpret_cast< QList<QString>(*)>(_a[19])),(*reinterpret_cast< QList<QString>(*)>(_a[20])),(*reinterpret_cast< QList<QString>(*)>(_a[21])),(*reinterpret_cast< QList<QString>(*)>(_a[22])),(*reinterpret_cast< QList<QString>(*)>(_a[23]))); break;
        case 8: _t->forlasttenDetails((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4])),(*reinterpret_cast< QList<QString>(*)>(_a[5])),(*reinterpret_cast< QList<QString>(*)>(_a[6])),(*reinterpret_cast< QList<QString>(*)>(_a[7])),(*reinterpret_cast< QList<QString>(*)>(_a[8])),(*reinterpret_cast< QList<QString>(*)>(_a[9])),(*reinterpret_cast< QList<QString>(*)>(_a[10])),(*reinterpret_cast< QList<QString>(*)>(_a[11])),(*reinterpret_cast< QList<QString>(*)>(_a[12])),(*reinterpret_cast< QList<QString>(*)>(_a[13])),(*reinterpret_cast< QList<QString>(*)>(_a[14])),(*reinterpret_cast< QList<QString>(*)>(_a[15])),(*reinterpret_cast< QList<QString>(*)>(_a[16])),(*reinterpret_cast< QList<QString>(*)>(_a[17]))); break;
        case 9: _t->persondetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 10: _t->sevadetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->seva_types_adding((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 12: _t->sevaName((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 13: _t->sevaname((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3])),(*reinterpret_cast< QList<QString>(*)>(_a[4])),(*reinterpret_cast< QList<QString>(*)>(_a[5])),(*reinterpret_cast< QList<QString>(*)>(_a[6])),(*reinterpret_cast< QList<QString>(*)>(_a[7])),(*reinterpret_cast< QList<QString>(*)>(_a[8])),(*reinterpret_cast< QList<QString>(*)>(_a[9]))); break;
        case 14: _t->mob_num_there((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 15: _t->mob_num_Not_there(); break;
        case 16: _t->gotraList((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 17: _t->bankList((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 18: _t->variable_sevacharge(); break;
        case 19: _t->fixed_sevacharge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setting_fixed_seva_charge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->get_receiptnumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->booking_report((*reinterpret_cast< BookingReportElement*(*)>(_a[1]))); break;
        case 23: _t->account_report((*reinterpret_cast< AccountReportElement*(*)>(_a[1]))); break;
        case 24: _t->account_report_Date_Range((*reinterpret_cast< AccountReportDateRangeElement*(*)>(_a[1]))); break;
        case 25: _t->booking_report_Date_Range((*reinterpret_cast< BookingReportDateRangeElement*(*)>(_a[1]))); break;
        case 26: _t->account_report_Month_Range((*reinterpret_cast< AccountReportMonthRangeElement*(*)>(_a[1]))); break;
        case 27: _t->booking_report_Month_Range((*reinterpret_cast< BookingReportMonthRangeElement*(*)>(_a[1]))); break;
        case 28: _t->voucher_report((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 29: _t->correct_password((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->success(); break;
        case 31: _t->wrongCred(); break;
        case 32: _t->show_username_password((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 33: _t->sucessfully_added(); break;
        case 34: _t->sendSevaType((*reinterpret_cast< SevaType*(*)>(_a[1]))); break;
        case 35: _t->sendSevaName((*reinterpret_cast< SevaName*(*)>(_a[1]))); break;
        case 36: _t->sendOneSevaBooking((*reinterpret_cast< SevaBookingElement*(*)>(_a[1]))); break;
        case 37: _t->sendoneByoneSevaBooking((*reinterpret_cast< SevaBookingElement*(*)>(_a[1]))); break;
        case 38: _t->setGrandTotalToZero(); break;
        case 39: _t->add_seva_type((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 40: _t->modify_db_type((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 41: _t->delete_db((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->modify_db_seva((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 43: _t->delete_sevadb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 44: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 45: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->insertVoucherIssued((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 49: { bool _r = _t->check_name_db((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->check_db((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->addsevaname((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 52: _t->to_persondetails_db((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 53: { bool _r = _t->check_sevaname_allreadyexist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->seva_modification_testing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11]))); break;
        case 55: _t->combobox_sevatype(); break;
        case 56: _t->getdata(); break;
        case 57: { bool _r = _t->dbtable_view();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 58: _t->getDbData(); break;
        case 59: _t->getpersondetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 60: _t->getsevadetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 61: _t->canceleDatasevabookingentry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 62: _t->get_sevabooking_modifying((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11]))); break;
        case 63: _t->table_view_forlast_ten_tran(); break;
        case 64: _t->print_data_db((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->seva_type_adding(); break;
        case 66: _t->seva_name_adding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: { DevotePersnalDetails* _r = _t->mobileNumberSearching((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DevotePersnalDetails**>(_a[0]) = std::move(_r); }  break;
        case 68: _t->gotra_list(); break;
        case 69: _t->Checking_sevacharge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 70: _t->receipt_no_printing(); break;
        case 71: _t->booking_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 72: _t->booking_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 73: _t->booking_report_cmonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 74: _t->booking_report_eachDateDataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 75: _t->booking_report_eachDateDataRangeForMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 76: _t->booking_report_eachMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 77: _t->account_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 78: _t->account_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 79: _t->account_report_eachDateDataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 80: _t->account_report_cmonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 81: _t->account_report_eachMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 82: _t->account_report_eachDateDataRangeForMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 83: _t->account_report_eachDateDataRangeForWholeMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 84: _t->voucher_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 85: _t->voucher_report_cmonth_function((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 86: _t->voucher_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 87: _t->signin_clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 88: _t->old_password((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 89: _t->add_new_signin_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 90: { QList<SigninDetails*> _r = _t->geting_signInDetails();
            if (_a[0]) *reinterpret_cast< QList<SigninDetails*>*>(_a[0]) = std::move(_r); }  break;
        case 91: _t->delete_selected_LoginDetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 92: _t->modify_selected_LoginDetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 93: { QStringList _r = _t->getMasterCredentials();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 94: _t->updateMasterCredentials((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 95: _t->bank_list(); break;
        case 96: _t->modify_person_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 97: { QList<print_details*> _r = _t->printWithReceiptNumber((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<print_details*>*>(_a[0]) = std::move(_r); }  break;
        case 98: { QString _r = _t->NumberToWord((*reinterpret_cast< const uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 99: { bool _r = _t->checkCredentials((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 100: { int _r = _t->getNextSevaId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 101: { QStringList _r = _t->qrySevaDates();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 102: { bool _r = _t->qrySevabookingBySevaDate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 103: _t->qrySevabookingByDateRange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 104: { bool _r = _t->querySevaType();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 105: { bool _r = _t->querySevaNames();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 106: { QStringList _r = _t->qryNakshatras();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 107: { QStringList _r = _t->qryGothras();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 108: { QStringList _r = _t->qryBankList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 109: { bool _r = _t->add_seva_type((*reinterpret_cast< SevaType*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 110: { bool _r = _t->addsevaname((*reinterpret_cast< SevaName*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 111: _t->readSevaNamesFromJson(); break;
        case 112: _t->readSevaTypesFromJson(); break;
        case 113: { DevotePersnalDetails* _r = _t->getPersonDetails((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DevotePersnalDetails**>(_a[0]) = std::move(_r); }  break;
        case 114: { bool _r = _t->saveData((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 115: { int _r = _t->insertPersonDetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 116: { int _r = _t->getLastReceiptNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 117: { int _r = _t->getLastVoucherNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 7:
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
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportElement* >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportElement* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportDateRangeElement* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportDateRangeElement* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportMonthRangeElement* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BookingReportMonthRangeElement* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherElement* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaName* >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaBookingElement* >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaBookingElement* >(); break;
            }
            break;
        case 48:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherElement* >(); break;
            }
            break;
        case 109:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        case 110:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaName* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DBInterface::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::send_seva_details)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(int , QString , int , QString , QString , int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::seva_Name)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(int , int , QString , int , QString , QString , int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::modifying_seva)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::seva_type)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::send_seva_details)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::s_type_sig)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::get_data_db)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::forFUllDetails)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::forlasttenDetails)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::persondetails)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sevadetails)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::seva_types_adding)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sevaName)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sevaname)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::mob_num_there)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::mob_num_Not_there)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::gotraList)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::bankList)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::variable_sevacharge)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::fixed_sevacharge)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::setting_fixed_seva_charge)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::get_receiptnumber)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(BookingReportElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::booking_report)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(AccountReportElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::account_report)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(AccountReportDateRangeElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::account_report_Date_Range)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(BookingReportDateRangeElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::booking_report_Date_Range)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(AccountReportMonthRangeElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::account_report_Month_Range)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(BookingReportMonthRangeElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::booking_report_Month_Range)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(VoucherElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::voucher_report)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::correct_password)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::success)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::wrongCred)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::show_username_password)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sucessfully_added)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaType * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendSevaType)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaName * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendSevaName)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaBookingElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendOneSevaBooking)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaBookingElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendoneByoneSevaBooking)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::setGrandTotalToZero)) {
                *result = 38;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DBInterface.data,
    qt_meta_data_DBInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DBInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 118)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 118;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 118)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 118;
    }
    return _id;
}

// SIGNAL 0
void DBInterface::send_seva_details(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBInterface::seva_Name(int _t1, QString _t2, int _t3, QString _t4, QString _t5, int _t6, QString _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DBInterface::modifying_seva(int _t1, int _t2, QString _t3, int _t4, QString _t5, QString _t6, int _t7, QString _t8, int _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DBInterface::seva_type(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DBInterface::send_seva_details(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DBInterface::s_type_sig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DBInterface::get_data_db(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DBInterface::forFUllDetails(QList<QString> _t1, QList<QString> _t2, QList<QString> _t3, QList<QString> _t4, QList<QString> _t5, QList<QString> _t6, QList<QString> _t7, QList<QString> _t8, QList<QString> _t9, QList<QString> _t10, QList<QString> _t11, QList<QString> _t12, QList<QString> _t13, QList<QString> _t14, QList<QString> _t15, QList<QString> _t16, QList<QString> _t17, QList<QString> _t18, QList<QString> _t19, QList<QString> _t20, QList<QString> _t21, QList<QString> _t22, QList<QString> _t23)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t22))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t23))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DBInterface::forlasttenDetails(QList<QString> _t1, QList<QString> _t2, QList<QString> _t3, QList<QString> _t4, QList<QString> _t5, QList<QString> _t6, QList<QString> _t7, QList<QString> _t8, QList<QString> _t9, QList<QString> _t10, QList<QString> _t11, QList<QString> _t12, QList<QString> _t13, QList<QString> _t14, QList<QString> _t15, QList<QString> _t16, QList<QString> _t17)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DBInterface::persondetails(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DBInterface::sevadetails(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DBInterface::seva_types_adding(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void DBInterface::sevaName(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void DBInterface::sevaname(QList<QString> _t1, QList<QString> _t2, QList<QString> _t3, QList<QString> _t4, QList<QString> _t5, QList<QString> _t6, QList<QString> _t7, QList<QString> _t8, QList<QString> _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void DBInterface::mob_num_there(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void DBInterface::mob_num_Not_there()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void DBInterface::gotraList(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void DBInterface::bankList(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void DBInterface::variable_sevacharge()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void DBInterface::fixed_sevacharge(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void DBInterface::setting_fixed_seva_charge(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void DBInterface::get_receiptnumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void DBInterface::booking_report(BookingReportElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void DBInterface::account_report(AccountReportElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void DBInterface::account_report_Date_Range(AccountReportDateRangeElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void DBInterface::booking_report_Date_Range(BookingReportDateRangeElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void DBInterface::account_report_Month_Range(AccountReportMonthRangeElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void DBInterface::booking_report_Month_Range(BookingReportMonthRangeElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void DBInterface::voucher_report(VoucherElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void DBInterface::correct_password(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void DBInterface::success()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void DBInterface::wrongCred()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void DBInterface::show_username_password(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void DBInterface::sucessfully_added()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void DBInterface::sendSevaType(SevaType * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void DBInterface::sendSevaName(SevaName * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void DBInterface::sendOneSevaBooking(SevaBookingElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void DBInterface::sendoneByoneSevaBooking(SevaBookingElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void DBInterface::setGrandTotalToZero()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
