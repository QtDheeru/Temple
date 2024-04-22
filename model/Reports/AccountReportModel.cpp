#include "AccountReportModel.h"

AccountReportModel::AccountReportModel(QObject *parent)
    : QAbstractTableModel(parent)
    ,m_iGrandTotal(0)
    ,m_cashTotal(0)
    ,m_chequeTotal(0)
    ,m_neftTotal(0)
    ,m_upiTotal(0)
    ,m_unknownTypeTotal(0)
{
    qDebug()<<Q_FUNC_INFO<<" Account Report Model object is created " << Qt::endl;
    accountCSVProcessor = nullptr;
}

AccountReportModel::~AccountReportModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

QVariant AccountReportModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return "";
}

int AccountReportModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    qDebug()<<Q_FUNC_INFO<<m_accountReportQryList.size()<<Qt::endl;
    for (auto it=m_accountReportQryList.begin();it != m_accountReportQryList.end(); it++){
        QString d1;
        d1.append((*it)->slNo()).append(" ");
        d1.append((*it)->getSeva_name()).append(" ");
        d1.append(QString::number((*it)->getSeva_cost())).append(" ");
        d1.append((*it)->getSeva_ticket()).append(" ");
        d1.append(QString::number((*it)->getSeva_total())).append(" ");
        qDebug() << Q_FUNC_INFO << "*** Account Record = " << d1 << Qt::endl;
    }
    return m_accountReportQryList.size();
}

int AccountReportModel::columnCount(const QModelIndex &parent) const
{
    return 9;
}

QVariant AccountReportModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    qDebug() << Q_FUNC_INFO << " Row =" << r << " Total Elements for Date =" << m_accountReportQryList.size() << Qt::endl;
    AccountReportElement *_da = m_accountReportQryList.at(r);
    _da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();
    }
    case 2:{
        return _da->getSeva_name();}
    case 3:{
        return QVariant(QString::number(_da->getSeva_cost(),'f',2)) ;break;
    }
    case 4:{
        return _da->getSeva_ticket(); break;
    }
    case 5:
        return QVariant(QString::number(_da->getCash(),'f',2));
    case 6:{
        return QVariant(QString::number(_da->getCheque(),'f',2));
    }
    case 7: {
        return QVariant(QString::number(_da->getNeft(),'f',2));
    }
    case 8:{
        return QVariant(QString::number(_da->getUpi(),'f',2));
    }
    case 9:{
        double totalAmount = _da->getSeva_total();
        QString total = QString::number(totalAmount,'f',2);
        return total;
    }
    }
    return "done";
}

QHash<int, QByteArray> AccountReportModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SlNo";
    roles[2] = "sevaName";
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
    qDebug() << Q_FUNC_INFO << " Data for the selected =" << date << Qt::endl;
    DBInterface::getInstance()->account_report_cdate_function("ALLSEVANAME",0,date);
}

void AccountReportModel::onDateRangeSelectedAccountModel(QString start, QString end)
{
    DBInterface::getInstance()->account_report_dataRange_function("ALLSEVANAME",0,start,end);
}

bool AccountReportModel::insertSevaRow(AccountReportElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<" New Row of Data Received from Data Store. Inserting.."<<Qt::endl;
    if (m_sevaName2AccReport.contains(elm->getSeva_name().trimmed())){
        AccountReportElement *el1 = m_sevaName2AccReport.value(elm->getSeva_name());
        double val = el1->getCash() + elm->getCash();
        el1->setCash(val);
        val = el1->getUpi() + elm->getUpi();
        el1->setUpi(val);
        val = el1->getCheque() + elm->getCheque();
        el1->setCheque(val);
        val = el1->getNeft() + elm->getNeft();
        el1->setNeft(val);
        val = el1->getSeva_total() + elm->getSeva_total();
        el1->setSeva_total(val);
        val = el1->getSeva_ticket() + elm->getSeva_ticket();
        el1->setSeva_ticket(val);
    } else {
        beginInsertRows(QModelIndex(),m_accountReportQryList.size(),m_accountReportQryList.size());
        this->m_sevaName2AccReport.insert(elm->getSeva_name().trimmed(),elm);
        this->m_accountReportQryList.append(elm);
        endInsertRows();
    }

    setIGrandTotal(m_iGrandTotal + elm->getSeva_total());
    setCashTotal(m_cashTotal + elm->getCash());
    setChequeTotal(m_chequeTotal + elm->getCheque());
    setUpiTotal(m_upiTotal + elm->getUpi());
    setNeftTotal(m_neftTotal + elm->getNeft());
    this->setUnknownTypeTotal(0);

    return true;
}

