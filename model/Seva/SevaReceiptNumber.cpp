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

    QString datePart =  QString::number(dt.year())+"_"+QString::number(dt.month()) +"_";

    m_receiptNumber++;

    long rcNo = DBInterface::getInstance()->getLastReceiptNumber();

    if (rcNo <= 0) rcNo = 0;
    rcNo++;

    QString zero2prepend;
    if (rcNo >0 && rcNo <10) {
        zero2prepend = "000";
    }
    if (rcNo >=10 && rcNo <100) {
        zero2prepend = "00";
    }
    if (rcNo >=100 && rcNo <1000) {
        zero2prepend = "0";
    }

    QString rc = datePart  + zero2prepend + QString("%1").arg(rcNo);

    qDebug() << Q_FUNC_INFO << " Last ReceiptNo from DB =" << rcNo << " Generated =" << rc  << Qt::endl;

    return rc;
}

QString SevaReceiptNumber::getLastReceiptNumber() const
{
    QString rNumber  = QString::number(m_receiptNumber);
    return rNumber;
}

