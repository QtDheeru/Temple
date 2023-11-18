#include "SevaTypeJsonProcessor.h"
#include <QDate>

SevaTypeJsonProcessor::SevaTypeJsonProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

SevaTypeJsonProcessor::~SevaTypeJsonProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void SevaTypeJsonProcessor::readSevaTypeFromJsonFormate()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString path = TrustListModel::getTrustListModelInstance()->getConfigLocation()+"/SevaTypes.json";
    QFile file(path);
    if(!file.exists())
    {
        qDebug()<<"File not exist"<<Qt::endl;
        return;
    }
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
            jsonObject = document.object();
        }
        QList<QString> sl = jsonObject.keys();
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                if(s!="")
                {
                    int max = v.top();
                    v.setRange(0,max);
                    int pos =0;
                    if(!( v.validate(s,pos) == QValidator::Acceptable))
                    {
                        qDebug()<<Q_FUNC_INFO<<"not a valid Seva Code"<<Qt::endl;
                    }
                    SevaType* st = new SevaType;
                    QJsonObject obj=jsonObject.value(s).toObject();
                    QList<QString> strList = obj.keys();
                    for(QString s1 : strList)
                    {
                        if(s1!="")
                        {
                            auto value  = obj.take(s1);

                            if(s1=="Name")
                            {
                                if(value.toString()!="")
                                {
                                    st->setSevaTypeName(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<"Name is empty"<<Qt::endl;
                                }
                            }
                            if(s1=="SevaCode")
                            {

                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid sevaTypeId"<<v.validate(z,pos)<<Qt::endl;
                                }
                                else
                                {
                                    st->setSevaTypeId(z.toInt());
                                }
                            }
                            if(s1=="UserName")
                            {
                                if(value.toString()!="")
                                {
                                    st->setUserName(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<"UserName is empty"<<Qt::endl;
                                }
                            }
                        }
                        else{
                            qDebug()<<Q_FUNC_INFO<<"string is empty"<<Qt::endl;
                        }
                    }
                    m_sevaTypeList.append(st);
                    qDebug()<<Q_FUNC_INFO<<" m_sevaTypeList.append(st);"<<Qt::endl;
                    m_sevaTypeMap.insert(s.toInt(),st);
                    emit sendSevaType(st);
                }
                else{
                    qDebug()<<Q_FUNC_INFO<<"string is empty"<<Qt::endl;
                }
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }

    file.close();
}

void SevaTypeJsonProcessor::printSevaTypeNames()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QMapIterator<int,SevaType*> it(m_sevaTypeMap);
    while (it.hasNext()) {
        it.next();
        qDebug()<<it.key() << ": " << it.value()->sevaTypeName()<<","<<it.value()->sevaTypeId()<<","
                 << it.value()->userName()<< Qt::endl;

    }
}