double AccountReportModel::iGrandTotal() const
{
    return m_iGrandTotal;
}

void AccountReportModel::setIGrandTotal(double newIGrandTotal)
{
    m_iGrandTotal = newIGrandTotal;
}

void AccountReportModel::generateAccReport(ReportFilterElements *elm)
{
    this->resetAccModel();

    switch(elm->iSelectedType()){
    case  ReportFilterElements::REPORT_DATE_SELECTION_TYPE::SINGLE_DATE_REPORT:{
        qDebug() << Q_FUNC_INFO << " Generate the Single Date Report " << Qt::endl;
        // convert the date from dd-mm-yyyy format to yyyy-mm-dd. DB expects this.
        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        DBInterface::getInstance()->account_report_cdate_function(elm->sSevaName(),elm->iSevaType(),(elm->sSingleDate()));
        break;
    }
    case  ReportFilterElements::REPORT_DATE_SELECTION_TYPE::DATE_RANGE_REPORT : {
        qDebug() << Q_FUNC_INFO << " Generate the Date Ranged Report " << Qt::endl;
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->account_report_dataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
        break;
    }
    case  ReportFilterElements::REPORT_DATE_SELECTION_TYPE::MONTH_REPORT : {
        qDebug() << Q_FUNC_INFO << " Generate the Month Report " << Qt::endl;
        DBInterface::getInstance()->account_report_cmonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
        break;
    }
    default : {qDebug() << Q_FUNC_INFO << " Wrong selection type. No reports" << Qt::endl; break;}
    }
}

QString AccountReportModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QDate date1 = QDate::fromString(unformat,"yyyy-MM-dd");
    if (date1.isValid()) return unformat;

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
    m_sevaName2AccReport.clear();
    reset();
    endResetModel();
}

AccountReportElement *AccountReportModel::getAccountReportElement(int idx)
{
    if (m_accountReportQryList.empty()){
        // Return dummy. Avoid crash
        return new AccountReportElement;
    }
    return m_accountReportQryList.at(idx);
}

int AccountReportModel::getAccountReportQryListSize()
{
    qDebug()<<Q_FUNC_INFO<<" Number of Rows in Account Report = " << m_accountReportQryList.size()<< Qt::endl;
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

double AccountReportModel::cashTotal() const
{
    return m_cashTotal;
}

void AccountReportModel::setCashTotal(double newCashTotal)
{
    if (qFuzzyCompare(m_cashTotal, newCashTotal))
        return;
    m_cashTotal = newCashTotal;
    emit cashTotalChanged();
}

double AccountReportModel::chequeTotal() const
{
    return m_chequeTotal;
}

void AccountReportModel::setChequeTotal(double newChequeTotal)
{
    if (qFuzzyCompare(m_chequeTotal, newChequeTotal))
        return;
    m_chequeTotal = newChequeTotal;
    emit chequeTotalChanged();
}

double AccountReportModel::neftTotal() const
{
    return m_neftTotal;
}

void AccountReportModel::setNeftTotal(double newNeftTotal)
{
    if (qFuzzyCompare(m_neftTotal, newNeftTotal))
        return;
    m_neftTotal = newNeftTotal;
    emit neftTotalChanged();
}

double AccountReportModel::upiTotal() const
{
    return m_upiTotal;
}

void AccountReportModel::setUpiTotal(double newUpiTotal)
{
    if (qFuzzyCompare(m_upiTotal, newUpiTotal))
        return;
    m_upiTotal = newUpiTotal;
    emit upiTotalChanged();
}

double AccountReportModel::unknownTypeTotal() const
{
    return m_unknownTypeTotal;
}

void AccountReportModel::setUnknownTypeTotal(double newUnknownTypeTotal)
{
    if (qFuzzyCompare(m_unknownTypeTotal, newUnknownTypeTotal))
        return;
    m_unknownTypeTotal = newUnknownTypeTotal;
    emit unknownTypeTotalChanged();
}

bool AccountReportModel::reset()
{
    this->setIGrandTotal(0);
    this->setNeftTotal(0);
    this->setCashTotal(0);
    this->setChequeTotal(0);
    this->setUpiTotal(0);
    this->setUnknownTypeTotal(0);
    return true;
}
