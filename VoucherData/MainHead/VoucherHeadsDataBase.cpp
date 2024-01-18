#include "VoucherHeadsDataBase.h"

VoucherHeadsDataBase::VoucherHeadsDataBase(QObject *parent)
    : QObject{parent}
{

}

void VoucherHeadsDataBase::init()
{
    dbase=QSqlDatabase::addDatabase("QSQLITE");
    QString currentpath=QDir::currentPath();
    qDebug()<<"Current Path"<<currentpath<<Qt::endl;
    dbase.setDatabaseName(currentpath+"/VoucherHead.db");
    if(dbase.open())
        qDebug()<<"Database opened";
    else
        qDebug()<<"Database not opened";

    query=new QSqlQuery();
    query->prepare("CREATE TABLE VOUCHER_DATA(SL_NO VARCHAR(5),VOUCHER_ID VARCHAR(20),VOUCHER_CATEGORY VARCHAR(20));");
    if(query->exec()){
        qDebug()<<"Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Query exe..failed"<<Qt::endl;
    }
}

void VoucherHeadsDataBase::addData(QString slno,QString vid,QString vname)
{
    qDebug()<<Q_FUNC_INFO;
    query->prepare("INSERT INTO VOUCHER_DATA(SL_NO,VOUCHER_ID,VOUCHER_CATEGORY) VALUES(:slno,:vid,:vname)");
    query->bindValue(":slno",slno);
    query->bindValue(":vid",vid);
    query->bindValue(":vname",vname);
    if(query->exec()){
        qDebug()<<"Insert Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Insert Query exe..failed"<<Qt::endl;
    }
}

void VoucherHeadsDataBase::updateData(QString slno,QString vid,QString vname)
{
    qDebug()<<Q_FUNC_INFO;
    query->prepare("UPDATE VOUCHER_DATA SET SL_NO=:slno,VOUCHER_CATEGORY=:vname WHERE VOUCHER_ID =:vid");
    query->bindValue(":slno",slno);
    query->bindValue(":vid",vid);
    query->bindValue(":vname",vname);
    if(query->exec()){
        qDebug()<<"Update Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Update Query exe..failed"<<Qt::endl;
    }
}

void VoucherHeadsDataBase::selectData()
{
    qDebug()<<"Select Data Called";
    query->prepare("SELECT SL_NO,VOUCHER_ID,VOUCHER_CATEGORY FROM VOUCHER_DATA");
    if(query->exec()){
        qDebug()<<"Retrieve Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Retrieve Query exe..failed"<<Qt::endl;
    }

    while(query->next()){
        QString serial_No=query->value(0).toString();
        QString vouch_Id=query->value(1).toString();
        QString vouch_Name=query->value(2).toString();
        emit selectSignal(serial_No,vouch_Id,vouch_Name);
    }
}

void VoucherHeadsDataBase::removeData(QString vid)
{
    qDebug()<<"Remove Data Called";
    query->prepare("DELETE FROM VOUCHER_DATA WHERE VOUCHER_ID=:vid");
    query->bindValue(":vid",vid);
    if(query->exec()){
        qDebug()<<"Remove Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Remove Query exe..failed"<<Qt::endl;
    }
}
