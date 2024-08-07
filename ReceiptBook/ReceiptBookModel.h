#ifndef RECEIPTBOOKMODEL_H
#define RECEIPTBOOKMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include "ReceiptBookManager.h"

using namespace std;
using namespace SmartTemple::ReceiptBookManagement;

class ReceiptBookModel : public QAbstractTableModel
{
    Q_OBJECT

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

    std::unique_ptr<ReceiptBookManager> m_receiptBookManager;
};

#endif // RECEIPTBOOKMODEL_H
