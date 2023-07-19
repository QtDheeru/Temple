#include "devoteeproxy.h"

DevoteeProxy::DevoteeProxy()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    devoteeTableModel=nullptr;
    devoteeSearchModel=nullptr;
    devoteeDataModel = nullptr;
    devoteeTableModel = new DevoteeDetailsTableModel;
    devoteeSearchModel = new DevoteeDetailsSearchModel;
    devoteeSearchModel->setSourceModel(devoteeTableModel);
    devoteeDataModel =  DevoteDetailsDataModel::getInstance();
}

DevoteeProxy::~DevoteeProxy()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

DevoteeDetailsSearchModel *DevoteeProxy::getDevoteeSearchModel() const
{
    return devoteeSearchModel;
}

void DevoteeProxy::setDevoteeSearchModel(DevoteeDetailsSearchModel *newDevoteeSearchModel)
{
    if (devoteeSearchModel == newDevoteeSearchModel)
        return;
    devoteeSearchModel = newDevoteeSearchModel;
    emit devoteeSearchModelChanged();
}

DevoteDetailsDataModel *DevoteeProxy::getDevoteeDataModel() const
{
    return devoteeDataModel;
}

void DevoteeProxy::setDevoteeDataModel(DevoteDetailsDataModel *newDevoteeDataModel)
{
    if (devoteeDataModel == newDevoteeDataModel)
        return;
    devoteeDataModel = newDevoteeDataModel;
    emit devoteeDataModelChanged();
}

DevoteeDetailsTableModel *DevoteeProxy::getDevoteeTableModel() const
{
    return devoteeTableModel;
}

void DevoteeProxy::setDevoteeTableModel(DevoteeDetailsTableModel *newDevoteeTableModel)
{
    if (devoteeTableModel == newDevoteeTableModel)
        return;
    devoteeTableModel = newDevoteeTableModel;
    emit devoteeTableModelChanged();
}
