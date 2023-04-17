#include "JSONWriter.h"
#include "./model/Seva/SevaBookingConformationDataModel.h"

JsonWriter::JsonWriter(QObject *parent)
    : IDataWriter(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

JsonWriter::~JsonWriter()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

bool JsonWriter::saveData(QObject *obj)
{
    SevaBookingConformationDataModel *sevaData = qobject_cast<SevaBookingConformationDataModel*>(obj);
    Q_ASSERT(sevaData != nullptr);
    this->writeToJson(sevaData->sevaReceipt(),sevaData->sevabookinglist());
    return true;
}

void JsonWriter::writeToJson(MySevaReceipt *sr, QList<SevaName *> sevaNamesList)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString todayDate = QDate::currentDate().toString("ddd_dd_MMM_yyyy");
    QString path =  "Data/" + todayDate+".json";
    QFile file(path);
    QByteArray bytes ;
    QJsonParseError jsonError;
    QJsonDocument jsonDocument ;
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<Q_FUNC_INFO<<"----file open-----"<<Qt::endl;
        bytes = file.readAll();
        jsonDocument = QJsonDocument::fromJson(bytes, &jsonError);
//        if(jsonError.error!=QJsonParseError::NoError)
//        {
//            qDebug()<<"parsing fromJson failed: "<<"-1-"<<QJsonParseError::NoError<<Qt::endl;
//            qDebug()<<"parsing fromJson failed: "<<"-2-"<<jsonError.error<<Qt::endl;
//            qDebug()<<"parsing fromJson failed: "<<"--"<<jsonError.errorString()<<Qt::endl;
//            return;
//        }
        file.close();
    }
    else{
        qDebug()<<"File not opened"<<Qt::endl;
    }

    QJsonObject receiptAndSevaNameObject = jsonDocument.object();
    QJsonObject receiptObject;
    QJsonObject sevaNameObject;

    //--------------------------------------
    receiptObject.insert("receiptNo",sr->receiptNo());
    receiptObject.insert("devoteeName",sr->devoteeName());
    receiptObject.insert("mobilenumber",sr->mobilenumber());
    receiptObject.insert("nakshtra",sr->nakshtra());
    receiptObject.insert("gothra",sr->gothra());
    receiptObject.insert("receiptDate",sr->receiptDate());
    receiptObject.insert("momento",sr->momento());
    receiptObject.insert("bookedBy",sr->bookedBy());
    receiptObject.insert("reference",sr->reference());
    receiptObject.insert("address",sr->address());

    //--------------------------------------
    for(int i = 0;i<sevaNamesList.size();i++)
    {
        sevaNameObject.insert("sevaName",sevaNamesList.at(i)->sevaName());
        sevaNameObject.insert("sevaId",sevaNamesList.at(i)->sevaId());
        sevaNameObject.insert("Number",sevaNamesList.at(i)->Number());
        sevaNameObject.insert("sevaType",sevaNamesList.at(i)->sevaType());
        sevaNameObject.insert("sevaCost",sevaNamesList.at(i)->sevaCost());
        sevaNameObject.insert("teerthaPrasada",sevaNamesList.at(i)->teerthaPrasada());
        sevaNameObject.insert("count",sevaNamesList.at(i)->count());
        sevaNameObject.insert("additionalCost",sevaNamesList.at(i)->additionalCost());
        sevaNameObject.insert("sevaTime",sevaNamesList.at(i)->sevaStartTime());
        receiptObject.insert(sevaNamesList.at(i)->sevaName(),sevaNameObject);
    }

    //------------------------------------------

    receiptAndSevaNameObject.insert(sr->receiptNo(),receiptObject);

    //------------------------------------------
    jsonDocument.setObject(receiptAndSevaNameObject);
    file.open(QIODevice::WriteOnly| QFile::Text | QFile::Truncate);
    file.write(jsonDocument.toJson());
    file.close();
}


