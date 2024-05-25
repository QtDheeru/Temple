#ifndef ACCOUNTREPORTMODEL_H
#define ACCOUNTREPORTMODEL_H

#include <QAbstractTableModel>
#include "./model/DBInterface.h"
#include <QDebug>
#include "AccountReportElement.h"
#include "ReportFilterElements.h"
#include "AccountReportCSVProcessor.h"
#include "ReportEnums.h"

class AccountReportModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AccountReportModel(QObject *parent = nullptr);
    ~AccountReportModel();
    Q_PROPERTY(double grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)
    Q_PROPERTY(double cashTotal READ cashTotal WRITE setCashTotal NOTIFY cashTotalChanged FINAL)
    Q_PROPERTY(double chequeTotal READ chequeTotal WRITE setChequeTotal NOTIFY chequeTotalChanged FINAL)
    Q_PROPERTY(double neftTotal READ neftTotal WRITE setNeftTotal NOTIFY neftTotalChanged FINAL)
    Q_PROPERTY(double upiTotal READ upiTotal WRITE setUpiTotal NOTIFY upiTotalChanged FINAL)
    Q_PROPERTY(double unknownTypeTotal READ unknownTypeTotal WRITE setUnknownTypeTotal NOTIFY unknownTypeTotalChanged FINAL)
    Q_PROPERTY(int sevasCount READ sevasCount WRITE setSevasCount NOTIFY sevasCountChanged FINAL)

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // bool insertSevaRow(SevaBookingElement *elm);
    void onDateSelectedAccountModel(QString);
    void onDateRangeSelectedAccountModel(QString,QString);
    bool insertSevaRow(AccountReportElement *elm);
    void generateAccReport(ReportFilterElements*);
    QString FormatDate(QString);
    void resetAccModel();

    double iGrandTotal() const;
    void setIGrandTotal(double newIGrandTotal);

    Q_INVOKABLE AccountReportElement* getAccountReportElement(int idx);
    Q_INVOKABLE int getAccountReportQryListSize();
    Q_INVOKABLE void setGrandTotalToZero();
    Q_INVOKABLE void generateAccountCSV();//Suman N

    double cashTotal() const;
    void setCashTotal(double newCashTotal);

    double chequeTotal() const;
    void setChequeTotal(double newChequeTotal);

    double neftTotal() const;
    void setNeftTotal(double newNeftTotal);

    double upiTotal() const;
    void setUpiTotal(double newUpiTotal);

    double unknownTypeTotal() const;
    void setUnknownTypeTotal(double newUnknownTypeTotal);

    int sevasCount() const;
    void setSevasCount(int newSevasCount);

private:
    bool reset();
    QList<AccountReportElement*> m_accountReportQryList;
    QMap<QString , AccountReportElement*> m_sevaName2AccReport;
    AccountReportCSVProcessor *accountCSVProcessor ;

    double m_iGrandTotal;
    double m_cashTotal;
    double m_chequeTotal;
    double m_neftTotal;
    double m_upiTotal;
    double m_unknownTypeTotal;
    int m_sevasCount;

signals:
    void grandTotalChanged();
    void sendAccountReportList(QList<AccountReportElement*>);
    void successMessage(QString exportmsg);                    //Suman N
    void cashTotalChanged();
    void chequeTotalChanged();
    void neftTotalChanged();
    void upiTotalChanged();
    void unknownTypeTotalChanged();
    void sevasCountChanged();
};

#endif // ACCOUNTREPORTMODEL_H
