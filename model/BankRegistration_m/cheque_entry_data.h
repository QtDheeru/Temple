#ifndef CHEQUE_ENTRY_DATA_H
#define CHEQUE_ENTRY_DATA_H

#include <QObject>

class Cheque_Entry_Data : public QObject
{
    Q_OBJECT


public:
    explicit Cheque_Entry_Data(QObject *parent = nullptr);

    QString receiptDate() const;
    void setReceiptDate(const QString &newReceiptDate);

    QString chequeDate() const;
    void setChequeDate(const QString &newChequeDate);

    QString bank() const;
    void setBank(const QString &newBank);

    QString receiptNumber() const;
    void setReceiptNumber(const QString &newReceiptNumber);

    QString amount() const;
    void setAmount(const QString &newAmount);

signals:
    void receiptDateChanged();
    void chequeDateChanged();
    void bankChanged();
    void receiptNumberChanged();
    void amountChanged();

private:
    QString m_receiptDate;
    QString m_chequeDate;
    QString m_bank;
    QString m_receiptNumber;
    QString m_amount;

    Q_PROPERTY(QString RECEIPTDATE READ receiptDate WRITE setReceiptDate NOTIFY receiptDateChanged)
    Q_PROPERTY(QString CHEQUEDATE READ chequeDate WRITE setChequeDate NOTIFY chequeDateChanged)
    Q_PROPERTY(QString BANK READ bank WRITE setBank NOTIFY bankChanged)
    Q_PROPERTY(QString RECEIPTNUMBER READ receiptNumber WRITE setReceiptNumber NOTIFY receiptNumberChanged)
    Q_PROPERTY(QString AMOUNT READ amount WRITE setAmount NOTIFY amountChanged)

};

#endif // CHEQUE_ENTRY_DATA_H
