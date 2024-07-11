#include "ProfitAndLossDataModel.h"

ProfitAndLossDataModel::ProfitAndLossDataModel(QObject *parent)
    : QAbstractTableModel{parent},m_balance(0)
{
    qDebug() << Q_FUNC_INFO ;
    connect(DBInterface::getInstance(),&DBInterface::profitAndLoss_SevaBooked_report,this,&ProfitAndLossDataModel::insertSevaBookedRow);
    connect(DBInterface::getInstance(),&DBInterface::profitAndLoss_Voucher_report,this,&ProfitAndLossDataModel::insertVoucherBookedRow);

    connect(DBInterface::getInstance(),&DBInterface::profitNLoss_DateRange_SevaBooked_report,this,&ProfitAndLossDataModel::insertSevaBookedRow);
    connect(DBInterface::getInstance(),&DBInterface::profitNLoss_DateRange_Voucher_report,this,&ProfitAndLossDataModel::insertVoucherBookedRow);
}

ProfitAndLossDataModel::~ProfitAndLossDataModel()
{
    qDebug() << Q_FUNC_INFO;
}

int ProfitAndLossDataModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << m_DateWiseProfitNloss.size() << Qt::endl;
    return m_DateWiseProfitNloss.size();
}

int ProfitAndLossDataModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant ProfitAndLossDataModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    qDebug() << Q_FUNC_INFO << " Row =" << r << " Total Elements for Date =" << m_profitNLossElementList.size() << Qt::endl;
    ProfitAndLossReportElement *_da = m_DateWiseProfitNloss.values().at(r);
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
        return QVariant(QString::number(_da->balance()));break;
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
    ProfitAndLossReportElement *_da;
    if(accElement != nullptr){
        if(m_DateWiseProfitNloss.contains(formatDate(accElement->date()))){
            qDebug() << Q_FUNC_INFO << "update acc element"  << formatDate(accElement->date()) << Qt::endl;
            _da = m_DateWiseProfitNloss.value(formatDate(accElement->date()));
            _da->setSevaBookedAmount(_da->sevaBookedAmount() + accElement->getSeva_total());
            // _da->setReceiptNo(QString::number(accElement->slNo()));
            _da->setBalance(_da->balance() + accElement->getSeva_total());
        }else{
            qDebug() << Q_FUNC_INFO << "new acc element" << formatDate(accElement->date()) << Qt::endl;
            _da = new ProfitAndLossReportElement;
            _da->setDate(formatDate(accElement->date()));
            _da->setSevaBookedAmount(accElement->getSeva_total());
            // _da->setReceiptNo(QString::number(accElement->slNo()));
            _da->setBalance(accElement->getSeva_total());
            m_DateWiseProfitNloss.insert(formatDate(accElement->date()),_da);
        }
    }else{
        qDebug() << Q_FUNC_INFO << "list size =" << m_DateWiseProfitNloss.size();
        if(m_DateWiseProfitNloss.contains(formatDate(voucherElement->voucherDate()))){
            qDebug() << Q_FUNC_INFO << "update voucher element11" << formatDate(voucherElement->voucherDate()) << Qt::endl;
            _da = m_DateWiseProfitNloss.value(formatDate(voucherElement->voucherDate()));
            qDebug() << Q_FUNC_INFO << "update voucher element22" << formatDate(voucherElement->voucherDate()) << Qt::endl;
            _da->setExpenditure(_da->expenditure() + voucherElement->voucherCost().toLong());
            // _da->setReceiptNo(QString::number(voucherElement->voucherNo()));
            _da->setBalance(_da->balance() - voucherElement->voucherCost().toLong());
            qDebug() << Q_FUNC_INFO << "update voucher element33" << formatDate(voucherElement->voucherDate()) << Qt::endl;
        }else{
            qDebug() << Q_FUNC_INFO << "new voucher element1" << formatDate(voucherElement->voucherDate()) << Qt::endl;
            _da = new ProfitAndLossReportElement;
            _da->setDate(formatDate(voucherElement->voucherDate()));
            qDebug() << Q_FUNC_INFO << "new voucher element2" << Qt::endl;
            _da->setExpenditure(voucherElement->voucherCost().toLong());
            // _da->setReceiptNo(QString::number(voucherElement->voucherNo()));
            _da->setBalance(-voucherElement->voucherCost().toLong());
            qDebug() << Q_FUNC_INFO << "new voucher element3" << Qt::endl;
            m_DateWiseProfitNloss.insert(formatDate(voucherElement->voucherDate()),_da);
            qDebug() << Q_FUNC_INFO << "new voucher element4" << Qt::endl;
        }
    }
    this->endInsertRows();
}

void ProfitAndLossDataModel::generateProfitAndLossForADay(ReportFilterElements *filterElement)
{
    resetModel();
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
        DBInterface::getInstance()->generateDateRangeReportForProfitNLoss(filterElement);
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
    qDebug() << Q_FUNC_INFO << " size of P & L element list :" << m_profitNLossElementList.size();
    for(int i = 0; i < m_accReportDateRangeList.size(); i++)
    {
        m_accReportDateRangeList.clear();
    }
    for(int i = 0; i < m_voucherReportDateRangeList.size(); i++)
    {
        m_voucherReportDateRangeList.clear();
    }
    m_DateWiseProfitNloss.clear();
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
