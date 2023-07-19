#include "DevoteDetailsDataModel.h"
#include <QQmlEngine>

DevoteDetailsDataModel* DevoteDetailsDataModel::m_self = nullptr;

DevoteDetailsDataModel::DevoteDetailsDataModel(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->m_devoteeList = DevoteeDataInterface::getInstance()->getAllDevotees();
    qDebug() << Q_FUNC_INFO << " Total Devotees =" << m_devoteeList.size();
    m_devoteeFoundIndex = -1;
}

DevotePersnalDetails *DevoteDetailsDataModel::getDevotee(int index)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    DevotePersnalDetails* devotee = m_devoteeList.at(index);
    QQmlEngine::setObjectOwnership(devotee,QQmlEngine::CppOwnership);
    return m_devoteeList.at(index);
}

int DevoteDetailsDataModel::size()
{
    qDebug() << Q_FUNC_INFO << " Number of Devotees =" << this->m_devoteeList.size() <<Qt::endl;
    return this->m_devoteeList.size();
}

bool DevoteDetailsDataModel::addDevotee(DevotePersnalDetails *devotee)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    devotee->print();
    return true;
}

bool DevoteDetailsDataModel::addDevoteeJSObject(QVariantMap map)
{
    qDebug() << Q_FUNC_INFO << map << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Devotee Name =" << map["devoteeName"];
    QString mobile = map["mobileNumber"].toString();
    QString devoteeName = map["devoteeName"].toString();
    int idx = mobile.indexOf("_");
    if (idx > 0){
        mobile = mobile.mid(0,idx);
        qDebug() << Q_FUNC_INFO << " Mobile Adjusted =" << mobile;
    }
    if (searchDevoteeByName(mobile.trimmed(),devoteeName.trimmed())) {
        return false;
    }
    DevotePersnalDetails *devotee  = new DevotePersnalDetails;
    devotee->setDevoteeName(map["devoteeName"].toString());
    devotee->setMobileNumber(mobile);
    devotee->setNakshatra(map["nakshatra"].toString());
    devotee->setGothra(map["gothra"].toString());
    QQmlEngine::setObjectOwnership(devotee,QQmlEngine::CppOwnership);
    if(DevoteeDataInterface::getInstance()->addDevotee(devotee)){
        qDebug()<<"inside if the devotee add function"<<Qt::endl;
        this->m_devoteeList.append(devotee);
        emit devoteeAdded();
        qDebug()<<"After emit if the devotee add function"<<Qt::endl;
        return true;
    } else {
        return false;
    }
}

bool DevoteDetailsDataModel::updateDevoteeJSObject(QVariantMap map)
{
    qDebug() << Q_FUNC_INFO << " Devotee Name =" << map["devoteeName"];
    QString mobile = map["mobileNumber"].toString();
    QString devoteeName = map["devoteeName"].toString();
    DevotePersnalDetails *devotee = searchDevoteeByMobile(mobile.trimmed());
    if (devotee != nullptr) {
        QScopedPointer<DevotePersnalDetails> devotee2Update(new DevotePersnalDetails);
        devotee2Update->setDevoteeName(devotee->devoteeName());
        devotee2Update->setMobileNumber(devotee->mobileNumber());
        devotee2Update->setNakshatra(map["nakshatra"].toString());
        devotee2Update->setGothra(map["gothra"].toString());
        if(DevoteeDataInterface::getInstance()->updateDevotee(devotee2Update.data())){
            devotee->setGothra(devotee2Update->gothra());
            devotee->setNakshatra(devotee2Update->nakshatra());
            emit devoteeUpdated(m_devoteeFoundIndex);
            return true;
        } else {
            QString dbError = DevoteeDataInterface::getInstance()->error();
            QString error = QString("Not Exist - %1 with Mobile =%2. Error =%3 \n Trying Adding Devotee ?").arg(devoteeName).arg(mobile).arg(dbError);
            this->setError(error);
            return false;
        }
    } else {
        QString error = QString("Not Exist Cache - %1 with Mobile =%2 \n Trying Adding Devotee ?").arg(devoteeName).arg(mobile);
        this->setError(error);
        return false;
    }
}

