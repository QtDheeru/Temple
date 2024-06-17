#include "BookingReportsDBInterface.h"
#include <QSqlQuery>
#include "BookingReportElement.h"
#include <QQmlEngine>

#include "../DevotePersnalDetails.h"
#include "../DBInterface.h"

BookingReportsDBInterface::BookingReportsDBInterface(QSqlDatabase db, QObject *parent)
    : QObject{parent}
    ,m_db(db)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

bool BookingReportsDBInterface::generateBookingSingleDateReport(ReportFilterElements *elm)
{
    elm->print();
    m_totalPrasada=0;
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    QString date2Query = elm->sSingleDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    qDebug()<< Q_FUNC_INFO <<"\nChanged format is: "<<date2Query<<Qt::endl;
    QSqlQuery query_other1;
    QString que;
    if(seva_type_string.isEmpty()) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is checked and sevaName is checked"<<Qt::endl;
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1';");
        que = que.arg(date2Query);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)==0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is checked and sevaName is unchecked"<<Qt::endl;
        qDebug()<< Q_FUNC_INFO << "Seve Type : " << seva_type_int <<Qt::endl;
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2'; ");
        que = que.arg(date2Query).arg(seva_type_int);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)!=0) {
        qDebug()<< Q_FUNC_INFO << Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is unchecked"<<Qt::endl;
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' ; ");
        que = que.arg(date2Query).arg(seva_type_int).arg(seva_name);
    }

    qDebug()<< Q_FUNC_INFO  << " Query string =" << que <<Qt::endl;
    bool b1= query_other1.prepare(que);
    qDebug()<< Q_FUNC_INFO  << " Query string = " << query_other1.lastError() <<Qt::endl;
    bool b = query_other1.exec();
    qDebug()<< Q_FUNC_INFO  << " Query string = " <<b <<Qt::endl;
    qDebug()<< Q_FUNC_INFO  << " Query prepared successfully =" <<b1 <<Qt::endl;
    qDebug()<< Q_FUNC_INFO  << " Query string = " << query_other1.lastError() <<Qt::endl;
    qDebug()<< Q_FUNC_INFO  << " Query string = " << que <<Qt::endl;

    QList<QString> listOfSevaNames;
    QList<int> listOfPrasada;
    QList<int> listOfSevaType;

    while(query_other1.next())
    {
        qDebug()<< Q_FUNC_INFO  << " Query string inside 1st while = book rep" << que <<Qt::endl;
        // ele->setSevaName(query_other1.value(3).toString());
        listOfSevaNames.append(query_other1.value(3).toString());
        qDebug() << Q_FUNC_INFO << query_other1.value(3).toString() <<Qt::endl;
        listOfSevaType.append(query_other1.value(6).toInt());
        qDebug() << Q_FUNC_INFO << query_other1.value(6).toInt() <<Qt::endl;
    }
    QSqlQuery query_other2;
    int i = 0;
    QString qu;
    while(i<listOfSevaNames.size())
    {
        qDebug()<< Q_FUNC_INFO  << "query while/**********" <<Qt::endl;
        qu = ("select sevaname.THEERTHAPRASADA from sevaname where SEVANAME = '%1' and SEVATYPE = '%2';");
        qu = qu.arg(listOfSevaNames.at(i)).arg(listOfSevaType.at(i));
        qDebug()<< Q_FUNC_INFO  << "query while/******1****" <<Qt::endl;

        qDebug()<< Q_FUNC_INFO  << "query while/*****2*****" <<Qt::endl;

        bool b1 =   query_other2.prepare(qu);
        qDebug()<< Q_FUNC_INFO  << "query while/*****3*****" <<b1<<Qt::endl;

        bool b2 =   query_other2.exec();
        qDebug()<< Q_FUNC_INFO  << "query while/*****4*****" <<b2<<qu<<Qt::endl;
        if(query_other2.next())
        {
            qDebug()<< Q_FUNC_INFO  << "query ifeee/*****5*****" <<Qt::endl;
            listOfPrasada.append(query_other2.value(0).toInt());
        }

        qDebug()<< Q_FUNC_INFO  << "query while/*****5*****" <<Qt::endl;
        i++;
    }
    i=0;
    query_other1.prepare(que);
    qDebug()<< Q_FUNC_INFO  << " Query string : " << query_other1.lastError() <<Qt::endl;
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<< Q_FUNC_INFO  << " Query string inside 2nd while = book rep" << que <<Qt::endl;
        BookingReportElement *ele = new BookingReportElement;
        ele->setName(query_other1.value(0).toString());
        ele->setGothra(query_other1.value(1).toString());
        ele->setNakshatra(query_other1.value(2).toString());
        ele->setSevaName(query_other1.value(3).toString());
        //   listOfSevaNames.append(ele->sevaName());
        ele->setTeerthaPrasada(listOfPrasada.at(i));
        ele->setMobileNumber(query_other1.value(4).toString());
        ele->setNote(query_other1.value(5).toString());
        ele->setSevaDate(query_other1.value(7).toString());
        ele->setReceiptDate(query_other1.value(8).toString());
        ele->setTotal(query_other1.value(9).toString());
        ele->setPaymntMode(query_other1.value(10).toString());
        ele->setReferenceNo(query_other1.value(11).toString());
        ele->setAddress(query_other1.value(12).toString());
        ele->setSevaCount(query_other1.value(13).toInt());
        ele->setSevaType(query_other1.value(14).toInt());
        ele->setSevaTypeName(query_other1.value(15).toString());
        //        ele->setTeerthaPrasada(0);

        qDebug() << Q_FUNC_INFO << " Printing all the booking report eelements :" <<Qt::endl;
        qDebug() <<"name--"<< query_other1.value(0).toString()<<Qt::endl;
        qDebug() <<"gothra--"<< query_other1.value(1).toString()<<Qt::endl;
        qDebug() <<"nakshatra--"<< query_other1.value(2).toString()<<Qt::endl;
        qDebug() <<"seva--"<< query_other1.value(3).toString()<<Qt::endl;
        qDebug() <<"mobile--"<< query_other1.value(4).toString()<<Qt::endl;
        qDebug() <<"note--"<< query_other1.value(5).toString()<<Qt::endl;
        qDebug() <<"prasada--"<< query_other1.value(6).toString()<<Qt::endl;
        qDebug() <<"SDate--"<< query_other1.value(7).toString()<<Qt::endl;
        qDebug() <<"Rdate--"<< query_other1.value(8).toString()<<Qt::endl;
        qDebug() <<"total--"<< query_other1.value(9).toString()<<Qt::endl;
        qDebug() <<"paymode--"<< query_other1.value(10).toString()<<Qt::endl;
        qDebug() <<"refrence--"<< query_other1.value(11).toString()<<Qt::endl;
        qDebug() <<"address--"<< query_other1.value(12).toString()<<Qt::endl;
        qDebug() <<"sevaType--"<< query_other1.value(14).toInt()<<Qt::endl;
        qDebug() <<"sevaTypeName--"<< query_other1.value(15).toString()<<Qt::endl;

        qDebug() <<"before emitting signal  booking_report ''''''''"<<Qt::endl;
        emit booking_report(ele);
        qDebug() <<"after emitting signal  booking_report ''''''''"<<Qt::endl;
        //        i++;
        qDebug()<<"after increment"<<i<<Qt::endl;
    }
}

