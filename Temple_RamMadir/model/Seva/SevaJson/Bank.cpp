#include "Bank.h"

Bank::Bank(QObject *parent)
    : QObject{parent}
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

Bank::~Bank()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &Bank::bankName() const
{
    return m_bankName;
}

void Bank::setBankName(const QString &newBankName)
{
    m_bankName = newBankName;
}

int Bank::bankId() const
{
    return m_bankId;
}

void Bank::setBankId(int newBankId)
{
    m_bankId = newBankId;
}
