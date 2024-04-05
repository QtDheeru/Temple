#include "DBInterface.h"
#include "DevotePersnalDetails.h"
#include "SevaJson/SevaTypeJsonProcessor.h"
#include "./model/SevaName.h"
#include "SevaBookingConformationDataModel.h"
#include "SevaName.h"
#include "SevaJson/JsonProcessor.h"
#include <QSqlError>


DBInterface *DBInterface::init =nullptr;

static int BID=0;
static int SID=0;
static int RID=0;
//static int SET=0 ;
static int TID=0 ;
static int VID=0;
static int sevalastNo=0;
static int sevanameLastNo=0;
//delete from sevaname where SNO>=1000;
DBInterface::DBInterface(QObject *parent) : QObject(parent)
{
    BID=0;
    TID=0;
    SID=0;
    RID=0;
    VID=0;
    db = QSqlDatabase::addDatabase("QSQLITE");
    //QString currentPath=qApp->applicationDirPath()+"/Data/nseva.db";
    QString currentPath = TrustListModel::getTrustListModelInstance()->getDataLocation()+"/nseva.db";
    QFileInfo info(currentPath);
    if (!info.exists()){
        qDebug()<<Q_FUNC_INFO<<"**************** DB path doesn't exist as a file = "<< currentPath <<Qt::endl;
        currentPath = TrustListModel::getTrustListModelInstance()->getDataLocation()+"/nseva.lnk";
        info.setFile(currentPath);
        if(!info.exists()){
            qDebug()<<Q_FUNC_INFO<<"**************** DB doesn't exist as shortcut also ="<< currentPath <<Qt::endl;
            exit(0);
        }
        if(info.isSymLink())
            currentPath = info.symLinkTarget();
        qDebug()<<Q_FUNC_INFO<<"**************** DB Path ="<< currentPath <<Qt::endl;
    }
    db.setDatabaseName(currentPath);

    bool ok = db.open();
    qDebug()<< Q_FUNC_INFO<<"******************* DB"<<currentPath<<Qt::endl;
    QSqlQuery qry;
    if(ok)
    {
        qDebug()<<"Database is opened " << currentPath << Qt::endl;
    }
    else{
        qDebug()<<"Database is NOT opened " <<currentPath << Qt::endl;
        exit(0);
    }

    QString query = "CREATE TABLE seva("
                    "SNO,"
                    "SEVATYPE,"
                    "SEVACODE,"
                    "PERSON);";

    QString query1 = "CREATE TABLE sevaname("
                     "SNO,"
                     "SEVANAME,"
                     "SEVATYPE,"
                     "SEVACOST,"
                     "SEVADATE,"
                     "PERSON,"
                     "THEERTHAPRASADA,"
                     "POOJATIMEING,"
                     "SANKALAPAPOOJA,"
                     "STATUS);";

    QString query2 = "CREATE TABLE sevabooking("
                     "SNO,"
                     "RECPT_NUM,"
                     "PERSONID,"
                     "SEVATYPE,"
                     "SEVANAME,"
                     "QUANTITY,"
                     "S_DATE,"
                     "S_MONTH,"
                     "S_YEAR,"
                     "SEVA_DATE,"
                     "R_DATE,"
                     "R_MONTH,"
                     "R_YEAR,"
                     "RECEIPT_DATE,"
                     "S_TIME,"
                     "SEVACOST,"
                     "ADDITIONALCOST,"
                     "SEVATOTALPRICE,"
                     "NOTE,"
                     "CASH TEXT(30),"
                     "BANK TEXT(30),"
                     "BANKDETAILS TEXT(30),"
                     "REFERENCE TEXT(30),"
                     "STATUS TEXT(30),"
                     "ADDRESS TEXT(30),"
                     "MOMENTO TEXT(30),"
                     "RECPT_NUM TEXT);";

    QString query3 = "CREATE TABLE persondetails("
                     "SNO,"
                     "PERSONNAME,"
                     "GOTHRA,"
                     "NAKSHATRA,"
                     "DATE,"
                     "MOBILE,"
                     "EMAIL,"
                     "ADDRESS);";

    QString query4 = "CREATE TABLE signindetails("
                     "SNO,"
                     "FIRSTNAME,"
                     "LASTNAME,"
                     "USERNAME,"
                     "PASSWORD,"
                     "ROLENUMBER,"
                     "DATE);";

    QString query5 = "CREATE TABLE mastersignin("
                     "SNO,"
                     "USERNAME,"
                     "PASSWORD,"
                     "DATE);";

    QString query6 = "CREATE TABLE VOUCHER_DETAILS("
                     "V_NO,"
                     "NAME,"
                     "PAYMENT_MODE,"
                     "NOTE,"
                     "PHONE,"
                     "PRODUCT,"
                     "COST,"
                     "QUANTITY,"
                     "TOTAL_COST,"
                     "DATES,"
                     "VOUCHER_TYPE,"
                     "REFERENCE_NO,"
                     "S_MONTH,"
                     "S_YEAR);";

    QString query7 = "CREATE TABLE CHEQUE_DATA("
                     "RECEIPT_DATE,"
                     "CHEQUE_DATE, "
                     "BANK_NAME, "
                     "RECEIPT_NUMBER, "
                     "AMOUNT);";

    QString query8="CREATE TABLE BANK("
                     "DATE VARCHAR[10],"
                     "LAST_RECEIPT VARCHAR[10],"
                     "CASH_IN_HAND VARCHAR[15],"
                     "TO_BANK VARCHAR[15],"
                     "TRANSACTION_TYPE VARCHAR[10],"
                     "BANK_NAME VARCHAR[15],"
                     "PERSON VARCHAR[20],"
                     "STATUS VARCHAR[20],"
                     "NOTES VARCHAR[30])";

    QString query9=" CREATE TABLE VOUCHER_DATA("
                     "SL_NO,"
                     "VOUCHER_ID,"
                     "VOUCHER_CATEGORY);";
    //                     "PRIMARY KEY(SL_NO,VOUCHER_ID,VOUCHER_CATEGORY);";

    QString query10="CREATE TABLE SUBVOUCHER_DATA("
                      "VOUCHERID VARCHAR[5],"
                      "SUBCATEGORY_ID VARCHAR[20],"
                      "SUBCATEGORY_NAME VARCHAR[20] UNIQUE,"
                      "PRIMARY KEY(SUBCATEGORY_ID));";

    qry.prepare(query);
    qry.prepare(query1);
    qry.prepare(query2);
    if(qry.exec()){qDebug()<<"Sevabooking table created";}else{qDebug()<<"Sevabboking table not created";}
    qry.prepare(query3);
    if(qry.exec()){qDebug()<<"persondetails table created";}else{qDebug()<<"person details creation failed";}
    qry.prepare(query4);
    if(qry.exec()){
        qDebug()<<"Signin table created";
    }
    qry.prepare(query5);
    qry.prepare(query6);
    qry.prepare(query7);  if(qry.exec()){
        qDebug()<<"Cheque entry table created";
    }
    qry.prepare(query8);
    if(qry.exec()){
        qDebug()<<"Cash Entry  table created";
    }
    qry.prepare(query9);
    if(qry.exec()){
        qDebug()<<"VoucherMain table created";
    }else{
        qDebug()<<"VoucherMain table not created";

    }
    qry.prepare(query10);
    if(qry.exec())
    {
        qDebug()<<" VoucherSub table created";
    }

    m_proc = new SevaTypeJsonProcessor;
    readSevaTypesFromJson();
    readSevaNamesFromJson();

}

QString DBInterface::getError() const
{
    qDebug() << Q_FUNC_INFO << " Error = " << m_error << Qt::endl;
    return m_error;
}

void DBInterface::setError(const QString &error)
{
    m_error = error;
}
void DBInterface::addCashTOdatabase(QString a_date, QString a_lastreci, QString a_cashinhand, QString a_tobank, QString a_transType, QString a_bank, QString a_person, QString a_status, QString a_notes)
{
    qDebug()<<"The receieved data"<<Qt::endl;

    if(a_tobank!=""){
        QSqlQuery m_sqlquery ;
        m_sqlquery.prepare("INSERT INTO BANK(DATE ,LAST_RECEIPT ,CASH_IN_HAND ,TO_BANK ,TRANSACTION_TYPE ,BANK_NAME ,PERSON ,STATUS ,NOTES) VALUES(:date,:lastreci,:cashinhand,:tobank,:transtype,:bank,:person,:status,:notes)");
        m_sqlquery.bindValue(":date",a_date);
        m_sqlquery.bindValue(":lastreci",a_lastreci);
        m_sqlquery.bindValue(":cashinhand",a_cashinhand);
        m_sqlquery.bindValue(":tobank",a_tobank);
        m_sqlquery.bindValue(":transtype",a_transType);
        m_sqlquery.bindValue(":bank",a_bank);
        m_sqlquery.bindValue(":person",a_person);
        m_sqlquery.bindValue(":status",a_status);
        m_sqlquery.bindValue(":notes",a_notes);
        if(m_sqlquery.exec()){
            qDebug()<<"query executed";
        }
    }
}

void DBInterface::databaseToCashEntry()
{
    QSqlQuery myquery;
    qDebug()<<"Select data called";
    myquery.prepare("Select * FROM sevabooking");
    bool val=myquery.exec();
    qDebug() << "The last error = "<<myquery.lastError();
    if(val){
        qDebug()<<"Select success";
    }
    else
        qDebug()<<"Select fail";

    while(myquery.next()){
        QString recieptNumber=myquery.value(0).toString();
        QString amount=myquery.value(18).toString();
        QString cashType=myquery.value(19).toString();
        qDebug()<<"recieptNumber="<<recieptNumber<<"amount="<<amount<<"cashType="<<cashType<<Qt::endl;
        if(cashType=="cash" || cashType=="Cash"){
            emit signalToCashEntry(recieptNumber,amount,cashType);
        }
    }
}

void DBInterface::lastDataToCashEntry()
{
    QSqlQuery myquery;
    qDebug()<<"Select data called";
    myquery.prepare("Select * FROM BANK");
    bool val=myquery.exec();
    qDebug() << "The last error = "<<myquery.lastError();
    if(val){
        qDebug()<<"Select success";
    }
    else
        qDebug()<<"Select fail";
    QString recieptNumber;
    QString amount;
    QString toBank;
    QString TransactionType;
    while(myquery.next()){
        recieptNumber=myquery.value(1).toString();
        amount=myquery.value(2).toString();
        toBank=myquery.value(3).toString();
        TransactionType=myquery.value(4).toString();
    }
    qDebug()<<"recieptNumber="<<recieptNumber<<"amount="<<amount<<Qt::endl;
    emit signalToCashTransaction(recieptNumber,amount,toBank,TransactionType);
}


void DBInterface::addData(QString slno, QString vid, QString vname)
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery query ;
    query.prepare("INSERT INTO VOUCHER_DATA(SL_NO,VOUCHER_ID,VOUCHER_CATEGORY) VALUES(:slno,:vid,:vname)");
    query.bindValue(":slno",slno);
    query.bindValue(":vid",vid);
    query.bindValue(":vname",vname);
    if(query.exec())
    {
        qDebug()<<"Insert Query executed"<<Qt::endl;
        emit addSuccessInDB(slno,vid,vname);
    }
    else{
        qDebug()<<"Insert Query exe..failed"<<Qt::endl;
        emit addFailInDB();
    }
}

void DBInterface::selectDataInMain()
{
    QSqlQuery myquery;
    qDebug()<<"Select data called";
    myquery.prepare("Select * FROM VOUCHER_DATA");
    bool val = myquery.exec();
    qDebug() << "The last error = "<<myquery.lastError();
    if(val){
        qDebug()<<"Select success";
    }
    else
        qDebug()<<"Select fail";

    while(myquery.next())
    {
        QString serial=myquery.value(0).toString();
        QString voucherId=myquery.value(1).toString();
        QString voucherName=myquery.value(2).toString();
        qDebug()<<"ser="<<serial<<"vouc="<<voucherId<<"Name="<<voucherName<<endl;
        emit selectSignalFromDB(serial,voucherId,voucherName);
    }
}

void DBInterface::updateData(QString slno, QString vid, QString vname)
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery query;
    query.prepare("UPDATE VOUCHER_DATA SET SL_NO=:slno,VOUCHER_CATEGORY=:vname WHERE VOUCHER_ID =:vid ");
    query.bindValue(":slno",slno);
    query.bindValue(":vid",vid);
    query.bindValue(":vname",vname);
    if(query.exec()){
        qDebug()<<"Update Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Update Query exe..failed"<<Qt::endl;
    }
    if(!query.numRowsAffected())
        emit updateFailedInDB();
    else
        emit updateSuccessInDB(slno,vid,vname);

}

void DBInterface::removeData(QString vid)
{
    qDebug()<<"Remove Data Called";
    QSqlQuery query;
    query.prepare("DELETE FROM VOUCHER_DATA WHERE VOUCHER_ID=:vid");
    query.bindValue(":vid",vid);
    if(query.exec()){
        qDebug()<<"Remove Query executed"<<Qt::endl;
    }
    else{
        qDebug()<<"Remove Query exe..failed"<<Qt::endl;
    }
    if(!query.numRowsAffected())
        emit deletionFailedInDB();
    else
        emit deletionSuccessInDB(vid);

}

void DBInterface::updateToDb(QString vid, QString sid, QString sname)
{
    QSqlQuery Myquery;
    Myquery.prepare("UPDATE SUBVOUCHER_DATA SET SUBCATEGORY_NAME=:sname WHERE VOUCHERID=:vid AND SUBCATEGORY_ID=:sid ");
    Myquery.bindValue(":sid",sid);
    Myquery.bindValue(":sname",sname);
    Myquery.bindValue(":vid",vid);

    if(Myquery.exec())
    {
        qDebug()<<"Update Query executed in Subhead"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Update Query exe..failed in Subhead"<<Myquery.lastError()<<Qt::endl;
    }
    qDebug()<<"number of Rows affected"<<Myquery.numRowsAffected();
    if(!(Myquery.numRowsAffected()))
    {
        emit update_Failed();
    }
    else
    {
        emit update_Success(vid,sid,sname);
    }
}

void DBInterface::deleteData(QString vid, QString sid, QString sname)
{
    QSqlQuery Myquery;
    qDebug()<<"vid in deleteData"<<vid;
    qDebug()<<"sid in deleteData"<<sid;
    qDebug()<<"sname in deleteData"<<sname;

    qDebug()<<"Remove Data Called in SubheadDatabase";
    Myquery.prepare("DELETE FROM SUBVOUCHER_DATA WHERE VOUCHERID=:vid AND SUBCATEGORY_ID=:sid ");
    Myquery.bindValue(":vid",vid);
    Myquery.bindValue(":sid",sid);

    if(Myquery.exec())
    {
        qDebug()<<"Remove Query executed in deleteData"<<Qt::endl;
    }
    else{
        qDebug()<<"Remove Query exe..failed deleteData"<<Qt::endl;
    }
    qDebug()<<"numRowsAffected("<<Myquery.numRowsAffected();
    if(!(Myquery.numRowsAffected()))
    {
        emit deletion_Failed();
    }
    else
    {
        emit deletion_Success(vid,sid,sname);
    }
}

void DBInterface::getChequeData()
{
    emit clearChequeList();

    qDebug()<<"Get Cheque Data";
    QList <QString> checkDbRecptNum;
    QString recptNum;
    QSqlQuery qry3,qry2;

    qry2.prepare("select * from CHEQUE_DATA");
    qry3.prepare("select * from sevabooking");

    if(qry2.exec())
    {
        qDebug()<<"Query2EXE";
        while(qry2.next())
        {
            recptNum = qry2.value(3).toString();
            checkDbRecptNum.append(recptNum);
        }
    }

    for(int i=0;i<checkDbRecptNum.count();i++)
    {
        qDebug()<<"ELEOFLIST="<<checkDbRecptNum.at(i);
    }

    if(qry3.exec())
    {
        qDebug()<<"Query1EXE";
        while(qry3.next())
        {
            recptNum = qry3.value(0).toString();
            QString bank = qry3.value(19).toString();
            QString bankName = qry3.value(20).toString();
            QString receiptNumber = qry3.value(0).toString();
            QString r_date =  qry3.value(5).toString() ;
            QString r_month = qry3.value(6).toString();
            QString r_year = qry3.value(7).toString();
            QString amount = qry3.value(18).toString();

            QString reciptdate = r_date +"-"+ r_month +"-"+ r_year ;
            QString chequeDate = "17-08-2023";

            if(checkDbRecptNum.contains(recptNum))
            {
                qDebug()<<recptNum<<" already contains";
            }
            else
            {
                if(bank == "Cheque" || bank == "cheque")
                {
                    qDebug()<<"DONTCONTAINS"<<recptNum;
                    qDebug()<<"BnkName = "<<receiptNumber;
                    emit sendDataToModel(bankName,receiptNumber,reciptdate,amount,chequeDate);
                }
            }
        }
    }
}

int DBInterface::getpersonID(QString devoteMobile,QString devoteeName)
{
    qDebug()<< Q_FUNC_INFO << "Devotee mobile no. " << devoteMobile << Qt::endl;
    QSqlQuery qry;

    QString stringQry = QString("SELECT * FROM persondetails");

    qry.prepare(stringQry);
    if(!qry.exec()){
        qWarning() << Q_FUNC_INFO << "Error in persondetails query!!!" << qry.lastError().text() << Qt::endl;
        return -1;
    }
    while (qry.next()){
        QVariant mobileNumber = qry.value(5);
        if(mobileNumber.toString().contains(devoteMobile)){
            qDebug()<< Q_FUNC_INFO << "qry.value(5) mobile no. =" << qry.value(5) << Qt::endl;
            if(qry.value(1).toString().contains(devoteeName)){
                qDebug()<< Q_FUNC_INFO << " qry.value(0) Name of devotee  =" << qry.value(1) << " person ID" << qry.value(0).toInt() << Qt::endl;
                return qry.value(0).toInt();
            }
        }
    }
    qWarning() << Q_FUNC_INFO << "Devotee is not present in persondetails !!!" << Qt::endl;
    return -1;
}

void DBInterface::addMyDB(QString vid, QString sid, QString sname)
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery Myquery;
    qDebug()<<"vid = "<<vid;
    qDebug()<<"sid = "<<sid;
    qDebug()<<"sname="<<sname;
    Myquery.prepare("INSERT INTO SUBVOUCHER_DATA(VOUCHERID,SUBCATEGORY_ID,SUBCATEGORY_NAME) VALUES(:vid,:sid,:sname)");

    Myquery.bindValue(":vid",vid);
    Myquery.bindValue(":sid",sid);
    Myquery.bindValue(":sname",sname);
    if(Myquery.exec())
    {
        emit insert_Success(vid,sid,sname);
        qDebug()<<"InseIrt Query executed In SubHeadsDataBase"<<Qt::endl;

    }
    else
    {
        qDebug()<<"Insert Query exe..failed in addMyDB SubHeads"<<Qt::endl;
        emit toModelDialog();

    }
}

