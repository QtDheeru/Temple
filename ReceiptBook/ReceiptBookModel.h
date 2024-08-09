#ifndef RECEIPTBOOKMODEL_H
#define RECEIPTBOOKMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include "ReceiptDataModel.h"

using namespace std;

namespace SmartTemple {
namespace ReceiptBookManagement {
class ReceiptBookModel : public QAbstractTableModel
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
    explicit ReceiptBookModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    ReceiptDataModel *m_receiptDataModel;
    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
    void setReceiptDataModel(ReceiptDataModel *newReceiptDataModel);
};
}
}

#endif // RECEIPTBOOKMODEL_H
