#ifndef BOOKINGREPORTMODEL_H
#define BOOKINGREPORTMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "./model/DBInterface.h"
#include "BookingReportElement.h"
#include "ReportFilterElements.h"
#include <QDebug>
#include "SevaReceiptCsvProcessor.h"
class BookingReportModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BookingReportModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool insertSevaRow(BookingReportElement *elm);
    void generateBookReport(ReportFilterElements*);
    QString FormatDate(QString);
    void resetBookingModel();
    Q_INVOKABLE int getBookingReportQryListSize();
    Q_INVOKABLE void generateBookingReportCSV(); //Suman N
signals:
    void sendBookingReportList( QList<BookingReportElement*>); //suman N
    void successMessage(QString exportmsg);                      //Suman N
private:
    QList<BookingReportElement*> m_bookingReportQryList;
    SevaReceiptCsvProcessor* sevaCSVProcessor;                //Suman N
};

#endif // BOOKINGREPORTMODEL_H
