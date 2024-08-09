#include "TrustConfiguration.h"

TrustConfiguration::TrustConfiguration(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

TrustConfiguration::~TrustConfiguration()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void TrustConfiguration::readTrustsFromJsonToList()
{
    QString path ;
    path = QCoreApplication::applicationDirPath();
    qDebug()<<Q_FUNC_INFO<<"path "<<path<<Qt::endl;
    QFile file(path+"/Trusts.json");
    if(!file.exists())
    {
        qDebug()<<Q_FUNC_INFO<<"File not exist"<<Qt::endl;
        return;
    }
    if(!QDir(path+"/Data").exists())
    {
        QDir().mkdir(path+"/Data");
        qDebug()<<Q_FUNC_INFO<<"Data dir created"<<Qt::endl;
    }
    if(!QDir(path+"/Config").exists())
    {
        QDir().mkdir(path+"/Config");
        qDebug()<<Q_FUNC_INFO<<"Config dir created"<<Qt::endl;
    }
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug() <<Q_FUNC_INFO <<" File opened ="<< file.fileName() <<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug() << Q_FUNC_INFO <<" Read all the contents of file = "<<  file.fileName() <<Qt::endl;
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);
        if(jsonError.error!=QJsonParseError::NoError)
        {

            qWarning()<<Q_FUNC_INFO<<"parsing fromJson failed: "<<jsonError.error<<Q_FUNC_INFO<<Qt::endl;
            qWarning()<<Q_FUNC_INFO<<"parsing fromJson failed: "<<QJsonParseError::NoError<<Q_FUNC_INFO<<Qt::endl;
            qWarning()<<Q_FUNC_INFO<<"parsing fromJson failed: "<<jsonError.errorString()<<Q_FUNC_INFO<<Qt::endl;
            return;
        }
        QJsonObject jsonObject ;
        if(document.isObject())
        {
            qDebug()<<Q_FUNC_INFO<<""<<Qt::endl;
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                Trust* t = new Trust;
                QJsonObject obj=jsonObject.value(s).toObject();
                QList<QString> strList = obj.keys();
                for(QString s1 : strList)
                {
                    auto value  = obj.take(s1);
                    //value.toInt();
                    if(s1=="TrustName")
                    {
                        t->setTrustName(value.toString());
                    }
                    if(s1=="TrustCode")
                    {
                        t->setTrustCode(value.toString());
                        if(QDir(path+"/Data").exists())
                        {
                            if(!QDir(path+"/Data/"+value.toString()).exists())
                            {
                                QDir().mkdir(path+"/Data/"+value.toString());
                            }
                        }
                        if(QDir(path+"/Config").exists())
                        {
                            if(!QDir(path+"/Config/"+value.toString()).exists())
                            {
                                QDir().mkdir(path+"/Config/"+value.toString());
                            }
                        }
                    }
                }
                m_trustList.append(t);
            }
        }
    }
    else{
        qWarning()<<Q_FUNC_INFO<< "File not opened" << file.error()<<Qt::endl;
    }
    file.close();
}

void TrustConfiguration::printTrustList()
{
    for(Trust* t :m_trustList)
    {
        qDebug()<<Q_FUNC_INFO<<"Trust Name "<<t->trustName()<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<"Trust Code"<<t->trustCode()<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<"----------list-------- "<<Qt::endl;
    }
}

const QList<Trust *> &TrustConfiguration::trustList() const
{
    return m_trustList;
}

void TrustConfiguration::setTrustList(const QList<Trust *> &newTrustList)
{
    m_trustList = newTrustList;
}