bool BookingReportsDBInterface::generateBookingDateRangeReort(ReportFilterElements *elm)
{
    elm->print();
    m_totalPrasada=0;
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    QString date2Query = elm->sSingleDate();
    QString seva_Enddate = elm->sEndDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity;

    QSqlQuery query_other1;
    QString que;
    if(seva_type_string.isEmpty()) {
        qDebug()<< Q_FUNC_INFO  <<date2Query<<seva_Enddate;
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is checked and sevaName is checked"<<Qt::endl;
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2';" );
        que  = que.arg(date2Query).arg(seva_Enddate);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)==0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is checked"<<Qt::endl;
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' ; " );
        que  = que.arg(date2Query).arg(seva_Enddate).arg(seva_type_int);
    }
    if ((seva_type_int!=0 & seva_name.compare(ALLSEVANAME)!=0)) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is unchecked"<<Qt::endl;
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' ;" );
        que  = que.arg(date2Query).arg(seva_Enddate).arg(seva_type_int).arg(seva_name);
    }
    qDebug()<< Q_FUNC_INFO  << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();

    QSqlQuery query;
    while(query_other1.next())
    {
        BookingReportElement *elm = new BookingReportElement;
        m_personid = query_other1.value(0).toString();
        elm->setSevaName( query_other1.value(1).toString());
        list_sevaname.append(m_sevaname);
        m_quantity = query_other1.value(2).toInt();
        list_quantity.append(m_quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == elm->sevaName())//regular seva at 1st index in combo
            {
                elm->setTeerthaPrasada( query.value(6).toInt());
                list_prasada.append(m_prasada);
            }
        }

        m_prasada = m_prasada * m_quantity;
        m_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<< Q_FUNC_INFO <<"DD-MM-YYYY is "<<m_date<<Qt::endl;
        m_sevadate = m_date.toString("dd-MM-yyyy");
        list_sevadate.append(m_sevadate);
        elm->setNote(query_other1.value(5).toString());//total
        list_note.append(m_note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(m_personid==p_id){
                elm->setName(query_other2.value(1).toString());
                elm->setGothra(query_other2.value(2).toString());
                elm->setNakshatra(query_other2.value(3).toString());
                elm->setMobileNumber(query_other2.value(5).toString());
                list_pname.append(m_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(m_nakshtra);
                list_mobile.append(m_mobile);
            }
        }
        m_totalPrasada= m_totalPrasada + m_prasada;
        emit booking_report(elm);
    }
}