void DBInterface::selectDataAll(QString MYVOUCHER)
{
    bool value=false;
    QSqlQuery Myquery;

    qDebug()<<"Select Data All Called";
    Myquery.prepare("SELECT VOUCHERID,SUBCATEGORY_ID,SUBCATEGORY_NAME FROM SUBVOUCHER_DATA ");
    if(Myquery.exec())
    {
        qDebug()<<"Retrieve Query executed in Subhead"<<Qt::endl;
    }
    else
    {
        qDebug()<<"Retrieve Query exe..failed in Subhead"<<Qt::endl;
    }

    while(Myquery.next())
    {
        qDebug("Inside selectData of VoucherSubheadDatabase");
        QString voucherID=Myquery.value(0).toString();
        QString subID=Myquery.value(1).toString();
        QString subName=Myquery.value(2).toString();
        if(MYVOUCHER == voucherID)
        {
            qDebug()<<"The Clicked Voucher Id is found in SubVoucher DB";
            value = true;
        }

        qDebug()<<"SUBID IN selectDataAll()"+subID;
        qDebug()<<"SUBNAME IN selectDataAll()"+subName;

        emit mySelectSignalAll(voucherID,subID,subName);

    }
    if(!value)
    {
        qDebug()<<"Emitting empty Data";
        emit mySelectSignalAll(MYVOUCHER,"","");
    }


}

void DBInterface::addChequeToDataBase(QString db_receiptDate, QString db_chequeDate, QString db_bankName, QString db_recepitNumber, QString db_amount)
{
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO CHEQUE_DATA(RECEIPT_DATE ,CHEQUE_DATE ,BANK_NAME ,RECEIPT_NUMBER ,AMOUNT) VALUES(:receiptDate,:chequeDate,:bankName,:receiptNumber,:amount)");
    Squery.bindValue(":receiptDate",db_receiptDate);
    Squery.bindValue(":chequeDate",db_chequeDate);
    Squery.bindValue(":bankName",db_bankName);
    Squery.bindValue(":receiptNumber",db_recepitNumber);
    Squery.bindValue(":amount",db_amount);
    if(Squery.exec()){
        qDebug()<<"cheque data query executed";
    }
    else{
        qDebug()<<"cheque insert query not executed"<<Squery.lastError()<<Qt::endl;
    }
}

bool DBInterface::add_seva_type(QString seva_type, int seva_code,QString seva_adder_name)
{
    qDebug()<<Q_FUNC_INFO;
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM seva");
    query_other.exec();
    int sevaSerialNumber=-1;
    while(query_other.next()){
        int snumber = query_other.value(0).toString().toInt();
        QString sevaTypeName = query_other.value(1).toString();
        int sevacode = query_other.value(2).toString().toInt();
        if(sevacode==seva_code){
            qCritical()<<Q_FUNC_INFO<<"sevacode alraedy exist"<<endl;
            emit dbError("Database Message: sevacode " + QString::number(seva_code) + "  already exist");
            this->setError("Database Message: sevacode = " + QString::number(seva_code) + " Already exist");
            return false;
        }
        if(sevaTypeName.compare(seva_type,Qt::CaseInsensitive)==0){
            qCritical()<<Q_FUNC_INFO<<" Seva Name = " << seva_type << "  alraedy exist"<<endl;
            emit dbError("DataBase Msg: sevatype  " + seva_type + "  already exist");
            this->setError("DataBase Msg: sevatype = " + seva_type + " Already exist");
            return false;
        }
        if(snumber > sevaSerialNumber){
            sevaSerialNumber = snumber;
        }
    }
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO seva(SNO,SEVATYPE,SEVACODE,PERSON)"
                   "VALUES (:sno, :seva_name, :seva_code, :person_name)");
    Squery.bindValue(":sno",++sevaSerialNumber);
    Squery.bindValue(":seva_name",seva_type);
    Squery.bindValue(":seva_code",seva_code );
    Squery.bindValue(":person_name",seva_adder_name);

    qDebug() << Q_FUNC_INFO <<sevaSerialNumber;
    qDebug() << Q_FUNC_INFO <<seva_type;
    qDebug() << Q_FUNC_INFO <<seva_code;
    qDebug() << Q_FUNC_INFO <<seva_adder_name;
    bool suc= Squery.exec();
    if(suc) {
        qDebug()<<Q_FUNC_INFO<<"  Successfully modified"<<Qt::endl;
        emit dbError("DataBase Msg: sevatype  " + seva_type + "  Added Successfully");
        this->setError(" Data Base : Seva Type Added Successfully");
    }else{
        qCritical()<<Q_FUNC_INFO<<"  Failed to be modified"<<Squery.lastError().text()<<Qt::endl;
        this->setError(" Data Base : Failed to add SevaType :"+Squery.lastError().text());
    }

    return suc;
}

bool DBInterface::add_seva_type(SevaType *sevaType)
{
    qDebug () << Q_FUNC_INFO << " Seva Type Requested to Add = " << sevaType->sevaTypeId() <<Qt::endl;
    QSqlQuery qry;
    qry.prepare("select * from seva where sevacode=:st");
    qry.bindValue(":st",sevaType->sevaTypeId());
    qry.exec();
    while(qry.next()){
        int snu =qry.value(2).toInt();
        qDebug () << Q_FUNC_INFO << " Seva Type in DB =" << snu <<Qt::endl;
        if (snu == sevaType->sevaTypeId()){
            qWarning() << Q_FUNC_INFO << " Seva Type with ID = " << sevaType->sevaTypeId() << "already exist in DB" <<Qt::endl;
            return false;
        }
    }

    QSqlQuery Squery;
    Squery.prepare("INSERT INTO seva(SNO,SEVATYPE,SEVACODE,PERSON)"
                   "VALUES (:sno, :seva_name, :seva_code, :person_name)");
    Squery.bindValue(":sno",sevaType->sevaTypeSeqNumber());
    Squery.bindValue(":seva_name",sevaType->sevaTypeName());
    Squery.bindValue(":seva_code",sevaType->sevaTypeId());
    Squery.bindValue(":person_name",sevaType->userName());
    Squery.exec();
    return true;
}

DBInterface* DBInterface::getInstance()
{
    if (init == nullptr) {
        qDebug() << "Creating the DataBase Connection " <<Qt::endl;
        init = new DBInterface();
    }
    return init;
}

bool DBInterface::check_db(QString seva_type, int seva_code, QString sevatype_adder_name)
{
    QMessageBox msgbox;
    int seva_type_size =seva_type.size();
    
    if((seva_code<0)||(seva_type_size<2))
    {
        msgbox.setText(tr("PLEASE ENTER ALL THE FIELDS"));
        msgbox.exec();
    }

    if((seva_type!=nullptr)||(seva_code!=0))
    {
        bool found =false;
        QSqlQuery qry;
        qry.prepare("select SNO,SEVATYPE,SEVACODE from seva ");
        qry.exec();
        while(qry.next())
        {
            BID =qry.value(0).toInt();
            QString val1=qry.value(1).toString();
            int val2=qry.value(2).toInt();
            qDebug()<<Q_FUNC_INFO<<val1<<Qt::endl;
            qDebug()<<Q_FUNC_INFO<<val2<<Qt::endl;
            if((val1.compare(seva_type)==0)||(seva_code==val2))
            {
                found =true;
                break;
            }
        }

        if(!found)
        {
            this->add_seva_type(seva_type,seva_code,sevatype_adder_name);
            emit send_seva_details(seva_type,seva_code,sevatype_adder_name);
            emit s_type_sig(seva_type);
        }
        else
        {
            msgbox.setText(tr("SEVA TYPE IS ALREADY EXISTS"));
            msgbox.exec();
        }
    }
    return true;
}

bool DBInterface::check_name_db(int sevatype, QString sevaName, int seva_cost, QString str_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    qDebug()<<"Inside check_name_db "<<Qt::endl;
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA from sevaname ");
    qry.exec();
    while(qry.next()){
        SID =qry.value(0).toInt();
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<val2<<Qt::endl;

        if((val1.compare(sevaName)==0)&&(sevatype==val2))
        {
            found =true;
            break;
        }
    }

    if(!found)
    {
        this->addsevaname(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
    }

    return found;
}

void DBInterface::addsevaname(int sevatype, QString sevaName, int seva_cost, QString strold_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    qDebug()<<"Inside addsevaname "<<Qt::endl;
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    
    QDate Date1 = QDate::fromString(strold_date,"dd-MM-yyyy");
    QString str_date  = Date1.toString("yyyy-MM-dd");

    SID = SID +1;
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO sevaname(SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,POOJATIMEING,SANKALAPAPOOJA,STATUS)"
                   "VALUES (:sno, :seva_name, :seva_type, :seva_cost, :seva_date, :seva_adder_name, :t_prasada, :pooja_time, :pooja )");
    Squery.bindValue(":sno",SID);
    Squery.bindValue(":seva_name",sevaName);
    Squery.bindValue(":seva_type",sevatype );
    Squery.bindValue(":seva_cost",seva_cost );
    Squery.bindValue(":seva_date",str_date );
    Squery.bindValue(":seva_adder_name",seva_adder_name);
    Squery.bindValue(":t_prasada",prasada);
    Squery.bindValue(":pooja_time",pooja_time);
    Squery.bindValue(":pooja",pooja);

    qDebug() << Q_FUNC_INFO <<sevaName;
    qDebug() << Q_FUNC_INFO <<SID;
    qDebug() << Q_FUNC_INFO <<sevatype;
    qDebug() << Q_FUNC_INFO <<seva_cost;
    qDebug() << Q_FUNC_INFO <<str_date;
    qDebug() << Q_FUNC_INFO <<seva_adder_name;
    qDebug() << Q_FUNC_INFO <<prasada;
    qDebug() << Q_FUNC_INFO <<pooja_time;
    qDebug() << Q_FUNC_INFO <<pooja;
    Squery.exec();
}

bool DBInterface::createSeva(SevaName* sevaName)
{
    qDebug () << Q_FUNC_INFO << "Request add. Seva Name = " << sevaName->sevaName() << " sevaId= " << sevaName->sevaId() <<Qt::endl;
    QSqlQuery qry;

    qry.prepare("select * from sevaname where SNO=:sno");
    qry.bindValue(":sno",sevaName->sevaId());
    if(!qry.exec()){
        qWarning() << Q_FUNC_INFO << "Seva Added " << qry.lastError().text() << Qt::endl;
        return false;
    }
    while(qry.next()){
        int snu = qry.value(0).toInt();
        qDebug () << Q_FUNC_INFO << " Seva Name in DB =" << snu << Qt::endl;
        if (snu == sevaName->sevaId()){
            qCritical() << Q_FUNC_INFO << "Seva with ID =" << sevaName->sevaId() << Qt::endl;
            emit dbError("Database Message: sevaID " + QString::number(sevaName->sevaId()) + "  already exist");
            this->setError("Database Message: sevaID = " + QString::number(sevaName->sevaId()) + " already exist");
            return false;
        }
    }

    QSqlQuery Squery;
    Squery.prepare("INSERT INTO sevaname(SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,POOJATIMEING,SANKALAPAPOOJA,STATUS)"
                   "VALUES (:sno, :seva_name, :seva_type, :seva_cost, :seva_date, :seva_adder_name, :t_prasada, :pooja_time, :pooja , :pooja_status )");
    Squery.bindValue(":sno",sevaName->sevaId());
    Squery.bindValue(":seva_name",sevaName->sevaName());
    Squery.bindValue(":seva_type",sevaName->sevaType());
    Squery.bindValue(":seva_cost",sevaName->sevaCost());
    Squery.bindValue(":seva_date",sevaName->sevaStartDate());
    Squery.bindValue(":seva_adder_name",sevaName->userName());
    Squery.bindValue(":t_prasada",sevaName->teerthaPrasada());
    Squery.bindValue(":pooja_time",sevaName->sevaStartTime());
    Squery.bindValue(":pooja",sevaName->sankalpa());
    Squery.bindValue(":pooja_status",sevaName->status());

    bool retVal = Squery.exec();
    if (!retVal) {
        qCritical() << Q_FUNC_INFO << "Erorr inn adding Seva with ID ="<< sevaName->sevaId() << ":: sql query error = " << Squery.lastError().text() <<endl;
        emit dbError("Database Message: sevaID " + QString::number(sevaName->sevaId()) + "  already exist");
        this->setError("Database Message: sevaID = " + QString::number(sevaName->sevaId()) + " already exist");
        return false;
    } else {
        emit dbError("Database Message: sevaID " + QString::number(sevaName->sevaId()) + "  Added successfully");
        this->setError("Database Message: sevaID = " + QString::number(sevaName->sevaId()) + " Added successfully");
        qDebug() << Q_FUNC_INFO << "**** Seva Name =" << sevaName->sevaName() << " Added successfully " <<Qt::endl;

        SevaName *sevaNames = new SevaName;
        sevaNames->setSevaId(sevaName->sevaId());
        sevaNames->setNumber(sevaName->sevaId());
        sevaNames->setSevaName(sevaName->sevaName());
        sevaNames->setSevaType(sevaName->sevaType());
        sevaNames->setSevaCost(sevaName->sevaCost());
        sevaNames->setSevaStartDate(sevaName->sevaStartDate());
        sevaNames->print();
        sevaNames->setObjectName("createSeva_DBInteerface");
        emit sendSevaName(sevaNames);

        return true;
    }
}

void DBInterface::modify_db_type(int r_s_no,QString r_seva_name,int r_seva_code,QString sevaadder_name,int m_s_no)
{

    qWarning()<<Q_FUNC_INFO<<r_s_no<<Qt::endl;
    QSqlQuery qry;
    qry.prepare("UPDATE seva SET SNO=:sno,SEVATYPE=:seva_type,SEVACODE=:seva_code,PERSON=:seva_adder_name WHERE SNO=:s_no");
    qry.bindValue(":s_no",m_s_no);
    qry.bindValue(":sno",r_s_no);
    qry.bindValue(":seva_type",r_seva_name);
    qry.bindValue(":seva_code",r_seva_code);
    qry.bindValue(":seva_adder_name",sevaadder_name);
    qry.exec();
}

void DBInterface::modify_db_seva(int ser_no, QString r_seva_name, int r_seva_code, QString seva_type, QString dateold, QString sevaadder_name, int mod_theertha_prasada, QString modifaid_ptime, int modifaidpooja)
{
    QDate Date1 = QDate::fromString(dateold,"dd-MM-yyyy");
    QString date  = Date1.toString("yyyy-MM-dd");
    qWarning()<<Q_FUNC_INFO<<ser_no<<Qt::endl;

    QSqlQuery qry;
    qDebug()<<Q_FUNC_INFO<<ser_no<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<r_seva_name<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<r_seva_code<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<seva_type<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<date<<Qt::endl;

    qry.prepare("UPDATE sevaname SET SNO=:sno,SEVANAME=:seva_name,SEVATYPE=:seva_type,SEVACOST=:seva_cost,SEVADATE=:seva_date,PERSON=:seav_adder, THEERTHAPRASADA=:terthaprasada,POOJATIMEING=:poojatiming,SANKALAPAPOOJA=:pooja  WHERE SNO=:s_no");
    
    qry.bindValue(":s_no",ser_no);
    qry.bindValue(":sno",ser_no);
    qry.bindValue(":seva_name",r_seva_name);
    qry.bindValue(":seva_type",seva_type);
    qry.bindValue(":seva_cost",r_seva_code);
    qry.bindValue(":seva_date",date);
    qry.bindValue(":seav_adder",sevaadder_name);
    qry.bindValue(":terthaprasada",mod_theertha_prasada);
    qry.bindValue(":poojatiming",modifaid_ptime);
    qry.bindValue(":pooja",modifaidpooja);
    qry.exec();
}

void DBInterface::delete_sevadb(QString old_seva_name,QString old_seva_type)
{
    qDebug()<<Q_FUNC_INFO<<old_seva_name<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<old_seva_type<<Qt::endl;
    int s_no=-1;
    QString sevaname;

    QSqlQuery query;
    query.prepare("SELECT * FROM  sevaname");
    query.exec();
    while(query.next())
    {
        sevaname = query.value(1).toString();
        QString sevat = query.value(2).toString();
        if(old_seva_name==sevaname && sevat==old_seva_type)
        {
            s_no=query.value(0).toInt();
        }
    }
    if(s_no!= -1){
        QSqlQuery qry;
        qry.prepare("DELETE FROM sevaname WHERE SNO=:sno");
        qry.bindValue(":sno", s_no);
        qry.exec();
    }
}

void DBInterface::gotra_list()
{
    QList<QString> list_gotra;
    QSqlQuery qury;
    qury.prepare("select * from persondetails");
    qury.exec();

    while(qury.next())
    {
        QString Gotra=qury.value(2).toString();
        bool alreadyExist = list_gotra.contains(Gotra);
        if(alreadyExist==true)
        {
            continue;
        }
        if(alreadyExist==false)
        {
            list_gotra.append(Gotra);
        }
    }
    emit gotraList(list_gotra);
}

void DBInterface::bank_list()
{
    qDebug()<<Q_FUNC_INFO<<" List of Banks: \n";
    QStringList list_bank;
    QSqlQuery query;
    query.prepare("select * from sevabooking");
    query.exec();

    while(query.next())
    {
        QString Banks=query.value(19).toString();

        bool alreadyExist = list_bank.contains(Banks);
        if(alreadyExist==true)
        {
            continue;
        }
        if(alreadyExist==false)
        {
            list_bank.append(Banks);
        }
    }

    qDebug()<< list_bank<<Qt::endl;
    emit bankList(list_bank);
}

void DBInterface::modify_person_details(QString personId,QString name,QString gothra,QString nakshatra,QString mobilenum)
{
    int id1=personId.toInt();
    QSqlQuery qry;
    qry.prepare("UPDATE persondetails SET SNO=:sno,PERSONNAME=:person_name,GOTHRA=:gothra,NAKSHATRA=:nakshatra,MOBILE=:mobile WHERE SNO=:sno");
    qry.bindValue(":sno",id1);
    qry.bindValue(":person_name",name);
    qry.bindValue(":gothra",gothra );
    qry.bindValue(":nakshatra",nakshatra);
    qry.bindValue(":mobile",mobilenum);
    bool suc = qry.exec();

    if(suc)
        qDebug()<<Q_FUNC_INFO<<"  Successfully modified\n";
    else
        qDebug()<<Q_FUNC_INFO<<"  Failed to be modified\n";

}

void DBInterface::Checking_sevacharge(QString data)
{
    int sevaCharge;
    QSqlQuery qry;
    qry.prepare("select * from sevaname");
    qry.exec();
    while(qry.next())
    {
        sevaCharge=qry.value(3).toInt();
        QString sevaCharges=qry.value(3).toString();
        QString sevaName=qry.value(1).toString();
        if(data==sevaName){
            if(sevaCharge==0)
            {

                emit variable_sevacharge();
            }
            else {
                emit fixed_sevacharge(sevaCharge);
                emit  setting_fixed_seva_charge(sevaCharges);
            }
        }
    }
}

