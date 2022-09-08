#include "ReportFilterElements.h"
#include <QDebug>
ReportFilterElements::ReportFilterElements(QObject *parent)
    : QObject{parent}
{

}

bool ReportFilterElements::bSevawise() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_bSevawise;
}

void ReportFilterElements::setBSevawise(bool newBSevawise)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_bSevawise == newBSevawise)
        return;
    m_bSevawise = newBSevawise;
    emit bSevawiseChanged();
}

bool ReportFilterElements::bDatewise() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_bDatewise;
}

void ReportFilterElements::setBDatewise(bool newBDatewise)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_bDatewise == newBDatewise)
        return;
    m_bDatewise = newBDatewise;
}

int ReportFilterElements::iSevaType() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_iSevaType;
}

void ReportFilterElements::setISevaType(int newISevaType)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_iSevaType == newISevaType)
        return;
    m_iSevaType = newISevaType;
}

const QString &ReportFilterElements::sSevaName() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sSevaName;
}

void ReportFilterElements::setSSevaName(const QString &newSSevaName)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_sSevaName == newSSevaName)
        return;
    m_sSevaName = newSSevaName;
}

const QString &ReportFilterElements::sSingleDate() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sSingleDate;
}

void ReportFilterElements::setSSingleDate(const QString &newSSingleDate)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_sSingleDate == newSSingleDate)
        return;
    m_sSingleDate = newSSingleDate;
}

const QString &ReportFilterElements::sStartDate() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sStartDate;
}

void ReportFilterElements::setSStartDate(const QString &newSStartDate)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(  m_sStartDate == newSStartDate)
        return;
    m_sStartDate = newSStartDate;
}

const QString &ReportFilterElements::sEndDate() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sEndDate;
}

void ReportFilterElements::setSEndDate(const QString &newSEndDate)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if( m_sEndDate == newSEndDate)
        return;
    m_sEndDate = newSEndDate;
}

const QString &ReportFilterElements::sMonth() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sMonth;
}

void ReportFilterElements::setSMonth(const QString &newSMonth)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(  m_sMonth == newSMonth)
        return;
    m_sMonth = newSMonth;
}

const QString &ReportFilterElements::sYear() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_sYear;
}

void ReportFilterElements::setSYear(const QString &newSYear)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(  m_sYear == newSYear)
        return;
    m_sYear = newSYear;
}
