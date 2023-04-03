#ifndef SEVAS_H
#define SEVAS_H

#include <QObject>
#include<QDebug>
class Sevas : public QObject
{
    Q_OBJECT
public:
    explicit Sevas(QObject *parent = nullptr);
    ~Sevas();

    const QString &sevaName() const;
    void setSevaName(const QString &newSevaName);

    const QString &userName() const;
    void setUserName(const QString &newUserName);

    const QString &sevaCode() const;
    void setSevaCode(const QString &newSevaCode);

    const QString &sevaType() const;
    void setSevaType(const QString &newSevaType);

    const QString &sevaCost() const;
    void setSevaCost(const QString &newSevaCost);

    const QString &theerthaPrasada() const;
    void setTheerthaPrasada(const QString &newTheerthaPrasada);

    const QString &poojaTime() const;
    void setPoojaTime(const QString &newPoojaTime);

    const QString &sevaDate() const;
    void setSevaDate(const QString &newSevaDate);



    const QString &sevaTime() const;
    void setSevaTime(const QString &newSevaTime);

signals:
private:

    QString m_sevaName;
    QString m_userName;
    QString m_sevaCode;
    QString m_sevaType;
    QString m_sevaTime;
    QString m_sevaCost;
    QString m_sevaDate;
    QString m_poojaTime;
    QString m_theerthaPrasada;
};

#endif // SEVAS_H
