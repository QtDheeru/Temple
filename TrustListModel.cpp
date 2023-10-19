#include "TrustListModel.h"

TrustListModel* TrustListModel::m_self = nullptr;
TrustListModel::TrustListModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}

TrustListModel::~TrustListModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

TrustListModel *TrustListModel::getTrustListModelInstance()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(m_self==nullptr)
    {
        qDebug()<<Q_FUNC_INFO<<"In static getTrustListModelInstance of TrustListModel inside if"<<Qt::endl;
        m_self = new TrustListModel;
    }
    return m_self;
}

void TrustListModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_trustConfiguration = new TrustConfiguration;
    m_trustConfiguration->readTrustsFromJsonToList();
    this->m_trustList = m_trustConfiguration->trustList();
}

int TrustListModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
   return m_trustList.size();
}

QVariant TrustListModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row  = index.row();
    Trust* t = m_trustList.at(row);
    qDebug()<<Q_FUNC_INFO<<"-----------------------row="<<row<<"Role = "<<role<<"index="<<index<<Qt::endl;
    switch (role)
    {
    case 1 :  return t->trustName();break;
    case 2 :  return t->trustCode();break;
    }
    return "Failed to Return Trust";
}

QHash<int, QByteArray> TrustListModel::roleNames() const
{   
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles.insert(1,"TrustName");
    roles.insert(2,"TrustCode");
    return roles;
}

QString TrustListModel::getDataLocation()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_currentDataLocation;
}

QString TrustListModel::getConfigLocation()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_currentConfigLocation;
}

int TrustListModel::getTrustListSize()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_trustList.size();
}

const QString &TrustListModel::currentConfigLocation() const
{
    return m_currentConfigLocation;
}

void TrustListModel::setCurrentConfigLocation(const QString &newCurrentConfigLocation)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path;
    path = QCoreApplication::applicationDirPath();
    m_currentConfigLocation = path+"/Config/"+newCurrentConfigLocation;
    qDebug()<<Q_FUNC_INFO<<"m_currentConfigLocation "<<m_currentConfigLocation<<Qt::endl;
    emit currentConfigLocationChanged();
}

const QString &TrustListModel::currentDataLocation() const
{
    return m_currentDataLocation;
}

void TrustListModel::setCurrentDataLocation(const QString &newCurrentDataLocation)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path;
    path = QCoreApplication::applicationDirPath();
    m_currentDataLocation = path+"/Data/"+newCurrentDataLocation;
    qDebug()<<Q_FUNC_INFO<<"m_currentDataLocation "<<m_currentDataLocation<<Qt::endl;
    emit currentDataLocationChanged();
}

const QString &TrustListModel::currentTrust() const
{
    return m_currentTrust;
}

void TrustListModel::setCurrentTrust(const QString &newCurrentTrust)
{
    m_currentTrust = newCurrentTrust;
    emit currentTrustChanged();
}

const QList<Trust *> &TrustListModel::trustList() const
{
    return m_trustList;
}

void TrustListModel::setTrustList(const QList<Trust *> &newTrustList)
{
    m_trustList = newTrustList;
}

void TrustListModel::showCurrentConfigLocation()
{
    qDebug()<<Q_FUNC_INFO<<m_currentConfigLocation<<Qt::endl;
}

void TrustListModel::showCurrentDataLocation()
{
    qDebug()<<Q_FUNC_INFO<<m_currentDataLocation<<Qt::endl;
}

