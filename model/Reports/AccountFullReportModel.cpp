#include "AccountFullReportModel.h"

AccountFullReportModel::AccountFullReportModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_iGrandTotal = 0;
    accountCSVProcessor  = new AccountReportCSVProcessor;
    m_accountSummary = new Account_Summary;
    this->accountCSVProcessor->addSummary(m_accountSummary);
    m_accountSummary->cashTotal = 0;
    m_accountSummary->neftTotal = 0;
    m_accountSummary->chequeTotal = 0;
    m_accountSummary->upiTotal = 0;
    m_accountSummary->unknownTypeTotal = 0;
    m_accountSummary->total = 0;
}

AccountFullReportModel::~AccountFullReportModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void AccountFullReportModel::insertrows(AccountFullreportElement * elememt)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginInsertRows(QModelIndex(),m_accountFullreportElementList.size(),m_accountFullreportElementList.size());
    this->m_accountFullreportElementList.append(elememt);
    endInsertRows();
    m_iGrandTotal += elememt->total();
    this->setIGrandTotal(m_iGrandTotal);
    qDebug() << Q_FUNC_INFO << "mode = " << elememt->paymentmode() << Qt::endl;
    if((elememt->paymentmode().compare("Cash",Qt::CaseInsensitive)==0) || elememt->paymentmode() == "0"){
        qDebug() << Q_FUNC_INFO << "cash" << Qt::endl;
        this->setCashTotal(m_accountSummary->cashTotal + elememt->total());
        return;
    }
    if(elememt->paymentmode().compare("UPI",Qt::CaseInsensitive)==0){
        qDebug() << Q_FUNC_INFO << "UPI " << Qt::endl;
        this->setUpiTotal(m_accountSummary->upiTotal + elememt->total());
        return;
    }

    if(elememt->paymentmode().compare("Cheque",Qt::CaseInsensitive)==0){
        qDebug() << Q_FUNC_INFO << "Cheque " << Qt::endl;
        this->setChequeTotal(m_accountSummary->chequeTotal + elememt->total());
        return;
    }

    if(elememt->paymentmode().compare("NEFT",Qt::CaseInsensitive)==0){
        qDebug() << Q_FUNC_INFO << "NEFT " << Qt::endl;
        this->setNeftTotal(m_accountSummary->neftTotal + elememt->total());
        return;
    }
    // This should be always zero. Code should never reach here.
    this->setUnknownTypeTotal(m_accountSummary->unknownTypeTotal + elememt->total());
    return;
}

void AccountFullReportModel::generateAccountReport(ReportFilterElements * filterelement)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void AccountFullReportModel::generateFullAccountReportEachdate(ReportFilterElements * filterelement)
{
    m_iGrandTotal = 0;
    m_neftTotal = 0;
    m_cashTotal = 0;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accountFullreportElementList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountFullreportElementList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<filterelement->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm details"<<filterelement->sSevaName()<<filterelement->iSevaType()<<Qt::endl;

    if(filterelement->iSelectedType()==0)
    {
        qDebug()<<Q_FUNC_INFO<<"Inside c date acc rep"<<Qt::endl;
        filterelement->setSSingleDate(FormatDate(filterelement->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<filterelement->sSingleDate()<<Qt::endl;
        DBInterface::getInstance()->fullAccounDetailsDateWise(filterelement->sSevaName(),filterelement->iSevaType(),(filterelement->sSingleDate()));
    }
    else if(filterelement->iSelectedType()==1)
    {
        filterelement->setSStartDate(FormatDate(filterelement->sStartDate()));
        filterelement->setSEndDate(FormatDate(filterelement->sEndDate()));
        DBInterface::getInstance()->fullAccounDetailsDateRangeWise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sStartDate(),filterelement->sEndDate());
    }
    else
    {
        DBInterface::getInstance()->fullAccounDetailsMonthwise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sMonth().toInt(),filterelement->sYear().toInt());
    }
}

