#ifndef ACCOUNTFULLREPORTELEMENT_H
#define ACCOUNTFULLREPORTELEMENT_H

#include <QObject>
#include <QDebug>
class AccountFullreportElement : public QObject
{
    Q_OBJECT
public:
    explicit AccountFullreportElement(QObject *parent = nullptr);
    ~AccountFullreportElement();
    const QString &recieptnumber() const;
    void setRecieptnumber(const QString &newRecieptnumber);

    const QString &recptDate() const;
    void setRecptDate(const QString &newRecptDate);

    const QString &sevadate() const;
    void setSevadate(const QString &newSevadate);

    const QString &sevaname() const;
    void setSevaname(const QString &newSevaname);

    const QString &devoteeName() const;
    void setDevoteeName(const QString &newDevoteeName);

    const QString &mobile() const;
    void setMobile(const QString &newMobile);

    const int &sevaCount() const;
    void setSevaCount(const int &newSevaCount);

    const QString &paymentmode() const;
    void setPaymentmode(const QString &newPaymentmode);

    const int &total() const;
    void setTotal(const int &newTotal);

    int sevacost() const;
    void setSevacost(int newSevacost);

    int slNo() const;
    void setSlNo(int newSlNo);

    const QString &bookingStatus() const;
    void setBookingStatus(const QString &newBookingStatus);

signals:

private:
    int m_slNo;
    QString m_recieptnumber;
    QString m_recptDate;
    QString m_sevadate;
    QString m_sevaname;
    QString m_devoteeName;
    QString m_mobile;
    int m_sevacost;
    int m_sevaCount;
    QString m_paymentmode;
    int m_total;
    QString m_bookingStatus;
};

#endif // ACCOUNTFULLREPORTELEMENT_H
