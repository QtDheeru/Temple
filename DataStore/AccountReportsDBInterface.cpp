#include "AccountReportsDBInterface.h"
#include <QSqlQuery>
#include "AccountReportElement.h"

AccountReportsDBInterface::AccountReportsDBInterface(QSqlDatabase db, QObject *parent)
    :QObject{parent}
    ,m_db(db)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

bool AccountReportsDBInterface::generateSingleDateReport(ReportFilterElements *elm)
{
    elm->print();
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    QString date2Query = elm->sSingleDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QString que1;
    QSqlQuery query_other1;
    qDebug() << Q_FUNC_INFO << "DB Query for SevaType ="<< seva_type_string << " Seva Code =" << seva_type_int <<  " Seva Name =" << seva_name << " Date =" << date2Query << Qt::endl;
    QList<QString> pay_mode={"cash","Cheque","NEFT","UPI"};

    if(seva_type_string.isEmpty()) {
        qDebug() << Q_FUNC_INFO << " Query all sevaTypes & Seva Names " << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' Group by SEVANAME,BANK;");
        que1 = que1.arg(date2Query);
    };
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0) {
        qDebug() << Q_FUNC_INFO << " This is ALL Seva Name Query for SevaType=" << seva_type_string << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity ,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(date2Query).arg(seva_type_int);
    };
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT) !=0) {
        qDebug() << Q_FUNC_INFO << " Seva Type & Seva Name is specified.." << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' and sevabooking.SEVATYPE LIKE '%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(date2Query).arg(seva_type_int).arg(seva_name);
    }

    qDebug() << Q_FUNC_INFO << " Single Date Query string =" << que1 << Qt::endl;
    query_other1.prepare(que1);

    query_other1.exec();

    while(query_other1.next()) {
        AccountReportElement *ele = new AccountReportElement;
        ele->setDate(date2Query);
        ele->setSevaType(seva_type_int);
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total

        if(query_other1.value("Tran_type").toString().compare(pay_mode[0],Qt::CaseInsensitive)==0){
            ele->setCash(query_other1.value("SEVATOTALPRICE").toFloat());
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[1],Qt::CaseInsensitive)==0){
            ele->setCheque(query_other1.value("SEVATOTALPRICE").toFloat());
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[2],Qt::CaseInsensitive)==0){
            ele->setNeft(query_other1.value("SEVATOTALPRICE").toFloat());
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[3],Qt::CaseInsensitive)==0){
            ele->setUpi(query_other1.value("SEVATOTALPRICE").toFloat());
        }
        ele->print();
        emit account_report(ele);
    }
    return true;
}

bool AccountReportsDBInterface::generateDateRangeReport(ReportFilterElements *elm)
{
    elm->print();
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    QString startDate2Query = elm->sSingleDate();
    QString endDate2Query = elm->sEndDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    qDebug() << Q_FUNC_INFO << "DB Query for SevaType ="<< seva_type_string << " Seva Code =" << seva_type_int <<  " Seva Name =" << seva_name << " Start-Date =" << startDate2Query << " End-Date =" << endDate2Query << Qt::endl;

    QSqlQuery query_other1;
    QString readstr;
    if(seva_type_string.isEmpty()) {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by sevabooking.SEVANAME;" );
        readstr = readstr.arg(startDate2Query,endDate2Query);
    }
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0)  {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; " );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int);
    }
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT) !=0) {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.SEVANAME;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int).arg(seva_name);
    }
    qDebug() << Q_FUNC_INFO << " Date Range Report Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();

    while(query_other1.next())
    {
        AccountReportElement *ele = new AccountReportElement;
        ele->setSevaType(seva_type_int);
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        emit account_report(ele);
    }
    return true;
}

bool AccountReportsDBInterface::generateMonthReport(ReportFilterElements *elm)
{
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    int month = elm->sMonth().toInt();
    int year  = elm->sYear().toInt();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    qDebug() << Q_FUNC_INFO << "DB Query for SevaType ="<< seva_type_string << " Seva Code =" << seva_type_int <<  " Seva Name =" << seva_name << " Month =" << month << " Year =" << year << Qt::endl;

    QSqlQuery query_other1;
    QString que;
    // All sevaType & All Seva Name report
    if(seva_type_string.isEmpty()) {
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE, BANK AS Tran_type from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year);
    }
    // Specific sevaType & All Seva Name report
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0) {
        qDebug()<< Q_FUNC_INFO << "Month report for Seva Type =" << seva_type_int << " Seva Type Name=" << seva_type_string << " Month =" <<month;
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE, BANK AS Tran_type from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year).arg(seva_type_int);
    }
    // Specific sevaType & Specific Seva Name report
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)!=0 ) {
        qDebug() << Q_FUNC_INFO << " Specific Report for Seva Type="<< seva_type_int << " SevaName =" << seva_name << " Month =" << month<<" Year ="<< year<< Qt::endl;
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE, BANK AS Tran_type from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.SEVANAME");
        que = que.arg(month).arg(year).arg(seva_type_int).arg(seva_name);
    }
    qDebug() << Q_FUNC_INFO << " Month Report Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        AccountReportElement *ele = new AccountReportElement;
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        emit account_report(ele);
    }
    return true;
}

int AccountReportsDBInterface::getSevaTypeID(QString seva_type_string)
{
    int seva_type_int = -1;
    if(!seva_type_string.isEmpty()){
        QSqlQuery query;
        // get seva type
        QString qry = "select SEVACODE from seva where seva.SEVATYPE LIKE '%1'";
        qry = qry.arg(seva_type_string);
        query.prepare(qry);
        query.exec();
        while(query.next()) {
            seva_type_int = query.value(0).toInt();
        }
    }
    return seva_type_int;
}
