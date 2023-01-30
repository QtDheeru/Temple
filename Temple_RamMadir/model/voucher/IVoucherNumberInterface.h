#ifndef IVOUCHERNUMBERINTERFACE_H
#define IVOUCHERNUMBERINTERFACE_H
#include <QString>
class IVoucherNumberInterface{

public :
    virtual QString getNextVoucherNumber() = 0;
};
#endif // IVOUCHERNUMBERINTERFACE_H
