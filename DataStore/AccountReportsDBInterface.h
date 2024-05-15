#ifndef ACCOUNTREPORTSDBINTERFACE_H
#define ACCOUNTREPORTSDBINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include "ReportFilterElements.h"
#include "AccountReportElement.h"
#include "AccountFullreportElement.h"

#define ALL_SEVA_REPORT "All"

class AccountReportsDBInterface : public QObject
{
    Q_OBJECT
public:
    explicit AccountReportsDBInterface(QSqlDatabase db, QObject *parent = nullptr);
    bool generateSingleDateReport(ReportFilterElements *elm);
    bool generateDateRangeReport(ReportFilterElements *elm);
    bool generateMonthReport(ReportFilterElements *elm);
    bool generateReportForEachDateOfMonth(ReportFilterElements *elm);
    bool generateReportForEachDateInDateRange(ReportFilterElements *elm);
    bool fullAccounDetailsDateWise(QString sevaName, int sevaType, QString reportDate);
    bool fullAccounDetailsDateWise(ReportFilterElements *elm);

private :
    int  getSevaTypeID(QString seva_type_string);

signals:
    void account_report(AccountReportElement *ace);
    void account_report_Date_Range(AccountReportElement *ele);
    void sendFullAccountDataElement(AccountFullreportElement *ele);

private :
    QSqlDatabase m_db;
    QList<QString> pay_mode={"cash","Cheque","NEFT","UPI"};
};

#endif // ACCOUNTREPORTSDBINTERFACE_H
