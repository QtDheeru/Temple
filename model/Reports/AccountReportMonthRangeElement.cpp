#include "AccountReportMonthRangeElement.h"

AccountReportMonthRangeElement::AccountReportMonthRangeElement(QObject *parent)
    : QObject{parent}
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

AccountReportMonthRangeElement::~AccountReportMonthRangeElement()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &AccountReportMonthRangeElement::month() const
{
    return m_month;
}

void AccountReportMonthRangeElement::setMonth(const QString &newMonth)
{
    m_month = newMonth;
}

int AccountReportMonthRangeElement::totalSevaCount() const
{
    return m_totalSevaCount;
}

void AccountReportMonthRangeElement::setTotalSevaCount(int newTotalSevaCount)
{
    m_totalSevaCount = newTotalSevaCount;
}

float AccountReportMonthRangeElement::totalAmount() const
{
    return m_totalAmount;
}

void AccountReportMonthRangeElement::setTotalAmount(float newTotalAmount)
{
    m_totalAmount = newTotalAmount;
}

int AccountReportMonthRangeElement::slNo() const
{
    return m_slNo;
}

void AccountReportMonthRangeElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}
