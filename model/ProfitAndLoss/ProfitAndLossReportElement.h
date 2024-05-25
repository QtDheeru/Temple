#ifndef PROFITANDLOSSREPORTELEMENT_H
#define PROFITANDLOSSREPORTELEMENT_H

#include <QObject>
#include <QDebug>

class ProfitAndLossReportElement : public QObject
{
    Q_OBJECT

public:
    explicit ProfitAndLossReportElement(QObject *parent = nullptr);

    QString date() const;
    void setDate(const QString &newDate);

    long sevaBookedAmount() const;
    void setSevaBookedAmount(const long &newSevaBookedAmount);

    long expenditure() const;
    void setExpenditure(const long &newExpenditure);

    void reset();

    int slNo() const;
    void setSlNo(int newSlNo);

    QString receiptNo() const;
    void setReceiptNo(const QString &newReceiptNo);

signals:
    void balanceChanged();

private:
    QString m_date;
    long m_sevaBookedAmount;
    long m_expenditure;
    int m_slNo;
    QString m_receiptNo;

};

#endif // PROFITANDLOSSREPORTELEMENT_H
