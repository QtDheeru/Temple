#ifndef SEVANAME_H
#define SEVANAME_H

#include <QObject>

class SevaName : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sevaName READ sevaName WRITE setSevaName NOTIFY sevaNameChanged)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged)
    Q_PROPERTY(int sevaId   READ sevaId WRITE setSevaId NOTIFY sevaIdChanged)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged)
    Q_PROPERTY(double sevaCost READ sevaCost WRITE setSevaCost NOTIFY sevaCostChanged)
    Q_PROPERTY(int teerthaPrasada READ teerthaPrasada WRITE setTeerthaPrasada NOTIFY teerthaPrasadaChanged)

    Q_PROPERTY(QString sevaStartDate READ sevaStartDate WRITE setSevaStartDate NOTIFY sevaStartDateChanged)
    Q_PROPERTY(QString sevaEndDate READ sevaEndDate WRITE setSevaEndDate NOTIFY sevaEndDateChanged)

    Q_PROPERTY(double count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(int additionalCost READ additionalCost WRITE setAdditionalCost NOTIFY additionalCostChanged)

    Q_PROPERTY(QString sevaStartTime READ sevaStartTime WRITE setSevaStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(QString sevaEndTime READ sevaEndTime WRITE setSevaEndTime NOTIFY endTimeChanged)

    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(bool sankalpa READ sankalpa WRITE setSankalpa NOTIFY sankalpaChanged)
    Q_PROPERTY(double enable READ enable WRITE setEnable NOTIFY enableChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged FINAL)

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

    QString sevaStartDate() const;
    void setSevaStartDate(const QString &sevaDate);

    Q_INVOKABLE void print();

    int count() const;
    void setCount(int count);

    int additionalCost() const;
    void setAdditionalCost(int additionalCost);

    QString sevaStartTime() const;
    void setSevaStartTime(const QString &sevaTime);

    QString sevaEndTime() const;
    void setSevaEndTime(const QString &sevaEndTime);

    QString userName() const;
    void setUserName(const QString &userName);

    bool sankalpa() const;
    void setSankalpa(bool sankalpa);

//    QString sevaEndTime() const;
//    void setSevaEndTime(const QString &sevaEndTime);

    bool enable() const;
    void setEnable(bool enable);

    QString sevaEndDate() const;
    void setSevaEndDate(const QString &sevaEndDate);

    const QString status() const;
    void setStatus(const QString &newStatus);

signals:
    void sevaNameChanged();
    void sevaTypeChanged();
    void sevaIdChanged();
  //  void sevaTypeChanged();
    void sevaCostChanged();
    void teerthaPrasadaChanged();
    void sevaStartDateChanged();
    void sevaEndDateChanged();
    void startTimeChanged();
    void endTimeChanged();
    void countChanged();
    void additionalCostChanged();
    void userNameChanged();
    void sankalpaChanged();
    void enableChanged();
    void statusChanged();

private :
    QString m_sevaName;
    int 	m_sevaId;
    int 	m_Number;
    int 	m_sevaType;
    double 	m_sevaCost;
    int 	m_teerthaPrasada;
    QString m_sevaStartDate;
    QString m_sevaEndDate;
    int     m_count;
    int     m_additionalCost;
    QString m_sevaStartTime;
    QString m_sevaEndTime;
    QString m_userName;
    bool    m_sankalpa;
    bool    m_enable;
    QString m_status;
};

#endif // SEVANAME_H
