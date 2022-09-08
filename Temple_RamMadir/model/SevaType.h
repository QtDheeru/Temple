#ifndef SEVATYPE_H
#define SEVATYPE_H

#include <QObject>
#include <QDebug>

class SevaType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int sevaTypeId READ sevaTypeId WRITE setSevaTypeId NOTIFY sevaTypeIdChanged)
    Q_PROPERTY(QString sevaTypeName READ sevaTypeName WRITE setSevaTypeName NOTIFY sevaTypeNameChanged)

public:
    explicit SevaType(QObject *parent = nullptr);

    QString sevaTypeName() const;
    void setSevaTypeName(const QString &sevaTypeName);

    int sevaTypeId() const;
    void setSevaTypeId(int sevaTypeId);

    Q_INVOKABLE bool printMe();

    QString userName() const;
    void setUserName(const QString &userName);

    int sevaTypeSeqNumber() const;
    void setSevaTypeSeqNumber(const int &sevaTypeSeqNumber);

signals:
    void sevaTypeIdChanged();
    void sevaTypeNameChanged();

private :
    int m_sevaTypeSeqNumber;
    QString m_sevaTypeName;
    QString m_userName;
    int     m_sevaTypeId;
};

//Q_DECLARE_METATYPE(SevaType)

#endif // SEVATYPE_H
