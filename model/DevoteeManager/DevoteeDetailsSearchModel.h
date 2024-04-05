#ifndef DEVOTEEDETAILSSEARCHMODEL_H
#define DEVOTEEDETAILSSEARCHMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>
#include "DevoteeDetailsTableModel.h"
#include <QMap>

class DevoteeDetailsSearchModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit DevoteeDetailsSearchModel(QObject *parent = nullptr);

    Q_INVOKABLE void updateTableModel(QString txtTyped, QString comboBoxText);
    Q_INVOKABLE int getRowOfDataFromTableViewModel(int source_row);
    //  QModelIndex mapToSource(const QModelIndex &proxyIndex);

private:
    QString m_txtTyped;
    QString m_comboBoxText;

    QMap<QString, DevoteeDetailsTableModel::DEVOTEE_ENUMS> m_search2EnumMap;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

#endif // DEVOTEEDETAILSSEARCHMODEL_H
