#ifndef BOOKINGREPORTDATERANGEMODEL_H
#define BOOKINGREPORTDATERANGEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include"BookingReportDateRangeElement.h"
#include<QDebug>
#include "ReportFilterElements.h"
#include "./model/DBInterface.h"
class BookingReportDateRangeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BookingReportDateRangeModel(QObject *parent = nullptr);
    ~BookingReportDateRangeModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool insertSevaRow(BookingReportDateRangeElement *elm);
    void generateBookingDateRangeReport(ReportFilterElements* elm);
   void generateBookingDateRangeReportForWholeMonth(ReportFilterElements* ele);
    QString FormatDate(QString unformat);
    Q_INVOKABLE BookingReportDateRangeElement *getBookingReportDateRangeElementAt(int indx);
    void resetBookingDateRangeModel();
       Q_INVOKABLE int getBookingReportDateRangeQryList();
private:
  QList<BookingReportDateRangeElement*> m_bookingReportDateRangeQryList;
  //int m_iGrandTotal;
};

#endif // BOOKINGREPORTDATERANGEMODEL_H
