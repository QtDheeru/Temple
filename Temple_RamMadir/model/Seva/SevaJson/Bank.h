#ifndef BANK_H
#define BANK_H

#include <QObject>
#include <QDebug>
class Bank : public QObject
{
    Q_OBJECT
public:
    explicit Bank(QObject *parent = nullptr);
    ~Bank();

    const QString &bankName() const;
    void setBankName(const QString &newBankName);

    int bankId() const;
    void setBankId(int newBankId);

signals:

private:

    QString m_bankName;
    int m_bankId;


};

#endif // BANK_H
