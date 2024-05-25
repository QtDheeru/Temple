#include "ProfitAndLossDBInterface.h"

ProfitAndLossDBInterface::ProfitAndLossDBInterface(QSqlDatabase db,QObject *parent)
    : QObject{parent},m_db(db)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

ProfitAndLossDBInterface::~ProfitAndLossDBInterface()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

bool ProfitAndLossDBInterface::generateSingleDateReport(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->generateSingleDateReportForSevaBooking(elm);
    this->generateSingleDateReportForVoucher(elm);
    return true;
}

bool ProfitAndLossDBInterface::generateSingleDateReportForSevaBooking(ReportFilterElements *elm)
{
    elm->print();
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();
    QString date2Query = elm->sSingleDate();
    qDebug() << Q_FUNC_INFO << date2Query << Qt::endl;

    if(!seva_type_string.isEmpty()){
        seva_type_int = this->getSevaTypeID(seva_type_string);
    }

    QString que1;
    QSqlQuery query_other1;
    qDebug() << Q_FUNC_INFO << "DB Query for SevaType =" << seva_type_string << " Seva Code =" << seva_type_int <<  " Seva Name =" << seva_name << " Date =" << date2Query << Qt::endl;

    if(seva_type_string.isEmpty()) {
        qDebug() << Q_FUNC_INFO << " Query all sevaTypes & Seva Names " << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' Group by SEVANAME,BANK;");
        que1 = que1.arg(date2Query);
    };
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT) == 0) {
        qDebug() << Q_FUNC_INFO << " This is ALL Seva Name Query for SevaType=" << seva_type_string << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity ,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(date2Query).arg(seva_type_int);
    };
    if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT) != 0) {
        qDebug() << Q_FUNC_INFO << " Seva Type & Seva Name is specified.." << Qt::endl;
        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE LIKE '%1' and sevabooking.SEVATYPE LIKE '%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(date2Query).arg(seva_type_int).arg(seva_name);
    }

    qDebug() << Q_FUNC_INFO << " Single Date Query string =" << que1 << Qt::endl;
    query_other1.prepare(que1);

    if(!query_other1.exec()) {
        qWarning() << Q_FUNC_INFO <<query_other1.lastError().text() << Qt::endl;
        return false;
    }

    while(query_other1.next()) {
        AccountReportElement *ele = this->getNewAccountElement();
        ele->setDate(date2Query);
        ele->setSevaType(seva_type_int);
        ele->setSevaTypeName(seva_type_string);
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        ele->print();
        emit profitAndLossSevaBookingReport(ele);
    }
    return true;
}

bool ProfitAndLossDBInterface::generateSingleDateReportForVoucher(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO <<  elm->sSingleDate() <<  Qt::endl;
    QString date2Query = elm->sSingleDate();
    QString str = ("select V_NO,NAME,PAYMENT_MODE, PHONE,COST,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES LIKE '%1'");
    str = str.arg(date2Query);
    QSqlQuery query_other1;
    query_other1.prepare(str);
    if(!query_other1.exec())
    {
        qWarning() << Q_FUNC_INFO << query_other1.lastError().text() << Qt::endl;
        return false;
    }

    while(query_other1.next()){
        qDebug() << Q_FUNC_INFO << "^^^^^^^^^^^^^^^ Query DB for View^^^^^^^^^^^^^^^^^^" << Qt::endl;
        VoucherReportElement *velement = new VoucherReportElement;

        QString vno = query_other1.value(0).toString();
        QString vname = query_other1.value(1).toString();
        QString vpaymntmode = query_other1.value(2).toString();
        QString vphone = query_other1.value(3).toString();
        QString vcost = query_other1.value(4).toString();
        QString v_referenceNo =  query_other1.value(5).toString();

        velement->setVoucherNo(vno.toInt());
        velement->setVoucherName(vname);
        velement->setVoucherPaymentMode(vpaymntmode);
        velement->setMobileNo(vphone);
        velement->setVoucherCost(vcost);

        qDebug() << Q_FUNC_INFO << query_other1.value(1).toString() << Qt::endl;
        emit profitAndLossVoucherReport(velement);
    }
    return true;
}

