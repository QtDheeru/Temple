#include "SevaViewProxy.h"
#include "./model/SevaListViewModel.h"
#include "./model/SevaTypeViewModel.h"
#include "../../Print/common.h"

#include "SevaTypeNamesDataModel.h"
#include <AllViewReports.h>
//#include <CancelModel>
#include <QScreen>
#include "print_file.h"
SevaViewProxy::SevaViewProxy(QObject *parent) : QObject(parent)
    ,m_sevaBookingModelData(SevaTypeNamesDataModel::self())
    ,m_currentSevaModel(nullptr)
    ,m_receiptNumber("-1")
    ,m_sevaTypeModel(nullptr)
{
    m_userMngmnt = new UserManagement;
    m_allReportModel  = new SevaDetailsTableView;
    m_allView = new AllViewReports;
    m_ReportOnDateModel = new SevaReport;
    m_csvReceipt = nullptr;
    m_voucherReportCSv = nullptr;
    m_sevaBookingTV = new SevaBookingTableModel;
    m_sevaBSearchModel = new SevaBookingSearchModel;
    m_sevacancelmodel = new SevaCancelModel;


    m_sevaBSearchModel->setSourceModel(m_sevaBookingTV);
    this->getNextReceiptNumber();

    //QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
    //               m_allReportModel,&SevaDetailsTableView::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_sevaBookingTV,&SevaBookingTableModel::addBookingDetails);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_ReportOnDateModel->sevaOnDateModel(),&SevaDetailsOnDateModel::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::account_report,
                     m_ReportOnDateModel->accountreportModel(),&AccountReportModel::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendFullAccountDataElement,
                     m_ReportOnDateModel->accountFullReportModel(),&AccountFullReportModel::insertrows);

    QObject::connect(DBInterface::getInstance(),&DBInterface::booking_report,
                     m_ReportOnDateModel->bookingReportModel(),&BookingReportModel::insertSevaRow);

    connect(this,&SevaViewProxy::collectAllAccountsdata,
            DBInterface::getInstance(),&DBInterface::getAccountData);

    //    QObject::connect(m_allView,&AllViewReports::exportCsvButtonClicked,
    //                     this,&SevaViewProxy::generateCSVSevaBookingReport);
    QDir dir(".");
    dir.mkdir("Data");
    QObject::connect(m_sevaBookingModelData,&SevaTypeNamesDataModel::error,this,
                     &SevaViewProxy::errorMessage);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sucessfully_added,m_userMngmnt,
                     &UserManagement::userAdded);

    QObject::connect(this,&SevaViewProxy::sendDeletedRecptNo,
                     DBInterface::getInstance(),&DBInterface::recvDeletedRecptNo);
    QObject::connect(DBInterface::getInstance(),&DBInterface::sendChangedDataToSevaBookingTablemodel,
                     m_sevaBookingTV,&SevaBookingTableModel::reset);
    QObject::connect(DBInterface::getInstance(),&DBInterface::refreshModel,m_sevaBookingTV,&SevaBookingTableModel::referseshTheModel);
    QObject::connect(DBInterface::getInstance(),&DBInterface::signalClosedStatus,this,&SevaViewProxy::rcvclosedStatus);
    QObject::connect(DBInterface::getInstance(),&DBInterface::sendUpdateStatus,this,&SevaViewProxy::recvUpdateStatus);

    //    QObject::connect(DBInterface::getInstance(),SIGNAL(forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>))
    //        ,m_allReportModel,SLOT(getData(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)));

    //    QString receiptno = "11592";
    //    getDataReceipt(receiptno);
}

QAbstractItemModel *SevaViewProxy::getSevaModel(int sevaType)
{
    qDebug() << Q_FUNC_INFO << " Seva Type =" << sevaType << Qt::endl;
    if (m_currentSevaModel == nullptr) {
        qDebug() << Q_FUNC_INFO << " Creating new object of SevaListViewModel :: Seva Type =" << sevaType << Qt::endl;
        m_currentSevaModel = new SevaListViewModel;
        QObject::connect(DBInterface::getInstance(),&DBInterface::signalClose,m_currentSevaModel,&SevaListViewModel::recvClosedObj);

        QQmlEngine::setObjectOwnership(m_currentSevaModel,QQmlEngine::CppOwnership);
    }
    m_currentSevaModel->initSevaList(sevaType);
    return m_currentSevaModel;
}

