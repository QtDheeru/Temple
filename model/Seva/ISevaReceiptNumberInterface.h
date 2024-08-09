#ifndef SEVARECEIPTNUMBERINTERFACE_H
#define SEVARECEIPTNUMBERINTERFACE_H

#include <QString>

class ISevaReceiptNumberInterface{

public :
    virtual QString getNextReceiptNumber() = 0;
    virtual QString getNextSevaTypeCode() = 0;
    virtual QString getNextSevanameID() = 0;
    virtual bool    updateReceiptNumber(QString recNo) = 0;
};

#endif // SEVARECEIPTNUMBERINTERFACE_H
