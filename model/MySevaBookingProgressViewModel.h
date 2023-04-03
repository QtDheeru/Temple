#ifndef MYSEVABOOKINGPROGRESSVIEWMODEL_H
#define MYSEVABOOKINGPROGRESSVIEWMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "SevaName.h"

class MySevaBookingProgressViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MySevaBookingProgressViewModel(QObject *parent = nullptr);
    ~MySevaBookingProgressViewModel();
    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool addSeva(SevaName *s);

    Q_INVOKABLE bool resetModel();
    bool deleteSeva(SevaName *s);

private:
    QList<SevaName*> m_sevaBookingList;

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const override;
};

#endif // MYSEVABOOKINGPROGRESSVIEWMODEL_H
