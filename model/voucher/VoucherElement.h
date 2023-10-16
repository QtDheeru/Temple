#ifndef VOUCHERELEMENT_H
#define VOUCHERELEMENT_H

#include <QObject>
#include <QDebug>

class VoucherElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString voucherDate READ voucherDate WRITE setVoucherDate NOTIFY voucherDateChanged)
    Q_PROPERTY(int voucherNo READ voucherNo WRITE setVoucherNo NOTIFY voucherNoChanged)
    Q_PROPERTY(QString voucherName READ voucherName WRITE setVoucherName NOTIFY voucherNameChanged)
    Q_PROPERTY(QString mobileNo READ mobileNo WRITE setMobileNo NOTIFY mobileNoChanged)
    Q_PROPERTY(QString voucherType READ voucherType WRITE setVoucherType NOTIFY voucherTypeChanged)
    Q_PROPERTY(QString voucherItem READ voucherItem WRITE setVoucherItem NOTIFY voucherItemChanged)
    Q_PROPERTY(QString voucherNote READ voucherNote WRITE setVoucherNote NOTIFY voucherNoteChanged)
    Q_PROPERTY(QString voucherCost READ voucherCost WRITE setVoucherCost NOTIFY voucherCostChanged)
    Q_PROPERTY(QString voucherPaymentMode READ voucherPaymentMode WRITE setVoucherPaymentMode NOTIFY voucherPaymentModeChanged)
    Q_PROPERTY(QString paymentReference READ PaymentReference WRITE setPaymentReference NOTIFY PaymentReferenceChanged)
public:
    explicit VoucherElement(QObject *parent = nullptr);

    const QString &voucherDate() const;
    void setVoucherDate(const QString &newVoucherDate);

    int voucherNo() const;
    void setVoucherNo(int newVoucherNo);


    const QString &voucherName() const;
    void setVoucherName(const QString &newVoucherName);


    QString mobileNo() const;
    void setMobileNo(QString newMobileNo);


    const QString &voucherType() const;
    void setVoucherType(const QString &newVoucherType);


    const QString &voucherItem() const;
    void setVoucherItem(const QString &newVoucherItem);


    const QString &voucherNote() const;
    void setVoucherNote(const QString &newVoucherNote);


    const QString &voucherCost() const;
    void setVoucherCost(const QString &newVoucherCost);


    const QString &voucherPaymentMode() const;
    void setVoucherPaymentMode(const QString &newVoucherPaymentMode);


    const QString &PaymentReference() const;
    void setPaymentReference(const QString &newPaymentReference);

public slots:

signals:
    void voucherDateChanged();
    void voucherNoChanged();
    void voucherNameChanged();
    void mobileNoChanged();
    void voucherTypeChanged();
    void voucherItemChanged();
    void voucherNoteChanged();
    void voucherCostChanged();
    void voucherPaymentModeChanged();
    void PaymentReferenceChanged();

private:
    QString m_voucherDate;
    int m_voucherNo;
    QString m_voucherName;
    QString m_mobileNo;
    QString m_voucherType;
    QString m_voucherItem;
    QString m_voucherNote;
    QString m_voucherCost;
    QString m_voucherPaymentMode;
    QString m_PaymentReference;

};

#endif // VOUCHERELEMENT_H
