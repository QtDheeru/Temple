#include "VoucherHeadsTypeDetails.h"

VoucherHeadsTypeDetails::VoucherHeadsTypeDetails()
{
    qDebug()<<"VoucherHeadsTypeDetails constructor called";
}

QString VoucherHeadsTypeDetails::serialNo() const
{
    qDebug()<<"get serial called";
    return m_serialNo;
}

void VoucherHeadsTypeDetails::setSerialNo(const QString &newSerialNo)
{
    qDebug()<<" set serial called";
    m_serialNo = newSerialNo;
}

QString VoucherHeadsTypeDetails::vouchId() const
{
    qDebug()<<"get v.Id called";
    return m_vouchId;
}

void VoucherHeadsTypeDetails::setVouchId(const QString &newVouchId)
{
    qDebug()<<"set v.Id called";
    m_vouchId = newVouchId;
}

QString VoucherHeadsTypeDetails::vCategory() const
{
    qDebug()<<"get v.Catgry called";
    return m_vCategory;
}

void VoucherHeadsTypeDetails::setVCategory(const QString &newVCategory)
{
    qDebug()<<"set v.Catgry called";
    m_vCategory = newVCategory;
}


