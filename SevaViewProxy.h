#ifndef SEVAVIEWPROXY_H
#define SEVAVIEWPROXY_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QAbstractListModel>
#include "./model/SevaListViewModel.h"
#include "./model/SevaName.h"
#include "./model/Seva/MySevaReceipt.h"
#include "./model/Reports/SevaDetailsTableViewModel.h"
#include "AllViewReports.h"

#include "SevaReport.h"
#include "SevaReceiptCsvProcessor.h"
#include "SevaBookingTableModel.h"
#include "SevaBookingSearchModel.h"
#include "./model/SevaTypeViewModel.h"
#include "./model/UserManagement.h"
#include "VoucherReportCSVProcessor.h"
#include "model/SevaCancelModel.h"

class SevaTypeNamesDataModel;

class SevaViewProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString receiptNumber READ getReceiptNumber NOTIFY receiptNumberChanged)
    Q_PROPERTY(SevaDetailsTableView* allReportModel READ getAllReportModel NOTIFY allReportModelChanged)
    Q_PROPERTY(SevaReport* sevaReport READ reportOnDateModel  NOTIFY sevaReportChanged)
    Q_PROPERTY(SevaBookingSearchModel* sevaBSearchModel READ sevaBSearchModel NOTIFY sevaBookingSearchModelChanged)
    Q_PROPERTY(SevaBookingTableModel* sevaBookingTV READ sevaBookingTV NOTIFY sevaBookingTVChanged)
    Q_PROPERTY(UserManagement* userManagement READ userMngmnt CONSTANT)
    Q_PROPERTY(SevaTypeNamesDataModel *sevaBookingModelData READ sevaBookingModelData CONSTANT)
    Q_PROPERTY(SevaCancelModel *mysevacancelmodel READ sevacancelmodel WRITE setSevacancelmodel NOTIFY mydataChanged )


public:
    explicit SevaViewProxy(QObject *parent = nullptr);
    Q_INVOKABLE QAbstractItemModel* getSevaModel(int sevaType);
    Q_INVOKABLE QAbstractItemModel* getSevaTypeModel();
    Q_INVOKABLE QAbstractItemModel* getBookedView();
    Q_INVOKABLE bool resetBookView();

    Q_INVOKABLE SevaName* getSeva(int sevaType, int sevaId);
    Q_INVOKABLE SevaName* getSevaByIndex(int index);
    Q_INVOKABLE SevaType*  getSevaTypeByIndex(int index);
    Q_INVOKABLE void print(int sevaType, int sevaId);

    Q_INVOKABLE QStringList getNakshatras();
    Q_INVOKABLE QStringList getGothras();
    Q_INVOKABLE QStringList getBankList();
    Q_INVOKABLE QString     getNextReceiptNumber();
    Q_INVOKABLE QStringList getMomentoCategory();

    Q_INVOKABLE bool saveReceiptDetails(QString recNumber,
                                        QString devName,
                                        QString mobNumber,
                                        QString nakshatra,
                                        QString gothra);
    Q_INVOKABLE bool saveReceipt(MySevaReceipt *receipt);

    Q_INVOKABLE void deleteRecipt(QString rcptNo);
    Q_INVOKABLE void setStatusToCancel(QString rcptNo);
    void checkIfStatusAlreadyCanceled(QString);

    Q_INVOKABLE bool addSevaOnly(int sevaType,int sevaId,QString sevaName,
                                 double sevaCost, QString sevaDate, QString sevaTime,
                                 int additionalCost=0,int count=1);

    Q_INVOKABLE bool deleteSeva(int sevaId, QString sevaName);
    Q_INVOKABLE bool closeSeva(int sevaId);
    Q_INVOKABLE bool modifySeva(int sevaId, QString sevaName,int cost,QString Date);
    Q_INVOKABLE bool printReceipt();
    Q_INVOKABLE bool printVoucherReceipt(VoucherElement* voucherElement);
    Q_INVOKABLE bool printBookingReceipt(SevaBookingElement* sevaBookingElement);
    QString getReceiptNumber() const;

    Q_INVOKABLE DevotePersnalDetails* searchMobile(QString mobile);

    SevaDetailsTableView *getAllReportModel() const;
    void setAllReportModel(SevaDetailsTableView *allReportModel);

    Q_INVOKABLE bool showAllData();
    Q_INVOKABLE void addNewSeva(int sevaID,QString sevaName, int cost);
    Q_INVOKABLE int getNextSevaId();
    Q_INVOKABLE int getNextSevaTypeID();
    Q_INVOKABLE QString addNewSevaType(QString sevaTypeName,int sevaTypeId,QString personName);
    Q_INVOKABLE QString createNewSeva(SevaName *seva);
    Q_INVOKABLE void deletedata(QString rcptNo);
    void print();
    Q_INVOKABLE QAbstractItemModel* getSevaModelForErrorHandling();
    SevaReport *reportOnDateModel() const;
    void setReportOnDateModel(SevaReport *newReportOnDateModel);

    Q_INVOKABLE SevaTypeNamesDataModel * getSevaTypeNamesDataModel();
    SevaBookingSearchModel *sevaBSearchModel() const;
    SevaBookingTableModel *sevaBookingTV() const;

    Q_INVOKABLE void addNewSigninDetails(QString name,QString lastname,QString userid,QString password ,int rolenumber,QString date);

    UserManagement *userMngmnt() const;

    SevaTypeNamesDataModel *sevaBookingModelData() const;

    Q_INVOKABLE bool removeSevaProgress(int index,QString);

    SevaCancelModel *m_sevacancelmodel;

    QList<SevaBookingElement *> recpt_details() const;
    void setRecpt_details(const QList<SevaBookingElement *> &newRecpt_details);

    SevaCancelModel *sevacancelmodel() const;
    void setSevacancelmodel(SevaCancelModel *newSevacancelmodel);

    void getDataReceipt(QString);

public slots:
    void generateCSVSevaBookingReport();
    void getAllAccountDetails();
    void rcvclosedStatus(QString status);
    void recvUpdateStatus(QString);
    void cancelReceipt(QString);

signals:
    void receiptNumberChanged();
    void allReportModelChanged();
    void sevaReportChanged();
    void sevaBookingSearchModelChanged();
    void sevaBookingTVChanged();
    void errorMessage(QString errMsg);
    void successMessage(QString exportmsg);
    void collectAllAccountsdata();
    void sendDeletedRecptNo(QString);
    void devoteeTableModelChanged();
    void devoteeSearchModelChanged();
    void sendStatustoQml(QString status);
    void sendUpdateStatustoQml(QString updateStatus);
    void mydataChanged();
    void statusAlreadyCancelled();

private :
    SevaTypeNamesDataModel *m_sevaBookingModelData;
    SevaListViewModel *m_currentSevaModel;
    SevaDetailsTableView *m_allReportModel;
    SevaReport *m_ReportOnDateModel;
    AllViewReports *m_allView;
    QString m_receiptNumber;
    SevaReceiptCsvProcessor *m_csvReceipt;
    VoucherReportCSVProcessor* m_voucherReportCSv;
    SevaBookingTableModel *m_sevaBookingTV;
    SevaBookingSearchModel *m_sevaBSearchModel;
    SevaTypeViewModel *m_sevaTypeModel;
    UserManagement* m_userMngmnt;

    QList<SevaBookingElement*> m_recpt_details;

};

#endif // SEVAVIEWPROXY_H
