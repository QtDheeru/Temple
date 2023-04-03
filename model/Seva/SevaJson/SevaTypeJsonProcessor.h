#ifndef SEVATYPEJSONPROCESSOR_H
#define SEVATYPEJSONPROCESSOR_H

#include <QObject>
#include<QDebug>
#include<QFile>
#include<QJsonParseError>
#include<QJsonObject>
#include<QJsonDocument>
#include "Sevas.h"
#include "model/SevaName.h"
#include "model/SevaType.h"
#include "TrustListModel.h"
#include <QIntValidator>
#include <QDoubleValidator>

class SevaTypeJsonProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SevaTypeJsonProcessor(QObject *parent = nullptr);
    ~SevaTypeJsonProcessor();
    void readSevaTypeFromJsonFormate();
    void printSevaTypeNames();
    void readSevasFromJsonFormate();
    void printSevasNames();

signals:
    void sendSevaType(SevaType*);
    void sendSevaName(SevaName*);

private:
    QList<SevaType*> m_sevaTypeList;
    QList<SevaName*> m_sevasList;
    QMap<int,SevaType*> m_sevaTypeMap;
    QMap<int,SevaName*> m_sevaNameMap;
    QIntValidator v;
    QDoubleValidator dv;
};

#endif // SEVATYPEJSONPROCESSOR_H
