#include "AccountReportDateRangeElement.h"

AccountReportDateRangeElement::AccountReportDateRangeElement(QObject *parent)
    : QObject{parent}
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

AccountReportDateRangeElement::~AccountReportDateRangeElement()
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &AccountReportDateRangeElement::date() const
{
    return m_date;
}

void AccountReportDateRangeElement::setDate(const QString &newDate)
{
    m_date = newDate;
}

int AccountReportDateRangeElement::totalSevaCount() const
{
    return m_totalSevaCount;
}

void AccountReportDateRangeElement::setTotalSevaCount(int newTotalSevaCount)
{
    m_totalSevaCount = newTotalSevaCount;
}

float AccountReportDateRangeElement::totalAmount() const
{
    return m_totalAmount;
}

void AccountReportDateRangeElement::setTotalAmount(float newTotalAmount)
{
    m_totalAmount = newTotalAmount;
}

int AccountReportDateRangeElement::slNo() const
{
    return m_slNo;
}

void AccountReportDateRangeElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}
