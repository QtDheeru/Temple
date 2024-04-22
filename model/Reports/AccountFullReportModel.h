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
    Q_PROPERTY(double iGrandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY iGrandTotalChanged)
    Q_PROPERTY(double neftTotal READ neftTotal WRITE setNeftTotal NOTIFY neftTotalChanged)
    Q_PROPERTY(double cashTotal READ cashTotal WRITE setCashTotal NOTIFY cashTotalChanged)
    Q_PROPERTY(double chequeTotal READ chequeTotal WRITE setChequeTotal NOTIFY chequeTotalChanged)
    Q_PROPERTY(double upiTotal READ upiTotal WRITE setUpiTotal NOTIFY upiTotalChanged)
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

    double iGrandTotal() const;
    void setIGrandTotal(double newIGrandTotal);
    AccountReportCSVProcessor *getAccountCSVProcessor() const;
    void setAccountCSVProcessor(AccountReportCSVProcessor *newAccountCSVProcessor);

    double neftTotal() const;
    void setNeftTotal(double newNeftTotal);

    double cashTotal() const;
    void setCashTotal(double newCashTotal);

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
    double m_iGrandTotal;
    double m_neftTotal;
    double m_cashTotal;
    double m_chequeTotal;
    double m_upiTotal;
    double m_unknownTypeTotal;

    Account_Summary *m_accountSummary;
    AccountReportCSVProcessor *accountCSVProcessor = nullptr;
 };

#endif // ACCOUNTFULLREPORTMODEL_H
