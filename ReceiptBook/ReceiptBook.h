#ifndef RECEIPTBOOK_H
#define RECEIPTBOOK_H

#include <QObject>
#include <QString>
#include <QDate>

class ReceiptBook : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString bookId READ bookId WRITE setBookId NOTIFY bookIdChanged)
    Q_PROPERTY(qint64 bookStartNo READ bookStartNo WRITE setBookStartNo NOTIFY bookStartNoChanged)
    Q_PROPERTY(qint64 receiptEndNo READ receiptEndNo WRITE setReceiptEndNo NOTIFY receiptEndNoChanged)
    Q_PROPERTY(qint64 currentReceiptNo READ currentReceiptNo WRITE setCurrentReceiptNo NOTIFY currentReceiptNoChanged)
    Q_PROPERTY(QString bookCreatedBy READ bookCreatedBy WRITE setBookCreatedBy NOTIFY bookCreatedByChanged)
    Q_PROPERTY(QDate creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged)
    Q_PROPERTY(QDate closingDate READ closingDate WRITE setClosingDate NOTIFY closingDateChanged)
    Q_PROPERTY(QDate openDate READ openDate WRITE setOpenDate NOTIFY openDateChanged)
    Q_PROPERTY(RECEIPT_BOOK_STATUS bookStatus READ bookStatus WRITE setBookStatus NOTIFY bookStatusChanged)

public:
    enum RECEIPT_BOOK_STATUS {
        OPEN = 1,
        ACTIVE,
        CLOSE,
        INVALID
    };
    Q_ENUM(RECEIPT_BOOK_STATUS)

    using BOOK_ID = QString;

    explicit ReceiptBook(QObject *parent = nullptr);

    QString bookId() const;
    void setBookId(const QString &newBookId);

    qint64 bookStartNo() const;
    void setBookStartNo(qint64 newBookStartNo);

    qint64 receiptEndNo() const;
    void setReceiptEndNo(qint64 newReceiptEndNo);

    qint64 currentReceiptNo() const;
    void setCurrentReceiptNo(qint64 newCurrentReceiptNo);

    QString bookCreatedBy() const;
    void setBookCreatedBy(const QString &newBookCreatedBy);

    QDate creationDate() const;
    void setCreationDate(const QDate &newCreationDate);

    QDate closingDate() const;
    void setClosingDate(const QDate &newClosingDate);

    QDate openDate() const;
    void setOpenDate(const QDate &newOpenDate);

    RECEIPT_BOOK_STATUS bookStatus() const;
    void setBookStatus(RECEIPT_BOOK_STATUS newBookStatus);

    Q_INVOKABLE bool print();
signals:
    void bookIdChanged();
    void bookStartNoChanged();
    void receiptEndNoChanged();
    void currentReceiptNoChanged();
    void bookCreatedByChanged();
    void creationDateChanged();
    void closingDateChanged();
    void openDateChanged();
    void bookStatusChanged();

private:
    BOOK_ID m_bookId;
    qint64 m_bookStartNo;
    qint64 m_receiptEndNo;
    qint64 m_currentReceiptNo;
    QString m_bookCreatedBy;
    QDate m_creationDate;
    QDate m_closingDate;
    QDate m_openDate;
    RECEIPT_BOOK_STATUS m_bookStatus;
};

#endif // RECEIPTBOOK_H
