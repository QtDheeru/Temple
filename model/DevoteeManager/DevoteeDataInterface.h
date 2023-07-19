#ifndef DEVOTEEDATAINTERFACE_H
#define DEVOTEEDATAINTERFACE_H

#include <QObject>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>

#include "model/DevotePersnalDetails.h"
#include "model/DBInterface.h"
class DevoteeDataInterface : public QObject
{
    Q_OBJECT
public:
    explicit DevoteeDataInterface(QObject *parent = nullptr);
    //bool openDataInterface();
    QList<DevotePersnalDetails*> searchMobile(QString mobile_num);
    QList<DevotePersnalDetails*> getAllDevotees();
    bool addDevotee(DevotePersnalDetails *devotee);
    bool updateDevotee(DevotePersnalDetails *devotee);
    bool deleteDevotee(DevotePersnalDetails *devotee);
    bool insertPersonDetails(DevotePersnalDetails *devotee);

signals:


public :
    static DevoteeDataInterface* m_self;
    static DevoteeDataInterface* getInstance();

    QSqlDatabase db;
    const QString &error() const;
    void setError(const QString &newError);

private :
    QString m_error;
};

#endif // DEVOTEEDATAINTERFACE_H
