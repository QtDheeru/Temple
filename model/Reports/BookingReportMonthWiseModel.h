#ifndef BOOKINGREPORTMONTHWISEMODEL_H
#define BOOKINGREPORTMONTHWISEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include<QDebug>
#include "./model/DBInterface.h"
#include"BookingReportMonthRangeElement.h"
#include"ReportFilterElements.h"
class BookingReportMonthWiseModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BookingReportMonthWiseModel(QObject *parent = nullptr);
    ~BookingReportMonthWiseModel();
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);

    bool insertSevaRow(BookingReportMonthRangeElement *elm);
    void generateBookingMonthRangeReport(ReportFilterElements* elm);
    QString FormatDate(QString unformat);
    Q_INVOKABLE BookingReportMonthRangeElement *getBookingReportMonthRangeElementAt(int indx);
    void resetBookingMonthRangeModel();
      Q_INVOKABLE int getBookingReportMonthWiseQryListSize();

private:
    QList<BookingReportMonthRangeElement*> m_bookingReportMonthRangeQryList;
};

#endif // BOOKINGREPORTMONTHWISEMODEL_H
