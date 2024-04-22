#ifndef DBInterface_H
#define DBInterface_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QList>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QDate>
#include "./common.h"
#include "SevaName.h"
#include "SevaType.h"
#include "DevotePersnalDetails.h"
#include "SevaTypeJsonProcessor.h"
#include "Reports/SevaBookingElement.h"
#include "Reports/AccountReportElement.h"
#include "Reports/BookingReportElement.h"
#include "voucher/VoucherElement.h"
#include "AccountReportDateRangeElement.h"
#include "AccountReportMonthRangeElement.h"
#include "BookingReportDateRangeElement.h"
#include "BookingReportMonthRangeElement.h"
#include "AccountFullreportElement.h"
#include <QQmlEngine>

//#include "voucher/VoucherFilterElements.h"
#include "IDataWriter.h"
#include "TrustListModel.h"

#define ALLSEVANAME "All"

class  DBInterface: public QObject
{
    Q_OBJECT
public:
    static DBInterface* init;
    static DBInterface* getInstance();

    QSqlDatabase db;
    ~ DBInterface();

    QString getError() const;
    void setError(const QString &error);
    void addChequeToDataBase(QString db_receiptDate, QString db_chequeDate, QString db_bankName, QString db_recepitNumber, QString db_amount);
    void addCashTOdatabase(QString a_date, QString a_lastreci, QString a_cashinhand, QString a_tobank, QString a_transType, QString a_bank, QString a_person, QString a_status, QString a_notes);
    void databaseToCashEntry();
    void lastDataToCashEntry();
    void addData(QString,QString,QString);
    void selectDataInMain();
    void addMyDB(QString,QString,QString);
    void selectDataAll(QString);
    void updateData(QString,QString,QString);
    void removeData(QString);

    void updateToDb(QString,QString,QString);
    void deleteData(QString,QString,QString);

    QList<SevaBookingElement*> getSewaBookingEntryForReceipt(QString);//added Now

    void getChequeData();
    int getpersonID(QString devoteMobile,QString devoteeName);

signals:
    void send_seva_details(QString,int);
    void seva_Name(int,QString,int,QString,QString,int,QString,int);
    void modifying_seva(int,int,QString,int,QString,QString,int,QString,int);
    void seva_type(QList<QString>);
    void send_seva_details(QString,int,QString);
    void s_type_sig(QString);
    void get_data_db(QString,QString,QString,QString);
    //void forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void forlasttenDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void persondetails(QString,QString,QString,QString,QString,QString);
    void sevadetails(QString,int);
    void seva_types_adding(QList<QString>);
    void sevaName(QList<QString>);
    void sevaname( QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>);
    void mob_num_there(QString,QString,QString,QString);
    void mob_num_Not_there();
    void gotraList(QList<QString>);
    void bankList(QList<QString>);
    void variable_sevacharge();
    void fixed_sevacharge(int);
    void setting_fixed_seva_charge(QString);
    void get_receiptnumber(int);
    // void booking_report(QList<QString>,QList<int>,QList<int>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
    void booking_report(BookingReportElement*);
    //void account_report(QList<QString>,QList<int>,QList<float>,QList<float>,QString);
    void account_report(AccountReportElement*);
    void account_report_Date_Range(AccountReportElement*);
    //void account_report_Date_Range(AccountReportDateRangeElement*);
    void booking_report_Date_Range(BookingReportDateRangeElement*);
    void account_report_Month_Range(AccountReportElement*);
    void booking_report_Month_Range(BookingReportMonthRangeElement*);
    void voucher_report(VoucherElement*);

    void correct_password(QString);
    void success();
    void wrongCred();
    void show_username_password(QString,QString);
    void sucessfully_added(QString msg);

    void selectSignalFromDB(QString serial,QString voucherId ,QString voucherName);
    void mySelectSignal(QString serl_no,QString vid,QString vcat);
    void toModelDialog();
    void update_Failed();
    void deletion_Failed();
    void update_Success(QString,QString,QString);
    void deletion_Success(QString,QString,QString);


    void signalToCashEntry(QString ,QString,QString);
    void signalToCashTransaction(QString,QString,QString,QString);
    void clearChequeList();
    void sendDataToModel(QString bankname,QString receiptNumber, QString receiptDate, QString amount, QString chequeDate);

    void addSuccessInDB(QString,QString,QString);
    void addFailInDB();
    void updateSuccessInDB(QString,QString,QString);
    void updateFailedInDB();
    void deletionSuccessInDB(QString);
    void deletionFailedInDB();

