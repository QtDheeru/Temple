#include "SevaTypeNamesDataModel.h"
#include <QQmlEngine>

SevaTypeNamesDataModel *SevaTypeNamesDataModel::_instance =nullptr;

SevaTypeNamesDataModel* SevaTypeNamesDataModel::self()
{
    if (_instance == nullptr) {
        qDebug() << "Creating the SevaTypeNamesDataModel " << Qt:: endl;
        _instance = new SevaTypeNamesDataModel;
    }
    qDebug() << Q_FUNC_INFO << "SevaTypeNamesDataModel Object is returned" << Qt::endl;
    return _instance;
}

SevaTypeNamesDataModel::SevaTypeNamesDataModel(QObject *parent) : QObject(parent)
    ,m_receiptGenerator(new SevaReceiptNumber)
    ,m_sevaBookingProgress(new MySevaBookingProgressViewModel)
    ,m_sevaBookingModel(new SevaBookingConformationDataModel)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    QQmlEngine::setObjectOwnership(m_sevaBookingProgress, QQmlEngine::CppOwnership);
    connectSignals();
    this->querySevaTypes();
    this->querySevaNames();
}

SevaTypeNamesDataModel::~SevaTypeNamesDataModel()
{
    qDebug() << Q_FUNC_INFO << "Deleted $$$$$$$$$$$$$$$$$$$$$$"<< Qt::endl;
}

bool SevaTypeNamesDataModel::querySevaTypes()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DBInterface::getInstance()->querySevaType();
    return true;
}

bool SevaTypeNamesDataModel::querySevaNames()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DBInterface::getInstance()->querySevaNames();
    return true;
}

QList<SevaName *> SevaTypeNamesDataModel::getSevaList(int sevaType)
{
    qDebug() << Q_FUNC_INFO << " Seva Type =" << sevaType << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Is empty = " << m_sevaNameDetails.empty() << Qt::endl;

    if(m_sevaNameDetails.empty()){
        qCritical() << Q_FUNC_INFO << "SevaNameDetails is empty !!!" << Qt::endl;
        exit(0);
    }
    qDebug() << Q_FUNC_INFO << "  m_sevaNameDetaiils is not empty." << sevaType << Qt::endl;
    QMap<int, SevaName*> map = this->m_sevaNameDetails.value(sevaType);
    qDebug() << Q_FUNC_INFO << "  Took values of sevanames " << sevaType  << ":: Seva Name detail size : " << m_sevaNameDetails.size()<< Qt::endl;
    qDebug() << Q_FUNC_INFO << " Sevas===== > " << this->m_sevaNameDetails << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Sevas===== > " << m_sevaNameDetails[0] << Qt::endl;
    if(map.empty())
    {
        qCritical() << Q_FUNC_INFO << " save name details  map is empty!!!" << Qt::endl;
        m_sevaNameDetails.remove(sevaType);
        m_sevaTypeDetails.remove(sevaType);
    }
    qDebug() << "Map values=" << map.values() << Qt::endl;
    return map.values();
}

bool SevaTypeNamesDataModel::processSevaTypes(SevaType *st)
{
    qDebug() << Q_FUNC_INFO << " Inserting Seva  Type =" << st->sevaTypeId() <<Qt::endl;
    QQmlEngine::setObjectOwnership(st, QQmlEngine::CppOwnership);
    this->m_sevaTypeDetails.insert(st->sevaTypeId(),st);
    return true;
}

int SevaTypeNamesDataModel::getSevaListSizeForType(int sevaType)
{
    int sevaCount = m_sevaNameDetails.value(sevaType).size();
    qDebug() << Q_FUNC_INFO << " Total Sevas in Type =" << sevaType << " count =" << sevaCount ;
    return sevaCount;
}

bool SevaTypeNamesDataModel::processSevaNames(SevaName *sn)
{
    qDebug() << Q_FUNC_INFO << " Inseting Seva Name "<<sn->sevaName() << " Type =" << sn->sevaType() << " SevaID ="<<sn->Number() <<Qt::endl;
    QQmlEngine::setObjectOwnership(sn,QQmlEngine::CppOwnership);
    QMap<int,SevaName*> sevaNameMap;
    if (m_sevaNameDetails.contains(sn->sevaType())){
        sevaNameMap = m_sevaNameDetails.value(sn->sevaType());
    }
    sevaNameMap.insert(sn->Number(),sn);
    m_sevaNameDetails.insert(sn->sevaType(),sevaNameMap);
    qDebug() << Q_FUNC_INFO << m_sevaNameDetails.values();
    return true;
}

QList<SevaType *> SevaTypeNamesDataModel::getSevaTypes()
{
    return this->m_sevaTypeDetails.values();
}

SevaName *SevaTypeNamesDataModel::getSevaDetails(int sevaType, int sevaId)
{
    return this->m_sevaNameDetails.value(sevaType).value(sevaId);
}

