#include "SevaCountOnDateData.h"

SevaCountOnDateData::SevaCountOnDateData()
{

}

const QDate &SevaCountOnDateData::Date() const
{
    return m_Date;
}

void SevaCountOnDateData::setDate(const QDate &newDate)
{
    m_Date = newDate;
}

int SevaCountOnDateData::Count() const
{
    return m_Count;
}

void SevaCountOnDateData::setCount(int newCount)
{
    m_Count = newCount;
}
