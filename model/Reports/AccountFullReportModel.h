#ifndef ACCOUNTFULLREPORTMODEL_H
#define ACCOUNTFULLREPORTMODEL_H

#include <QObject>
#include <QDebug>
#include "AccountFullreportElement.h"
#include "AccountReportCSVProcessor.h"
#include "ReportFilterElements.h"
#include <QAbstractTableModel>
#include "./model/DBInterface.h"

class AccountFullReportModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int iGrandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY iGrandTotalChanged)
    Q_PROPERTY(AccountReportCSVProcessor *accountCSVProcessor READ getAccountCSVProcessor WRITE setAccountCSVProcessor NOTIFY accountCSVProcessorChanged)
public:
    explicit AccountFullReportModel(QObject *parent = nullptr);
    ~AccountFullReportModel();
    enum roles{
        recieptnumber=0,
        recptDate,
        sevadate,
        sevaname,
        sevacost,
        sevaCount,
        devoteeName,
        mobile,
        paymentmode,
        total,
        status
    };

signals:

    void iGrandTotalChanged();
    void sendAccountFullreportElementList(QList<AccountFullreportElement*>);
    void accountCSVProcessorChanged();
    void successMessage(QString exportmsg);
public slots:
    void insertrows(AccountFullreportElement*);

    void generateAccountReport(ReportFilterElements*);
    void generateFullAccountReportEachdate(ReportFilterElements*);
    void generateFullAccountReportForDateRange(ReportFilterElements*);
    void generateFullAccountReportForMonth(ReportFilterElements*);
    int  getaccountFullreportElementListSize();
    QString FormatDate(QString unformat);

    void setGrandTotalToZero();
private:
    QList<AccountFullreportElement*> m_accountFullreportElementList;
    int m_iGrandTotal;
    AccountReportCSVProcessor *accountCSVProcessor = nullptr;
    // QAbstractItemModel interface


public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void resetAccModel();
    Q_INVOKABLE void generateFullAccountDataCSV();

    // QAbstractItemModel interface
public:

    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);
    AccountReportCSVProcessor *getAccountCSVProcessor() const;
    void setAccountCSVProcessor(AccountReportCSVProcessor *newAccountCSVProcessor);
};

#endif // ACCOUNTFULLREPORTMODEL_H