#include "MySevaReceipt.h"
#include <QDebug>

MySevaReceipt::MySevaReceipt(QObject *parent) : QObject(parent)
{

}

QString MySevaReceipt::receiptNo() const
{
    return m_receiptNo;
}

void MySevaReceipt::setReceiptNo(const QString &receiptNo)
{
    m_receiptNo = receiptNo;
}

QString MySevaReceipt::devoteeName() const
{
    return m_devoteeName;
}

void MySevaReceipt::setDevoteeName(const QString &devoteeName)
{
    m_devoteeName = devoteeName;
}

QString MySevaReceipt::mobilenumber() const
{
    return m_mobilenumber;
}

void MySevaReceipt::setMobilenumber(const QString &mobilenumber)
{
    m_mobilenumber = mobilenumber;
}

QString MySevaReceipt::nakshtra() const
{
    return m_nakshtra;
}

void MySevaReceipt::setNakshtra(const QString &nakshtra)
{
    m_nakshtra = nakshtra;
}

QString MySevaReceipt::gothra() const
{
    return m_gothra;
}

void MySevaReceipt::setGothra(const QString &gothra)
{
    m_gothra = gothra;
}

QString MySevaReceipt::receiptDate() const
{
    return m_receiptDate;
}

void MySevaReceipt::setReceiptDate(const QString &receiptDate)
{
    m_receiptDate = receiptDate;
}

QString MySevaReceipt::momento() const
{
    return m_momento;
}

void MySevaReceipt::setMomento(const QString &momento)
{
    m_momento = momento;
}

QString MySevaReceipt::bookedBy() const
{
    return m_bookedBy;
}

void MySevaReceipt::setBookedBy(const QString &bookedBy)
{
    m_bookedBy = bookedBy;
}

QString MySevaReceipt::reference() const
{
    return m_reference;
}

void MySevaReceipt::setReference(const QString &reference)
{
    m_reference = reference;
}

QString MySevaReceipt::address() const
{
    return m_address;
}

void MySevaReceipt::setAddress(const QString &address)
{
    m_address = address;
}

void MySevaReceipt::print()
{
     qDebug() << Q_FUNC_INFO << this->receiptNo() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->devoteeName() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->mobilenumber() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->nakshtra() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->gothra() <<Qt::endl;

     qDebug() << Q_FUNC_INFO << this->receiptDate() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->reference() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->address() <<Qt::endl;

     qDebug() << Q_FUNC_INFO << this->momento() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->bookedBy() <<Qt::endl;
     qDebug() << Q_FUNC_INFO << this->note() <<Qt::endl;
}

QString MySevaReceipt::cash() const
{
    return m_cash;
}

void MySevaReceipt::setCash(const QString &cash)
{
    m_cash = cash;
}

QString MySevaReceipt::bank() const
{
    return m_bank;
}

void MySevaReceipt::setBank(const QString &bank)
{
    m_bank = bank;
}


QString MySevaReceipt::checkOrTranscationId() const{
    return this->m_checkOrTranscationId;
}
void MySevaReceipt::setCheckOrTranscationId(const QString &transId){
    this->m_checkOrTranscationId = transId;
}

QString MySevaReceipt::note() const
{
    return m_note;
}

void MySevaReceipt::setNote(const QString &note)
{
    m_note = note;
}

const QString &MySevaReceipt::sevatime() const
{
    return m_sevatime;
}

void MySevaReceipt::setSevatime(const QString &newSevatime)
{
    if (m_sevatime == newSevatime)
        return;
    m_sevatime = newSevatime;
    emit sevatimeChanged();
}

const QString &MySevaReceipt::paymentMode() const
{
    return m_paymentMode;
}

void MySevaReceipt::setPaymentMode(const QString &newPaymentMode)
{
    if (m_paymentMode == newPaymentMode)
        return;
    m_paymentMode = newPaymentMode;
    emit paymentModeChanged();
}

const QString &MySevaReceipt::bookingStatus() const
{
    return m_bookingStatus;
}

void MySevaReceipt::setBookingStatus(const QString &newBookingStatus)
{
    m_bookingStatus = newBookingStatus;
    emit bookingStatusChanged();
}
