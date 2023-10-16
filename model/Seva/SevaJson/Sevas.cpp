#include "Sevas.h"

Sevas::Sevas(QObject *parent)
    : QObject{parent}
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

Sevas::~Sevas()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &Sevas::sevaName() const
{
    return m_sevaName;
}

void Sevas::setSevaName(const QString &newSevaName)
{
    m_sevaName = newSevaName;
}

const QString &Sevas::userName() const
{
    return m_userName;
}

void Sevas::setUserName(const QString &newUserName)
{
    m_userName = newUserName;
}

const QString &Sevas::sevaCode() const
{
    return m_sevaCode;
}

void Sevas::setSevaCode(const QString &newSevaCode)
{
    m_sevaCode = newSevaCode;
}

const QString &Sevas::sevaType() const
{
    return m_sevaType;
}

void Sevas::setSevaType(const QString &newSevaType)
{
    m_sevaType = newSevaType;
}

const QString &Sevas::sevaCost() const
{
    return m_sevaCost;
}

void Sevas::setSevaCost(const QString &newSevaCost)
{
    m_sevaCost = newSevaCost;
}

const QString &Sevas::theerthaPrasada() const
{
    return m_theerthaPrasada;
}

void Sevas::setTheerthaPrasada(const QString &newTheerthaPrasada)
{
    m_theerthaPrasada = newTheerthaPrasada;
}

const QString &Sevas::poojaTime() const
{
    return m_poojaTime;
}

void Sevas::setPoojaTime(const QString &newPoojaTime)
{
    m_poojaTime = newPoojaTime;
}

const QString &Sevas::sevaDate() const
{
    return m_sevaDate;
}

void Sevas::setSevaDate(const QString &newSevaDate)
{
    m_sevaDate = newSevaDate;
}

const QString &Sevas::sevaTime() const
{
    return m_sevaTime;
}

void Sevas::setSevaTime(const QString &newSevaTime)
{
    m_sevaTime = newSevaTime;
}
