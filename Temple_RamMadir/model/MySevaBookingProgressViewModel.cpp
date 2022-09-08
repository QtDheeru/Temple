#include "MySevaBookingProgressViewModel.h"

MySevaBookingProgressViewModel::MySevaBookingProgressViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

MySevaBookingProgressViewModel::~MySevaBookingProgressViewModel()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

//QVariant MySevaBookingProgressViewModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

int MySevaBookingProgressViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
//    if (parent.isValid())
//        return 0;

    return m_sevaBookingList.size();
    // FIXME: Implement me!
}

QVariant MySevaBookingProgressViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    SevaName *s = m_sevaBookingList.at(index.row());
    switch(role){
        case 1 : return s->sevaName();
        case 2 : return s->sevaCost();
        case 4 : return s->sevaId();
    }

    // FIXME: Implement me!
    return QVariant();
}

bool MySevaBookingProgressViewModel::addSeva(SevaName *s)
{
    qDebug() << Q_FUNC_INFO << "AAAAAA"<< Qt::endl;
     int size1 = m_sevaBookingList.size();
     qDebug() << Q_FUNC_INFO << "BBBBBBBBBBBBB = "<< size1 <<  Qt::endl;
     this->beginInsertRows(QModelIndex(),size1,size1);
     qDebug() << Q_FUNC_INFO << "CCCCCC"<< Qt::endl;
     this->m_sevaBookingList.append(s);
     qDebug() << Q_FUNC_INFO << "DDDDDDDDDd"<< Qt::endl;
     this->endInsertRows();
     qDebug() << Q_FUNC_INFO << "FFFFFFFFF"<< Qt::endl;
     return true;
}

bool MySevaBookingProgressViewModel::deleteSeva(SevaName *s)
{
    for(int i=0;i<m_sevaBookingList.size();i++){
        SevaName *seva = m_sevaBookingList.at(i);
        if (s->sevaId() == seva->sevaId()){
            this->beginRemoveRows(QModelIndex(),i,i);
            this->m_sevaBookingList.removeAt(i);
            this->endRemoveRows();
            break;
        }
    }
    return true;
}

bool MySevaBookingProgressViewModel::resetModel()
{
     this->beginResetModel();
     m_sevaBookingList.clear();
     this->endResetModel();
     return true;
}

QHash<int, QByteArray> MySevaBookingProgressViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1]  = "sevaname";
    roles[2]  = "sevacost";
    roles[3]  = "sevaooked";
    roles[4]  = "sevaid";
    return roles;
}
