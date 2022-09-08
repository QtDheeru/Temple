#ifndef TRUST_H
#define TRUST_H

#include <QObject>
#include<QDebug>
class Trust : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString trustName READ trustName CONSTANT)
    Q_PROPERTY(QString trustCode READ trustCode CONSTANT)
public:
    explicit Trust(QObject *parent = nullptr);
    ~Trust();

    const QString &trustName() const;
    void setTrustName(const QString &newTrustName);

    const QString &trustCode() const;
    void setTrustCode(const QString &newTrustCode);

signals:
private:
    QString m_trustName;
    QString m_trustCode;

};

#endif // TRUST_H
