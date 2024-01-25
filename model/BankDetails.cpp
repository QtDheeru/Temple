#include "BankDetails.h"

BankDetails::BankDetails(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_bankId = 0;
}

BankDetails::~BankDetails()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &BankDetails::bankName() const
{
    return m_bankName;
}

void BankDetails::setBankName(const QString &newBankName)
{
    m_bankName = newBankName;
}

int BankDetails::bankId() const
{
    return m_bankId;
}

void BankDetails::setBankId(int newBankId)
{
    m_bankId = newBankId;
}
