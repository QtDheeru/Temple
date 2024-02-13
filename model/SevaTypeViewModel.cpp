#include "SevaTypeViewModel.h"

SevaTypeViewModel::SevaTypeViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->init();
}

SevaTypeViewModel::~SevaTypeViewModel()
{
    qDebug() << Q_FUNC_INFO << " Object is getting destroyed..." << Qt::endl;
}

//QVariant SevaTypeViewModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//    return "";
//}

int SevaTypeViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    qDebug() << Q_FUNC_INFO << " Row Count == " <<  m_sevaTypes.size()  << Qt::endl;
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    //    if (parent.isValid())
    //        //return 0;
    return m_sevaTypes.size();
    // FIXME: Implement me!
}

QVariant SevaTypeViewModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    qDebug() << Q_FUNC_INFO << " Row =" << index.row() <<Qt::endl;
    if (!index.isValid())
        return QVariant();

    SevaType *s = this->m_sevaTypes.at(index.row());
    switch(role){
    case 1 : return s->sevaTypeId();break;
    case 2 : return s->sevaTypeName();break;
    }

    //return QVariant::fromValue(m_sevaTypes.at(index.row()));
    return QVariant();

}

bool SevaTypeViewModel::init()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    beginInsertRows(QModelIndex(),m_sevaTypes.size(),m_sevaTypes.size());
    m_sevaTypes.append(SevaTypeNamesDataModel::self()->getSevaTypes());
    endInsertRows();
    qDebug() << Q_FUNC_INFO << " Number of Seva Types =" << m_sevaTypes.size() <<Qt::endl;
    return true;
}

bool SevaTypeViewModel::reflectToView(SevaType *sevatype)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    beginInsertRows(QModelIndex(),m_sevaTypes.size(),m_sevaTypes.size());
    m_sevaTypes.append(sevatype);
    endInsertRows();
    qDebug() << Q_FUNC_INFO << " Number of Seva Types =" << m_sevaTypes.size() <<Qt::endl;
    return true;

}

const QList<SevaType *> &SevaTypeViewModel::sevaTypes() const
{
    return m_sevaTypes;
}

void SevaTypeViewModel::setSevaTypes(const QList<SevaType *> &newSevaTypes)
{
    m_sevaTypes = newSevaTypes;
}

SevaType *SevaTypeViewModel::getSevaTypeByIndex(int index)
{
    return  m_sevaTypes.at(index);
}

QString SevaTypeViewModel::getSevaTypeName(int id)
{
    QString SevatypeName;
    for(auto it = m_sevaTypes.begin(); it != m_sevaTypes.end();it++){
        if(id==(*it)->sevaTypeId()){
            SevatypeName = (*it)->sevaTypeName();
        }
    }
    return SevatypeName;
}


QHash<int, QByteArray> SevaTypeViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "sevaTypeId";
    roles[2] = "sevaTypeName";
    return roles;
}

int SevaTypeViewModel::getSevaTypeListSize()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_sevaTypes.size();
}
