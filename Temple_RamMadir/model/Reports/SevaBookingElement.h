#ifndef SEVABOOKINGELEMENT_H
#define SEVABOOKINGELEMENT_H

#include <QObject>
#include "../DevotePersnalDetails.h"

class SevaBookingElement : public QObject
{
    Q_OBJECT
public:
    explicit SevaBookingElement(QObject *parent = nullptr);

    QString sno() const;
    void setSno(const QString &sno);

    QString person_id() const;
    void setPerson_id(const QString &person_id);

    QString sevatype() const;
    void setSevatype(const QString &sevatype);

    QString sevaname() const;
    void setSevaname(const QString &sevaname);

    QString quantity() const;
    void setQuantity(const QString &quantity);

    void print();
    DevotePersnalDetails *person() const;
    void setPerson(DevotePersnalDetails *person);

    QString receiptDate() const;
    void setReceiptDate(const QString &receiptDate);

    QString sevaDate() const;
    void setSevaDate(const QString &sevaDate);

    QString totalCost() const;
    void setTotalCost(const QString &totalCost);

    QString cash() const;
    void setCash(const QString &cash);

    QString bank() const;
    void setBank(const QString &bank);

    QString reference() const;
    void setReference(const QString &reference);

    QString address() const;
    void setAddress(const QString &address);

    QString momento() const;
    void setMomento(const QString &momento);

    const QString &bookedBy() const;
    void setBookedBy(const QString &newBookedBy);

signals:

private :
    QString m_sno ;
    QString m_person_id ;
    DevotePersnalDetails *m_person;
    QString m_sevatype ;
    QString m_sevaname ;
    QString m_quantity;
    QString m_receiptDate;
    QString m_sevaDate;
    QString m_totalCost;
    QString m_cash;
    QString m_bank;
    QString m_reference;
    QString m_address;
    QString m_momento;
    QString m_bookedBy;
};

#endif // SEVABOOKINGELEMENT_H
