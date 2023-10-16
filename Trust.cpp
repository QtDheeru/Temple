#include "Trust.h"

Trust::Trust(QObject *parent)
    : QObject{parent}
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

Trust::~Trust()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &Trust::trustName() const
{
    return m_trustName;
}

void Trust::setTrustName(const QString &newTrustName)
{
    m_trustName = newTrustName;
}

const QString &Trust::trustCode() const
{
    return m_trustCode;
}

void Trust::setTrustCode(const QString &newTrustCode)
{
    m_trustCode = newTrustCode;
}
