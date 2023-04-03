#ifndef VOUCHERNUMBER_H
#define VOUCHERNUMBER_H
#include "IVoucherNumberInterface.h"
#include "./model/DBInterface.h"
#include "QDebug"
class VoucherNumber: public IVoucherNumberInterface
{
public:
    VoucherNumber();
    QString getNextVoucherNumber() override ;



};

#endif // VOUCHERNUMBER_H
