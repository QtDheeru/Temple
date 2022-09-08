#ifndef SEVAVIEWPROXY_H
#define SEVAVIEWPROXY_H

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>
#include "./model/SevaListViewModel.h"
#include "./model/SevaName.h"
#include "./model/Seva/MySevaReceipt.h"
#include "./model/Reports/SevaDetailsTableViewModel.h"
#include "AllViewReports.h"
#include "SevaReport.h"
#include "SevaReceiptCsvProcessor.h"
#include <QDir>

class SevaTypeNamesDataModel;

class SevaViewProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString receiptNumber READ getReceiptNumber NOTIFY receiptNumberChanged)
    Q_PROPERTY(SevaDetailsTableView* allReportModel READ getAllReportModel NOTIFY allReportModelChanged)
    Q_PROPERTY(SevaReport* sevaReport READ reportOnDateModel  NOTIFY sevaReportChanged)
public:
    explicit SevaViewProxy(QObject *parent = nullptr);
    Q_INVOKABLE QAbstractItemModel* getSevaModel(int sevaType);
    Q_INVOKABLE QAbstractItemModel* getSevaTypeModel();
    Q_INVOKABLE QAbstractItemModel* getBookedView();
    Q_INVOKABLE bool resetBookView();

    Q_INVOKABLE SevaName* getSeva(int sevaType, int sevaId);
    Q_INVOKABLE SevaName* getSevaByIndex(int index);
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

    Q_INVOKABLE bool addSevaOnly(int sevaType,int sevaId,QString sevaName,
                                 double sevaCost, QString sevaDate, QString sevaTime,
                                 int additionalCost=0,int count=1);

    Q_INVOKABLE bool deleteSeva(int sevaId, QString sevaName);
    Q_INVOKABLE bool printReceipt();
    QString getReceiptNumber() const;

    Q_INVOKABLE DevotePersnalDetails* searchMobile(QString mobile);

    SevaDetailsTableView *getAllReportModel() const;
    void setAllReportModel(SevaDetailsTableView *allReportModel);

    Q_INVOKABLE bool showAllData();
    Q_INVOKABLE void addNewSeva(int sevaID,QString sevaName, int cost);
    Q_INVOKABLE int getNextSevaId();
    Q_INVOKABLE void addNewSevaType(QString sevaTypeName,QString personName);

    SevaReport *reportOnDateModel() const;
    void setReportOnDateModel(SevaReport *newReportOnDateModel);

public slots:
    Q_INVOKABLE void generateCSV();

signals:
    void receiptNumberChanged();
    void allReportModelChanged();
    void sevaReportChanged();

private :
    SevaTypeNamesDataModel *m_sevaBookingModelData;
    SevaListViewModel *m_currentSevaModel;
    SevaDetailsTableView *m_allReportModel;
    SevaReport *m_ReportOnDateModel;
    AllViewReports *m_allView;
    QString m_receiptNumber;
    SevaReceiptCsvProcessor *m_csvReceipt;
};

#endif // SEVAVIEWPROXY_H