void DBInterface::delete_db(int d_sno)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM seva WHERE SNO=:sno");
    qry.bindValue(":sno", d_sno);
    qry.exec();
}

//void DBInterface::sevabookingdb(QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra, QString devoteSevacharge, QString devoteAdditionalcharges, QString devoteCount, QString devotereceiptdate, QString devoteSevadate, QString devoteNote, QString devoteSevaName, int cost, int rspt_no, QString cash, QString bank_ref, QString bank_name)
bool DBInterface::insertSevaBooked(QString rcptNumI,QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra, QString devoteSevacharge, QString devoteAdditionalcharges, QString devoteCount, QString devotereceiptdate, QString devoteSevadate,QString devoteNote, QString devoteSevaName, int cost, int rspt_no, QString cash, QString bank_ref, QString bank_name,
                                   QString sevaType,QString reference,QString status ,QString address,QString momento,QString sevatime)
{
    qDebug()<<Q_FUNC_INFO << " Mobile number is "<<devoteMobile<<"\n";
    qDebug() << Q_FUNC_INFO << "gotra ===  > " << devoteGotra ;

    QSqlQuery qury;

    QString qr1 = QString("select * from sevaname where sevaname='%1'").arg(devoteSevaName);
    qury.prepare(qr1);
    QString devoteSevaType;
    qury.exec();
    int bookedsevaSerialNumber = 0;
    while(qury.next()){
        RID=qury.value(0).toInt();
        QString val1 = qury.value(1).toString();
        devoteSevaType = qury.value(2).toString();
    }
    qDebug() << Q_FUNC_INFO << " Name =" << devoteSevaName << " Query Size ="<<qury.size() << " Type=" << devoteSevaType <<  Qt::endl;

    // Check if devotee exist in DB.
    int personId = getpersonID(devoteMobile,devoteName); //insertPersonDetails(devoteMobile,devoteName,devoteNakshatra,devoteGotra,address);
    QString Person_id = QString(personId);

    QDate sevaDate = QDate::fromString(devoteSevadate,"dd-MM-yyyy");
    int sday = sevaDate.day();
    int smonth = sevaDate.month();
    int syear = sevaDate.year();
    devoteSevadate = sevaDate.toString("yyyy-MM-dd");

    QDate receiptDate = QDate::fromString(devotereceiptdate,"dd-MM-yyyy");
    int rday = receiptDate.day();
    int rmonth = receiptDate.month();
    int ryear = receiptDate.year();
    devotereceiptdate = receiptDate.toString("yyyy-MM-dd");
    QSqlQuery qry;
    qry.prepare("INSERT INTO sevabooking(SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,S_TIME,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE, NOTE, CASH, BANK, BANKDETAILS, REFERENCE,STATUS ,ADDRESS, MOMENTO,RECPT_NUM)"
                "VALUES (:sno, :person_id, :sevatype, :sevaname, :quantity, :s_date, :s_month, :s_year, :seva_date, :r_date, :r_month,:r_year, :receipt_date, :s_time, :seva_cost, :additionalcost, :sevatotalprice, :note, :cash, :bank, :bankdetails, :reference, :status ,:address, :momento, :recpt_num)");
    qry.bindValue(":sno",rspt_no);
    qry.bindValue(":person_id",personId);
    qry.bindValue(":sevatype",sevaType );
    qry.bindValue(":sevaname",devoteSevaName);
    qry.bindValue(":quantity",devoteCount);
    qry.bindValue(":s_date",sday);
    qry.bindValue(":s_month",smonth);
    qry.bindValue(":s_year",syear);
    qry.bindValue(":seva_date",devoteSevadate);
    qry.bindValue(":r_date",rday);
    qry.bindValue(":r_month",rmonth );
    qry.bindValue(":r_year",ryear );
    qry.bindValue(":receipt_date",devotereceiptdate);
    qry.bindValue(":s_time",sevatime);
    qry.bindValue(":seva_cost",devoteSevacharge);
    qry.bindValue(":additionalcost",devoteAdditionalcharges);
    qry.bindValue(":sevatotalprice",cost);
    qry.bindValue(":note",devoteNote );
    qry.bindValue(":cash", cash);
    qry.bindValue(":bank",bank_ref);
    qry.bindValue(":bankdetails",bank_name);
    qry.bindValue(":reference",reference);
    qry.bindValue(":status",status);
    qry.bindValue(":address",address);
    qry.bindValue(":momento",momento);
    qry.bindValue(":recpt_num",rcptNumI);

    bool retVal = qry.exec();
    if (!retVal){
        qDebug() << Q_FUNC_INFO << " sevabooking insert failed!" << qry.lastError().text() <<Qt::endl;
        return false;
    }else{
        qDebug() << Q_FUNC_INFO << " sevabooking insert Success!" << qry.lastError().text() <<Qt::endl;
    }

    qDebug()<<Q_FUNC_INFO<<"  exiting...\n";
    return true;
}

void DBInterface::insertVoucherIssued(VoucherElement *ele)
{
    QDate sevaDate = QDate::fromString(ele->voucherDate());
    QList<QString> li = ele->voucherDate().split("-");
    int smonth = li.at(1).toInt();
    int syear =li.at(0).toInt();
    qDebug()<<Q_FUNC_INFO<<ele->voucherDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"hereee"<<sevaDate<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<smonth<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<syear<<Qt::endl;
    QSqlQuery qry;
    qry.prepare("INSERT INTO VOUCHER_DETAILS(V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO,S_MONTH,S_YEAR)"
                "VALUES (:vno, :name, :payment_mode, :note, :phone, :product, :cost, :dates, :voucher_type, :reference_no, :s_month,:s_year)");
    qry.bindValue(":vno",ele->voucherNo());
    qry.bindValue(":name",ele->voucherName());
    qry.bindValue(":payment_mode",ele->voucherPaymentMode());
    qry.bindValue(":note",ele->voucherNote());
    qry.bindValue(":phone",ele->mobileNo());
    qry.bindValue(":product",ele->voucherItem());
    qry.bindValue(":cost",ele->voucherCost());
    qry.bindValue(":dates", ele->voucherDate());
    //qry.bindValue(":dates", sevaDate);
    qry.bindValue(":voucher_type", ele->voucherType());
    qry.bindValue(":reference_no",ele->receiptNumber());
    qry.bindValue(":s_month",smonth);
    qry.bindValue(":s_year",syear);
    bool retVal = qry.exec();
    if (!retVal){
        qWarning() << Q_FUNC_INFO << " Query Failed " << qry.lastError().text() <<Qt::endl;
    }
    qDebug()<<Q_FUNC_INFO<<"  exiting...\n";
}

int DBInterface::insertPersonDetails(QString devoteMobile,QString devoteName,QString devoteNakshatra,QString devoteGotra,QString address)
{
    qDebug() << Q_FUNC_INFO << " entered\n";

    bool found = false;
    int  personId = 0;

    qDebug() << Q_FUNC_INFO << " Name: " << devoteName << " Mobile: " << devoteMobile << "\n";

    QSqlQuery qry;

    QString stringQry = QString("select * from persondetails where mobile=%1").arg(devoteMobile.trimmed());
    qry.prepare(stringQry);
    bool result = qry.exec();
    qDebug() << Q_FUNC_INFO << " String to Query ="<<stringQry << Qt::endl;
    qDebug() << Q_FUNC_INFO << " Query Result =" << result << " Size =" << qry.size() << Qt::endl;
    if (!qry.next()){
        qry.clear();
        qDebug() << Q_FUNC_INFO << " Devotee not in table. Insert" << Qt::endl;
        QString lastRecord = "select * from persondetails";
        QSqlQuery qry1;
        qry1.prepare(lastRecord);
        qry1.exec();
        qDebug() << Q_FUNC_INFO << " Query Size =" << qry1.size() << Qt::endl;
        while(qry1.next()){
            int pId = qry1.value(0).toInt();
            if(pId > personId){
                personId = pId;
            }
        }
        ++personId;
        qDebug() << Q_FUNC_INFO << " Size =" << qry1.size() << " Person ID="<< personId << " Value ="<<qry1.value(0)<<Qt::endl;

        QSqlQuery qry;
        qry.prepare("INSERT INTO persondetails(SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE,ADDRESS)"
                    "VALUES (:sno, :person_name, :gothra, :nakshatra, :date, :mobile, :address)");
        qry.bindValue(":sno",personId);
        qry.bindValue(":person_name",devoteName);
        qry.bindValue(":gothra",devoteGotra);
        qry.bindValue(":nakshatra",devoteNakshatra );
        qry.bindValue(":date",QDate::currentDate().toString("dd-MMM-yyyy"));
        qry.bindValue(":mobile",devoteMobile);
        qry.bindValue(":address",address);
        if( qry.exec()){
            qDebug() << Q_FUNC_INFO << " Person insert success full"<< devoteMobile <<Qt::endl;
        }
    }else {
        qDebug() << Q_FUNC_INFO << " Devotee = " << devoteMobile << " exist in table ..." <<Qt::endl;
        //        while(qry.next())
        //        {
        personId=qry.value(0).toInt();
        QString mobileDB =qry.value(5).toString();
        QString nameDB=qry.value(1).toString();
        if(mobileDB == devoteMobile){
            found =true;
            qDebug()<<"Mobile number  " << devoteMobile << " is found\n";

            if( nameDB !=devoteName){
                qDebug()<<Q_FUNC_INFO<<" Devote names dont match\n";
                qDebug()<<Q_FUNC_INFO<<" Devote name in db is: "<<nameDB<<"    and in editor is: "<<devoteName<<"\n";

                QSqlQuery u_qry;
                u_qry.prepare("UPDATE persondetails SET PERSONNAME=:person_name,GOTHRA=:gothra,NAKSHATRA=:nakshatra WHERE MOBILE=:mobile");
                u_qry.bindValue(":mobile",devoteMobile);
                u_qry.bindValue(":person_name",devoteName);
                u_qry.bindValue(":gothra",devoteGotra);
                u_qry.bindValue(":nakshatra",devoteNakshatra );
                bool succ = u_qry.exec();
                if(succ)
                    qDebug()<<"\nSuccessfully updated person name to "<<devoteName<<"\n";
                else
                    qDebug()<<"\nUpdate of person name FAILED...\n";
            }
            //break;
            //}
        }
    }
    return personId;
}

int DBInterface::getLastReceiptNumber()
{
    //QString lastRecord = "select * from sevabooking ORDER BY SNO ASC LIMIT 1";
    QString lastRecord = "select SNO from sevabooking";

    int receiptNo=-1;
    QSqlQuery qry;
    //qry.prepare(lastRecord);
    qry.exec(lastRecord);

    while(qry.next()){
        qDebug() << Q_FUNC_INFO << " Found the last record element " <<Qt::endl;
        receiptNo = qry.value(0).toInt();
        qDebug() << Q_FUNC_INFO << " Found the last record element SevaName" <<qry.value(3).toString() << Qt::endl;
        qDebug() << Q_FUNC_INFO << " Found the last record element SNO" <<qry.value(0).toString() << Qt::endl;
    }
    qDebug() << Q_FUNC_INFO << " Size = " << qry.size() << " receiptNo ID = "<<receiptNo << " Value = " << qry.value(0) << Qt::endl;
    return receiptNo;
}

int DBInterface::getLastVoucherNumber()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    //QString lastRecord = "select * from sevabooking ORDER BY SNO ASC LIMIT 1";
    QString lastRecord = "select V_NO from VOUCHER_DETAILS";

    QSqlQuery qry;
    //qry.prepare(lastRecord);
    qry.exec(lastRecord);

    while(qry.next()){

        VID = qry.value(0).toInt();

    }
    qDebug() << VID<< Qt::endl;
    return VID+1;
}

int DBInterface::getLastSevatypeNumber()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    QString lastRecord = "select SEVACODE from seva";

    QSqlQuery qry;
    qry.exec(lastRecord);
    while(qry.next()){
        sevalastNo = qry.value(0).toInt();
    }
    qDebug() << sevalastNo<< Qt::endl;
    return sevalastNo+1;
}

int DBInterface::getLastSevaNameNumber()
{
    qDebug() << Q_FUNC_INFO <<Qt::endl;
}

void DBInterface::getvoucherdata()
{
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^1111111^^^^^^^^^^^^^^^^^^"<<Qt::endl;

    QList<QString> v_sno,v_date,v_name,v_phone,v_cost,v_voucherType,v_item ,v_paymentMode,v_note,v_refNo;
    QString str;
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^222222^^^^^^^^^^^^^^^^^^"<<Qt::endl;

    str = ("select * from VOUCHER_DETAILS;");
    QSqlQuery query_other1;
    query_other1.prepare(str);
    query_other1.exec();
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^3333333^^^^^^^^^^^^^^^^^^  " << query_other1.size() <<Qt::endl;

    while(query_other1.next()){
        qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^ Query DB for View^^^^^^^^^^^^^^^^^^"<<Qt::endl;
        VoucherElement *velement = new VoucherElement;

        QString vno = query_other1.value(0).toString();
        QString vname = query_other1.value(1).toString();
        QString vpaymntmode =query_other1.value(2).toString();
        QString vnote =query_other1.value(3).toString();
        QString vphone=query_other1.value(4).toString();

        velement->setVoucherNo(vno.toInt());
        velement->setVoucherName(vname);
        velement->setVoucherPaymentMode(vpaymntmode);
        velement->setVoucherNote(vnote);
        velement->setMobileNo(vphone);

        QString vproduct = query_other1.value(5).toString();
        QString  vcost = query_other1.value(6).toString();
        QString vqauntity =query_other1.value(7).toString();
        QString vtotal =query_other1.value(8).toString();
        QString vdate= query_other1.value(9).toString();
        QDate v_voucherdate = QDate::fromString(vdate,"yyyy-MM-dd");
        QString voucheDate = v_voucherdate.toString("dd-MM-yyyy");

        QString voucherType = query_other1.value(10).toString();
        QString v_referenceNo =  query_other1.value(11).toString();


        int v_day = query_other1.value(12).toInt();
        int  v_month = query_other1.value(13).toInt();

        velement->setVoucherCost(vcost);
        velement->setVoucherItem(vproduct);
        velement->setVoucherDate(voucheDate);
        velement->setVoucherType(voucherType);
        velement->setPaymentReference(v_referenceNo);

        v_sno.append(vno);
        v_date.append(voucheDate);
        v_name.append(vname);
        v_phone.append(vphone);
        v_note.append(vnote);
        v_cost.append(vcost);
        v_voucherType.append(voucherType);
        v_item.append(vproduct);
        v_paymentMode.append(vpaymntmode);
        v_refNo.append(v_referenceNo);
        emit sendVoucheronebyone(velement);
    }
}

void DBInterface::getAccountData()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

}

void DBInterface::deleteWrongData(QString rcptNum)
{
    qDebug()<<Q_FUNC_INFO<< rcptNum<<Qt::endl;
    QSqlQuery query;
    QString str;
    str =("delete from sevabooking where RECPT_NUM = '%1' ;");
    str= str.arg(rcptNum);
    query.prepare(str);
    bool b = query.exec();
    if(b==true){
        qDebug() << Q_FUNC_INFO <<"delete cmd executed....!"<<query.lastError().text()<<Qt::endl;
        emit refreshModel(rcptNum);
    }
    else{
        qDebug() << Q_FUNC_INFO <<"delete cmd failed....!"<<query.lastError().text()<<Qt::endl;
    }
}

void DBInterface::recvDeletedRecptNo(QString recptNo)
{
    qDebug() << Q_FUNC_INFO << " ::Receipt number :" << recptNo << Qt::endl;

    QSqlQuery query;
    QString str;
    //int num = recptNo.toInt();
    //qDebug() << Q_FUNC_INFO << " :: num :" << num << Qt::endl;
    const QString cmd = "canceled";
    str =("UPDATE sevabooking SET STATUS = '%1' WHERE RECPT_NUM = '%2' ;");
    str= str.arg(cmd).arg(recptNo);
    query.prepare(str);
    if(!query.exec()){
        qWarning() << Q_FUNC_INFO << "Update query for DB failed....!"<<query.lastError().text()<<Qt::endl;
        return;
    }

    if((query.numRowsAffected()) == -1)
    {
        qWarning() << Q_FUNC_INFO << "Update too DB failed....!"<<query.lastError().text()<<Qt::endl;
        emit updateToDbFailed();
    }
    else
    {
        qDebug() << Q_FUNC_INFO << "Update cmd executed....!" << query.lastError().text() << Qt::endl;
        emit sendChangedDataToSevaBookingTablemodel(recptNo);
    }
}


QList<SevaBookingElement *> DBInterface::getSewaBookingEntryForReceipt(QString receipt_no)
{
    QList<SevaBookingElement*> details ;

    QSqlQuery query;

    qDebug() << Q_FUNC_INFO <<"getSewaBookingEntryForReceipt Called receiptno is"<<receipt_no<<Qt::endl;
    query.prepare("SELECT * FROM sevabooking WHERE RECPT_NUM=:receipt_no");
    query.bindValue(":receipt_no", receipt_no);
    if(query.exec())
    {
        qDebug() << Q_FUNC_INFO <<"Retrieve Query executed in getSewaBookingEntryForReceipt"<<Qt::endl;
    }
    else
    {
        qWarning() << Q_FUNC_INFO <<"Retrieve Query exe..failed in getSewaBookingEntryForReceipt"<<Qt::endl;
    }

    while(query.next())
    {
        qDebug() << Q_FUNC_INFO <<"Inside getSewaBookingEntryForReceipt of DBInterface";
        SevaBookingElement *seva_ele = new SevaBookingElement;
        QString s_no=query.value(0).toString();
        QString person_id = query.value(1).toString();
        QString seva_type = query.value(2).toString();
        QString seva_name = query.value(3).toString();
        QString seva_quantity = query.value(4).toString();
        QString seva_cost = query.value(14).toString();
        QString seva_status = query.value(22).toString();

        qDebug() << Q_FUNC_INFO <<"s_no"<<s_no<<Qt::endl;
        qDebug()<<"person_id"<<person_id<<Qt::endl;
        qDebug()<<"seva_type"<<seva_type<<Qt::endl;
        qDebug()<<"seva_name"<<seva_name<<Qt::endl;
        qDebug()<<"seva_cost"<<seva_cost<<Qt::endl;
        qDebug()<<"Seva quantity "<<seva_quantity;
        qDebug()<<"Seva status in db "<<seva_status;

        seva_ele->setSno(s_no);
        seva_ele->setPerson_id(person_id);
        seva_ele->setSevatype(seva_type);
        seva_ele->setSevaname(seva_name);
        seva_ele->setSevacost(seva_cost);
        seva_ele->setStatus(seva_status);
        seva_ele->setQuantity(seva_quantity);
        details.append(seva_ele);
    }

    return details;
}