QAbstractItemModel *SevaViewProxy::getSevaTypeModel()
{
    if (m_sevaTypeModel == nullptr) {
        m_sevaTypeModel  = new SevaTypeViewModel;
        QQmlEngine::setObjectOwnership(m_sevaTypeModel,QQmlEngine::CppOwnership);
    }
    return m_sevaTypeModel;
}

QAbstractItemModel *SevaViewProxy::getBookedView()
{
    return this->m_sevaBookingModelData->getSevaBookingProgress();
}

bool SevaViewProxy::resetBookView()
{
    m_sevaBookingModelData->resetBookingProgressModel();
    return true;
}

SevaName* SevaViewProxy::getSeva(int sevaType, int sevaId)
{
    qDebug() << Q_FUNC_INFO << "sevaType = " << sevaType << " sevaId = " << sevaId << Qt::endl;
    return SevaTypeNamesDataModel::self()->getSevaDetails(sevaType,sevaId);
}

SevaName *SevaViewProxy::getSevaByIndex(int sevaType,int index)
{
    qDebug() << Q_FUNC_INFO << index << Qt::endl;
    qDebug() << "current.... seva model" << Qt::endl;
    Q_ASSERT(m_currentSevaModel != nullptr);
    qDebug() << "current seva model" << m_currentSevaModel << Qt::endl;
    return this->m_currentSevaModel->getSevaNameByIndex(sevaType,index);
}

SevaType *SevaViewProxy::getSevaTypeByIndex(int index)
{
    return this->m_sevaTypeModel->getSevaTypeByIndex(index);
}

void SevaViewProxy::print(int sevaType, int sevaId)
{
    SevaTypeNamesDataModel::self()->printSevaDetails(sevaType,sevaId);
}

QStringList SevaViewProxy::getNakshatras()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return SevaTypeNamesDataModel::self()->getNakshatras();
}

QStringList SevaViewProxy::getGothras()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return SevaTypeNamesDataModel::self()->getGothras();
}

QStringList SevaViewProxy::getBankList()
{
    return m_sevaBookingModelData->getBankList();
}

QString SevaViewProxy::getNextReceiptNumber()
{
    QString rNumber = m_sevaBookingModelData->getNextReceiptNumber();
    qDebug() <<Q_FUNC_INFO <<  " r number = " << rNumber << Qt::endl;
    if (m_receiptNumber.compare(rNumber) == 0) return m_receiptNumber;
    m_receiptNumber = rNumber;
    emit receiptNumberChanged();
    return m_receiptNumber;
}

QStringList SevaViewProxy::getMomentoCategory()
{
    QStringList category;
    category << "Category-1" << "Category-2"  << "Category-3"  << "Category-4" ;
    return  category;
}

bool SevaViewProxy::saveReceiptDetails(QString recNumber, QString devName, QString mobNumber, QString nakshatra, QString gothra)
{
    this->m_sevaBookingModelData->saveReceiptDetails(recNumber,devName,mobNumber,nakshatra,gothra);
    return true;
}

bool SevaViewProxy::saveReceipt(MySevaReceipt *receipt)
{
    qDebug() << Q_FUNC_INFO <<  Qt::endl;
    return m_sevaBookingModelData->saveReceipt(receipt);
}

void SevaViewProxy::cancelReceipt(QString a_recptno)
{
    qDebug() << Q_FUNC_INFO << "Receipt no in cancelReceipt " << a_recptno << Qt::endl;
    this->getDataReceipt(a_recptno);
}

void SevaViewProxy::deleteSevaBookingTableModel()
{
    //    m_sevaBookingTV
    delete m_sevaBookingTV;
}

void SevaViewProxy::cleanBookingTableModel()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_sevaBookingTV->clearData();
    QObject::disconnect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                        m_sevaBookingTV,&SevaBookingTableModel::addBookingDetails);
    QObject::disconnect(DBInterface::getInstance(),&DBInterface::sendChangedDataToSevaBookingTablemodel,
                        m_sevaBookingTV,&SevaBookingTableModel::reset);
    QObject::disconnect(DBInterface::getInstance(),&DBInterface::refreshModel,
                        m_sevaBookingTV,&SevaBookingTableModel::referseshTheModel);
    delete m_sevaBookingTV;
    m_sevaBookingTV = new SevaBookingTableModel;
    m_sevaBSearchModel->setSourceModel(m_sevaBookingTV);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_sevaBookingTV,&SevaBookingTableModel::addBookingDetails);
    QObject::connect(DBInterface::getInstance(),&DBInterface::sendChangedDataToSevaBookingTablemodel,
                     m_sevaBookingTV,&SevaBookingTableModel::reset);
    QObject::connect(DBInterface::getInstance(),&DBInterface::refreshModel,
                     m_sevaBookingTV,&SevaBookingTableModel::referseshTheModel);
}

