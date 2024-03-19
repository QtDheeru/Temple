#include "DevoteeDataInterface.h"
#include <QElapsedTimer>

DevoteeDataInterface* DevoteeDataInterface::m_self = nullptr;
DevoteeDataInterface::DevoteeDataInterface(QObject *parent)
    : QObject{parent}
{
    db=DBInterface::getInstance()->db;
}

//bool DevoteeDataInterface::openDataInterface()
//{
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    QString currentPath = "nseva.db";
//    QFileInfo info(currentPath);
//    if (!info.exists()){
//        qWarning()<<Q_FUNC_INFO<<"**************** DB path doesn't exist as a file = "<< currentPath <<Qt::endl;
//        return false;
//    }
//    db.setDatabaseName(currentPath);

//    bool ok = db.open();
//    qDebug()<<Q_FUNC_INFO<<"******************* DB"<<currentPath<< Qt::endl;
//    if(ok){
//        qDebug()<< Q_FUNC_INFO << "Database is opened " << currentPath<<Qt::endl;
//    } else {
//        qCritical()<< Q_FUNC_INFO << "Database is NOT opened " <<currentPath <<Qt::endl;
//        exit(0);
//    }
//    return true;
//}

DevoteeDataInterface *DevoteeDataInterface::getInstance()
{

    if (m_self == nullptr) {
        qDebug() << "Creating the DataBase Connection " <<Qt::endl;
        m_self = new DevoteeDataInterface();
        //m_self->openDataInterface();
    }
    return m_self;
}

const QString &DevoteeDataInterface::error() const
{
    return m_error;
}

void DevoteeDataInterface::setError(const QString &newError)
{
    m_error = newError;
}

QList<DevotePersnalDetails *> DevoteeDataInterface::searchMobile(QString mobile_num)
{
    qDebug()<< Q_FUNC_INFO<< " Mobile_number searching"<<  mobile_num<<Qt::endl;

    QElapsedTimer el;
    el.start();
    QList<DevotePersnalDetails*> m_searchList;
    static QString qryFixPart = "select * from persondetails";
    QString sqlQuery = QString("%1").arg(qryFixPart);
    qDebug() << Q_FUNC_INFO << " SQL Query = " << sqlQuery << Qt::endl;
    QSqlQuery qry;
    qry.prepare(sqlQuery);
    qry.exec(sqlQuery);
    while(qry.next()){
        QString  d_mobile = qry.value(5).toString().trimmed();
        if (d_mobile.contains(mobile_num)){
            qDebug() << Q_FUNC_INFO << " Mobile Matching.. = " << d_mobile << Qt::endl;
            DevotePersnalDetails* devotee = new DevotePersnalDetails;
            int personId =qry.value(0).toInt();
            QString  d_Name =qry.value(1).toString().trimmed();
            QString  d_Gotra = qry.value(2).toString().trimmed();
            QString  d_Nakshatra =qry.value(3).toString().trimmed();
            devotee->setPersonDbId(QString::number(personId));
            devotee->setDevoteeName(d_Name);
            devotee->setNakshatra(d_Nakshatra);
            devotee->setGothra(d_Gotra);
            devotee->setMobileNumber(d_mobile);
            //devotee->print();
            m_searchList.append(devotee);
        }
    }
    qDebug() << Q_FUNC_INFO << " Total Devotees Matched " << m_searchList.size() << qry.lastError() << " Time Spent =" << el.elapsed() << Qt::endl;
    return m_searchList;
}

QList<DevotePersnalDetails *> DevoteeDataInterface::getAllDevotees()
{
    QElapsedTimer el;
    el.start();
    QList<DevotePersnalDetails*> searchList;
    static QString qryFixPart = "select * from persondetails";
    QString sqlQuery = QString("%1").arg(qryFixPart);
    qDebug() << Q_FUNC_INFO << " SQL Query = " << sqlQuery << Qt::endl;
    QSqlQuery qry;
    qry.prepare(sqlQuery);
    qry.exec(sqlQuery);
    while(qry.next()){
        DevotePersnalDetails* devotee = new DevotePersnalDetails;
        QString personId =qry.value(0).toString();
        QString  d_Name =qry.value(1).toString().trimmed();
        QString  d_Gotra = qry.value(2).toString().trimmed();
        QString  d_Nakshatra =qry.value(3).toString().trimmed();
        QString  d_mobile = qry.value(5).toString().trimmed();
        devotee->setPersonDbId(personId);
        devotee->setDevoteeName(d_Name);
        devotee->setNakshatra(d_Nakshatra);
        devotee->setGothra(d_Gotra);
        devotee->setMobileNumber(d_mobile);
        devotee->print();
        searchList.append(devotee);
    }
    qDebug() << Q_FUNC_INFO << " Total Devotees Matched " << searchList.size() << qry.lastError() << " Time Spent =" << el.elapsed() << Qt::endl;
    return searchList;
}