void DBInterface::modifySeva(int sevaId, QString sevaName, int cost, QString Date)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QSqlQuery query;
    QString str;
    qDebug()<<"suman--ModifysevaId--"<<sevaId<<Qt::endl;
    str =("UPDATE sevaname SET SEVANAME = '%1',SEVACOST= '%2',SEVADATE='%3' WHERE SNO = '%4' ;");
    str= str.arg(sevaName).arg(cost).arg(Date).arg(sevaId);
    query.prepare(str);
    bool b = query.exec();
    if(b==true){
        qDebug() << Q_FUNC_INFO <<"cost Update cmd executed....!"<<query.lastError().text()<<Qt::endl;
        emit sendUpdateStatus("The Seva id:"+QString::number(sevaId)+" Update Success");
    }
    else{
        qWarning() << Q_FUNC_INFO <<"cost Update cmd failed....!"<<query.lastError().text()<<Qt::endl;
    }

}

void DBInterface::closeSeva(int SevaId)
{
    qDebug() << Q_FUNC_INFO << SevaId  <<  Qt::endl;
    QSqlQuery query;
    QString str;
    QString cmd = "close";
    str =("UPDATE sevaname SET STATUS = '%1' WHERE SNO = '%2' ;");
    str= str.arg(cmd).arg(SevaId);
    query.prepare(str);
    bool b = query.exec();
    if(b==true){
        qDebug() << Q_FUNC_INFO <<"Seva Id /Seva name is closed....! ::Seva ID:"<< SevaId << query.lastError().text()<<Qt::endl;
        emit signalClose(SevaId);
        emit signalClosedStatus("The SevaId "+QString::number(SevaId)+" Closed");
    }
    else{
        qWarning() << Q_FUNC_INFO << "Seva Id /Seva name close query failed....! ::Seva ID:"<< SevaId << query.lastError().text()<<Qt::endl;
    }



    //    str = ("SELECT SEVATYPE from Sevaname");
    //    query.prepare(str);

}

