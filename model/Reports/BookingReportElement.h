#ifndef BOOKINGREPORTELEMENT_H
#define BOOKINGREPORTELEMENT_H

#include <QObject>

class BookingReportElement : public QObject
{
    Q_OBJECT
public:
    explicit BookingReportElement(QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &gothra() const;
    void setGothra(const QString &newGothra);

    const QString &nakshatra() const;
    void setNakshatra(const QString &newNakshatra);

    const QString &sevaName() const;
    void setSevaName(const QString &newSevaName);

    int teerthaPrasada() const;
    void setTeerthaPrasada(int newTeerthaPrasada);

    const QString &mobileNumber() const;
    void setMobileNumber(const QString &newMobileNumber);

    const QString &note() const;
    void setNote(const QString &newNote);

    const QString &sevaDate() const;
    void setSevaDate(const QString &newSevaDate);

    const QString &receiptDate() const;
    void setReceiptDate(const QString &newReceiptDate);

    const QString &total() const;
    void setTotal(const QString &newTotal);

    const QString &paymntMode() const;
    void setPaymntMode(const QString &newPaymntMode);

    const QString &referenceNo() const;
    void setReferenceNo(const QString &newReferenceNo);

    const QString &address() const;
    void setAddress(const QString &newAddress);

    int sNO() const;
    void setSNO(int newSNO);

    int sevaCount() const;
    void setSevaCount(int newSevaCount);

signals:

private:
    int m_sNO;
    QString m_name;
    QString m_gothra;
    QString m_nakshatra;
    QString m_sevaName;
    int  m_teerthaPrasada;
    QString m_mobileNumber;
    QString m_note;
    QString m_sevaDate;
    QString m_receiptDate;
    int m_sevaCount;
    QString m_total;
    QString m_paymntMode;
    QString m_referenceNo;
    QString m_address;



};

#endif // BOOKINGREPORTELEMENT_H