#ifndef VOUCHERREPORTMODEL_H
#define VOUCHERREPORTMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "VoucherFilterElements.h"
#include <QDebug>
#include <QDate>
#include "./model/DBInterface.h"

class VoucherReportModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int grandTotal READ iGrandTotal WRITE setIGrandTotal NOTIFY grandTotalChanged)
public:
    explicit VoucherReportModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    QString FormatDate(QString);
    int iGrandTotal() const;
    void setIGrandTotal(int newIGrandTotal);
    Q_INVOKABLE int getVoucherReportQryListSize();

     Q_INVOKABLE VoucherElement *getVoucherReportAt(int indx);
public slots:
    void generateVoucherReport(VoucherFilterElements*);
    void insertVoucherRow(VoucherElement*);
    void resetVouModel();
private:
    QList<VoucherElement*> m_voucherReportQryList;
    int m_iGrandTotal;

signals:
    void grandTotalChanged();
};

#endif // VOUCHERREPORTMODEL_H