void DBInterface::fullAccounDetailsDateWise(QString SEVA,int TYPE,QString formatchangedcalendar_str)
{
    qDebug()<<Q_FUNC_INFO<<"1 "<<SEVA<<"2 "<<TYPE<<"3 "<<formatchangedcalendar_str<<Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if(TYPE == 0){
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1';");
        que1 = que1.arg(formatchangedcalendar_str);
    }
    else if(SEVA == ALLSEVANAME){
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2';");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else{
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2 and sevabooking.SEVANAME = '%3';");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }
    query_other1.prepare(que1);
    bool test = query_other1.exec();
    if(test == true){
        qDebug() << "test executed";
    }else{
        qWarning() << "test not executed";
    }
    while(query_other1.next()){
        qDebug()<<"test inside date while"<<Qt::endl;
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
}

void DBInterface::fullAccounDetailsDateRangeWise(QString SEVA,int TYPE ,QString seva_Startdate,QString seva_Enddate)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"1 "<<SEVA<<"2 "<<TYPE<<"3 "<<seva_Startdate<<" 4"<<seva_Enddate <<Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if(TYPE == 0){
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE between '%1' and '%2';");
        que1 = que1.arg(seva_Startdate).arg(seva_Enddate);
    }
    else if(SEVA == ALLSEVANAME){
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3';");
        que1 = que1.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else{
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4';");
        que1 = que1.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    query_other1.prepare(que1);
    bool test = query_other1.exec();
    if(test==true){
        qDebug()<<"test executed";
    }else{
        qDebug()<<"test not executed";
    }
    while(query_other1.next()){
        qDebug()<<"test inside range while"<<Qt::endl;
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
}

void DBInterface::fullAccounDetailsMonthwise(QString SEVA,int TYPE,int month,int year)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    qDebug() << Q_FUNC_INFO << "1 " << SEVA << "2 " << TYPE << "3 " << month << " 4" << year << Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if(TYPE == 0){
        qDebug() << "temple First" << Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2';");
        que1 = que1.arg(month).arg(year);
    }
    else if(SEVA == ALLSEVANAME){
        qDebug()<<"temple second"<<Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3';");
        que1 = que1.arg(month).arg(year).arg(TYPE);
    }
    else{
        qDebug()<<"temple 3rd"<<Qt::endl;
        que1 = ("select sevabooking.SNO,sevabooking.RECEIPT_DATE,sevabooking.SEVA_DATE,sevabooking.SEVANAME,sevabooking.SEVACOST,sevabooking.QUANTITY,persondetails.PERSONNAME,persondetails.MOBILE,sevabooking.BANK,sevabooking.SEVATOTALPRICE,sevabooking.ADDITIONALCOST,sevabooking.STATUS from sevabooking  INNER JOIN persondetails ON sevabooking.PERSONID=persondetails.SNO where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4';");
        que1 = que1.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    query_other1.prepare(que1);
    bool test = query_other1.exec();
    if(test==true){
        qDebug()<<"test executed";
    }else{
        qDebug()<<"test not executed";
    }
    while(query_other1.next()){
        qDebug() << "test inside month while" << Qt::endl;
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
        qDebug() << query_other1.value(0).toString()<<Qt::endl;
        qDebug() << query_other1.value(1).toString()<<Qt::endl;
        qDebug() << query_other1.value(2).toString()<<Qt::endl;
        qDebug() << query_other1.value(3).toString()<<Qt::endl;
        qDebug() << query_other1.value(4).toString()<<Qt::endl;
        qDebug() << query_other1.value(5).toString()<<Qt::endl;
        qDebug() << query_other1.value(6).toString()<<Qt::endl;
        qDebug() << query_other1.value(7).toString()<<Qt::endl;
        qDebug() << query_other1.value(8).toString()<<Qt::endl;
        qDebug() << query_other1.value(9).toString()<<Qt::endl;
        emit sendFullAccountDataElement(felement);
    }
    qDebug()<<"Hello world!"<<Qt::endl;
}

void DBInterface::to_persondetails_db(QString devoteMobile,QString devoteName,QString devoteNakshatra,QString devoteGotra,QString devoteSevacharge,QString devoteAdditionalcharges,QString devoteCount,QString devotereceiptdate,QString devoteSevadate,QString devoteNote)
{
    //    devoteAdditionalcharges,QString devoteCount,QString devotereceiptdate,QString devoteSevadate,QString devoteNote)
    Q_UNUSED(devoteSevacharge)
    Q_UNUSED(devoteAdditionalcharges)
    Q_UNUSED(devoteCount)
    Q_UNUSED(devoteSevadate)
    Q_UNUSED(devoteNote)
    qDebug() << Q_FUNC_INFO << " entered\n";
    bool found =false;
    qDebug() << " Name: " << devoteName << " Mobile: " << devoteMobile <<"\n";
    QSqlQuery qry;
    qry.prepare("select * from persondetails");
    qry.exec();
    int personserilaNumber=-1;
    while(qry.next())
    {
        int personSNO = qry.value(0).toInt();
        QString val1 = qry.value(5).toString();
        QString val2 = qry.value(1).toString();
        if(personSNO > personserilaNumber){
            personserilaNumber = personSNO;
        }

        if(val1==devoteMobile)
        {
            found = true;
            qDebug() << "Mobile number  " << devoteMobile << " is found\n";

            if(val2!=devoteName)
            {
                qDebug()<<Q_FUNC_INFO<<"Devote names dont match\n";
                qDebug()<<Q_FUNC_INFO<<"Devote name in db is: "<<val2<<"    and in editor is: "<<devoteName<<"\n";

                QSqlQuery u_qry;
                u_qry.prepare("UPDATE persondetails SET PERSONNAME=:person_name,GOTHRA=:gothra,NAKSHATRA=:nakshatra WHERE MOBILE=:mobile");
                u_qry.bindValue(":mobile",devoteMobile);
                u_qry.bindValue(":person_name",devoteName);
                u_qry.bindValue(":gothra",devoteGotra);
                u_qry.bindValue(":nakshatra",devoteNakshatra );
                bool succ = u_qry.exec();
                if(succ)
                    qDebug()<<"\nSuccessfully updated person name to "<<devoteName<<"\n";
                else
                    qDebug()<<"\nUpdate of person name FAILED...\n";
            }
            break;
        }
    }
    if(!found)
    {
        qDebug()<<"Mobile number  "<<devoteMobile<<" is  NOT  found\n";

        RID = RID +1;

        qDebug()<<" Person id: "<<RID<<"\n";

        QSqlQuery qry;
        qry.prepare("INSERT INTO persondetails(SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE)"
                    "VALUES (:sno, :person_name, :gothra, :nakshatra, :date, :mobile)");
        qry.bindValue(":sno",++personserilaNumber);
        qry.bindValue(":person_name",devoteName);
        qry.bindValue(":gothra",devoteGotra );
        qry.bindValue(":nakshatra",devoteNakshatra );
        qry.bindValue(":date",devotereceiptdate );
        qry.bindValue(":mobile",devoteMobile);
        qDebug() << Q_FUNC_INFO <<devoteName;
        qDebug() << Q_FUNC_INFO <<devoteGotra;
        qDebug() << Q_FUNC_INFO <<devoteNakshatra;
        qDebug() << Q_FUNC_INFO <<devoteMobile;
        if( qry.exec()){
        };
    }
}

bool DBInterface::check_sevaname_allreadyexist(int sevatype, QString sevaName, int seva_cost, QString str_date, QString seva_adder_name,int prasada,QString pooja_time,int pooja)
{
    QMessageBox msgbox;
    bool found =false;
    QSqlQuery qry;
    qDebug()<<"Inside check_sevaname_allreadyexist "<<Qt::endl;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON from sevaname ");
    qry.exec();
    while(qry.next()){
        SID =qry.value(0).toInt();
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<val2<<Qt::endl;

        if((val1.compare(sevaName)==0)&&(sevatype==val2))
        {
            found =true;
            break;
        }
    }
    if(!found)
    {

        this->check_name_db(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
        emit seva_Name(sevatype,sevaName,seva_cost,str_date,seva_adder_name,prasada,pooja_time,pooja);
        msgbox.setText("SEVA NAME ADDED SUCCESSFULLY");
        msgbox.exec();
    }
    else
    {
        msgbox.setText("SEVA TYPE IS ALREADY EXISTS");
        msgbox.exec();
    }
    return found;
}

void DBInterface::seva_modification_testing(int sno, int new_sevarow, QString new_seva_nmae, int new_seva_cost, QString new_date, QString sevamodifairname, int mod_theertha_prasada, QString modifaid_ptime, int modifaidpooja, QString old_seva_name, QString old_seva_type)
{
    QString sevaname;
    int seva_type_size =new_seva_nmae.size();
    int s_no;
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM  sevaname");
    query_other.exec();
    while(query_other.next())
    {
        sevaname = query_other.value(1).toString();
        QString sevat = query_other.value(2).toString();
        if(old_seva_name==sevaname && sevat==old_seva_type)
        {
            s_no=query_other.value(0).toInt();
        }
    }
    QString s_seva_name=new_seva_nmae;
    int s_seva_cost=new_seva_cost;
    qDebug()<<Q_FUNC_INFO<<new_seva_nmae<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<new_seva_cost<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<sno<<Qt::endl;
    QMessageBox msgbox;
    if((new_seva_cost<0)||(seva_type_size<2))
    {
        msgbox.setText(tr("PLEASE ENTER ALL THE FIELDS"));
        msgbox.exec();
        return;
    }
    emit modifying_seva(sno,new_sevarow,new_seva_nmae,new_seva_cost,new_date,sevamodifairname,mod_theertha_prasada,modifaid_ptime,modifaidpooja);
    this->modify_db_seva(s_no,s_seva_name,s_seva_cost,old_seva_type,new_date,sevamodifairname,mod_theertha_prasada,modifaid_ptime,modifaidpooja);
}

void DBInterface::combobox_sevatype()
{
    QList<QString> list_sevatype;

    list_sevatype.clear();
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM seva");
    query_other.exec();
    while(query_other.next())
    {
        QString str = query_other.value(1).toString();
        list_sevatype.append(str);
    }
    emit seva_type(list_sevatype);
}

void DBInterface::getdata()
{
    QSqlQuery qry;
    qry.prepare("select SNO,SEVATYPE,SEVACODE,PERSON from seva ");
    qry.exec();
    while(qry.next()){
        QString s_no=qry.value(0).toString();
        QString seva_name=qry.value(1).toString();
        QString seva_code=qry.value(2).toString();
        QString seva_adder_name=qry.value(3).toString();
        qDebug()<<Q_FUNC_INFO<<s_no<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<seva_name<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<seva_code<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<seva_adder_name<<Qt::endl;
        emit get_data_db(s_no,seva_name,seva_code,seva_adder_name);
    }
}

bool DBInterface::dbtable_view()
{
    qDebug()<<Q_FUNC_INFO<<"Getting all seva booking details for table view"<<Qt::endl;
    //QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note,l_cash,l_bank,l_BankDeatils,l_Ref,l_status,l_add,l_momento;
    QString str;
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^222222^^^^^^^^^^^^^^^^^^"<<Qt::endl;
    //str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS,REFERENCE,STATUS,ADDRESS,MOMENTO,RECPT_NUM from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    bool queryResult = query_other1.exec();
    if(queryResult == false)
    {
        qWarning() << Q_FUNC_INFO << "query is failed" << Qt::endl;
        return false;
    }
    qDebug() << Q_FUNC_INFO << " Query  is successful and size : " << query_other1.size() <<Qt::endl;

    while(query_other1.next()){
        qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^ Query DB for View^^^^^^^^^^^^^^^^^^"<<Qt::endl;
        SevaBookingElement *elem = new SevaBookingElement;
        QString sno = query_other1.value(0).toString();
        QString person_id = query_other1.value(1).toString();
        QString sevatype =query_other1.value(2).toString();
        QString sevaname =query_other1.value(3).toString();
        QString quantity=query_other1.value(4).toString();

        elem->setSno(query_other1.value(24).toString());
        elem->setPerson_id(person_id);
        elem->setSevatype(sevatype);
        elem->setSevaname(sevaname);
        elem->setQuantity(quantity);

        QString s_date = query_other1.value(5).toString();
        QString s_month = query_other1.value(6).toString();
        QString s_year =query_other1.value(7).toString();
        QString realformatsevadate =query_other1.value(8).toString();
        QDate sevadateDate = QDate::fromString(realformatsevadate,"yyyy-MM-dd");
        QString sevadate = sevadateDate.toString("dd-MM-yyyy");

        QString r_date = query_other1.value(9).toString();
        QString r_month = query_other1.value(10).toString();
        QString r_year =query_other1.value(11).toString();
        QString realformatreceiptdate =query_other1.value(12).toString();
        QDate receiptdateDate = QDate::fromString(realformatreceiptdate,"yyyy-MM-dd");
        QString receiptdate = receiptdateDate.toString("dd-MM-yyyy");

        elem->setSevaDate(sevadate);
        elem->setReceiptDate(receiptdate);

        QString seva_cost =query_other1.value(13).toString();
        QString add_cost=query_other1.value(14).toString();
        QString total_cost=query_other1.value(15).toString();
        QString note=query_other1.value(16).toString();
        QString cash = query_other1.value(17).toString();
        QString bank =query_other1.value(18).toString();
        elem->setSevacost(seva_cost);
        elem->setTotalCost(total_cost);
        elem->setCash(cash);
        elem->setBank(bank);

        QString bankDetails =query_other1.value(19).toString();
        QString reference =query_other1.value(20).toString();
        QString status= query_other1.value(21).toString();
        QString add =query_other1.value(22).toString();
        QString momento =query_other1.value(23).toString();

        elem->setBankName(bankDetails);
        elem->setReference(reference);
        elem->setStatus(status);
        elem->setMomento(momento);
        elem->setAddress(add);

        l_sno.append(sno);
        l_person_id.append(person_id);
        l_sevatype.append(sevatype);
        l_sevaname.append(sevaname);
        l_quantity.append(quantity);
        l_s_date.append(s_date);
        l_s_month.append(s_month);
        l_s_year.append(s_year);
        l_sevadate.append(sevadate);
        l_r_date.append(r_date);
        l_r_month.append(r_month);
        l_r_year.append(r_year);
        l_receiptdate.append(receiptdate);
        l_seva_cost.append(seva_cost);
        l_add_cost.append(add_cost);
        l_total_cost.append(total_cost);
        l_note.append(note);

        l_cash.append(cash);
        l_bank.append(bank);
        l_BankDeatils.append(bankDetails);
        l_Ref.append(reference);
        l_status.append(status);
        l_add.append(add);
        l_momento.append(momento);

        // Deleted later.
        DevotePersnalDetails  *devotee = getPersonDetails(elem->person_id());

        elem->setPerson(devotee);
        emit sendOneSevaBooking(elem);
    }
    qDebug() << Q_FUNC_INFO << "Successfull on getting the seva booked data " << Qt::endl;
    return true;
}

void DBInterface::getDbData()
{
    qDebug()<<Q_FUNC_INFO<<"Getting the  DB data "<<Qt::endl;

    //QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note,l_cash,l_bank,l_BankDeatils,l_Ref,l_add,l_momento;
    QString str;
    //str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS,REFERENCE,ADDRESS,MOMENTO from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    bool queryResult = query_other1.exec();
    if(queryResult == false)
    {
        qDebug() << Q_FUNC_INFO << "query is failed" <<Qt::endl;
        return ;
    }
    qDebug() << Q_FUNC_INFO << "Query is successful " << query_other1.size() << Qt::endl;

    while(query_other1.next()){
        qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^ Query DB for View^^^^^^^^^^^^^^^^^^"<<Qt::endl;
        SevaBookingElement *elem = new SevaBookingElement;
        QString sno = query_other1.value(0).toString();
        QString person_id = query_other1.value(1).toString();
        QString sevatype =query_other1.value(2).toString();
        QString sevaname =query_other1.value(3).toString();
        QString quantity=query_other1.value(4).toString();

        elem->setSno(sno);
        elem->setPerson_id(person_id);
        elem->setSevatype(sevatype);
        elem->setSevaname(sevaname);
        elem->setQuantity(quantity);

        QString s_date = query_other1.value(5).toString();
        QString  s_month = query_other1.value(6).toString();
        QString s_year =query_other1.value(7).toString();
        QString realformatsevadate =query_other1.value(8).toString();
        QDate sevadateDate = QDate::fromString(realformatsevadate,"yyyy-MM-dd");
        QString sevadate = sevadateDate.toString("dd-MM-yyyy");

        QString r_date = query_other1.value(9).toString();
        QString  r_month = query_other1.value(10).toString();
        QString r_year =query_other1.value(11).toString();
        QString realformatreceiptdate =query_other1.value(12).toString();
        QDate receiptdateDate = QDate::fromString(realformatreceiptdate,"yyyy-MM-dd");
        QString receiptdate = receiptdateDate.toString("dd-MM-yyyy");

        elem->setSevaDate(sevadate);
        elem->setReceiptDate(receiptdate);

        QString seva_cost =query_other1.value(13).toString();
        QString add_cost=query_other1.value(14).toString();
        QString total_cost=query_other1.value(15).toString();
        QString note=query_other1.value(16).toString();
        QString cash = query_other1.value(17).toString();
        QString bank =query_other1.value(18).toString();

        elem->setTotalCost(total_cost);
        elem->setCash(cash);
        elem->setBank(bank);

        QString bankDetails =query_other1.value(19).toString();
        QString reference =query_other1.value(20).toString();
        QString add =query_other1.value(21).toString();
        QString momento =query_other1.value(22).toString();

        elem->setReference(reference);
        elem->setMomento(momento);
        elem->setAddress(add);
        l_sno.append(sno);
        l_person_id.append(person_id);
        l_sevatype.append(sevatype);
        l_sevaname.append(sevaname);
        l_quantity.append(quantity);
        l_s_date.append(s_date);
        l_s_month.append(s_month);
        l_s_year.append(s_year);
        l_sevadate.append(sevadate);
        l_r_date.append(r_date);
        l_r_month.append(r_month);
        l_r_year.append(r_year);
        l_receiptdate.append(receiptdate);
        l_seva_cost.append(seva_cost);
        l_add_cost.append(add_cost);
        l_total_cost.append(total_cost);
        l_note.append(note);

        l_cash.append(cash);
        l_bank.append(bank);
        l_BankDeatils.append(bankDetails);
        l_Ref.append(reference);
        l_add.append(add);
        l_momento.append(momento);

        // Deleted later.
        DevotePersnalDetails  *devotee = getPersonDetails(elem->person_id());

        elem->setPerson(devotee);
        emit sendoneByoneSevaBooking(elem);
    }
    qDebug()<<Q_FUNC_INFO<<"Completed the fetching the DB data"<<Qt::endl;
    return;
}

void DBInterface::getpersondetails(QString person_id)
{
    qDebug()<<Q_FUNC_INFO<<"   called\n";
    m_person = new PersonDetails;

    QString id,person_name,gotra,nakshatra,date,mobile;//,email;
    QString newstr = QString("select SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE from persondetails where SNO==%1;").arg(person_id);
    QSqlQuery query;
    query.prepare(newstr);
    bool suc = query.exec();

    if(suc)
        qDebug()<<"\nQuery Execution successful\n";
    while(query.next())
    {

        QString id = query.value(0).toString();
        if(id==person_id)
        {
            id = query.value(0).toString();
            person_name = query.value(1).toString();
            gotra =query.value(2).toString();
            nakshatra =query.value(3).toString();
            date=query.value(4).toString();
            mobile = query.value(5).toString();
            m_person->NAME =person_name;
            m_person->MOB_NO =mobile;
            m_person->GOTHRA =gotra;
            m_person->NAKSHATRA =person_name;
        }

        qDebug()<<"Person name is "<<person_name<<Qt::endl;
        qDebug()<<"Mobile no. is "<<mobile<<Qt::endl;

        emit persondetails(id,person_name,gotra,nakshatra,date,mobile);
    }
}

DevotePersnalDetails* DBInterface::getPersonDetails(QString person_id)
{
    qDebug()<<Q_FUNC_INFO<<"   called\n";
    DevotePersnalDetails *person = new DevotePersnalDetails;

    QString id,person_name,gotra,nakshatra,date,mobile;//,email;
    QString newstr = QString("select SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE from persondetails where SNO==%1;").arg(person_id);
    QSqlQuery query;
    query.prepare(newstr);
    bool suc = query.exec();
    person->setPersonDbId(person_id);

    if(suc){
        qDebug()<<Q_FUNC_INFO << "\nQuery Execution successful\n" <<Qt::endl;
    } else {
        qWarning() << Q_FUNC_INFO << " Query failed..." <<Qt::endl;
        return person;
    }
    while(query.next()) {
        QString id = query.value(0).toString();
        if(id==person_id) {
            id = query.value(0).toString();
            person_name = query.value(1).toString();
            gotra =query.value(2).toString();
            nakshatra =query.value(3).toString();
            date=query.value(4).toString();
            mobile = query.value(5).toString();
            person->setDevoteeName(person_name);
            person->setMobileNumber(mobile);
            person->setGothra(gotra);
            person->setNakshatra(nakshatra);
            break;
        }
    }
    return person;
}

bool DBInterface::saveData(QObject *obj)
{
    qDebug() << Q_FUNC_INFO << " Inserting the data into DB"<<Qt::endl;
    bool b = false;
    SevaBookingConformationDataModel *sevaData = qobject_cast<SevaBookingConformationDataModel*>(obj);
    MySevaReceipt *rec = sevaData->sevaReceipt();
    if(rec->paymentMode()=="Cash"){
        rec->setBank("");
    }
    qDebug() << Q_FUNC_INFO << " ****8888 NOte =" << rec->note() <<Qt::endl;
    qDebug() << Q_FUNC_INFO << rec->gothra() << Qt::endl;
    // to Test ---------
    QSqlQuery qry;
    QString que;
    que = ("select * from sevabooking where sevabooking.SNO = '%1';");
    QStringList recieptNumber=rec->receiptNo().split("_");
    QString rcptNo=rec->receiptNo();
    int rcptNum=recieptNumber[2].toInt();
    qDebug()<<"The reciept number: "<<rcptNum<<Qt::endl;

    que = que.arg(rec->receiptNo());
    qry.prepare(que);
    qry.exec();

    if(qry.next())
    {
        qDebug() << Q_FUNC_INFO <<  "Add ####Inside if ######## =" << Qt::endl;
        //        l_sevaname=qry.value(1).toString();
        //        sevacost=qry.value(3).toInt();
        //        if(sevaname==l_sevaname)
        //        {
        //            emit sevadetails(l_sevaname,sevacost);
        //        }
        return false;
    }
    // to Test --------
    QList<SevaName*> sevas = sevaData->sevabookinglist();
    Q_ASSERT(sevaData != nullptr);
    for(int i = 0;i < sevas.size();i++){
        SevaName *seva = sevas.at(i);
        qDebug() << Q_FUNC_INFO <<  "Add ############ ="<< seva->additionalCost() << Qt::endl;
        b =   this->insertSevaBooked(rcptNo,rec->mobilenumber(),rec->devoteeName(),
                                   rec->nakshtra(),rec->gothra(),
                                   QString::number(seva->sevaCost()),QString::number(seva->additionalCost()),
                                   QString::number(seva->count()),rec->receiptDate(),
                                   seva->sevaStartDate(),rec->note(),
                                   seva->sevaName(),(seva->sevaCost()*seva->count())+seva->additionalCost(),
                                   rcptNum,rec->cash(),
                                   rec->paymentMode(),rec->bank(),
                                   QString("%1").arg(seva->sevaType()),
                                   rec->checkOrTranscationId(),rec->bookingStatus(),rec->address(),rec->momento(),QString("%1").arg(seva->sevaStartTime()));
        qDebug() << Q_FUNC_INFO << " Inserting the data in for loop into DB b is "<<b<<Qt::endl;
    }
    qDebug() << Q_FUNC_INFO << " Inserting the data into DB b is "<<b<<Qt::endl;
    return b;
}

void DBInterface::getsevadetails(QString sevaname)
{
    QSqlQuery qry;
    qry.prepare("select * from sevaname");
    qry.exec();
    QString l_sevaname;
    int sevacost;
    while(qry.next())
    {
        l_sevaname=qry.value(1).toString();
        sevacost=qry.value(3).toInt();
        if(sevaname==l_sevaname)
        {
            emit sevadetails(l_sevaname,sevacost);
        }
    }
}

void DBInterface::canceleDatasevabookingentry(int s_no, QString sevaname,QString note)
{
    QSqlQuery qry;
    qDebug()<<Q_FUNC_INFO<<"  seva_name is: "<<sevaname<<Qt::endl;
    qry.prepare("UPDATE sevabooking SET NOTE=:note WHERE SNO=:sno AND SEVANAME=:sevaname;");
    qry.bindValue(":sno",s_no);
    qry.bindValue(":note",note);
    qry.bindValue(":sevaname",sevaname);

    qDebug()<<Q_FUNC_INFO<< qry.executedQuery() <<Qt::endl;

    bool suc = qry.exec();

    if(suc)
        qDebug()<<Q_FUNC_INFO<<"  Successfully cancelled\n";
    else
        qDebug()<<Q_FUNC_INFO<<"  Failed to be cancelled\n";
}

void DBInterface::get_sevabooking_modifying(int s_no,int count,int s_date,int s_month,int s_year, QString sevadate,int sevacharge,int addcharg,int total, QString note ,QString seva_name )
{
    QSqlQuery qry;
    qDebug()<<Q_FUNC_INFO<<"  Quantity is: "<<count<<Qt::endl;

    qDebug()<<Q_FUNC_INFO<<"  seva_name is: "<<seva_name<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"  Date, month, year and seva date:  "<<s_date<<s_month<<s_year<<sevadate<<Qt::endl;

    qry.prepare("UPDATE sevabooking SET SNO=:sno,QUANTITY=:count,S_DATE=:s_date,S_MONTH=:s_month,S_YEAR=:s_year,SEVA_DATE=:sevadate,SEVACOST=:seva_cost,ADDITIONALCOST=:add_cost,SEVATOTALPRICE =:total_price,NOTE=:note WHERE SNO=:sno AND SEVANAME=:sevaname;");
    qry.bindValue(":sno",s_no);
    qry.bindValue(":count",count);
    qry.bindValue(":s_date",s_date);
    qry.bindValue(":s_month",s_month);
    qry.bindValue(":s_year",s_year);
    qry.bindValue(":sevadate",sevadate);
    qry.bindValue(":seva_cost",sevacharge);
    qry.bindValue(":add_cost",addcharg);
    qry.bindValue(":total_price",total);
    qry.bindValue(":note",note);
    qry.bindValue(":sevaname",seva_name);

    qDebug()<<Q_FUNC_INFO<< qry.executedQuery() <<Qt::endl;

    bool suc = qry.exec();

    if(suc)
        qDebug()<<Q_FUNC_INFO<<"  Successfully modified\n";
    else
        qDebug()<<Q_FUNC_INFO<<"  Failed to be modified\n";

    qDebug()<<Q_FUNC_INFO<<"  Quantity is: "<<count<<Qt::endl;
}

void DBInterface::table_view_forlast_ten_tran()
{

    qDebug()<<Q_FUNC_INFO<<"welcome all"<<Qt::endl;
    QList<QString> m_sno,m_person_id,m_sevatype,m_sevaname,m_quantity,m_s_date,m_s_month,m_s_year,m_sevadate,m_r_date,m_r_month,m_r_year,m_receiptdate,m_seva_cost,m_add_cost,m_total_cost,m_note;

    m_sno.clear();
    m_person_id.clear();
    m_sevatype.clear();
    m_sevaname.clear();
    m_quantity.clear();
    m_s_date.clear();
    m_s_month.clear();
    m_s_year.clear();
    m_sevadate.clear();
    m_r_date.clear();
    m_r_month.clear();
    m_r_year.clear();
    m_receiptdate.clear();
    m_seva_cost.clear();
    m_add_cost.clear();
    m_total_cost.clear();
    m_note.clear();

    QSqlQuery query_other5;
    query_other5.prepare("SELECT * FROM (SELECT SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE FROM sevabooking ORDER BY ROWID DESC LIMIT 10 ) t1 ORDER BY t1.SNO ASC");
    query_other5.exec();
    while(query_other5.next())
    {
        qDebug()<<Q_FUNC_INFO<<"welcome all22"<<Qt::endl;
        QString sno = query_other5.value(0).toString();
        QString  person_id = query_other5.value(1).toString();
        QString sevatype =query_other5.value(2).toString();
        QString sevaname =query_other5.value(3).toString();
        QString quantity=query_other5.value(4).toString();
        QString s_date = query_other5.value(5).toString();
        QString  s_month = query_other5.value(6).toString();
        QString s_year =query_other5.value(7).toString();
        QString realformatsevadate =query_other5.value(8).toString();
        QDate sevadateDate = QDate::fromString(realformatsevadate,"yyyy-MM-dd");
        QString sevadate = sevadateDate.toString("dd-MM-yyyy");
        QString r_date= query_other5.value(9).toString();
        QString  r_month = query_other5.value(10).toString();
        QString r_year =query_other5.value(11).toString();
        QString realformatreceiptdate =query_other5.value(12).toString();
        QDate receiptdateDate = QDate::fromString(realformatreceiptdate,"yyyy-MM-dd");
        QString receiptdate = receiptdateDate.toString("dd-MM-yyyy");
        QString seva_cost =query_other5.value(13).toString();
        QString add_cost=query_other5.value(14).toString();
        QString total_cost=query_other5.value(15).toString();
        QString note=query_other5.value(16).toString();

        m_sno.append(sno);
        m_person_id.append(person_id);
        m_sevatype.append(sevatype);
        m_sevaname.append(sevaname);
        m_quantity.append(quantity);
        m_s_date.append(s_date);
        m_s_month.append(s_month);
        m_s_year.append(s_year);
        m_sevadate.append(sevadate);
        m_r_date.append(r_date);
        m_r_month.append(r_month);
        m_r_year.append(r_year);
        m_receiptdate.append(receiptdate);
        m_seva_cost.append(seva_cost);
        m_add_cost.append(add_cost);
        m_total_cost.append(total_cost);
        m_note.append(note);
    }
    emit forlasttenDetails(m_sno,m_person_id,m_sevatype,m_sevaname,m_quantity,m_s_date,m_s_month,m_s_year ,m_sevadate,m_r_date,m_r_month,m_r_year,m_receiptdate,m_seva_cost,m_add_cost,m_total_cost,m_note);
}

void DBInterface::print_data_db(int seva_Type)
{
    QList<QString> list_s_no,list_seva_name,list_seva_type,list_seva_cost,list_seva_date,list_seva_adder_name,list_prasada,list_pooja_time,list_pooja;
    qDebug()<<"coming to "<<Q_FUNC_INFO <<Qt::endl;
    list_s_no.clear();
    list_seva_name.clear();
    list_seva_type.clear();
    list_seva_cost.clear();
    list_seva_date.clear();
    list_seva_adder_name.clear();
    list_prasada.clear();
    list_pooja_time.clear();
    list_pooja.clear();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM sevaname");
    qry.exec();
    while(qry.next())
    {
        int val = qry.value(2).toInt();
        if(seva_Type == 0)//regular seva at 1st index in combo
        {
            qDebug()<<"comming"<<seva_Type<<Qt::endl;
            QString s_no=qry.value(0).toString();
            QString seva_name=qry.value(1).toString();
            QString seva_type=qry.value(2).toString();
            QString seva_cost=qry.value(3).toString();
            QString seva_date_real=qry.value(4).toString();
            QDate Dateseva_date = QDate::fromString(seva_date_real,"yyyy-MM-dd");
            QString seva_date = Dateseva_date.toString("dd-MM-yyyy");
            QString seva_adder_name=qry.value(5).toString();
            QString prasada=qry.value(6).toString();
            QString pooja_time=qry.value(7).toString();
            QString pooja=qry.value(8).toString();
            list_s_no.append(s_no);
            list_seva_name.append(seva_name);
            list_seva_type.append(seva_type);
            list_seva_cost.append(seva_cost);
            list_seva_date.append(seva_date);
            list_seva_adder_name.append(seva_adder_name);
            list_prasada.append(prasada);
            list_pooja_time.append(pooja_time);
            list_pooja.append(pooja);
        }

        if(val == seva_Type)//regular seva at 1st index in combo
        {
            qDebug()<<"comming"<<seva_Type<<Qt::endl;
            QString s_no=qry.value(0).toString();
            QString seva_name=qry.value(1).toString();
            QString seva_type=qry.value(2).toString();
            QString seva_cost=qry.value(3).toString();
            QString seva_date_real=qry.value(4).toString();
            QDate Dateseva_date = QDate::fromString(seva_date_real,"yyyy-MM-dd");
            QString seva_date = Dateseva_date.toString("dd-MM-yyyy");
            QString seva_adder_name=qry.value(5).toString();
            QString prasada=qry.value(6).toString();
            QString pooja_time=qry.value(7).toString();
            QString pooja=qry.value(8).toString();
            list_s_no.append(s_no);
            list_seva_name.append(seva_name);
            list_seva_type.append(seva_type);
            list_seva_cost.append(seva_cost);
            list_seva_date.append(seva_date);
            list_seva_adder_name.append(seva_adder_name);
            list_prasada.append(prasada);
            list_pooja_time.append(pooja_time);
            list_pooja.append(pooja);
        }
    }
    emit sevaname(list_s_no,list_seva_name,list_seva_type,list_seva_cost,list_seva_date,list_seva_adder_name,list_prasada,list_pooja_time,list_pooja);
}

void DBInterface::seva_type_adding()
{
    QList<QString> list_sevatypes;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM seva");
    qry.exec();
    while(qry.next())
    {
        QString sevaType = qry.value(1).toString();
        list_sevatypes.append(sevaType);
        qDebug()<<Q_FUNC_INFO<<sevaType;
    }
    emit seva_types_adding(list_sevatypes);

}

void DBInterface::seva_name_adding(int sevaT)
{
    QList<QString> list_seva_name;
    list_seva_name.clear();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM sevaname");
    qry.exec();
    while(qry.next())
    {
        int sevaType = qry.value(2).toInt();
        if(sevaT==0)
        {
            list_seva_name.append("ALL SEVA NAME");
            break;
        }
        if(sevaT==sevaType)
        {
            QString sevaname = qry.value(1).toString();
            list_seva_name.append(sevaname);

        }
    }
    emit sevaName(list_seva_name);
}

DevotePersnalDetails* DBInterface::mobileNumberSearching(QString mobile_num)
{
    qDebug()<<"mobile_number searching"<<  mobile_num<<Qt::endl;

    DevotePersnalDetails* devotee = new DevotePersnalDetails;
    QSqlQuery qry;
    qry.prepare("select * from persondetails");
    qry.exec();
    while(qry.next()){
        RID =qry.value(0).toInt();
        QString  d_Mobile= qry.value(5).toString().trimmed();
        if(mobile_num==d_Mobile){
            QString  d_Name =qry.value(1).toString().trimmed();
            QString  d_Gotra = qry.value(2).toString().trimmed();
            QString  d_Nakshatra =qry.value(3).toString().trimmed();
            QString  d_receiptdate = qry.value(4).toString().trimmed();
            devotee->setDevoteeName(d_Name);
            devotee->setNakshatra(d_Nakshatra);
            devotee->setGothra(d_Gotra);
            devotee->setMobileNumber(d_Mobile);
            devotee->print();
            break;
        }else {
            qDebug() << Q_FUNC_INFO << " Devotee is new " <<Qt::endl;
            emit mob_num_Not_there();
        }
    }
    return devotee;
}

void DBInterface::receipt_no_printing()
{
    int r_number;
    QSqlQuery qury_SNO;
    qury_SNO.prepare("select * from sevabooking");
    qury_SNO.exec();
    while(qury_SNO.next())
    {
        r_number=qury_SNO.value(0).toInt();
    }
    emit get_receiptnumber(r_number);
}

void DBInterface::booking_report_cdate_function(QString formatchangedcalendar_str, QString SEVA, int TYPE)
{
    total_prasada=0;
    QList<QString> listOfSevaNames;
    QList<int> listOfPrasada;
    QList<int> listOfSevaType;

    qDebug()<<"\nChanged format is: "<<formatchangedcalendar_str<<Qt::endl;
    QSqlQuery query_other1;
    QString que;
    if(TYPE==0) {
        qDebug()<<"In type 0: "<<Qt::endl;
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1';");
        que = que.arg(formatchangedcalendar_str);
        //            que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,sevaname.THEERTHAPRASADA,persondetails.MOBILE,NOTE from sevabooking,persondetails,sevaname where sevabooking.PERSONID = persondetails.SNO and sevabooking.RECEIPT_DATE='%1' group by sevabooking.SEVANAME;");
        //    select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,NOTE from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.RECEIPT_DATE='2022-12-15'
    }
    else if (SEVA==ALLSEVANAME) {
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2'; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE);
        // select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2';
        //  select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,NOTE,sevabooking.SEVATYPE from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1';
    }
    else {
        qDebug()<<"Inside else@@@@@@"<<Qt::endl;
        que = ("select persondetails.PERSONNAME,persondetails.GOTHRA,persondetails.NAKSHATRA,sevabooking.SEVANAME,persondetails.MOBILE,sevabooking.NOTE,sevabooking.SEVATYPE,sevabooking.SEVA_DATE,sevabooking.RECEIPT_DATE,sevabooking.SEVATOTALPRICE,sevabooking.BANK,sevabooking.REFERENCE,sevabooking.ADDRESS,sevabooking.QUANTITY from sevabooking,persondetails where sevabooking.PERSONID = persondetails.SNO and sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' ; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que <<Qt::endl;

    bool b1= query_other1.prepare(que);
    qDebug() << " Query string =111111111111111111111" << query_other1.lastError() <<Qt::endl;
    bool b = query_other1.exec();
    qDebug() << " Query string =" <<b <<Qt::endl;
    qDebug() << " Query prepared successfully =" <<b1 <<Qt::endl;
    qDebug() << " Query string =111111111111111111111" << query_other1.lastError() <<Qt::endl;
    //  QSqlQuery query;
    //    while(query_other1.next())
    //    {
    //        qDebug() << " Query string inside while = Book rep" << que <<Qt::endl;
    //        BookingReportElement *elm = new BookingReportElement;
    //        personid = query_other1.value(0).toString();
    //        elm->setSevaName(query_other1.value(1).toString());
    //        list_sevaname.append(p_sevaname);
    //        quantity = query_other1.value(2).toInt();
    //        list_quantity.append(quantity);
    //        query.prepare("SELECT * FROM sevaname");
    //        query.exec();
    //        while(query.next())
    //        {
    //            QString val = query.value(1).toString();
    //            qDebug()<<"Seva name in db "<<val<<Qt::endl;
    //            qDebug()<<"Seva name11 in db "<<elm->sevaName()<<Qt::endl;
    //            if(val == elm->sevaName())//regular seva at 1st index in combo
    //            {
    //                elm->setTeerthaPrasada( query.value(6).toInt());
    //                qDebug()<<"teethaPrasada in db "<<query.value(6).toInt()<<Qt::endl;
    //                list_prasada.append(prasada);
    //            }
    //        }
    //        prasada =prasada*quantity;
    //        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
    //        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
    //        sevadate = yy_date.toString("dd-MM-yyyy") ;
    //        list_sevadate.append(sevadate);
    //        elm->setNote(query_other1.value(5).toString());//total
    //        list_note.append(note);
    //        QSqlQuery query_other2;//person details
    //        query_other2.prepare("SELECT * FROM  persondetails");
    //        query_other2.exec();
    //        while(query_other2.next())
    //        {
    //            QString p_id = query_other2.value(0).toString();
    //            if(personid==p_id){
    //                elm->setName(query_other2.value(1).toString());
    //                elm->setGothra(query_other2.value(2).toString());
    //                elm->setNakshatra(query_other2.value(3).toString());
    //                elm->setMobileNumber(query_other2.value(5).toString());
    //                list_pname.append(p_name);
    //                list_gotra.append(p_gotra);
    //                list_nakshatra.append(p_nakshtra);
    //                list_mobile.append(p_mobile);
    //            }
    //        }
    //        total_prasada=total_prasada+prasada;
    //        emit booking_report(elm);
    //    }
    //emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);
    qDebug() << " Query string =2222222222222" << que <<Qt::endl;
    while(query_other1.next())
    {
        qDebug() << " Query string inside 1st while = book rep" << que <<Qt::endl;
        // ele->setSevaName(query_other1.value(3).toString());
        listOfSevaNames.append(query_other1.value(3).toString());
        qDebug() << "999999999999999999999999" << query_other1.value(3).toString() <<Qt::endl;
        listOfSevaType.append(query_other1.value(6).toInt());
        qDebug() << "88888888888888888888888888" << query_other1.value(6).toInt() <<Qt::endl;
    }
    QSqlQuery query_other2;
    int i = 0;
    QString qu;
    while(i<listOfSevaNames.size())
    {
        qDebug() << "query while/**********" <<Qt::endl;
        qu = ("select sevaname.THEERTHAPRASADA from sevaname where SEVANAME = '%1' and SEVATYPE = '%2';");
        qu = qu.arg(listOfSevaNames.at(i)).arg(listOfSevaType.at(i));
        qDebug() << "query while/******1****" <<Qt::endl;

        qDebug() << "query while/*****2*****" <<Qt::endl;

        bool b1 =   query_other2.prepare(qu);
        qDebug() << "query while/*****3*****" <<b1<<Qt::endl;

        bool b2 =   query_other2.exec();
        qDebug() << "query while/*****4*****" <<b2<<qu<<Qt::endl;
        if(query_other2.next())
        {
            qDebug() << "query ifeee/*****5*****" <<Qt::endl;
            listOfPrasada.append(query_other2.value(0).toInt());
        }
        //                else{
        //                     listOfPrasada.append(-1);
        //                }
        qDebug() << "query while/*****5*****" <<Qt::endl;

        i++;
    }
    i=0;
    bool b5 = query_other1.prepare(que);
    qDebug() << " Query string =@@@@@@@@@@@@@" << query_other1.lastError() <<Qt::endl;
    bool b6 = query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << " Query string inside 2nd while = book rep" << que <<Qt::endl;
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
        //        ele->setTeerthaPrasada(0);
        qDebug() << " kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" <<Qt::endl;

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

        qDebug() <<"before emitting signal  booking_report ''''''''"<<Qt::endl;
        emit booking_report(ele);
        qDebug() <<"after emitting signal  booking_report ''''''''"<<Qt::endl;
        //        i++;
        qDebug()<<"after increment"<<i<<Qt::endl;
    }
}

void DBInterface::booking_report_cmonth_function(QString SEVA,int TYPE,int month,int year)
{
    qDebug()<<Q_FUNC_INFO<<"booking report month wise"<<SEVA<<TYPE<<month<<year<<Qt::endl;
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR='%2';");
        que = que.arg(month).arg(year);
    }
    else if (SEVA==ALLSEVANAME){
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' ; ");
        que = que.arg(month).arg(year).arg(TYPE);
    }
    else {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  ");
        qDebug() <<month<<year<<TYPE<<SEVA<<Qt::endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    QSqlQuery query;

    while(query_other1.next())
    {
        BookingReportElement *elm = new BookingReportElement;
        personid = query_other1.value(0).toString();
        elm->setSevaName( query_other1.value(1).toString());
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == elm->sevaName())//regular seva at 1st index in combo
            {
                elm->setTeerthaPrasada( query.value(6).toInt());
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
        sevadate = yy_date.toString("dd-MM-yyyy") ;
        list_sevadate.append(sevadate);
        elm->setNote(query_other1.value(5).toString());//total
        list_note.append(note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                elm->setName(query_other2.value(1).toString());
                elm->setGothra(query_other2.value(2).toString());
                elm->setNakshatra(query_other2.value(3).toString());
                elm->setMobileNumber(query_other2.value(5).toString());
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }

        total_prasada=total_prasada+prasada;
        emit booking_report(elm);
    }

    //emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

}

void DBInterface::booking_report_eachDateDataRangeForMonth_function(QString SEVA,int TYPE ,int S_MONTH,int S_YEAR)
{
    qDebug() <<Q_FUNC_INFO<<"The suman monthe"<<S_MONTH<<S_YEAR<<Qt::endl;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE);
    }
    else {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug()<<"Query in while"<<Qt::endl;
        qDebug() << "In while of db ***************************" << readstr <<Qt::endl;
        BookingReportDateRangeElement *ele = new   BookingReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
        ele->setDate( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        emit booking_report_Date_Range(ele);
    }
}

void DBInterface::booking_report_eachMonth_function(QString SEVA, int TYPE, int month, int year)
{
    qDebug() <<Q_FUNC_INFO<<Qt::endl;
    //    QList<QString> list_name;
    //    QList<int> list_ticket;
    //    QList<float> list_cost,list_total;
    //  int sum=0;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        qDebug()<<"+__________________________________1___++++++++++________________"<<month;

        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR='%2' Group by sevabooking.S_MONTH; ");
        que = que.arg(year);
    }
    else if (SEVA==ALLSEVANAME)
    {

        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.S_MONTH; ");
        que = que.arg(month).arg(year).arg(TYPE);
        qDebug()<<"+________________________________2_____++++++++++________________"<<month;

    }
    else {
        que = ("select S_Month,sum(QUANTITY) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.S_MONTH");
        qDebug() <<month<<"&&&&&&&&&&&"<<year<<"&&&&&&&&&&&&&&&&&&&"<<TYPE<<"&&&&&&&&&&&&&&&&&&&"<<SEVA<<Qt::endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************"  <<Qt::endl;
        BookingReportMonthRangeElement *ele = new   BookingReportMonthRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
        ele->setMonth( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        //        ele->setTotalAmount(query_other1.value(2).toFloat());
        //        qDebug() << "In while of db **************query_other1.value(2).toFloat()*************" << query_other1.value(2).toFloat() <<Qt::endl;
        emit booking_report_Month_Range(ele);
    }
    //select S_Month,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking wher
}

void DBInterface::booking_report_dataRange_function(QString SEVA,int TYPE,QString seva_Startdate,QString seva_Enddate)
{
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString str;
    if(TYPE == 0)
    {
        qDebug() <<seva_Startdate<<seva_Enddate;

        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2';" );
        str  = str.arg(seva_Startdate).arg(seva_Enddate);

    }
    else if (SEVA==ALLSEVANAME) {
        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' ; " );
        str  = str.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else {
        str = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' ;" );
        str  = str.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << str <<Qt::endl;

    query_other1.prepare(str);
    query_other1.exec();
    QSqlQuery query;
    while(query_other1.next())
    {
        BookingReportElement *elm = new BookingReportElement;
        personid = query_other1.value(0).toString();
        elm->setSevaName( query_other1.value(1).toString());
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == elm->sevaName())//regular seva at 1st index in combo
            {
                elm->setTeerthaPrasada( query.value(6).toInt());
                list_prasada.append(prasada);
            }
        }

        prasada = prasada * quantity;
        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
        sevadate = yy_date.toString("dd-MM-yyyy");
        list_sevadate.append(sevadate);
        elm->setNote(query_other1.value(5).toString());//total
        list_note.append(note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                elm->setName(query_other2.value(1).toString());
                elm->setGothra(query_other2.value(2).toString());
                elm->setNakshatra(query_other2.value(3).toString());
                elm->setMobileNumber(query_other2.value(5).toString());
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }
        total_prasada=total_prasada+prasada;
        emit booking_report(elm);
    }
    //emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);
}

void DBInterface::booking_report_eachDateDataRange_function(QString SEVA,int TYPE ,QString seva_Startdate,QString seva_Enddate)
{
    qDebug() <<Q_FUNC_INFO<<Qt::endl;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else {
        readstr = ("select SEVA_DATE,sum(QUANTITY) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************" << readstr <<Qt::endl;
        BookingReportDateRangeElement *ele = new   BookingReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);

        ele->setDate( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;

        emit booking_report_Date_Range(ele);

    }
}

DBInterface::~DBInterface()
{
    qDebug() <<"DBInterface Destructor is called"<<Qt::endl;
}

void DBInterface::account_report_cdate_function(QString SEVA,int TYPE,QString formatchangedcalendar_str)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<formatchangedcalendar_str<<"^^^^^^^^^^^^^^^^^^^^^^^^^^ "<<SEVA<< "  "<<TYPE<<Qt::endl;
    QList<QString> pay_mode={"cash","Cheque","NEFT","UPI"};
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QSqlQuery cash,cheque,neft,upi;
    QString que1;
    QString cashmode,cheqmode,neftmode,upimode;
    //    AccountReportElement ele;

    if(TYPE==0) {
        qDebug() <<"First"<<Qt::endl;

        //        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' Group by sevabooking.SEVANAME;");
        /*  que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS total_cost,"
                "CASE "
                "WHEN sevabooking.BANK = 'cash' THEN SUM(CASE WHEN sevabooking.BANK = 'cash' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'NEFT' THEN SUM(CASE WHEN sevabooking.BANK = 'NEFT' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'Cheque' THEN SUM(CASE WHEN sevabooking.BANK = 'Cheque' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'UPI' THEN SUM(CASE WHEN sevabooking.BANK = 'UPI' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "END AS total_price FROM sevabooking WHERE (sevabooking.BANK = 'cash' OR sevabooking.BANK = 'NEFT' OR sevabooking.BANK='Cheque' OR sevabooking.BANK='UPI') "
                "and sevabooking.RECEIPT_DATE='%1' Group by sevabooking.SEVANAME;"); */

        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE='%1' Group by sevabooking.BANK and sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(formatchangedcalendar_str);


    }
    else if (SEVA==ALLSEVANAME) {
        qDebug() <<"Second"<<Qt::endl;
        //        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST))  from sevabooking where  sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME; ");
        /*  que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS total_cost,"
                "CASE "
                "WHEN sevabooking.BANK = 'cash' THEN SUM(CASE WHEN sevabooking.BANK = 'cash' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'NEFT' THEN SUM(CASE WHEN sevabooking.BANK = 'NEFT' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'Cheque' THEN SUM(CASE WHEN sevabooking.BANK = 'Cheque' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'UPI' THEN SUM(CASE WHEN sevabooking.BANK = 'UPI' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "END AS total_price FROM sevabooking WHERE (sevabooking.BANK = 'cash' OR sevabooking.BANK = 'NEFT' OR sevabooking.BANK='Cheque' OR sevabooking.BANK='UPI') "
                "and sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME;"); */

        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity ,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else {
        qDebug() <<"Third"<<Qt::endl;
        //        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where  sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME; ");
        /*  que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS total_cost,"
                "CASE "
                "WHEN sevabooking.BANK = 'cash' THEN SUM(CASE WHEN sevabooking.BANK = 'cash' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'NEFT' THEN SUM(CASE WHEN sevabooking.BANK = 'NEFT' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'Cheque' THEN SUM(CASE WHEN sevabooking.BANK = 'Cheque' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "WHEN sevabooking.BANK = 'UPI' THEN SUM(CASE WHEN sevabooking.BANK = 'UPI' THEN ADDITIONALCOST+(QUANTITY*SEVACOST) ELSE 0 END) "
                "END AS total_price FROM sevabooking WHERE (sevabooking.BANK = 'cash' OR sevabooking.BANK = 'NEFT' OR sevabooking.BANK='Cheque' OR sevabooking.BANK='UPI') "
                "and sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME;");*/

        que1 = ("select SEVANAME,sum(QUANTITY) AS Qauntity,SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) AS SEVATOTALPRICE,BANK AS Tran_type from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME,BANK;");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    cash.prepare(cashmode);
    cash.exec();

    cheque.prepare(cheqmode);
    cheque.exec();

    neft.prepare(neftmode);
    neft.exec();

    upi.prepare(upimode);
    upi.exec();


    if(cash.exec()){
        qDebug()<<"inside cash true"<<Qt::endl;
    }
    else{
        qDebug()<<"inside cash false"<<Qt::endl;
    }
    bool b =  query_other1.exec();
    qDebug() << " Query string Acc rep" << b <<Qt::endl;

    //    while(query_other1.next() && cash.next() && cheque.next() && neft.next() && upi.next())
    while(query_other1.next())
    {
        qDebug() << " Query string inside while = Acc rep" << que1 <<Qt::endl;
        AccountReportElement *ele = new AccountReportElement;
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        qDebug()<<"suman bank query---"<<query_other1.value("Tran_type").toString()<<Qt::endl;

        if(query_other1.value("Tran_type").toString()==pay_mode[0]){
            ele->setCash(query_other1.value("SEVATOTALPRICE").toFloat());
        }
        else if(query_other1.value("Tran_type").toString()==pay_mode[1]){
            ele->setCheque(query_other1.value("SEVATOTALPRICE").toFloat());}

        else if(query_other1.value("Tran_type").toString()==pay_mode[2]){
            ele->setNeft(query_other1.value("SEVATOTALPRICE").toFloat());}

        else if(query_other1.value("Tran_type").toString()==pay_mode[3]){
            ele->setUpi(query_other1.value("SEVATOTALPRICE").toFloat());}

        qDebug() << query_other1.value(0).toString()<<Qt::endl;
        qDebug() << query_other1.value(1).toString()<<Qt::endl;
        qDebug() << query_other1.value(2).toString()<<Qt::endl;
        qDebug() << query_other1.value(3).toString()<<Qt::endl;
        qDebug()<<"The 4th query Value"<< query_other1.value(4).toFloat()<<Qt::endl;
        qDebug() <<"before emitting signal  account_report ''''''''" <<Qt::endl;
        emit account_report(ele);
        qDebug() <<"after emitting signal  account_report ''''''''"<<Qt::endl;
    }

}

void DBInterface::account_report_cmonth_function(QString SEVA,int TYPE,int month,int year)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    int sum=0;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2' Group by sevabooking.SEVANAME; ");
        //    que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR='%2' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year);
    }
    else if (SEVA==ALLSEVANAME)
    {

        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; ");
        que = que.arg(month).arg(year).arg(TYPE);
        qDebug()<<"+_____________________________________++++++++++________________"<<month;

    }
    else {
        que = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.R_MONTH='%1' and sevabooking.R_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.SEVANAME");
        qDebug() <<month<<"&&&&&&&&&&&"<<year<<"&&&&&&&&&&&&&&&&&&&"<<TYPE<<"&&&&&&&&&&&&&&&&&&&"<<SEVA<<Qt::endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que <<Qt::endl;
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

}

void DBInterface::account_report_eachMonth_function(QString SEVA,int TYPE,int month,int year)
{

    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    int sum=0;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        qDebug()<<"+__________________________________1___++++++++++________________"<<month;

        que = ("select S_Month,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR='%2' Group by sevabooking.S_MONTH; ");
        que = que.arg(year);
    }
    else if (SEVA==ALLSEVANAME)
    {

        que = ("select S_Month,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.S_MONTH; ");
        que = que.arg(month).arg(year).arg(TYPE);
        qDebug()<<"+________________________________2_____++++++++++________________"<<month;

    }
    else {
        que = ("select S_Month,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4'  Group by sevabooking.S_MONTH");
        qDebug() <<month<<"&&&&&&&&&&&"<<year<<"&&&&&&&&&&&&&&&&&&&"<<TYPE<<"&&&&&&&&&&&&&&&&&&&"<<SEVA<<Qt::endl;
        que = que.arg(month).arg(year).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << que <<Qt::endl;
    query_other1.prepare(que);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************"  <<Qt::endl;
        AccountReportMonthRangeElement *ele = new   AccountReportMonthRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);
        ele->setMonth( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        ele->setTotalAmount(query_other1.value(2).toFloat());
        qDebug() << "In while of db **************query_other1.value(2).toFloat()*************" << query_other1.value(2).toFloat() <<Qt::endl;
        emit account_report_Month_Range(ele);
    }
    //select S_Month,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR = '2022' Group by sevabooking.S_MONTH;
}

void DBInterface::voucher_report_cdate_function(QString formatchangedcalendar_str, QString voucher_type , QString payment_mode)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<< formatchangedcalendar_str<<"1111111"<<Qt::endl;
    qDebug()<<voucher_type<<"222222"<<Qt::endl;
    qDebug()<<payment_mode<<"333333"<<Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if(voucher_type =="ALL" && payment_mode=="ALL")
    {
        qDebug() << "inside voucherdate 1" <<Qt::endl;
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES='%1';");
        que1 = que1.arg(formatchangedcalendar_str);
    }

    if(voucher_type =="ALL" && payment_mode!="ALL")
    {
        qDebug() << "inside voucherdate 2" <<Qt::endl;
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES='%1' and VOUCHER_DETAILS.PAYMENT_MODE='%2';");
        que1 = que1.arg(formatchangedcalendar_str).arg(payment_mode);
    }

    if(voucher_type !="ALL" && payment_mode=="ALL")
    {
        qDebug() << "inside voucherdate 3" <<Qt::endl;
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES='%1' and VOUCHER_DETAILS.VOUCHER_TYPE='%2';");
        que1 = que1.arg(formatchangedcalendar_str).arg(voucher_type);
    }

    if(voucher_type !="ALL" && payment_mode!="ALL")
    {
        qDebug() << "inside voucherdate 4" <<Qt::endl;
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES='%1' and VOUCHER_DETAILS.VOUCHER_TYPE='%2' and VOUCHER_DETAILS.PAYMENT_MODE='%3';");
        que1 = que1.arg(formatchangedcalendar_str).arg(voucher_type).arg(payment_mode);
    }

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    qDebug() << " Query string =111111" << que1 <<Qt::endl;
    bool b = query_other1.exec();
    qDebug() << " Query string =222222" << b <<Qt::endl;
    qDebug()<<query_other1.lastError()<<Qt::endl;
    while(query_other1.next())
    {
        qDebug() << "Voucher Cdate inside while =" << que1 <<Qt::endl;
        VoucherElement *ele = new VoucherElement;
        ele->setVoucherNo(query_other1.value(0).toInt());
        ele->setVoucherName(query_other1.value(1).toString());
        ele->setVoucherPaymentMode(query_other1.value(2).toString());
        ele->setVoucherNote(query_other1.value(3).toString());
        ele->setMobileNo(query_other1.value(4).toString());
        ele->setVoucherItem(query_other1.value(5).toString());
        ele->setVoucherCost(query_other1.value(6).toString());
        ele->setVoucherDate(query_other1.value(7).toString());
        ele->setVoucherType(query_other1.value(8).toString());
        ele->setPaymentReference(query_other1.value(9).toString());

        qDebug() <<  query_other1.value(0).toString();
        qDebug() <<  query_other1.value(1).toString();
        qDebug() <<  query_other1.value(2).toString();
        qDebug() <<  query_other1.value(3).toString();
        qDebug() <<  query_other1.value(4).toString();
        qDebug() <<  query_other1.value(5).toString();
        qDebug() <<  query_other1.value(6).toString();
        qDebug() <<  query_other1.value(7).toString();
        qDebug() << "++++++++++ setVoucherDate =" << que1 <<query_other1.value(7).toString() <<Qt::endl;
        qDebug() << query_other1.value(8).toString();
        qDebug() << query_other1.value(9).toString();
        emit voucher_report(ele);
    }
}

void DBInterface::voucher_report_cmonth_function(int month, int year, QString voucher_type , QString payment_mode)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<< month<<Qt::endl;
    qDebug()<< year<<Qt::endl;
    qDebug()<<voucher_type<<Qt::endl;
    qDebug()<<payment_mode<<Qt::endl;
    QSqlQuery query_other1;
    QString que1;
    if(voucher_type =="ALL" && payment_mode=="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,S_MONTH,S_YEAR,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.S_MONTH='%1' and VOUCHER_DETAILS.S_YEAR='%2';");
        que1 = que1.arg(month).arg(year);
    }

    if(voucher_type =="ALL" && payment_mode!="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,S_MONTH,S_YEAR,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.S_MONTH='%1' and VOUCHER_DETAILS.S_YEAR='%2' and VOUCHER_DETAILS.PAYMENT_MODE='%3';");
        que1 = que1.arg(month).arg(year).arg(payment_mode);
    }

    if(voucher_type !="ALL" && payment_mode=="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,S_MONTH,S_YEAR,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.S_MONTH='%1' and VOUCHER_DETAILS.S_YEAR='%2' and VOUCHER_DETAILS.VOUCHER_TYPE='%3';");
        que1 = que1.arg(month).arg(year).arg(voucher_type);
    }

    if(voucher_type !="ALL" && payment_mode!="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,S_MONTH,S_YEAR,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.S_MONTH='%1' and VOUCHER_DETAILS.S_YEAR='%2' and VOUCHER_DETAILS.VOUCHER_TYPE='%3' and VOUCHER_DETAILS.PAYMENT_MODE='%4';");
        que1 = que1.arg(month).arg(year).arg(voucher_type).arg(payment_mode);
    }

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    query_other1.exec();
    qDebug()<<query_other1.lastError()<<Qt::endl;
    while(query_other1.next())
    {
        qDebug() << " Inside voucher Month while"<<Qt::endl;
        VoucherElement *ele = new VoucherElement;
        ele->setVoucherNo(query_other1.value(0).toInt());
        ele->setVoucherName(query_other1.value(1).toString());
        ele->setVoucherPaymentMode(query_other1.value(2).toString());
        ele->setVoucherNote(query_other1.value(3).toString());
        ele->setMobileNo(query_other1.value(4).toString());
        ele->setVoucherItem(query_other1.value(5).toString());
        ele->setVoucherCost(query_other1.value(6).toString());
        ele->setVoucherDate(query_other1.value(7).toString());
        ele->setVoucherType(query_other1.value(8).toString());
        ele->setPaymentReference(query_other1.value(11).toString());

        qDebug() <<  query_other1.value(0).toString();
        qDebug() <<  query_other1.value(1).toString();
        qDebug() <<  query_other1.value(2).toString();
        qDebug() <<  query_other1.value(3).toString();
        qDebug() <<  query_other1.value(4).toString();
        qDebug() <<  query_other1.value(5).toString();
        qDebug() <<  query_other1.value(6).toString();
        qDebug() <<  query_other1.value(7).toString();
        qDebug() << query_other1.value(8).toString();
        qDebug() << query_other1.value(9).toString();
        emit voucher_report(ele);
    }
}

