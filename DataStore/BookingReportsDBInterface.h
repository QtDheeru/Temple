#ifndef BOOKINGREPORTSDBINTERFACE_H
#define BOOKINGREPORTSDBINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include "ReportFilterElements.h"
#include "BookingReportElement.h"
#include "BookingReportDateRangeElement.h"
#include "BookingReportMonthRangeElement.h"
#include "../Print/common.h"
#include "../DevotePersnalDetails.h"

#define ALLSEVANAME "All"

class BookingReportsDBInterface : public QObject
{
    Q_OBJECT
public:
    explicit BookingReportsDBInterface(QSqlDatabase db,QObject *parent = nullptr);
    bool generateBookingSingleDateReport(ReportFilterElements *elm);
    bool generateBookingDateRangeReort(ReportFilterElements *elm);
    bool generateBookingMonthReport(ReportFilterElements *elm);
    bool generateBookingReportForEachDateOfMonth(ReportFilterElements *elm);
    bool generateBookingReportForEachDateInDateRange(ReportFilterElements *elm);
    bool generateBookingReportForAllMonths(ReportFilterElements *elm);

signals:
    void booking_report(BookingReportElement *ace);
    void booking_report_Date_Range(BookingReportDateRangeElement *ace);
    void booking_report_Month_Range(BookingReportMonthRangeElement *ace);

private:
    QSqlDatabase m_db;
    int m_totalPrasada=0;
    int m_quantity , m_prasada;
    QString m_name, p_gotra, m_nakshtra, m_mobile, m_personid, m_sevaname, m_sevadate, m_note ;
    QDate m_date;

    int  getSevaTypeID(QString seva_type_string);
};

#endif // BOOKINGREPORTSDBINTERFACE_H
