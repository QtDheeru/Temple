#include "JsonProcessor.h"

JsonProcessor::JsonProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

JsonProcessor::~JsonProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QList<BankDetails *> &JsonProcessor::banksList() const
{
    return m_banksList;
}

void JsonProcessor::setBanksList(const QList<BankDetails *> &newBanksList)
{
    m_banksList = newBanksList;
}

QStringList JsonProcessor::bankListAsStringList()
{
   QStringList list;
   foreach(BankDetails* BankDetails,m_banksList){
           list.append(BankDetails->bankName());
   }
   return list;
}

QStringList JsonProcessor::categoryListAsStringList()
{
   QStringList list;
   foreach(MomentoCategory* category,m_categoryList){
           list.append(category->categoryName());
   }
   return list;
}

const QMap<int, BankDetails *> &JsonProcessor::banksMap() const
{
    return m_banksMap;
}

void JsonProcessor::setBanksMap(const QMap<int, BankDetails *> &newBanksMap)
{
    m_banksMap = newBanksMap;
}

const QList<MomentoCategory *> &JsonProcessor::categoryList() const
{
    return m_categoryList;
}

void JsonProcessor::setCategoryList(const QList<MomentoCategory *> &newCategoryList)
{
    m_categoryList = newCategoryList;
}

const QMap<int, MomentoCategory *> &JsonProcessor::categoryMap() const
{
    return m_categoryMap;
}

void JsonProcessor::setCategoryMap(const QMap<int, MomentoCategory *> &newCategoryMap)
{
    m_categoryMap = newCategoryMap;
}
void  JsonProcessor::readBanksFromJsonToList()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path = "Data/Banks.json";
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"file opened"<<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug()<<"read all"<<Qt::endl;
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);
        if(jsonError.error!=QJsonParseError::NoError)
        {

            qDebug()<<"parsing fromJson failed: "<<jsonError.error<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<QJsonParseError::NoError<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<jsonError.errorString()<<Q_FUNC_INFO<<Qt::endl;
            return;
        }
        QJsonObject jsonObject ;
        if(document.isObject())
        {
            qDebug()<<Q_FUNC_INFO<<"dddddddoooooooooooocccccccc"<<Qt::endl;
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                BankDetails* b = new BankDetails;
                QJsonObject obj=jsonObject.value(s).toObject();
                QList<QString> strList = obj.keys();
                for(QString s1 : strList)
                {
                    auto value  = obj.take(s1);
                    if(s1=="BankName")
                    {
                        b->setBankName(value.toString());
                    }
                    if(s1=="Id")
                    {
                        b->setBankId(value.toInt());
                    }
                }
                m_banksList.append(b);
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }
    file.close();
}

void  JsonProcessor::readBanksFromJsonToMap()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path = "Banks.json";
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"file opened"<<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug()<<"read all"<<Qt::endl;
        QJsonParseError jsonError;
        if(jsonError.error!=QJsonParseError::NoError)
        {

            qDebug()<<"parsing fromJson failed: "<<jsonError.error<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<QJsonParseError::NoError<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<jsonError.errorString()<<Q_FUNC_INFO<<Qt::endl;
            return;
        }
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);
        QJsonObject jsonObject ;
        if(document.isObject())
        {
            qDebug()<<Q_FUNC_INFO<<"dddddddoooooooooooocccccccc"<<Qt::endl;
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        QString v ;
        int k;
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                BankDetails* b = new BankDetails;
                QJsonObject obj=jsonObject.value(s).toObject();
                QList<QString> strList = obj.keys();
                for(QString s1 : strList)
                {
                    auto value  = obj.take(s1);
                    if(s1=="BankName")
                    {
                        b->setBankName(value.toString());
                    }
                    if(s1=="Id")
                    {
                        k = value.toInt();
                        b->setBankId(value.toInt());
                    }
                }
                m_banksMap.insert(k,b);
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }
    file.close();
}

void JsonProcessor::readCategoriesFromJsonToList()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path = "Momento.json";
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"file opened"<<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug()<<"read all"<<Qt::endl;
        QJsonParseError jsonError;
        if(jsonError.error!=QJsonParseError::NoError)
        {

            qDebug()<<"parsing fromJson failed: "<<jsonError.error<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<QJsonParseError::NoError<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<jsonError.errorString()<<Q_FUNC_INFO<<Qt::endl;
            return;
        }
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);
        QJsonObject jsonObject ;
        if(document.isObject())
        {
            qDebug()<<Q_FUNC_INFO<<"dddddddoooooooooooocccccccc"<<Qt::endl;
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                MomentoCategory* c = new MomentoCategory;
                QJsonObject obj=jsonObject.value(s).toObject();
                QList<QString> strList = obj.keys();
                for(QString s1 : strList)
                {
                    auto value  = obj.take(s1);
                    if(s1=="CategoryName")
                    {
                        c->setCategoryName(value.toString());
                    }
                    if(s1=="Id")
                    {
                        c->setCategoryId(value.toInt());
                    }
                }
                m_categoryList.append(c);
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }
    file.close();
}

void JsonProcessor::readCategoriesFromJsonToMap()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path = "Momento.json";
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"file opened"<<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug()<<"read all"<<Qt::endl;
        QJsonParseError jsonError;
        if(jsonError.error!=QJsonParseError::NoError)
        {

            qDebug()<<"parsing fromJson failed: "<<jsonError.error<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<QJsonParseError::NoError<<Q_FUNC_INFO<<Qt::endl;
            qDebug()<<"parsing fromJson failed: "<<jsonError.errorString()<<Q_FUNC_INFO<<Qt::endl;
            return;
        }
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);
        QJsonObject jsonObject ;
        if(document.isObject())
        {
            qDebug()<<Q_FUNC_INFO<<"dddddddoooooooooooocccccccc"<<Qt::endl;
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        QString v ;
        int k;
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                MomentoCategory* c = new MomentoCategory;
                QJsonObject obj=jsonObject.value(s).toObject();
                QList<QString> strList = obj.keys();
                for(QString s1 : strList)
                {
                    auto value  = obj.take(s1);
                    if(s1=="CategoryName")
                    {
                        c->setCategoryName(value.toString());
                    }
                    if(s1=="Id")
                    {
                        k = value.toInt();
                        c->setCategoryId(value.toInt());
                    }
                }
                m_categoryMap.insert(k,c);
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }
    file.close();
}
void JsonProcessor::printBanksList()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(BankDetails* b :m_banksList)
    {
        qDebug()<<"Bank name "<<b->bankId()<<Qt::endl;
        qDebug()<<"Bank id "<<b->bankId()<<Qt::endl;
        qDebug()<<"----------list-------- "<<b->bankId()<<Qt::endl;
    }
}

void JsonProcessor::printBanksMap()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QMapIterator<int,BankDetails*> it(m_banksMap);
    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << ": " << it.value()->bankName()<<","<<it.value()->bankId() << Qt::endl;
    }

}

void JsonProcessor::printCategoriesList()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(MomentoCategory* c :m_categoryList)
    {
        qDebug()<<"category Name "<<c->categoryName()<<Qt::endl;
        qDebug()<<"category id "<<c->categoryId()<<Qt::endl;
        qDebug()<<"----------list-------- "<<Qt::endl;
    }
}

void JsonProcessor::printCategoriesMap()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QMapIterator<int,MomentoCategory*> it(m_categoryMap);
    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << ": " << it.value()->categoryName()<<","<<it.value()->categoryId() << Qt::endl;
    }
}
