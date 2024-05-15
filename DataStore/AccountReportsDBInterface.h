#ifndef ACCOUNTREPORTSDBINTERFACE_H
#define ACCOUNTREPORTSDBINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include "ReportFilterElements.h"
#include "AccountReportElement.h"

#define ALL_SEVA_REPORT "All"

class AccountReportsDBInterface : public QObject
{
    Q_OBJECT
public:
    explicit AccountReportsDBInterface(QSqlDatabase db, QObject *parent = nullptr);
    bool generateSingleDateReport(ReportFilterElements *elm);
    bool generateDateRangeReport(ReportFilterElements *elm);
    bool generateMonthReport(ReportFilterElements *elm);

private :
    int  getSevaTypeID(QString seva_type_string);

signals:
    void account_report(AccountReportElement *ace);

private :
    QSqlDatabase m_db;
};

#endif // ACCOUNTREPORTSDBINTERFACE_H
