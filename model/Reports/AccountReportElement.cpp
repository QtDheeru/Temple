#include "AccountReportElement.h"

AccountReportElement::AccountReportElement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    cash = 0;
    neft =0;
    cheque = 0;
    upi = 0;
    this->reportGenerationSource = 0;
}

const QString &AccountReportElement::getSeva_name() const
{
    return seva_name;
}

void AccountReportElement::setSeva_name(const QString &newSeva_name)
{
    seva_name = newSeva_name;
}

int AccountReportElement::getSeva_ticket() const
{
    return seva_ticket;
}

void AccountReportElement::setSeva_ticket(int newSeva_ticket)
{
    seva_ticket = newSeva_ticket;
}

float AccountReportElement::getSeva_cost() const
{
    return seva_cost;
}

void AccountReportElement::setSeva_cost(float newSeva_cost)
{
    seva_cost = newSeva_cost;
}

double AccountReportElement::getSeva_total() const
{
    return seva_total;
}

void AccountReportElement::setSeva_total(double newSeva_total)
{
    seva_total = newSeva_total;
}

int AccountReportElement::slNo() const
{
    return m_slNo;
}

void AccountReportElement::setSlNo(int newSlNo)
{
    m_slNo = newSlNo;
}

double AccountReportElement::getCash() const
{
    return cash;
}

void AccountReportElement::setCash(double newCash)
{
    cash = newCash;
}

float AccountReportElement::getNeft() const
{
    return neft;
}

void AccountReportElement::setNeft(float newNeft)
{
    neft = newNeft;
}

float AccountReportElement::getCheque() const
{
    return cheque;
}

void AccountReportElement::setCheque(float newCheque)
{
    cheque = newCheque;
}

float AccountReportElement::getUpi() const
{
    return upi;
}

void AccountReportElement::setUpi(float newUpi)
{
    upi = newUpi;
}

QString AccountReportElement::getTransaction_mode() const
{
    return transaction_mode;
}

void AccountReportElement::setTransaction_mode(const QString &newTransaction_mode)
{
    transaction_mode = newTransaction_mode;
}

void AccountReportElement::print()
{
    qDebug() << " Date =" << this->date() << " SevaType=" << this->sevaType() << " SevaName =" << this->seva_name << " Count=" << this->seva_ticket << " " << this->seva_cost << " " << this->seva_total << Qt::endl;
    qDebug() << " Cash =" << this->cash << " Chq=" << this->cheque << " UPI="<<this->upi << " NEFT"<<this->neft << " Total " << seva_total << Qt::endl;
}

int AccountReportElement::getReportGenerationSource() const
{
    return reportGenerationSource;
}

void AccountReportElement::setReportGenerationSource(int newReportGenerationSource)
{
    if (reportGenerationSource == newReportGenerationSource)
        return;
    reportGenerationSource = newReportGenerationSource;
    emit reportGenerationSourceChanged();
}

QString AccountReportElement::month() const
{
    return m_month;
}

void AccountReportElement::setMonth(const QString &newMonth)
{
    if (m_month == newMonth)
        return;
    m_month = newMonth;
    emit monthChanged();
}

QString AccountReportElement::year() const
{
    return m_year;
}

void AccountReportElement::setYear(const QString &newYear)
{
    if (m_year == newYear)
        return;
    m_year = newYear;
    emit yearChanged();
}

QString AccountReportElement::date() const
{
    return m_date;
}

void AccountReportElement::setDate(const QString &newDate)
{
    m_date = newDate;
}

int AccountReportElement::sevaType() const
{
    return m_sevaType;
}

void AccountReportElement::setSevaType(int newSevaType)
{
    if (m_sevaType == newSevaType)
        return;
    m_sevaType = newSevaType;
    emit sevaTypeChanged();
}

