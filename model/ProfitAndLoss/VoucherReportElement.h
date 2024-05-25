#ifndef VOUCHERREPORTELEMENT_H
#define VOUCHERREPORTELEMENT_H

#include <QObject>
#include <QDebug>

class VoucherReportElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int voucherNo READ voucherNo WRITE setVoucherNo NOTIFY voucherNoChanged)
    Q_PROPERTY(QString voucherName READ voucherName WRITE setVoucherName NOTIFY voucherNameChanged)
    Q_PROPERTY(QString voucherDate READ voucherDate WRITE setVoucherDate NOTIFY voucherDateChanged)
    Q_PROPERTY(QString mobileNo READ mobileNo WRITE setMobileNo NOTIFY mobileNoChanged)
    Q_PROPERTY(QString voucherCost READ voucherCost WRITE setVoucherCost NOTIFY voucherCostChanged)
    Q_PROPERTY(QString voucherPaymentMode READ voucherPaymentMode WRITE setVoucherPaymentMode NOTIFY voucherPaymentModeChanged)
    Q_PROPERTY(QString receiptNumber READ receiptNumber WRITE setReceiptNumber NOTIFY receiptNumberChanged)

public:
    explicit VoucherReportElement(QObject *parent = nullptr);

    int voucherNo() const;
    void setVoucherNo(int newVoucherNo);

    QString voucherName() const;
    void setVoucherName(const QString &newVoucherName);

    QString voucherPaymentMode() const;
    void setVoucherPaymentMode(const QString &newVoucherPaymentMode);

    QString mobileNo() const;
    void setMobileNo(const QString &newMobileNo);

    QString voucherDate() const;
    void setVoucherDate(const QString &newVoucherDate);

    QString voucherCost() const;
    void setVoucherCost(const QString &newVoucherCost);

    QString receiptNumber() const;
    void setReceiptNumber(const QString &newReceiptNumber);

signals:
    void voucherNoChanged();
    void voucherNameChanged();
    void voucherPaymentModeChanged();
    void mobileNoChanged();
    void voucherDateChanged();
    void voucherCostChanged();
    void receiptNumberChanged();

private:
    int m_voucherNo;
    QString m_voucherName;
    QString m_voucherPaymentMode;
    QString m_mobileNo;
    QString m_voucherDate;
    QString m_voucherCost;
    QString m_receiptNumber;
};

#endif // VOUCHERREPORTELEMENT_H
