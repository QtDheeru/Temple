#ifndef SAVEVOUCHER_H
#define SAVEVOUCHER_H

#include <QObject>
#include <IVoucherNumberInterface.h>
#include <VoucherNumber.h>
#include <QDebug>
#include "VoucherElement.h"
#include "./model/DBInterface.h"
#include <QDate>
class saveVoucher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nextVoucherNumber READ nextVoucherNumber WRITE setNextVoucherNumber NOTIFY nextVoucherNumberChanged)
public:
    explicit saveVoucher(QObject *parent = nullptr);

    const QString &nextVoucherNumber() const;
    void setNextVoucherNumber(const QString &newNextVoucherNumber);
    QString FormatDate(QString);
public slots:
    void saveVoucherElements(VoucherElement*);
signals:
    void nextVoucherNumberChanged();
private:
    IVoucherNumberInterface *m_voucherNumber;
    QString m_nextVoucherNumber;

};

#endif // SAVEVOUCHER_H
