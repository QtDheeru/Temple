#include "SevaDetailsOnDateRangeModel.h"

SevaDetailsOnDateRangeModel::SevaDetailsOnDateRangeModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant SevaDetailsOnDateRangeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int SevaDetailsOnDateRangeModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SevaDetailsOnDateRangeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> SevaDetailsOnDateRangeModel::roleNames() const
{

}

void SevaDetailsOnDateRangeModel::onDateRangeSelected(QString start, QString end)
{
 DBInterface::getInstance()->qrySevabookingByDateRange(start,end);
}
