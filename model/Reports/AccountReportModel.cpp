#include "AccountReportModel.h"

AccountReportModel::AccountReportModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_iGrandTotal=0;
    accountCSVProcessor = nullptr;
    //  connect(DBInterface::getInstance(),&DBInterface::setGrandTotalToZero,
    //         this,[&](){m_iGrandTotal = 0;});
}

AccountReportModel::~AccountReportModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

QVariant AccountReportModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int AccountReportModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    qDebug()<<Q_FUNC_INFO<<m_accountReportQryList.size()<<Qt::endl;
    for (auto it=m_accountReportQryList.begin();it != m_accountReportQryList.end(); it++){
        qDebug()<<"Suman Accounts---"<<(*it)->slNo()<<Qt::endl;
        qDebug()<<"Suman Accounts---"<<(*it)->getSeva_name()<<Qt::endl;
        qDebug()<<"Suman Accounts---"<<(*it)->getSeva_cost()<<Qt::endl;
        qDebug()<<"Suman Accounts---"<<(*it)->getSeva_ticket()<<Qt::endl;
        qDebug()<<"Suman Accounts---"<<(*it)->getSeva_total()<<Qt::endl;

    }
    return m_accountReportQryList.size();
}

int AccountReportModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant AccountReportModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();

    AccountReportElement *_da = m_accountReportQryList.at(r);
    _da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_name()<<Qt::endl;
        return _da->getSeva_name();}
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->getSeva_cost()<<Qt::endl;
        QString b;
        // return b.setNum(_da->getSeva_cost())  + ".00 ?" ;}
        return b.setNum(_da->getSeva_cost())  + ".00 " ;}
    case 4:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_ticket()<<Qt::endl;
        return _da->getSeva_ticket();}
    case 5:
        return _da->getCash();break;
    case 6:{
        return _da->getCheque();break;
    }
    case 7: {
        return _da->getNeft();break;}
    case 8:{

        return _da->getUpi();break;
    }
    case 9:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_total()<<Qt::endl;
        QString c;
        // return c.setNum(_da->getSeva_total())+ ".00 ?";}
        return c.setNum(_da->getSeva_total())+ ".00 ";}
    }
    return "done";
}

QHash<int, QByteArray> AccountReportModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[1] = "SlNo";
    roles[2] ="sevaName";
    roles[3] = "cost";
    roles[4] = "personCount";
    roles[5] = "Cash";
    roles[6] = "Cheque";
    roles[7] = "NEFT";
    roles[8] = "UPI";
    roles[9] = "totalAmount";
    return roles;
}

void AccountReportModel::onDateSelectedAccountModel(QString date)
{

    DBInterface::getInstance()->account_report_cdate_function("ALLSEVANAME",0,date);
}

void AccountReportModel::onDateRangeSelectedAccountModel(QString start, QString end)
{
    DBInterface::getInstance()->account_report_dataRange_function("ALLSEVANAME",0,start,end);
}

bool AccountReportModel::insertSevaRow(AccountReportElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    beginInsertRows(QModelIndex(),m_accountReportQryList.size(),m_accountReportQryList.size());
    this->m_accountReportQryList.append(elm);
    endInsertRows();
    m_iGrandTotal += elm->getSeva_total();
    setIGrandTotal(m_iGrandTotal);
    qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;
    return true;
}

void AccountReportModel::generateAccReport(ReportFilterElements *elm)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_accountReportQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountReportQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;

    if(elm->iSelectedType()==0)
    {
        qDebug()<<Q_FUNC_INFO<<"Inside c date acc rep"<<Qt::endl;
        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<elm->sSingleDate()<<Qt::endl;
        // elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        DBInterface::getInstance()->account_report_cdate_function(elm->sSevaName(),elm->iSevaType(),(elm->sSingleDate()));
    }
    else if(elm->iSelectedType()==1)
    {
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->account_report_dataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
    }
    else
    {
        DBInterface::getInstance()->account_report_cmonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
    }
}

QString AccountReportModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

void AccountReportModel::resetAccModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accountReportQryList.clear();
    m_iGrandTotal = 0;
    endResetModel();
}

int AccountReportModel::iGrandTotal() const
{
    qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;

    return m_iGrandTotal;
}

void AccountReportModel::setIGrandTotal(int newIGrandTotal)
{
    qDebug()<<Q_FUNC_INFO<<newIGrandTotal<<Qt::endl;
    m_iGrandTotal = newIGrandTotal;
    emit grandTotalChanged();
}

int AccountReportModel::getAccountReportQryListSize()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_accountReportQryList.size();
}

void AccountReportModel::setGrandTotalToZero()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    setIGrandTotal(0);
}

void AccountReportModel::generateAccountCSV()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(accountCSVProcessor!=nullptr)
        delete accountCSVProcessor;
    accountCSVProcessor  = new AccountReportCSVProcessor;
    connect(this,&AccountReportModel::sendAccountReportList,accountCSVProcessor,
            &AccountReportCSVProcessor::recieveAccountReportList);
    emit sendAccountReportList(m_accountReportQryList);
    emit successMessage("Export Complete");
}


