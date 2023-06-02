#include "VoucherReportModel.h"

VoucherReportModel::VoucherReportModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    voucherReportCSVProcessor = nullptr;
    m_iGrandTotal = 0;
    connect(DBInterface::getInstance(),&DBInterface::voucher_report,
            this,&VoucherReportModel::insertVoucherRow);
}

int VoucherReportModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherReportQryList.size();
}

int VoucherReportModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return 10;
}

QVariant VoucherReportModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int r = index.row();
    VoucherElement *_da = m_voucherReportQryList.at(r);
    switch (role) {

    case 1:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherDate()<<Qt::endl;
        return _da->voucherDate();}
    case 2:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherNo()<<Qt::endl;
        return _da->voucherNo();}
    case 3:{
        qDebug()<< Q_FUNC_INFO<<_da->voucherName()<<Qt::endl;
        return _da->voucherName() ;}
    case 4:{
        qDebug()<<Q_FUNC_INFO<<_da->mobileNo()<<Qt::endl;
        return _da->mobileNo();}
    case 5:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherType()<<Qt::endl;
        return _da->voucherType();}
    case 6:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherItem()<<Qt::endl;
        return _da->voucherItem();}
    case 7:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherNote()<<Qt::endl;
        return _da->voucherNote();}

    case 8:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherCost()<<Qt::endl;
        return _da->voucherCost();}

    case 9:{
        qDebug()<<Q_FUNC_INFO<<_da->voucherPaymentMode()<<Qt::endl;
        return _da->voucherPaymentMode();}

    case 10:{
        qDebug()<<Q_FUNC_INFO<<_da->PaymentReference()<<Qt::endl;
        return _da->PaymentReference();}
    }
    return "done";
}

QHash<int, QByteArray> VoucherReportModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles[1] = "voucherDate";
    roles[2] = "voucherNo";
    roles[3] = "voucherName";
    roles[4] = "mobileNo";
    roles[5] = "voucherType";
    roles[6] = "voucherItem";
    roles[7] = "voucherNote";
    roles[8] = "voucherCost";
    roles[9] = "voucherPaymentMode";
    roles[10]= "paymentReference";

    return roles;
}

QString VoucherReportModel::FormatDate(QString unformat)
{
    qDebug()<<Q_FUNC_INFO<<unformat<<Qt::endl;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug()<<Q_FUNC_INFO<<Date<<Qt::endl;
    format =Date.toString("yyyy-MM-dd");
    qDebug()<<Q_FUNC_INFO<<format<<Qt::endl;
    return format;
}

void VoucherReportModel::generateVoucherReport(VoucherFilterElements *ele)
{
    m_iGrandTotal = 0;
    beginResetModel();
    m_voucherReportQryList.clear();
    endResetModel();
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    qDebug()<<"selected type "<<ele->iSelectedType()<<Qt::endl;
    qDebug()<<"voucher type "<<ele->sVoucherType()<<Qt::endl;
    qDebug()<<ele->sSingleDate()<<Qt::endl;
    qDebug()<<ele->sStartDate()<<Qt::endl;
    qDebug()<<ele->sEndDate()<<Qt::endl;
    qDebug()<<ele->sMonth()<<Qt::endl;
    qDebug()<<ele->sYear()<<Qt::endl;
    qDebug()<<"Payment mode "<<ele->sPaymentMode()<<Qt::endl;
    if(ele->iSelectedType()==0)
    {
        ele->setSSingleDate(FormatDate(ele->sSingleDate()));
        DBInterface::getInstance()->voucher_report_cdate_function(ele->sSingleDate(),ele->sVoucherType(),ele->sPaymentMode());
    }
    else if(ele->iSelectedType()==1)
    {
        ele->setSStartDate(FormatDate(ele->sStartDate()));
        ele->setSEndDate(FormatDate(ele->sEndDate()));
        /*int x =*/ DBInterface::getInstance()->voucher_report_dataRange_function(ele->sStartDate(),ele->sEndDate(),ele->sVoucherType(),ele->sPaymentMode());
        //        if(x==0)
        //        {
        //          m_iGrandTotal = 0;
        //        }
    }
    else
    {
        DBInterface::getInstance()->voucher_report_cmonth_function(ele->sMonth().toInt(),ele->sYear().toInt(),ele->sVoucherType(),ele->sPaymentMode());
    }
}

void VoucherReportModel::insertVoucherRow(VoucherElement *elm)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    //beginResetModel();
    beginInsertRows(QModelIndex(),m_voucherReportQryList.size(),m_voucherReportQryList.size());
    this->m_voucherReportQryList.append(elm);
    endInsertRows();
    m_iGrandTotal += elm->voucherCost().toInt();
    setIGrandTotal(m_iGrandTotal);
   // m_voucherReportQryList.clear();
  //  endResetModel();
    qDebug()<<"grand total : "<<m_iGrandTotal<<Qt::endl;

}

void VoucherReportModel::resetVouModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginResetModel();
    m_voucherReportQryList.clear();
    endResetModel();

}

int VoucherReportModel::iGrandTotal() const
{
//    if(m_voucherReportQryList.size()==0)
//    {
//     this.sesetIGrandTotal(0);
//    }
    return m_iGrandTotal;
}

void VoucherReportModel::setIGrandTotal(int newIGrandTotal)
{
    m_iGrandTotal = newIGrandTotal;
    emit grandTotalChanged();
}

int VoucherReportModel::getVoucherReportQryListSize()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_voucherReportQryList.size();
}
VoucherElement* VoucherReportModel::getVoucherReportAt(int indx)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    //return m_voucherReportQryList.size();
    return m_voucherReportQryList.at(indx);
}

void VoucherReportModel::generateVoucherReportCSV()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(voucherReportCSVProcessor!=nullptr)
        delete voucherReportCSVProcessor;
    voucherReportCSVProcessor  = new VoucherReportCSVProcessor;
    connect(this,&VoucherReportModel::sendVoucherReportList,voucherReportCSVProcessor,
            &VoucherReportCSVProcessor::writeToCsvFormatVoucherReport);
    emit sendVoucherReportList(m_voucherReportQryList);
    emit successMessage("Export Complete");
}
