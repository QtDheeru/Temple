#include "VoucherReportElement.h"

VoucherReportElement::VoucherReportElement(QObject *parent)
    : QObject{parent}
{

}

int VoucherReportElement::voucherNo() const
{
    return m_voucherNo;
}

void VoucherReportElement::setVoucherNo(int newVoucherNo)
{
    m_voucherNo = newVoucherNo;
}

QString VoucherReportElement::voucherName() const
{
    return m_voucherName;
}

void VoucherReportElement::setVoucherName(const QString &newVoucherName)
{
    m_voucherName = newVoucherName;
}

QString VoucherReportElement::voucherPaymentMode() const
{
    return m_voucherPaymentMode;
}

void VoucherReportElement::setVoucherPaymentMode(const QString &newVoucherPaymentMode)
{
    m_voucherPaymentMode = newVoucherPaymentMode;
}

QString VoucherReportElement::mobileNo() const
{
    return m_mobileNo;
}

void VoucherReportElement::setMobileNo(const QString &newMobileNo)
{
    m_mobileNo = newMobileNo;
}

QString VoucherReportElement::voucherDate() const
{
    return m_voucherDate;
}

void VoucherReportElement::setVoucherDate(const QString &newVoucherDate)
{
    m_voucherDate = newVoucherDate;
}

QString VoucherReportElement::voucherCost() const
{
    return m_voucherCost;
}

void VoucherReportElement::setVoucherCost(const QString &newVoucherCost)
{
    m_voucherCost = newVoucherCost;
}

QString VoucherReportElement::receiptNumber() const
{
    return m_receiptNumber;
}

void VoucherReportElement::setReceiptNumber(const QString &newReceiptNumber)
{
    m_receiptNumber = newReceiptNumber;
}
