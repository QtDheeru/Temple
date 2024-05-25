#include "AccountReportsDBInterface.h"
#include <QSqlQuery>
#include "AccountReportElement.h"
#include <QQmlEngine>

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
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setDate(date2Query);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
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
    QString startDate2Query = elm->sStartDate();
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
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
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
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        emit account_report(ele);
    }
    return true;
}

AccountReportElement *AccountReportsDBInterface::getNewAccountElement(){
    AccountReportElement *ele = new AccountReportElement;
    QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
    return ele;
}


bool AccountReportsDBInterface::generateReportForEachDateOfMonth(ReportFilterElements *elm)
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
    QString readstr;
    // All sevaType & All Seva Name report
    if(seva_type_string.isEmpty()) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) as SevaTotalPrice,BANK as Tran_type from sevabooking where sevabooking.R_YEAR ='%1' and sevabooking.R_MONTH ='%2' Group by sevabooking.RECEIPT_DATE,BANK;" );
        readstr  = readstr.arg(year).arg(month);
    }

    // Specific sevaType & All Seva Name report
    if (seva_type_int !=0 && seva_name.compare(ALL_SEVA_REPORT)==0) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) as SevaTotalPrice,BANK as Tran_type from sevabooking where sevabooking.R_YEAR ='%1' and sevabooking.R_MONTH ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(year).arg(month).arg(seva_type_int);
    }

    if (seva_type_int !=0 && seva_name.compare(ALL_SEVA_REPORT)!=0 ) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) as SevaTotalPrice,BANK as Tran_type from sevabooking where sevabooking.R_YEAR ='%1' and sevabooking.R_MONTH ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(year).arg(month).arg(seva_type_int).arg(seva_name);
    }

    qDebug() << Q_FUNC_INFO << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setSeva_name(seva_name);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setDate(query_other1.value(0).toString());
        ele->setSeva_ticket(query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        double totalPrice = 0;
        if(query_other1.value("Tran_type").toString().compare(pay_mode[0],Qt::CaseInsensitive)==0){
            ele->setCash(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getCash();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[1],Qt::CaseInsensitive)==0){
            ele->setCheque(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getCheque();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[2],Qt::CaseInsensitive)==0){
            ele->setNeft(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getNeft();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[3],Qt::CaseInsensitive)==0){
            ele->setUpi(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getUpi();
        }

        ele->setSeva_total(totalPrice);//total
        emit account_report_Date_Range(ele);
        ele->print();
    }
    return true;
}

