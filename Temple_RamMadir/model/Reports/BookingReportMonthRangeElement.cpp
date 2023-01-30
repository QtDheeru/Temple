#include "BookingReportMonthRangeElement.h"

BookingReportMonthRangeElement::BookingReportMonthRangeElement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

BookingReportMonthRangeElement::~BookingReportMonthRangeElement()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int BookingReportMonthRangeElement::totalSevaCount() const
{
    return m_totalSevaCount;
}

void BookingReportMonthRangeElement::setTotalSevaCount(int newTotalSevaCount)
{
    if (m_totalSevaCount == newTotalSevaCount)
        return;
    m_totalSevaCount = newTotalSevaCount;
    emit totalSevaCountChanged();
}

const QString &BookingReportMonthRangeElement::month() const
{
    return m_month;
}

void BookingReportMonthRangeElement::setMonth(const QString &newMonth)
{
    if (m_month == newMonth)
        return;
    m_month = newMonth;
    emit monthChanged();
}

int BookingReportMonthRangeElement::slNo() const
{
    return m_slNo;
}

void BookingReportMonthRangeElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}
