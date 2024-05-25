#ifndef SEVAREPORT_H
#define SEVAREPORT_H

#include <QObject>
#include <QDebug>
#include <QSortFilterProxyModel>
#include "SevaBookingElement.h"
#include "SevaDetailsOnDateModel.h"
#include "AccountReportElement.h"
#include "AccountReportModel.h"
#include "ReportFilterElements.h"
#include "BookingReportModel.h"
#include "BookingReportElement.h"
#include "AccountReportDateRangeModel.h"
#include "AccountReportMonthWiseModel.h"
#include "BookingReportDateRangeModel.h"
#include "BookingReportMonthWiseModel.h"
#include "AccountFullReportModel.h"
#include "ProfitAndLossDataModel.h"

class SevaReport : public QObject
{
    Q_OBJECT
public:
    explicit SevaReport(QObject *parent = nullptr);
    Q_PROPERTY(SevaDetailsOnDateModel* reportOnDateModel READ sevaOnDateModel NOTIFY ReportOnDateModelChanged)
    Q_PROPERTY(AccountReportModel* accReportModel READ accountreportModel NOTIFY AccReportModelChanged)
    Q_PROPERTY(BookingReportModel* bookReportModel READ bookingReportModel NOTIFY bookReportModelChanged)
    Q_PROPERTY(AccountReportDateRangeModel* accountReportDateRangeModel READ accountReportDateRangeModel NOTIFY AccReportDateRangeModelChanged)
    Q_PROPERTY(AccountReportMonthWiseModel* accountReportMonthRangeModel READ accountReportMonthRangeModel NOTIFY AccReportMonthRangeModelChanged)
    Q_PROPERTY(ReportFilterElements* reportElements READ getReportElements  NOTIFY reportElementsChanged)
    Q_PROPERTY(AccountFullReportModel *accountFullReportModel READ accountFullReportModel WRITE setAccountFullReportModel NOTIFY accountFullReportModelChanged)
    Q_PROPERTY(BookingReportDateRangeModel* bookingReportDateRangeModel READ bookingReportDateRangeModel NOTIFY BookingReportDateRangeModelChanged)
    Q_PROPERTY(BookingReportMonthWiseModel* bookingReportMonthWiseModel READ bookingReportMonthWiseModel NOTIFY BookingReportMonthRangeModelChanged)
    Q_PROPERTY(ProfitAndLossDataModel *profitAndLossDataModel READ profitAndLossDataModel WRITE setProfitAndLossDataModel RESET resetProfitAndLossDataModel NOTIFY profitAndLossDataModelChanged FINAL)

    void setSevaOnDateModel(SevaDetailsOnDateModel *newSevaOnDateModel);
    SevaDetailsOnDateModel *sevaOnDateModel() const;

    const QList<SevaBookingElement *> &sevaDetailsOnDateRange() const;
    void setSevaDetailsOnDateRange(const QList<SevaBookingElement *> &newSevaDetailsOnDateRange);

    AccountReportModel *accountreportModel() const;
    void setAccountreportModel(AccountReportModel *newAccountreportModel);

    ReportFilterElements* getReportElements() const;
    BookingReportModel *bookingReportModel() const;

    AccountReportDateRangeModel *accountReportDateRangeModel() const;
    void setAccountReportDateRangeModel(AccountReportDateRangeModel *newAccountReportDateRangeModel);

    AccountReportMonthWiseModel *accountReportMonthRangeModel() const;
    void setAccountReportMonthRangeModel(AccountReportMonthWiseModel *newAccountReportMonthRangeModel);

    BookingReportDateRangeModel *bookingReportDateRangeModel() const;
    void setBookingReportDateRangeModel(BookingReportDateRangeModel *newBookingReportDateRangeModel);

    BookingReportMonthWiseModel *bookingReportMonthWiseModel() const;
    void setBookingReportMonthWiseModel(BookingReportMonthWiseModel *newBookingReportMonthWiseModel);

    AccountFullReportModel *accountFullReportModel() const;
    void setAccountFullReportModel(AccountFullReportModel *newAccountFullReportModel);

    ProfitAndLossDataModel *profitAndLossDataModel() const;
    void setProfitAndLossDataModel(ProfitAndLossDataModel *newProfitAndLossDataModel);
    void resetProfitAndLossDataModel();

private:
    SevaDetailsOnDateModel *m_sevaOnDateModel;
    AccountReportModel *m_accountreportModel;
    BookingReportModel *m_bookingReportModel;
    ReportFilterElements *m_reportElements;
    AccountReportDateRangeModel* m_accountReportDateRangeModel;
    AccountReportMonthWiseModel* m_accountReportMonthRangeModel;
    BookingReportDateRangeModel* m_bookingReportDateRangeModel;
    BookingReportMonthWiseModel* m_bookingReportMonthWiseModel;
    AccountFullReportModel* m_accountFullReportModel = nullptr;
    ProfitAndLossDataModel* m_profitAndLossDataModel;
    // QList<SevaBookingElement*> m_sevaDetailsOnDate;

public slots:
    void onDateSelected(QString);
    void onDateRangeSelected(QString,QString);

    void onDateSelectedAccountModel(QString);
    void onDateRangeSelectedAccountModel(QString,QString);

    void generateAccReport(ReportFilterElements*);
    void generateAccReportForEachDate(ReportFilterElements*);
    void generateAccReportForEachDateForWholeMonth(ReportFilterElements*);
    void generateAccReportForEachMonth(ReportFilterElements*);

    void generateBookReport(ReportFilterElements*);
    void generateBookingReportForEachDate(ReportFilterElements*);
    void generateBookingReportForEachDateForWholeMonth(ReportFilterElements*);
    void generateBookingReportForEachMonth(ReportFilterElements*);

    void resetAccModel();
    void resetAccDateRangeModel();
    void resetAccMonthRangeModel();

    void resetBookingModel();
    void resetBookingDateRangeModel();
    void resetBookingMonthRangeModel();

signals:
    void ReportOnDateModelChanged();
    void AccReportModelChanged();
    void reportElementsChanged();
    void bookReportModelChanged();
    void AccReportDateRangeModelChanged();
    void AccReportMonthRangeModelChanged();

    void BookingReportDateRangeModelChanged();
    void BookingReportMonthRangeModelChanged();

    void accountFullReportModelChanged();
    void profitAndLossDataModelChanged();
};

#endif // SEVAREPORT_H
