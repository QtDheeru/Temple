#ifndef ACCOUNTREPORTELEMENT_H
#define ACCOUNTREPORTELEMENT_H

#include <QObject>
#include <QDebug>
#include "ReportEnums.h"

class AccountReportElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(int totalSevaCount READ getSeva_ticket WRITE setSeva_ticket NOTIFY totalSevaCountChanged)
    Q_PROPERTY(double totalAmount READ getSeva_total WRITE setSeva_total NOTIFY totalAmountChanged)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged)
    Q_PROPERTY(QString sevaName READ getSeva_name WRITE  setSeva_name NOTIFY sevaNameChanged)
    Q_PROPERTY(QString month READ month WRITE setMonth NOTIFY monthChanged FINAL)
    Q_PROPERTY(QString year READ year WRITE setYear NOTIFY yearChanged FINAL)
    Q_PROPERTY(ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource READ reportGenerationSource WRITE setReportGenerationSource NOTIFY reportGenerationSourceChanged FINAL)

public:
    explicit AccountReportElement(QObject *parent = nullptr);

    const QString &getSeva_name() const;
    void setSeva_name(const QString &newSeva_name);

    int getSeva_ticket() const;
    void setSeva_ticket(int newSeva_ticket);

    float getSeva_cost() const;
    void setSeva_cost(float newSeva_cost);

    double getSeva_total() const;
    void setSeva_total(double newSeva_total);

    int slNo() const;
    void setSlNo(int newSlNo);

    double getCash() const;
    void setCash(double newCash);

    float getNeft() const;
    void setNeft(float newNeft);

    float getCheque() const;
    void setCheque(float newCheque);

    float getUpi() const;
    void setUpi(float newUpi);

    QString getTransaction_mode() const;
    void setTransaction_mode(const QString &newTransaction_mode);

    QString date() const;
    void setDate(const QString &newDate);

    int sevaType() const;
    void setSevaType(int newSevaType);

    Q_INVOKABLE void print();

    QString month() const;
    void setMonth(const QString &newMonth);

    QString year() const;
    void setYear(const QString &newYear);

    ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource() const;
    void setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource);

signals:
    void dateChanged();
    void totalSevaCountChanged();
    void totalAmountChanged();
    void sevaNameChanged();
    void sevaTypeChanged();
    void monthChanged();
    void yearChanged();
    void reportGenerationSourceChanged();

private:

    QString m_date;
    int m_slNo;
    QString seva_name;
    int m_sevaType;
    int seva_ticket;
    float seva_cost;
    double seva_total;
    double cash;
    float neft;
    float cheque;
    float upi;
    QString transaction_mode;
    QString m_month;
    QString m_year;
    ReportEnums::REPORT_GENERATION_SOURCE m_reportGenerationSource;
};

#endif // ACCOUNTREPORTELEMENT_H