void SevaViewProxy::setStatusToCancel(QString rcptNo){
    qDebug() << Q_FUNC_INFO << "rcptNo" << rcptNo << Qt::endl;
    //    this->checkIfStatusAlreadyCanceled(rcptNo);
    DBInterface::getInstance()->recvDeletedRecptNo(rcptNo);
}

void SevaViewProxy::getDataReceipt(QString receipt_no)
{
    qDebug() << Q_FUNC_INFO << "Inside getDataReceipt(QString) " << Qt::endl;

    m_recpt_details = DBInterface::getInstance()->getSewaBookingEntryForReceipt(receipt_no);
    qDebug() << Q_FUNC_INFO << "Iterating QList " << Qt::endl;
    for(SevaBookingElement *ele : m_recpt_details)
    {
        qDebug() << Q_FUNC_INFO << "s_no in QList" << ele->sno() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "person_id in QList" << ele->person_id() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "seva_type in QList" << ele->sevatype() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "seva_namein QList " << ele->sevaname() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "seva_costin QList " << ele->sevacost() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "Seva checked = " << ele->sevaChecked() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "Seva checked Status in getData" << ele->status() << Qt::endl;
    }
    m_sevacancelmodel->setData(m_recpt_details);
}

void SevaViewProxy::checkIfStatusAlreadyCanceled(QString a_recptNo)
{
    const QString l_checkStatus = "canceled";
    int l_count=0;

    qDebug() << "Number of objects in list " << m_recpt_details.size();
    for(SevaBookingElement *ele : m_recpt_details)
    {
        qDebug() << "Seva checked Status in statusCheck " << ele->status();
        if(ele->status() == l_checkStatus){
            l_count++;
        }
    }
    if(l_count == m_recpt_details.count()){
        emit statusAlreadyCancelled();
    }
    else{
        DBInterface::getInstance()->recvDeletedRecptNo(a_recptNo);
    }
}

QList<SevaBookingElement *> SevaViewProxy::recpt_details() const
{
    return m_recpt_details;
}

void SevaViewProxy::setRecpt_details(const QList<SevaBookingElement *> &newRecpt_details)
{
    m_recpt_details = newRecpt_details;
}

bool SevaViewProxy::addSevaOnly(int sevaType,int sevaId,QString sevaName,
                                double sevaCost, QString sevaDate, QString sevaTime,
                                int additionalCost,int count)
{
    qDebug() << Q_FUNC_INFO <<additionalCost << Qt::endl;

    SevaName *s = new SevaName;
    s->setSevaType(sevaType);
    s->setSevaId(sevaId);
    s->setSevaName(sevaName);
    s->setSevaCost(sevaCost);
    s->setAdditionalCost(additionalCost);
    s->setSevaStartDate(sevaDate);
    s->setSevaStartTime(sevaTime);
    s->setCount(count);
    return this->m_sevaBookingModelData->addSevaOnly(s);
}

bool SevaViewProxy::deleteSeva(int sevaid, QString sevaname){
    SevaName *s = new SevaName;
    s->setSevaName(sevaname);
    s->setSevaId(sevaid);
    this->m_sevaBookingModelData->deleteSeva(s);
    delete s;
    return true;
}

bool SevaViewProxy::closeSeva(int sevaId)
{
    qDebug() << Q_FUNC_INFO << sevaId << Qt::endl;
    DBInterface::getInstance()->closeSeva(sevaId);
    return true;
}

bool SevaViewProxy::modifySeva(int sevaId, QString sevaName,int cost, QString Date)
{
    DBInterface::getInstance()->modifySeva(sevaId,sevaName,cost,Date);
    return true;
}

bool SevaViewProxy::printReceipt()
{
    return m_sevaBookingModelData->printReceipt();
}

