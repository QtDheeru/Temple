#include "SevaBookingElement.h"
#include <QDebug>

SevaBookingElement::SevaBookingElement(QObject *parent) : QObject(parent)
{

}

QString SevaBookingElement::sno() const
{
    return m_sno;
}

void SevaBookingElement::setSno(const QString &sno)
{
    m_sno = sno;
}

QString SevaBookingElement::person_id() const
{
    return m_person_id;
}

void SevaBookingElement::setPerson_id(const QString &person_id)
{
    m_person_id = person_id;
}

QString SevaBookingElement::sevatype() const
{
    return m_sevatype;
}

void SevaBookingElement::setSevatype(const QString &sevatype)
{
    m_sevatype = sevatype;
}

QString SevaBookingElement::sevaname() const
{
    return m_sevaname;
}

void SevaBookingElement::setSevaname(const QString &sevaname)
{
    m_sevaname = sevaname;
}

QString SevaBookingElement::quantity() const
{
    return m_quantity;
}

void SevaBookingElement::setQuantity(const QString &quantity)
{
    m_quantity = quantity;
}

void SevaBookingElement::print()
{
     qDebug() << Q_FUNC_INFO << " SNO      =" << this->sno() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << " SName    =" << this->sevaname() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << " Person   =" << this->person_id() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << " SevaType =" << this->sevatype() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << " Qty      =" << this->quantity() <<Qt::endl;
     this->m_person->print();
}

DevotePersnalDetails *SevaBookingElement::person() const
{
    return m_person;
}

void SevaBookingElement::setPerson(DevotePersnalDetails *person)
{
    m_person = person;
}

QString SevaBookingElement::receiptDate() const
{
    return m_receiptDate;
}

void SevaBookingElement::setReceiptDate(const QString &receiptDate)
{
    m_receiptDate = receiptDate;
}

QString SevaBookingElement::sevaDate() const
{
    return m_sevaDate;
}

void SevaBookingElement::setSevaDate(const QString &sevaDate)
{
    m_sevaDate = sevaDate;
}

QString SevaBookingElement::totalCost() const
{
    return m_totalCost;
}

void SevaBookingElement::setTotalCost(const QString &totalCost)
{
    m_totalCost = totalCost;
}

QString SevaBookingElement::cash() const
{
    return m_cash;
}

void SevaBookingElement::setCash(const QString &cash)
{
    m_cash = cash;
}

QString SevaBookingElement::bank() const
{
    return m_bank;
}

void SevaBookingElement::setBank(const QString &bank)
{
    m_bank = bank;
}

QString SevaBookingElement::reference() const
{
    return m_reference;
}

void SevaBookingElement::setReference(const QString &reference)
{
    m_reference = reference;
}

QString SevaBookingElement::address() const
{
    return m_address;
}

void SevaBookingElement::setAddress(const QString &address)
{
    m_address = address;
}

QString SevaBookingElement::momento() const
{
    return m_momento;
}

void SevaBookingElement::setMomento(const QString &momento)
{
    m_momento = momento;
}

const QString &SevaBookingElement::bookedBy() const
{
    return m_bookedBy;
}

void SevaBookingElement::setBookedBy(const QString &newBookedBy)
{
    m_bookedBy = newBookedBy;
}