#ifndef ACCOUNTFULLREPORTMODEL_H
#define ACCOUNTFULLREPORTMODEL_H

#include <QObject>
#include <QDebug>
#include "AccountFullreportElement.h"
#include "AccountReportCSVProcessor.h"
#include "ReportFilterElements.h"
#include <QAbstractTableModel>
#include "./model/DBInterface.h"
#include "common.h"

class AccountFullReportModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int iGrandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY iGrandTotalChanged)
    Q_PROPERTY(int neftTotal READ neftTotal WRITE setNeftTotal NOTIFY neftTotalChanged)
    Q_PROPERTY(int cashTotal READ cashTotal WRITE setCashTotal NOTIFY cashTotalChanged)
    Q_PROPERTY(int chequeTotal READ chequeTotal WRITE setChequeTotal NOTIFY chequeTotalChanged)
    Q_PROPERTY(int upiTotal READ upiTotal WRITE setUpiTotal NOTIFY upiTotalChanged)
    // QAbstractItemModel interface
    Q_PROPERTY(double unknownTypeTotal READ unknownTypeTotal WRITE setUnknownTypeTotal NOTIFY unknownTypeTotalChanged FINAL)

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
        additionalCost,
        status
    };

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void resetAccModel();
    Q_INVOKABLE void generateFullAccountDataCSV();

    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);
    AccountReportCSVProcessor *getAccountCSVProcessor() const;
    void setAccountCSVProcessor(AccountReportCSVProcessor *newAccountCSVProcessor);

    int neftTotal() const;
    void setNeftTotal(int newNeftTotal);

    int cashTotal() const;
    void setCashTotal(int newCashTotal);

    double chequeTotal() const;
    void setChequeTotal(double newChequeTotal);

    double upiTotal() const;
    void setUpiTotal(double newUpiTotal);

    double unknownTypeTotal() const;
    void setUnknownTypeTotal(double newUnknownTypeTotal);

signals:

    void iGrandTotalChanged();
    void cashTotalChanged();
    void neftTotalChanged();
    void chequeTotalChanged();
    void upiTotalChanged();

    void sendAccountFullreportElementList(QList<AccountFullreportElement*>);
    void accountCSVProcessorChanged();
    void successMessage(QString exportmsg);

    void unknownTypeTotalChanged();

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
    int m_neftTotal;
    int  m_cashTotal;
    double m_chequeTotal;
    double m_upiTotal;
    double m_unknownTypeTotal;

    Account_Summary *m_accountSummary;
    AccountReportCSVProcessor *accountCSVProcessor = nullptr;
 };

#endif // ACCOUNTFULLREPORTMODEL_H
