#include "SevaName.h"
#include <QDebug>

SevaName::SevaName(QObject *parent) : QObject(parent)
          ,m_count(1)
          ,m_additionalCost(0)
{
     m_sankalpa = false;
}

SevaName::~SevaName()
{
    qDebug() << Q_FUNC_INFO << " Seva Object is getting destroyed " << Qt::endl;
}

void SevaName::setSevaName(const QString &sevaName)
{
    m_sevaName = sevaName;
}

int SevaName::sevaId() const
{
    return m_sevaId;
}

void SevaName::setSevaId(int sevaId)
{
    m_sevaId = sevaId;
}

int SevaName::Number() const
{
    return m_Number;
}

void SevaName::setNumber(int Number)
{
    m_Number = Number;
}

int SevaName::sevaType() const
{
    return m_sevaType;
}

void SevaName::setSevaType(int sevaType)
{
    m_sevaType = sevaType;
}

double SevaName::sevaCost() const
{
    return m_sevaCost;
}

void SevaName::setSevaCost(double sevaCost)
{
    m_sevaCost = sevaCost;
}

int SevaName::teerthaPrasada() const
{
    return m_teerthaPrasada;
}

void SevaName::setTeerthaPrasada(int teerthaPrasada)
{
    m_teerthaPrasada = teerthaPrasada;
}

QString SevaName::sevaStartDate() const
{
    return m_sevaStartDate;
}

void SevaName::setSevaStartDate(const QString &sevaDate)
{
    m_sevaStartDate = sevaDate;
}

void SevaName::print()
{
    qDebug() << Q_FUNC_INFO << " Seva Name   =" << this->sevaName();
    qDebug() << Q_FUNC_INFO << " Seva ID     =" << this->sevaId();
    qDebug() << Q_FUNC_INFO << " Seva Number =" << this->Number();
    qDebug() << Q_FUNC_INFO << " Seva        =" << this->sevaCost();
    qDebug() << Q_FUNC_INFO << " Seva Date   =" << this->sevaStartDate();
    qDebug() << Q_FUNC_INFO << " Seva Type   =" << this->sevaType();
    qDebug() << Q_FUNC_INFO << " Seva Cost   =" << this->sevaCost();
    qDebug() << Q_FUNC_INFO << " Seva Count  =" << this->count();
    qDebug() << Q_FUNC_INFO << " Additional Cost =" << this->additionalCost();
    qDebug() << Q_FUNC_INFO << " Seva Time  =" << this->sevaStartTime();
}

int SevaName::count() const
{
    return m_count;
}

void SevaName::setCount(int count)
{
    qDebug() << Q_FUNC_INFO << " Seva count=  " << count << Qt::endl;
    m_count = count;
}

int SevaName::additionalCost() const
{
    return m_additionalCost;
}

void SevaName::setAdditionalCost(int additionalCost)
{
    qDebug() << Q_FUNC_INFO << " Seva additionalCost=  " << additionalCost << Qt::endl;
    m_additionalCost = additionalCost;
}

QString SevaName::sevaStartTime() const
{
    return m_sevaStartTime;
}

void SevaName::setSevaStartTime(const QString &sevaTime)
{
    m_sevaStartTime = sevaTime;
}

QString SevaName::userName() const
{
    return m_userName;
}

void SevaName::setUserName(const QString &userName)
{
    m_userName = userName;
}

bool SevaName::sankalpa() const
{
    return m_sankalpa;
}

void SevaName::setSankalpa(bool sankalpa)
{
    m_sankalpa = sankalpa;
}

QString SevaName::sevaEndTime() const
{
    return m_sevaEndTime;
}

void SevaName::setSevaEndTime(const QString &sevaEndTime)
{
    m_sevaEndTime = sevaEndTime;
}

bool SevaName::enable() const
{
    return m_enable;
}

void SevaName::setEnable(bool enable)
{
    m_enable = enable;
}

QString SevaName::sevaEndDate() const
{
    return m_sevaEndDate;
}

void SevaName::setSevaEndDate(const QString &sevaEndDate)
{
    m_sevaEndDate = sevaEndDate;
}

const QString SevaName::status() const
{
    return m_status;
}

void SevaName::setStatus(const QString &newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}

QString SevaName::sevaName() const
{
    return m_sevaName;
}
