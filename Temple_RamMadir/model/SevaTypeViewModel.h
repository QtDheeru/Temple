#ifndef SEVATYPEVIEWMODEL_H
#define SEVATYPEVIEWMODEL_H

#include <QAbstractListModel>
#include <QMap>
#include <QDebug>
#include "SevaType.h"
#include "SevaTypeNamesDataModel.h"

class SevaTypeViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SevaTypeViewModel(QObject *parent = nullptr);

//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private :
    bool init();

private:
    QList<SevaType*> m_sevaTypes;

    // QAbstractItemModel interface
};

#endif // SEVATYPEVIEWMODEL_H
