#ifndef SEVADETAILSONDATERANGEMODEL_H
#define SEVADETAILSONDATERANGEMODEL_H

#include <QAbstractListModel>
#include "./model/DBInterface.h"
#include <QDebug>

class SevaDetailsOnDateRangeModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SevaDetailsOnDateRangeModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

   bool insertSevaRow(SevaBookingElement *elm);
    void onDateRangeSelected(QString,QString);

private:
     QList<SevaBookingElement*> m_sevaDetailsOnDateRange;
};

#endif // SEVADETAILSONDATERANGEMODEL_H
