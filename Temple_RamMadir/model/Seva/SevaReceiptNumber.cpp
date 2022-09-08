#include "SevaReceiptNumber.h"
#include <QDate>
#include <QDebug>
#include "./model/DBInterface.h"

SevaReceiptNumber::SevaReceiptNumber():m_receiptNumber(1000)
{
    m_receiptNumber = 5000;
}


QString SevaReceiptNumber::getNextReceiptNumber()
{
    // Read the last receipt number from DB & then set it.
    QDate dt = QDate::currentDate();
    qDebug() << Q_FUNC_INFO << " Date ="<< dt.day() << " Mon ="<<dt.month() << " Year =" << dt.year();
    QString rc = QString::number(dt.year())+"_"+QString::number(dt.month()) +"_"+ this->getLastReceiptNumber();
    m_receiptNumber++;
    rc = QString("%1").arg(m_receiptNumber);
    qDebug() << Q_FUNC_INFO << " Last Receipt number =" << rc << Qt::endl;

    rc = QString("%1").arg(DBInterface::getInstance()->getLastReceiptNumber()+1);
    qDebug() << Q_FUNC_INFO << " Last Receipt number from DB =" << rc << Qt::endl;

    return rc;
}

QString SevaReceiptNumber::getLastReceiptNumber() const
{
    QString rNumber  = QString::number(m_receiptNumber);
    return rNumber;
}

