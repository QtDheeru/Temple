#ifndef ACCOUNTREPORTDATERANGEMODEL_H
#define ACCOUNTREPORTDATERANGEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include"AccountReportDateRangeElement.h"
#include<QDebug>
#include "ReportFilterElements.h"
#include "./model/DBInterface.h"
class AccountReportDateRangeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AccountReportDateRangeModel(QObject *parent = nullptr);
    ~AccountReportDateRangeModel();
   Q_PROPERTY(float grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
   // QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);

      bool insertSevaRow(AccountReportDateRangeElement *elm);
      void generateAccDateRangeReport(ReportFilterElements* elm);
     void generateAccDateRangeReportForWholeMonth(ReportFilterElements* ele);
      QString FormatDate(QString unformat);
      Q_INVOKABLE AccountReportDateRangeElement *getAccountReportDateRangeElementAt(int indx);
      void resetAccDateRangeModel();
        Q_INVOKABLE int getAccountReportDateRangeQryListSize();
private:
    QList<AccountReportDateRangeElement*> m_accountReportDateRangeQryList;
    int m_iGrandTotal;
signals:
    void grandTotalChanged();
};

#endif // ACCOUNTREPORTDATERANGEMODEL_H
