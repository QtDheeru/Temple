#ifndef DEVOTEPERSNALDETAILS_H
#define DEVOTEPERSNALDETAILS_H

#include <QObject>

class DevotePersnalDetails : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString devoteeName READ devoteeName)
    Q_PROPERTY(QString mobileNumber READ mobileNumber)
    Q_PROPERTY(QString gothra READ gothra)
    Q_PROPERTY(QString nakshatra READ nakshatra)
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
