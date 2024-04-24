#include "AccountReportModel.h"
#include "AccountReportMonthWiseModel.h"

AccountReportMonthWiseModel::AccountReportMonthWiseModel(QObject *parent)
    : QAbstractTableModel{parent}
    ,m_iGrandTotal(0)
    ,m_cashTotal(0)
    ,m_chequeTotal(0)
    ,m_neftTotal(0)
    ,m_upiTotal(0)
    ,m_unknownTypeTotal(0)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    connect(DBInterface::getInstance(),&DBInterface::account_report_Month_Range,
            this,&AccountReportMonthWiseModel::insertSevaRow);
    m_iGrandTotal=0;
}

AccountReportMonthWiseModel::~AccountReportMonthWiseModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int AccountReportMonthWiseModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<m_accountReportMonthRangeQryList.size()<<Qt::endl;
    return m_accountReportMonthRangeQryList.size();
}

int AccountReportMonthWiseModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant AccountReportMonthWiseModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    AccountReportElement *_da = m_accountReportMonthRangeQryList.at(r);
    _da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->month()<<Qt::endl;
        return m_number_month_map.value(_da->month().toInt());
    }
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->getSeva_ticket()<<Qt::endl;
        QString b;
        return b.setNum(_da->getSeva_ticket()) /* + ".00 " */;}
    case 4:
        return QVariant(QString::number(_da->getCash(),'f',2));break;
    case 5:{
        return QVariant(QString::number(_da->getCheque(),'f',2));break;
    }
    case 6: {
        return QVariant(QString::number(_da->getNeft(),'f',2));
        break;
    }
    case 7:{
        return QVariant(QString::number(_da->getUpi(),'f',2));break;
    }
    case 8:{
        return QVariant(QString::number(_da->getSeva_total(),'f',2));break;
    }
    return "done";
    }
}

QHash<int, QByteArray> AccountReportMonthWiseModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SlNo";
    roles[2] = "month";
    roles[3] = "totalSevaCount";
    roles[4] = "cash";
    roles[5] = "cheque";
    roles[6] = "neft";
    roles[7] = "upi";
    roles[8] = "totalAmount";

    return roles;
}

double AccountReportMonthWiseModel::iGrandTotal() const
{
    return m_iGrandTotal;
}

void AccountReportMonthWiseModel::setIGrandTotal(double newIGrandTotal)
{
    qDebug()<<Q_FUNC_INFO<<newIGrandTotal<<Qt::endl;
    m_iGrandTotal = newIGrandTotal;
    emit grandTotalChanged();
}

bool AccountReportMonthWiseModel::insertSevaRow(AccountReportElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    double totalValue  = 0;
    beginInsertRows(QModelIndex(),m_accountReportMonthRangeQryList.size(),m_accountReportMonthRangeQryList.size());
    if (m_month2AcountMap.contains(elm->month().trimmed())){
        AccountReportElement *el1 = m_month2AcountMap.value(elm->month());
        double val = el1->getCash() + elm->getCash();
        totalValue += val;
        el1->setCash(val);
        val = el1->getUpi() + elm->getUpi();
        totalValue += val;
        el1->setUpi(val);
        val = el1->getCheque() + elm->getCheque();
        el1->setCheque(val);
        totalValue += val;
        val = el1->getNeft() + elm->getNeft();
        el1->setNeft(val);
        totalValue += val;
        val = totalValue + elm->getSeva_total();
        el1->setSeva_total(val);
        val = el1->getSeva_ticket() + elm->getSeva_ticket();
        el1->setSeva_ticket(val);
    } else {
        beginInsertRows(QModelIndex(),m_accountReportMonthRangeQryList.size(),m_accountReportMonthRangeQryList.size());
        this->m_month2AcountMap.insert(elm->month().trimmed(),elm);
        this->m_accountReportMonthRangeQryList.append(elm);
        endInsertRows();
    }

    setIGrandTotal(m_iGrandTotal + elm->getSeva_total());
    setCashTotal(m_cashTotal + elm->getCash());
    setChequeTotal(m_chequeTotal + elm->getCheque());
    setUpiTotal(m_upiTotal + elm->getUpi());
    setNeftTotal(m_neftTotal + elm->getNeft());
    this->setTotalSevaCount(m_totalSevaCount + elm->getSeva_ticket());
    this->setUnknownTypeTotal(0);

    endInsertRows();
    return true;
}

