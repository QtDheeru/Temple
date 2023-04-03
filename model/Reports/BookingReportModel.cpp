#include "BookingReportModel.h"

BookingReportModel::BookingReportModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int BookingReportModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<m_bookingReportQryList.size()<<Qt::endl;
    return m_bookingReportQryList.size();
}

int BookingReportModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return 7;
}

QVariant BookingReportModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int r = index.row();
    BookingReportElement *_da = m_bookingReportQryList.at(r);
    switch (role) {

    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->name()<<Qt::endl;
        return _da->name();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->gothra()<<Qt::endl;
        return _da->gothra();}
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->nakshatra()<<Qt::endl;
        return _da->nakshatra() ;}
    case 4:{
        qDebug()<<Q_FUNC_INFO<<_da->sevaName()<<Qt::endl;
        return _da->sevaName();}
    case 5:{
        qDebug()<<Q_FUNC_INFO<<_da->teerthaPrasada()<<Qt::endl;
        return _da->teerthaPrasada();}
    case 6:{
        qDebug()<<Q_FUNC_INFO<<_da->mobileNumber()<<Qt::endl;
        return _da->mobileNumber();}
    case 7:{
        qDebug()<<Q_FUNC_INFO<<_da->note()<<Qt::endl;
        return _da->note();}
    }
    return "done";
}

QHash<int, QByteArray> BookingReportModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;

    roles[1] = "name";
    roles[2] = "gothra";
    roles[3] = "nakshatra";
    roles[4] = "sevaName";
    roles[5] = "teerthaPrasada";
    roles[6] = "mobileNumber";
    roles[7] = "note";

    return roles;
}

bool BookingReportModel::insertSevaRow(BookingReportElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginInsertRows(QModelIndex(),m_bookingReportQryList.size(),m_bookingReportQryList.size());
    this->m_bookingReportQryList.append(elm);
    endInsertRows();
    qDebug()<<elm->name()<<Qt::endl;
    qDebug()<<elm->gothra()<<Qt::endl;
    qDebug()<<elm->nakshatra()<<Qt::endl;
    qDebug()<<elm->sevaName()<<Qt::endl;
    qDebug()<<elm->mobileNumber()<<Qt::endl;
    qDebug()<<elm->note()<<Qt::endl;
    return true;
}

void BookingReportModel::generateBookReport(ReportFilterElements *elm)
{
    beginResetModel();
    m_bookingReportQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<m_bookingReportQryList.size()<<Qt::endl;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<"Selected Type "<< elm->iSelectedType()<<Qt::endl;
    qDebug()<<"Selected Month "<< elm->sMonth().toInt()<<Qt::endl;
    qDebug()<<"Selected Year "<< elm->sYear().toInt()<<Qt::endl;
    qDebug()<<"Selected date "<< elm->sSingleDate()<<Qt::endl;

    if(elm->iSelectedType()==0)
    {
        qDebug()<<Q_FUNC_INFO<<"Inside c date book rep"<<Qt::endl;
        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<elm->sSingleDate()<<Qt::endl;
        // elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        DBInterface::getInstance()->booking_report_cdate_function(elm->sSingleDate(),elm->sSevaName(),elm->iSevaType());
    }
    else if(elm->iSelectedType()==1)
    {
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->booking_report_dataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
    }
    else
    {
        DBInterface::getInstance()->booking_report_cmonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
    }
}

QString BookingReportModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

void BookingReportModel::resetBookingModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_bookingReportQryList.clear();
    endResetModel();
}

int BookingReportModel::getBookingReportQryListSize()
{
qDebug()<<Q_FUNC_INFO<<Qt::endl;
return m_bookingReportQryList.size();
}
