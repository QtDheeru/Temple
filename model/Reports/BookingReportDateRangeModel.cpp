#include "BookingReportDateRangeModel.h"

BookingReportDateRangeModel::BookingReportDateRangeModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    bool status= connect(DBInterface::getInstance(),&DBInterface::booking_report_Date_Range,
                         this,&BookingReportDateRangeModel::insertSevaRow);
    qDebug()<<"The connect status"<<status<<Qt::endl;

}

BookingReportDateRangeModel::~BookingReportDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int BookingReportDateRangeModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<m_bookingReportDateRangeQryList.size()<<Qt::endl;
    return m_bookingReportDateRangeQryList.size();
}

int BookingReportDateRangeModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return 2;
}

QVariant BookingReportDateRangeModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;

    int r = index.row();
    BookingReportDateRangeElement *_da = m_bookingReportDateRangeQryList.at(r);
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
        return b.setNum(_da->totalSevaCount()) ;}
    }
    return "done";
}

QHash<int, QByteArray> BookingReportDateRangeModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;

    roles[1] = "SlNo";
    roles[2] = "date";
    roles[3] = "totalSevaCount";
    //roles[4] = "totalAmount";

    return roles;
}

bool BookingReportDateRangeModel::insertSevaRow(BookingReportDateRangeElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<"suman insert sevaRow for report"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"------------"<<Qt::endl;
    beginInsertRows(QModelIndex(),m_bookingReportDateRangeQryList.size(),m_bookingReportDateRangeQryList.size());
    this->m_bookingReportDateRangeQryList.append(elm);
    endInsertRows();
    // m_iGrandTotal += elm->totalAmount();
    // setIGrandTotal(m_iGrandTotal);
    // qDebug()<<Q_FUNC_INFO<<m_iGrandTotal<<Qt::endl;
    return true;
}

void BookingReportDateRangeModel::generateBookingDateRangeReport(ReportFilterElements *elm)
{
    qDebug()<<Q_FUNC_INFO<<"-----------/-1-----------"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"-----------0-----------"<<Qt::endl;
    // m_iGrandTotal = 0;
    beginResetModel();
    qDebug()<<Q_FUNC_INFO<<"-----------1-----------"<<Qt::endl;
    m_bookingReportDateRangeQryList.clear();
    qDebug()<<Q_FUNC_INFO<<"-----------2-----------"<<Qt::endl;
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<"-----------3-----------"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<m_bookingReportDateRangeQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"-----------4-----------"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"-----------5-----------"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"-----------6-----------"<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetailqqqqqqqqqqqqqqqqqs"<<elm->iSelectedType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"-----------7-----------"<<Qt::endl;
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
        DBInterface::getInstance()->booking_report_eachDateDataRangeForMonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<Qt::endl;
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->booking_report_eachDateDataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
    }
}

void BookingReportDateRangeModel::generateBookingDateRangeReportForWholeMonth(ReportFilterElements *elm)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    // m_iGrandTotal = 0;
    beginResetModel();
    m_bookingReportDateRangeQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_bookingReportDateRangeQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm date"<<elm->sSingleDate()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetails"<<elm->sSevaName()<<elm->iSevaType()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"elm ddetailqqqqqqqqqqqqqqqqqs"<<elm->iSelectedType()<<Qt::endl;

    DBInterface::getInstance()->booking_report_eachDateDataRangeForMonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
}

QString BookingReportDateRangeModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

BookingReportDateRangeElement *BookingReportDateRangeModel::getBookingReportDateRangeElementAt(int indx)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<"I am index "<<indx<<Qt::endl;
    beginResetModel();
    BookingReportDateRangeElement* a = m_bookingReportDateRangeQryList.at(indx);
    qDebug()<<Q_FUNC_INFO<< a->date()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<< a->totalSevaCount()<<Qt::endl;
    endResetModel();
    return a;
}

void BookingReportDateRangeModel::resetBookingDateRangeModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    endResetModel();
}

int BookingReportDateRangeModel::getBookingReportDateRangeQryList()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_bookingReportDateRangeQryList.size();
}
