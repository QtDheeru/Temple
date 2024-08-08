#include "ReceiptBook.h"
#include <QDebug>

ReceiptBook::ReceiptBook(QObject *parent)
    : QObject{parent},
    m_bookId(""),
    m_bookStartNo(0),
    m_receiptEndNo(0),
    m_currentReceiptNo(0),
    m_bookCreatedBy(""),
    m_creationDate(QDate::currentDate()),
    m_closingDate(QDate::currentDate()),
    m_openDate(QDate::currentDate()),
    m_bookStatus(CLOSE)
{
}

ReceiptBook::~ReceiptBook()
{
    qDebug() << Q_FUNC_INFO << " Object is destroyed =" << this->objectName() << Qt::endl;
}

QString ReceiptBook::bookId() const
{
    return m_bookId;
}

void ReceiptBook::setBookId(const QString &newBookId)
{
    if (m_bookId != newBookId)
    {
        m_bookId = newBookId;
    }
}

qint64 ReceiptBook::bookStartNo() const
{
    return m_bookStartNo;
}

void ReceiptBook::setBookStartNo(qint64 newBookStartNo)
{
    if (m_bookStartNo != newBookStartNo)
    {
        m_bookStartNo = newBookStartNo;
    }
}

qint64 ReceiptBook::receiptEndNo() const
{
    return m_receiptEndNo;
}

void ReceiptBook::setReceiptEndNo(qint64 newReceiptEndNo)
{
    if (m_receiptEndNo != newReceiptEndNo)
    {
        m_receiptEndNo = newReceiptEndNo;
    }
}

qint64 ReceiptBook::currentReceiptNo() const
{
    return m_currentReceiptNo;
}

void ReceiptBook::setCurrentReceiptNo(qint64 newCurrentReceiptNo)
{
    if (m_currentReceiptNo != newCurrentReceiptNo)
    {
        m_currentReceiptNo = newCurrentReceiptNo;
    }
}

QString ReceiptBook::bookCreatedBy() const
{
    return m_bookCreatedBy;
}

void ReceiptBook::setBookCreatedBy(const QString &newBookCreatedBy)
{
    if (m_bookCreatedBy != newBookCreatedBy)
    {
        m_bookCreatedBy = newBookCreatedBy;
    }
}

QDate ReceiptBook::creationDate() const
{
    return m_creationDate;
}

void ReceiptBook::setCreationDate(const QDate &newCreationDate)
{
    if (m_creationDate != newCreationDate)
    {
        m_creationDate = newCreationDate;
    }
}

QDate ReceiptBook::closingDate() const
{
    return m_closingDate;
}

void ReceiptBook::setClosingDate(const QDate &newClosingDate)
{
    if (m_closingDate != newClosingDate)
    {
        m_closingDate = newClosingDate;
    }
}

QDate ReceiptBook::openDate() const
{
    return m_openDate;
}

void ReceiptBook::setOpenDate(const QDate &newOpenDate)
{
    if (m_openDate != newOpenDate)
    {
        m_openDate = newOpenDate;
    }
}

ReceiptBook::RECEIPT_BOOK_STATUS ReceiptBook::bookStatus() const
{
    return m_bookStatus;
}

void ReceiptBook::setBookStatus(RECEIPT_BOOK_STATUS newBookStatus)
{
    if (m_bookStatus != newBookStatus)
    {
        m_bookStatus = newBookStatus;
    }
}

bool ReceiptBook::print()
{
    qDebug() << "Book ID:" << m_bookId;
    qDebug() << "Book Start No:" << m_bookStartNo;
    qDebug() << "Receipt End No:" << m_receiptEndNo;
    qDebug() << "Current Receipt No:" << m_currentReceiptNo;
    qDebug() << "Book Created By:" << m_bookCreatedBy;
    qDebug() << "Creation Date:" << m_creationDate.toString("dd/MM/yyyy");
    qDebug() << "Closing Date:" << m_closingDate.toString("dd/MM/yyyy");
    qDebug() << "Open Date:" << m_openDate.toString("dd/MM/yyyy");
    qDebug() << "Book Status:" << m_bookStatus;
    return true;
}

