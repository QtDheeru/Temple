#ifndef ACCOUNTREPORTMONTHWISEMODEL_H
#define ACCOUNTREPORTMONTHWISEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include<QDebug>
#include "./model/DBInterface.h"
#include"AccountReportMonthRangeElement.h"
#include"ReportFilterElements.h"
class AccountReportMonthWiseModel : public QAbstractTableModel
{
    Q_OBJECT

    Q_PROPERTY(double grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)
    Q_PROPERTY(double cashTotal READ cashTotal WRITE setCashTotal NOTIFY cashTotalChanged FINAL)
    Q_PROPERTY(double chequeTotal READ chequeTotal WRITE setChequeTotal NOTIFY chequeTotalChanged FINAL)
    Q_PROPERTY(double neftTotal READ neftTotal WRITE setNeftTotal NOTIFY neftTotalChanged FINAL)
    Q_PROPERTY(double upiTotal READ upiTotal WRITE setUpiTotal NOTIFY upiTotalChanged FINAL)
    Q_PROPERTY(double unknownTypeTotal READ unknownTypeTotal WRITE setUnknownTypeTotal NOTIFY unknownTypeTotalChanged FINAL)
    Q_PROPERTY(double totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged FINAL)

public:
    explicit AccountReportMonthWiseModel(QObject *parent = nullptr);
    ~AccountReportMonthWiseModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    double iGrandTotal() const;
    void setIGrandTotal(double newIGrandTotal);

    bool insertSevaRow(AccountReportElement *elm);
    void generateAccMonthRangeReport(ReportFilterElements* elm);
    QString FormatDate(QString unformat);
    Q_INVOKABLE AccountReportElement *getAccountReportMonthRangeElementAt(int indx);
    void resetAccMonthRangeModel();
    Q_INVOKABLE int getAccountReportMonthWiseQryListSize();

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

    bool reset();

    double totalSevaCount() const;
    void setTotalSevaCount(double newTotalSevaCount);

private:
    QList<AccountReportElement*> m_accountReportMonthRangeQryList;
    QMap<QString, AccountReportElement*> m_month2AcountMap;
    QMap<int, QString> m_number_month_map = { {1, "Jan"},{2, "Feb"},{3, "Mar"},{4, "April"},{5, "May"},{6, "Jun"},
    {8, "Aug"},{9, "Sept"},{10, "Oct"},{11, "Nov"},{12, "Dec"}};

    double m_iGrandTotal;
    double m_cashTotal;
    double m_chequeTotal;
    double m_neftTotal;
    double m_upiTotal;
    double m_unknownTypeTotal;
    double m_totalSevaCount;

signals:
    void grandTotalChanged();
    void cashTotalChanged();
    void chequeTotalChanged();
    void neftTotalChanged();
    void upiTotalChanged();
    void unknownTypeTotalChanged();
    void totalSevaCountChanged();
};

#endif // ACCOUNTREPORTMONTHWISEMODEL_H