bool BookingReportsDBInterface::generateBookingMonthReport(ReportFilterElements *elm)
{
    elm->print();
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    int month = elm->sMonth().toInt();
    int year  = elm->sYear().toInt();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    qDebug()<<Q_FUNC_INFO<<"booking report month wise"<<seva_name<<seva_type_int<<month<<year<<Qt::endl;
    m_totalPrasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity;
    QSqlQuery query_other1;

    QString que;
    if(seva_type_string.isEmpty()) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR='%2';");
        que = que.arg(month).arg(year);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)==0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' ; ");
        que = que.arg(month).arg(year).arg(seva_type_int);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)!=0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  ");
        qDebug()<< Q_FUNC_INFO  <<month<<year<<seva_type_int<<seva_name<<Qt::endl;
        que = que.arg(month).arg(year).arg(seva_type_int).arg(seva_name);
    }
    qDebug()<< Q_FUNC_INFO  << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    QSqlQuery query;

    while(query_other1.next())
    {
        BookingReportElement *elm = new BookingReportElement;
        m_personid = query_other1.value(0).toString();
        elm->setSevaName( query_other1.value(1).toString());
        list_sevaname.append(m_sevaname);
        m_quantity = query_other1.value(2).toInt();
        list_quantity.append(m_quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == elm->sevaName())//regular seva at 1st index in combo
            {
                elm->setTeerthaPrasada( query.value(6).toInt());
                list_prasada.append(m_prasada);
            }
        }
        m_prasada = m_prasada * m_quantity;
        m_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<< Q_FUNC_INFO <<"DD-MM-YYYY is "<<m_date<<Qt::endl;
        m_sevadate = m_date.toString("dd-MM-yyyy") ;
        list_sevadate.append(m_sevadate);
        elm->setNote(query_other1.value(5).toString());//total
        list_note.append(m_note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(m_personid==p_id){
                elm->setName(query_other2.value(1).toString());
                elm->setGothra(query_other2.value(2).toString());
                elm->setNakshatra(query_other2.value(3).toString());
                elm->setMobileNumber(query_other2.value(5).toString());
                list_pname.append(m_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(m_nakshtra);
                list_mobile.append(m_mobile);
            }
        }

        m_totalPrasada= m_totalPrasada + m_prasada;
        emit booking_report(elm);
    }
}

