#ifndef VOUCHERFILTERELEMENTS_H
#define VOUCHERFILTERELEMENTS_H

#include <QObject>
#include <QDebug>

class VoucherFilterElements : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sVoucherType READ sVoucherType WRITE setSVoucherType NOTIFY sVoucherTypeChanged)
    Q_PROPERTY(QString sPaymentMode READ sPaymentMode WRITE setSPaymentMode NOTIFY sPaymentModeChanged)
    Q_PROPERTY(QString sSingleDate READ sSingleDate WRITE setSSingleDate NOTIFY sSingleDateChanged)
    Q_PROPERTY(QString sStartDate READ sStartDate WRITE setSStartDate NOTIFY sStartDateChanged)
    Q_PROPERTY(QString sEndDate READ sEndDate WRITE setSEndDate NOTIFY sEndDateChanged)
    Q_PROPERTY(QString sMonth READ sMonth WRITE setSMonth NOTIFY sMonthChanged)
    Q_PROPERTY(QString sYear READ sYear WRITE setSYear NOTIFY sYearChanged)
    Q_PROPERTY(int iSelectedType READ iSelectedType WRITE setISelectedType NOTIFY iSelectedTypeChanged)
public:
    explicit VoucherFilterElements(QObject *parent = nullptr);

    const QString &sSingleDate() const;
    void setSSingleDate(const QString &newSSingleDate);

    const QString &sStartDate() const;
    void setSStartDate(const QString &newSStartDate);

    const QString &sEndDate() const;
    void setSEndDate(const QString &newSEndDate);

    const QString &sMonth() const;
    void setSMonth(const QString &newSMonth);

    const QString &sYear() const;
    void setSYear(const QString &newSYear);

    int iSelectedType() const;
    void setISelectedType(int newISelectedType);

    const QString &sVoucherType() const;
    void setSVoucherType(const QString &newSVoucherType);

    const QString &sPaymentMode() const;
    void setSPaymentMode(const QString &newSPaymentMode);

signals:
    void sVoucherTypeChanged();
    void sPaymentModeChanged();
    void sSingleDateChanged();
    void sStartDateChanged();
    void sEndDateChanged();
    void sMonthChanged();
    void sYearChanged();
    void iSelectedTypeChanged();

private:
    QString m_sVoucherType;
    QString m_sPaymentMode;
    QString m_sSingleDate;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sMonth;
    QString m_sYear;
    int m_iSelectedType;

};

#endif // VOUCHERFILTERELEMENTS_H
