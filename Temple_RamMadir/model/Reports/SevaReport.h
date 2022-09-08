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

class SevaReport : public QObject
{
    Q_OBJECT
public:
    explicit SevaReport(QObject *parent = nullptr);
    Q_PROPERTY(SevaDetailsOnDateModel* reportOnDateModel READ sevaOnDateModel NOTIFY ReportOnDateModelChanged)
    Q_PROPERTY(AccountReportModel* accReportModel READ accountreportModel NOTIFY AccReportModelChanged)
    Q_PROPERTY(ReportFilterElements* reportElements READ getReportElements  NOTIFY reportElementsChanged)




    void setSevaOnDateModel(SevaDetailsOnDateModel *newSevaOnDateModel);

    SevaDetailsOnDateModel *sevaOnDateModel() const;

    const QList<SevaBookingElement *> &sevaDetailsOnDateRange() const;
    void setSevaDetailsOnDateRange(const QList<SevaBookingElement *> &newSevaDetailsOnDateRange);

    AccountReportModel *accountreportModel() const;
    void setAccountreportModel(AccountReportModel *newAccountreportModel);

    ReportFilterElements* getReportElements() const;

private:
    SevaDetailsOnDateModel *m_sevaOnDateModel;
    AccountReportModel *m_accountreportModel;
    ReportFilterElements *m_reportElements;


    // QList<SevaBookingElement*> m_sevaDetailsOnDate;

public slots:
    void onDateSelected(QString);
    void onDateRangeSelected(QString,QString);

    void onDateSelectedAccountModel(QString);
    void onDateRangeSelectedAccountModel(QString,QString);
    void generateAccReport(ReportFilterElements*);

signals:
    void ReportOnDateModelChanged();
    void AccReportModelChanged();
    void reportElementsChanged();


};

#endif // SEVAREPORT_H
