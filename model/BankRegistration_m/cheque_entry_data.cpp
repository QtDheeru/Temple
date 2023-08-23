#include "cheque_entry_data.h"

Cheque_Entry_Data::Cheque_Entry_Data(QObject *parent)
    : QObject{parent}
{

}

QString Cheque_Entry_Data::receiptDate() const
{
    return m_receiptDate;
}

void Cheque_Entry_Data::setReceiptDate(const QString &newReceiptDate)
{
    m_receiptDate = newReceiptDate;
    emit receiptDateChanged();
}

QString Cheque_Entry_Data::bank() const
{
    return m_bank;
}

void Cheque_Entry_Data::setBank(const QString &newBank)
{
    m_bank = newBank;
    emit bankChanged();
}

QString Cheque_Entry_Data::receiptNumber() const
{
    return m_receiptNumber;
}

void Cheque_Entry_Data::setReceiptNumber(const QString &newReceiptNumber)
{
    m_receiptNumber = newReceiptNumber;
    emit receiptNumberChanged();
}

QString Cheque_Entry_Data::amount() const
{
    return m_amount;
}

void Cheque_Entry_Data::setAmount(const QString &newAmount)
{
    m_amount = newAmount;
    emit amountChanged();
}

QString Cheque_Entry_Data::chequeDate() const
{
    return m_chequeDate;
}

void Cheque_Entry_Data::setChequeDate(const QString &newChequeDate)
{
    m_chequeDate = newChequeDate;
    emit chequeDateChanged();
}
