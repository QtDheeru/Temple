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
};

#endif // SEVARECEIPTNUMBER_H
