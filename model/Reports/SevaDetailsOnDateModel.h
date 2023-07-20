#ifndef SEVADETAILSONDATEMODEL_H
#define SEVADETAILSONDATEMODEL_H

#include <QAbstractListModel>
#include "./model/DBInterface.h"
#include <QDebug>
class SevaDetailsOnDateModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SevaDetailsOnDateModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool insertSevaRow(SevaBookingElement *elm);
    bool onDateSelected(QString);
    void onDateRangeSelected(QString,QString);

private:

    QList<SevaBookingElement*> m_sevaDetailsOnDate;
public slots:

};

#endif // SEVADETAILSONDATEMODEL_H
