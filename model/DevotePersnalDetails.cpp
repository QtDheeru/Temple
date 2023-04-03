#include "DevotePersnalDetails.h"
#include <QDebug>

DevotePersnalDetails::DevotePersnalDetails(QObject *parent) : QObject(parent)
  ,m_devoteeName("")
  ,m_mobileNumber("")
  ,m_gothra("")
  ,m_nakshatra("")
{

}

QString DevotePersnalDetails::devoteeName() const
{
    return m_devoteeName;
}

void DevotePersnalDetails::setDevoteeName(const QString &devoteeName)
{
    m_devoteeName = devoteeName;
}

QString DevotePersnalDetails::mobileNumber() const
{
    return m_mobileNumber;
}

void DevotePersnalDetails::setMobileNumber(const QString &mobileNumber)
{
    m_mobileNumber = mobileNumber;
}

QString DevotePersnalDetails::gothra() const
{
    return m_gothra;
}

void DevotePersnalDetails::setGothra(const QString &gothra)
{
    m_gothra = gothra;
}

QString DevotePersnalDetails::nakshatra() const
{
    return m_nakshatra;
}

void DevotePersnalDetails::setNakshatra(const QString &nakshatra)
{
    m_nakshatra = nakshatra;
}

void DevotePersnalDetails::print()
{
     qDebug() << " Name =" << this->devoteeName();
     qDebug() << " Nakshatra " << this->nakshatra();
     qDebug() << " Gothra " << this->gothra() <<Qt::endl;
     qDebug() << " Mobile " << this->mobileNumber() <<Qt::endl;
}

QString DevotePersnalDetails::personDbId() const
{
    return m_personDbId;
}

void DevotePersnalDetails::setPersonDbId(const QString &personDbId)
{
    m_personDbId = personDbId;
}
