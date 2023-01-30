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

signals:

private:
    QString m_name;
    QString m_gothra;
    QString m_nakshatra;
    QString m_sevaName;
    int m_teerthaPrasada;
    QString m_mobileNumber;
    QString m_note;

};

#endif // BOOKINGREPORTELEMENT_H
