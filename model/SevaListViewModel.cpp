#include "SevaListViewModel.h"
#include "SevaTypeNamesDataModel.h"

SevaListViewModel::SevaListViewModel(QObject *parent)
    : QAbstractListModel(parent),m_sevaTypeNameModel(nullptr)
{
    qDebug() << Q_FUNC_INFO << "Created #####################" << Qt::endl;
    connect(SevaTypeNamesDataModel::self(),&SevaTypeNamesDataModel::newSevaAdded,this,&SevaListViewModel::sevaNameListUpdated);
    this->init();
}

SevaListViewModel::~SevaListViewModel()
{
    qDebug() << Q_FUNC_INFO << "Deleted #####################" << Qt::endl;
}


int SevaListViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    //    if (parent.isValid())
    //        return 0;

    return this->m_sevaTypeNameModel->getSevaListSizeForType(m_sevaType);
}

QVariant SevaListViewModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << "Seva Type = " << m_sevaType << Qt::endl;
    if (!index.isValid())
        return QVariant();
    int row = index.row();
    SevaName *seva = m_sevaTypeNameModel->getSevaList(m_sevaType).at(row);
    Q_ASSERT(seva != nullptr);
    switch(role){
    case 1 : return seva->sevaName();
    case 2 : return seva->sevaId();
    case 3 : return seva->sevaType();
    }
    return QVariant();
}

void SevaListViewModel::init()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_sevaTypeNameModel = SevaTypeNamesDataModel::self();
}

void SevaListViewModel::initSevaList(int sevaType)
{
    qDebug() << Q_FUNC_INFO <<  "Seva Type =" << sevaType << Qt::endl;
    Q_ASSERT(m_sevaTypeNameModel != nullptr);
    qDebug() << Q_FUNC_INFO <<  "Seva Type =" << sevaType << Qt::endl;
    beginResetModel();
    m_sevaType = sevaType;
    endResetModel();
}

int SevaListViewModel::getSevaListViewSize()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_sevaTypeNameModel->getSevaListSizeForType(m_sevaType);
}

SevaName *SevaListViewModel::getSevaNameByIndex(int sevaType, int index)
{
    qDebug() << Q_FUNC_INFO << "SevaType:" << sevaType << " :: index:" << index << Qt::endl;
    return m_sevaTypeNameModel->getSevaList(sevaType).at(index);
}

void SevaListViewModel::recvClosedObj(int sevaid)
{
    int idx = m_sevaTypeNameModel->removeSevaName(m_sevaType,sevaid);
    beginRemoveRows(QModelIndex(),idx,idx);
    endRemoveRows();
    qDebug() << Q_FUNC_INFO << " Seva Type = " << m_sevaType << " :: sevaname ID :" << sevaid <<Qt::endl;
}

void SevaListViewModel::sevaNameListUpdated(SevaName *sevaname)
{
    qDebug() << Q_FUNC_INFO << " New Seva Added " << sevaname->sevaName() <<Qt::endl;
    sevaname->print();
//    beginInsertRows(QModelIndex(), m_sevaTypeNameModel->getSevaList(m_sevaType).size(),m_sevaTypeNameModel->getSevaList(m_sevaType).size());
//    //m_sevaTypeNameModel->getSevaList(m_sevaType).append(sevaname);
//    endInsertRows();

    beginResetModel();

    endResetModel();
}

QHash<int, QByteArray> SevaListViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SevaName";
    roles[2] = "SevaId";
    roles[3] = "SevaType";

    return roles;
}
