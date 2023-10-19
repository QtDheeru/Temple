#ifndef ACCOUNTREPORTMONTHRANGEELEMENT_H
#define ACCOUNTREPORTMONTHRANGEELEMENT_H

#include <QObject>
#include<QDebug>
class AccountReportMonthRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)
    Q_PROPERTY(float totalAmount READ totalAmount WRITE setTotalAmount NOTIFY totalAmountChanged)
public:
    explicit AccountReportMonthRangeElement(QObject *parent = nullptr);
    ~AccountReportMonthRangeElement();

    const QString &month() const;
    void setMonth(const QString &newMonth);

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

    float totalAmount() const;
    void setTotalAmount(float newTotalAmount);

    int slNo() const;
    void setSlNo(int newSlNo);

signals:
    void monthChanged();
    void totalSevaCountChanged();
    void totalAmountChanged();
private:
    int m_slNo;
    QString m_month;
    int m_totalSevaCount;
    float m_totalAmount;

};

#endif // ACCOUNTREPORTMONTHRANGEELEMENT_H
