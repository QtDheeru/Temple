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

QString BookingReportDateRangeElement::sevaTypeName() const
{
    return m_sevaTypeName;
}

void BookingReportDateRangeElement::setSevaTypeName(const QString &newSevaTypeName)
{
    if (m_sevaTypeName == newSevaTypeName)
        return;
    m_sevaTypeName = newSevaTypeName;
    emit sevaTypeNameChanged();
}

ReportEnums::REPORT_GENERATION_SOURCE BookingReportDateRangeElement::reportGenerationSource() const
{
    return m_reportGenerationSource;
}

void BookingReportDateRangeElement::setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource)
{
    if (m_reportGenerationSource == newReportGenerationSource)
        return;
    m_reportGenerationSource = newReportGenerationSource;
    emit reportGenerationSourceChanged();
}

int BookingReportDateRangeElement::sevaType() const
{
    return m_sevaType;
}

void BookingReportDateRangeElement::setSevaType(int newSevaType)
{
    if (m_sevaType == newSevaType)
        return;
    m_sevaType = newSevaType;
    emit sevaTypeChanged();
}

QString BookingReportDateRangeElement::sevaName() const
{
    return m_sevaName;
}

void BookingReportDateRangeElement::setSevaName(const QString &newSevaName)
{
    if (m_sevaName == newSevaName)
        return;
    m_sevaName = newSevaName;
    emit sevaNameChanged();
}
