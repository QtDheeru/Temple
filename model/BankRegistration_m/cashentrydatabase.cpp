#include "cashentrydatabase.h"

CashEntryDataBase::CashEntryDataBase(QObject *parent)
    : QObject{parent}
{

    m_sqlDatabase= QSqlDatabase::addDatabase("QSQLITE");
    QString path=QDir::currentPath();
    qDebug()<<path<<Qt::endl;
    m_sqlDatabase.setDatabaseName(path+"/Bankdata.db");
    if(m_sqlDatabase.open()){
        qDebug()<<"Database opened";
    }
    else {
        qDebug()<<"Database not opened";
    }
    m_sqlquery=new QSqlQuery;
    m_sqlquery->prepare("CREATE TABLE BANK(DATE VARCHAR[10],LAST_RECEIPT VARCHAR[10],CASH_IN_HAND VARCHAR[15],TO_BANK VARCHAR[15],TRANSACTION_TYPE VARCHAR[10],BANK_NAME VARCHAR[15],PERSON VARCHAR[20],STATUS VARCHAR[20],NOTES VARCHAR[30])");
    if(m_sqlquery->exec()){
        qDebug()<<"Table created";
    }
    else{
        qDebug()<<"Table not created"<<m_sqlDatabase.lastError();
    }

}

void CashEntryDataBase::addTOdatabase(QString a_date, QString a_lastreci, QString a_cashinhand, QString a_tobank, QString a_transType, QString a_bank, QString a_person, QString a_status, QString a_notes)
{
    qDebug()<<"The receieved data"<<Qt::endl;

    if(a_tobank!=""){
        QSqlQuery *m_sqlquery = new QSqlQuery;
        m_sqlquery->prepare("INSERT INTO BANK(DATE ,LAST_RECEIPT ,CASH_IN_HAND ,TO_BANK ,TRANSACTION_TYPE ,BANK_NAME ,PERSON ,STATUS ,NOTES) VALUES(:date,:lastreci,:cashinhand,:tobank,:transtype,:bank,:person,:status,:notes)");
        m_sqlquery->bindValue(":date",a_date);
        m_sqlquery->bindValue(":lastreci",a_lastreci);
        m_sqlquery->bindValue(":cashinhand",a_cashinhand);
        m_sqlquery->bindValue(":tobank",a_tobank);
        m_sqlquery->bindValue(":transtype",a_transType);
        m_sqlquery->bindValue(":bank",a_bank);
        m_sqlquery->bindValue(":person",a_person);
        m_sqlquery->bindValue(":status",a_status);
        m_sqlquery->bindValue(":notes",a_notes);
        if(m_sqlquery->exec()){
            qDebug()<<"query executed";
        }
    }
}
