#include "SevaReport.h"

SevaReport::SevaReport(QObject *parent)
    : QObject{parent}
{
    m_sevaOnDateModel = new SevaDetailsOnDateModel;
    m_accountreportModel = new AccountReportModel;
    m_reportElements = new ReportFilterElements;
}



void SevaReport::setSevaOnDateModel(SevaDetailsOnDateModel *newSevaOnDateModel)
{
    m_sevaOnDateModel = newSevaOnDateModel;
}

SevaDetailsOnDateModel *SevaReport::sevaOnDateModel() const
{
    return m_sevaOnDateModel;
}

AccountReportModel *SevaReport::accountreportModel() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_accountreportModel;
}

void SevaReport::setAccountreportModel(AccountReportModel *newAccountreportModel)
{
    m_accountreportModel = newAccountreportModel;
}

ReportFilterElements *SevaReport::getReportElements() const
{
    return m_reportElements;
}


void SevaReport::onDateSelected(QString date)
{
    m_sevaOnDateModel->onDateSelected(date);
}

void SevaReport::onDateRangeSelected(QString startDate, QString endDate)
{
    m_sevaOnDateModel->onDateRangeSelected(startDate,endDate);
}

void SevaReport::onDateSelectedAccountModel(QString date)
{
    m_accountreportModel->onDateSelectedAccountModel(date);
}

void SevaReport::onDateRangeSelectedAccountModel(QString start, QString end)
{
    m_accountreportModel->onDateRangeSelectedAccountModel(start,end);
}

void SevaReport::generateAccReport(ReportFilterElements* ele)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_accountreportModel->generateAccReport(ele);
    qDebug()<<ele->bDatewise()<<Qt::endl;
    qDebug()<<ele->sSingleDate()<<Qt::endl;
}
