#include "saveVoucher.h"

saveVoucher::saveVoucher(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_voucherNumber = new VoucherNumber;
    m_nextVoucherNumber =  m_voucherNumber->getNextVoucherNumber();
    qDebug() << Q_FUNC_INFO << m_nextVoucherNumber << Qt::endl;

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
    qDebug() << Q_FUNC_INFO << unformat << Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug() << Q_FUNC_INFO << Date << Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << format << Qt::endl;
    return format;
}

void saveVoucher::saveVoucherElements(VoucherElement *ele)
{
    qDebug() << Q_FUNC_INFO <<  "saveVoucherElements :: Mobile No : " << ele->mobileNo()  << " receipt num : " << ele->receiptNumber() << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Payment ref: " << ele->PaymentReference() << Qt::endl;
    DBInterface::getInstance()->insertVoucherIssued(ele);
    setNextVoucherNumber(m_voucherNumber->getNextVoucherNumber());

}
