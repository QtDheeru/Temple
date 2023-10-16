#include "VoucherFilterElements.h"

VoucherFilterElements::VoucherFilterElements(QObject *parent)
    : QObject{parent}
{

}

const QString &VoucherFilterElements::sVoucherType() const
{
    return m_sVoucherType;
}

void VoucherFilterElements::setSVoucherType(const QString &newSVoucherType)
{
    m_sVoucherType = newSVoucherType;
    emit sVoucherTypeChanged();
}

const QString &VoucherFilterElements::sPaymentMode() const
{
    return m_sPaymentMode;
}

void VoucherFilterElements::setSPaymentMode(const QString &newSPaymentMode)
{
    m_sPaymentMode = newSPaymentMode;
    emit sPaymentModeChanged();
}

const QString &VoucherFilterElements::sSingleDate() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sSingleDate;
}

void VoucherFilterElements::setSSingleDate(const QString &newSSingleDate)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(m_sSingleDate == newSSingleDate)
        return;
    m_sSingleDate = newSSingleDate;
    emit sSingleDateChanged();
}

const QString &VoucherFilterElements::sStartDate() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sStartDate;
}

void VoucherFilterElements::setSStartDate(const QString &newSStartDate)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(  m_sStartDate == newSStartDate)
        return;
    m_sStartDate = newSStartDate;
    emit sStartDateChanged();
}

const QString &VoucherFilterElements::sEndDate() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sEndDate;
}

void VoucherFilterElements::setSEndDate(const QString &newSEndDate)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if( m_sEndDate == newSEndDate)
        return;
    m_sEndDate = newSEndDate;
    emit sEndDateChanged();
}

const QString &VoucherFilterElements::sMonth() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sMonth;
}

void VoucherFilterElements::setSMonth(const QString &newSMonth)
{
    qDebug()<<Q_FUNC_INFO<<newSMonth<<Qt::endl;
    if(  m_sMonth == newSMonth)
        return;
    m_sMonth = newSMonth;
    emit sMonthChanged();
}

const QString &VoucherFilterElements::sYear() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sYear;
}

void VoucherFilterElements::setSYear(const QString &newSYear)
{
    qDebug()<<Q_FUNC_INFO<<newSYear<<Qt::endl;
    if(  m_sYear == newSYear)
        return;
    m_sYear = newSYear;
    emit sYearChanged();
}

int VoucherFilterElements::iSelectedType() const
{
    return m_iSelectedType;
}

void VoucherFilterElements::setISelectedType(int newISelectedType)
{
    m_iSelectedType = newISelectedType;
    emit iSelectedTypeChanged();
}
