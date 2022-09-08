#include "SevaViewProxy.h"
#include "./model/SevaListViewModel.h"
#include "./model/SevaTypeViewModel.h"
#include "SevaTypeNamesDataModel.h"
#include <AllViewReports.h>
#include <QScreen>

SevaViewProxy::SevaViewProxy(QObject *parent) : QObject(parent)
  ,m_sevaBookingModelData(SevaTypeNamesDataModel::self())
  ,m_receiptNumber("-1")
{
    m_allReportModel  = new SevaDetailsTableView;
    m_allView = new AllViewReports;
    m_ReportOnDateModel = new SevaReport;
    m_csvReceipt = nullptr;

    this->getNextReceiptNumber();

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_allReportModel,&SevaDetailsTableView::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_allView,&AllViewReports::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendOneSevaBooking,
                     m_ReportOnDateModel->sevaOnDateModel(),&SevaDetailsOnDateModel::insertSevaRow);

    QObject::connect(DBInterface::getInstance(),&DBInterface::account_report,
                     m_ReportOnDateModel->accountreportModel(),&AccountReportModel::insertSevaRow);

    QObject::connect(m_allView,&AllViewReports::exportCsvButtonClicked,
                     this,&SevaViewProxy::generateCSV);
    QDir dir(".");
    dir.mkdir("Data");


    //    QObject::connect(DBInterface::getInstance(),SIGNAL(forFUllDetails(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>))
    //        ,m_allReportModel,SLOT(getData(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>)));
}

QAbstractItemModel *SevaViewProxy::getSevaModel(int sevaType)
{
    qDebug() << Q_FUNC_INFO << " Seva Type =" << sevaType << Qt::endl;
    m_currentSevaModel = new SevaListViewModel;
    m_currentSevaModel->initSevaList(sevaType);
    return m_currentSevaModel;
}

QAbstractItemModel *SevaViewProxy::getSevaTypeModel()
{
    qDebug() << Q_FUNC_INFO << " ###############"  << Qt::endl;
    SevaTypeViewModel *mod  = new SevaTypeViewModel;
    return mod;
}

QAbstractItemModel *SevaViewProxy::getBookedView()
{
    return this->m_sevaBookingModelData->getSevaBookingProgress();
}

bool SevaViewProxy::resetBookView()
{
    this->getNextReceiptNumber();
    m_sevaBookingModelData->resetBookingProgressModel();
    return true;
}

SevaName* SevaViewProxy::getSeva(int sevaType, int sevaId)
{
    return SevaTypeNamesDataModel::self()->getSevaDetails(sevaType,sevaId);
}

SevaName *SevaViewProxy::getSevaByIndex(int index)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    Q_ASSERT(m_currentSevaModel != nullptr);
    return this->m_currentSevaModel->getSevaByIndex(index);
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
    m_sevaBookingModelData->saveReceipt(receipt);
    //receipt->print();
    return true;
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
    s->setSevaDate(sevaDate);
    s->setSevaTime(sevaTime);
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

bool SevaViewProxy::printReceipt()
{
    m_sevaBookingModelData->printReceipt();
    return true;
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
    m_allView->clearModel();
    DBInterface::getInstance()->dbtable_view();
    QScreen *screen = qApp->primaryScreen();
    int w = screen->availableSize().width();
    int h = screen->availableSize().height()-30;
    m_allView->setFixedSize(w,h);
    m_allView->setWindowFlag(Qt::Dialog,true);
    m_allView->setWindowModality(Qt::ApplicationModal);
    m_allView->setWindowFlags(Qt::CustomizeWindowHint);
    m_allView->show();
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
    s->setSevaDate(QDate::currentDate().toString("dd.MM.yyyy"));
    s->setSevaTime("09:00 AM");
    s->setSevaId(1111);
    DBInterface::getInstance()->addsevaname(s);
}

int SevaViewProxy::getNextSevaId()
{
    return DBInterface::getInstance()->getNextSevaId();
}

void SevaViewProxy::addNewSevaType(QString sevaTypeName, QString personName)
{

}

void SevaViewProxy::generateCSV()
{
    if(m_csvReceipt!=nullptr)
        delete m_csvReceipt;
    m_csvReceipt = new SevaReceiptCsvProcessor;

    QObject::connect(DBInterface::getInstance(),&DBInterface::sendoneByoneSevaBooking,
    m_csvReceipt,&SevaReceiptCsvProcessor::writeToCsvFormate);
    qDebug() << Q_FUNC_INFO << Qt::endl;
    DBInterface::getInstance()->getDbData();
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

SevaReport *SevaViewProxy::reportOnDateModel() const
{
    return m_ReportOnDateModel;
}

void SevaViewProxy::setReportOnDateModel(SevaReport *newReportOnDateModel)
{
    m_ReportOnDateModel = newReportOnDateModel;
}
