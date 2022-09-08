#ifndef TRUSTCONFIGURATION_H
#define TRUSTCONFIGURATION_H

#include <QObject>
#include<QDebug>
#include"Trust.h"
#include<QFile>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QDir>
#include<QCoreApplication>

class TrustConfiguration : public QObject
{
    Q_OBJECT
public:
    explicit TrustConfiguration(QObject *parent = nullptr);
    ~TrustConfiguration();
     void readTrustsFromJsonToList();
     void printTrustList();

     const QList<Trust *> &trustList() const;
     void setTrustList(const QList<Trust *> &newTrustList);

signals:

private:
    QList<Trust*> m_trustList;

};

#endif // TRUSTCONFIGURATION_H
