#ifndef SEVATYPE_H
#define SEVATYPE_H

#include <QObject>
#include<QDebug>
class SevaType : public QObject
{
    Q_OBJECT
public:
    explicit SevaType(QObject *parent = nullptr);
    ~SevaType();

    const QString &name() const;
    void setName(const QString &newName);

    const QString &sevaTypeCode() const;
    void setSevaTypeCode(const QString &newSevaTypeCode);

    const QString &userName() const;
    void setUserName(const QString &newUserName);

signals:

private:
    QString m_name;
    QString m_sevaTypeCode;
    QString m_userName;
};

#endif // SEVATYPE_H
