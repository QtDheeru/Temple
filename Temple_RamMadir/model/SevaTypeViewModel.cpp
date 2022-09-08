#include "SevaTypeViewModel.h"

SevaTypeViewModel::SevaTypeViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->init();
}

//QVariant SevaTypeViewModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//    return "";
//}

int SevaTypeViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
//    if (parent.isValid())
//        //return 0;
        return m_sevaTypes.size();
    // FIXME: Implement me!
}

QVariant SevaTypeViewModel::data(const QModelIndex &index, int role) const
{
    //Q_UNUSED(role);
    qDebug() << Q_FUNC_INFO << " Row =" << index.row() <<Qt::endl;
    if (!index.isValid())
        return QVariant();

    SevaType *s = this->m_sevaTypes.at(index.row());
    switch(role){
        case 1 : return s->sevaTypeId();
        case 2 : return s->sevaTypeName();
    }

    //return QVariant::fromValue(m_sevaTypes.at(index.row()));
    return QVariant();

}

bool SevaTypeViewModel::init()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_sevaTypes.append(SevaTypeNamesDataModel::self()->getSevaTypes());
    qDebug() << Q_FUNC_INFO << " Number of Seva Types =" << m_sevaTypes.size() <<Qt::endl;
    return true;
}


QHash<int, QByteArray> SevaTypeViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "sevaTypeId";
    roles[2] = "sevaTypeName";
    return roles;
}
