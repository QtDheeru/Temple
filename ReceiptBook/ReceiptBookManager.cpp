#include "ReceiptBookManager.h"

using namespace SmartTemple::ReceiptBookManagement;

ReceiptBookManager::ReceiptBookManager(QObject *parent)
    : QObject{parent}
{
    this->connectSignal();
    this->reset();
}

bool ReceiptBookManager::addBook(ReceiptBook *bookFromQML)
{
    if (!bookFromQML) {
        qWarning() << Q_FUNC_INFO << "Error: Null ReceiptBook pointer passed to addBook";
        return false;
    }

    qDebug() << Q_FUNC_INFO << "Add new book from receipt book manager";

    ReceiptBook *book = new ReceiptBook;
    book->setBookId(bookFromQML->bookId());
    book->setBookStartNo(bookFromQML->bookStartNo());
    book->setReceiptEndNo(bookFromQML->receiptEndNo());
    book->setCurrentReceiptNo(bookFromQML->currentReceiptNo());
    book->setBookCreatedBy(bookFromQML->bookCreatedBy());
    book->setCreationDate(bookFromQML->creationDate());
    book->setClosingDate(bookFromQML->closingDate());
    book->setOpenDate(bookFromQML->openDate());
    book->setBookStatus(bookFromQML->bookStatus());

    if (this->getBookStatus()) {
        qDebug() << Q_FUNC_INFO << " Current Book active" << Qt::endl;
        book->setBookStatus(ReceiptBook::ACTIVE);
    } else {
        book->setBookStatus(ReceiptBook::OPEN);
    }
    bool success = DBInterface::getInstance()->addReceiptBook(book);
    if (!success) {
        qWarning() << Q_FUNC_INFO << "Failed to add book to the database.";
    } else {
        qDebug() << Q_FUNC_INFO << "Add receipt book =" << book->bookId() << " is successfull";
    }
    return success;
}

bool ReceiptBookManager::updateBook(ReceiptBook *book)
{
    if (!book) {
        qDebug() << "Error: Null ReceiptBook pointer passed to updateBook";
        return false;
    }
    qDebug() << Q_FUNC_INFO << " Current Book =" << this->m_currentReceiptBook->bookId();
    // Call the updateReceiptBook method on the database interface
    bool success = DBInterface::getInstance()->updateReceiptBook(book);
    if (!success) {
        qWarning() << "Failed to update book in the database.";
        return false;
    } else {
        qDebug() << "Update book in the database is successful";
        return success;
    }
}

QString ReceiptBookManager::getNextReceiptNumber()
{
    qDebug() << Q_FUNC_INFO << " Current Book =" << this->m_currentReceiptBook->bookId();
    qint64 recno = m_currentReceiptBook->currentReceiptNo();
    if (m_currentReceiptBook->receiptEndNo() == recno){
        m_currentReceiptBook->setBookStatus(ReceiptBook::CLOSE);
        // Current receipt book status should be set to close state
        qDebug() << Q_FUNC_INFO << " Current Book =" << this->m_currentReceiptBook->bookId();
        if (this->updateBook(m_currentReceiptBook.get())){
            qDebug() << "Status update for book =" << m_currentReceiptBook->bookId() << " in the database is successful";
        } else {
           qDebug() << "Status update for book =" << m_currentReceiptBook->bookId() << " in the database failed";
        }
        this-m_receiptBooks.remove(m_currentReceiptBook->bookId().toInt());
        m_currentReceiptBook = std::unique_ptr<ReceiptBook>(m_receiptBooks.first());
        qDebug() << "Current Receipt Book for book =" << m_currentReceiptBook->bookId();
        m_currentReceiptBook->print();
    }
    m_currentReceiptBook->setCurrentReceiptNo(recno++);
}

bool ReceiptBookManager::reset()
{
    m_dbInterface->readAllReceiptBooks();
    this->updateCurrentValues();
}

