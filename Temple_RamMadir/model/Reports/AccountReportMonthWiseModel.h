#ifndef ACCOUNTREPORTMONTHWISEMODEL_H
#define ACCOUNTREPORTMONTHWISEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include<QDebug>
#include "./model/DBInterface.h"
#include"AccountReportMonthRangeElement.h"
#include"ReportFilterElements.h"
class AccountReportMonthWiseModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AccountReportMonthWiseModel(QObject *parent = nullptr);
    ~AccountReportMonthWiseModel();
 Q_PROPERTY(float grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);

    bool insertSevaRow(AccountReportMonthRangeElement *elm);
    void generateAccMonthRangeReport(ReportFilterElements* elm);
    QString FormatDate(QString unformat);
    Q_INVOKABLE AccountReportMonthRangeElement *getAccountReportMonthRangeElementAt(int indx);
    void resetAccMonthRangeModel();
      Q_INVOKABLE int getAccountReportMonthWiseQryListSize();

private:
    QList<AccountReportMonthRangeElement*> m_accountReportMonthRangeQryList;
    int m_iGrandTotal;
signals:
    void grandTotalChanged();
};

#endif // ACCOUNTREPORTMONTHWISEMODEL_H