bool DevoteeDataInterface::addDevotee(DevotePersnalDetails *devotee)
{
    qDebug() << Q_FUNC_INFO;
    devotee->print();

    int count=1;
    int personDbID = 0;
    static QString qryFixPart = "select * from persondetails";
    QString sqlQuery = QString("%1").arg(qryFixPart);
    QSqlQuery qry;
    qry.prepare(sqlQuery);
    qry.exec(sqlQuery);
    while(qry.next()){
        QString  d_mobile = qry.value(5).toString().trimmed();
        if (d_mobile.contains(devotee->mobileNumber())){
            qDebug() << " Mobile Found =" << qry.value(1).toString().trimmed();
            count++;
        }
        int pId = qry.value(0).toInt();
        if(pId>personDbID){
            personDbID=pId;
        }
    }
    QString mobileNumber = QString("%1_%2").arg(devotee->mobileNumber()).arg(count);
    qDebug() << Q_FUNC_INFO << " Mobile to Insert = " << mobileNumber << Qt::endl;

    personDbID++;
    devotee->setMobileNumber(mobileNumber);
    devotee->setPersonDbId(QString::number(personDbID));
    qDebug() << Q_FUNC_INFO << " personDbID = " << personDbID << Qt::endl;
    return this->insertPersonDetails(devotee);
}

bool DevoteeDataInterface::updateDevotee(DevotePersnalDetails *devotee)
{
    qDebug() <<Q_FUNC_INFO<<devotee->nakshatra()<<Qt::endl;
    QSqlQuery qry;
    QString stringQry = QString("select * from persondetails where MOBILE='%1'").arg(devotee->mobileNumber().trimmed());
    qry.prepare(stringQry);
    qDebug() << Q_FUNC_INFO << " Query Before Updating =" << stringQry <<Qt::endl;
    qry.exec();
    if (qry.next()){
        int personId=qry.value(0).toInt();
        QSqlQuery u_qry;
        u_qry.prepare("UPDATE persondetails SET SNO=:sno,PERSONNAME=:person_name,GOTHRA=:gothra,NAKSHATRA=:nakshatra WHERE MOBILE=:mobile");
        u_qry.bindValue(":sno",personId);
        u_qry.bindValue(":mobile",devotee->mobileNumber());
        u_qry.bindValue(":person_name",devotee->devoteeName());
        u_qry.bindValue(":gothra",devotee->gothra());
        u_qry.bindValue(":nakshatra",devotee->nakshatra());
        bool succ = u_qry.exec();
        if(succ) {
            qDebug()<< Q_FUNC_INFO << " Successfully updated person name to "<<devotee->devoteeName()<<Qt::endl;
            return true;
        } else {
            qWarning()<< Q_FUNC_INFO << " Update of following person FAILED..." << Qt::endl;
            devotee->print();
            this->setError(" DB Insert Error ="+u_qry.lastError().text());
            return false;
        }
    } else {
        qry.clear();
        qDebug() << Q_FUNC_INFO <<" Devotee does not exist" << Qt::endl;
        return false;
    }
}

bool DevoteeDataInterface::deleteDevotee(DevotePersnalDetails *devotee)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM persondetails WHERE MOBILE=:devoteMobileNo");
    qry.bindValue(":devoteMobileNo", devotee->mobileNumber());
    bool result = qry.exec();
    if (!result){
        this->setError(qry.lastError().text());
        return false;
    }
    return result;
}


bool DevoteeDataInterface::insertPersonDetails(DevotePersnalDetails *devotee)
{
    qDebug()<<Q_FUNC_INFO << " Name: "<<devotee->devoteeName()<<" Mobile: "<<devotee->mobileNumber();

    QSqlQuery qry;
    qry.prepare("INSERT INTO persondetails(SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE)"
                "VALUES (:sno, :person_name, :gothra, :nakshatra, :date, :mobile)");
    qry.bindValue(":sno",devotee->personDbId());
    qry.bindValue(":person_name",devotee->devoteeName());
    qry.bindValue(":gothra",devotee->gothra());
    qry.bindValue(":nakshatra",devotee->nakshatra());
    qry.bindValue(":date",QDate::currentDate().toString("dd-MMM-yyyy"));
    qry.bindValue(":mobile",devotee->mobileNumber());
    if( qry.exec()){
        qDebug() << Q_FUNC_INFO << " Person insert success full"<< devotee->mobileNumber() <<Qt::endl;
        return true;
    } else {
        qWarning() << Q_FUNC_INFO << " Person insert success full"<< devotee->mobileNumber() <<Qt::endl;
        this->setError(" DB Insert Error ="+qry.lastError().text());
        return false;
    }
}
