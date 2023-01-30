#ifndef SEVABOOKINGSEARCHMODEL_H
#define SEVABOOKINGSEARCHMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>
#include "SevaBookingTableModel.h"

class SevaBookingSearchModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit SevaBookingSearchModel(QObject *parent = nullptr);

    Q_INVOKABLE void updateTableModel(QString txtTyped, QString comboBoxText);
    Q_INVOKABLE int getRowOfDataFromTableViewModel(int source_row);
    //  QModelIndex mapToSource(const QModelIndex &proxyIndex);

private:
    QString m_txtTyped;
    QString m_comboBoxText;
//   const QModelIndex sourceIndex;
    static int i ;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

#endif // SEVABOOKINGSEARCHMODEL_H