bool AccountReportsDBInterface::generateReportForEachDateInDateRange(ReportFilterElements *elm)
{

    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    QString startDate2Query = elm->sStartDate();
    QString endDate2Query = elm->sEndDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QSqlQuery query_other1;
    QString readstr;
    if(seva_type_string.isEmpty()) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) as SevaTotalPrice, BANK as Tran_type from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by RECEIPT_DATE,BANK;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query);
    } else if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int);
    } else if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)!=0 ) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' and  Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int).arg(seva_name);
    }
    qDebug() << Q_FUNC_INFO << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();

    while(query_other1.next())
    {
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setSeva_name(seva_name);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setDate(query_other1.value(0).toString());
        ele->setSeva_ticket(query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        double totalPrice = 0;
        if(query_other1.value("Tran_type").toString().compare(pay_mode[0],Qt::CaseInsensitive)==0){
            ele->setCash(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getCash();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[1],Qt::CaseInsensitive)==0){
            ele->setCheque(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getCheque();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[2],Qt::CaseInsensitive)==0){
            ele->setNeft(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getNeft();
        } else if(query_other1.value("Tran_type").toString().compare(pay_mode[3],Qt::CaseInsensitive)==0){
            ele->setUpi(query_other1.value("SEVATOTALPRICE").toFloat());
            totalPrice = ele->getUpi();
        }

        ele->setSeva_total(totalPrice);//total
        emit account_report_Date_Range(ele);
        ele->print();
    }
    return true;
}


bool AccountReportsDBInterface::fullAccounDetailsDateWise(QString sevaName,int sevaType,QString reportDate)
{
    qDebug()<<Q_FUNC_INFO<<"Seva Name= "<<sevaName<<" Type= "<<sevaType<<" Date = "<<reportDate<<Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if( sevaType == 0 && sevaName.compare(ALL_SEVA_REPORT)==0){
        qDebug() << Q_FUNC_INFO << " Report filter only on Date ..=" << reportDate << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1';");
        que1 = que1.arg(reportDate);
    } else if ( sevaType == 0 && !sevaName.isEmpty()){
        qDebug() << Q_FUNC_INFO << " Report filter on Date ..=" << reportDate << " & SevaName =" << sevaName << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVANAME='%2';");
        que1 = que1.arg(reportDate).arg(sevaName);
    }
    else if(sevaName == ALL_SEVA_REPORT){
        qDebug() << Q_FUNC_INFO << " Report filter on SevaType ..=" << sevaType <<  Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2';");
        que1 = que1.arg(reportDate).arg(sevaType);
    } else {
        qDebug() << Q_FUNC_INFO << " Report filter on SevaType ..=" << sevaType <<  " SevaName=" << sevaName << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3';");
        que1 = que1.arg(reportDate).arg(sevaType).arg(sevaName);
    }
    qDebug() << Q_FUNC_INFO << " Query to Execute =" << que1 << Qt::endl;
    query_other1.prepare(que1);
    query_other1.exec();

    while(query_other1.next()){
        qDebug()<<Q_FUNC_INFO << " Records Found. Iteratring.."<<Qt::endl;
        AccountFullreportElement* felement = new AccountFullreportElement;
        felement->setRecieptnumber(query_other1.value(0).toString());
        felement->setRecptDate(query_other1.value(1).toString());
        felement->setSevadate(query_other1.value(2).toString());
        felement->setSevaname(query_other1.value(3).toString());
        felement->setSevacost(query_other1.value(4).toInt());
        felement->setSevaCount(query_other1.value(5).toInt());
        felement->setDevoteeName(query_other1.value(6).toString());
        felement->setMobile(query_other1.value(7).toString());
        felement->setPaymentmode(query_other1.value(8).toString());
        felement->setTotal(query_other1.value(9).toInt());
        felement->setAdditionalCost(query_other1.value(10).toString());
        felement->setBookingStatus(query_other1.value(11).toString());
        qDebug()<<query_other1.value(0).toString()<<Qt::endl;
        qDebug()<<query_other1.value(1).toString()<<Qt::endl;
        qDebug()<<query_other1.value(2).toString()<<Qt::endl;
        qDebug()<<query_other1.value(3).toString()<<Qt::endl;
        qDebug()<<query_other1.value(4).toString()<<Qt::endl;
        qDebug()<<query_other1.value(5).toString()<<Qt::endl;
        qDebug()<<query_other1.value(6).toString()<<Qt::endl;
        qDebug()<<query_other1.value(7).toString()<<Qt::endl;
        qDebug()<<query_other1.value(8).toString()<<Qt::endl;
        qDebug()<<query_other1.value(9).toString()<<Qt::endl;
        emit sendFullAccountDataElement(felement);
    }
    return true;
}

bool AccountReportsDBInterface::fullAccounDetailsDateWise(ReportFilterElements *elm)
{

    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString sevaName = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    QString reportDate = elm->sSingleDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    qDebug()<<Q_FUNC_INFO<<"Seva Name= "<<sevaName<<" SevaTypeName =" << seva_type_string << "  TypeIS= "<<seva_type_int<<" Receipt Date = "<< reportDate<< Qt::endl;

    QSqlQuery query_other1;
    QString que1;
    if(seva_type_string.isEmpty()) {
        qDebug() << Q_FUNC_INFO << " Report filter only on Date ..=" << reportDate << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1';");
        que1 = que1.arg(reportDate);
    } else if (seva_type_int !=0 && sevaName.compare(ALL_SEVA_REPORT)==0) {
        qDebug() << Q_FUNC_INFO << " Report filter on SevaType ..=" << seva_type_int <<  Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2';");
        que1 = que1.arg(reportDate).arg(seva_type_int);
    } else {
        qDebug() << Q_FUNC_INFO << " Report filter on SevaType ..=" << seva_type_int <<  " SevaName=" << sevaName << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3';");
        que1 = que1.arg(reportDate).arg(seva_type_int).arg(sevaName);
    }
    qDebug() << Q_FUNC_INFO << " Query to Execute =" << que1 << Qt::endl;
    query_other1.prepare(que1);
    query_other1.exec();

    while(query_other1.next()){
        qDebug()<<Q_FUNC_INFO << " Records Found. Iteratring.."<<Qt::endl;
        AccountFullreportElement* felement= new AccountFullreportElement;
        felement->setRecieptnumber(query_other1.value(0).toString());
        felement->setRecptDate(query_other1.value(1).toString());
        felement->setSevadate(query_other1.value(2).toString());
        felement->setSevaname(query_other1.value(3).toString());
        felement->setSevacost(query_other1.value(4).toInt());
        felement->setSevaCount(query_other1.value(5).toInt());
        felement->setDevoteeName(query_other1.value(6).toString());
        felement->setMobile(query_other1.value(7).toString());
        felement->setPaymentmode(query_other1.value(8).toString());
        felement->setTotal(query_other1.value(9).toInt());
        felement->setAdditionalCost(query_other1.value(10).toString());
        felement->setBookingStatus(query_other1.value(11).toString());
        qDebug()<<query_other1.value(0).toString()<<Qt::endl;
        qDebug()<<query_other1.value(1).toString()<<Qt::endl;
        qDebug()<<query_other1.value(2).toString()<<Qt::endl;
        qDebug()<<query_other1.value(3).toString()<<Qt::endl;
        qDebug()<<query_other1.value(4).toString()<<Qt::endl;
        qDebug()<<query_other1.value(5).toString()<<Qt::endl;
        qDebug()<<query_other1.value(6).toString()<<Qt::endl;
        qDebug()<<query_other1.value(7).toString()<<Qt::endl;
        qDebug()<<query_other1.value(8).toString()<<Qt::endl;
        qDebug()<<query_other1.value(9).toString()<<Qt::endl;
        emit sendFullAccountDataElement(felement);
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
