﻿#include "DBInterface.h"
#include "DevotePersnalDetails.h"
#include "SevaJson/SevaTypeJsonProcessor.h"
#include "./model/SevaName.h"
#include "SevaBookingConformationDataModel.h"
#include "SevaName.h"
#include "SevaJson/JsonProcessor.h"

DBInterface *DBInterface::init =nullptr;
static int BID=0;
static int SID=0;
static int RID=0;
//static int SET=0 ;
static int TID=0 ;


//delete from sevaname where SNO>=1000;
DBInterface::DBInterface(QObject *parent) : QObject(parent)
{
    BID=0;
    TID=0;
    SID=0;
    RID=0;
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

    QSqlQuery qry;
    if(ok)
    {
        qDebug()<<"Database is opened " << currentPath<<Qt::endl;
    }
    else{
        qDebug()<<"Database is NOT opened " <<currentPath <<Qt::endl;

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
                     "SANKALAPAPOOJA);";

    QString query2 = "CREATE TABLE sevabooking("
                     "SNO,"
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
                     "SEVACOST,"
                     "ADDITIONALCOST,"
                     "SEVATOTALPRICE,"
                     "NOTE,"
                     "CASH TEXT(30),"
                     "BANK TEXT(30),"
                     "BANKDETAILS TEXT(30));";

    QString query3 = "CREATE TABLE persondetails("
                     "SNO,"
                     "PERSONNAME,"
                     "GOTHRA,"
                     "NAKSHATRA,"
                     "DATE,"
                     "MOBILE,"
                     "EMAIL);";

    QString query4 = "CREATE TABLE signindetails("
                     "SNO,"
                     "FIRSTNAME,"
                     "LASTNAME,"
                     "USERNAME,"
                     "PASSWORD,"
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
                     "DATES);";

    qry.prepare(query);
    qry.prepare(query1);
    qry.prepare(query2);
    qry.prepare(query3);
    qry.prepare(query4);
    qry.prepare(query5);
    qry.prepare(query6);
    //    qry.exec();

    m_proc = new SevaTypeJsonProcessor;
    readSevaTypesFromJson();
    readSevaNamesFromJson();
}

void DBInterface::add_seva_type(QString seva_type, int seva_code,QString seva_adder_name)
{
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    BID = BID +1;

    QSqlQuery Squery;
    Squery.prepare("INSERT INTO seva(SNO,SEVATYPE,SEVACODE,PERSON)"
                   "VALUES (:sno, :seva_name, :seva_code, :person_name)");
    Squery.bindValue(":sno",BID);
    Squery.bindValue(":seva_name",seva_type);
    Squery.bindValue(":seva_code",seva_code );
    Squery.bindValue(":person_name",seva_adder_name);

    qDebug() << Q_FUNC_INFO <<BID;
    qDebug() << Q_FUNC_INFO <<seva_type;
    qDebug() << Q_FUNC_INFO <<seva_code;
    qDebug() << Q_FUNC_INFO <<seva_adder_name;
    Squery.exec();
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
    QSqlQuery query_sevaID;
    query_sevaID.exec();
    
    QDate Date1 = QDate::fromString(strold_date,"dd-MM-yyyy");
    QString str_date  = Date1.toString("yyyy-MM-dd");

    SID = SID +1;
    QSqlQuery Squery;
    Squery.prepare("INSERT INTO sevaname(SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,POOJATIMEING,SANKALAPAPOOJA)"
                   "VALUES (:sno, :seva_name, :seva_type, :seva_cost, :seva_date, :seva_adder_name, :t_prasada, :pooja_time, :pooja  )");
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

bool DBInterface::addsevaname(SevaName* sevaName)
{
    qDebug () << Q_FUNC_INFO << " Seva Requested to Add = " << sevaName->sevaId() <<Qt::endl;
    QSqlQuery qry;
    qry.prepare("select * from sevaname where SNO=:sno");
    qry.bindValue(":sno",sevaName->sevaId());
    qry.exec();
    while(qry.next()){
        int snu =qry.value(0).toInt();
        qDebug () << Q_FUNC_INFO << " Seva Name in DB =" << snu <<Qt::endl;
        if (snu == sevaName->sevaId()){
            qWarning() << Q_FUNC_INFO << " Seva with ID = " << sevaName->sevaId() << "already exist in DB" <<Qt::endl;
            return false;
        }
    }

    QSqlQuery Squery;
    Squery.prepare("INSERT INTO sevaname(SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA,POOJATIMEING,SANKALAPAPOOJA)"
                   "VALUES (:sno, :seva_name, :seva_type, :seva_cost, :seva_date, :seva_adder_name, :t_prasada, :pooja_time, :pooja  )");
    Squery.bindValue(":sno",sevaName->sevaId());
    Squery.bindValue(":seva_name",sevaName->sevaName());
    Squery.bindValue(":seva_type",sevaName->sevaType());
    Squery.bindValue(":seva_cost",sevaName->sevaCost());
    Squery.bindValue(":seva_date",sevaName->sevaDate());
    Squery.bindValue(":seva_adder_name",sevaName->userName());
    Squery.bindValue(":t_prasada",sevaName->teerthaPrasada());
    Squery.bindValue(":pooja_time",sevaName->sevaTime());
    Squery.bindValue(":pooja",sevaName->sankalpa());

    qDebug() << Q_FUNC_INFO << "**** Seva name added *******" <<Qt::endl;
    sevaName->print();
    Squery.exec();
    return true;
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
void DBInterface::insertSevaBooked(QString devoteMobile, QString devoteName, QString devoteNakshatra, QString devoteGotra, QString devoteSevacharge, QString devoteAdditionalcharges, QString devoteCount, QString devotereceiptdate, QString devoteSevadate, QString devoteNote, QString devoteSevaName, int cost, int rspt_no, QString cash, QString bank_ref, QString bank_name,
                                   QString sevaType,QString reference,QString address,QString momento)
{
    qDebug()<<Q_FUNC_INFO << " Mobile number is "<<devoteMobile<<"\n";
    qDebug() << Q_FUNC_INFO << "gotra ===  > " << devoteGotra ;

    QSqlQuery qury;

    QString qr1 = QString("select * from sevaname where sevaname='%1'").arg(devoteSevaName);
    //qury.prepare("select * from sevaname");
    qury.prepare(qr1);
    QString devoteSevaType;
    qury.exec();
    while(qury.next()){
        RID=qury.value(0).toInt();
        QString val1=qury.value(1).toString();
        devoteSevaType=qury.value(2).toString();
    }
    qDebug() << Q_FUNC_INFO << " Name =" << devoteSevaName << " Query Size ="<<qury.size() << " Type=" << devoteSevaType <<  Qt::endl;

    // Check if devotee exist in DB.
    int personId = insertPersonDetails(devoteMobile,devoteName,devoteNakshatra,devoteGotra);
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
    qry.prepare("INSERT INTO sevabooking(SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE, NOTE, CASH, BANK, BANKDETAILS, REFERENCE, ADDRESS, MOMENTO)"
                    "VALUES (:sno, :person_id, :sevatype, :sevaname, :quantity, :s_date, :s_month, :s_year, :seva_date, :r_date, :r_month,:r_year, :receipt_date, :seva_cost, :additionalcost, :sevatotalprice, :note, :cash, :bank, :bankdetails, :reference, :address, :momento)");
    qry.bindValue(":sno",rspt_no);
    qry.bindValue(":person_id",personId);
    qry.bindValue(":sevatype",sevaType );
    qry.bindValue(":sevaname",devoteSevaName);
    qry.bindValue(":quantity",devoteCount );
    qry.bindValue(":s_date",sday);
    qry.bindValue(":s_month",smonth );
    qry.bindValue(":s_year",syear );
    qry.bindValue(":seva_date",devoteSevadate);
    qry.bindValue(":r_date",rday);
    qry.bindValue(":r_month",rmonth );
    qry.bindValue(":r_year",ryear );
    qry.bindValue(":receipt_date",devotereceiptdate);
    qry.bindValue(":seva_cost",devoteSevacharge );
    qry.bindValue(":additionalcost",devoteAdditionalcharges);
    qry.bindValue(":sevatotalprice",cost);
    qry.bindValue(":note",devoteNote );
    qry.bindValue(":cash", cash);
    qry.bindValue(":bank",bank_ref);
    qry.bindValue(":bankdetails",bank_name);
    qry.bindValue(":reference",reference);
    qry.bindValue(":address",address);
    qry.bindValue(":momento",momento);
    bool retVal = qry.exec();
    if (!retVal){
        qDebug() << Q_FUNC_INFO << " Query Failed " << qry.lastError().text() <<Qt::endl;
    }
    qDebug()<<Q_FUNC_INFO<<"  exiting...\n";
}

int DBInterface::insertPersonDetails(QString devoteMobile,QString devoteName,QString devoteNakshatra,QString devoteGotra)
{
    qDebug()<<Q_FUNC_INFO<<" entered\n";

    bool found = false;
    int  personId = -1;

    qDebug()<<Q_FUNC_INFO << " Name: "<<devoteName<<" Mobile: "<<devoteMobile <<"\n";

    QSqlQuery qry;

    QString stringQry = QString("select * from persondetails where mobile=%1").arg(devoteMobile.trimmed());
    qry.prepare(stringQry);
    bool result = qry.exec();
    qDebug() << Q_FUNC_INFO << " String to Query ="<<stringQry <<Qt::endl;
    qDebug()<< Q_FUNC_INFO << " Query Result =" << result << " Size =" << qry.size() <<Qt::endl;
    if (!qry.next()){
        qry.clear();
        qDebug() << Q_FUNC_INFO << " Devotee not in table. Insert" <<Qt::endl;
        QString lastRecord = "select * from persondetails";
        QSqlQuery qry1;
        qry1.prepare(lastRecord);
        qry1.exec();
        qDebug() << Q_FUNC_INFO << " Query Size =" << qry1.size() <<Qt::endl;
        while(qry1.next()){
            personId = qry1.value(0).toInt();
        }
        personId++;
        qDebug() << Q_FUNC_INFO << " Size =" << qry1.size() << " Person ID="<<personId << " Value ="<<qry1.value(0)<<Qt::endl;

        QSqlQuery qry;
        qry.prepare("INSERT INTO persondetails(SNO,PERSONNAME,GOTHRA,NAKSHATRA,DATE,MOBILE)"
                    "VALUES (:sno, :person_name, :gothra, :nakshatra, :date, :mobile)");
        qry.bindValue(":sno",personId);
        qry.bindValue(":person_name",devoteName);
        qry.bindValue(":gothra",devoteGotra);
        qry.bindValue(":nakshatra",devoteNakshatra );
        qry.bindValue(":date",QDate::currentDate().toString("dd-MMM-yyyy"));
        qry.bindValue(":mobile",devoteMobile);
        if( qry.exec()){
            qDebug() << Q_FUNC_INFO << " Person insert success full"<< devoteMobile <<Qt::endl;
        }
    }else {
        qDebug() << Q_FUNC_INFO << " Devotee = " << devoteMobile << " exist in table ..." <<Qt::endl;
        //        while(qry.next())
        //        {
        personId=qry.value(0).toInt();
        QString mobileDB=qry.value(5).toString();
        QString nameDB=qry.value(1).toString();
        if(mobileDB==devoteMobile){
            found =true;
            qDebug()<<"Mobile number  "<<devoteMobile<<" is found\n";

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
    while(qry.next())
    {
        RID=qry.value(0).toInt();
        QString val1 = qry.value(5).toString();
        QString val2 = qry.value(1).toString();

        if(val1==devoteMobile)
        {
            found =true;
            qDebug()<<"Mobile number  "<<devoteMobile<<" is found\n";

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
        qry.bindValue(":sno",RID);
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

void DBInterface::dbtable_view()
{
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^1111111^^^^^^^^^^^^^^^^^^"<<Qt::endl;

    //QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note,l_cash,l_bank,l_BankDeatils,l_Ref,l_add,l_momento;
    QString str;
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^222222^^^^^^^^^^^^^^^^^^"<<Qt::endl;
    //str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS,REFERENCE,ADDRESS,MOMENTO from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    query_other1.exec();
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^3333333^^^^^^^^^^^^^^^^^^  " << query_other1.size() <<Qt::endl;

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
        emit sendOneSevaBooking(elem);
    }
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^3333333^^^^^^^^^^^^^^^^^^"<<Qt::endl;
}

void DBInterface::getDbData()
{
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^1111111^^^^^^^^^^^^^^^^^^"<<Qt::endl;

    //QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note;
    QList<QString> l_sno,l_person_id,l_sevatype,l_sevaname,l_quantity,l_s_date,l_s_month,l_s_year ,l_sevadate,l_r_date,l_r_month,l_r_year,l_receiptdate,l_seva_cost,l_add_cost,l_total_cost,l_note,l_cash,l_bank,l_BankDeatils,l_Ref,l_add,l_momento;
    QString str;
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^222222^^^^^^^^^^^^^^^^^^"<<Qt::endl;
    //str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE from sevabooking;" );
    str = ("select SNO,PERSONID,SEVATYPE,SEVANAME,QUANTITY,S_DATE,S_MONTH,S_YEAR,SEVA_DATE,R_DATE,R_MONTH,R_YEAR,RECEIPT_DATE,SEVACOST,ADDITIONALCOST,SEVATOTALPRICE,NOTE,CASH,BANK,BANKDETAILS,REFERENCE,ADDRESS,MOMENTO from sevabooking;" );
    QSqlQuery query_other1;
    query_other1.prepare(str);
    query_other1.exec();
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^3333333^^^^^^^^^^^^^^^^^^  " << query_other1.size() <<Qt::endl;

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
    qDebug()<<Q_FUNC_INFO<<"^^^^^^^^^^^^^^^3333333^^^^^^^^^^^^^^^^^^"<<Qt::endl;
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
    SevaBookingConformationDataModel *sevaData = qobject_cast<SevaBookingConformationDataModel*>(obj);
    MySevaReceipt *rec = sevaData->sevaReceipt();
    qDebug() << Q_FUNC_INFO << " ****8888 NOte =" << rec->note() <<Qt::endl;
    qDebug() << Q_FUNC_INFO << rec->gothra() << Qt::endl;
    QList<SevaName*> sevas = sevaData->sevabookinglist();
    Q_ASSERT(sevaData != nullptr);
    for(int i=0;i<sevas.size();i++){
        SevaName *seva = sevas.at(i);
        qDebug() << Q_FUNC_INFO <<  "Add ############ ="<< seva->additionalCost() << Qt::endl;
        this->insertSevaBooked(rec->mobilenumber(),rec->devoteeName(),
                               rec->nakshtra(),rec->gothra(),
                               QString::number(seva->sevaCost()),QString::number(seva->additionalCost()),
                               QString::number(seva->count()),rec->receiptDate(),
                               seva->sevaDate(),rec->note(),
                               seva->sevaName(),(seva->sevaCost()*seva->count())+seva->additionalCost(),
                               rec->receiptNo().toInt(),rec->cash(),
                               rec->bank(),rec->checkOrTranscationId(),
                               QString("%1").arg(seva->sevaType()),
                               rec->reference(),rec->address(),rec->momento());
    }
    return true;
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
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QList<float> list_cost,list_total;

    qDebug()<<"\nChanged format is: "<<formatchangedcalendar_str<<Qt::endl;

    QString que;
    if(TYPE==0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1';");
        que = que.arg(formatchangedcalendar_str);
    }
    else if (SEVA==ALLSEVANAME) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2'; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else {

        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.SEVA_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3'; ");
        que = que.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que <<Qt::endl;
    QSqlQuery query_other1;
    query_other1.prepare(que);
    query_other1.exec();

    QSqlQuery query;
    while(query_other1.next())
    {
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
        sevadate = yy_date.toString("dd-MM-yyyy") ;
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);
        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }
        total_prasada=total_prasada+prasada;
    }
    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

}

void DBInterface::booking_report_cmonth_function(QString SEVA,int TYPE,int month,int year)
{
    total_prasada=0;
    QList<QString> list_sevaname,list_sevadate,list_pname,list_gotra,list_nakshatra,list_mobile,list_note;
    QList<int> list_prasada,list_quantity,list_ticket;
    QSqlQuery query_other1;
    QString que;
    if(TYPE == 0) {
        que = ("select PERSONID,SEVANAME,QUANTITY,SEVA_DATE,SEVATOTALPRICE,NOTE from sevabooking where sevabooking.S_MONTH='%1' and sevabooking.S_YEAR='%2' ; ");
        que = que.arg(month).arg(year);
    }
    else if (SEVA==ALLSEVANAME) {

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
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }
        prasada =prasada*quantity;
        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
        sevadate = yy_date.toString("dd-MM-yyyy") ;
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }

        total_prasada=total_prasada+prasada;
    }

    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);

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
        personid = query_other1.value(0).toString();
        p_sevaname = query_other1.value(1).toString();
        list_sevaname.append(p_sevaname);
        quantity = query_other1.value(2).toInt();
        list_quantity.append(quantity);
        query.prepare("SELECT * FROM sevaname");
        query.exec();
        while(query.next())
        {
            QString val = query.value(1).toString();
            if(val == p_sevaname)//regular seva at 1st index in combo
            {
                prasada = query.value(6).toInt();
                list_prasada.append(prasada);
            }
        }

        prasada =prasada*quantity;
        yy_date=QDate::fromString(query_other1.value(3).toString(),"yyyy-MM-dd");//cost
        qDebug()<<"DD-MM-YYYY is "<<yy_date<<Qt::endl;
        sevadate = yy_date.toString("dd-MM-yyyy") ;
        list_sevadate.append(sevadate);
        note=query_other1.value(5).toString();//total
        list_note.append(note);

        QSqlQuery query_other2;//person details
        query_other2.prepare("SELECT * FROM  persondetails");
        query_other2.exec();
        while(query_other2.next())
        {
            QString p_id = query_other2.value(0).toString();
            if(personid==p_id){
                p_name=query_other2.value(1).toString();
                p_gotra=query_other2.value(2).toString();
                p_nakshtra=query_other2.value(3).toString();
                p_mobile=query_other2.value(5).toString();
                list_pname.append(p_name);
                list_gotra.append(p_gotra);
                list_nakshatra.append(p_nakshtra);
                list_mobile.append(p_mobile);
            }
        }
        total_prasada=total_prasada+prasada;
    }
    emit booking_report(list_sevaname,list_quantity,list_prasada,list_sevadate,list_note,list_pname,list_gotra,list_nakshatra,list_mobile);
}

DBInterface::~DBInterface()
{

}

void DBInterface::account_report_cdate_function(QString SEVA,int TYPE,QString formatchangedcalendar_str)
{
    qDebug()<<formatchangedcalendar_str<<"^^^^^^^^^^^^^^^^^^^^^^^^^^"<<Qt::endl;
    QList<QString> list_name;
    QList<int> list_ticket;
    QList<float> list_cost,list_total;
    QSqlQuery query_other1;
    QString que1;
    AccountReportElement ele;
    if(TYPE==0) {
        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' Group by sevabooking.SEVANAME");
        que1 = que1.arg(formatchangedcalendar_str);

    }
    else if (SEVA==ALLSEVANAME) {
        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' Group by sevabooking.SEVANAME; ");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE);
    }
    else {

        que1 = ("select SEVANAME,sum(QUANTITY),SEVACOST,sum(ADDITIONALCOST+(QUANTITY*SEVACOST)) from sevabooking where sevabooking.RECEIPT_DATE='%1' and sevabooking.SEVATYPE='%2' and sevabooking.SEVANAME = '%3' Group by sevabooking.SEVANAME; ");
        que1 = que1.arg(formatchangedcalendar_str).arg(TYPE).arg(SEVA);
    }

    qDebug() << " Query string =" << que1 <<Qt::endl;
    query_other1.prepare(que1);
    query_other1.exec();

    while(query_other1.next())
    {
        AccountReportElement *ele = new AccountReportElement;
        ele->setSeva_name( query_other1.value(0).toString());
        ele->setSeva_ticket( query_other1.value(1).toInt());
        ele->setSeva_cost(query_other1.value(2).toFloat());//cost
        ele->setSeva_total(query_other1.value(3).toFloat());//total
        qDebug() << query_other1.value(0).toString()<<endl;
        qDebug() << query_other1.value(1).toString()<<endl;
        qDebug() << query_other1.value(2).toString()<<endl;
        qDebug() << query_other1.value(3).toString()<<endl;
        emit account_report(ele);

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

void DBInterface::add_new_signin_details(QString fname, QString lname, QString username, QString password,QString date)
{

    QSqlQuery query_s_no;
    QMessageBox msgbox;
    query_s_no.prepare("select SNO from signindetails");
    query_s_no.exec();
    while(query_s_no.next()){
        TID =query_s_no.value(0).toInt();
        qDebug()<<TID<<Qt::endl;
    }
    bool found =false;
    QSqlQuery qry;
    qry.prepare("select SNO,FIRSTNAME,LASTNAME from signindetails");
    qry.exec();
    while(qry.next())
    {
        QString val1=qry.value(1).toString();
        int val2=qry.value(2).toInt();
        qDebug()<<Q_FUNC_INFO<<val1<<Qt::endl;
        qDebug()<<Q_FUNC_INFO<<val2<<Qt::endl;

        qDebug()<<Q_FUNC_INFO<< fname<<lname<<username<<  password<< date<<"%%%%%%%%%%%%"<<val1<<val2<<Qt::endl;

        if((fname==val1)||(lname==val2))
        {
            found =true;
            msgbox.setText(tr("ITS ALLREADY EXIST"));
            msgbox.exec();
            return;
            break;
        }
    }
    if(!found)
    {
        QSqlQuery Squery;
        Squery.prepare("INSERT INTO signindetails(SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE)"
                       "VALUES (:sno, :first_name, :last_name, :user_name, :password, :date)");
        TID = TID +1;
        Squery.bindValue(":sno",TID);
        Squery.bindValue(":first_name",fname);
        Squery.bindValue(":last_name",lname );
        Squery.bindValue(":user_name",username);
        Squery.bindValue(":password",password);
        Squery.bindValue(":date",date);
        Squery.exec();
        emit sucessfully_added();
    }
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
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO,FIRSTNAME,LASTNAME,USERNAME,PASSWORD,DATE from signindetails");
    query_s_no.exec();
    //    qDebug() << Q_FUNC_INFO << "Size of query == " << query_s_no.size()<<Qt::endl;
    while(query_s_no.next())
    {
        QString user_name=query_s_no.value(3).toString();
        QString pass_word=query_s_no.value(4).toString();
        //        qDebug() << Q_FUNC_INFO << "db id and password ==  " << user_name << pass_word;
        if(userID==user_name && pass == pass_word){
            emit success();
            return true;
        }
    }
    qDebug() << Q_FUNC_INFO << userID << pass << Qt::endl;
    emit wrongCred();
    return false;
}

int DBInterface::getNextSevaId()
{
    QSqlQuery query_s_no;
    query_s_no.prepare("select SNO from sevaname");
    query_s_no.exec();
    int lastId = 0;
    qDebug() << Q_FUNC_INFO << "Size of query == " << query_s_no.size()<<Qt::endl;
    while(query_s_no.next())
    {
        lastId = query_s_no.value(0).toInt();
    }
    qDebug() << Q_FUNC_INFO << "last ID == " << lastId+1<<Qt::endl;
    return lastId+1;
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

void DBInterface::qrySevabookingBySevaDate(QString formatchangedcalendar_str)
{

    QSqlQuery query;
    QSqlQuery qury;
    QString que,que_1;
    //    QString list_recNo, list_names, list_mobileNo, list_sevaNames,list_sevaDates,list_receiptDates,list_totalPrice;
    //    QString list_cash,list_bank,list_reference,list_address,list_momemto;

    que = ("select SNO,PERSONID,SEVANAME,SEVA_DATE,RECEIPT_DATE,SEVATOTALPRICE,CASH,BANK,reference,address,momento from sevabooking where sevabooking.SEVA_DATE='%1';");
    que = que.arg(formatchangedcalendar_str);
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
        elem->setAddress(query.value(9).toString());
        elem->setMomento(query.value(10).toString());
        qDebug() <<Q_FUNC_INFO << query.value(0).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(1).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(2).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(3).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(4).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(5).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(6).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(7).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(8).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(9).toString()<<Qt::endl;


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

void DBInterface::qrySevabookingByDateRange(QString startDate, QString endDate)
{
    QSqlQuery query;
    QSqlQuery qury;
    QString que,que_1;
    //    QString list_recNo, list_names, list_mobileNo, list_sevaNames,list_sevaDates,list_receiptDates,list_totalPrice;
    //    QString list_cash,list_bank,list_reference,list_address,list_momemto;

    que = ("select SNO,PERSONID,SEVANAME,SEVA_DATE,RECEIPT_DATE,SEVATOTALPRICE,CASH,BANK,reference,address,momento from sevabooking where sevabooking.SEVA_DATE between '%1' and '%2';");
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
        elem->setAddress(query.value(9).toString());
        elem->setMomento(query.value(10).toString());
        qDebug() <<Q_FUNC_INFO << query.value(0).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(1).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(2).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(3).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(4).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(5).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(6).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(7).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(8).toString()<<Qt::endl;
        qDebug() <<Q_FUNC_INFO << query.value(9).toString()<<Qt::endl;


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
        sevaTypeObject->setSevaTypeId(sevaCode);
        sevaTypeObject->setSevaTypeName(sevaTypeName);
        emit sendSevaType(sevaTypeObject);
    }
    qDebug() << Q_FUNC_INFO << "querying seva type done" << Qt::endl;
    return true;
}

bool DBInterface::querySevaNames()
{
    QSqlQuery qry;
    qry.prepare("select SNO,SEVANAME,SEVATYPE,SEVACOST,SEVADATE,PERSON,THEERTHAPRASADA from sevaname ");
    qry.exec();
    while(qry.next()){
        int sevaId = qry.value(0).toInt();
        // if (sevaId < 1000) continue;
        SevaName *sevaNames = new SevaName;
        sevaNames->setSevaId(sevaId);
        sevaNames->setNumber(qry.value(0).toInt());
        sevaNames->setSevaName(qry.value(1).toString());
        sevaNames->setSevaType(qry.value(2).toInt());
        sevaNames->setSevaCost(qry.value(3).toInt());
        sevaNames->setSevaDate(qry.value(4).toString());
        emit sendSevaName(sevaNames);
    }
    qDebug() << Q_FUNC_INFO << "querying seva names done" << Qt::endl;
    return true;
}

void DBInterface::readSevaNamesFromJson() {
    //SevaTypeJsonProcessor proc;
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    connect(m_proc,&SevaTypeJsonProcessor::sendSevaName,
            this,[this](SevaName* sevaName){
        this->addsevaname(sevaName);
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
    nakshatras << "Ashwini" << "Bharani" << "Krittika" << "Rohini"
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
        if( alreadyExist==true){
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
    //    QStringList banks;
    //    banks << "SBI" << "HDFC"<< "ICICI"<<"CanaraBank"
    //          << "UnionBank"<<"BankOfBaroda"<<"Karnataka"
    //          << "PNB" << "BankOfMaharashtra" <<"HSBC";
    //    return banks;
}