void AccountFullReportModel::generateFullAccountReportForDateRange(ReportFilterElements * filterelement)
{
    m_iGrandTotal = 0;
    m_neftTotal = 0;
    m_cashTotal = 0;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accountFullreportElementList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountFullreportElementList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<filterelement->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<filterelement->sSevaName()<<filterelement->iSevaType()<<Qt::endl;

    if(filterelement->iSelectedType()==0)
    {
        qDebug()<<Q_FUNC_INFO<<"Inside c date acc rep"<<Qt::endl;
        filterelement->setSSingleDate(FormatDate(filterelement->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<filterelement->sSingleDate()<<Qt::endl;
        DBInterface::getInstance()->fullAccounDetailsDateWise(filterelement->sSevaName(),filterelement->iSevaType(),(filterelement->sSingleDate()));
    }
    else if(filterelement->iSelectedType()==1)
    {
        filterelement->setSStartDate(FormatDate(filterelement->sStartDate()));
        filterelement->setSEndDate(FormatDate(filterelement->sEndDate()));
        DBInterface::getInstance()->fullAccounDetailsDateRangeWise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sStartDate(),filterelement->sEndDate());
    }
    else
    {
        DBInterface::getInstance()->fullAccounDetailsMonthwise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sMonth().toInt(),filterelement->sYear().toInt());
    }
}

void AccountFullReportModel::generateFullAccountReportForMonth(ReportFilterElements * filterelement)
{
    m_iGrandTotal = 0;
    m_neftTotal = 0;
    m_cashTotal = 0;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accountFullreportElementList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountFullreportElementList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<filterelement->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<filterelement->sSevaName()<<filterelement->iSevaType()<<Qt::endl;

    if(filterelement->iSelectedType()==0)
    {
        qDebug()<<Q_FUNC_INFO<<"Inside c date acc rep"<<Qt::endl;
        filterelement->setSSingleDate(FormatDate(filterelement->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<filterelement->sSingleDate()<<Qt::endl;
        DBInterface::getInstance()->fullAccounDetailsDateWise(filterelement->sSevaName(),filterelement->iSevaType(),(filterelement->sSingleDate()));
    }
    else if(filterelement->iSelectedType()==1)
    {
        filterelement->setSStartDate(FormatDate(filterelement->sStartDate()));
        filterelement->setSEndDate(FormatDate(filterelement->sEndDate()));
        DBInterface::getInstance()->fullAccounDetailsDateRangeWise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sStartDate(),filterelement->sEndDate());
    }
    else
    {
        DBInterface::getInstance()->fullAccounDetailsMonthwise(filterelement->sSevaName(),filterelement->iSevaType(),filterelement->sMonth().toInt(),filterelement->sYear().toInt());
    }
}

int AccountFullReportModel::getaccountFullreportElementListSize()
{
    return m_accountFullreportElementList.size();
}

QString AccountFullReportModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

void AccountFullReportModel::setGrandTotalToZero()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    this->setIGrandTotal(0);
}

double AccountFullReportModel::unknownTypeTotal() const
{
    return this->m_accountSummary->unknownTypeTotal;
}

void AccountFullReportModel::setUnknownTypeTotal(double newUnknownTypeTotal)
{
    if (qFuzzyCompare(m_unknownTypeTotal, newUnknownTypeTotal))
        return;
    this->m_accountSummary->unknownTypeTotal = newUnknownTypeTotal;
    emit unknownTypeTotalChanged();
}

double AccountFullReportModel::upiTotal() const
{
    return this->m_accountSummary->upiTotal;
}

void AccountFullReportModel::setUpiTotal(double newUpiTotal)
{
    this->m_accountSummary->upiTotal = newUpiTotal;
}

double AccountFullReportModel::chequeTotal() const
{
    return m_accountSummary->chequeTotal;
}

