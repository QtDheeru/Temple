#include "vouchersubheaddatabase.h"
#include<QSqlError>

VoucherSubheadDatabase::VoucherSubheadDatabase(QObject *parent)
    : QObject{parent}
{

    Mydbase=QSqlDatabase::addDatabase("QSQLITE");
    QString currentpath=QDir::currentPath();
    qDebug()<<"Current Path"<<currentpath<<Qt::endl;
    Mydbase.setDatabaseName(currentpath+"/voucherHead.db");
    if(Mydbase.open())
        qDebug()<<"Database opened in Subheads";
    else
        qDebug()<<"Database not opened in Subheads";

    Myquery=new QSqlQuery();

    Myquery->prepare("CREATE TABLE SUBVOUCHER_DATA(VOUCHERID VARCHAR(5),SUBCATEGORY_ID VARCHAR(20),SUBCATEGORY_NAME VARCHAR(20),PRIMARY KEY(SUBCATEGORY_ID));");
    if(Myquery->exec()){
        qDebug()<<"Query executed in SUBHEAD"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Query exe..failed IN CONSTRUCTOR DB"<<Qt::endl;
    }

}


void VoucherSubheadDatabase::addMyDB(QString vid, QString sid, QString sname)
{
    qDebug()<<Q_FUNC_INFO;

    qDebug()<<"vid = "<<vid;
    qDebug()<<"sid = "<<sid;
    qDebug()<<"sname="<<sname;
    QSqlQuery *Myquery=new QSqlQuery;

    Myquery->prepare("INSERT INTO SUBVOUCHER_DATA(VOUCHERID,SUBCATEGORY_ID,SUBCATEGORY_NAME) VALUES(:vid,:sid,:sname)");

    Myquery->bindValue(":vid",vid);
    Myquery->bindValue(":sid",sid);
    Myquery->bindValue(":sname",sname);
    if(Myquery->exec())
    {
        qDebug()<<"InseIrt Query executed In SubHeadsDataBase"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Insert Query exe..failed in addMyDB SubHeads"<<Qt::endl;
        emit toModelDialog();

    }

}

void VoucherSubheadDatabase::selectData(QString VOUCHERID)
{
    bool value=false;
    QSqlQuery *Myquery=new QSqlQuery;
    qDebug()<<"Select Data Called";
    Myquery->prepare("SELECT VOUCHERID,SUBCATEGORY_ID,SUBCATEGORY_NAME FROM SUBVOUCHER_DATA ");
    if(Myquery->exec()){
        qDebug()<<"Retrieve Query executed in Subhead"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Retrieve Query exe..failed in Subhead"<<Qt::endl;

    }
    qDebug()<<"VOUCHER IS IN SELECTDATA"<<VOUCHERID;

    qDebug()<<"VOUCHER IS IN SELECTDATA"<<VOUCHERID;

    while(Myquery->next())
    {
        QString voucherID=Myquery->value(0).toString();
        if(VOUCHERID == voucherID)
        {
            value=true;
            qDebug("Inside selectData of VoucherSubheadDatabase");
            QString subID=Myquery->value(1).toString();
            QString subName=Myquery->value(2).toString();
            qDebug()<<"SUBID IN selectData()"+subID;
            qDebug()<<"SUBNAME IN selectData()"+subName;
            emit mySelectSignal(voucherID,subID,subName);

        }

    }
    if(!value)
    {
        emit mySelectSignal("Data not found","","");
    }

}

void VoucherSubheadDatabase::updateToDb(QString vid, QString sid, QString sname)
{
    QSqlQuery *Myquery=new QSqlQuery;
    Myquery->prepare("UPDATE SUBVOUCHER_DATA SET SUBCATEGORY_NAME=:sname WHERE VOUCHERID=:vid AND SUBCATEGORY_ID=:sid ");
    Myquery->bindValue(":sid",sid);
    Myquery->bindValue(":sname",sname);
    Myquery->bindValue(":vid",vid);

    if(Myquery->exec())
    {
        qDebug()<<"Update Query executed in Subhead"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Update Query exe..failed in Subhead"<<Myquery->lastError()<<Qt::endl;

    }
    qDebug()<<"number of Rows affected"<<Myquery->numRowsAffected();

    if(!(Myquery->numRowsAffected()))
    {
        emit update_Failed();

    }

}
void VoucherSubheadDatabase::deleteData(QString vid,QString sid,QString sname)
{
    QSqlQuery *Myquery=new QSqlQuery;
    qDebug()<<"vid in deleteData"<<vid;
    qDebug()<<"sid in deleteData"<<sid;
    qDebug()<<"sname in deleteData"<<sname;

    qDebug()<<"Remove Data Called in SubheadDatabase";
    Myquery->prepare("DELETE FROM SUBVOUCHER_DATA WHERE VOUCHERID=:vid AND SUBCATEGORY_ID=:sid ");
    Myquery->bindValue(":vid",vid);
    Myquery->bindValue(":sid",sid);

    if(Myquery->exec())
    {
        qDebug()<<"Remove Query executed in deleteData"<<Qt::endl;
    }
    else{
        qDebug()<<"Remove Query exe..failed deleteData"<<Qt::endl;
    }

    if(!(Myquery->numRowsAffected()))
    {
        emit deletion_Failed();

    }


}
