#include "ReceiptBookModel.h"
#include "ReceiptBookManager.h"

using namespace SmartTemple::ReceiptBookManagement;

ReceiptBookModel::ReceiptBookModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

QVariant ReceiptBookModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    // FIXME: Implement me!
}

int ReceiptBookModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<" Row Count =" << m_receiptDataModel->count() << Qt::endl;
    return m_receiptDataModel->count();
    //return ReceiptBookManager::getInstance()->count();
}

int ReceiptBookModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return 9;
}

QVariant ReceiptBookModel::data(const QModelIndex &index, int role) const
{
    // if (!index.isValid())
    //     return QVariant();

    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    //ReceiptBookManager *receiptBookManager = ReceiptBookManager::getInstance();
    //return receiptBookManager->getData(index.row(),index.column(),role);
    return m_receiptDataModel->getData(index.row(),role);
}

void ReceiptBookModel::setReceiptDataModel(ReceiptDataModel *newReceiptDataModel)
{
    m_receiptDataModel = newReceiptDataModel;
}

QHash<int, QByteArray> ReceiptBookModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BOOK_ID] = "BOOK_ID";
    roles[BOOK_START_NO] = "START_BOOK_NO";
    roles[BOOK_END_NO] = "RECEIPT_BOOK_NO";
    roles[BOOK_CURRENT_RECEIPT_NO] = "CURRENT_RECEIPT_NO";
    roles[BOOK_CREATION_DATE] = "CREATION_DATE";
    roles[BOOK_CLOSING_DATE] = "CLOSING_DATE";
    roles[BOOK_ACTIVE_DATE] = "ACTIVE_DATE";
    roles[BOOK_CREATED_BY] = "BOOKED_BY";
    roles[BOOK_STATUS] = "BOOK_STATUS";
    return roles;
}
