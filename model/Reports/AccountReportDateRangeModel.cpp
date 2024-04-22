#include "AccountReportDateRangeModel.h"
#include <QQmlEngine>>

AccountReportDateRangeModel::AccountReportDateRangeModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    connect(DBInterface::getInstance(),
            &DBInterface::account_report_Date_Range,
            this,
            &AccountReportDateRangeModel::insertSevaRow);
    m_iGrandTotal=0;
}

AccountReportDateRangeModel::~AccountReportDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int AccountReportDateRangeModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<m_accReportDateRangeList.size()<<Qt::endl;
    return m_accReportDateRangeList.size();
}

int AccountReportDateRangeModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant AccountReportDateRangeModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    //AccountReportDateRangeElement *_da = m_accountReportDateRangeQryList.at(r);
    AccountReportElement *_da = this->m_accReportDateRangeList.at(r);
    //_da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->date() <<Qt::endl;
        return _da->date();}
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->getSeva_ticket()<<Qt::endl;
        return _da->getSeva_ticket();
    }
    case 4:{
        return QVariant(QString::number(_da->getCash(),'f',2));break;
    }
    case 5:{
        return QVariant(QString::number(_da->getCheque(),'f',2));break;
    }

    case 6:{
        return QVariant(QString::number(_da->getUpi(),'f',2));break;
    }

    case 7:{
        return QVariant(QString::number(_da->getNeft(),'f',2));break;
    }
    case 8:{
        return QVariant(QString::number(_da->getSeva_total(),'f',2));break;
       }
    }
    return "done";
}

//QVariant AccountReportDateRangeModel::headerData(int section, Qt::Orientation orientation, int role) const
//{

//}

QHash<int, QByteArray> AccountReportDateRangeModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[1] = "SlNo";
    roles[2] = "date";
    roles[3] = "totalSevaCount";
    roles[4] = "cash";
    roles[5] = "cheque";
    roles[6] = "upi";
    roles[7] = "neft";
    roles[8] = "totalAmount";

    return roles;
}

int AccountReportDateRangeModel::iGrandTotal() const
{
    return m_iGrandTotal;
}

void AccountReportDateRangeModel::setIGrandTotal(int newIGrandTotal)
{
    qDebug()<<Q_FUNC_INFO<<newIGrandTotal<<Qt::endl;
    m_iGrandTotal = newIGrandTotal;
    emit grandTotalChanged();
}

bool AccountReportDateRangeModel::insertSevaRow(AccountReportElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    QQmlEngine::setObjectOwnership(elm,QQmlEngine::CppOwnership);
    if (m_date2AccReport.contains(elm->date())){
        AccountReportElement *el1 = m_date2AccReport.value(elm->date());
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
        beginInsertRows(QModelIndex(),m_accReportDateRangeList.size(),m_accReportDateRangeList.size());
        this->m_accReportDateRangeList.append(elm);
        m_date2AccReport.insert(elm->date(),elm);
        endInsertRows();
    }
    m_iGrandTotal += elm->getSeva_total();
    setIGrandTotal(m_iGrandTotal);
    qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;
    return true;
}

void AccountReportDateRangeModel::generateAccDateRangeReport(ReportFilterElements *elm)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_accReportDateRangeList.clear();
    m_date2AccReport.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accReportDateRangeList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetailqqqqqqqqqqqqqqqqqs"<<elm->iSelectedType()<<Qt::endl;
    if((elm->iSelectedType()==1)&&(elm->sStartDate()=="null")&&(elm->sEndDate()=="null"))
    {
        qDebug()<<Q_FUNC_INFO<<Qt::endl;
        DBInterface::getInstance()->account_report_eachDateDataRangeForMonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<Qt::endl;
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->account_report_eachDateDataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
    }
}

void AccountReportDateRangeModel::generateAccDateRangeReportForWholeMonth(ReportFilterElements *elm)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_accReportDateRangeList.clear();
    m_date2AccReport.clear();
    endResetModel();
    qDebug() << Q_FUNC_INFO << " Generated the Report for complete month " << Qt::endl;
    elm->print();

    DBInterface::getInstance()->account_report_eachDateDataRangeForMonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
}
QString AccountReportDateRangeModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

AccountReportElement *AccountReportDateRangeModel::getAccountReportDateRangeElementAt(int indx)
{
    beginResetModel();
    AccountReportElement* a = m_accReportDateRangeList.at(indx);
    a->print();
    endResetModel();
    return a;
}
void AccountReportDateRangeModel::resetAccDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_accReportDateRangeList.clear();
    m_date2AccReport.clear();
    m_iGrandTotal = 0;
    endResetModel();
}

int AccountReportDateRangeModel::getAccountReportDateRangeQryListSize()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_accReportDateRangeList.size();
}
