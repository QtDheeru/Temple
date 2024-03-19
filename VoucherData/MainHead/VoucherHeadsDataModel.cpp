#include "VoucherHeadsDataModel.h"

VoucherHeadsDataModel::VoucherHeadsDataModel(QObject *parent)
    : QObject{parent}
{
    qDebug()<<"Data model constructor called";
}

const QHash<int, QByteArray> &VoucherHeadsDataModel::roles()
{
    QHash<int, QByteArray> roles;
    m_roles[0] = "serial";
    m_roles[1] = "vid";
    m_roles[2] = "vcategory";
    qDebug() << Q_FUNC_INFO << " Roles are created .." << roles;
    return m_roles;
}

QVariant VoucherHeadsDataModel::data(int row, int col, int role)
{
    qDebug() << Q_FUNC_INFO << " VoucherHeadsDataModel. Row="<<row <<Qt::endl;
    std::shared_ptr<VoucherHeadsTypeDetails> mainHead = this->m_voucherHeadList.at(row);

    switch(role) {
    case serialNumber : return mainHead->serialNo();break;
    case voucherID : return mainHead->vouchId();break;
    case VoucherName : return mainHead->vCategory();break;
    }
    return QVariant("Empty");
}

void VoucherHeadsDataModel::init()
{
    qDebug() << "init function called";
    connect(DBInterface::init,&DBInterface::selectSignalFromDB,this,&VoucherHeadsDataModel::onSelectSignalFromDB,Qt::UniqueConnection);
    DBInterface::init->selectDataInMain();
}

void VoucherHeadsDataModel::callRowInDataModel(int row_number)
{
    qDebug() << "rowNum in string = " << row_number;
    int num = row_number;
    if(m_voucherHeadList.empty()){
        qWarning() << Q_FUNC_INFO << "Voucher head list is empty!!! "<< endl;
        return;
    }

    QString mainSerial = m_voucherHeadList.at(num)->serialNo();
    QString mainVouchId = m_voucherHeadList.at(num)->vouchId();
    QString mainVouchName = m_voucherHeadList.at(num)->vCategory();
    qDebug() << "VoucherId = " << mainVouchId;
    qDebug() << "serialId = " << mainSerial;
    qDebug() << "Voucher name = " << mainVouchName;
    emit vouchToTableModel(mainVouchId,mainSerial,mainVouchName);
}

void VoucherHeadsDataModel::updateDetails(QString a_serial, QString a_voucherId, QString a_voucherName)
{
    connect(DBInterface::init,&DBInterface::updateSuccessInDB,this,&VoucherHeadsDataModel::onUpdateSuccessInDB,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::updateFailedInDB,this,&VoucherHeadsDataModel::onUpdateFailInDB,Qt::UniqueConnection);
    DBInterface::init->updateData(a_serial,a_voucherId,a_voucherName);
    qDebug()<<"Update called in DataModel";
}

void VoucherHeadsDataModel::removeDetails(QString a_voucherId)
{
    qDebug()<<"Remove called in DataModel";
    connect(DBInterface::init,&DBInterface::deletionSuccessInDB,this,&VoucherHeadsDataModel::onDeletionSuccessInDB,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::deletionFailedInDB,this,&VoucherHeadsDataModel::onDeletionFailInDB,Qt::UniqueConnection);;
    DBInterface::init->removeData(a_voucherId);
}

void VoucherHeadsDataModel::loadTbViewInData()
{
    this->init();
}

void VoucherHeadsDataModel::addDetails(QString slno,QString v_id,QString v_name)
{
    if((slno==""&&v_id==""&&v_name=="")||(slno==""||v_id==""||v_name=="")){
        emit sigEmpty();
        return;
    }
    for(int i=0;i<m_voucherHeadList.count();i++){
        if(slno==m_voucherHeadList[i]->serialNo()){
            emit serialError();
            return;
        }
        else if(v_id==m_voucherHeadList[i]->vouchId()){
            emit voucherError();
            return;
        }
        else if((v_name.compare(m_voucherHeadList[i]->vCategory(),Qt::CaseInsensitive))==0){
            if((v_name.compare(m_voucherHeadList[i]->vCategory(),Qt::CaseSensitive))!=0){
                emit voucherNameError();
                return;
            }
            emit voucherNameError();
            return;
        }
    }
    //    Called db addfunction
    connect(DBInterface::init,&DBInterface::addSuccessInDB,this,&VoucherHeadsDataModel::onSelectSignalFromDB,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::addFailInDB,this,&VoucherHeadsDataModel::onAddFailInDB,Qt::UniqueConnection);
    DBInterface::init->addData(slno,v_id,v_name);
    qDebug()<<"AddDetails called in heads model";
}

int VoucherHeadsDataModel::size()
{
    return m_voucherHeadList.size();
}

void VoucherHeadsDataModel::onSelectSignalFromDB(QString serl_no,QString vid,QString vcat)
{
    qDebug()<<"came to OnSelectsignal";
    int flag1=0;
    int flag2=0;

    for(int i=0;i<m_voucherHeadList.count();i++){
        if(serl_no==m_voucherHeadList[i]->serialNo())
            flag1=1;
        else if(vid==m_voucherHeadList[i]->vouchId())
            flag2=1;
    }
    if(flag1==0 && flag2==0){
        std::shared_ptr<VoucherHeadsTypeDetails> subHead(new VoucherHeadsTypeDetails);
        subHead->setSerialNo(serl_no);
        subHead->setVouchId(vid);
        subHead->setVCategory(vcat);
        qDebug()<<"serd="<<serl_no<<"voucd="<<vid<<"Named="<<vcat<<endl;
        m_voucherHeadList.append(subHead);
        emit addSuccessInData();
        emit addTableModel(m_voucherHeadList.size(),m_voucherHeadList.size());
        emit listCount(m_voucherHeadList.count());
    }
}

void VoucherHeadsDataModel::onUpdateSuccessInDB(QString a_serial, QString a_voucherId, QString a_voucherName)
{
    qDebug()<<"Called update slot";
    for(int i=0;i<m_voucherHeadList.count();i++){
        if(m_voucherHeadList[i]->vouchId()==a_voucherId){
            //Called db updatefunction
            m_voucherHeadList[i]->setSerialNo(a_serial);
            m_voucherHeadList[i]->setVouchId(a_voucherId);
            m_voucherHeadList[i]->setVCategory(a_voucherName);
            emit updateToTableModel(i);
            emit updateSuccessInData();
            break;
        }
    }
}

void VoucherHeadsDataModel::onDeletionSuccessInDB(QString a_voucherId)
{
    qDebug()<<"Called Deletion slot";
    int i;
    for(i=0;i<m_voucherHeadList.count();i++){
        if(m_voucherHeadList[i]->vouchId()==a_voucherId){
            m_voucherHeadList.removeAt(i);
            emit removeToTableModel(i);
            emit listCount(m_voucherHeadList.count());
            emit removeSuccessInData();
            break;
        }
    }
    qDebug()<<"Removed at row="<<i;
}

void VoucherHeadsDataModel::onUpdateFailInDB()
{
    emit updateFailInData();
}

void VoucherHeadsDataModel::onDeletionFailInDB()
{
    emit removeFailInData();
}

void VoucherHeadsDataModel::onAddFailInDB()
{
    qDebug()<<"On add failed called";
    emit addFailInData();
}