void SevaTypeJsonProcessor::readSevasFromJsonFormate()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    QString path = TrustListModel::getTrustListModelInstance()->getConfigLocation()+"/SevaNames.json";
    QFile file(path);
    qDebug() << Q_FUNC_INFO <<" path"<<path<<Qt::endl;
    //  int sevaId = 1000;
    if(!file.exists())
    {
        qDebug()<<Q_FUNC_INFO<<"File not exist"<<Qt::endl;
        return;
    }
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<< Q_FUNC_INFO <<"file opened"<<Qt::endl;
        QByteArray bytes = file.readAll();
        qDebug()<< Q_FUNC_INFO<<"read all"<<Qt::endl;
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
            jsonObject = document.object();
        }
        bool flag = false;
        bool flag1 = false;
        QList<QString> sl = jsonObject.keys();
        for(QString s:sl)
        {
            if(jsonObject.contains(s))
            {
                if(s!="")
                {
                    int max = v.top();
                    v.setRange(0,max);
                    int pos =0;

                    double max1 = dv.top();
                    dv.setRange(0,max1);
                    int pos1 =0;
                    if(!(( v.validate(s,pos) == QValidator::Acceptable)||( v.validate(s,pos) == QValidator::Intermediate)))
                    {
                        qDebug()<<Q_FUNC_INFO<<"not a valid Seva Id for key"<<Qt::endl;
                    }
                    SevaName* sn = new SevaName;
                    QJsonObject obj=jsonObject.value(s).toObject();
                    QList<QString> strList = obj.keys();
                    for(QString s1 : strList)
                    {   if(s1!="")
                        {
                            auto value  = obj.take(s1);
                            if(s1=="SevaName")
                            {
                                if(value.toString()!="")
                                {
                                    qDebug()<<Q_FUNC_INFO<<" SevaName string = " <<value.toString() <<Qt::endl;
                                    sn->setSevaName(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<" SevaName string is empty"<<Qt::endl;
                                }
                            }
                            if(s1=="sevaId")
                            {
                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid sevaId"<<v.validate(z,pos)<<Qt::endl;
                                }
                                else
                                {
                                    qDebug()<<Q_FUNC_INFO<<" sevaID string = " <<z.toInt() <<Qt::endl;

                                    sn->setSevaId(z.toInt());
                                }

                            }
                            if(s1=="Number")
                            {

                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid Number"<<Qt::endl;
                                }
                                else
                                {
                                    qDebug()<<Q_FUNC_INFO<<" number string = " <<z.toInt() <<Qt::endl;
                                    sn->setNumber(z.toInt());
                                }
                            }
                            if(s1=="sevaType")
                            {
                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid SevaTypeCode"<<Qt::endl;
                                }
                                else
                                {

                                    for(SevaType* sevaType : m_sevaTypeList)
                                    {
                                        if((QString::number(sevaType->sevaTypeId()).compare(value.toString()))==0)
                                        {
                                            qDebug()<<Q_FUNC_INFO<<" sevatype string = " <<z.toInt() <<Qt::endl;
                                            sn->setSevaType(z.toInt());
                                            flag1 = true;
                                        }
                                    }
                                    if(flag1==false)
                                    {
                                        break;
                                    }
                                }
                            }
                            if(s1=="sevaCost")
                            {
                                QString z = value.toString();
                                if(!(( dv.validate(z,pos1) == QValidator::Acceptable)||( dv.validate(z,pos1) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid SevaCost"<<Qt::endl;
                                }
                                else
                                {
                                    if(z.toDouble()==0)
                                    {
                                        flag=true;
                                        break;
                                    }
                                    sn->setSevaCost(z.toDouble());
                                }
                            }
                            if(s1=="teerthaPrasada")
                            {
                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid theerthaPrasada"<<z<<Qt::endl;
                                }
                                else
                                {
                                    sn->setTeerthaPrasada(z.toInt());
                                }
                            }
                            if(s1=="sevaDate")
                            {
                                if(value.toString()!="")
                                {
                                    sn->setSevaStartDate(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<"SevaDate is empty"<<Qt::endl;
                                }
                            }
                            if(s1=="count")
                            {
                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid count"<<Qt::endl;
                                }
                                else
                                {
                                    sn->setCount(z.toInt());
                                }
                            }
                            if(s1=="additionalCost")
                            {
                                QString z = value.toString();
                                if(!(( v.validate(z,pos) == QValidator::Acceptable)||( v.validate(z,pos) == QValidator::Intermediate)))
                                {
                                    qDebug()<<Q_FUNC_INFO<<"not a valid additionalCost"<<Qt::endl;
                                }
                                else
                                {
                                    sn->setAdditionalCost(z.toInt());
                                }
                            }
                            if(s1=="sevaTime")
                            {
                                if(value.toString()!="")
                                {
                                    sn->setSevaStartTime(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<" SevaTime string is empty"<<Qt::endl;
                                }
                            }
                            if(s1=="sankalpa")
                            {
                                QString z = value.toString();
                                if(z!="")
                                {
                                    if((z=="true"))
                                    {
                                        sn->setSankalpa(true);
                                    }
                                    else
                                    {
                                        sn->setSankalpa(false);
                                    }
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<" sankalpa is empty"<<Qt::endl;
                                }
                            }
                            if(s1=="userName")
                            {
                                if(value.toString()!="")
                                {
                                    sn->setUserName(value.toString());
                                }
                                else{
                                    qDebug()<<Q_FUNC_INFO<<" userName string is empty"<<Qt::endl;
                                }
                            }
                        }
                        else{
                            qDebug()<<Q_FUNC_INFO<<"string is empty"<<Qt::endl;
                        }
                    }
                    if(flag==true)
                    {
                        qDebug()<<Q_FUNC_INFO<<"continue flag"<<Qt::endl;
                        continue;
                    }
                    qDebug()<<Q_FUNC_INFO<<"11"<<Qt::endl;
                    if(flag1==false)
                    {
                        qDebug()<<Q_FUNC_INFO<<"continue flag1"<<Qt::endl;
                        continue;
                    }
                    flag=false;
                    flag1=false;
                    qDebug()<<Q_FUNC_INFO<<"22"<<Qt::endl;
                    m_sevasList.append(sn);
                    qDebug()<<Q_FUNC_INFO<<"33"<<Qt::endl;
                    m_sevaNameMap.insert(s.toInt(),sn);
                    qDebug()<<Q_FUNC_INFO<<"emiting sendSevaName signal "<<Qt::endl;
                    emit sendSevaName(sn);
                }
                else
                {
                    qDebug()<<Q_FUNC_INFO<<"string is empty"<<Qt::endl;
                }
            }
        }
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }
    file.close();
}

void SevaTypeJsonProcessor::printSevasNames()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QMapIterator<int,SevaName*> it(m_sevaNameMap);
    while (it.hasNext())
    {
        it.next();
        qDebug()<<it.key() << ": " << it.value()->sevaName()<<","<<it.value()->sevaId() <<","
                 <<it.value()->Number()<<","<<it.value()->sevaType()<<","<<it.value()->sevaCost()
                 <<","<<it.value()->teerthaPrasada()<<","<<it.value()->sevaStartDate()<<","<<it.value()->count()
                 <<","<<it.value()->additionalCost()<<","<<it.value()->sevaStartTime()<<","<<it.value()->userName()
                 <<","<<it.value()->sankalpa()<<Qt::endl;
    }
}

