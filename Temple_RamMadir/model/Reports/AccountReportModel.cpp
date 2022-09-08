#include "AccountReportModel.h"

AccountReportModel::AccountReportModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_iGrandTotal=0;
}

QVariant AccountReportModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int AccountReportModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<m_accountReportQryList.size()<<Qt::endl;
    return m_accountReportQryList.size();
}

QVariant AccountReportModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    AccountReportElement *_da = m_accountReportQryList.at(r);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_name()<<Qt::endl;
        return (QString::number( r+1 )+ " " +_da->getSeva_name());}
    case 2:{
        qDebug()<< Q_FUNC_INFO<<_da->getSeva_cost()<<Qt::endl;
        return _da->getSeva_cost();}
    case 3:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_ticket()<<Qt::endl;
        return _da->getSeva_ticket();}
    case 4:{
        qDebug()<<Q_FUNC_INFO<<_da->getSeva_total()<<Qt::endl;

        return _da->getSeva_total();}
    }
    return "done";
}

QHash<int, QByteArray> AccountReportModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] ="sevaName";
    roles[2] = "cost";
    roles[3] = "personCount";
    roles[4] = "totalAmount";

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
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
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
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

    if(elm->sSingleDate().compare("null") !=0)
    {
        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
       // elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        DBInterface::getInstance()->account_report_cdate_function(elm->sSevaName(),elm->iSevaType(),(elm->sSingleDate()));
    }
    else
    {
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->account_report_dataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
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


