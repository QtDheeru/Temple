#include "SevaListViewModel.h"
#include "SevaTypeNamesDataModel.h"

SevaListViewModel::SevaListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->init();
}

//QVariant SevaListViewModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

int SevaListViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    //    if (parent.isValid())
    //        return 0;

    return this->m_sevaList.size();
    // FIXME: Implement me!
}

QVariant SevaListViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    int row = index.row();
    SevaName *seva = m_sevaList.at(row);
    Q_ASSERT(seva != nullptr);
    switch(role){
    case 1 : return seva->sevaName();
    case 2 : return seva->sevaId();
    case 3 : return seva->sevaType();
    }
    // FIXME: Implement me!
    return QVariant();
}

void SevaListViewModel::init()
{
    for(int i=0;i<30;i++){
        SevaName *sevaN = new SevaName;
        sevaN->setSevaId(i);
        sevaN->setSevaName(" Pallakki Utsava_"+QString::number(i));
        this->m_sevaList.append(sevaN);
    }
}

void SevaListViewModel::initSevaList(int sevaType)
{
    SevaTypeNamesDataModel *dataModel = SevaTypeNamesDataModel::self();
    qDebug() << Q_FUNC_INFO <<  "data model object == " << dataModel <<  Qt::endl;
    Q_ASSERT(dataModel != nullptr);
    qDebug() << Q_FUNC_INFO << dataModel->getSevaList(sevaType) << Qt::endl;
    m_sevaList = dataModel->getSevaList(sevaType);
}

SevaName *SevaListViewModel::getSevaByIndex(int index)
{
    qDebug() << Q_FUNC_INFO <<m_sevaList << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Index requested 1=" << index  << Qt::endl;
    Q_ASSERT(m_sevaList.at(index) != nullptr);
    return this->m_sevaList.at(index);
    qDebug() << Q_FUNC_INFO << " Index requested 2=" << index << Qt::endl;
}

QHash<int, QByteArray> SevaListViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SevaName";
    roles[2] = "SevaId";
    roles[3] = "SevaType";

    return roles;
}