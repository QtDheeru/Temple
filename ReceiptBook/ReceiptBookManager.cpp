#include "ReceiptBookManager.h"

using namespace SmartTemple::ReceiptBookManagement;
ReceiptBookManager* ReceiptBookManager::m_receiptBookManager = nullptr;

ReceiptBookManager::ReceiptBookManager(QObject *parent)
    : QObject{parent}
{
    this->m_currentReceiptBook = nullptr;
    this->m_currentReceiptNo = -1;
    this->m_bookId = "";
    this->m_startReceiptNumber = -1;
    this->m_endReceiptNumber = -1;
    m_receiptBookModel = nullptr;

    m_receiptDataModel = new ReceiptDataModel;
    this->m_receiptBookModel = new ReceiptBookModel;
    m_receiptBookModel->setReceiptDataModel(m_receiptDataModel);
    this->connectSignal();
    this->reset();
}

ReceiptBookManager *ReceiptBookManager::getInstance()
{
    if (m_receiptBookManager == nullptr){
        m_receiptBookManager = new ReceiptBookManager;
    }
    return m_receiptBookManager;
}

bool ReceiptBookManager::autoAddReceiptBook() {

    ReceiptBook *book = new ReceiptBook;

    int nextBookId = m_currentReceiptBook->bookId().toInt() + 1;
    qint64 lastReceipt = m_currentReceiptBook->receiptEndNo();
    book->setBookId(QString::number(nextBookId));
    book->setBookStartNo(lastReceipt+1);
    book->setReceiptEndNo(lastReceipt+RECEIPT_BOOK_LOT);
    book->setCurrentReceiptNo(lastReceipt);
    book->setBookCreatedBy("Auto");
    book->setCreationDate(QDate::currentDate());
    book->setClosingDate(QDate::currentDate());
    book->setOpenDate(QDate::currentDate());
    book->setBookStatus(ReceiptBook::OPEN);
    this->addBook(book);
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
        qWarning() << Q_FUNC_INFO << "Failed to update book in the database.";
        return false;
    } else {
        qDebug() << Q_FUNC_INFO << "Update book in the database is successful";
        return success;
    }
}

QString ReceiptBookManager::getNextReceiptNumber()
{
    int currentBookId = this->m_currentReceiptBook->bookId().toInt();
    qDebug() << Q_FUNC_INFO << " Current Book =" << this->m_currentReceiptBook->bookId().toInt();
    if (m_currentReceiptBook == nullptr) {
        qWarning() << Q_FUNC_INFO << " Current object is null ptr" << Qt::endl;
        return "nothing";
    } else {
        qDebug() << Q_FUNC_INFO << " Current Book is good. = " << this->m_currentReceiptBook->bookId().toInt();
    }
    qint64 recno = m_currentReceiptBook->currentReceiptNo();
    qDebug() << Q_FUNC_INFO << " Print all the details of current receipt book ="<<this->m_currentReceiptBook->bookId();
    m_currentReceiptBook->print();
    qDebug() << Q_FUNC_INFO << " Details of current receipt book "<<this->m_currentReceiptBook->bookId();
    if (m_currentReceiptBook->receiptEndNo() == recno){
        qDebug() << Q_FUNC_INFO << " Close the current receipt book =" << this->m_currentReceiptBook->bookId();
        m_currentReceiptBook->print();
        m_currentReceiptBook->setBookStatus(ReceiptBook::CLOSE);
        this->m_receiptBooks.remove(m_currentReceiptBook->bookId().toInt());
        if (this->updateBook(m_currentReceiptBook.get())){
            qDebug() << "Status update for book =" << currentBookId << " in the database is successful";
        } else {
            qDebug() << "Status update for book =" << currentBookId << " in the database failed";
        }
        // Current receipt book status should be set to close state
        qDebug() << Q_FUNC_INFO << " Current Book Processing =" << this->m_currentReceiptBook->bookId();
        if (m_receiptBooks.size() == 0){
            qDebug() << Q_FUNC_INFO << " All Receipt books are over. Generated the new book ";
            emit generateNewReceiptBook();
            return "";
        }
        if (m_currentReceiptBook.get() != m_receiptBooks.first())
            m_currentReceiptBook.reset(m_receiptBooks.first());

        m_currentReceiptBook->setBookStatus(ReceiptBook::ACTIVE);
        if (this->updateBook(m_currentReceiptBook.get())){
            qDebug() << "Status update for book =" << m_currentReceiptBook->bookId() << " in the database is successful";
        } else {
            qDebug() << "Status update for book =" << m_currentReceiptBook->bookId() << " in the database failed";
        }


        QString objName = m_currentReceiptBook->bookId() + "_" + m_currentReceiptBook->bookStartNo()+"_" + m_currentReceiptBook->receiptEndNo();
        this->m_currentReceiptBook->setObjectName(objName);
        qDebug() << "Current Receipt Book for book =" << m_currentReceiptBook->bookId();
        m_currentReceiptBook->print();
    }
    qDebug() << Q_FUNC_INFO << " Before increment, current receipt number: " << recno;
    m_currentReceiptBook->setCurrentReceiptNo(++recno);
    if (this->updateBook(m_currentReceiptBook.get())){
        qDebug() << "Current Receipt Update  Book =" << currentBookId << " CurrentRecNo=" << recno <<  " in the database is successful";
        this->setCurrentReceiptNo(recno);
    } else {
        qDebug() << "Current Receipt Update  Book =" << currentBookId << " CurrentRecNo=" << recno <<  " in the database failed";
    }
    qDebug() << Q_FUNC_INFO << " After increment, current receipt number: " << recno;
    return QString::number(currentReceiptNo());
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
    this->setEndReceiptNumber(lastReceipt+RECEIPT_BOOK_LOT);

    return true;
}

