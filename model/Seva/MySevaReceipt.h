#ifndef MYSEVARECEIPT_H
#define MYSEVARECEIPT_H

#include <QObject>

class MySevaReceipt : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString receiptNo READ receiptNo WRITE  setReceiptNo NOTIFY receiptNoChanged)
    Q_PROPERTY(QString devoteeName READ devoteeName WRITE  setDevoteeName NOTIFY devoteeNameChanged)
    Q_PROPERTY(QString mobileNo READ mobilenumber WRITE  setMobilenumber NOTIFY mobileNoChanged)
    Q_PROPERTY(QString nakshtra READ nakshtra WRITE  setNakshtra NOTIFY nakshtraChanged)
    Q_PROPERTY(QString gothra READ gothra WRITE  setGothra NOTIFY gothraChanged)
    Q_PROPERTY(QString receiptDate READ receiptDate WRITE  setReceiptDate NOTIFY receiptDateChanged)
    Q_PROPERTY(QString momento READ momento WRITE  setMomento NOTIFY momentoChanged)
    Q_PROPERTY(QString bookedBy READ bookedBy WRITE  setBookedBy NOTIFY bookedByChanged)
    Q_PROPERTY(QString reference READ reference WRITE  setReference NOTIFY referenceChanged)
    Q_PROPERTY(QString address READ address WRITE  setAddress NOTIFY addressChanged)
    Q_PROPERTY(QString sevatime READ sevatime WRITE setSevatime NOTIFY sevatimeChanged)

    Q_PROPERTY(QString cash READ cash WRITE  setCash NOTIFY cashChanged)
    Q_PROPERTY(QString bank READ bank WRITE  setBank NOTIFY bankChanged)
    Q_PROPERTY(QString onlineRef READ checkOrTranscationId WRITE setCheckOrTranscationId NOTIFY onlineRefChanged)
    Q_PROPERTY(QString note READ note WRITE setNote NOTIFY noteChanged)
    Q_PROPERTY(QString paymentMode READ paymentMode WRITE setPaymentMode NOTIFY paymentModeChanged)
    Q_PROPERTY(QString bookingStatus READ bookingStatus WRITE setBookingStatus NOTIFY bookingStatusChanged)
public:
    explicit MySevaReceipt(QObject *parent = nullptr);
    ~MySevaReceipt();
    void clear();

    QString receiptNo() const;
    void setReceiptNo(const QString &receiptNo);

    QString devoteeName() const;
    void setDevoteeName(const QString &devoteeName);

    QString mobilenumber() const;
    void setMobilenumber(const QString &mobilenumber);

    QString nakshtra() const;
    void setNakshtra(const QString &nakshtra);

    QString gothra() const;
    void setGothra(const QString &gothra);

    QString receiptDate() const;
    void setReceiptDate(const QString &receiptDate);

    QString momento() const;
    void setMomento(const QString &momento);

    QString bookedBy() const;
    void setBookedBy(const QString &bookedBy);

    QString reference() const;
    void setReference(const QString &reference);

    QString address() const;
    void setAddress(const QString &address);

    void print();
    QString cash() const;
    void setCash(const QString &cash);

    QString bank() const;
    void setBank(const QString &bank);

    QString checkOrTranscationId() const;
    void setCheckOrTranscationId(const QString &transId);

    QString note() const;
    void setNote(const QString &note);

    const QString &sevatime() const;
    void setSevatime(const QString &newSevatime);

    const QString &paymentMode() const;
    void setPaymentMode(const QString &newPaymentMode);

    const QString &bookingStatus() const;
    void setBookingStatus(const QString &newBookingStatus);

signals:
    void receiptNoChanged();
    void devoteeNameChanged();
    void mobileNoChanged();
    void nakshtraChanged();
    void gothraChanged();

    void receiptDateChanged();
    void momentoChanged();
    void bookedByChanged();

    void referenceChanged();
    void addressChanged();

    void bankChanged();
    void cashChanged();
    void onlineRefChanged();
    void noteChanged();

    void sevatimeChanged();

    void paymentModeChanged();
    void bookingStatusChanged();

private :
    QString m_receiptNo;
    QString m_devoteeName;
    QString m_mobilenumber;
    QString m_nakshtra;
    QString m_gothra;

    QString m_receiptDate;
    QString m_sevatime;
    QString m_momento;
    QString m_bookedBy;

    QString m_reference;
    QString m_bookingStatus;
    QString m_address;

    QString m_cash;
    QString m_bank;
    QString m_checkOrTranscationId;
    QString m_note;
    QString m_paymentMode;
};

#endif // MYSEVARECEIPT_H
