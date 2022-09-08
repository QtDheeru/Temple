#ifndef SEVANAME_H
#define SEVANAME_H

#include <QObject>

class SevaName : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sevaName READ sevaName WRITE setSevaName NOTIFY sevaNameChanged)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged)
    Q_PROPERTY(int sevaId   READ sevaId WRITE setSevaId NOTIFY sevaIdChanged)
    Q_PROPERTY(double sevaCost READ sevaCost WRITE setSevaCost NOTIFY sevaCostChanged)
    Q_PROPERTY(int additionalCost READ additionalCost WRITE setAdditionalCost NOTIFY additionalCostChanged)

public:
    explicit SevaName(QObject *parent = nullptr);
    ~SevaName();

    QString sevaName() const;
    void setSevaName(const QString &sevaName);

    int sevaId() const;
    void setSevaId(int sevaId);

    int Number() const;
    void setNumber(int Number);

    int sevaType() const;
    void setSevaType(int sevaType);

    double sevaCost() const;
    void setSevaCost(double sevaCost);

    int teerthaPrasada() const;
    void setTeerthaPrasada(int teerthaPrasada);

    QString sevaDate() const;
    void setSevaDate(const QString &sevaDate);

    Q_INVOKABLE void print();

    int count() const;
    void setCount(int count);

    int additionalCost() const;
    void setAdditionalCost(int additionalCost);

    QString sevaTime() const;
    void setSevaTime(const QString &sevaTime);

    QString userName() const;
    void setUserName(const QString &userName);

    bool sankalpa() const;
    void setSankalpa(bool sankalpa);

signals:
    void sevaNameChanged();
    void sevaTypeChanged();
    void sevaIdChanged();
    void sevaCostChanged();
    void additionalCostChanged();

private :
    QString m_sevaName;
    int 	m_sevaId;
    int 	m_Number;
    int 	m_sevaType;
    double 	m_sevaCost;
    int 	m_teerthaPrasada;
    QString m_sevaDate;
    int     m_count;
    int     m_additionalCost;
    QString m_sevaTime;
    QString m_userName;
    bool    m_sankalpa;
};

#endif // SEVANAME_H