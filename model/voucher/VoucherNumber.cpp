#include "VoucherNumber.h"

VoucherNumber::VoucherNumber()
{

}

QString VoucherNumber::getNextVoucherNumber()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return QString::number(DBInterface::getInstance()->getLastVoucherNumber());
}
