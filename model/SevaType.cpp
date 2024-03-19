#include "SevaType.h"

SevaType::SevaType(QObject *parent) : QObject(parent)
{

}

SevaType::~SevaType()
{
    qDebug() << Q_FUNC_INFO << this->objectName()<< " Seva Type is destroyed" << Qt::endl;
}

QString SevaType::sevaTypeName() const
{
    return m_sevaTypeName;
}

void SevaType::setSevaTypeName(const QString &sevaTypeName)
{
    m_sevaTypeName = sevaTypeName;
}

int SevaType::sevaTypeId() const
{
    return m_sevaTypeId;
}

void SevaType::setSevaTypeId(int sevaTypeId)
{
    m_sevaTypeId = sevaTypeId;
}

bool SevaType::printMe()
{
    return true;
}

QString SevaType::userName() const
{
    return m_userName;
}

void SevaType::setUserName(const QString &userName)
{
    m_userName = userName;
}

int SevaType::sevaTypeSeqNumber() const
{
    return m_sevaTypeSeqNumber;
}

void SevaType::setSevaTypeSeqNumber(const int &sevaTypeSeqNumber)
{
    m_sevaTypeSeqNumber = sevaTypeSeqNumber;
}
