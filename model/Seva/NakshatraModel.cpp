#include "NakshatraModel.h"

NakshatraModel::NakshatraModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

//QVariant NakshatraModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

int NakshatraModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 1;
}

QVariant NakshatraModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool NakshatraModel::getNakshathras()
{
     this->m_nakshathras = DBInterface::getInstance()->qryNakshatras();
    return true;
}
