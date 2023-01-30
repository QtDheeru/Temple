#ifndef BOOKINGREPORTMONTHRANGEELEMENT_H
#define BOOKINGREPORTMONTHRANGEELEMENT_H

#include <QObject>
#include<QDebug>
class BookingReportMonthRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)

public:
    explicit BookingReportMonthRangeElement(QObject *parent = nullptr);
    ~BookingReportMonthRangeElement();

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

    const QString &month() const;
    void setMonth(const QString &newMonth);

    int slNo() const;
    void setSlNo(int newSlNo);

signals:
    void monthChanged();
    void totalSevaCountChanged();

private:
    int m_slNo;
    QString m_month;
    int m_totalSevaCount;

};

#endif // BOOKINGREPORTMONTHRANGEELEMENT_H