int SevaTypeNamesDataModel::removeSevaName(int sevaType, int sevaId)
{
    qDebug() << Q_FUNC_INFO << "SevaType : " << sevaType << " :: SevaNameId : " << sevaId << Qt::endl;

    QMap<int,SevaName*> sevaNameMap = (m_sevaNameDetails.value(sevaType));//.value(sevaId);//.remove(sevaId);
    if(sevaNameMap.empty()){
        qWarning() << Q_FUNC_INFO << " Seva Name map is empty!!" << Qt::endl;
        return -1;
    }

    QList<SevaName*> sevaList = sevaNameMap.values();
    if(sevaList.empty()){
        qWarning() << Q_FUNC_INFO << " Seva Name list is empty!!" << Qt::endl;
        return -1;
    }
    SevaName* seva = sevaNameMap.take(sevaId);
    m_sevaNameDetails[sevaType] = sevaNameMap;
    int index = sevaList.indexOf(seva);
    delete seva;
    return index;
}

bool SevaTypeNamesDataModel::printSevaDetails(int sevaType, int sevaId)
{
    this->m_sevaNameDetails.value(sevaType).value(sevaId)->print();
    return true;
}

bool SevaTypeNamesDataModel::addSevaOnly(SevaName *s)
{
    qDebug() << Q_FUNC_INFO << "aaaaaa"<< Qt::endl;
    if (this->m_sevaBookingModel->addSeva(s)){
        qDebug() << Q_FUNC_INFO << "bbbbb"<< s->sevaCost() << s->sevaName()<<s->additionalCost()<<Qt::endl;
        this->m_sevaBookingProgress->addSeva(s);
        qDebug() << Q_FUNC_INFO << "cccccc"<< Qt::endl;
        return true;
    } else
    {
        // seva already exist. Don't add anywhere
        qDebug() << Q_FUNC_INFO << "ddddddd"<< Qt::endl;
        return false;
    }
}

bool SevaTypeNamesDataModel::deleteSeva(SevaName *s)
{
    bool b1 = this->m_sevaBookingModel->deleteSeva(s);
    bool b2 = this->m_sevaBookingProgress->deleteSeva(s);
    return b1||b2;
}

SevaBookingConformationDataModel *SevaTypeNamesDataModel::getSevaBookingConformationDataModel()
{
    return m_sevaBookingModel;
}

void SevaTypeNamesDataModel::setSevaBookingConformationDataModel(SevaBookingConformationDataModel *newData)
{
    m_sevaBookingModel = newData;
    emit SevaBookingConformationDataModelChanged();
}

QString SevaTypeNamesDataModel::createNewSeva(SevaName *seva)
{
    qDebug() << Q_FUNC_INFO << "seva = "  << seva->sevaName() << Qt::endl;
    if(DBInterface::getInstance()->createSeva(seva)) {
        emit newSevaAdded(seva);
        qDebug() << Q_FUNC_INFO << "Seva Added Successfully" << Qt::endl;
    }else{
        qWarning() << Q_FUNC_INFO << "Error in Seva Adding" << Qt::endl;
    }
    return  DBInterface::getInstance()->getError();
}

SevaType* SevaTypeNamesDataModel::addSevaTypeDetail(int seva_id, QString seva_name, QString person_name)
{
    SevaType* sevatype = new SevaType;
    sevatype->setSevaTypeId(seva_id);
    sevatype->setSevaTypeName(seva_name);
    m_sevaTypeDetails.insert(seva_id,sevatype);
    return sevatype;

}

QStringList SevaTypeNamesDataModel::getNakshatras()
{
    return DBInterface::getInstance()->qryNakshatras();
}

QStringList SevaTypeNamesDataModel::getGothras()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    return DBInterface::getInstance()->qryGothras();
}

QStringList SevaTypeNamesDataModel::getBankList()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    return DBInterface::getInstance()->qryBankList();
}

QString SevaTypeNamesDataModel::getNextReceiptNumber()
{
    return this->m_receiptGenerator->getNextReceiptNumber();
}

DevotePersnalDetails *SevaTypeNamesDataModel::searchMobile(QString mobile)
{
    return DBInterface::getInstance()->mobileNumberSearching(mobile);
}

void SevaTypeNamesDataModel::connectSignals() {
    qDebug() << Q_FUNC_INFO << Qt::endl;
    connect(DBInterface::getInstance(),&DBInterface::sendSevaType,this,&SevaTypeNamesDataModel::processSevaTypes);
    connect(DBInterface::getInstance(),&DBInterface::sendSevaName ,this,&SevaTypeNamesDataModel::processSevaNames);
    connect(DBInterface::getInstance(),&DBInterface::dbError,this,&SevaTypeNamesDataModel::error);
}

MySevaBookingProgressViewModel *SevaTypeNamesDataModel::getSevaBookingProgress() const
{
    return m_sevaBookingProgress;
}

bool SevaTypeNamesDataModel::resetBookingProgressModel()
{
    this->m_sevaBookingModel->reset();
    return this->m_sevaBookingProgress->resetModel();
}

bool SevaTypeNamesDataModel::printReceipt()
{
    m_sevaBookingModel->printReceipt();
    return true;
}

bool SevaTypeNamesDataModel::saveReceiptDetails(QString recNumber, QString devName, QString mobNumber, QString nakshatra, QString gothra)
{
    this->m_sevaBookingModel->saveReceiptDetails(recNumber,devName,mobNumber,nakshatra,gothra);
    return true;
}

bool SevaTypeNamesDataModel::saveReceipt(MySevaReceipt *receipt)
{
    this->m_sevaBookingModel->saveReceipt(receipt);
    return true;
}
