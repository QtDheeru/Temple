#include "AccountFullreportElement.h"

AccountFullreportElement::AccountFullreportElement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

AccountFullreportElement::~AccountFullreportElement()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &AccountFullreportElement::recieptnumber() const
{
    return m_recieptnumber;
}

void AccountFullreportElement::setRecieptnumber(const QString &newRecieptnumber)
{
    m_recieptnumber = newRecieptnumber;
}

const QString &AccountFullreportElement::recptDate() const
{
    return m_recptDate;
}

void AccountFullreportElement::setRecptDate(const QString &newRecptDate)
{
    m_recptDate = newRecptDate;
}

const QString &AccountFullreportElement::sevadate() const
{
    return m_sevadate;
}

void AccountFullreportElement::setSevadate(const QString &newSevadate)
{
    m_sevadate = newSevadate;
}

const QString &AccountFullreportElement::sevaname() const
{
    return m_sevaname;
}

void AccountFullreportElement::setSevaname(const QString &newSevaname)
{
    m_sevaname = newSevaname;
}

const QString &AccountFullreportElement::devoteeName() const
{
    return m_devoteeName;
}

void AccountFullreportElement::setDevoteeName(const QString &newDevoteeName)
{
    m_devoteeName = newDevoteeName;
}

const QString &AccountFullreportElement::mobile() const
{
    return m_mobile;
}

void AccountFullreportElement::setMobile(const QString &newMobile)
{
    m_mobile = newMobile;
}

const int &AccountFullreportElement::sevaCount() const
{
    return m_sevaCount;
}

void AccountFullreportElement::setSevaCount(const int &newSevaCount)
{
    m_sevaCount = newSevaCount;
}

const QString &AccountFullreportElement::paymentmode() const
{
    return m_paymentmode;
}

void AccountFullreportElement::setPaymentmode(const QString &newPaymentmode)
{
    m_paymentmode = newPaymentmode;
}

const int &AccountFullreportElement::total() const
{
    return m_total;
}

void AccountFullreportElement::setTotal(const int &newTotal)
{
    m_total = newTotal;
}

int AccountFullreportElement::sevacost() const
{
    return m_sevacost;
}

void AccountFullreportElement::setSevacost(int newSevacost)
{
    m_sevacost = newSevacost;
}

int AccountFullreportElement::slNo() const
{
    return m_slNo;
}

void AccountFullreportElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}

const QString &AccountFullreportElement::bookingStatus() const
{
    return m_bookingStatus;
}

void AccountFullreportElement::setBookingStatus(const QString &newBookingStatus)
{
    m_bookingStatus = newBookingStatus;
}
