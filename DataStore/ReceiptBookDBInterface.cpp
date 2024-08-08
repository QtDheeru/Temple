#include "ReceiptBookDBInterface.h"
#include <QCoreApplication>
#include <QFile>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

ReceiptBookDBInterface::ReceiptBookDBInterface(QSqlDatabase db, QObject *parent)
    : QObject{parent}, m_db(db)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}


bool ReceiptBookDBInterface::addReceiptBook(ReceiptBook *book)
{
    qDebug() << Q_FUNC_INFO << "DB : " << "Inserting ReceiptBook with values:";
    qDebug() << Q_FUNC_INFO << "DB : " << "bookId:" << book->bookId();
    qDebug() << Q_FUNC_INFO << "DB : " << "bookStartNo:" << book->bookStartNo();
    qDebug() << Q_FUNC_INFO << "DB : " << "receiptEndNo:" << book->receiptEndNo();
    qDebug() << Q_FUNC_INFO << "DB : " << "currentReceiptNo:" << book->currentReceiptNo();
    qDebug() << Q_FUNC_INFO << "DB : " << "bookCreatedBy:" << book->bookCreatedBy();
    qDebug() << Q_FUNC_INFO << "DB : " << "creationDate:" << book->creationDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "DB : " << "closingDate:" << book->closingDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "DB : " << "openDate:" << book->openDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "DB : " << "bookStatus:" << static_cast<int>(book->bookStatus());

    QSqlQuery query;

    QString queryString = "INSERT INTO ReceiptBook(bookId, bookStartNo, receiptEndNo, currentReceiptNo, bookCreatedBy, creationDate, closingDate, openDate, bookStatus) VALUES(:bookId, :bookStartNo, :receiptEndNo, :currentReceiptNo, :bookCreatedBy, :creationDate, :closingDate, :openDate, :bookStatus)";
    query.prepare(queryString);

    query.bindValue(":bookId", book->bookId());
    query.bindValue(":bookStartNo", book->bookStartNo());
    query.bindValue(":receiptEndNo", book->receiptEndNo());
    query.bindValue(":currentReceiptNo", book->currentReceiptNo());
    query.bindValue(":bookCreatedBy", book->bookCreatedBy());
    query.bindValue(":creationDate", book->creationDate().toString("yyyy-MM-dd"));
    query.bindValue(":closingDate", book->closingDate().toString("yyyy-MM-dd"));
    query.bindValue(":openDate", book->openDate().toString("yyyy-MM-dd"));
    query.bindValue(":bookStatus", static_cast<int>(book->bookStatus()));

    qDebug() << Q_FUNC_INFO << "success in binding the values";
    if (!query.exec()) {
        qDebug() << Q_FUNC_INFO << "Error: Unable to insert data" << query.lastError().text();
        return false;
    }

    emit receiptBook_addBook(book);
    return true;
}

bool ReceiptBookDBInterface::updateReceiptBook(ReceiptBook *book)
{
    qDebug() << Q_FUNC_INFO << "DB : " << "Updating ReceiptBook with values:";
    qDebug() << Q_FUNC_INFO << "bookId:" << book->bookId();
    qDebug() << Q_FUNC_INFO << "bookStartNo:" << book->bookStartNo();
    qDebug() << Q_FUNC_INFO << "receiptEndNo:" << book->receiptEndNo();
    qDebug() << Q_FUNC_INFO << "currentReceiptNo:" << book->currentReceiptNo();
    qDebug() << Q_FUNC_INFO << "bookCreatedBy:" << book->bookCreatedBy();
    qDebug() << Q_FUNC_INFO << "creationDate:" << book->creationDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "closingDate:" << book->closingDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "openDate:" << book->openDate().toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << "bookStatus:" << static_cast<int>(book->bookStatus());

    QSqlQuery query;

    QString queryString = "UPDATE ReceiptBook SET "
                          "bookStartNo = :bookStartNo, "
                          "receiptEndNo = :receiptEndNo, "
                          "currentReceiptNo = :currentReceiptNo, "
                          "bookCreatedBy = :bookCreatedBy, "
                          "creationDate = :creationDate, "
                          "closingDate = :closingDate, "
                          "openDate = :openDate, "
                          "bookStatus = :bookStatus "
                          "WHERE bookId = :bookId";
    query.prepare(queryString);

    query.bindValue(":bookId", book->bookId());
    query.bindValue(":bookStartNo", book->bookStartNo());
    query.bindValue(":receiptEndNo", book->receiptEndNo());
    query.bindValue(":currentReceiptNo", book->currentReceiptNo());
    query.bindValue(":bookCreatedBy", book->bookCreatedBy());
    query.bindValue(":creationDate", book->creationDate().toString("yyyy-MM-dd"));
    query.bindValue(":closingDate", book->closingDate().toString("yyyy-MM-dd"));
    query.bindValue(":openDate", book->openDate().toString("yyyy-MM-dd"));
    query.bindValue(":bookStatus", static_cast<int>(book->bookStatus()));

    if (!query.exec()) {
        qDebug() << Q_FUNC_INFO << "Error: Unable to update data" << query.lastError().text();
        return false;
    }

    emit receiptBook_updateBook(book);
    return true;
}

bool ReceiptBookDBInterface::readAllReceiptBooks()
{
    QSqlQuery query;
    query.prepare("select * from ReceiptBook");
    query.exec();

    int count = 0;
    while(query.next())
    {
        int bookStatus = query.value(8).toInt();
        ReceiptBook *book = new ReceiptBook;
        QString bookId = query.value(0).toString();
        qint64 bookStartNo = query.value(1).toInt();
        qint64 bookEndNo = query.value(2).toInt();
        qint64 currentReceiptNo = query.value(3).toInt();
        QString bookCreatedBy = query.value(4).toString();
        QString creationDate = query.value(5).toString();
        QString closingDate = query.value(6).toString();
        QString openDate = query.value(7).toString();

        book->setBookId(bookId);
        book->setBookStartNo(bookStartNo);
        book->setReceiptEndNo(bookEndNo);
        book->setCurrentReceiptNo(currentReceiptNo);
        book->setCreationDate(QDate::fromString(creationDate, "yyyy-MM-dd"));
        book->setClosingDate(QDate::fromString(closingDate, "yyyy-MM-dd"));
        book->setOpenDate(QDate::fromString(openDate, "yyyy-MM-dd"));
        book->setBookCreatedBy(bookCreatedBy);
        book->setBookStatus(static_cast<ReceiptBook::RECEIPT_BOOK_STATUS>(bookStatus));
        book->print();
        emit receiptBook_addBook(book);
        count++;
    }
    emit totalReceiptBooks(count);
}
