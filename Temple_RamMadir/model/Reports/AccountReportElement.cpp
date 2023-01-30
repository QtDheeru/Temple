#include "AccountReportElement.h"

AccountReportElement::AccountReportElement(QObject *parent)
    : QObject{parent}
{

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

