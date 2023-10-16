#include "AccountReportMonthWiseModel.h"

AccountReportMonthWiseModel::AccountReportMonthWiseModel(QObject *parent)
    : QAbstractTableModel{parent}
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
    return 3;
}

QVariant AccountReportMonthWiseModel::data(const QModelIndex &index, int role) const
{
    //for(AccountReportDateRangeElement* a:m_accountReportDateRangeQryList)
    //{
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->date()<<Qt::endl;
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->totalSevaCount()<<Qt::endl;
    //      qDebug()<<Q_FUNC_INFO<<"iiilllllliiiieee"<<a->totalAmount()<<Qt::endl;
    //}
    int r = index.row();
    AccountReportMonthRangeElement *_da = m_accountReportMonthRangeQryList.at(r);
    _da->setSlNo(r+1);
    switch (role) {
    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->slNo()<<Qt::endl;
        return _da->slNo();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->month()<<Qt::endl;
        if(_da->month()=="1")
        {
            return "January";
        }
        if(_da->month()=="2")
        {
            return "February";
        }
        if(_da->month()=="3")
        {
            return "March";
        }
        if(_da->month()=="4")
        {
            return "April";
        }
        if(_da->month()=="5")
        {
            return "May";
        }
        if(_da->month()=="6")
        {
            return "June";
        }
        if(_da->month()=="7")
        {
            return "July";
        }
        if(_da->month()=="8")
        {
            return "August";
        }
        if(_da->month()=="9")
        {
            return "September";
        }
        if(_da->month()=="10")
        {
            return "October";
        }
        if(_da->month()=="11")
        {
            return "November";
        }
        if(_da->month()=="12")
        {
            return "December";
        }
    }
        // return _da->month();}
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

QHash<int, QByteArray> AccountReportMonthWiseModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SlNo";
    roles[2] = "month";
    roles[3] = "totalSevaCount";
    roles[4] = "totalAmount";

    return roles;
}

int AccountReportMonthWiseModel::iGrandTotal() const
{
    return m_iGrandTotal;
}

void AccountReportMonthWiseModel::setIGrandTotal(int newIGrandTotal)
{
    qDebug()<<Q_FUNC_INFO<<newIGrandTotal<<Qt::endl;
    m_iGrandTotal = newIGrandTotal;
    emit grandTotalChanged();
}

bool AccountReportMonthWiseModel::insertSevaRow(AccountReportMonthRangeElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    beginInsertRows(QModelIndex(),m_accountReportMonthRangeQryList.size(),m_accountReportMonthRangeQryList.size());
    this->m_accountReportMonthRangeQryList.append(elm);
    endInsertRows();
    m_iGrandTotal += elm->totalAmount();
    setIGrandTotal(m_iGrandTotal);
    qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;
    return true;
}

void AccountReportMonthWiseModel::generateAccMonthRangeReport(ReportFilterElements *elm)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_accountReportMonthRangeQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_accountReportMonthRangeQryList.size()<<Qt::endl;
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
    //    if(elm->iSelectedType()==1)
    //    {
    //        elm->setSStartDate(FormatDate(elm->sStartDate()));
    //        elm->setSEndDate(FormatDate(elm->sEndDate()));
    //        DBInterface::getInstance()->account_report_eachDateDataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
    //    }
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

AccountReportMonthRangeElement *AccountReportMonthWiseModel::getAccountReportMonthRangeElementAt(int indx)
{
    qDebug()<<Q_FUNC_INFO<<"I am index "<<indx<<Qt::endl;
    beginResetModel();
    AccountReportMonthRangeElement* a = m_accountReportMonthRangeQryList.at(indx);
    qDebug()<<Q_FUNC_INFO<< a->month()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->totalSevaCount()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->totalAmount()<<Qt::endl;
    endResetModel();
    return a;
}

void AccountReportMonthWiseModel::resetAccMonthRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    //    m_accountReportDateRangeQryList.clear();
    //    m_iGrandTotal = 0;
    endResetModel();
}

int AccountReportMonthWiseModel::getAccountReportMonthWiseQryListSize()
{
    return m_accountReportMonthRangeQryList.size();
}