bool DevoteDetailsDataModel::deleteDevoteeJSObject(QVariantMap map)
{
    this->m_devoteeFoundIndex = -1;
    qDebug() << Q_FUNC_INFO << " Devotee Name =" << map["devoteeName"];
    QString mobile = map["mobileNumber"].toString();
    QString devoteeName = map["devoteeName"].toString();
    DevotePersnalDetails *devoteeFound = searchDevoteeByMobile(mobile.trimmed());
    if (devoteeFound != nullptr) {
        QScopedPointer<DevotePersnalDetails> devotee2Delete(new DevotePersnalDetails);
        devotee2Delete->setDevoteeName(devoteeName);
        devotee2Delete->setMobileNumber(mobile);
        if(DevoteeDataInterface::getInstance()->deleteDevotee(devotee2Delete.data())){
            this->m_devoteeList.removeAt(m_devoteeFoundIndex);
            emit devoteeDeleted(m_devoteeFoundIndex);
            return true;
        } else {
            QString dbError = DevoteeDataInterface::getInstance()->error();
            QString error = QString("Not Exist - %1 with Mobile =%2. Error =%3 \n Delete Failed ?").arg(devoteeName).arg(mobile).arg(dbError);
            this->setError(error);
            return false;
        }
        return true;
    } else {
        QString error = QString("Not Exist - %1 with Mobile =%2 \n Trying Adding Devotee ?").arg(devoteeName).arg(mobile);
        this->setError(error);
        return false;
    }
}

bool DevoteDetailsDataModel::updateDevotee(DevotePersnalDetails *devotee)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

bool DevoteDetailsDataModel::deleteDevotee(DevotePersnalDetails *devotee)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

QString DevoteDetailsDataModel::lastError()
{
    return this->error();
}

bool DevoteDetailsDataModel::printAll()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

QList<DevotePersnalDetails *> DevoteDetailsDataModel::searchDevotee(QString mobileNo)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

DevoteDetailsDataModel *DevoteDetailsDataModel::getInstance()
{
    if (m_self == nullptr) {
        qDebug() << "Creating the DataModel Object " <<Qt::endl;
        m_self = new DevoteDetailsDataModel();
    }
    return m_self;
}

bool DevoteDetailsDataModel::searchDevoteeByName(QString mobileNo, QString name)
{
    bool found = false;
    DevotePersnalDetails *devoteeFound = nullptr;
    foreach(auto devote, this->m_devoteeList){
        if(devote->mobileNumber().startsWith(mobileNo)) {
            qDebug() << Q_FUNC_INFO << " Mobile Number found. Check Name =" << devote->devoteeName() << " Name =" << name <<Qt::endl;
            if (devote->devoteeName().compare(name)==0){
                found = true;
                QString error = QString(" Name %1 with Mobile =%2 already exist").arg(name).arg(mobileNo);
                this->setError(error);
                devoteeFound = devote;
                break;
            }
        }
    }
    return found;
}

DevotePersnalDetails* DevoteDetailsDataModel::searchDevoteeByMobile(QString mobileNo)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DevotePersnalDetails *devoteeFound = nullptr;
    foreach(auto devote, this->m_devoteeList){
        m_devoteeFoundIndex++;
        if(devote->mobileNumber().startsWith(mobileNo)) {
            qDebug() << Q_FUNC_INFO << " Mobile Number found. Check Name =" << devote->devoteeName() <<Qt::endl;
            QString error = QString(" Name %1 with Mobile =%2 already exist").arg(devote->devoteeName()).arg(mobileNo);
            this->setError(error);
            devoteeFound = devote;
            break;
        }
    }
    return devoteeFound;
}

const QString &DevoteDetailsDataModel::error() const
{
    return m_error;
}

void DevoteDetailsDataModel::setError(const QString &newError)
{
    m_error = newError;
}
