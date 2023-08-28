#include "VoucherSubHeadsTableModel.h"

VoucherSubHeadsTableModel::VoucherSubHeadsTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    m_voucherSubHeadsDataModel = new VoucherSubHeadsDataModel();
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::onDeletion_Failed,this,&VoucherSubHeadsTableModel::toTableDelete);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::toTableDialog,this,&VoucherSubHeadsTableModel::onTableDialog);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::onUpdated_Failed,this,&VoucherSubHeadsTableModel::toFailedUpdate);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::updated_data,this,&VoucherSubHeadsTableModel::row_Slot);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::addToTableModel,this,&VoucherSubHeadsTableModel::onAddToTableModel);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::onUpdated_Success,this,&VoucherSubHeadsTableModel::UpdateSuccessProxy);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::onDeletion_Success,this,&VoucherSubHeadsTableModel::deletion_SuccessProxy);
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::onInsert_Success,this,&VoucherSubHeadsTableModel::Insert_SuccessProxy);
}


int VoucherSubHeadsTableModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO;
    return m_voucherSubHeadsDataModel->my_rowCount(parent);
}

int VoucherSubHeadsTableModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO;
    return m_voucherSubHeadsDataModel->my_columnCount(parent);
}

QVariant VoucherSubHeadsTableModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO;
    qDebug()<<"helloss"<<m_voucherSubHeadsDataModel->data(index,role);
    return m_voucherSubHeadsDataModel->data(index,role);
}

QHash<int, QByteArray> VoucherSubHeadsTableModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<" TBM "<<m_voucherSubHeadsDataModel->roleNames();;
    return m_voucherSubHeadsDataModel->roleNames();

}
VoucherSubHeadsTableModel::~VoucherSubHeadsTableModel()
{
    qDebug()<<Q_FUNC_INFO;

}

void VoucherSubHeadsTableModel::voucher_data(QString id)
{
    qDebug()<<Q_FUNC_INFO;
    m_voucherSubHeadsDataModel->set_MainId(id);

}

void VoucherSubHeadsTableModel::selectRow(int my_row)
{
    m_voucherSubHeadsDataModel->set_data(my_row);
}

void VoucherSubHeadsTableModel::toTableModel()
{
    m_voucherSubHeadsDataModel->getFromModel();
    qDebug()<<"Inside toTableModel Function";
    connect(m_voucherSubHeadsDataModel,&VoucherSubHeadsDataModel::my_data,this,&VoucherSubHeadsTableModel::fromTm);

}

void VoucherSubHeadsTableModel::clickTable()
{
    m_voucherSubHeadsDataModel->clickModel();
}

void VoucherSubHeadsTableModel::clearTable()
{
    this->beginResetModel();
    m_voucherSubHeadsDataModel->clearModel();
    this->endResetModel();
}

void VoucherSubHeadsTableModel::updateToTable(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsDataModel->updateToModel(vid,sid,sname);

}

void VoucherSubHeadsTableModel::deleteToTable(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsDataModel->deleteToModel(vid,sid,sname);
}
void VoucherSubHeadsTableModel::addToTable(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsDataModel->addFromModel(vid,sid,sname);

}

void VoucherSubHeadsTableModel::onAddToTableModel(int first, int last)
{
    qDebug()<<"Called Insert Rows in VoucherSubHeadsTableModel ";
    beginInsertRows(QModelIndex(),first-1,last-1);
    endInsertRows();
}

void VoucherSubHeadsTableModel::onTableDialog()
{
    emit toProxyDialog();
}

void VoucherSubHeadsTableModel::row_Slot(QString subid,QString name)
{
    emit row_Signal(subid,name);
}

void VoucherSubHeadsTableModel::fromTm(QString subcat, QString subname, QString voucherId)
{
    qDebug()<<"Inside fromTm function";
    emit toMyProxy(subcat,subname,voucherId);

}