void DBInterface::voucher_report_dataRange_function(QString startDate, QString endDate, QString voucher_type , QString payment_mode)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<< startDate<<Qt::endl;
    qDebug()<< endDate<<Qt::endl;
    qDebug()<<voucher_type<<Qt::endl;
    qDebug()<<payment_mode<<Qt::endl;

    QSqlQuery query_other1;
    QString que1;
    if(voucher_type =="ALL" && payment_mode=="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2';");
        que1 = que1.arg(startDate).arg(endDate);
    }

    if(voucher_type =="ALL" && payment_mode!="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2' and VOUCHER_DETAILS.PAYMENT_MODE='%3';");
        que1 = que1.arg(startDate).arg(endDate).arg(payment_mode);
    }

    if(voucher_type !="ALL" && payment_mode=="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2' and VOUCHER_DETAILS.VOUCHER_TYPE='%3';");
        que1 = que1.arg(startDate).arg(endDate).arg(voucher_type);
    }

    if(voucher_type !="ALL" && payment_mode!="ALL")
    {
        que1 = ("select V_NO,NAME,PAYMENT_MODE,NOTE,PHONE,PRODUCT,COST,DATES,VOUCHER_TYPE,REFERENCE_NO from VOUCHER_DETAILS where VOUCHER_DETAILS.DATES between '%1' and '%2' and VOUCHER_DETAILS.VOUCHER_TYPE='%3' and VOUCHER_DETAILS.PAYMENT_MODE='%4';");
        que1 = que1.arg(startDate).arg(endDate).arg(voucher_type).arg(payment_mode);
    }

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    bool b =  query_other1.exec();
    qDebug()<<"b = "<<b<<Qt::endl;
    //    bool b1 =  query_other1.next();
    //    qDebug()<<"b1 = "<<b1<<Qt::endl;
    //    if(query_other1.next()==false)
    //    {
    //        return;
    //    }
    //    if(query_other1.size()==0)
    //    {
    //        return 0;
    //    }
    while(query_other1.next())
    {
        qDebug()<<"Inside while "<<Qt::endl;
        VoucherElement *ele = new VoucherElement;
        ele->setVoucherNo(query_other1.value(0).toInt());
        ele->setVoucherName(query_other1.value(1).toString());
        ele->setVoucherPaymentMode(query_other1.value(2).toString());
        ele->setVoucherNote(query_other1.value(3).toString());
        ele->setMobileNo(query_other1.value(4).toString());
        ele->setVoucherItem(query_other1.value(5).toString());
        ele->setVoucherCost(query_other1.value(6).toString());
        ele->setVoucherDate(query_other1.value(7).toString());
        ele->setVoucherType(query_other1.value(8).toString());
        ele->setPaymentReference(query_other1.value(9).toString());

        qDebug() <<  query_other1.value(0).toString();
        qDebug() <<  query_other1.value(1).toString();
        qDebug() <<  query_other1.value(2).toString();
        qDebug() <<  query_other1.value(3).toString();
        qDebug() <<  query_other1.value(4).toString();
        qDebug() <<  query_other1.value(5).toString();
        qDebug() <<  query_other1.value(6).toString();
        qDebug() <<  query_other1.value(7).toString();
        //      qDebug() << "++++++++++ setVoucherDate of data range=" << que1 <<query_other1.value(7).toString() <<Qt::endl;
        qDebug() << query_other1.value(8).toString();
        qDebug() << query_other1.value(9).toString();
        emit voucher_report(ele);
    }
    //  return 1;
}

