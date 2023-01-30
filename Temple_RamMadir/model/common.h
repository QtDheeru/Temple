#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <QString>

using namespace std;

struct SigninDetails{
    QString firstName;
    QString LastName;
    QString UserName;
    QString Password;
};

struct Congigartions{
    QString welcomeImage;
    QString LoginImage;
};

typedef struct print_details Print_Detail;

struct print_details
{
    QString NAME;
    QString RECPT_NO;
    QString MOB_NO;
    QString DATE;
    QString GOTHRA;
    QString SEVA_DATE;
    QString NAKSHATRA;
    QString SEVA_TIME;
    QString SL_NO;
    QString SEVA_DESCR;
    QString QTY;
    QString ADDITIONAL;
    QString AMT;
    QString RATE;
    QString TOTAL_AMT;
    QString TOTAL_IN_WORDS;
    QString NOTE;
    QString CASH;
    QString BANK_REF;

};
typedef struct print_voucherDetails  Print_VoucherDetail;

struct print_voucherDetails
{
    QString VOUCHER_DATE;
    QString VOUCHER_NO;
    QString VOUCHER_NAME;
    QString MOB_NO;
    QString VOUCHER_TYPE;
    QString VOUCHER_ITEM;
    QString VOUCHER_NOTE;
    QString VOUCHER_COST;
    QString VOUCHER_PAYMENT_MOD;
    QString VOUCHER_PAYMENT_REFERENCE;
};
typedef struct print_bookingDetails  Print_BookingDetail;

struct print_bookingDetails
{
    QString  serial_No;
    QString  person_Id;
    QString  devotee_Name;
    QString  mobile_No;
    QString  gothra;
    QString  nakshatra;
    QString  seva_Type;
    QString  seva_Name;
    QString  quantity;
    QString  receipt_Date;
    QString  seva_Date;
    QString  total_Cost;
    QString  cash;
    QString  bank;
     QString note;
};
struct PersonDetails{
    QString personId;
    QString NAME;
    QString MOB_NO;
    QString GOTHRA;
    QString NAKSHATRA;
};

struct SevaTypeDetails {
    int seva_type_id;
    QString seva_type_name;
};

struct SevaNameDetails{
    int sNumber;
    QString sevaName;
    int sevaType;
    int sevaCost;
    int teerthaPrasada;
    QString sevaDate;
};


#endif // COMMON_H
