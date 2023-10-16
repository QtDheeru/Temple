#ifndef CASHTRANSACTION_H
#define CASHTRANSACTION_H

#include <QObject>
#include <QList>
#include <QStringList>
#include <QDate>
#include <QDateTime>
#include <QDebug>
#include "model/DBInterface.h"

class CashTransaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList banksList READ getBanksList WRITE setBanksList NOTIFY banksListChanged)
    Q_PROPERTY(QString receiptNumber READ receiptNumber WRITE setReceiptNumber NOTIFY receiptNumberChanged)
    Q_PROPERTY(QString cashInHand READ cashInHand WRITE setCashInHand NOTIFY cashInHandChanged)

public slots:
    void dataFromQml(QString a_date,QString a_lastreci,QString a_cashinhand,QString a_tobank, QString a_transType,QString a_bank,QString a_person,QString a_notes);
    void onSignalToCashTransaction(QString a_recieptNumber,QString a_cashInHand,QString a_toBank,QString a_TransactionType);
    void onSignalToCashEntry(QString a_recieptNumber,QString a_cash,QString a_cashType);
    void initial();

public:
    explicit CashTransaction(QObject *parent = nullptr);

    QStringList getBanksList() const;
    void setBanksList(const QStringList &newBanksList);


    QString receiptNumber() const;
    void setReceiptNumber(const QString &newReceiptNumber);

    QString cashInHand() const;
    void setCashInHand(const QString &newCashInHand);


signals:
    void banksListChanged();
    void receiptNumberChanged();
    void cashInHandChanged();
    void toBankEmpty();
    void addedData();
    void lowBalance();

private:
    QStringList m_banksList = {"ICICI","SBI","UNION","HDFC","KOTAK","AXIS"};
    QString m_receiptNumber;
    QString m_cashInHand;


};

#endif // CASHTRANSACTION_H
