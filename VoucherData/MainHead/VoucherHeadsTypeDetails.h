#ifndef VOUCHERHEADSTYPEDETAILS_H
#define VOUCHERHEADSTYPEDETAILS_H

#include <QString>
#include <QDebug>

class VoucherHeadsTypeDetails
{
    Q_GADGET
public:
    VoucherHeadsTypeDetails();


    QString serialNo() const;
    void setSerialNo(const QString &newSerialNo);

    QString vouchId() const;
    void setVouchId(const QString &newVouchId);

    QString vCategory() const;
    void setVCategory(const QString &newVCategory);

private:
    QString m_serialNo;
    QString m_vouchId;
    QString m_vCategory;
};

#endif // VOUCHERHEADSTYPEDETAILS_H
