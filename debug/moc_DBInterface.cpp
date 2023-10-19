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
    QByteArrayData data[203];
    char stringdata0[3591];
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
QT_MOC_LITERAL(43, 744, 3), // "msg"
QT_MOC_LITERAL(44, 748, 18), // "selectSignalFromDB"
QT_MOC_LITERAL(45, 767, 6), // "serial"
QT_MOC_LITERAL(46, 774, 9), // "voucherId"
QT_MOC_LITERAL(47, 784, 11), // "voucherName"
QT_MOC_LITERAL(48, 796, 14), // "mySelectSignal"
QT_MOC_LITERAL(49, 811, 7), // "serl_no"
QT_MOC_LITERAL(50, 819, 3), // "vid"
QT_MOC_LITERAL(51, 823, 4), // "vcat"
QT_MOC_LITERAL(52, 828, 13), // "toModelDialog"
QT_MOC_LITERAL(53, 842, 13), // "update_Failed"
QT_MOC_LITERAL(54, 856, 15), // "deletion_Failed"
QT_MOC_LITERAL(55, 872, 14), // "update_Success"
QT_MOC_LITERAL(56, 887, 16), // "deletion_Success"
QT_MOC_LITERAL(57, 904, 17), // "signalToCashEntry"
QT_MOC_LITERAL(58, 922, 23), // "signalToCashTransaction"
QT_MOC_LITERAL(59, 946, 15), // "clearChequeList"
QT_MOC_LITERAL(60, 962, 15), // "sendDataToModel"
QT_MOC_LITERAL(61, 978, 8), // "bankname"
QT_MOC_LITERAL(62, 987, 13), // "receiptNumber"
QT_MOC_LITERAL(63, 1001, 11), // "receiptDate"
QT_MOC_LITERAL(64, 1013, 6), // "amount"
QT_MOC_LITERAL(65, 1020, 10), // "chequeDate"
QT_MOC_LITERAL(66, 1031, 14), // "addSuccessInDB"
QT_MOC_LITERAL(67, 1046, 11), // "addFailInDB"
QT_MOC_LITERAL(68, 1058, 17), // "updateSuccessInDB"
QT_MOC_LITERAL(69, 1076, 16), // "updateFailedInDB"
QT_MOC_LITERAL(70, 1093, 19), // "deletionSuccessInDB"
QT_MOC_LITERAL(71, 1113, 18), // "deletionFailedInDB"
QT_MOC_LITERAL(72, 1132, 17), // "mySelectSignalAll"
QT_MOC_LITERAL(73, 1150, 12), // "sendSevaType"
QT_MOC_LITERAL(74, 1163, 9), // "SevaType*"
QT_MOC_LITERAL(75, 1173, 12), // "sendSevaName"
QT_MOC_LITERAL(76, 1186, 9), // "SevaName*"
QT_MOC_LITERAL(77, 1196, 18), // "sendOneSevaBooking"
QT_MOC_LITERAL(78, 1215, 19), // "SevaBookingElement*"
QT_MOC_LITERAL(79, 1235, 23), // "sendoneByoneSevaBooking"
QT_MOC_LITERAL(80, 1259, 19), // "setGrandTotalToZero"
QT_MOC_LITERAL(81, 1279, 7), // "dbError"
QT_MOC_LITERAL(82, 1287, 8), // "errorMsg"
QT_MOC_LITERAL(83, 1296, 14), // "sendRolenumber"
QT_MOC_LITERAL(84, 1311, 7), // "rolenum"
QT_MOC_LITERAL(85, 1319, 10), // "signInName"
QT_MOC_LITERAL(86, 1330, 19), // "sendVoucheronebyone"
QT_MOC_LITERAL(87, 1350, 19), // "sendAcoountoneByone"
QT_MOC_LITERAL(88, 1370, 26), // "sendFullAccountDataElement"
QT_MOC_LITERAL(89, 1397, 25), // "AccountFullreportElement*"
QT_MOC_LITERAL(90, 1423, 38), // "sendChangedDataToSevaBookingT..."
QT_MOC_LITERAL(91, 1462, 14), // "insert_Success"
QT_MOC_LITERAL(92, 1477, 13), // "add_seva_type"
QT_MOC_LITERAL(93, 1491, 9), // "seva_code"
QT_MOC_LITERAL(94, 1501, 15), // "seva_adder_name"
QT_MOC_LITERAL(95, 1517, 14), // "modify_db_type"
QT_MOC_LITERAL(96, 1532, 9), // "delete_db"
QT_MOC_LITERAL(97, 1542, 14), // "modify_db_seva"
QT_MOC_LITERAL(98, 1557, 13), // "delete_sevadb"
QT_MOC_LITERAL(99, 1571, 16), // "insertSevaBooked"
QT_MOC_LITERAL(100, 1588, 8), // "sevaType"
QT_MOC_LITERAL(101, 1597, 9), // "reference"
QT_MOC_LITERAL(102, 1607, 7), // "address"
QT_MOC_LITERAL(103, 1615, 7), // "momento"
QT_MOC_LITERAL(104, 1623, 19), // "insertVoucherIssued"
QT_MOC_LITERAL(105, 1643, 13), // "check_name_db"
QT_MOC_LITERAL(106, 1657, 8), // "check_db"
QT_MOC_LITERAL(107, 1666, 11), // "addsevaname"
QT_MOC_LITERAL(108, 1678, 19), // "to_persondetails_db"
QT_MOC_LITERAL(109, 1698, 28), // "check_sevaname_allreadyexist"
QT_MOC_LITERAL(110, 1727, 25), // "seva_modification_testing"
QT_MOC_LITERAL(111, 1753, 17), // "combobox_sevatype"
QT_MOC_LITERAL(112, 1771, 7), // "getdata"
QT_MOC_LITERAL(113, 1779, 12), // "dbtable_view"
QT_MOC_LITERAL(114, 1792, 9), // "getDbData"
QT_MOC_LITERAL(115, 1802, 16), // "getpersondetails"
QT_MOC_LITERAL(116, 1819, 14), // "getsevadetails"
QT_MOC_LITERAL(117, 1834, 27), // "canceleDatasevabookingentry"
QT_MOC_LITERAL(118, 1862, 4), // "note"
QT_MOC_LITERAL(119, 1867, 25), // "get_sevabooking_modifying"
QT_MOC_LITERAL(120, 1893, 9), // "seva_name"
QT_MOC_LITERAL(121, 1903, 27), // "table_view_forlast_ten_tran"
QT_MOC_LITERAL(122, 1931, 13), // "print_data_db"
QT_MOC_LITERAL(123, 1945, 9), // "seva_Type"
QT_MOC_LITERAL(124, 1955, 16), // "seva_type_adding"
QT_MOC_LITERAL(125, 1972, 16), // "seva_name_adding"
QT_MOC_LITERAL(126, 1989, 5), // "sevaT"
QT_MOC_LITERAL(127, 1995, 21), // "mobileNumberSearching"
QT_MOC_LITERAL(128, 2017, 21), // "DevotePersnalDetails*"
QT_MOC_LITERAL(129, 2039, 10), // "gotra_list"
QT_MOC_LITERAL(130, 2050, 19), // "Checking_sevacharge"
QT_MOC_LITERAL(131, 2070, 19), // "receipt_no_printing"
QT_MOC_LITERAL(132, 2090, 29), // "booking_report_cdate_function"
QT_MOC_LITERAL(133, 2120, 33), // "booking_report_dataRange_func..."
QT_MOC_LITERAL(134, 2154, 30), // "booking_report_cmonth_function"
QT_MOC_LITERAL(135, 2185, 41), // "booking_report_eachDateDataRa..."
QT_MOC_LITERAL(136, 2227, 49), // "booking_report_eachDateDataRa..."
QT_MOC_LITERAL(137, 2277, 33), // "booking_report_eachMonth_func..."
QT_MOC_LITERAL(138, 2311, 4), // "SEVA"
QT_MOC_LITERAL(139, 2316, 4), // "TYPE"
QT_MOC_LITERAL(140, 2321, 5), // "month"
QT_MOC_LITERAL(141, 2327, 4), // "year"
QT_MOC_LITERAL(142, 2332, 29), // "account_report_cdate_function"
QT_MOC_LITERAL(143, 2362, 33), // "account_report_dataRange_func..."
QT_MOC_LITERAL(144, 2396, 41), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(145, 2438, 30), // "account_report_cmonth_function"
QT_MOC_LITERAL(146, 2469, 33), // "account_report_eachMonth_func..."
QT_MOC_LITERAL(147, 2503, 49), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(148, 2553, 54), // "account_report_eachDateDataRa..."
QT_MOC_LITERAL(149, 2608, 29), // "voucher_report_cdate_function"
QT_MOC_LITERAL(150, 2638, 30), // "voucher_report_cmonth_function"
QT_MOC_LITERAL(151, 2669, 33), // "voucher_report_dataRange_func..."
QT_MOC_LITERAL(152, 2703, 25), // "fullAccounDetailsDateWise"
QT_MOC_LITERAL(153, 2729, 30), // "fullAccounDetailsDateRangeWise"
QT_MOC_LITERAL(154, 2760, 26), // "fullAccounDetailsMonthwise"
QT_MOC_LITERAL(155, 2787, 14), // "signin_clicked"
QT_MOC_LITERAL(156, 2802, 12), // "old_password"
QT_MOC_LITERAL(157, 2815, 15), // "l_userfirstname"
QT_MOC_LITERAL(158, 2831, 14), // "l_userlastname"
QT_MOC_LITERAL(159, 2846, 22), // "add_new_signin_details"
QT_MOC_LITERAL(160, 2869, 20), // "geting_signInDetails"
QT_MOC_LITERAL(161, 2890, 21), // "QList<SigninDetails*>"
QT_MOC_LITERAL(162, 2912, 28), // "delete_selected_LoginDetails"
QT_MOC_LITERAL(163, 2941, 28), // "modify_selected_LoginDetails"
QT_MOC_LITERAL(164, 2970, 20), // "getMasterCredentials"
QT_MOC_LITERAL(165, 2991, 23), // "updateMasterCredentials"
QT_MOC_LITERAL(166, 3015, 9), // "bank_list"
QT_MOC_LITERAL(167, 3025, 21), // "modify_person_details"
QT_MOC_LITERAL(168, 3047, 22), // "printWithReceiptNumber"
QT_MOC_LITERAL(169, 3070, 21), // "QList<print_details*>"
QT_MOC_LITERAL(170, 3092, 12), // "NumberToWord"
QT_MOC_LITERAL(171, 3105, 6), // "number"
QT_MOC_LITERAL(172, 3112, 16), // "checkCredentials"
QT_MOC_LITERAL(173, 3129, 6), // "userID"
QT_MOC_LITERAL(174, 3136, 4), // "pass"
QT_MOC_LITERAL(175, 3141, 13), // "getNextSevaId"
QT_MOC_LITERAL(176, 3155, 12), // "qrySevaDates"
QT_MOC_LITERAL(177, 3168, 24), // "qrySevabookingBySevaDate"
QT_MOC_LITERAL(178, 3193, 25), // "qrySevabookingByDateRange"
QT_MOC_LITERAL(179, 3219, 13), // "querySevaType"
QT_MOC_LITERAL(180, 3233, 14), // "querySevaNames"
QT_MOC_LITERAL(181, 3248, 13), // "qryNakshatras"
QT_MOC_LITERAL(182, 3262, 10), // "qryGothras"
QT_MOC_LITERAL(183, 3273, 11), // "qryBankList"
QT_MOC_LITERAL(184, 3285, 10), // "createSeva"
QT_MOC_LITERAL(185, 3296, 21), // "readSevaNamesFromJson"
QT_MOC_LITERAL(186, 3318, 21), // "readSevaTypesFromJson"
QT_MOC_LITERAL(187, 3340, 16), // "getPersonDetails"
QT_MOC_LITERAL(188, 3357, 9), // "person_id"
QT_MOC_LITERAL(189, 3367, 8), // "saveData"
QT_MOC_LITERAL(190, 3376, 19), // "insertPersonDetails"
QT_MOC_LITERAL(191, 3396, 12), // "devoteMobile"
QT_MOC_LITERAL(192, 3409, 10), // "devoteName"
QT_MOC_LITERAL(193, 3420, 15), // "devoteNakshatra"
QT_MOC_LITERAL(194, 3436, 11), // "devoteGotra"
QT_MOC_LITERAL(195, 3448, 20), // "getLastReceiptNumber"
QT_MOC_LITERAL(196, 3469, 20), // "getLastVoucherNumber"
QT_MOC_LITERAL(197, 3490, 21), // "getLastSevatypeNumber"
QT_MOC_LITERAL(198, 3512, 21), // "getLastSevaNameNumber"
QT_MOC_LITERAL(199, 3534, 14), // "getvoucherdata"
QT_MOC_LITERAL(200, 3549, 14), // "getAccountData"
QT_MOC_LITERAL(201, 3564, 18), // "recvDeletedRecptNo"
QT_MOC_LITERAL(202, 3583, 7) // "recptNo"

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
    "msg\0selectSignalFromDB\0serial\0voucherId\0"
    "voucherName\0mySelectSignal\0serl_no\0"
    "vid\0vcat\0toModelDialog\0update_Failed\0"
    "deletion_Failed\0update_Success\0"
    "deletion_Success\0signalToCashEntry\0"
    "signalToCashTransaction\0clearChequeList\0"
    "sendDataToModel\0bankname\0receiptNumber\0"
    "receiptDate\0amount\0chequeDate\0"
    "addSuccessInDB\0addFailInDB\0updateSuccessInDB\0"
    "updateFailedInDB\0deletionSuccessInDB\0"
    "deletionFailedInDB\0mySelectSignalAll\0"
    "sendSevaType\0SevaType*\0sendSevaName\0"
    "SevaName*\0sendOneSevaBooking\0"
    "SevaBookingElement*\0sendoneByoneSevaBooking\0"
    "setGrandTotalToZero\0dbError\0errorMsg\0"
    "sendRolenumber\0rolenum\0signInName\0"
    "sendVoucheronebyone\0sendAcoountoneByone\0"
    "sendFullAccountDataElement\0"
    "AccountFullreportElement*\0"
    "sendChangedDataToSevaBookingTablemodel\0"
    "insert_Success\0add_seva_type\0seva_code\0"
    "seva_adder_name\0modify_db_type\0delete_db\0"
    "modify_db_seva\0delete_sevadb\0"
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
    "fullAccounDetailsDateWise\0"
    "fullAccounDetailsDateRangeWise\0"
    "fullAccounDetailsMonthwise\0signin_clicked\0"
    "old_password\0l_userfirstname\0"
    "l_userlastname\0add_new_signin_details\0"
    "geting_signInDetails\0QList<SigninDetails*>\0"
    "delete_selected_LoginDetails\0"
    "modify_selected_LoginDetails\0"
    "getMasterCredentials\0updateMasterCredentials\0"
    "bank_list\0modify_person_details\0"
    "printWithReceiptNumber\0QList<print_details*>\0"
    "NumberToWord\0number\0checkCredentials\0"
    "userID\0pass\0getNextSevaId\0qrySevaDates\0"
    "qrySevabookingBySevaDate\0"
    "qrySevabookingByDateRange\0querySevaType\0"
    "querySevaNames\0qryNakshatras\0qryGothras\0"
    "qryBankList\0createSeva\0readSevaNamesFromJson\0"
    "readSevaTypesFromJson\0getPersonDetails\0"
    "person_id\0saveData\0insertPersonDetails\0"
    "devoteMobile\0devoteName\0devoteNakshatra\0"
    "devoteGotra\0getLastReceiptNumber\0"
    "getLastVoucherNumber\0getLastSevatypeNumber\0"
    "getLastSevaNameNumber\0getvoucherdata\0"
    "getAccountData\0recvDeletedRecptNo\0"
    "recptNo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     153,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      64,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  779,    2, 0x06 /* Public */,
       3,    8,  784,    2, 0x06 /* Public */,
       4,    9,  801,    2, 0x06 /* Public */,
       5,    1,  820,    2, 0x06 /* Public */,
       1,    3,  823,    2, 0x06 /* Public */,
       7,    1,  830,    2, 0x06 /* Public */,
       8,    4,  833,    2, 0x06 /* Public */,
       9,   23,  842,    2, 0x06 /* Public */,
      10,   17,  889,    2, 0x06 /* Public */,
      11,    6,  924,    2, 0x06 /* Public */,
      12,    2,  937,    2, 0x06 /* Public */,
      13,    1,  942,    2, 0x06 /* Public */,
      14,    1,  945,    2, 0x06 /* Public */,
      15,    9,  948,    2, 0x06 /* Public */,
      16,    4,  967,    2, 0x06 /* Public */,
      17,    0,  976,    2, 0x06 /* Public */,
      18,    1,  977,    2, 0x06 /* Public */,
      19,    1,  980,    2, 0x06 /* Public */,
      20,    0,  983,    2, 0x06 /* Public */,
      21,    1,  984,    2, 0x06 /* Public */,
      22,    1,  987,    2, 0x06 /* Public */,
      23,    1,  990,    2, 0x06 /* Public */,
      24,    1,  993,    2, 0x06 /* Public */,
      26,    1,  996,    2, 0x06 /* Public */,
      28,    1,  999,    2, 0x06 /* Public */,
      30,    1, 1002,    2, 0x06 /* Public */,
      32,    1, 1005,    2, 0x06 /* Public */,
      34,    1, 1008,    2, 0x06 /* Public */,
      36,    1, 1011,    2, 0x06 /* Public */,
      38,    1, 1014,    2, 0x06 /* Public */,
      39,    0, 1017,    2, 0x06 /* Public */,
      40,    0, 1018,    2, 0x06 /* Public */,
      41,    2, 1019,    2, 0x06 /* Public */,
      42,    1, 1024,    2, 0x06 /* Public */,
      44,    3, 1027,    2, 0x06 /* Public */,
      48,    3, 1034,    2, 0x06 /* Public */,
      52,    0, 1041,    2, 0x06 /* Public */,
      53,    0, 1042,    2, 0x06 /* Public */,
      54,    0, 1043,    2, 0x06 /* Public */,
      55,    3, 1044,    2, 0x06 /* Public */,
      56,    3, 1051,    2, 0x06 /* Public */,
      57,    3, 1058,    2, 0x06 /* Public */,
      58,    4, 1065,    2, 0x06 /* Public */,
      59,    0, 1074,    2, 0x06 /* Public */,
      60,    5, 1075,    2, 0x06 /* Public */,
      66,    3, 1086,    2, 0x06 /* Public */,
      67,    0, 1093,    2, 0x06 /* Public */,
      68,    3, 1094,    2, 0x06 /* Public */,
      69,    0, 1101,    2, 0x06 /* Public */,
      70,    1, 1102,    2, 0x06 /* Public */,
      71,    0, 1105,    2, 0x06 /* Public */,
      72,    3, 1106,    2, 0x06 /* Public */,
      73,    1, 1113,    2, 0x06 /* Public */,
      75,    1, 1116,    2, 0x06 /* Public */,
      77,    1, 1119,    2, 0x06 /* Public */,
      79,    1, 1122,    2, 0x06 /* Public */,
      80,    0, 1125,    2, 0x06 /* Public */,
      81,    1, 1126,    2, 0x06 /* Public */,
      83,    2, 1129,    2, 0x06 /* Public */,
      86,    1, 1134,    2, 0x06 /* Public */,
      87,    1, 1137,    2, 0x06 /* Public */,
      88,    1, 1140,    2, 0x06 /* Public */,
      90,    1, 1143,    2, 0x06 /* Public */,
      91,    3, 1146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      92,    3, 1153,    2, 0x0a /* Public */,
      95,    5, 1160,    2, 0x0a /* Public */,
      96,    1, 1171,    2, 0x0a /* Public */,
      97,    9, 1174,    2, 0x0a /* Public */,
      98,    2, 1193,    2, 0x0a /* Public */,
      99,   22, 1198,    2, 0x0a /* Public */,
      99,   21, 1243,    2, 0x2a /* Public | MethodCloned */,
      99,   20, 1286,    2, 0x2a /* Public | MethodCloned */,
      99,   19, 1327,    2, 0x2a /* Public | MethodCloned */,
      99,   18, 1366,    2, 0x2a /* Public | MethodCloned */,
      99,   17, 1403,    2, 0x2a /* Public | MethodCloned */,
     104,    1, 1438,    2, 0x0a /* Public */,
     105,    8, 1441,    2, 0x0a /* Public */,
     106,    3, 1458,    2, 0x0a /* Public */,
     107,    8, 1465,    2, 0x0a /* Public */,
     108,   10, 1482,    2, 0x0a /* Public */,
     109,    8, 1503,    2, 0x0a /* Public */,
     110,   11, 1520,    2, 0x0a /* Public */,
     111,    0, 1543,    2, 0x0a /* Public */,
     112,    0, 1544,    2, 0x0a /* Public */,
     113,    0, 1545,    2, 0x0a /* Public */,
     114,    0, 1546,    2, 0x0a /* Public */,
     115,    1, 1547,    2, 0x0a /* Public */,
     116,    1, 1550,    2, 0x0a /* Public */,
     117,    3, 1553,    2, 0x0a /* Public */,
     119,   11, 1560,    2, 0x0a /* Public */,
     121,    0, 1583,    2, 0x0a /* Public */,
     122,    1, 1584,    2, 0x0a /* Public */,
     124,    0, 1587,    2, 0x0a /* Public */,
     125,    1, 1588,    2, 0x0a /* Public */,
     127,    1, 1591,    2, 0x0a /* Public */,
     129,    0, 1594,    2, 0x0a /* Public */,
     130,    1, 1595,    2, 0x0a /* Public */,
     131,    0, 1598,    2, 0x0a /* Public */,
     132,    3, 1599,    2, 0x0a /* Public */,
     133,    4, 1606,    2, 0x0a /* Public */,
     134,    4, 1615,    2, 0x0a /* Public */,
     135,    4, 1624,    2, 0x0a /* Public */,
     136,    4, 1633,    2, 0x0a /* Public */,
     137,    4, 1642,    2, 0x0a /* Public */,
     142,    3, 1651,    2, 0x0a /* Public */,
     143,    4, 1658,    2, 0x0a /* Public */,
     144,    4, 1667,    2, 0x0a /* Public */,
     145,    4, 1676,    2, 0x0a /* Public */,
     146,    4, 1685,    2, 0x0a /* Public */,
     147,    4, 1694,    2, 0x0a /* Public */,
     148,    4, 1703,    2, 0x0a /* Public */,
     149,    3, 1712,    2, 0x0a /* Public */,
     150,    4, 1719,    2, 0x0a /* Public */,
     151,    4, 1728,    2, 0x0a /* Public */,
     152,    3, 1737,    2, 0x0a /* Public */,
     153,    4, 1744,    2, 0x0a /* Public */,
     154,    4, 1753,    2, 0x0a /* Public */,
     155,    3, 1762,    2, 0x0a /* Public */,
     156,    2, 1769,    2, 0x0a /* Public */,
     159,    6, 1774,    2, 0x0a /* Public */,
     160,    0, 1787,    2, 0x0a /* Public */,
     162,    1, 1788,    2, 0x0a /* Public */,
     163,    6, 1791,    2, 0x0a /* Public */,
     164,    0, 1804,    2, 0x0a /* Public */,
     165,    4, 1805,    2, 0x0a /* Public */,
     166,    0, 1814,    2, 0x0a /* Public */,
     167,    5, 1815,    2, 0x0a /* Public */,
     168,    1, 1826,    2, 0x0a /* Public */,
     170,    1, 1829,    2, 0x0a /* Public */,
     172,    2, 1832,    2, 0x0a /* Public */,
     175,    0, 1837,    2, 0x0a /* Public */,
     176,    0, 1838,    2, 0x0a /* Public */,
     177,    1, 1839,    2, 0x0a /* Public */,
     178,    2, 1842,    2, 0x0a /* Public */,
     179,    0, 1847,    2, 0x0a /* Public */,
     180,    0, 1848,    2, 0x0a /* Public */,
     181,    0, 1849,    2, 0x0a /* Public */,
     182,    0, 1850,    2, 0x0a /* Public */,
     183,    0, 1851,    2, 0x0a /* Public */,
      92,    1, 1852,    2, 0x0a /* Public */,
     184,    1, 1855,    2, 0x0a /* Public */,
     185,    0, 1858,    2, 0x0a /* Public */,
     186,    0, 1859,    2, 0x0a /* Public */,
     187,    1, 1860,    2, 0x0a /* Public */,
     189,    1, 1863,    2, 0x0a /* Public */,
     190,    5, 1866,    2, 0x0a /* Public */,
     195,    0, 1877,    2, 0x0a /* Public */,
     196,    0, 1878,    2, 0x0a /* Public */,
     197,    0, 1879,    2, 0x0a /* Public */,
     198,    0, 1880,    2, 0x0a /* Public */,
     199,    0, 1881,    2, 0x0a /* Public */,
     200,    0, 1882,    2, 0x0a /* Public */,
     201,    1, 1883,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   45,   46,   47,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   49,   50,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   61,   62,   63,   64,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 74,    2,
    QMetaType::Void, 0x80000000 | 76,    2,
    QMetaType::Void, 0x80000000 | 78,    2,
    QMetaType::Void, 0x80000000 | 78,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   82,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   84,   85,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 27,    2,
    QMetaType::Void, 0x80000000 | 89,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,   93,   94,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,  101,    2,  102,  103,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,  101,    2,  102,  103,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,  101,    2,  102,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,  101,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,  101,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  100,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,   94,
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
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,   15,  118,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,  120,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  123,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  126,
    0x80000000 | 128, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,  138,  139,  140,  141,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,  138,  139,  140,  141,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  157,  158,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    0x80000000 | 161,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    0x80000000 | 169, QMetaType::Int,   62,
    QMetaType::QString, QMetaType::UInt,  171,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,  173,  174,
    QMetaType::Int,
    QMetaType::QStringList,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::Bool, 0x80000000 | 74,  100,
    QMetaType::Bool, 0x80000000 | 76,   14,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 128, QMetaType::QString,  188,
    QMetaType::Bool, QMetaType::QObjectStar,    2,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,  191,  192,  193,  194,  102,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  202,

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
        case 33: _t->sucessfully_added((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->selectSignalFromDB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 35: _t->mySelectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 36: _t->toModelDialog(); break;
        case 37: _t->update_Failed(); break;
        case 38: _t->deletion_Failed(); break;
        case 39: _t->update_Success((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 40: _t->deletion_Success((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 41: _t->signalToCashEntry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 42: _t->signalToCashTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 43: _t->clearChequeList(); break;
        case 44: _t->sendDataToModel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 45: _t->addSuccessInDB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 46: _t->addFailInDB(); break;
        case 47: _t->updateSuccessInDB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 48: _t->updateFailedInDB(); break;
        case 49: _t->deletionSuccessInDB((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 50: _t->deletionFailedInDB(); break;
        case 51: _t->mySelectSignalAll((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 52: _t->sendSevaType((*reinterpret_cast< SevaType*(*)>(_a[1]))); break;
        case 53: _t->sendSevaName((*reinterpret_cast< SevaName*(*)>(_a[1]))); break;
        case 54: _t->sendOneSevaBooking((*reinterpret_cast< SevaBookingElement*(*)>(_a[1]))); break;
        case 55: _t->sendoneByoneSevaBooking((*reinterpret_cast< SevaBookingElement*(*)>(_a[1]))); break;
        case 56: _t->setGrandTotalToZero(); break;
        case 57: _t->dbError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 58: _t->sendRolenumber((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 59: _t->sendVoucheronebyone((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 60: _t->sendAcoountoneByone((*reinterpret_cast< AccountReportElement*(*)>(_a[1]))); break;
        case 61: _t->sendFullAccountDataElement((*reinterpret_cast< AccountFullreportElement*(*)>(_a[1]))); break;
        case 62: _t->sendChangedDataToSevaBookingTablemodel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 63: _t->insert_Success((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 64: { bool _r = _t->add_seva_type((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 65: _t->modify_db_type((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 66: _t->delete_db((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->modify_db_seva((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 68: _t->delete_sevadb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 69: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< QString(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 70: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< QString(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 71: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 72: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 73: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->insertSevaBooked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 75: _t->insertVoucherIssued((*reinterpret_cast< VoucherElement*(*)>(_a[1]))); break;
        case 76: { bool _r = _t->check_name_db((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 77: { bool _r = _t->check_db((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 78: _t->addsevaname((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 79: _t->to_persondetails_db((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 80: { bool _r = _t->check_sevaname_allreadyexist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 81: _t->seva_modification_testing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11]))); break;
        case 82: _t->combobox_sevatype(); break;
        case 83: _t->getdata(); break;
        case 84: { bool _r = _t->dbtable_view();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 85: _t->getDbData(); break;
        case 86: _t->getpersondetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 87: _t->getsevadetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 88: _t->canceleDatasevabookingentry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 89: _t->get_sevabooking_modifying((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11]))); break;
        case 90: _t->table_view_forlast_ten_tran(); break;
        case 91: _t->print_data_db((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 92: _t->seva_type_adding(); break;
        case 93: _t->seva_name_adding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 94: { DevotePersnalDetails* _r = _t->mobileNumberSearching((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DevotePersnalDetails**>(_a[0]) = std::move(_r); }  break;
        case 95: _t->gotra_list(); break;
        case 96: _t->Checking_sevacharge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 97: _t->receipt_no_printing(); break;
        case 98: _t->booking_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 99: _t->booking_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 100: _t->booking_report_cmonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 101: _t->booking_report_eachDateDataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 102: _t->booking_report_eachDateDataRangeForMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 103: _t->booking_report_eachMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 104: _t->account_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 105: _t->account_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 106: _t->account_report_eachDateDataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 107: _t->account_report_cmonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 108: _t->account_report_eachMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 109: _t->account_report_eachDateDataRangeForMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 110: _t->account_report_eachDateDataRangeForWholeMonth_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 111: _t->voucher_report_cdate_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 112: _t->voucher_report_cmonth_function((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 113: _t->voucher_report_dataRange_function((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 114: _t->fullAccounDetailsDateWise((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 115: _t->fullAccounDetailsDateRangeWise((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 116: _t->fullAccounDetailsMonthwise((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 117: _t->signin_clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 118: _t->old_password((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 119: _t->add_new_signin_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 120: { QList<SigninDetails*> _r = _t->geting_signInDetails();
            if (_a[0]) *reinterpret_cast< QList<SigninDetails*>*>(_a[0]) = std::move(_r); }  break;
        case 121: _t->delete_selected_LoginDetails((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 122: _t->modify_selected_LoginDetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 123: { QStringList _r = _t->getMasterCredentials();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 124: _t->updateMasterCredentials((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 125: _t->bank_list(); break;
        case 126: _t->modify_person_details((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 127: { QList<print_details*> _r = _t->printWithReceiptNumber((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<print_details*>*>(_a[0]) = std::move(_r); }  break;
        case 128: { QString _r = _t->NumberToWord((*reinterpret_cast< const uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 129: { bool _r = _t->checkCredentials((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 130: { int _r = _t->getNextSevaId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 131: { QStringList _r = _t->qrySevaDates();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 132: { bool _r = _t->qrySevabookingBySevaDate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 133: _t->qrySevabookingByDateRange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 134: { bool _r = _t->querySevaType();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 135: { bool _r = _t->querySevaNames();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 136: { QStringList _r = _t->qryNakshatras();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 137: { QStringList _r = _t->qryGothras();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 138: { QStringList _r = _t->qryBankList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 139: { bool _r = _t->add_seva_type((*reinterpret_cast< SevaType*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 140: { bool _r = _t->createSeva((*reinterpret_cast< SevaName*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 141: _t->readSevaNamesFromJson(); break;
        case 142: _t->readSevaTypesFromJson(); break;
        case 143: { DevotePersnalDetails* _r = _t->getPersonDetails((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< DevotePersnalDetails**>(_a[0]) = std::move(_r); }  break;
        case 144: { bool _r = _t->saveData((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 145: { int _r = _t->insertPersonDetails((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 146: { int _r = _t->getLastReceiptNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 147: { int _r = _t->getLastVoucherNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 148: { int _r = _t->getLastSevatypeNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 149: { int _r = _t->getLastSevaNameNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 150: _t->getvoucherdata(); break;
        case 151: _t->getAccountData(); break;
        case 152: _t->recvDeletedRecptNo((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        case 52:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        case 53:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaName* >(); break;
            }
            break;
        case 54:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaBookingElement* >(); break;
            }
            break;
        case 55:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaBookingElement* >(); break;
            }
            break;
        case 59:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherElement* >(); break;
            }
            break;
        case 60:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountReportElement* >(); break;
            }
            break;
        case 61:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AccountFullreportElement* >(); break;
            }
            break;
        case 75:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VoucherElement* >(); break;
            }
            break;
        case 139:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SevaType* >(); break;
            }
            break;
        case 140:
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
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sucessfully_added)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::selectSignalFromDB)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::mySelectSignal)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::toModelDialog)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::update_Failed)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::deletion_Failed)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::update_Success)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::deletion_Success)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::signalToCashEntry)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::signalToCashTransaction)) {
                *result = 42;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::clearChequeList)) {
                *result = 43;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendDataToModel)) {
                *result = 44;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::addSuccessInDB)) {
                *result = 45;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::addFailInDB)) {
                *result = 46;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::updateSuccessInDB)) {
                *result = 47;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::updateFailedInDB)) {
                *result = 48;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::deletionSuccessInDB)) {
                *result = 49;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::deletionFailedInDB)) {
                *result = 50;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::mySelectSignalAll)) {
                *result = 51;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaType * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendSevaType)) {
                *result = 52;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaName * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendSevaName)) {
                *result = 53;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaBookingElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendOneSevaBooking)) {
                *result = 54;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(SevaBookingElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendoneByoneSevaBooking)) {
                *result = 55;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::setGrandTotalToZero)) {
                *result = 56;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::dbError)) {
                *result = 57;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendRolenumber)) {
                *result = 58;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(VoucherElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendVoucheronebyone)) {
                *result = 59;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(AccountReportElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendAcoountoneByone)) {
                *result = 60;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(AccountFullreportElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendFullAccountDataElement)) {
                *result = 61;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::sendChangedDataToSevaBookingTablemodel)) {
                *result = 62;
                return;
            }
        }
        {
            using _t = void (DBInterface::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBInterface::insert_Success)) {
                *result = 63;
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
        if (_id < 153)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 153;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 153)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 153;
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
void DBInterface::sucessfully_added(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void DBInterface::selectSignalFromDB(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void DBInterface::mySelectSignal(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void DBInterface::toModelDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}

// SIGNAL 37
void DBInterface::update_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 37, nullptr);
}

// SIGNAL 38
void DBInterface::deletion_Failed()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void DBInterface::update_Success(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void DBInterface::deletion_Success(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void DBInterface::signalToCashEntry(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 42
void DBInterface::signalToCashTransaction(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void DBInterface::clearChequeList()
{
    QMetaObject::activate(this, &staticMetaObject, 43, nullptr);
}

// SIGNAL 44
void DBInterface::sendDataToModel(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 44, _a);
}

// SIGNAL 45
void DBInterface::addSuccessInDB(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 45, _a);
}

// SIGNAL 46
void DBInterface::addFailInDB()
{
    QMetaObject::activate(this, &staticMetaObject, 46, nullptr);
}

// SIGNAL 47
void DBInterface::updateSuccessInDB(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}

// SIGNAL 48
void DBInterface::updateFailedInDB()
{
    QMetaObject::activate(this, &staticMetaObject, 48, nullptr);
}

// SIGNAL 49
void DBInterface::deletionSuccessInDB(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void DBInterface::deletionFailedInDB()
{
    QMetaObject::activate(this, &staticMetaObject, 50, nullptr);
}

// SIGNAL 51
void DBInterface::mySelectSignalAll(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 51, _a);
}

// SIGNAL 52
void DBInterface::sendSevaType(SevaType * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 52, _a);
}

// SIGNAL 53
void DBInterface::sendSevaName(SevaName * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 53, _a);
}

// SIGNAL 54
void DBInterface::sendOneSevaBooking(SevaBookingElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 54, _a);
}

// SIGNAL 55
void DBInterface::sendoneByoneSevaBooking(SevaBookingElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 55, _a);
}

// SIGNAL 56
void DBInterface::setGrandTotalToZero()
{
    QMetaObject::activate(this, &staticMetaObject, 56, nullptr);
}

// SIGNAL 57
void DBInterface::dbError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 57, _a);
}

// SIGNAL 58
void DBInterface::sendRolenumber(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 58, _a);
}

// SIGNAL 59
void DBInterface::sendVoucheronebyone(VoucherElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 59, _a);
}

// SIGNAL 60
void DBInterface::sendAcoountoneByone(AccountReportElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 60, _a);
}

// SIGNAL 61
void DBInterface::sendFullAccountDataElement(AccountFullreportElement * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 61, _a);
}

// SIGNAL 62
void DBInterface::sendChangedDataToSevaBookingTablemodel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 62, _a);
}

// SIGNAL 63
void DBInterface::insert_Success(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 63, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
