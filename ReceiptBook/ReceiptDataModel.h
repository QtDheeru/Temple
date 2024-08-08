#ifndef RECEIPTDATAMODEL_H
#define RECEIPTDATAMODEL_H

#include <QObject>
#include <QDebug>
#include <QList>
#include "ReceiptBook.h"

class ReceiptDataModel : public QObject
{
    Q_OBJECT
    enum ROLES {
        BOOK_ID = 0,
        BOOK_START_NO,
        BOOK_END_NO,
        BOOK_CURRENT_RECEIPT_NO,
        BOOK_CREATED_BY,
        BOOK_CREATION_DATE,
        BOOK_ACTIVE_DATE,
        BOOK_CLOSING_DATE,
        BOOK_STATUS
    };
public:
    explicit ReceiptDataModel(QObject *parent = nullptr);

    void addBook(ReceiptBook *book);
    int  count();
    QVariant getData(int row, int role);

signals:

private :
    QList<ReceiptBook*> m_books;
};

#endif // RECEIPTDATAMODEL_H