    void mySelectSignalAll(QString,QString,QString);
    void signalClosedStatus(QString);

public slots:
    bool add_seva_type(QString seva_type, int seva_code, QString seva_adder_name);
    void modify_db_type(int,QString,int,QString,int);
    void delete_db(int);
    void modify_db_seva(int,QString,int,QString,QString,QString,int,QString,int);
    void delete_sevadb(QString, QString);
    //void sevabookingdb(QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , int, int , QString , QString , QString);
    bool insertSevaBooked(QString,QString , QString , QString ,QString , QString , QString , QString , QString , QString , QString , QString , int, int , QString , QString , QString, QString sevaType,QString reference="ref",QString="",QString address="RR nagar",QString momento="momento",QString="");
    void insertVoucherIssued(VoucherElement*);
    bool check_name_db(int,QString,int,QString,QString,int,QString,int);
    bool check_db(QString, int, QString seva_adder_name);
    void addsevaname(int, QString, int, QString, QString, int , QString,int );
    void to_persondetails_db(QString , QString , QString , QString , QString , QString , QString , QString , QString , QString );
    bool check_sevaname_allreadyexist(int , QString , int , QString , QString , int , QString , int );
    void seva_modification_testing(int, int, QString, int, QString, QString, int, QString, int, QString, QString );
    void combobox_sevatype();
    void getdata();
    bool dbtable_view();
    void getDbData();
    void getpersondetails(QString);
    void getsevadetails(QString);
    void canceleDatasevabookingentry(int, QString sevaname, QString note);
    void get_sevabooking_modifying(int, int, int, int, int, QString, int, int , int , QString, QString seva_name);
    void table_view_forlast_ten_tran();
    void print_data_db(int seva_Type);
    void seva_type_adding();
    void seva_name_adding(int sevaT);
    DevotePersnalDetails* mobileNumberSearching(QString);
    void gotra_list();
    void Checking_sevacharge(QString);
    void receipt_no_printing();
    void booking_report_cdate_function(QString,QString,int);
    void booking_report_dataRange_function(QString,int,QString,QString);
    void booking_report_cmonth_function(QString,int,int,int);
    void booking_report_eachDateDataRange_function(QString,int,QString,QString);
    void booking_report_eachDateDataRangeForMonth_function(QString,int,int,int);
    void booking_report_eachMonth_function(QString SEVA,int TYPE,int month,int year);

    void account_report_cdate_function(QString, int, QString);
    void account_report_dataRange_function(QString,int,QString,QString);
    void account_report_eachDateDataRange_function(QString,int,QString,QString);
    void account_report_cmonth_function(QString ,int ,int ,int );
    void account_report_eachMonth_function(QString SEVA,int TYPE,int month,int year);
    void account_report_eachDateDataRangeForMonth_function(QString,int,int,int);
    void account_report_eachDateDataRangeForWholeMonth_function(QString,int,int,int);


    void voucher_report_cdate_function(QString,QString,QString);
    void voucher_report_cmonth_function(int, int, QString, QString);
    void voucher_report_dataRange_function(QString,QString,QString,QString);

    void fullAccounDetailsDateWise(QString, int, QString);              //Suman
    void fullAccounDetailsDateRangeWise(QString,int,QString,QString);   //Suman
    void fullAccounDetailsMonthwise(QString ,int ,int ,int );           //Suman

    void signin_clicked(QString, QString, int);
    void old_password(QString l_userfirstname, QString l_userlastname);
    void add_new_signin_details(QString, QString, QString, QString,int ,QString);
    QList<SigninDetails*> geting_signInDetails();
    void delete_selected_LoginDetails(QString);
    void modify_selected_LoginDetails(QString,QString,QString, QString, QString, QString);
    QStringList getMasterCredentials();
    void updateMasterCredentials(QString,QString,QString,QString);
    void bank_list();
    void modify_person_details(QString,QString,QString,QString,QString);

    QList<print_details*> printWithReceiptNumber(int receiptNumber);
    QString NumberToWord(const unsigned int number);

    //Raj
    bool checkCredentials(QString userID, QString pass);
    int getNextSevaId();
    QStringList qrySevaDates();
    bool qrySevabookingBySevaDate(QString);
    void qrySevabookingByDateRange(QString,QString);

    // Dheerendra added
    bool querySevaType();
    bool querySevaNames();
    QStringList qryNakshatras();
    QStringList qryGothras();
    QStringList qryBankList();
    bool add_seva_type(SevaType *sevaType);
    bool createSeva(SevaName *sevaName);
    void readSevaNamesFromJson();
    void readSevaTypesFromJson();
    DevotePersnalDetails* getPersonDetails(QString person_id);
    bool saveData(QObject *);
    int insertPersonDetails(QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra,QString address);

    int getLastReceiptNumber();
    int getLastVoucherNumber();
    int getLastSevatypeNumber(); //Suman N added
    int getLastSevaNameNumber(); //suman N added

    void getvoucherdata();  //Suman N added
    void getAccountData();  //Suman N added
    void deleteWrongData(QString rcptNum); //Suman N Added
    void recvDeletedRecptNo(QString recptNo); //Suman N added
    void modifySeva(int sevaId, QString sevaName,int cost,QString Date); //Suman N added
    void closeSeva(int SevaId);                                          //Suman N added

signals :
    void sendSevaType(SevaType *);
    void sendSevaName(SevaName *);
    void sendOneSevaBooking(SevaBookingElement*);
    void sendoneByoneSevaBooking(SevaBookingElement*);
    void setGrandTotalToZero();
    void dbError(QString errorMsg);
    void sendRolenumber(int rolenum,QString signInName);
    void sendVoucheronebyone(VoucherElement*); //Suman N
    void sendAcoountoneByone(AccountReportElement*); //Suman N
    void sendFullAccountDataElement(AccountFullreportElement*);
    void sendChangedDataToSevaBookingTablemodel(QString);
    void insert_Success(QString,QString,QString);
    void refreshModel(QString);
    void sendUpdateStatus(QString);
    void signalClose(int);
    void updateToDbFailed();

private:
    explicit DBInterface(QObject *parent=nullptr);
    int val;
    int last_s_no;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QString p_name,p_gotra, p_nakshtra, p_mobile,personid,p_sevaname,sevadate,note,que ;
    int  quantity,prasada;
    int total_prasada=0;
    QDate yy_date;
    PersonDetails *m_person;
    SevaTypeJsonProcessor* m_proc;
    QList<SevaBookingElement*> m_sevabooking;

    QString m_error;

};

#endif // DBFILE_H