bool SevaViewProxy::printVoucherReceipt(VoucherElement *voucherElement)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    print_voucherDetails* p = new Print_VoucherDetail;
    int voucherNumber = voucherElement->voucherNo();
    qDebug() << Q_FUNC_INFO << " Voucher~~~~ " << voucherNumber << Qt::endl;
    p->VOUCHER_NO = QString::number(voucherNumber);
    p->VOUCHER_COST = voucherElement->voucherCost();
    p->VOUCHER_DATE = voucherElement->voucherDate();
    p->MOB_NO = voucherElement->mobileNo();
    p->VOUCHER_ITEM = voucherElement->voucherItem();
    p->VOUCHER_NAME = voucherElement->voucherName();
    p->VOUCHER_NOTE = voucherElement->voucherNote();
    p->VOUCHER_PAYMENT_MOD = voucherElement->voucherPaymentMode();
    p->VOUCHER_PAYMENT_REFERENCE = voucherElement->PaymentReference();
    p->VOUCHER_TYPE = voucherElement->voucherType();
    print_file file;
    file.printing_file(p);
    return true ;
}

bool SevaViewProxy::printBookingReceipt(SevaBookingElement *sevaBookingElement)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;

    QQmlEngine::setObjectOwnership(sevaBookingElement,QQmlEngine::CppOwnership);
    print_bookingDetails* p = new Print_BookingDetail;
    p->serial_No = sevaBookingElement->sno();
    p->person_Id = sevaBookingElement->person_id();
    p->devotee_Name = sevaBookingElement->person()->devoteeName();
    p->mobile_No = sevaBookingElement->person()->mobileNumber();
    p->gothra = sevaBookingElement->person()->gothra();
    p->nakshatra = sevaBookingElement->person()->nakshatra();
    p->seva_Type = sevaBookingElement->sevatype();
    p->seva_Name = sevaBookingElement->sevaname();
    p->sevacost = sevaBookingElement->sevacost();
    p->quantity = sevaBookingElement->quantity();
    p->receipt_Date = sevaBookingElement->receiptDate();
    p->seva_Date = sevaBookingElement->sevaDate();
    p->seva_time = sevaBookingElement->sevatime();
    p->total_Cost = sevaBookingElement->cash();
    p->cash = sevaBookingElement->cash();
    p->bank = sevaBookingElement->bank();
    print_file *file = new print_file;
    file->printing_file(p);
    return true ;
}

QString SevaViewProxy::getReceiptNumber() const
{
    return m_receiptNumber;
}

DevotePersnalDetails* SevaViewProxy::searchMobile(QString mobile)
{
    return this->m_sevaBookingModelData->searchMobile(mobile);
}

SevaDetailsTableView *SevaViewProxy::getAllReportModel() const
{

    return m_allReportModel;
}

void SevaViewProxy::setAllReportModel(SevaDetailsTableView *allReportModel)
{
    m_allReportModel = allReportModel;
}

bool SevaViewProxy::showAllData()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    bool b = DBInterface::getInstance()->dbtable_view();
    if(b==false)
    {
        return false;
    }
    //  QScreen *screen = qApp->primaryScreen();
    //  int w = screen->availableSize().width();
    //   int h = screen->availableSize().height()-30;
    //   m_allView->setFixedSize(w,h);
    //   m_allView->setWindowFlag(Qt::Dialog,true);
    //   m_allView->setWindowModality(Qt::ApplicationModal);
    //  m_allView->setWindowFlags(Qt::CustomizeWindowHint);
    //  m_allView->show();
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return true;
}

void SevaViewProxy::addNewSeva(int sevaID, QString sevaName, int cost)
{
    SevaName *s = new SevaName;
    s->setSevaName(sevaName);
    s->setSevaCost(cost);
    s->setSevaType(sevaID);
    s->setSankalpa(false);
    s->setTeerthaPrasada(1);
    s->setSevaStartDate(QDate::currentDate().toString("dd.MM.yyyy"));
    s->setSevaStartTime("09:00 AM");
    s->setSevaId(1111);
    DBInterface::getInstance()->createSeva(s);
}

int SevaViewProxy::getNextSevaId()
{
    return DBInterface::getInstance()->getNextSevaId();
}

int SevaViewProxy::getNextSevaTypeID()
{
    qDebug()<<Q_FUNC_INFO<< DBInterface::getInstance()->getLastSevatypeNumber()<<Qt::endl;
    return DBInterface::getInstance()->getLastSevatypeNumber();
}

