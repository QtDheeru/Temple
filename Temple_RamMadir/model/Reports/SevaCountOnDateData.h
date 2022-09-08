#ifndef SEVACOUNTONDATEDATA_H
#define SEVACOUNTONDATEDATA_H
#include <QString>
#include <QDate>
class SevaCountOnDateData
{
public:
    SevaCountOnDateData();

    const QDate &Date() const;
    void setDate(const QDate &newDate);

    int Count() const;
    void setCount(int newCount);

private:
    QDate m_Date;
    int m_Count;

};

#endif // SEVACOUNTONDATEDATA_H
