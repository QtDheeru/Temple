#ifndef ACCOUNTREPORTMODEL_H
#define ACCOUNTREPORTMODEL_H

#include <QAbstractListModel>
#include "./model/DBInterface.h"
#include <QDebug>
#include "AccountReportElement.h"
#include "ReportFilterElements.h"
class AccountReportModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit AccountReportModel(QObject *parent = nullptr);
    Q_PROPERTY(float grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // bool insertSevaRow(SevaBookingElement *elm);
    void onDateSelectedAccountModel(QString);
    void onDateRangeSelectedAccountModel(QString,QString);
    bool insertSevaRow(AccountReportElement *elm);
    void generateAccReport(ReportFilterElements*);
    QString FormatDate(QString);

    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);


private:
    QList<AccountReportElement*> m_accountReportQryList;
    int m_iGrandTotal;

    signals:
    void grandTotalChanged();
};

#endif // ACCOUNTREPORTMODEL_H
