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


VoucherSubHead::VoucherSubHead()
{
    qDebug()<<"Inside VoucherSubhead";
}
