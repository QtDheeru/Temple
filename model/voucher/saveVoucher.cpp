#include "saveVoucher.h"

saveVoucher::saveVoucher(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherNumber = new VoucherNumber;
    m_nextVoucherNumber =  m_voucherNumber->getNextVoucherNumber();
    qDebug()<<m_nextVoucherNumber<<Qt::endl;

}

const QString &saveVoucher::nextVoucherNumber() const
{
    return m_nextVoucherNumber;
}

void saveVoucher::setNextVoucherNumber(const QString &newNextVoucherNumber)
{
    m_nextVoucherNumber = newNextVoucherNumber;
    emit nextVoucherNumberChanged();
}

QString saveVoucher::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

void saveVoucher::saveVoucherElements(VoucherElement *ele)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<ele->mobileNo()<<Qt::endl;
    qDebug()<<"suman**********"<<ele->PaymentReference()<<Qt::endl;
   // ele->setVoucherDate(FormatDate(ele->voucherDate()));
    DBInterface::getInstance()->insertVoucherIssued(ele);
     // qDebug()<<"save voucher insert"<<b<<Qt::endl;
    setNextVoucherNumber(m_voucherNumber->getNextVoucherNumber());

}
