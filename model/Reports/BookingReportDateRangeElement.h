#ifndef BOOKINGREPORTDATERANGEELEMENT_H
#define BOOKINGREPORTDATERANGEELEMENT_H

#include <QObject>
#include<QDebug>
class BookingReportDateRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)
public:
    explicit BookingReportDateRangeElement(QObject *parent = nullptr);
    ~BookingReportDateRangeElement();


    int slNo() const;
    void setSlNo(int newSlNo);

    const QString &date() const;
    void setDate(const QString &newDate);

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

signals:
    void dateChanged();
    void totalSevaCountChanged();
    void totalAmountChanged();
private:
    int m_slNo;
    QString m_date;
    int m_totalSevaCount;


};

#endif // BOOKINGREPORTDATERANGEELEMENT_H
