#include "BookingReportModel.h"

BookingReportModel::BookingReportModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    sevaCSVProcessor = nullptr;
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
    return 8;
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
        qDebug()<<Q_FUNC_INFO<<_da->sevaDate()<<Qt::endl;
        return _da->sevaDate();}
    case 6:{
        qDebug()<<Q_FUNC_INFO<<_da->teerthaPrasada()<<Qt::endl;
        return _da->sevaCount();}
    case 7:{
        qDebug()<<Q_FUNC_INFO<<_da->mobileNumber()<<Qt::endl;
        return _da->mobileNumber();}
    case 8:{
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
    roles[5] = "sDate";
    roles[6] = "sevaCount";
    roles[7] = "mobileNumber";
    roles[8] = "note";

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

    switch(elm->iSelectedType()){
    case  ReportEnums::SINGLE_DATE_REPORT:{
        qDebug()<<Q_FUNC_INFO<<"Inside c date book rep 0"<<Qt::endl;
        elm->setSSingleDate(FormatDate(elm->sSingleDate()));
        qDebug()<<Q_FUNC_INFO<<"elm->setSSingleDate(FormatDate(elm->sSingleDate()))"<<elm->sSingleDate()<<Qt::endl;
        DBInterface::getInstance()->booking_report_cdate_function(elm->sSingleDate(),elm->sSevaName(),elm->iSevaType());
        break;
    }
    case  ReportEnums::DATE_RANGE_REPORT : {
        qDebug()<<Q_FUNC_INFO<<"Inside c date book rep 1"<<Qt::endl;
        elm->setSStartDate(FormatDate(elm->sStartDate()));
        elm->setSEndDate(FormatDate(elm->sEndDate()));
        DBInterface::getInstance()->booking_report_dataRange_function(elm->sSevaName(),elm->iSevaType(),elm->sStartDate(),elm->sEndDate());
        break;
    }
    case  ReportEnums::MONTH_REPORT : {
        qDebug()<<Q_FUNC_INFO<<"Inside c date book rep 2"<<Qt::endl;
        DBInterface::getInstance()->booking_report_cmonth_function(elm->sSevaName(),elm->iSevaType(),elm->sMonth().toInt(),elm->sYear().toInt());
        break;
    }
    default : {qDebug() << Q_FUNC_INFO << " Wrong selection type. No reports" << Qt::endl; break;}
    }
}

QString BookingReportModel::FormatDate(QString unformat)
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

void BookingReportModel::generateBookingReportCSV()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(sevaCSVProcessor!=nullptr)
        delete sevaCSVProcessor;
    sevaCSVProcessor = new SevaReceiptCsvProcessor;
    connect(this,&BookingReportModel::sendBookingReportList,
            sevaCSVProcessor,&SevaReceiptCsvProcessor::recieveBookingReportList);
    emit sendBookingReportList(m_bookingReportQryList);
    emit successMessage("Export Complete");
}
