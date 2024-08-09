#ifndef RECEIPTBOOKDBINTERFACE_H
#define RECEIPTBOOKDBINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QStandardPaths>
#include <QDir>

#include "../../ReceiptBook/ReceiptBook.h"

class ReceiptBookDBInterface : public QObject
{
    Q_OBJECT

public:
    explicit ReceiptBookDBInterface(QSqlDatabase db,QObject *parent = nullptr);
    bool addReceiptBook(ReceiptBook *book);
    bool updateReceiptBook(ReceiptBook *book);
    bool readAllReceiptBooks();

private :

signals:
    void receiptBook_addBook(ReceiptBook *book);
    void receiptBook_updateBook(ReceiptBook *book);
    void totalReceiptBooks(int count);

private:
    QSqlDatabase m_db;
    QString m_dbPath;
};

#endif // RECEIPTBOOKDBINTERFACE_H
