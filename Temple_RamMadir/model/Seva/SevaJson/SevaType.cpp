#include "SevaType.h"

SevaType::SevaType(QObject *parent)
    : QObject{parent}
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

SevaType::~SevaType()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &SevaType::name() const
{
    return m_name;
}

void SevaType::setName(const QString &newName)
{
    m_name = newName;
}

const QString &SevaType::sevaTypeCode() const
{
    return m_sevaTypeCode;
}

void SevaType::setSevaTypeCode(const QString &newSevaTypeCode)
{
    m_sevaTypeCode = newSevaTypeCode;
}

const QString &SevaType::userName() const
{
    return m_userName;
}

void SevaType::setUserName(const QString &newUserName)
{
    m_userName = newUserName;
}
