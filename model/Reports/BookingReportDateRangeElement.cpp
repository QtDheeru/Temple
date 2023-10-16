#include "BookingReportDateRangeElement.h"

BookingReportDateRangeElement::BookingReportDateRangeElement(QObject *parent)
    : QObject{parent}
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

BookingReportDateRangeElement::~BookingReportDateRangeElement()
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int BookingReportDateRangeElement::slNo() const
{
    return m_slNo;
}

void BookingReportDateRangeElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}

const QString &BookingReportDateRangeElement::date() const
{
    return m_date;
}

void BookingReportDateRangeElement::setDate(const QString &newDate)
{
    m_date = newDate;
    emit dateChanged();
}

int BookingReportDateRangeElement::totalSevaCount() const
{
    return m_totalSevaCount;
}

void BookingReportDateRangeElement::setTotalSevaCount(int newTotalSevaCount)
{
    if (m_totalSevaCount == newTotalSevaCount)
        return;
    m_totalSevaCount = newTotalSevaCount;
    emit totalSevaCountChanged();
}
