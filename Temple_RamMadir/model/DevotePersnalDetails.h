#ifndef DEVOTEPERSNALDETAILS_H
#define DEVOTEPERSNALDETAILS_H

#include <QObject>

class DevotePersnalDetails : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString devoteeName READ devoteeName WRITE setDevoteeName CONSTANT)
    Q_PROPERTY(QString mobileNumber READ mobileNumber WRITE setMobileNumber CONSTANT)
    Q_PROPERTY(QString gothra READ gothra WRITE setGothra CONSTANT)
    Q_PROPERTY(QString nakshatra READ nakshatra WRITE setNakshatra CONSTANT)
public:
    explicit DevotePersnalDetails(QObject *parent = nullptr);

    QString devoteeName() const;
    void setDevoteeName(const QString &devoteeName);

    QString mobileNumber() const;
    void setMobileNumber(const QString &mobileNumber);

    QString gothra() const;
    void setGothra(const QString &gothra);

    QString nakshatra() const;
    void setNakshatra(const QString &nakshatra);

    void print();

    QString personDbId() const;
    void setPersonDbId(const QString &personDbId);

signals:

private :
    QString m_personDbId;
    QString m_devoteeName;
    QString m_mobileNumber;
    QString m_gothra;
    QString m_nakshatra;
};

#endif // DEVOTEPERSNALDETAILS_H
