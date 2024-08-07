#ifndef RECEIPTBOOKMANAGER_H
#define RECEIPTBOOKMANAGER_H

#include <QObject>
#include "ReceiptBook.h"
#include "./model/DBInterface.h"

using namespace std;
namespace SmartTemple {
namespace ReceiptBookManagement {
class ReceiptBookManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString bookId READ bookId NOTIFY bookIdChanged)
    Q_PROPERTY(qint64  startReceiptNumber READ  startReceiptNumber WRITE setStartReceiptNumber NOTIFY  startReceiptNumberChanged FINAL)
    Q_PROPERTY(qint64  endReceiptNumber READ  endReceiptNumber WRITE setEndReceiptNumber NOTIFY  endReceiptNumberChanged FINAL)
    Q_PROPERTY(bool isFreshBook READ isFreshBookAllowed CONSTANT)

public:
    explicit ReceiptBookManager(QObject *parent = nullptr);

    using BOOKID=int;

    static ReceiptBookManager* getInstance();

    Q_INVOKABLE bool addBook(ReceiptBook *bookFromQML);
    Q_INVOKABLE bool updateBook(ReceiptBook *book);
    int  count();
    ReceiptBook *getBook(ReceiptBook::BOOK_ID bookId);
    Q_INVOKABLE QString getNextReceiptNumber();
    Q_INVOKABLE bool reset();

    bool connectSignal();

    bool getBookStatus();
    bool isFreshBookAllowed() const;
    void setIsFreshBookAllowed(bool newIsFreshBookAllowed);

    QString bookId() const;
    void setBookId(const QString &newBookId);

    qint64 startReceiptNumber() const;
    void setStartReceiptNumber(qint64 newStartReceiptNumber);

    qint64 endReceiptNumber() const;
    void setEndReceiptNumber(qint64 newEndReceiptNumber);

public slots:
    bool updateCurrentValues();

signals:
    void startReceiptNumberChanged();
    void endReceiptNumberChanged();
    void bookIdChanged();

private :
    void addBook2Map(ReceiptBook *bookAddedInDb);

private :
    QMap<BOOKID, ReceiptBook*> m_receiptBooks;
    std::unique_ptr<ReceiptBook>  m_currentReceiptBook;
    ReceiptBookManager *m_receiptBookManager;

    DBInterface *m_dbInterface;

    bool m_isFreshBookAllowed;
    QString  m_bookId;
    qint64 m_startReceiptNumber;
    qint64 m_endReceiptNumber;
};
}
}

#endif // RECEIPTBOOKMANAGER_H
