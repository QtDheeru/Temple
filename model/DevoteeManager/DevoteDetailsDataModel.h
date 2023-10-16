#ifndef DEVOTEDETAILSDATAMODEL_H
#define DEVOTEDETAILSDATAMODEL_H

#include <QObject>
#include <QDebug>
#include <QList>

#include "model/DevotePersnalDetails.h"
#include "DevoteeDataInterface.h"

class DevoteDetailsDataModel : public QObject
{
    Q_OBJECT
    explicit DevoteDetailsDataModel(QObject *parent = nullptr);
public:

    int size();

    Q_INVOKABLE DevotePersnalDetails *getDevotee(int index);
    Q_INVOKABLE bool addDevotee(DevotePersnalDetails *devotee);
    Q_INVOKABLE bool addDevoteeJSObject(QVariantMap map);
    Q_INVOKABLE bool updateDevoteeJSObject(QVariantMap map);
    Q_INVOKABLE bool deleteDevoteeJSObject(QVariantMap map);

    Q_INVOKABLE bool updateDevotee(DevotePersnalDetails *devotee);
    Q_INVOKABLE bool deleteDevotee(DevotePersnalDetails *devotee);
    Q_INVOKABLE QString lastError();
    Q_INVOKABLE bool printAll();

    QList<DevotePersnalDetails*> searchDevotee(QString mobileNo);


signals:
    void devoteeAdded();
    void devoteeUpdated(int updatedIndex);
    void devoteeDeleted(int updatedIndex);

public :
    static DevoteDetailsDataModel* m_self;
    static DevoteDetailsDataModel* getInstance();

    const QString &error() const;
    void setError(const QString &newError);

public slots:


private :
    bool searchDevoteeByName(QString mobileNo,QString name);
    DevotePersnalDetails* searchDevoteeByMobile(QString mobileNo);

private :
    QList<DevotePersnalDetails*> m_devoteeList;
    QString m_error;
    int m_devoteeFoundIndex;

};

#endif // DEVOTEDETAILSDATAMODEL_H
