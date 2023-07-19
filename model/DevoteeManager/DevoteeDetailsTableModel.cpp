#include "DevoteeDetailsTableModel.h"
int DevoteeDetailsTableModel::x= 0;
int DevoteeDetailsTableModel::y= 0;
int DevoteeDetailsTableModel::z= 0;
DevoteeDetailsTableModel::DevoteeDetailsTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_devoteModel = DevoteDetailsDataModel::getInstance();
    connect(m_devoteModel,&DevoteDetailsDataModel::devoteeAdded,
            this,[this](){
        qDebug()<<Q_FUNC_INFO<<" Add New Devotee is succesfull " << Qt::endl;
        this->beginInsertRows(QModelIndex(),m_devoteModel->size()-1,m_devoteModel->size()-1);
        this->endInsertRows();
    });
    connect(m_devoteModel,&DevoteDetailsDataModel::devoteeUpdated,
            this,[this](int updatedIndex){
        qDebug()<<Q_FUNC_INFO<<" Update Devotee is succesfull " << updatedIndex << Qt::endl;
        QModelIndex left1 = index(updatedIndex,0);
        QModelIndex right1 = index(updatedIndex,5);
        emit dataChanged(left1,right1);
    });
    connect(m_devoteModel,&DevoteDetailsDataModel::devoteeDeleted,
            this,[this](int deletedIndex){
        qDebug()<<Q_FUNC_INFO<<" Delete Devotee is succesfull " << deletedIndex << Qt::endl;
        beginRemoveRows(QModelIndex(),deletedIndex,deletedIndex);
        endRemoveRows();
    });
}

DevoteeDetailsTableModel::~DevoteeDetailsTableModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int DevoteeDetailsTableModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO << m_devoteModel->size() <<x<< Qt::endl;
    Q_UNUSED(parent);
    x++;
    return m_devoteModel->size();
}

int DevoteeDetailsTableModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO << m_devoteModel->size() <<y<< Qt::endl;
    Q_UNUSED(parent);
    y++;
    return 5;
}

QVariant DevoteeDetailsTableModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<" Data for Row =" << index.row() << " column ="<<index.column()<<" Role =" << role<<Qt::endl;

    QVariant data2Send;
    if (!index.isValid()) {
        qWarning()<<Q_FUNC_INFO<<z<<" Invalid Index for Row =" << index.row() <<Qt::endl;
        return data2Send;
    }
    qDebug()<<Q_FUNC_INFO<<" Data for Row =1";
    int sevaRow = index.row();
    qDebug()<<Q_FUNC_INFO<<" Data for Row =2";
    DevotePersnalDetails *devotee = m_devoteModel->getDevotee(sevaRow);
    qDebug()<<Q_FUNC_INFO<<" Data for Row =3";
    if (devotee == nullptr){
        qWarning()<<Q_FUNC_INFO<<z<<" No Devotee Data for Row ="<<index.row()<< " Col =" << index.column()<<" Role=" << role<<Qt::endl;
        return data2Send;
    }
    switch(role){
    case SNO_ROLE: {
        qWarning() << Q_FUNC_INFO << " Data = " << index.row() << Qt::endl;
        data2Send = index.row();
        break;
    }
    case PERSON_DBID_ROLE: {
        qWarning() << Q_FUNC_INFO << " Data = " << devotee->personDbId() << Qt::endl;
        data2Send = devotee->personDbId();
        break;
    }
    case MOBILE_NUMBER_ROLE: {
        data2Send = devotee->mobileNumber();
        qWarning() << Q_FUNC_INFO << " Invalid Role " << Qt::endl;
        break;
    }
    case DEVOTEE_NAME_ROLE: {
        data2Send =  devotee->devoteeName();
        qWarning() << Q_FUNC_INFO << " Invalid Role " << Qt::endl;
        break;
    }
    case GOTHRA_ROLE: {
        data2Send =  devotee->gothra();
        qWarning() << Q_FUNC_INFO << " Invalid Role " << Qt::endl;
        break;
    }
    case NAKSHATRA_ROLE: {
        data2Send =  devotee->nakshatra();
        qWarning() << Q_FUNC_INFO << " Invalid Role " << Qt::endl;
        break;
    }

    default : {
        qWarning() << Q_FUNC_INFO << " Invalid Role " << Qt::endl;
    }
    }
    qDebug()<<Q_FUNC_INFO<< data2Send << Qt::endl;
    return data2Send;
}

QHash<int, QByteArray> DevoteeDetailsTableModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles.insert(SNO_ROLE,"SerialNo");
    roles.insert(PERSON_DBID_ROLE,"PersonDbID");
    roles.insert(DEVOTEE_NAME_ROLE,"DevoteeName");
    roles.insert(MOBILE_NUMBER_ROLE,"MobileNumber");
    roles.insert(GOTHRA_ROLE,"Gothra");
    roles.insert(NAKSHATRA_ROLE,"Nakshatra");
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return roles;
}


void DevoteeDetailsTableModel::printBookingList()
{

}
