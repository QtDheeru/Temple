#ifndef SEVARECEIPTNUMBER_H
#define SEVARECEIPTNUMBER_H

#include "ISevaReceiptNumberInterface.h"

class SevaReceiptNumber : public ISevaReceiptNumberInterface
{
public:
    SevaReceiptNumber();
    virtual ~SevaReceiptNumber() {}

    // ISevaReceiptNumberInterface interface
public:
    QString getNextReceiptNumber() override;

private :

    QString getLastReceiptNumber() const;
    void setLastReceiptNumber(const QString &lastReceiptNumber);

private :
    //QString m_lastReceiptNumber;
    int   m_receiptNumber;

    // ISevaReceiptNumberInterface interface
public:
    virtual QString getNextSevaTypeCode() override;
    virtual QString getNextSevanameID() override;
};

#endif // SEVARECEIPTNUMBER_H
