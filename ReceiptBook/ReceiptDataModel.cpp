#include "ReceiptDataModel.h"

ReceiptDataModel::ReceiptDataModel(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << " Book Added =" << Qt::endl;
}

void ReceiptDataModel::addBook(ReceiptBook *book)
{
    qDebug() << Q_FUNC_INFO << " Book Added =" << book->bookId();
    if (book != nullptr)
        this->m_books.append(book);
}

int ReceiptDataModel::count()
{
    return m_books.count();
}

QVariant ReceiptDataModel::getData(int row, int role)
{
    ReceiptBook *book = m_books.at(row);
    if (book == nullptr) {
        qWarning() << Q_FUNC_INFO << " Receipt book is null"  << Qt::endl;
        return QVariant();
    }
    switch(role){
    case BOOK_ID: return book->bookId();break;
    case BOOK_START_NO : return book->bookStartNo();break;
    case BOOK_END_NO : return book->receiptEndNo();break;
    case BOOK_CURRENT_RECEIPT_NO : return book->currentReceiptNo(); break;
    case BOOK_CREATED_BY : return book->bookCreatedBy(); break;
    case BOOK_CREATION_DATE : return book->creationDate().toString("dd-MMM-yyyy"); break;
    case BOOK_CLOSING_DATE : return book->closingDate().toString("dd-MMM-yyyy");break;
    case BOOK_ACTIVE_DATE : return book->openDate().toString("dd-MMM-yyyy"); break;
    case BOOK_STATUS : return book->bookStatus();break;
    }
}
