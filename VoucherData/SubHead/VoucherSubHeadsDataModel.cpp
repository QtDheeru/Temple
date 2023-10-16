#include "VoucherSubHeadsDataModel.h"
#include<QDebug>
#include<QString>

VoucherSubHeadsDataModel::VoucherSubHeadsDataModel(QObject *parent)
    : QObject{parent}
{

    qDebug()<<"Hello There Inside VoucherSubHeadsData Model";

}

void VoucherSubHeadsDataModel::clearModel()
{
    m_table2Data.clear();
    qDebug()<<Q_FUNC_INFO<<"cLEARED tABLE2DATA"<<m_table2Data.length();
}

void VoucherSubHeadsDataModel::updateToModel(QString vid, QString sid, QString sname)
{
    connect(DBInterface::init,&DBInterface::update_Success,this,&VoucherSubHeadsDataModel::onUpdated_List,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::update_Success,this,&VoucherSubHeadsDataModel::onUpdated_Success,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::update_Failed,this,&VoucherSubHeadsDataModel::onUpdated_Failed,Qt::UniqueConnection);
    DBInterface::init->updateToDb(vid,sid,sname);

}

void VoucherSubHeadsDataModel::deleteToModel(QString vid, QString sid, QString sname)
{
    connect(DBInterface::init,&DBInterface::deletion_Success,this,&VoucherSubHeadsDataModel::onDeletion_item,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::deletion_Success,this,&VoucherSubHeadsDataModel::onDeletion_Success,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::deletion_Failed,this,&VoucherSubHeadsDataModel::onDeletion_Failed,Qt::UniqueConnection);
    DBInterface::init->deleteData(vid,sid,sname);


}

void VoucherSubHeadsDataModel::myInit()
{
    qDebug()<<Q_FUNC_INFO;
    connect(DBInterface::init,&DBInterface::mySelectSignalAll,this,&VoucherSubHeadsDataModel::onSelectAll,Qt::UniqueConnection);
    m_tableAllData.clear();
    DBInterface::init->selectDataAll(voucherId);
}

void VoucherSubHeadsDataModel::listAppendDataModel()
{
    QString subid,subname,vid;
    cout<<"Inside AppendDataModel function";
    int flag=0;
    int j=0;

    qDebug()<<"Size of List m_tableAllData.count() "<<m_tableAllData.count();
    for(int i=0; i <m_tableAllData.count();i++)
    {
        qDebug()<<"i ="<<i;
        if((m_tableAllData[i]->getVoucher() == voucherId) )
        {
            flag=1;
            VoucherSubHead *m_table = new VoucherSubHead;
            subid = m_tableAllData[i]->getVSubid();
            subname = m_tableAllData[i]->getVscn();
            vid = m_tableAllData[i]->getVoucher();
            qDebug()<<"subid in list append function hii"<<subid;
            qDebug()<<"Subname in list append function hii"<<subname;
            qDebug()<<"vname list append function "<<vid;
            m_table->setVSubid(subid);
            m_table->setVscn(subname);
            m_table->setVoucher(vid);
            m_table2Data.append(m_table);
            emit addToTableModel(m_table2Data.size(),m_table2Data.size());
            qDebug()<<"after click table2data():"<<m_table2Data.at(j)->getVscn();

            qDebug()<<"voucher Id in list m_tableAllData in clickModel "<<m_tableAllData[i]->getVoucher();
            j++;

        }


    }
    if(flag == 0)
    {
        VoucherSubHead *m_table = new VoucherSubHead;
        QString subid="";
        QString subname="";
        m_table->setVSubid(subid);
        m_table->setVscn(subname);
        m_table2Data.append(m_table);
        emit addToTableModel(m_table2Data.size(),m_table2Data.size());
    }

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

void VoucherSubHeadsDataModel::onModelDialog()
{
    emit toTableDialog();
}

void VoucherSubHeadsDataModel::onSelectAll(QString vid, QString sid, QString sname)
{

    qDebug("Inside onMySelectSignal SUBHEADMODEL");
    qDebug()<<m_tableAllData.length()<<"LENGTHHHHHHHHHHHHHHHHHHHHHHHH";

    VoucherSubHead *m_table = new VoucherSubHead;
    m_table->setVSubid(sid);
    m_table->setVscn(sname);
    m_table->setVoucher(vid);
    qDebug()<<"m_tableAllData.count() = "<<m_tableAllData.count();

    if(sid != "" && sname != "")
    {
        m_tableAllData.append(m_table);
    }

    if(voucherId == vid)
    {
        qDebug()<<"voucherId"<<voucherId;
        m_table2Data.append(m_table);
        emit addToTableModel(m_table2Data.size(),m_table2Data.size());
    }

    qDebug()<<"Inside the m_table subid is"<<m_table->getVSubid();
    qDebug()<<"Inside the m_table subname is"<<m_table->getVscn();
    qDebug()<<"Creating the tavle2_Data List";
    qDebug()<<"table2Data.size() count"<<m_table2Data.count();


}

void VoucherSubHeadsDataModel::onAddToList(QString vid, QString sid, QString sname)
{
    VoucherSubHead *m_table = new VoucherSubHead;
    m_table->setVoucher(vid);
    m_table->setVSubid(sid);
    m_table->setVscn(sname);
    m_tableAllData.append(m_table);

    if((m_table2Data.count() == 1) && m_table2Data.at(0)->getVscn() == "")
    {
        emit ResetMList();
        m_table2Data.append(m_table);
        emit addToTableModel(m_table2Data.size(),m_table2Data.size());
    }
    else
    {
        m_table2Data.append(m_table);
        emit addToTableModel(m_table2Data.size(),m_table2Data.size());
    }


}

void VoucherSubHeadsDataModel::onUpdated_List(QString vid, QString sid, QString sname)
{
    qDebug()<<"Inside onUpdated_List";
    for(int i=0; i<m_tableAllData.count(); i++)
    {
        if((m_tableAllData[i]->getVoucher() == vid) && (m_tableAllData[i]->getVSubid() == sid))
        {
            m_tableAllData[i]->setVscn(sname);

        }

    }

    for(int j=0; j<m_table2Data.count();j++)
    {
        if((m_table2Data[j]->getVoucher() == vid) && (m_table2Data[j]->getVSubid() == sid))
        {
            m_table2Data[j]->setVscn(sname);
            emit updateToSubTableModel(j);

        }

    }

}

void VoucherSubHeadsDataModel::onDeletion_item(QString vid, QString sid, QString sname)
{
    qDebug()<<"IUpond deleting item";
    for(int i=0; i<m_tableAllData.count(); i++)
    {
        if((m_tableAllData[i]->getVoucher() == vid) && (m_tableAllData[i]->getVSubid() == sid))
        {
            m_tableAllData.removeAt(i);

        }

    }

    for(int j=0; j<m_table2Data.count();j++)
    {
        if((m_table2Data[j]->getVoucher() == vid) && (m_table2Data[j]->getVSubid() == sid))
        {
            m_table2Data.removeAt(j);
            emit removeToSubTableModel(j);

        }

    }

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
    connect(DBInterface::init,&DBInterface::insert_Success,this,&VoucherSubHeadsDataModel::onAddToList,Qt::UniqueConnection);
    connect(DBInterface::init,&DBInterface::insert_Success,this,&VoucherSubHeadsDataModel::onInsert_Success,Qt::UniqueConnection);

    DBInterface::init->addMyDB(vid,sid,sname);

}