QString SevaViewProxy::addNewSevaType(QString sevaTypeName,int sevaTypeId ,QString personName)
{
    bool value;
    SevaType *sevatype;
    qDebug() << Q_FUNC_INFO << Qt::endl;
    if(DBInterface::getInstance()->add_seva_type(sevaTypeName,sevaTypeId,personName))
    {
        sevatype = SevaTypeNamesDataModel::self()->addSevaTypeDetail(sevaTypeId,sevaTypeName,personName);
        m_sevaTypeModel->reflectToView(sevatype);
    }
    return DBInterface::getInstance()->getError();
}

QString SevaViewProxy::createNewSeva(SevaName *seva)
{
    qDebug()<<Q_FUNC_INFO<<seva->sevaName()<<seva->sevaId()<<seva->Number()<<seva->sevaCost()<<seva->sevaStartDate()<<seva->sevaType()<<seva->sevaCost()<<seva->count()<<seva->sevaStartTime();
    seva->print();
    seva->setStatus("active");
    return m_sevaBookingModelData->createNewSeva(seva);
}

void SevaViewProxy::deletedata(QString rcptNo)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DBInterface::getInstance()->deleteWrongData(rcptNo);
}

void SevaViewProxy::print()
{
}

void SevaViewProxy::generateCSVSevaBookingReport()
{
    qDebug()<<Q_FUNC_INFO<<"genrarte CSV Sevabooking Report"<<Qt::endl;
    if(m_csvReceipt!=nullptr)
        delete m_csvReceipt;
    m_csvReceipt = new SevaReceiptCsvProcessor;
    QObject::connect(DBInterface::getInstance(),&DBInterface::sendoneByoneSevaBooking,
                     m_csvReceipt,&SevaReceiptCsvProcessor::writeToCsvFormate);
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DBInterface::getInstance()->getDbData();
    qDebug() << Q_FUNC_INFO << Qt::endl;
    emit successMessage("Export Completed!");
}

void SevaViewProxy::getAllAccountDetails()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    emit collectAllAccountsdata();
}

void SevaViewProxy::rcvclosedStatus(QString status)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    emit sendStatustoQml(status + " Successfully");
}

void SevaViewProxy::recvUpdateStatus(QString updatestatus)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    emit sendUpdateStatustoQml(updatestatus);
}

SevaTypeNamesDataModel *SevaViewProxy::sevaBookingModelData() const
{
    return m_sevaBookingModelData;
}

bool SevaViewProxy::removeSevaProgress(int index,QString sevaname)
{
    qDebug()<<Q_FUNC_INFO<<index<<" "<<sevaname<<Qt::endl;
    this->m_sevaBookingModelData->getSevaBookingProgress()->removerow(index);
    m_sevaBookingModelData->getSevaBookingConformationDataModel()->removeSeva(index,sevaname);
    return true;
}

SevaCancelModel *SevaViewProxy::sevacancelmodel() const
{
    return m_sevacancelmodel;
}

void SevaViewProxy::setSevacancelmodel(SevaCancelModel *newSevacancelmodel)
{
    m_sevacancelmodel = newSevacancelmodel;
}

UserManagement *SevaViewProxy::userMngmnt() const
{
    return m_userMngmnt;
}

SevaBookingSearchModel *SevaViewProxy::sevaBSearchModel() const
{
    return m_sevaBSearchModel;
}

SevaBookingTableModel *SevaViewProxy::sevaBookingTV()
{
    if(m_sevaBookingTV == nullptr)
    {
        m_sevaBookingTV = new SevaBookingTableModel;
    }
    return m_sevaBookingTV;
}

void SevaViewProxy::addNewSigninDetails(QString name, QString lastname, QString userid, QString password, int rolenumber, QString date)
{
    qDebug()<<Q_FUNC_INFO<<name<<lastname<<userid<<password<<rolenumber<<date<<Qt::endl;
    DBInterface::getInstance()->add_new_signin_details(name,lastname,userid,password,rolenumber,"");
}

SevaReport *SevaViewProxy::reportOnDateModel() const
{
    return m_ReportOnDateModel;
}

void SevaViewProxy::setReportOnDateModel(SevaReport *newReportOnDateModel)
{
    m_ReportOnDateModel = newReportOnDateModel;
}

SevaTypeNamesDataModel *SevaViewProxy::getSevaTypeNamesDataModel()
{
    return m_sevaBookingModelData;
}
QAbstractItemModel *SevaViewProxy::getSevaModelForErrorHandling()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_currentSevaModel;
}
