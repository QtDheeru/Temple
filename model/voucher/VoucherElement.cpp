#include "VoucherElement.h"

VoucherElement::VoucherElement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &VoucherElement::voucherDate() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherDate;
}

void VoucherElement::setVoucherDate(const QString &newVoucherDate)
{
    qDebug()<<Q_FUNC_INFO<<"In vocccccccher string"<<newVoucherDate<<Qt::endl;
    QList<QString> l = newVoucherDate.split("-");
    QString s ="";
    s = l.at(2)+"-"+l.at(1)+"-"+l.at(0);
    qDebug()<<Q_FUNC_INFO<<"In vocccccccher ssssssssss string"<<s<<Qt::endl;
    m_voucherDate = s;
    emit voucherDateChanged();
}

int VoucherElement::voucherNo() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherNo;
}

void VoucherElement::setVoucherNo(int newVoucherNo)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherNo = newVoucherNo;
    emit voucherNoChanged();
}

const QString &VoucherElement::voucherName() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherName;
}

void VoucherElement::setVoucherName(const QString &newVoucherName)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherName = newVoucherName;
    emit voucherNameChanged();
}

QString VoucherElement::mobileNo() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_mobileNo;
}

void VoucherElement::setMobileNo(QString newMobileNo)
{
    qDebug()<<Q_FUNC_INFO<<newMobileNo<<Qt::endl;
    m_mobileNo = newMobileNo;
    emit  mobileNoChanged();
}

const QString &VoucherElement::voucherType() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherType;
}

void VoucherElement::setVoucherType(const QString &newVoucherType)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherType = newVoucherType;
    emit voucherTypeChanged();
}

const QString &VoucherElement::voucherItem() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherItem;
}

void VoucherElement::setVoucherItem(const QString &newVoucherItem)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherItem = newVoucherItem;
    emit voucherItemChanged();
}

const QString &VoucherElement::voucherNote() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherNote;
}

void VoucherElement::setVoucherNote(const QString &newVoucherNote)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherNote = newVoucherNote;
    emit voucherNoteChanged();
}

const QString &VoucherElement::voucherCost() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherCost;
}

void VoucherElement::setVoucherCost(const QString &newVoucherCost)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherCost = newVoucherCost;
    emit voucherCostChanged();
}

const QString &VoucherElement::voucherPaymentMode() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherPaymentMode;
}

void VoucherElement::setVoucherPaymentMode(const QString &newVoucherPaymentMode)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherPaymentMode = newVoucherPaymentMode;
    emit voucherPaymentModeChanged();
}

const QString &VoucherElement::PaymentReference() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_PaymentReference;
}

void VoucherElement::setPaymentReference(const QString &newPaymentReference)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_PaymentReference = newPaymentReference;
    emit PaymentReferenceChanged();
}