bool ReceiptBookManager::updateCurrentValues()
{
    if (m_receiptBooks.size() == 0 )
        this->setIsFreshBookAllowed(true);
    else
        this->setIsFreshBookAllowed(false);
    ReceiptBook *lastBook = m_receiptBooks.last();
    int nextBookId = lastBook->bookId().toInt() + 1;
    this->setBookId(QString::number(nextBookId));

    qint64 lastReceipt = lastBook->receiptEndNo();
    this->setStartReceiptNumber(lastReceipt+1);
    this->setEndReceiptNumber(lastReceipt+100);

    lastBook->print();
}

bool ReceiptBookManager::connectSignal()
{
    qDebug() << Q_FUNC_INFO << " Connecting the signals..." << Qt::endl;
    m_dbInterface = DBInterface::getInstance();
    if (m_dbInterface == nullptr) {
        qWarning() << Q_FUNC_INFO << " DB interface falied ..." << Qt::endl;
        return false;
    } else {
        qDebug() << Q_FUNC_INFO << " Connecting the signals...DB is proper..." << Qt::endl;
    }
    connect(m_dbInterface,
            &DBInterface::receiptBook_addBook,
            this,
            &ReceiptBookManager::addBook2Map);

    connect(m_dbInterface,
            &DBInterface::receiptBook_updateBook,
            this,
            &ReceiptBookManager::addBook2Map);

}

// If no receipt books OR all the receipt books are closed
// return true. Current receipt book to be added becomes active.
bool ReceiptBookManager::getBookStatus(){
    int count=0;
    QMapIterator<BOOKID,ReceiptBook*> iter(this->m_receiptBooks);
    while(iter.hasNext()){
        iter.next();
        ReceiptBook *book = iter.value();
        if( book->bookStatus() == ReceiptBook::CLOSE) count++;
    }
    if (m_receiptBooks.count() == count) {
        qDebug()<< Q_FUNC_INFO << "All books are closed. So new receipt books to be made active" << Qt::endl;
        return true;
    }
    return false;
}

void ReceiptBookManager::addBook2Map(ReceiptBook *bookAddedInDb)
{
    bookAddedInDb->print();
    if (m_receiptBooks.contains(bookAddedInDb->bookId().toInt())){
        qWarning() << Q_FUNC_INFO << " This book = " << bookAddedInDb->bookId() <<" already exist. Updating.. ?";
    }
    this->m_receiptBooks.insert(bookAddedInDb->bookId().toInt(),bookAddedInDb);
    if (bookAddedInDb->bookStatus() == ReceiptBook::ACTIVE){
        qDebug() << Q_FUNC_INFO << " Changing the current receipt book " << bookAddedInDb->bookId().toInt();
        this->m_currentReceiptBook.reset(bookAddedInDb);
    }
    updateCurrentValues();
}

qint64 ReceiptBookManager::endReceiptNumber() const
{
    return m_endReceiptNumber;
}

void ReceiptBookManager::setEndReceiptNumber(qint64 newEndReceiptNumber)
{
    m_endReceiptNumber = newEndReceiptNumber;
    emit endReceiptNumberChanged();
}

qint64 ReceiptBookManager::startReceiptNumber() const
{
    return m_startReceiptNumber;
}

void ReceiptBookManager::setStartReceiptNumber(qint64 newStartReceiptNumber)
{
    m_startReceiptNumber = newStartReceiptNumber;
    emit startReceiptNumberChanged();
}

QString ReceiptBookManager::bookId() const
{
    return m_bookId;
}

void ReceiptBookManager::setBookId(const QString &newBookId)
{
    m_bookId = newBookId;
    emit bookIdChanged();
}

bool ReceiptBookManager::isFreshBookAllowed() const
{
    return m_isFreshBookAllowed;
}

void ReceiptBookManager::setIsFreshBookAllowed(bool newIsFreshBookAllowed)
{
    m_isFreshBookAllowed = newIsFreshBookAllowed;
}
