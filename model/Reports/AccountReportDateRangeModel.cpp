#include "AccountReportDateRangeModel.h"

AccountReportDateRangeModel::AccountReportDateRangeModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    connect(DBInterface::getInstance(),&DBInterface::account_report_Date_Range,
            this,&AccountReportDateRangeModel::insertSevaRow);
    m_iGrandTotal=0;
}

AccountReportDateRangeModel::~AccountReportDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int AccountReportDateRangeModel::rowCount(const QModelIndex &parent) const
{

    qDebug()<<Q_FUNC_INFO<<m_accountReportDateRangeQryList.size()<<Qt::endl;
    return m_accountReportDateRangeQryList.size();
}

int AccountReportDateRangeModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant AccountReportDateRangeModel::data(const QModelIndex &index, int role) const
{

    //for(AccountReportDateRangeElement* a:m_accountReportDateRangeQryList)
    //{
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->date()<<Qt::endl;
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->totalSevaCount()<<Qt::endl;
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->totalAmount()<<Qt::endl;
    //}
    int r = index.row();
    AccountReportDateRangeElement *_da = m_accountReportDateRangeQryList.at(r);
    _da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->date()<<Qt::endl;
        return _da->date();}
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->totalSevaCount()<<Qt::endl;
        QString b;
        // return b.setNum(_da->getSeva_cost())  + ".00 ?" ;}
        return b.setNum(_da->totalSevaCount()) /* + ".00 " */;}
    case 4:{
        qDebug()<<Q_FUNC_INFO<<_da->totalAmount()<<Qt::endl;
        return _da->totalAmount();}

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
    roles[4] = "totalAmount";

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

bool AccountReportDateRangeModel::insertSevaRow(AccountReportDateRangeElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    beginInsertRows(QModelIndex(),m_accountReportDateRangeQryList.size(),m_accountReportDateRangeQryList.size());
    this->m_accountReportDateRangeQryList.append(elm);
    endInsertRows();
    m_iGrandTotal += elm->totalAmount();
    setIGrandTotal(m_iGrandTotal);
    qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;
    return true;
}

void AccountReportDateRangeModel::generateAccDateRangeReport(ReportFilterElements *elm)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_accountReportDateRangeQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountReportDateRangeQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetailqqqqqqqqqqqqqqqqqs"<<elm->iSelectedType()<<Qt::endl;
    //    if(elm->iSelectedType()==0)
    //    {
    //        qDebug()<<Q_FUNC_INFO<<"Inside c date acc rep"<<Qt::endl;
    //        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
    //        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<elm->sSingleDate()<<Qt::endl;
    //        // elm->setSSingleDate(FormatDate(elm->sSingleDate()));
    //        DBInterface::getInstance()->account_report_cdate_function(elm->sSevaName(),elm->iSevaType(),(elm->sSingleDate()));
    //    }
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
    m_accountReportDateRangeQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountReportDateRangeQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetailqqqqqqqqqqqqqqqqqs"<<elm->iSelectedType()<<Qt::endl;

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

AccountReportDateRangeElement *AccountReportDateRangeModel::getAccountReportDateRangeElementAt(int indx)
{
    qDebug()<<Q_FUNC_INFO<<"I am index "<<indx<<Qt::endl;
    beginResetModel();
    AccountReportDateRangeElement* a = m_accountReportDateRangeQryList.at(indx);
    qDebug()<<Q_FUNC_INFO<< a->date()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->totalSevaCount()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->totalAmount()<<Qt::endl;
    endResetModel();
    return a;
}
void AccountReportDateRangeModel::resetAccDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    //    m_accountReportDateRangeQryList.clear();
    //    m_iGrandTotal = 0;
    endResetModel();

}

int AccountReportDateRangeModel::getAccountReportDateRangeQryListSize()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_accountReportDateRangeQryList.size();
}
