#ifndef ACCOUNTREPORTMODEL_H
#define ACCOUNTREPORTMODEL_H

#include <QAbstractTableModel>
#include "./model/DBInterface.h"
#include <QDebug>
#include "AccountReportElement.h"
#include "ReportFilterElements.h"
#include "AccountReportCSVProcessor.h"
class AccountReportModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccountReportModel(QObject *parent = nullptr);
    ~AccountReportModel();
    Q_PROPERTY(float grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
     int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // bool insertSevaRow(SevaBookingElement *elm);
    void onDateSelectedAccountModel(QString);
    void onDateRangeSelectedAccountModel(QString,QString);
    bool insertSevaRow(AccountReportElement *elm);
    void generateAccReport(ReportFilterElements*);
    QString FormatDate(QString);
    void resetAccModel();

    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);
    Q_INVOKABLE int getAccountReportQryListSize();
    Q_INVOKABLE void setGrandTotalToZero();
    Q_INVOKABLE void generateAccountCSV();//Suman N

private:
    QList<AccountReportElement*> m_accountReportQryList;
    int m_iGrandTotal;
    AccountReportCSVProcessor *accountCSVProcessor ;

signals:
    void grandTotalChanged();
    void sendAccountReportList(QList<AccountReportElement*>);
    void successMessage(QString exportmsg);                    //Suman N
};

#endif // ACCOUNTREPORTMODEL_H
