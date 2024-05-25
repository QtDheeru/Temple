#ifndef PROFITANDLOSSDATAMODEL_H
#define PROFITANDLOSSDATAMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "../DBInterface.h"
#include "VoucherReportElement.h"
#include "ProfitAndLossReportElement.h"


class ProfitAndLossDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ProfitAndLossDataModel(QObject *parent = nullptr);
    ~ProfitAndLossDataModel();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool insertSevaBookedRow(AccountReportElement *elm);
    bool insertVoucherBookedRow(VoucherReportElement *elm);
    void updateProfitLossElement(AccountReportElement *accElement = nullptr,VoucherReportElement *voucherElement = nullptr);

    QString formatDate(QString unformat);

public slots:
    void generateProfitAndLossForADay(ReportFilterElements * filterElement);
    void resetModel();

private:
    QList<AccountReportElement*> m_accReportDateRangeList;
    QList<VoucherReportElement*> m_voucherReportDateRangeList;
    QList<ProfitAndLossReportElement*> m_profitNLossElementList;
    long m_balance;
};

#endif // PROFITANDLOSSDATAMODEL_H
