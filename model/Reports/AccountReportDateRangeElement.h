#ifndef ACCOUNTREPORTDATERANGEELEMENT_H
#define ACCOUNTREPORTDATERANGEELEMENT_H

#include <QObject>
#include <QDebug>
class AccountReportDateRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)
    Q_PROPERTY(float totalAmount READ totalAmount WRITE setTotalAmount NOTIFY totalAmountChanged)
public:
    explicit AccountReportDateRangeElement(QObject *parent = nullptr);
    ~AccountReportDateRangeElement();
    const QString &date() const;
    void setDate(const QString &newDate);

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

    float totalAmount() const;
    void setTotalAmount(float newTotalAmount);

    int slNo() const;
    void setSlNo(int newSlNo);

signals:
    void dateChanged();
    void totalSevaCountChanged();
    void totalAmountChanged();
private:
    int m_slNo;
    QString m_date;
    int m_totalSevaCount;
    float m_totalAmount;

};

#endif // ACCOUNTREPORTDATERANGEELEMENT_H
