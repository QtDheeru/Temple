#include "ReportFilterElements.h"
#include <QDebug>
#include <QMetaEnum>
ReportFilterElements::ReportFilterElements(QObject *parent)
    : QObject{parent}
{
    this->setReportGenerationSource(ReportEnums::CLICK_ON_REPORT);
}

bool ReportFilterElements::bSevawise() const
{
    return m_bSevawise;
}

void ReportFilterElements::setBSevawise(bool newBSevawise)
{
    if(m_bSevawise == newBSevawise)
        return;
    m_bSevawise = newBSevawise;
    emit bSevawiseChanged();
}

bool ReportFilterElements::bDatewise() const
{
    return m_bDatewise;
}

void ReportFilterElements::setBDatewise(bool newBDatewise)
{
    if(m_bDatewise == newBDatewise)
        return;
    m_bDatewise = newBDatewise;
}

int ReportFilterElements::iSevaType() const
{
    return m_iSevaType;
}

void ReportFilterElements::setISevaType(int newISevaType)
{
    if(m_iSevaType == newISevaType)
        return;
    m_iSevaType = newISevaType;
}

const QString &ReportFilterElements::sSevaName() const
{
    return m_sSevaName;
}

void ReportFilterElements::setSSevaName(const QString &newSSevaName)
{
    if(m_sSevaName == newSSevaName)
        return;
    m_sSevaName = newSSevaName;
}

const QString &ReportFilterElements::sSingleDate() const
{
    return m_sSingleDate;
}

void ReportFilterElements::setSSingleDate(const QString &newSSingleDate)
{
    if(m_sSingleDate == newSSingleDate)
        return;
    m_sSingleDate = newSSingleDate;
}

const QString &ReportFilterElements::sStartDate() const
{
    return m_sStartDate;
}

void ReportFilterElements::setSStartDate(const QString &newSStartDate)
{
    if(  m_sStartDate == newSStartDate)
        return;
    m_sStartDate = newSStartDate;
}

const QString &ReportFilterElements::sEndDate() const
{
    return m_sEndDate;
}

void ReportFilterElements::setSEndDate(const QString &newSEndDate)
{
    if( m_sEndDate == newSEndDate)
        return;
    m_sEndDate = newSEndDate;
}

const QString &ReportFilterElements::sMonth() const
{
    return m_sMonth;
}

void ReportFilterElements::setSMonth(const QString &newSMonth)
{
    m_sMonth = newSMonth;
    emit sMonthChanged();
}

const QString &ReportFilterElements::sYear() const
{
    return m_sYear;
}

void ReportFilterElements::setSYear(const QString &newSYear)
{
    m_sYear = newSYear;
    emit sYearChanged();
}

int ReportFilterElements::iSelectedType() const
{
    return m_iSelectedType;
}

void ReportFilterElements::setISelectedType(int newISelectedType)
{
    m_iSelectedType = newISelectedType;
}

int ReportFilterElements::reportType() const
{
    return m_reportType;
}

void ReportFilterElements::setReportType(int newReportType)
{
    if (m_reportType == newReportType)
        return;
    m_reportType = newReportType;
    emit reportTypeChanged();
}

void ReportFilterElements::print()
{
    qDebug() << Q_FUNC_INFO << " **** Pritning the Filter Selection ******* "  << Qt::endl;
    if (bSevawise()){
        qDebug() << " Seva Wise Report = " << bSevawise();
    }
    if (bDatewise()){
        qDebug() << " Date Wise Report = " << bDatewise();
    }
    qDebug() << " SevaType Index =" << this->iSevaType() << " Name="<<this->sevaType();
    qDebug() << " SevaName Index =" << this->sevaNameIndex() << " Name  =" << this->sSevaName();
    QMetaEnum metaEnum = QMetaEnum::fromType<ReportEnums::REPORT_DATE_SELECTION_TYPE>();
    qDebug() << " Which Date Report = ?" << metaEnum.valueToKey(ReportEnums::REPORT_DATE_SELECTION_TYPE(this->iSelectedType()));

    QMetaEnum metaEnum1 = QMetaEnum::fromType<ReportEnums::REPORT_TYPE>();
    qDebug() << " TypeOfReport = " << metaEnum1.valueToKey(ReportEnums::REPORT_TYPE(this->reportType()));
    if (this->iSelectedType() == ReportEnums::SINGLE_DATE_REPORT){
        qDebug() << " Date Report. Date =" << this->sSingleDate();
    }
    if (this->iSelectedType() == ReportEnums::DATE_RANGE_REPORT){
        qDebug() << " Date Range Report. Start Date =" << this->sStartDate() << " EndDate="<<this->sEndDate();
    }
    if (this->iSelectedType() == ReportEnums::MONTH_REPORT){
        qDebug() << " Month Report. Year =" << this->sYear() << " Month =" << this->sMonth();
    }
}

QString ReportFilterElements::sevaType() const
{
    return m_sevaType;
}

void ReportFilterElements::setSevaType(const QString &newSevaType)
{
    if (m_sevaType == newSevaType)
        return;
    m_sevaType = newSevaType;
    emit sevaTypeChanged();
}

int ReportFilterElements::sevaNameIndex() const
{
    return m_sevaNameIndex;
}

void ReportFilterElements::setSevaNameIndex(int newSevaNameIndex)
{
    if (m_sevaNameIndex == newSevaNameIndex)
        return;
    m_sevaNameIndex = newSevaNameIndex;
    emit sevaNameIndexChanged();
}

ReportEnums::REPORT_GENERATION_SOURCE ReportFilterElements::reportGenerationSource() const
{
    return m_reportGenerationSource;
}

void ReportFilterElements::setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource)
{
    if (m_reportGenerationSource == newReportGenerationSource)
        return;
    m_reportGenerationSource = newReportGenerationSource;
    emit reportGenerationSourceChanged();
}
