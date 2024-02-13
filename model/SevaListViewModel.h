#ifndef SEVALISTVIEWMODEL_H
#define SEVALISTVIEWMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "SevaName.h"
#include "SevaTypeNamesDataModel.h"

class SevaListViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SevaListViewModel(QObject *parent = nullptr);
    ~SevaListViewModel();

    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void init();

    QHash<int, QByteArray> roleNames() const override;
    void initSevaList(int sevaType);
    Q_INVOKABLE int getSevaListViewSize();
    SevaName * getSevaNameByIndex(int sevaType,int index);


public slots:
    void recvClosedObj(int sevaid);
    void sevaNameListUpdated(SevaName*);

private:
    SevaTypeNamesDataModel *m_sevaTypeNameModel;
    int m_sevaType;

};

#endif // SEVALISTVIEWMODEL_H