void DBInterface::account_report_dataRange_function(QString SEVA,int TYPE ,QString seva_Startdate,QString seva_Enddate)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by sevabooking.SEVANAME;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.SEVANAME; " );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);
    }
    else {
        readstr = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.SEVANAME;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
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
}

void DBInterface::account_report_eachDateDataRange_function(QString SEVA,int TYPE ,QString seva_Startdate,QString seva_Enddate)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate);

    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE);

    }
    else {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '%1' and '%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' and  Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(seva_Startdate).arg(seva_Enddate).arg(TYPE).arg(SEVA);

    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();

    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************" << readstr <<Qt::endl;
        AccountReportDateRangeElement *ele = new   AccountReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);

        ele->setDate( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        ele->setTotalAmount(query_other1.value(2).toFloat());

        qDebug() << "In while of db **************query_other1.value(2).toFloat()*************" << query_other1.value(2).toFloat() <<Qt::endl;
        emit account_report_Date_Range(ele);

    }

    //   select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE between '2022-08-01' and '2022-11-18' Group by sevabooking.RECEIPT_DATE
}
void DBInterface::account_report_eachDateDataRangeForMonth_function(QString SEVA,int TYPE ,int S_MONTH,int S_YEAR)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE);
    }
    else {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************" << readstr <<Qt::endl;
        AccountReportDateRangeElement *ele = new   AccountReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);

        ele->setDate( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        ele->setTotalAmount(query_other1.value(2).toFloat());
        qDebug() << "In while of db **************query_other1.value(2).toFloat()*************" << query_other1.value(2).toFloat() <<Qt::endl;
        emit account_report_Date_Range(ele);

    }
    //  select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_year ='2022' and sevabooking.S_Month ='11' Group by sevabooking.RECEIPT_DATE
}

void DBInterface::account_report_eachDateDataRangeForWholeMonth_function(QString SEVA,int TYPE ,int S_MONTH,int S_YEAR)
{
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString readstr;
    if(TYPE == 0)
    {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH);
    }
    else if (SEVA==ALLSEVANAME) {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE);
    }
    else {
        readstr = ("select RECEIPT_DATE,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.S_YEAR ='%1' and sevabooking.S_MONTH ='%2' and sevabooking.SEVATYPE = '%3' and sevabooking.SEVANAME = '%4' Group by sevabooking.RECEIPT_DATE;" );
        readstr  = readstr.arg(S_YEAR).arg(S_MONTH).arg(TYPE).arg(SEVA);
    }
    qDebug() << " Query string =" << readstr <<Qt::endl;
    query_other1.prepare(readstr);
    query_other1.exec();
    while(query_other1.next())
    {
        qDebug() << "In while of db ***************************" << readstr <<Qt::endl;
        AccountReportDateRangeElement *ele = new   AccountReportDateRangeElement;
        QQmlEngine::setObjectOwnership(ele, QQmlEngine::CppOwnership);

        ele->setDate( query_other1.value(0).toString());
        qDebug() << "In while of db ********query_other1.value(0).toString()*******************" << query_other1.value(0).toString() <<Qt::endl;
        ele->setTotalSevaCount( query_other1.value(1).toInt());
        qDebug() << "In while of db **********query_other1.value(1).toInt()*****************" << query_other1.value(1).toInt() <<Qt::endl;
        ele->setTotalAmount(query_other1.value(2).toFloat());
        qDebug() << "In while of db **************query_other1.value(2).toFloat()*************" << query_other1.value(2).toFloat() <<Qt::endl;
        emit account_report_Date_Range(ele);

    }
}
void DBInterface::signin_clicked(QString username,QString password,int type)
{
    bool found =false;
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE from signindetails");
    query_s_no.exec();
    while(query_s_no.next())
    {
        QString Last_name=query_s_no.value(2).toString();
        QString user_name=query_s_no.value(3).toString();
        QString pass_word=query_s_no.value(4).toString();

        if(username==user_name && password==pass_word)
        {
            if(type==1)
            {
                emit success();
            }
            else {
                qDebug()<<"%%%%%%%%%%%%%%%%%%%--------------111111----------------%%%%%%%%%%%%%%%%%%%%%%%%%%"<<type<<this->objectName();
                emit correct_password(Last_name);
            }
            found =true;
            break;
        }
    }
    if(!found)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("YOU ENTERD THE WRONG PASSWORD"));
        msgBox.exec();
    }
    qDebug()<<"%%%%%%%%%%%%%%%%%%%------------------------------%%%%%%%%%%%%%%%%%%%%%%%%%%"<<type<<this->objectName();
}

void DBInterface::old_password(QString l_userfirstname, QString l_userlastname)
{
    bool found =false;
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE from signindetails");
    query_s_no.exec();
    while(query_s_no.next())
    {
        QString f_First_name=query_s_no.value(1).toString();
        QString  l_last_name=query_s_no.value(2).toString();
        QString l_username=query_s_no.value(3).toString();
        QString l_password=query_s_no.value(4).toString();
        qDebug()<<l_userfirstname<<f_First_name <<l_userlastname<<l_last_name;
        if((l_userfirstname==f_First_name) && (l_userlastname==l_last_name))
        {
            emit show_username_password(l_username,l_password);
            found =true;
            break;
        }
    }
    if(!found)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("YOU ENTERD THE WRONG USERNAME OR PASSWORD"));
        msgBox.exec();
    }
}

void DBInterface::add_new_signin_details(QString fname, QString lname, QString username, QString password,int rolenum,QString date)
{
    QSqlQuery query_s_no;
    QMessageBox msgbox;
    QString status;
    query_s_no.prepare("select SNO from signindetails");
    query_s_no.exec();
    while(query_s_no.next()){
        TID =query_s_no.value(0).toInt();
        qDebug()<<TID<<Qt::endl;
    }
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select * from signindetails");
    qry.exec();
    while(qry.next())
    {
        QString val1=qry.value(3).toString();
        qDebug()<< Q_FUNC_INFO << "The val1 is= "<<val1<<Qt::endl;

        qDebug()<<Q_FUNC_INFO<< fname<<lname<<username<<  password<<rolenum<< date<<"%%%%%%%%%%%%"<<val1<<Qt::endl;

        if(username==val1)
        {
            qDebug()<<"User exist"<<Qt::endl;
            found =true;
            status = username + ": " + "Alraedy Exist";
        }
    }
    if(found==false)
    {
        qDebug()<<"Data not found"<<Qt::endl;
        QSqlQuery Squery;
        Squery.prepare("INSERT INTO signindetails(SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,ROLENUMBER,DATE)"
                       "VALUES (:sno, :first_name, :last_name, :user_name, :password,:role_no, :date)");
        TID = TID +1;
        Squery.bindValue(":sno",TID);
        Squery.bindValue(":first_name",fname);
        Squery.bindValue(":last_name",lname );
        Squery.bindValue(":user_name",username);
        Squery.bindValue(":password",password);
        Squery.bindValue(":role_no",rolenum);
        Squery.bindValue(":date",date);
        Squery.exec();
        status = username+ ": " + "Added Successfuly";
    }
    emit sucessfully_added(status);
}

QList<SigninDetails *> DBInterface::geting_signInDetails()
{
    QList<SigninDetails *>  listOfSignin;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM signindetails");
    qry.exec();
    while(qry.next())
    {
        SigninDetails *signIn_Detail  = new SigninDetails;
        signIn_Detail->firstName=qry.value(1).toString();
        signIn_Detail->LastName=qry.value(2).toString();
        signIn_Detail->UserName=qry.value(3).toString();
        signIn_Detail->Password=qry.value(4).toString();
        listOfSignin.append(signIn_Detail);
    }
    return listOfSignin;
}

void DBInterface::delete_selected_LoginDetails(QString Name)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM signindetails WHERE FIRSTNAME=:firstname");
    qry.bindValue(":firstname", Name);
    qry.exec();
}

void DBInterface::modify_selected_LoginDetails(QString previous_name,QString first_name, QString last_name, QString user_name, QString password, QString date)
{
    QSqlQuery qry;
    qry.prepare("UPDATE signindetails SET  FIRSTNAME=:firstname,LASTNAME=:lastname,USERNAME=:username,PASSWORD=:password,DATE=:date WHERE FIRSTNAME=:previous");
    qry.bindValue(":previous",previous_name);
    qry.bindValue(":firstname",first_name);
    qry.bindValue(":lastname",last_name);
    qry.bindValue(":username",user_name);
    qry.bindValue(":password",password);
    qry.bindValue(":date",date);
    qry.exec();
}

