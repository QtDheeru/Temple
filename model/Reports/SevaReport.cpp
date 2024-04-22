#include "SevaReport.h"

SevaReport::SevaReport(QObject *parent)
    : QObject{parent}
{
    m_sevaOnDateModel = new SevaDetailsOnDateModel;
    m_accountreportModel = new AccountReportModel;
    m_reportElements = new ReportFilterElements;
    m_bookingReportModel = new BookingReportModel;
    m_accountReportDateRangeModel = new AccountReportDateRangeModel;
    m_accountReportMonthRangeModel = new AccountReportMonthWiseModel;
    m_bookingReportDateRangeModel = new BookingReportDateRangeModel;
    m_bookingReportMonthWiseModel = new BookingReportMonthWiseModel;
    m_accountFullReportModel = new AccountFullReportModel;
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

BookingReportModel *SevaReport::bookingReportModel() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_bookingReportModel;
}

AccountReportDateRangeModel *SevaReport::accountReportDateRangeModel() const
{
    return m_accountReportDateRangeModel;
}

void SevaReport::setAccountReportDateRangeModel(AccountReportDateRangeModel *newAccountReportDateRangeModel)
{
    m_accountReportDateRangeModel = newAccountReportDateRangeModel;
}

AccountReportMonthWiseModel *SevaReport::accountReportMonthRangeModel() const
{
    return m_accountReportMonthRangeModel;
}

void SevaReport::setAccountReportMonthRangeModel(AccountReportMonthWiseModel *newAccountReportMonthRangeModel)
{
    m_accountReportMonthRangeModel = newAccountReportMonthRangeModel;
}

BookingReportDateRangeModel *SevaReport::bookingReportDateRangeModel() const
{
    return m_bookingReportDateRangeModel;
}

void SevaReport::setBookingReportDateRangeModel(BookingReportDateRangeModel *newBookingReportDateRangeModel)
{
    m_bookingReportDateRangeModel = newBookingReportDateRangeModel;
}

BookingReportMonthWiseModel *SevaReport::bookingReportMonthWiseModel() const
{
    return m_bookingReportMonthWiseModel;
}

void SevaReport::setBookingReportMonthWiseModel(BookingReportMonthWiseModel *newBookingReportMonthWiseModel)
{
    m_bookingReportMonthWiseModel = newBookingReportMonthWiseModel;
}

AccountFullReportModel *SevaReport::accountFullReportModel() const
{
    return m_accountFullReportModel;
}

void SevaReport::setAccountFullReportModel(AccountFullReportModel *newAccountFullReportModel)
{
    if (m_accountFullReportModel == newAccountFullReportModel)
        return;
    m_accountFullReportModel = newAccountFullReportModel;
    emit accountFullReportModelChanged();
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
}

void SevaReport::generateAccReportForEachDate(ReportFilterElements *ele)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_accountReportDateRangeModel->generateAccDateRangeReport(ele);
}

void SevaReport::generateAccReportForEachDateForWholeMonth(ReportFilterElements *ele)
{
  m_accountReportDateRangeModel->generateAccDateRangeReportForWholeMonth(ele);
}

void SevaReport::generateAccReportForEachMonth(ReportFilterElements *ele)
{
    qDebug()<<Q_FUNC_INFO<<ele->sMonth()<<Qt::endl;
    //ele->
    m_accountReportMonthRangeModel->generateAccMonthRangeReport(ele);
}

void SevaReport::generateBookReport(ReportFilterElements *ele)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_bookingReportModel->generateBookReport(ele);
    qDebug()<<ele->bDatewise()<<Qt::endl;
    qDebug()<<ele->sSingleDate()<<Qt::endl;
}

void SevaReport::generateBookingReportForEachDate(ReportFilterElements *ele)
{
     qDebug()<<Q_FUNC_INFO<<Qt::endl;
     m_bookingReportDateRangeModel->generateBookingDateRangeReport(ele);
}

void SevaReport::generateBookingReportForEachDateForWholeMonth(ReportFilterElements *ele)
{
      qDebug()<<Q_FUNC_INFO<<Qt::endl;
      m_bookingReportDateRangeModel->generateBookingDateRangeReportForWholeMonth(ele);
}

void SevaReport::generateBookingReportForEachMonth(ReportFilterElements *ele)
{
    qDebug()<<Q_FUNC_INFO<<ele->sMonth()<<Qt::endl;

    m_bookingReportMonthWiseModel->generateBookingMonthRangeReport(ele);
}

void SevaReport::resetAccModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_accountreportModel->resetAccModel();
}

void SevaReport::resetAccDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_accountReportDateRangeModel->resetAccDateRangeModel();
}

void SevaReport::resetAccMonthRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_accountReportMonthRangeModel->resetAccMonthRangeModel();
}

void SevaReport::resetBookingModel()
{
    m_bookingReportModel->resetBookingModel();
}

void SevaReport::resetBookingDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_bookingReportDateRangeModel->resetBookingDateRangeModel();
}

void SevaReport::resetBookingMonthRangeModel()
{
 m_bookingReportMonthWiseModel->resetBookingMonthRangeModel();
}
