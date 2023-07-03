#ifndef ACCOUNTREPORTELEMENT_H
#define ACCOUNTREPORTELEMENT_H

#include <QObject>
#include <QDebug>
class AccountReportElement : public QObject
{
    Q_OBJECT
public:
    explicit AccountReportElement(QObject *parent = nullptr);



    const QString &getSeva_name() const;
    void setSeva_name(const QString &newSeva_name);

    int getSeva_ticket() const;
    void setSeva_ticket(int newSeva_ticket);

    float getSeva_cost() const;
    void setSeva_cost(float newSeva_cost);

    float getSeva_total() const;
    void setSeva_total(float newSeva_total);

    int slNo() const;
    void setSlNo(int newSlNo);

    float getCash() const;
    void setCash(float newCash);

    float getNeft() const;
    void setNeft(float newNeft);

    float getCheque() const;
    void setCheque(float newCheque);

    float getUpi() const;
    void setUpi(float newUpi);

signals:

private:
    int m_slNo;
    QString seva_name;
    int seva_ticket;
    float seva_cost;
    float seva_total;
    float cash;
    float neft;
    float cheque;
    float upi;

};

#endif // ACCOUNTREPORTELEMENT_H