bool BookingReportsDBInterface::generateBookingReportForEachDateOfMonth(ReportFilterElements *elm)
{
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    int month = elm->sMonth().toInt();
    int year  = elm->sYear().toInt();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QSqlQuery query_other1;
    QString que;
    if(seva_type_string.isEmpty())
    {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is checked and sevaName is checked"<<Qt::endl;
        que = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' Group by sevabooking.SEVA_DATE;" );
        que  = que.arg(year).arg(month);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)==0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is checked"<<Qt::endl;
        que = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVA_DATE;" );
        que  = que.arg(year).arg(month).arg(seva_type_int);
    }
    if (seva_type_int!=0 & seva_name.compare(ALLSEVANAME)!=0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is unchecked"<<Qt::endl;
        que = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.SEVA_DATE;" );
        que  = que.arg(year).arg(month).arg(seva_type_int).arg(seva_name);
    }
    qDebug() << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<< Q_FUNC_INFO <<"Query in while"<<Qt::endl;
        qDebug()<< Q_FUNC_INFO  << "In while of db ***************************" << que <<Qt::endl;
        BookingReportDateRangeElement *ele = new   BookingReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
        ele->setDate( query_other1.value(0).toString());
        qDebug()<< Q_FUNC_INFO  << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setSevaName(seva_name);
        qDebug()<< Q_FUNC_INFO  << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        emit booking_report_Date_Range(ele);
    }
}

bool BookingReportsDBInterface::generateBookingReportForEachDateInDateRange(ReportFilterElements *elm)
{
    qDebug() <<Q_FUNC_INFO<<Qt::endl;
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    QString startDate2Query = elm->sStartDate();
    QString endDate2Query = elm->sEndDate();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QSqlQuery query_other1;
    QString readstr;
    if(seva_type_string.isEmpty())
    {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is checked and sevaName is checked"<<Qt::endl;
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' Group by sevabooking.SEVA_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query);
    }
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is checked"<<Qt::endl;
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVA_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int);
    }
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)!=0) {
        qDebug()<< Q_FUNC_INFO <<"When the sevaType is unchecked and sevaName is unchecked"<<Qt::endl;
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.SEVA_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int).arg(seva_name);
    }
    qDebug()<< Q_FUNC_INFO  << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<< Q_FUNC_INFO  << "In while of db ***************************" << readstr <<Qt::endl;
        BookingReportDateRangeElement *ele = new   BookingReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);

        ele->setSevaName(seva_name);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setDate( query_other1.value(0).toString());
        qDebug()<< Q_FUNC_INFO  << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug()<< Q_FUNC_INFO  << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;

        emit booking_report_Date_Range(ele);
    }
}

bool BookingReportsDBInterface::generateBookingReportForAllMonths(ReportFilterElements *elm)
{
    qDebug() <<Q_FUNC_INFO<<Qt::endl;

    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int seva_type_int = elm->iSevaType();
    int month = elm->sMonth().toInt();
    int year = elm->sYear().toInt();

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QSqlQuery query_other1;
    QString que;
    if(seva_type_string.isEmpty()) {
        qDebug() << Q_FUNC_INFO << "SevaType is checked and SevaName is checked" << Qt::endl;
        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR='%2' Group by sevabooking.S_MONTH; ");
        que = que.arg(year);
    }
    if (seva_type_int !=0 & seva_name.compare(ALLSEVANAME)==0) {
        qDebug() << Q_FUNC_INFO << "SevaType is unchecked and SevaName is checked" << Qt::endl;
        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.S_MONTH ");
        que = que.arg(year).arg(seva_type_int);
    }
    if (seva_type_int !=0 & seva_name.compare(ALLSEVANAME)!=0) {
        qDebug() << Q_FUNC_INFO << "SevaType is unchecked and SevaName is checked" << Qt::endl;
        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.S_MONTH");
        que = que.arg(year).arg(seva_type_int).arg(seva_name);
    }
    qDebug()<< Q_FUNC_INFO  << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<< Q_FUNC_INFO  << "In while of db ***************************"  <<Qt::endl;
        BookingReportMonthRangeElement *ele = new   BookingReportMonthRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
        ele->setSevaName(seva_name);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setMonth( query_other1.value(0).toString());
        ele->setYear(QString::number(year));
        qDebug()<< Q_FUNC_INFO  << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug()<< Q_FUNC_INFO  << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        emit booking_report_Month_Range(ele);
    }
}

int BookingReportsDBInterface::getSevaTypeID(QString seva_type_string)
{
    qDebug() << Q_FUNC_INFO << "Run getSevaTypeID " << Qt::endl;
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
