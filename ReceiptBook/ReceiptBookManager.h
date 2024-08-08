#ifndef RECEIPTBOOKMANAGER_H
#define RECEIPTBOOKMANAGER_H

#include <QObject>
#include "ReceiptBook.h"
#include "ReceiptBookModel.h"
#include "ReceiptDataModel.h"

#include "./model/DBInterface.h"
#include "common.h"

using namespace std;
namespace SmartTemple {
namespace ReceiptBookManagement {
class ReceiptBookManager : public QObject
{
    Q_OBJECT

    enum ROLES {
        BOOK_ID = 0,
        BOOK_START_NO,
        BOOK_END_NO,
        BOOK_CURRENT_RECEIPT_NO,
        BOOKED_BY,
        BOOK_CREATION_DATE,
        BOOK_ACTIVE_DATE,
        BOOK_CLOSING_DATE,
        BOOK_STATUS
    };

    Q_PROPERTY(QString bookId READ bookId NOTIFY bookIdChanged)
    Q_PROPERTY(qint64  startReceiptNumber READ  startReceiptNumber WRITE setStartReceiptNumber NOTIFY  startReceiptNumberChanged FINAL)
    Q_PROPERTY(qint64  endReceiptNumber READ  endReceiptNumber WRITE setEndReceiptNumber NOTIFY  endReceiptNumberChanged FINAL)
    Q_PROPERTY(bool isFreshBook READ isFreshBookAllowed CONSTANT)
    Q_PROPERTY(qint64 currentReceiptNo READ currentReceiptNo WRITE setCurrentReceiptNo NOTIFY currentReceiptNoChanged FINAL)
    Q_PROPERTY(ReceiptBookModel *receiptBookModel READ receiptBookModel)

    explicit ReceiptBookManager(QObject *parent = nullptr);

public:

    using BOOKID=int;

    static ReceiptBookManager* getInstance();

    Q_INVOKABLE bool addBook(ReceiptBook *bookFromQML = nullptr);
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

    qint64 currentReceiptNo() const;
    void setCurrentReceiptNo(qint64 newCurrentReceiptNo);

    QVariant getData(int row, int col, int role);

    ReceiptBookModel *receiptBookModel() const;

public slots:
    bool updateCurrentValues();
    bool updateCurrentReceiptBook(int count);
    bool autoAddReceiptBook();

signals:
    void startReceiptNumberChanged();
    void endReceiptNumberChanged();
    void bookIdChanged();

    void currentReceiptNoChanged();
    void generateNewReceiptBook();

private :
    void addBook2Map(ReceiptBook *bookAddedInDb);

private :
    QMap<BOOKID, ReceiptBook*> m_receiptBooks;
    std::unique_ptr<ReceiptBook>  m_currentReceiptBook;
    static ReceiptBookManager *m_receiptBookManager;
    ReceiptBookModel  *m_receiptBookModel;
    ReceiptDataModel  *m_receiptDataModel;

    DBInterface *m_dbInterface;

    bool m_isFreshBookAllowed;
    QString  m_bookId;
    qint64 m_startReceiptNumber;
    qint64 m_endReceiptNumber;
    qint64 m_currentReceiptNo;
};
}
}

#endif // RECEIPTBOOKMANAGER_H