void AccountFullReportModel::setChequeTotal(double newChequeTotal)
{
    m_accountSummary->chequeTotal = newChequeTotal;
}

int AccountFullReportModel::cashTotal() const
{
    return m_accountSummary->cashTotal;
}

void AccountFullReportModel::setCashTotal(int newCashTotal)
{
    m_accountSummary->cashTotal = newCashTotal;
}

int AccountFullReportModel::neftTotal() const
{
    return m_accountSummary->neftTotal;
}

void AccountFullReportModel::setNeftTotal(int newNeftTotal)
{
    m_accountSummary->neftTotal = newNeftTotal;
}

AccountReportCSVProcessor *AccountFullReportModel::getAccountCSVProcessor() const
{
    return accountCSVProcessor;
}

void AccountFullReportModel::setAccountCSVProcessor(AccountReportCSVProcessor *newAccountCSVProcessor)
{
    if (accountCSVProcessor == newAccountCSVProcessor)
        return;
    accountCSVProcessor = newAccountCSVProcessor;
    emit accountCSVProcessorChanged();
}

int AccountFullReportModel::iGrandTotal() const
{
    return m_accountSummary->total;
}

void AccountFullReportModel::setIGrandTotal(int newIGrandTotal)
{
    m_accountSummary->total = newIGrandTotal;
    emit iGrandTotalChanged();
}

void AccountFullReportModel::resetAccModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accountFullreportElementList.clear();
    m_accountSummary->cashTotal = 0;
    m_accountSummary->neftTotal = 0;
    m_accountSummary->chequeTotal = 0;
    m_accountSummary->upiTotal = 0;
    m_accountSummary->unknownTypeTotal = 0;
    m_accountSummary->total = 0;
    endResetModel();
}

void AccountFullReportModel::generateFullAccountDataCSV()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    connect(this,&AccountFullReportModel::sendAccountFullreportElementList,accountCSVProcessor,
            &AccountReportCSVProcessor::recieveAccountFullreportElementList);
    emit sendAccountFullreportElementList(m_accountFullreportElementList);
    emit successMessage("Export Completed");
}

int AccountFullReportModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    qDebug()<<Q_FUNC_INFO<<"  "<<m_accountFullreportElementList.size()<<Qt::endl;
    return m_accountFullreportElementList.size();
}

int AccountFullReportModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    Q_UNUSED(parent);
    return 10;
}

QVariant AccountFullReportModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int r = index.row();
    QString c;
    AccountFullreportElement* _da = m_accountFullreportElementList.at(r);
    switch (role) {
    case recieptnumber:{
        return _da->recieptnumber();break;}
    case recptDate:{
        return _da->recptDate();break;}
    case sevadate:{
        return _da->sevadate();break;}
    case sevaname:{
        return _da->sevaname();break;}
    case sevacost:{
        return  c.setNum( _da->sevacost()) + ".00 ";break;}
    case sevaCount:{
        return _da->sevaCount();break;}
    case devoteeName: {
        return _da->devoteeName();break;}
    case mobile:{
        return _da->mobile();break;}
    case paymentmode:{
        return _da->paymentmode();break;}
    case additionalCost:{
        return _da->additionalCost()+ ".00 ";break;}
    case total:{
        return c.setNum(_da->total())+ ".00 ";break;}
    case status:{
        return _da->bookingStatus();break;}
    }
    return QVariant();
}

QHash<int, QByteArray> AccountFullReportModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles[recieptnumber] = "recieptnumber";
    roles[recptDate] = "recptDate";
    roles[sevadate] = "sevadate";
    roles[sevaname] = "sevaname";
    roles[sevacost] = "sevacost";
    roles[sevaCount] = "sevaCount";
    roles[devoteeName] = "devoteeName";
    roles[mobile] = "mobile";
    roles[paymentmode] = "paymentmode";
    roles[total] = "total";
    roles[additionalCost] = "additionalCost";
    roles[status]= "status";
    return roles;
}


