#ifndef SEVAJSON_H
#define SEVAJSON_H

#include <QObject>
#include <QDebug>
#include "MySevaReceipt.h"
#include "SevaBookingConformationDataModel.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDate>
#include "IDataWriter.h"

class JsonWriter : public IDataWriter
{
    Q_OBJECT
public:
    explicit JsonWriter(QObject *parent = nullptr);
    ~JsonWriter();
    bool saveData(QObject *obj) override;
    void writeToJson(MySevaReceipt* sr, QList<SevaName*> sevaNamesList);

signals:

};

#endif // SEVAJSON_H
