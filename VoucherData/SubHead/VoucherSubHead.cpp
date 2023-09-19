#include "VoucherSubHead.h"
#include<QDebug>

QString VoucherSubHead::getVSubid() const
{
    return vSubid;
}

void VoucherSubHead::setVSubid(const QString &newVSubid)
{
    vSubid = newVSubid;
}

QString VoucherSubHead::getVscn() const
{
    return Vscn;
}

void VoucherSubHead::setVscn(const QString &newVscn)
{
    Vscn = newVscn;
}


QString VoucherSubHead::getVoucher() const
{
    return Voucher;
}

void VoucherSubHead::setVoucher(const QString &newVoucher)
{
    Voucher = newVoucher;
}

VoucherSubHead::VoucherSubHead()
{
    qDebug()<<"Inside VoucherSubhead";
}
