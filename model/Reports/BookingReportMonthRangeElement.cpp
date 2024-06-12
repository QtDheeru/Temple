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

QString BookingReportMonthRangeElement::date() const
{
    return m_date;
}

void BookingReportMonthRangeElement::setDate(const QString &newDate)
{
    if (m_date == newDate)
        return;
    m_date = newDate;
    emit dateChanged();
}

QString BookingReportMonthRangeElement::year() const
{
    return m_year;
}

void BookingReportMonthRangeElement::setYear(const QString &newYear)
{
    if (m_year == newYear)
        return;
    m_year = newYear;
    emit yearChanged();
}

QString BookingReportMonthRangeElement::sevaTypeName() const
{
    return m_sevaTypeName;
}

void BookingReportMonthRangeElement::setSevaTypeName(const QString &newSevaTypeName)
{
    if (m_sevaTypeName == newSevaTypeName)
        return;
    m_sevaTypeName = newSevaTypeName;
    emit sevaTypeNameChanged();
}

QString BookingReportMonthRangeElement::sevaName() const
{
    return m_sevaName;
}

void BookingReportMonthRangeElement::setSevaName(const QString &newSevaName)
{
    if (m_sevaName == newSevaName)
        return;
    m_sevaName = newSevaName;
    emit sevaNameChanged();
}

int BookingReportMonthRangeElement::sevaType() const
{
    return m_sevaType;
}

void BookingReportMonthRangeElement::setSevaType(int newSevaType)
{
    if (m_sevaType == newSevaType)
        return;
    m_sevaType = newSevaType;
    emit sevaTypeChanged();
}

ReportEnums::REPORT_GENERATION_SOURCE BookingReportMonthRangeElement::reportGenerationSource() const
{
    return m_reportGenerationSource;
}

void BookingReportMonthRangeElement::setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource)
{
    if (m_reportGenerationSource == newReportGenerationSource)
        return;
    m_reportGenerationSource = newReportGenerationSource;
    emit reportGenerationSourceChanged();
}