bool ProfitAndLossDBInterface::generateMonthReport(ReportFilterElements *elm)
{
    this->generateMonthReportForSevaBooking(elm);
    this->generateMonthReportForVoucher(elm);
    return true;
}

bool ProfitAndLossDBInterface::generateMonthReportForSevaBooking(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

bool ProfitAndLossDBInterface::generateMonthReportForVoucher(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

bool ProfitAndLossDBInterface::generateDateRangeReport(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->generateDateRangeReportForSevaBooking(elm);
    this->generateDateRangeReportForVoucher(elm);
    return true;
}

bool ProfitAndLossDBInterface::generateDateRangeReportForSevaBooking(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
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
    qDebug() << Q_FUNC_INFO << " Query string =" << readstr << Qt::endl;
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
        emit profitNLoss_DateRange_SevaBooked_report(ele);
        ele->print();
    }
    return true;
}

bool ProfitAndLossDBInterface::generateDateRangeReportForVoucher(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    qDebug() << Q_FUNC_INFO <<  elm->sSingleDate() <<  Qt::endl;
    QString seva_name = elm->sSevaName();
    QString seva_type_string = elm->sevaType();
    int     seva_type_int = elm->iSevaType();

    QString startDate2Query = elm->sStartDate();
    QString endDate2Query = elm->sEndDate();

    QSqlQuery query_other1;
    QString readstr;
    if(seva_type_string.isEmpty()) {
        readstr = ("select V_NO,NAME,PAYMENT_MODE, PHONE,COST,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2' and  Group by VOUCHER_DETAILS.DATES;");
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query);
    } else if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)==0) {
        readstr = ("select V_NO,NAME,PAYMENT_MODE, PHONE,COST,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2' and  Group by VOUCHER_DETAILS.DATES;");
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int);
    } else if (seva_type_int !=0 & seva_name.compare(ALL_SEVA_REPORT)!=0 ) {
        readstr = ("select DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' and  Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(startDate2Query).arg(endDate2Query).arg(seva_type_int).arg(seva_name);
    }

    QString str = ("select V_NO,NAME,PAYMENT_MODE, PHONE,COST,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES LIKE '%1'");
    str = str.arg(startDate2Query).arg(endDate2Query);
    query_other1.prepare(str);
    if(!query_other1.exec())
    {
        qWarning() << Q_FUNC_INFO << query_other1.lastError().text() << Qt::endl;
        return false;
    }

    while(query_other1.next()){
        qDebug() << Q_FUNC_INFO << "^^^^^^^^^^^^^^^ Query DB for View^^^^^^^^^^^^^^^^^^" << Qt::endl;
        VoucherReportElement *velement = new VoucherReportElement;

        QString vno = query_other1.value(0).toString();
        QString vname = query_other1.value(1).toString();
        QString vpaymntmode = query_other1.value(2).toString();
        QString vphone = query_other1.value(3).toString();
        QString vcost = query_other1.value(4).toString();
        QString v_referenceNo = query_other1.value(5).toString();

        velement->setVoucherNo(vno.toInt());
        velement->setVoucherName(vname);
        velement->setVoucherPaymentMode(vpaymntmode);
        velement->setMobileNo(vphone);
        velement->setVoucherCost(vcost);

        qDebug() << Q_FUNC_INFO << query_other1.value(1).toString() << Qt::endl;
        emit profitNLoss_DateRange_Voucher_report(velement);
    }
    return true;
}

int ProfitAndLossDBInterface::getSevaTypeID(QString seva_type_string)
{
    int seva_type_int = -1;
    if(!seva_type_string.isEmpty()){
        QSqlQuery query;
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

AccountReportElement *ProfitAndLossDBInterface::getNewAccountElement()
{
    AccountReportElement *ele = new AccountReportElement;
    QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
    return ele;
}