bool ReceiptBookManager::updateCurrentReceiptBook(int count) {
    if (m_currentReceiptBook == nullptr && m_receiptBooks.size() == count) {
        m_currentReceiptBook.reset(m_receiptBooks.first());
        m_currentReceiptBook->setBookStatus(ReceiptBook::ACTIVE);
        this->updateBook(this->m_currentReceiptBook.get());
    }
    return true;
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
    connect(m_dbInterface, &DBInterface::receiptBook_addBook,
            this, &ReceiptBookManager::addBook2Map);

    connect(this,&ReceiptBookManager::generateNewReceiptBook,
            this,&ReceiptBookManager::autoAddReceiptBook);

    connect(m_dbInterface,&DBInterface::totalReceiptBooks,
            this, &ReceiptBookManager::updateCurrentReceiptBook);

    connect(m_dbInterface, &DBInterface::receiptBook_addBook,
            m_receiptDataModel, &ReceiptDataModel::addBook);
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
    qDebug() << Q_FUNC_INFO << " Update the local map. DB add/update is successful.." << Qt::endl;
    bookAddedInDb->print();
    if (bookAddedInDb->bookStatus() == ReceiptBook::CLOSE){
        qDebug() << Q_FUNC_INFO << " Remove the receipt book from the local map = " << bookAddedInDb->bookId().toInt();
        if (m_receiptBooks.contains(bookAddedInDb->bookId().toInt())){
            m_receiptBooks.remove(bookAddedInDb->bookId().toInt());
        }
        m_currentReceiptBook.reset();
        if (m_receiptBooks.size() !=0 )
            m_currentReceiptBook.reset(m_receiptBooks.first());
        return;
    }
    if (m_receiptBooks.contains(bookAddedInDb->bookId().toInt())){
        qWarning() << Q_FUNC_INFO << " This book = " << bookAddedInDb->bookId() <<" already exist. Updating.. ?";
    }
    this->m_receiptBooks.insert(bookAddedInDb->bookId().toInt(),bookAddedInDb);
    if (bookAddedInDb->bookStatus() == ReceiptBook::ACTIVE){
        qDebug() << Q_FUNC_INFO << " Changing the current receipt book " << bookAddedInDb->bookId().toInt();

        if (m_currentReceiptBook.get() != bookAddedInDb)
            this->m_currentReceiptBook.reset(bookAddedInDb);
        QString objName = m_currentReceiptBook->bookId() + "_" + m_currentReceiptBook->bookStartNo()+"_" + m_currentReceiptBook->receiptEndNo();
        this->m_currentReceiptBook->setObjectName(objName);
        qDebug() << Q_FUNC_INFO << " Current receipt book changed = " << bookAddedInDb->bookId().toInt();
    }

    updateCurrentValues();
}

ReceiptBookModel *ReceiptBookManager::receiptBookModel() const
{
    return m_receiptBookModel;
}

qint64 ReceiptBookManager::currentReceiptNo() const
{
    return m_currentReceiptNo;
}

void ReceiptBookManager::setCurrentReceiptNo(qint64 newCurrentReceiptNo)
{
    if (m_currentReceiptNo == newCurrentReceiptNo)
        return;
    m_currentReceiptNo = newCurrentReceiptNo;
    emit currentReceiptNoChanged();
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

int ReceiptBookManager::count(){
    return m_receiptBooks.size();
}

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

QVariant ReceiptBookManager::getData(int row, int col , int role){
    Q_UNUSED(col);
    QList<ReceiptBook*> books = this->m_receiptBooks.values();
    ReceiptBook *book = books.at(row);
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
    case BOOK_CREATION_DATE : return book->creationDate(); break;
    case BOOK_CLOSING_DATE : return book->closingDate();break;
    case BOOK_ACTIVE_DATE : return book->openDate(); break;
    case BOOK_STATUS : return book->bookStatus();break;
    }
}
