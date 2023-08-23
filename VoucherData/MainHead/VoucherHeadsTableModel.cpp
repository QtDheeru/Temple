#include "VoucherHeadsTableModel.h"

VoucherHeadsTableModel::VoucherHeadsTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_voucherHeadsDataModel = std::make_unique<VoucherHeadsDataModel>();
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::addTableModel,this,&VoucherHeadsTableModel::onAddTableModel);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::vouchToTableModel,this,&VoucherHeadsTableModel::callVouchToTableModel);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::updateToTableModel,this,&VoucherHeadsTableModel::onUpdateToTableModel);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::removeToTableModel,this,&VoucherHeadsTableModel::onRemoveToTableModel);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::sigEmpty,this,&VoucherHeadsTableModel::onSigEmpty);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::serialError,this,&VoucherHeadsTableModel::onSerialError);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::voucherError,this,&VoucherHeadsTableModel::onVoucherError);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::addSuccessInData,this,&VoucherHeadsTableModel::onAddSuccessInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::updateFailInData,this,&VoucherHeadsTableModel::onUpdateFailInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::updateSuccessInData,this,&VoucherHeadsTableModel::onUpdateSuccessInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::removeSuccessInData,this,&VoucherHeadsTableModel::onRemoveSuccessInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::listCount,this,&VoucherHeadsTableModel::onListCount);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::removeFailInData,this,&VoucherHeadsTableModel::onRemoveFailInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::addFailInData,this,&VoucherHeadsTableModel::onAddFailInData);
    connect(m_voucherHeadsDataModel.get(),&VoucherHeadsDataModel::voucherNameError,this,&VoucherHeadsTableModel::onVoucherNameError);
    m_voucherHeadsDataModel->init();
    qDebug()<<"connect called";
}

VoucherHeadsTableModel::~VoucherHeadsTableModel(){}

int VoucherHeadsTableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_voucherHeadsDataModel->size();
}

int VoucherHeadsTableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_voucherHeadsDataModel->size();
}

QHash<int, QByteArray> VoucherHeadsTableModel::roleNames() const {
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_voucherHeadsDataModel->roles();
}

void VoucherHeadsTableModel::addDetailsInTable(QString slno, QString vid, QString vname)
{
    qDebug()<<"TSerial="<<slno;
    qDebug()<<"Tvid="<<vid;
    qDebug()<<"Tvname="<<vname;
    m_voucherHeadsDataModel->addDetails(slno,vid,vname);
    qDebug()<<"add called in Table model";
}

void VoucherHeadsTableModel::updateDetailsIntable(QString a_slno, QString a_vid, QString a_vname)
{
    m_voucherHeadsDataModel->updateDetails(a_slno,a_vid,a_vname);
}

void VoucherHeadsTableModel::removeDetailsIntable(QString a_vid)
{
    m_voucherHeadsDataModel->removeDetails(a_vid);
}

void VoucherHeadsTableModel::loadTbViewInTable()
{
    m_voucherHeadsDataModel->loadTbViewInData();
}

void VoucherHeadsTableModel::onAddTableModel(int first,int last)
{
    qDebug()<<"Called Insert Rows";
    beginInsertRows(QModelIndex(),first-1,last-1);
    endInsertRows();
}

void VoucherHeadsTableModel::rowClicked(int row)
{
    qDebug()<<"Row clicked in table="<<row;
    m_voucherHeadsDataModel->callRowInDataModel(row);
}

void VoucherHeadsTableModel::callVouchToTableModel(QString vouchid,QString serial_no,QString vouch_name)
{
    qDebug()<<"VouchId in Table model="<<vouchid;
    emit vouchToProxy(vouchid,serial_no,vouch_name);
}

void VoucherHeadsTableModel::onUpdateToTableModel(int a_position)
{
    QModelIndex l_left=createIndex(a_position,0);
    emit dataChanged(l_left,l_left);
}

void VoucherHeadsTableModel::onRemoveToTableModel(int a_position)
{
    beginRemoveRows(QModelIndex(),a_position,a_position);
    endRemoveRows();
}

void VoucherHeadsTableModel::onSigEmpty()
{
    emit sigToProxy();
}

void VoucherHeadsTableModel::onSerialError()
{
    emit serialErrorInTable();
}

void VoucherHeadsTableModel::onVoucherError()
{
    emit voucherErrorInTable();
}

void VoucherHeadsTableModel::onAddSuccessInData()
{
    emit addSuccessInTable();
}

void VoucherHeadsTableModel::onUpdateFailInData()
{
    emit updateFailInTable();
}

void VoucherHeadsTableModel::onUpdateSuccessInData()
{
    emit updateSuccessInTable();
}

void VoucherHeadsTableModel::onRemoveSuccessInData()
{
    emit removeSuccessInTable();
}

void VoucherHeadsTableModel::onRemoveFailInData()
{
    emit removeFailInTable();
}

void VoucherHeadsTableModel::onAddFailInData()
{
    qDebug()<<"On add failed called in Table";
    emit addFailInTable();
}

void VoucherHeadsTableModel::onVoucherNameError()
{
    emit voucherNameErrorInTable();
}

void VoucherHeadsTableModel::onListCount(int a_listCount)
{
    emit ListCountToProxy(a_listCount);
}

QVariant VoucherHeadsTableModel::data(const QModelIndex &index, int role) const {
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_voucherHeadsDataModel->data(index.row(),index.column(),role);
}




