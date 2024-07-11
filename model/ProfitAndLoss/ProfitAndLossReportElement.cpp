#include "ProfitAndLossReportElement.h"

ProfitAndLossReportElement::ProfitAndLossReportElement(QObject *parent)
    : QObject{parent}
{
    m_date = "";
    m_sevaBookedAmount = 0;
    m_expenditure = 0;
}

QString ProfitAndLossReportElement::date() const
{
    return m_date;
}

void ProfitAndLossReportElement::setDate(const QString &newDate)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_date = newDate;
}

long ProfitAndLossReportElement::sevaBookedAmount() const
{
    return m_sevaBookedAmount;
}

void ProfitAndLossReportElement::setSevaBookedAmount(const long &newSevaBookedAmount)
{
    m_sevaBookedAmount = newSevaBookedAmount;
}

long ProfitAndLossReportElement::expenditure() const
{
    return m_expenditure;
}

void ProfitAndLossReportElement::setExpenditure(const long &newExpenditure)
{
    m_expenditure = newExpenditure;
}

void ProfitAndLossReportElement::reset()
{
    m_date = "";
    m_sevaBookedAmount = 0;
    m_expenditure = 0;
    m_balance = 0;
}

int ProfitAndLossReportElement::slNo() const
{
    return m_slNo;
}

void ProfitAndLossReportElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}

QString ProfitAndLossReportElement::receiptNo() const
{
    return m_receiptNo;
}

void ProfitAndLossReportElement::setReceiptNo(const QString &newReceiptNo)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_receiptNo = newReceiptNo;
}

long ProfitAndLossReportElement::balance() const
{
    return m_balance;
}

void ProfitAndLossReportElement::setBalance(long newBalance)
{
    m_balance = newBalance;
}
