#include "VoucherProxy.h"
#include <QQmlEngine>
VoucherProxy::VoucherProxy(QObject *parent)
    : QObject{parent}
{
    m_voucherSubHeadsTableModel = std::make_unique<VoucherSubHeadsTableModel>();
    m_voucherHeadsTableModel = std::make_unique<VoucherHeadsTableModel>();
    QQmlEngine::setObjectOwnership(m_voucherSubHeadsTableModel.get(),QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(m_voucherHeadsTableModel.get(),QQmlEngine::CppOwnership);

    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::toTableDelete,this,&VoucherProxy::proxyDelete);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel:: toFailedUpdate,this,&VoucherProxy::proxyUpdate);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::toProxyDialog,this,&VoucherProxy::onProxyDialog);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::vouchToProxy,this,&VoucherProxy::onVouchToProxy);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::row_Signal,this,&VoucherProxy::from_Proxy);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::UpdateSuccessProxy,this,&VoucherProxy::updateQml);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::deletion_SuccessProxy,this,&VoucherProxy::deleteQml);
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::Insert_SuccessProxy,this,&VoucherProxy::insertQml);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::addSuccessInTable,this,&VoucherProxy::onAddSuccessInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::updateFailInTable,this,&VoucherProxy::onUpdateFailInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::updateSuccessInTable,this,&VoucherProxy::onUpdateSuccessInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::ListCountToProxy,this,&VoucherProxy::onListCountToProxy);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::sigToProxy,this,&VoucherProxy::onSigToProxy);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::serialErrorInTable,this,&VoucherProxy::onSerialErrorInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::voucherErrorInTable,this,&VoucherProxy::onVoucherErrorInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::removeSuccessInTable,this,&VoucherProxy::onRemoveSuccessInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::removeFailInTable,this,&VoucherProxy::onRemoveFailInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::addFailInTable,this,&VoucherProxy::onAddFailInTable);
    connect(m_voucherHeadsTableModel.get(),&VoucherHeadsTableModel::voucherNameErrorInTable,this,&VoucherProxy::onVoucherNameErrorInTable);
}

QString VoucherProxy::getSerialno() const
{
    return serialno;
}

void VoucherProxy::setSerialno(const QString &newSerialno)
{
    serialno = newSerialno;
}

QString VoucherProxy::getVouchername() const
{
    return vouchername;
}

void VoucherProxy::setVouchername(const QString &newVouchername)
{
    vouchername = newVouchername;
}

void VoucherProxy::clearProxy()
{
    m_voucherSubHeadsTableModel->clearTable();
}

void VoucherProxy::deleteToDb(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsTableModel->deleteToTable(vid,sid,sname);
}

void VoucherProxy::updateToDb(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsTableModel->updateToTable(vid,sid,sname);
}

void VoucherProxy::addToDb(QString vid, QString sid, QString sname)
{
    m_voucherSubHeadsTableModel->addToTable(vid,sid,sname);
    qDebug()<<"add TO Table called vadiraj";

}

void VoucherProxy::clickedVoucher()
{
    m_voucherSubHeadsTableModel->clickTable();
}

void VoucherProxy::addVoucherMainType(QString slno,QString v_id,QString v_name)
{
    m_voucherHeadsTableModel->addDetailsInTable(slno,v_id,v_name);
    qDebug()<<"AddDetails called";
}

void VoucherProxy::send_Voucher(QString voucherId)
{
    m_voucherSubHeadsTableModel->voucher_data(voucherId);
}
void VoucherProxy::set_data(int row)
{
    m_voucherSubHeadsTableModel->selectRow(row);
}
void VoucherProxy::from_Proxy(QString subid,QString name)
{
    qDebug()<<"emmiting from qml to SubTable Category";
    emit my_update(subid,name);
}
void VoucherProxy::toDataModel()
{
    qDebug()<<"Inside toDataModelFunction";
    m_voucherSubHeadsTableModel->toTableModel();
    connect(m_voucherSubHeadsTableModel.get(),&VoucherSubHeadsTableModel::toMyProxy,this,&VoucherProxy::toMyQml);
}

void VoucherProxy::toMyQml(QString subcat, QString subname, QString voucherId)
{
    emit use_Data(subcat,subname,voucherId);
}

void VoucherProxy::onProxyDialog()
{
    emit qmlDialog();
}

void VoucherProxy::onSigToProxy()
{
    qDebug()<<"Sig came to proxy";
    emit sigToQml();
}
void VoucherProxy::onAddSuccessInTable()
{
    qDebug()<<"success in Proxy";
    emit addSucsessInProxy();
}

void VoucherProxy::onUpdateFailInTable()
{
    emit updateFailInProxy();
}

void VoucherProxy::onUpdateSuccessInTable()
{
    emit updateSuccessInProxy();
}

void VoucherProxy::onListCountToProxy(int a_listCount)
{
    emit listCountToQml(a_listCount+1);
}

void VoucherProxy::onSerialErrorInTable()
{
    emit serialErrorInProxy();
}

void VoucherProxy::onVoucherErrorInTable()
{
    emit voucherErrorInProxy();
}

void VoucherProxy::onRemoveSuccessInTable()
{
    emit removeSuccessInProxy();
}

void VoucherProxy::onRemoveFailInTable()
{
    emit removeFailInProxy();
}

void VoucherProxy::loadTbViewInProxy()
{
    m_voucherHeadsTableModel->loadTbViewInTable();
}

void VoucherProxy::rowClickedInProxy(int row)
{
    qDebug()<<"Row clicked in proxy";
    m_voucherHeadsTableModel->rowClicked(row);
}

void VoucherProxy::onAddFailInTable()
{
    qDebug()<<"On add failed called in proxy";
    emit addFailInProxy();
}

void VoucherProxy::onVoucherNameErrorInTable()
{
    emit voucherNameErrorInProxy();
}

void VoucherProxy::updateVoucherInProxy(QString a_slno, QString a_vid, QString a_vname)
{
    m_voucherHeadsTableModel->updateDetailsIntable(a_slno,a_vid,a_vname);
}

void VoucherProxy::onVouchToProxy(QString a_voucherId,QString serial_no,QString vouch_name)
{
    qDebug()<<"Voucher Id in proxy="<<a_voucherId;
    serialno=serial_no;
    vouchername=vouch_name;
    emit vouchToQml(serial_no,a_voucherId,vouch_name);
}

void VoucherProxy::removeVoucherInProxy(QString a_voucherid)
{
    m_voucherHeadsTableModel->removeDetailsIntable(a_voucherid);
}

VoucherHeadsTableModel*VoucherProxy::voucherHeadsTableModel() const
{
    return m_voucherHeadsTableModel.get();
}

void VoucherProxy::setVoucherHeadsTableModel(std::unique_ptr<VoucherHeadsTableModel> newVoucherHeadsTableModel)
{
    m_voucherHeadsTableModel = std::move(newVoucherHeadsTableModel);
}

VoucherSubHeadsTableModel*VoucherProxy::voucherSubHeadsTableModel() const
{
    return m_voucherSubHeadsTableModel.get();
}

void VoucherProxy::setVoucherSubHeadsTableModel(std::unique_ptr<VoucherSubHeadsTableModel> newVoucherSubHeadsTableModel)
{
    m_voucherSubHeadsTableModel = std::move(newVoucherSubHeadsTableModel);
}




