#ifndef BOOKINGREPORTSDBINTERFACE_H
#define BOOKINGREPORTSDBINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include "ReportFilterElements.h"
#include "BookingReportElement.h"
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

signals:
    void booking_report(BookingReportElement *ace);
    // void persondetails(QString,QString,QString,QString,QString,QString);

public slots:
    // void to_persondetails_db(QString , QString , QString , QString , QString , QString , QString , QString , QString , QString );
    // void getpersondetails(QString);

    // DevotePersnalDetails* getPersonDetails(QString person_id);
    // int insertPersonDetails(QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra,QString address);

private:
    int total_prasada=0;
    QSqlDatabase m_db;
    PersonDetails *m_person;
    int  getSevaTypeID(QString seva_type_string);
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QString p_name,p_gotra, p_nakshtra, p_mobile,personid,p_sevaname,sevadate,note,que ;
    int  quantity,prasada;
    QDate yy_date;
};

#endif // BOOKINGREPORTSDBINTERFACE_H
