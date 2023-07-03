#include "AccountReportElement.h"

AccountReportElement::AccountReportElement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    cash = 0;
    neft =0;
    cheque = 0;
    upi = 0;
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

float AccountReportElement::getSeva_total() const
{
    return seva_total;
}

void AccountReportElement::setSeva_total(float newSeva_total)
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

float AccountReportElement::getCash() const
{
    return cash;
}

void AccountReportElement::setCash(float newCash)
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

