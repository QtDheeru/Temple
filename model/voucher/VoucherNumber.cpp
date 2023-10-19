#include "VoucherNumber.h"

VoucherNumber::VoucherNumber()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

QString VoucherNumber::getNextVoucherNumber()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return QString::number(DBInterface::getInstance()->getLastVoucherNumber());
}
