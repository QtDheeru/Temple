#include "model/BankRegistration_m/chequeentrydb.h"

ChequeEntryDB::ChequeEntryDB(QObject *parent)
    : QObject{parent}
{

    m_sqlDatabase2= QSqlDatabase::addDatabase("QSQLITE");
    QString path=QDir::currentPath();
    qDebug()<<path<<Qt::endl;
    m_sqlDatabase2.setDatabaseName(path+"/Bankdata.db");
    m_sqlquery2=new QSqlQuery;
    if(m_sqlDatabase2.open()){
        qDebug()<<"Database opened 1";
    }
    else {
        qDebug()<<"Database not opened 1";
    }
    m_sqlquery2->prepare("CREATE TABLE CHEQUE_DATA(RECEIPT_DATE VARCHAR[10],CHEQUE_DATE VARCHAR[10],BANK_NAME VARCHAR[15],RECEIPT_NUMBER VARCHAR[15],AMOUNT VARCHAR[10])");
   if(m_sqlquery2->exec()){
        qDebug()<<"Table created 1";
    }
    else{
        qDebug()<<"Table not created 2"<<m_sqlDatabase2.lastError();
   }
}

//void ChequeEntryDB::addTOdatabase(QString db_receiptDate, QString db_chequeDate, QString db_bankName, QString db_recepitNumber, QString db_amount)
//{
//    qDebug()<<"The receieved data";
//    qDebug()<<db_receiptDate<<" "<<db_chequeDate<<" "<<db_bankName<<" "<<db_recepitNumber<<" "<<db_amount;
//    QSqlQuery *s = new QSqlQuery;
//    s->prepare("INSERT INTO CHEQUE_DATA(RECEIPT_DATE ,CHEQUE_DATE ,BANK_NAME ,RECEIPT_NUMBER ,AMOUNT) VALUES(:receiptDate,:chequeDate,:bankName,:receiptNumber,:amount)");
//    s->bindValue(":receiptDate",db_receiptDate);
//    s->bindValue(":chequeDate",db_chequeDate);
//    s->bindValue(":bankName",db_bankName);
//    s->bindValue(":receiptNumber",db_recepitNumber);
//    s->bindValue(":amount",db_amount);

//    if(s->exec()){
//        qDebug()<<"query executed";
//    }
//    else{
//        qDebug()<<"insert query not executed"<<m_sqlquery2->lastError()<<Qt::endl;

//    }

//}
