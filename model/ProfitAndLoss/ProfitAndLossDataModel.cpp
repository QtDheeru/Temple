#include "ProfitAndLossDataModel.h"

ProfitAndLossDataModel::ProfitAndLossDataModel(QObject *parent)
    : QAbstractTableModel{parent},m_balance(0)
{
    connect(DBInterface::getInstance(),&DBInterface::profitAndLoss_SevaBooked_report,this,&ProfitAndLossDataModel::insertSevaBookedRow);
    connect(DBInterface::getInstance(),&DBInterface::profitAndLoss_Voucher_report,this,&ProfitAndLossDataModel::insertVoucherBookedRow);

    connect(DBInterface::getInstance(),&DBInterface::profitNLoss_DateRange_SevaBooked_report,this,&ProfitAndLossDataModel::insertSevaBookedRow);
    connect(DBInterface::getInstance(),&DBInterface::profitNLoss_DateRange_Voucher_report,this,&ProfitAndLossDataModel::insertVoucherBookedRow);

}

ProfitAndLossDataModel::~ProfitAndLossDataModel()
{

}

int ProfitAndLossDataModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << m_accReportDateRangeList.size() << Qt::endl;
    return m_accReportDateRangeList.size();
}

int ProfitAndLossDataModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant ProfitAndLossDataModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    qDebug() << Q_FUNC_INFO << " Row =" << r << " Total Elements for Date =" << m_profitNLossElementList.size() << Qt::endl;
    ProfitAndLossReportElement *_da = m_profitNLossElementList.at(r);
    _da->setSlNo(r);
    switch (role) {
    case 1:{
        qDebug() << Q_FUNC_INFO << "index" << Qt::endl;
        return _da->slNo();
    }
    case 2:{
        qDebug() << Q_FUNC_INFO << "date " << _da->date() << Qt::endl;
        return _da->date();
    }
    case 3:{
        qDebug() << Q_FUNC_INFO << "sevaAmount "<< _da->sevaBookedAmount() << Qt::endl;
        return QVariant(QString::number(_da->sevaBookedAmount()));
    }
    case 4:{
        return QVariant(QString::number(_da->expenditure()));break;
    }
    case 5:{
        return QVariant(QString::number(m_balance < 0 ? 0 : m_balance));break;
    }
    }
    return "done";
}

QHash<int, QByteArray> ProfitAndLossDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[1] = "SlNo";
    roles[2] = "Date";
    roles[3] = "TotalBookedAmount";
    roles[4] = "TotalExpenditure";
    roles[5] = "Balance";
    return roles;
}

bool ProfitAndLossDataModel::insertSevaBookedRow(AccountReportElement *elm)
{
    qDebug() << Q_FUNC_INFO << "------------" << Qt::endl;
    QQmlEngine::setObjectOwnership(elm,QQmlEngine::CppOwnership);
    this->m_accReportDateRangeList.append(elm);
    qDebug() << Q_FUNC_INFO << "------------" << Qt::endl;
    this->updateProfitLossElement(elm);
    return true;
}

bool ProfitAndLossDataModel::insertVoucherBookedRow(VoucherReportElement *elm)
{
    qDebug() << Q_FUNC_INFO << elm->voucherCost() <<  Qt::endl;
    QQmlEngine::setObjectOwnership(elm,QQmlEngine::CppOwnership);
    this->m_voucherReportDateRangeList.append(elm);
    this->updateProfitLossElement(nullptr,elm);
    return true;
}

void ProfitAndLossDataModel::updateProfitLossElement(AccountReportElement *accElement ,VoucherReportElement *voucherElement )
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->beginInsertRows(QModelIndex(),0,0);
    ProfitAndLossReportElement *_da = new ProfitAndLossReportElement;
    if(accElement != nullptr){
        _da->setDate(formatDate(accElement->date()));
        _da->setSevaBookedAmount(accElement->getSeva_total());
        _da->setReceiptNo(QString::number(accElement->slNo()));
        m_balance += accElement->getSeva_total();
    }else{
        _da->setDate(formatDate(voucherElement->voucherDate()));
        _da->setExpenditure(voucherElement->voucherCost().toLong());
        _da->setReceiptNo(QString::number(voucherElement->voucherNo()));
        m_balance -= voucherElement->voucherCost().toLong();
    }
    m_profitNLossElementList.append(_da);
    this->endInsertRows();
}

void ProfitAndLossDataModel::generateProfitAndLossForADay(ReportFilterElements *filterElement)
{
    switch(filterElement->iSelectedType()) {
    case ReportEnums::SINGLE_DATE_REPORT: {
        qDebug() << Q_FUNC_INFO << " Generate the Single Date Full Report " << Qt::endl;
        filterElement->setSSingleDate(formatDate(filterElement->sSingleDate()));
        DBInterface::getInstance()->generateSingleDateReportForProfitNLoss(filterElement);
        break;
    }
    case ReportEnums::DATE_RANGE_REPORT : {
        filterElement->setSStartDate(formatDate(filterElement->sStartDate()));
        filterElement->setSEndDate(formatDate(filterElement->sEndDate()));
        DBInterface::getInstance()->generateDateRangeReportForProfitNLoss(filterElement);
        break;
    }
    case ReportEnums::MONTH_REPORT : {
        DBInterface::getInstance()->fullAccounDetailsMonthwise(filterElement->sSevaName(),filterElement->iSevaType(),filterElement->sMonth().toInt(),filterElement->sYear().toInt());
        break;
    }
    default : {
        qDebug() << Q_FUNC_INFO << " Wrong selection type. No full reports" << Qt::endl;
        break;
    }
    }
}

void ProfitAndLossDataModel::resetModel()
{
    for(int i = 0; i < m_profitNLossElementList.size(); i++)
    {
        m_accReportDateRangeList.clear();
        m_voucherReportDateRangeList.clear();
        m_profitNLossElementList.at(i)->reset();
        delete m_profitNLossElementList.at(i);
    }
}

QString ProfitAndLossDataModel::formatDate(QString unformat)
{
    qDebug() << Q_FUNC_INFO << unformat << Qt::endl;
    QDate date1 = QDate::fromString(unformat,"yyyy-MM-dd");
    if (date1.isValid()) return unformat;
    QString format;
    QDate Date = QDate::fromString(unformat,"dd-MM-yyyy");
    qDebug() << Q_FUNC_INFO << Date << Qt::endl;
    format = Date.toString("yyyy-MM-dd");
    qDebug() << Q_FUNC_INFO << format << Qt::endl;
    return format;
}