QStringList DBInterface::getMasterCredentials()
{
    QStringList listOfSignin;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM mastersignin");
    qry.exec();
    while(qry.next())
    {
        listOfSignin.append(qry.value(1).toString());
        listOfSignin.append(qry.value(2).toString());
    }
    return listOfSignin;
}

void DBInterface::updateMasterCredentials(QString oldUserName,QString NewUsername,QString NewPassword,QString date)
{
    QSqlQuery qry;
    qry.prepare("UPDATE mastersignin SET USERNAME=:username,PASSWORD=:password,DATE=:date WHERE USERNAME=:old_username");
    qry.bindValue(":old_username",oldUserName);
    qry.bindValue(":username",NewUsername);
    qry.bindValue(":password",NewPassword);
    qry.bindValue(":date",date);
    qry.exec();
}

QList<print_details *> DBInterface::printWithReceiptNumber(int receiptNumber)
{
    int SNO =1;
    QSqlQuery query_other1;
    QString que1;
    QList<print_details*> printdetails;
    //    QList<QString> printdeta;

    que1 = ("select SNO,PERSONID,SEVANAME,SEVACOST,QUANTITY,ADDITIONALCOST,SEVATOTALPRICE,RECEIPT_DATE,SEVA_DATE,NOTE,CASH,BANK from sevabooking where sevabooking.SNO='%1' Group by sevabooking.SEVANAME");
    que1 = que1.arg(receiptNumber);

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    query_other1.exec();


    while(query_other1.next())
    {
        print_details *pdetails = new print_details;
        QString RECPTNO = QString::number(query_other1.value(0).toInt());
        pdetails->RECPT_NO = RECPTNO;


        QString realformatreceiptdate=query_other1.value(7).toString();
        QDate Date = QDate::fromString(realformatreceiptdate,"yyyy-MM-dd");
        pdetails->DATE = Date.toString("dd-MM-yyyy");


        QString realformatsevadate =query_other1.value(8).toString();
        QDate sevadateDate = QDate::fromString(realformatsevadate,"yyyy-MM-dd");
        //        QString r_date = query_other1.value(9).toString();
        //        QString  r_month = query_other1.value(10).toString();
        //        QString r_year =query_other1.value(11).toString();


        pdetails->SEVA_DATE =sevadateDate.toString("dd-MM-yyyy");
        pdetails->SL_NO =SNO++;
        pdetails->SEVA_DESCR = query_other1.value(2).toString();
        QString quantity = QString::number(query_other1.value(4).toInt());
        pdetails->QTY =quantity ;
        int cost = (query_other1.value(3).toInt()*query_other1.value(4).toInt());
        pdetails->AMT = cost;
        QString rate = QString::number(query_other1.value(3).toInt());
        pdetails->RATE = rate;

        QString TOTALAMT = QString::number(query_other1.value(6).toInt());
        pdetails->TOTAL_AMT = TOTALAMT;
        pdetails->TOTAL_IN_WORDS = NumberToWord(query_other1.value(6).toInt());
        pdetails->NOTE = query_other1.value(9).toString();
        pdetails->CASH = query_other1.value(10).toInt();
        pdetails->BANK_REF = query_other1.value(11).toString();
        QString additionalCharges = QString::number(query_other1.value(5).toInt());
        pdetails->ADDITIONAL =additionalCharges;


        qDebug()<< "SNO"<<query_other1.value(0).toInt();
        qDebug()<< "PERSONID"<< query_other1.value(1).toInt()<<Qt::endl;
        qDebug()<< "SEVANAME"<<query_other1.value(2).toString()<<Qt::endl;
        qDebug()<< "SEVACOST"<<query_other1.value(3).toInt()<<Qt::endl;
        qDebug()<< "QUANTITY"<< query_other1.value(4).toInt();
        qDebug()<< "ADDITIONALCOST"<< query_other1.value(5).toInt()<<Qt::endl;
        qDebug()<< "SEVATOTALPRICE"<< query_other1.value(6).toInt();
        qDebug()<< "RECEIPT_DATE"<< query_other1.value(7).toString()<<Qt::endl;
        qDebug()<< "SEVA_DATE"<<query_other1.value(8).toString()<<Qt::endl;
        qDebug()<< "NOTE"<<query_other1.value(9).toString()<<Qt::endl;
        qDebug()<< "CASH"<< query_other1.value(10).toInt()<<Qt::endl;
        qDebug()<< "BANK"<<query_other1.value(11).toString();

        QSqlQuery query_other;
        QString que;
        que = ("select SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE from persondetails where persondetails.SNO='%1'");
        que = que.arg(query_other1.value(1).toInt());
        qDebug() << " Query string PERSONNAME=" << que <<Qt::endl;
        query_other.prepare(que);
        query_other.exec();

        while(query_other.next())
        {

            pdetails->NAME = query_other.value(1).toString();
            QString MOBNUM = QString::number(query_other.value(5).toInt());

            pdetails->MOB_NO = MOBNUM;
            pdetails->GOTHRA = query_other.value(2).toString();
            pdetails->NAKSHATRA = query_other.value(3).toString();

            //        int PID = query_other1.value(0).toInt();
            //        QString  name = query_other1.value(1).toString();
            //        QString  gotra =query_other1.value(2).toString();//cost
            //        QString  naksatra =query_other1.value(3).toString();//cost
            //        QString  mobile =query_other1.value(4).toString();//cost

            qDebug()<<"SNO"<< query_other.value(0).toInt()<<Qt::endl;
            qDebug()<<"PERSONNAME xxxxxxxxxxxxxxxxxxxxxx"<<query_other.value(1).toString()<<Qt::endl;
            qDebug()<<"GOTHRA"<<query_other.value(2).toString()<<Qt::endl;
            qDebug()<<"NAKSHATRA"<<query_other.value(3).toString()<<Qt::endl;
            qDebug()<<"DATE"<< query_other.value(4).toString()<<Qt::endl;
            qDebug()<<"MOBILE"<< query_other.value(5).toInt()<<Qt::endl;
        }
        SNO++;
        printdetails.append(pdetails);
    }
    return printdetails;
}

QString DBInterface::NumberToWord(const unsigned int number)
{
    const std::vector<QString> first14=
        {"Zero", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
         "Twelve", "Thirteen", "Fourteen" };
    const std::vector<QString> prefixes=
        {"Twen","Thir","For","Fif","Six","Seven","Eigh","Nine"};

    if( number <= 14 )
    {
        return first14.at(number);
    }
    if( number < 20 )
    {
        return prefixes.at(number-12) + "teen";
    }
    if( number < 100 )
    {
        unsigned int remainder = number - (static_cast<int>(number/10)*10);
        return prefixes.at(number/10-2) + (0 != remainder ? "ty " + NumberToWord(remainder) : "ty");
    }
    if( number < 1000 )
    {
        unsigned int remainder = number - (static_cast<int>(number/100)*100);
        return first14.at(number/100) + (0 != remainder ? " Hundred " + NumberToWord(remainder) : " Hundred");
    }
    if( number < 100000 )
    {
        unsigned int thousands = static_cast<int>(number/1000);
        unsigned int remainder = number - (thousands*1000);
        return NumberToWord(thousands) + (0 != remainder ? " Thousand " + NumberToWord(remainder) : " Thousand");
    }
    if( number < 10000000 )
    {
        unsigned int millions = static_cast<int>(number/100000);
        unsigned int remainder = number - (millions*100000);
        return NumberToWord(millions) + (0 != remainder ? " Lakhs " + NumberToWord(remainder) : " Lakhs");
    }

    throw std::out_of_range("NumberToWord() value too large");
}

bool DBInterface::checkCredentials(QString userID, QString pass)
{
    qDebug() << Q_FUNC_INFO << userID << pass << Qt::endl;
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,ROLENUMBER,DATE from signindetails");
    if(!query_s_no.exec()){
        qWarning()<<"Error in signin db query "<< query_s_no.lastError().text() <<Qt::endl;
        return false;
    }
    while(query_s_no.next())
    {
        qDebug() << Q_FUNC_INFO << "The while id =" << userID << " password =" << pass << Qt::endl;
        QString first_name = query_s_no.value(1).toString();
        QString last_name = query_s_no.value(2).toString();
        QString user_name = query_s_no.value(3).toString();
        QString pass_word = query_s_no.value(4).toString();
        int rolenumber = query_s_no.value(5).toString().toInt();
        qDebug() << Q_FUNC_INFO << " db id = " << user_name << " password = " << pass_word;
        if(userID == user_name && pass == pass_word){
            emit success();
            qDebug() << "The role number is " << rolenumber << Qt::endl;
            emit sendRolenumber(rolenumber,first_name +" "+ last_name);
            return true;
        }
    }

    emit wrongCred();
    return false;
}

int DBInterface::getNextSevaId()
{
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO from sevaname");
    query_s_no.exec();
    qDebug() << Q_FUNC_INFO << "Size of query == " << query_s_no.size()<<Qt::endl;
    while(query_s_no.next())
    {
        sevanameLastNo = query_s_no.value(0).toInt();
    }
    qDebug() << Q_FUNC_INFO << "last ID == " << sevanameLastNo + 1<<Qt::endl;
    return sevanameLastNo + 1;
}

QStringList DBInterface::qrySevaDates()
{
    qDebug() <<Q_FUNC_INFO << Qt::endl;
    QSqlQuery query;
    query.prepare("SELECT * FROM sevabooking");
    query.exec();
    QStringList l_sevaDateList;
    while(query.next()){
        l_sevaDateList.append(query.value(8).toString());
    }
    return l_sevaDateList;
}

bool DBInterface::qrySevabookingBySevaDate(QString formatchangedcalendar_str)
{

    QSqlQuery query;
    QSqlQuery qury;
    QString que,que_1;
    //    QString list_recNo, list_names, list_mobileNo, list_sevaNames,list_sevaDates,list_receiptDates,list_totalPrice;
    //    QString list_cash,list_bank,list_reference,list_address,list_momemto;

    que = ("select SNO,PERSONID,SEVANAME,SEVA_DATE,RECEIPT_DATE,SEVATOTALPRICE,CASH,BANK,reference,STATUS,address,momento from sevabooking where sevabooking.SEVA_DATE='%1';");
    que = que.arg(formatchangedcalendar_str);
    query.prepare(que);
    bool b = query.exec();
    if(b==false)
    {
        return false;
    }
    while(query.next())
    {
        SevaBookingElement *elem = new SevaBookingElement;
        DevotePersnalDetails *person = new DevotePersnalDetails;
        elem->setSno(query.value(0).toString());
        personid = query.value(1).toString();
        elem->setPerson_id(query.value(1).toString());
        elem->setSevaname(query.value(2).toString());
        elem->setSevaDate(query.value(3).toString());
        elem->setReceiptDate(query.value(4).toString());
        elem->setTotalCost(query.value(5).toString());
        elem->setCash(query.value(6).toString());
        elem->setBank(query.value(7).toString());
        elem->setReference(query.value(8).toString());
        elem->setStatus(query.value(9).toString());
        elem->setAddress(query.value(10).toString());
        elem->setMomento(query.value(11).toString());
        qDebug() <<Q_FUNC_INFO << query.value(0).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(1).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(2).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(3).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(4).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(5).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(6).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(7).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(8).toString()<<Qt::endl;
        qDebug() <<"Suman Status" << query.value(9).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(10).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(11).toString()<<Qt::endl;


        que_1 = ("select PERSONNAME,MOBILE from persondetails where persondetails.SNO='%1';");
        que_1 = que_1.arg(personid);

        qury.prepare(que_1);
        bool c = qury.exec();
        if(c==false)
        {
            return false;
        }
        while(qury.next()){
            person->setDevoteeName(qury.value(0).toString());
            person->setMobileNumber(qury.value(1).toString());
            elem->setPerson(person);

            qDebug() <<Q_FUNC_INFO << qury.value(0).toString()<<Qt::endl;
            qDebug() <<Q_FUNC_INFO << qury.value(1).toString()<<Qt::endl;
        }
        emit sendOneSevaBooking(elem);
    }
    return true;

}

void DBInterface::qrySevabookingByDateRange(QString startDate, QString endDate)
{
    QSqlQuery query;
    QSqlQuery qury;
    QString que,que_1;
    //    QString list_recNo, list_names, list_mobileNo, list_sevaNames,list_sevaDates,list_receiptDates,list_totalPrice;
    //    QString list_cash,list_bank,list_reference,list_address,list_momemto;

    que = ("select SNO,PERSONID,SEVANAME,SEVA_DATE,RECEIPT_DATE,SEVATOTALPRICE,CASH,BANK,reference,STATUS,address,momento from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2';");
    que = que.arg(startDate).arg(endDate);
    query.prepare(que);
    query.exec();
    while(query.next())
    {
        SevaBookingElement *elem = new SevaBookingElement;
        DevotePersnalDetails *person = new DevotePersnalDetails;
        elem->setSno(query.value(0).toString());
        personid = query.value(1).toString();
        elem->setPerson_id(query.value(1).toString());
        elem->setSevaname(query.value(2).toString());
        elem->setSevaDate(query.value(3).toString());
        elem->setReceiptDate(query.value(4).toString());
        elem->setTotalCost(query.value(5).toString());
        elem->setCash(query.value(6).toString());
        elem->setBank(query.value(7).toString());
        elem->setReference(query.value(8).toString());
        elem->setStatus(query.value(9).toString());
        elem->setAddress(query.value(10).toString());
        elem->setMomento(query.value(11).toString());
        qDebug() <<Q_FUNC_INFO << query.value(0).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(1).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(2).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(3).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(4).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(5).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(6).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(7).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(8).toString()<<Qt::endl;
        qDebug() <<"Suman status" << query.value(9).toString()<<Qt::endl;


        que_1 = ("select PERSONNAME,MOBILE from persondetails where persondetails.SNO='%1';");
        que_1 = que_1.arg(personid);

        qury.prepare(que_1);
        qury.exec();
        while(qury.next()){
            person->setDevoteeName(qury.value(0).toString());
            person->setMobileNumber(qury.value(1).toString());
            elem->setPerson(person);

            qDebug() <<Q_FUNC_INFO << qury.value(0).toString()<<Qt::endl;
            qDebug() <<Q_FUNC_INFO << qury.value(1).toString()<<Qt::endl;
        }
        emit sendOneSevaBooking(elem);
    }
}

bool DBInterface::querySevaType()
{
    QSqlQuery query_other;
    query_other.prepare("SELECT * FROM seva");
    query_other.exec();
    qDebug() <<Q_FUNC_INFO << Qt::endl;
    while(query_other.next()){
        QString sevaTypeName = query_other.value(1).toString();
        int sevaCode = query_other.value(2).toInt();
        qDebug() << Q_FUNC_INFO << "Inside while ---before if------ querying seva type " << Qt::endl;
        //        if (sevaCode < 2000) continue;
        //          if (sevaCode > 2000) continue;
        qDebug() << Q_FUNC_INFO << "Inside while --- after if------ querying seva type " << Qt::endl;
        SevaType *sevaTypeObject = new SevaType;
        sevaTypeObject->setObjectName("sevaTypeJsonProcessor");
        sevaTypeObject->setSevaTypeId(sevaCode);
        sevaTypeObject->setSevaTypeName(sevaTypeName);
        emit sendSevaType(sevaTypeObject);
    }
    qDebug() << Q_FUNC_INFO << "querying seva type done" << Qt::endl;
    return true;
}

bool DBInterface::querySevaNames()
{
    const QString status= "active";
    QSqlQuery qry;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,STATUS from sevaname ");
    qry.exec();
    while(qry.next()){
        int sevaId = qry.value(0).toInt();
        QString Sevastatus = qry.value(7).toString();
        if(Sevastatus == status || Sevastatus == NULL ){
            SevaName *sevaNames = new SevaName;
            sevaNames->setSevaId(sevaId);
            sevaNames->setNumber(qry.value(0).toInt());
            sevaNames->setSevaName(qry.value(1).toString());
            sevaNames->setSevaType(qry.value(2).toInt());
            sevaNames->setSevaCost(qry.value(3).toInt());
            sevaNames->setSevaStartDate(qry.value(4).toString());
            sevaNames->setObjectName("querysevaname_DBInterface");
            emit sendSevaName(sevaNames);
        }
        else{
            qDebug()<<"Status are closed"<<Qt::endl;
        }
    }
    qDebug() << Q_FUNC_INFO << "querying seva names done" << Qt::endl;
    return true;
}

void DBInterface::readSevaNamesFromJson() {
    //SevaTypeJsonProcessor proc;
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    connect(m_proc,&SevaTypeJsonProcessor::sendSevaName,
            this,[this](SevaName* sevaName){
                this->createSeva(sevaName);
            });
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    m_proc->readSevasFromJsonFormate();
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    m_proc->printSevasNames();
    qDebug() << Q_FUNC_INFO <<Qt::endl;
}

void DBInterface::readSevaTypesFromJson()
{
    //SevaTypeJsonProcessor proc;
    connect(m_proc,&SevaTypeJsonProcessor::sendSevaType,
            this,[this](SevaType* sevaType){
                this->add_seva_type(sevaType);
            });
    m_proc->readSevaTypeFromJsonFormate();
    m_proc->printSevaTypeNames();

}

QStringList DBInterface::qryNakshatras()
{
    QStringList nakshatras;
    nakshatras << "" << "Ashwini" << "Bharani" << "Krittika" << "Rohini"
               << "Mrigashira" << "Ardra" << "Punarvasu" << "Pushya"
               << "Ashlesha" << "Magha" << "Purvaphalguni"<<"Uttaraphalguni"
               << "Hasta" << "Chitra" << "Swati"<<"Vishakha"<<"Anuradha"
               << "Jyeshtha"<<"Moola"<<"Purvashadha"<<"Uttarashadha"
               << "Shravana"<< "Dhanishtha" <<"Shathabhisha" <<"Purvabhadrapada"
               << "Uttarabhadrapada"<<"Revati";
    return nakshatras;
}

QStringList DBInterface::qryGothras()
{
    QStringList list_gotra;
    QSqlQuery qury;
    qury.prepare("select * from persondetails");
    qury.exec();

    while(qury.next())
    {
        QString Gotra=qury.value(2).toString();
        if (Gotra.compare("-") == 0 || Gotra.compare("--") == 0) continue;
        bool alreadyExist = list_gotra.contains(Gotra);
        if( alreadyExist == true){
            continue;
        }else {
            list_gotra.append(Gotra);
        }
    }
    qDebug() << Q_FUNC_INFO << " Gothra List =" << list_gotra <<Qt::endl;
    return list_gotra;
}

QStringList DBInterface::qryBankList()
{
    JsonProcessor proc;
    proc.readBanksFromJsonToList();
    return proc.bankListAsStringList();
}




