#ifndef DEVOTEEPROXY_H
#define DEVOTEEPROXY_H

#include <QObject>
#include <QDebug>
#include "DevoteeDetailsSearchModel.h"
#include "DevoteeDetailsTableModel.h"
class DevoteeProxy:public QObject
{
    Q_OBJECT

    Q_PROPERTY(DevoteeDetailsTableModel *devoteeTableModel READ getDevoteeTableModel WRITE setDevoteeTableModel NOTIFY devoteeTableModelChanged)
    Q_PROPERTY(DevoteeDetailsSearchModel *devoteeSearchModel READ getDevoteeSearchModel WRITE setDevoteeSearchModel NOTIFY devoteeSearchModelChanged)
    Q_PROPERTY(DevoteDetailsDataModel *devoteeDataModel READ getDevoteeDataModel WRITE setDevoteeDataModel NOTIFY devoteeDataModelChanged)

public:
    DevoteeProxy();
    ~DevoteeProxy();

    DevoteeDetailsTableModel *getDevoteeTableModel() const;
    void setDevoteeTableModel(DevoteeDetailsTableModel *newDevoteeTableModel);
    DevoteeDetailsSearchModel *getDevoteeSearchModel() const;
    void setDevoteeSearchModel(DevoteeDetailsSearchModel *newDevoteeSearchModel);

    DevoteDetailsDataModel *getDevoteeDataModel() const;
    void setDevoteeDataModel(DevoteDetailsDataModel *newDevoteeDataModel);

signals:
    void devoteeTableModelChanged();
    void devoteeSearchModelChanged();
    void devoteeDataModelChanged();

private:
    DevoteeDetailsTableModel* devoteeTableModel;
    DevoteeDetailsSearchModel* devoteeSearchModel;
    DevoteDetailsDataModel* devoteeDataModel;
};

#endif // DEVOTEEPROXY_H
