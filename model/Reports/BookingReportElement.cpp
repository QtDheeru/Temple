#include "BookingReportElement.h"

BookingReportElement::BookingReportElement(QObject *parent)
    : QObject{parent}
{

}

const QString &BookingReportElement::name() const
{
    return m_name;
}

void BookingReportElement::setName(const QString &newName)
{
    m_name = newName;
}

const QString &BookingReportElement::gothra() const
{
    return m_gothra;
}

void BookingReportElement::setGothra(const QString &newGothra)
{
    m_gothra = newGothra;
}

const QString &BookingReportElement::nakshatra() const
{
    return m_nakshatra;
}

void BookingReportElement::setNakshatra(const QString &newNakshatra)
{
    m_nakshatra = newNakshatra;
}

const QString &BookingReportElement::sevaName() const
{
    return m_sevaName;
}

void BookingReportElement::setSevaName(const QString &newSevaName)
{
    m_sevaName = newSevaName;
}

int BookingReportElement::teerthaPrasada() const
{
    return m_teerthaPrasada;
}

void BookingReportElement::setTeerthaPrasada(int newTeerthaPrasada)
{
    m_teerthaPrasada = newTeerthaPrasada;
}

const QString &BookingReportElement::mobileNumber() const
{
    return m_mobileNumber;
}

void BookingReportElement::setMobileNumber(const QString &newMobileNumber)
{
    m_mobileNumber = newMobileNumber;
}

const QString &BookingReportElement::note() const
{
    return m_note;
}

void BookingReportElement::setNote(const QString &newNote)
{
    m_note = newNote;
}
