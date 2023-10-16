#ifndef GOTRAMODEL_H
#define GOTRAMODEL_H

#include <QAbstractListModel>

class GotraModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit GotraModel(QObject *parent = nullptr);

    // Header:
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // GOTRAMODEL_H
