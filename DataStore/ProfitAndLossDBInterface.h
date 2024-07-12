#ifndef PROFITANDLOSSDBINTERFACE_H
#define PROFITANDLOSSDBINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QQmlEngine>
#include <QSqlError>
#include <QDate>
#include "ReportFilterElements.h"
#include "AccountReportElement.h"
#include "AccountFullreportElement.h"
#include "VoucherReportElement.h"

#define ALL_SEVA_REPORT "All"

class ProfitAndLossDBInterface : public QObject
{
    Q_OBJECT
public:
    explicit ProfitAndLossDBInterface(QSqlDatabase db,QObject *parent = nullptr);
    ~ProfitAndLossDBInterface();

    bool generateSingleDateReport(ReportFilterElements *elm);
    bool generateSingleDateReportForSevaBooking(ReportFilterElements *elm);
    bool generateSingleDateReportForVoucher(ReportFilterElements *elm);

    bool generateDateRangeReport(ReportFilterElements *elm);
    bool generateDateRangeReportForSevaBooking(ReportFilterElements *elm);
    bool generateDateRangeReportForVoucher(ReportFilterElements *elm);

    bool generateMonthReport(ReportFilterElements *elm);
    bool generateMonthReportForSevaBooking(ReportFilterElements *elm);
    bool generateMonthReportForVoucher(ReportFilterElements *elm);

signals:
    void profitAndLossSevaBookingReport(AccountReportElement *ace);
    void profitAndLossVoucherReport(VoucherReportElement *elm);

    void profitNLoss_DateRange_SevaBooked_report(AccountReportElement *ele);
    void profitNLoss_DateRange_Voucher_report(VoucherReportElement *ele);

    void profitNLoss_Month_SevaBooked_report(AccountReportElement *ele);
    void profitNLoss_Month_Voucher_report(VoucherReportElement *ele);

private:
    QSqlDatabase m_db;
    int getSevaTypeID(QString seva_type_string);
    AccountReportElement *getNewAccountElement();
    QList<QString> pay_mode={"cash","Cheque","NEFT","UPI"};
};

#endif // PROFITANDLOSSDBINTERFACE_H
