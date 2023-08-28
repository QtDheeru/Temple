#include "VoucherSubHeadsDataModel.h"
#include<QDebug>
#include<QString>

VoucherSubHeadsDataModel::VoucherSubHeadsDataModel(QObject *parent)
    : QObject{parent}
{

    qDebug()<<"Hello There Inside VoucherSubHeadsData Model";

}

void VoucherSubHeadsDataModel::init()
{
    qDebug()<<"Voucher Subheads data model init called"<<voucherId;
    if(voucherId != "")
    {

        qDebug()<<"Inside if Voucher Subheads data model init called"<<voucherId;
        DBInterface::init->selectData(voucherId);
    }
}

void VoucherSubHeadsDataModel::clickModel()
{
    qDebug()<<"VOUCHER ID OF CPP IS"<<voucherId;
    if(voucherId != "")
    {

        qDebug()<<"VOUCHER ID IN clickModel() is"<<voucherId;
        connect(DBInterface::init,&DBInterface::mySelectSignal,this,&VoucherSubHeadsDataModel::onMySelectSignal,Qt::UniqueConnection);

        DBInterface::init->selectData(voucherId);
    }
}

void VoucherSubHeadsDataModel::clearModel()
{
    m_table2Data.clear();
    qDebug()<<Q_FUNC_INFO<<"cLEARED tABLE2DATA"<<m_table2Data.length();
}

void VoucherSubHeadsDataModel::updateToModel(QString vid, QString sid, QString sname)
{
    connect(DBInterface::init,&DBInterface::update_Success,this,&VoucherSubHeadsDataModel::onUpdated_Success,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::update_Failed,this,&VoucherSubHeadsDataModel::onUpdated_Failed,Qt::UniqueConnection);
    DBInterface::init->updateToDb(vid,sid,sname);
    DBInterface::init->selectData(voucherId);
}

void VoucherSubHeadsDataModel::deleteToModel(QString vid, QString sid, QString sname)
{
    connect(DBInterface::init,&DBInterface::deletion_Success,this,&VoucherSubHeadsDataModel::onDeletion_Success,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::deletion_Failed,this,&VoucherSubHeadsDataModel::onDeletion_Failed,Qt::UniqueConnection);
    DBInterface::init->deleteData(vid,sid,sname);
    DBInterface::init->selectData(voucherId);

}

QString VoucherSubHeadsDataModel::getSub_name() const
{
    return sub_name;
}

void VoucherSubHeadsDataModel::setSub_name(const QString &newSub_name)
{
    sub_name = newSub_name;
}

QString VoucherSubHeadsDataModel::getSub_cat_id() const
{
    return sub_cat_id;
}

void VoucherSubHeadsDataModel::setSub_cat_id(const QString &newSub_cat_id)
{
    sub_cat_id = newSub_cat_id;
}


int VoucherSubHeadsDataModel::my_rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO;
    return m_table2Data.count();

}

int VoucherSubHeadsDataModel::my_columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO;
    return m_table2Data.count();

}

QVariant VoucherSubHeadsDataModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<" indexValInTBM "<<index.row()<<role;

    if(role == 0 )
    {
        qDebug()<<"inside myt data"<<m_table2Data.at(index.row())->getVSubid();
        return m_table2Data.at(index.row())->getVSubid();//table->getVSubid();
    }
    if(role == 1)
    {
        qDebug()<<"inside data"<<table->getVSubid();
        return m_table2Data.at(index.row())->getVscn();
    }


}

QHash<int, QByteArray> VoucherSubHeadsDataModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO;
    QHash<int, QByteArray> roles;
    roles[0] = "Vsubid";
    roles[1] = "Vscn";

    qDebug()<<Q_FUNC_INFO<<" 2 " <<roles;
    return roles;

}

void VoucherSubHeadsDataModel:: set_MainId(QString my_voucher)
{
    voucherId=my_voucher;
    qDebug()<<"vadiraj voucherID is"<< voucherId;
}



void VoucherSubHeadsDataModel::onMySelectSignal(QString vid, QString sid, QString sname)
{

    qDebug("Inside onMySelectSignal SUBHEADMODEL");
    VoucherSubHead *m_table = new VoucherSubHead;
    m_table->setVSubid(sid);
    m_table->setVscn(sname);

    m_table2Data.append(m_table);
    qDebug()<<"Inside the m_table subid is"<<m_table->getVSubid();
    qDebug()<<"Inside the m_table subname is"<<m_table->getVscn();
    qDebug()<<"Creating the tavle2_Data List";
    emit addToTableModel(m_table2Data.size(),m_table2Data.size());

}

void VoucherSubHeadsDataModel::onModelDialog()
{
    emit toTableDialog();
}

void VoucherSubHeadsDataModel::set_data(int rid)
{
    int num=rid;
    QString subid=m_table2Data.at(num)->getVSubid();
    QString name=m_table2Data.at(num)->getVscn();

    sub_cat_id=subid;
    sub_name=name;
    qDebug()<<"sending updated data signal()";
    emit updated_data(subid,name);

}

void VoucherSubHeadsDataModel::getFromModel()
{
    qDebug()<<"Inside getFromModel function";
    emit  my_data( sub_cat_id,sub_name,voucherId);

}

void VoucherSubHeadsDataModel::addFromModel(QString vid, QString sid, QString sname)
{

    connect(DBInterface::init,&DBInterface::toModelDialog,this,&VoucherSubHeadsDataModel::onModelDialog,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::insert_Success,this,&VoucherSubHeadsDataModel::onInsert_Success,Qt::UniqueConnection);
    DBInterface::init->addMyDB(vid,sid,sname);
    DBInterface::init->selectData(voucherId);
}