void AccountReportMonthWiseModel::generateAccMonthRangeReport(ReportFilterElements *elm)
{
    qDebug() << Q_FUNC_INFO << " Start Generting the month wise report .." << Qt::endl;
    m_iGrandTotal = 0;
    beginResetModel();
    m_accountReportMonthRangeQryList.clear();
    endResetModel();
    elm->print();
    qDebug()<<Q_FUNC_INFO<<m_accountReportMonthRangeQryList.size()<<Qt::endl;

    if(elm->iSelectedType()==2)
    {
        qDebug()<<Q_FUNC_INFO<<"(elm->iSelectedType()==2)"<<Qt::endl;
        DBInterface::getInstance()->account_report_eachMonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
    }
}

QString AccountReportMonthWiseModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

AccountReportElement *AccountReportMonthWiseModel::getAccountReportMonthRangeElementAt(int indx)
{
    qDebug()<<Q_FUNC_INFO<<"I am index "<<indx<<Qt::endl;
    beginResetModel();
    AccountReportElement* a = m_accountReportMonthRangeQryList.at(indx);
    qDebug()<<Q_FUNC_INFO<< a->month()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->getSeva_ticket()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->getSeva_total()<<Qt::endl;
    endResetModel();
    return a;
}

void AccountReportMonthWiseModel::resetAccMonthRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    //    m_accountReportDateRangeQryList.clear();
    //    m_iGrandTotal = 0;
    m_accountReportMonthRangeQryList.clear();
    m_month2AcountMap.clear();
    reset();
    endResetModel();
}

bool AccountReportMonthWiseModel::reset()
{
    this->setIGrandTotal(0);
    this->setNeftTotal(0);
    this->setCashTotal(0);
    this->setChequeTotal(0);
    this->setUpiTotal(0);
    this->setUnknownTypeTotal(0);
    return true;
}

double AccountReportMonthWiseModel::totalSevaCount() const
{
    return m_totalSevaCount;
}

void AccountReportMonthWiseModel::setTotalSevaCount(double newTotalSevaCount)
{
    if (qFuzzyCompare(m_totalSevaCount, newTotalSevaCount))
        return;
    m_totalSevaCount = newTotalSevaCount;
    emit totalSevaCountChanged();
}

int AccountReportMonthWiseModel::getAccountReportMonthWiseQryListSize()
{
    return m_accountReportMonthRangeQryList.size();
}

double AccountReportMonthWiseModel::cashTotal() const
{
    return m_cashTotal;
}

void AccountReportMonthWiseModel::setCashTotal(double newCashTotal)
{
    if (qFuzzyCompare(m_cashTotal, newCashTotal))
        return;
    m_cashTotal = newCashTotal;
    emit cashTotalChanged();
}

double AccountReportMonthWiseModel::chequeTotal() const
{
    return m_chequeTotal;
}

void AccountReportMonthWiseModel::setChequeTotal(double newChequeTotal)
{
    if (qFuzzyCompare(m_chequeTotal, newChequeTotal))
        return;
    m_chequeTotal = newChequeTotal;
    emit chequeTotalChanged();
}

double AccountReportMonthWiseModel::neftTotal() const
{
    return m_neftTotal;
}

void AccountReportMonthWiseModel::setNeftTotal(double newNeftTotal)
{
    if (qFuzzyCompare(m_neftTotal, newNeftTotal))
        return;
    m_neftTotal = newNeftTotal;
    emit neftTotalChanged();
}

double AccountReportMonthWiseModel::upiTotal() const
{
    return m_upiTotal;
}

void AccountReportMonthWiseModel::setUpiTotal(double newUpiTotal)
{
    if (qFuzzyCompare(m_upiTotal, newUpiTotal))
        return;
    m_upiTotal = newUpiTotal;
    emit upiTotalChanged();
}

double AccountReportMonthWiseModel::unknownTypeTotal() const
{
    return m_unknownTypeTotal;
}

void AccountReportMonthWiseModel::setUnknownTypeTotal(double newUnknownTypeTotal)
{
    if (qFuzzyCompare(m_unknownTypeTotal, newUnknownTypeTotal))
        return;
    m_unknownTypeTotal = newUnknownTypeTotal;
    emit unknownTypeTotalChanged();
}
