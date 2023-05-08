#ifndef SEVABOOKINGELEMENT_H
#define SEVABOOKINGELEMENT_H

#include <QObject>
#include "../DevotePersnalDetails.h"

class SevaBookingElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sno READ sno WRITE setSno CONSTANT)
    Q_PROPERTY(QString person_id READ person_id WRITE setPerson_id CONSTANT)
    Q_PROPERTY(DevotePersnalDetails* person READ person WRITE setPerson CONSTANT)
    Q_PROPERTY(QString sevatype READ sevatype WRITE setSevatype CONSTANT)
    Q_PROPERTY(QString sevaname READ sevaname WRITE setSevaname CONSTANT)
    Q_PROPERTY(QString quantity READ quantity WRITE setQuantity CONSTANT)
    Q_PROPERTY(QString receiptDate READ receiptDate WRITE setReceiptDate CONSTANT)
    Q_PROPERTY(QString sevaDate READ sevaDate WRITE setSevaDate CONSTANT)
    Q_PROPERTY(QString sevatime READ sevatime WRITE setSevatime NOTIFY sevatimeChanged)
    Q_PROPERTY(QString totalCost READ totalCost WRITE setTotalCost CONSTANT)
    Q_PROPERTY(QString cash READ cash WRITE setCash CONSTANT)
    Q_PROPERTY(QString bank READ bank WRITE setBank CONSTANT)
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


    const QString &sevatime() const;
    void setSevatime(const QString &newSevatime);

signals:

    void sevatimeChanged();

private :
    QString m_sno ;
    QString m_person_id ;
    DevotePersnalDetails *m_person;
    QString m_sevatype ;
    QString m_sevaname ;
    QString m_quantity;
    QString m_receiptDate;
    QString m_sevaDate;
    QString m_sevatime;
    QString m_totalCost;
    QString m_cash;
    QString m_bank;
    QString m_reference;
    QString m_address;
    QString m_momento;
    QString m_bookedBy;
};

#endif // SEVABOOKINGELEMENT_H
