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
    Q_PROPERTY(QList<SevaType *> sevaTypes READ sevaTypes CONSTANT)

public:
    explicit SevaTypeViewModel(QObject *parent = nullptr);
    ~SevaTypeViewModel() override;

//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE int getSevaTypeListSize();

    const QList<SevaType *> &sevaTypes() const;
    void setSevaTypes(const QList<SevaType *> &newSevaTypes);


    SevaType* getSevaTypeByIndex(int index);

private :
    bool init();

private:
    QList<SevaType*> m_sevaTypes;

    // QAbstractItemModel interface
};

#endif // SEVATYPEVIEWMODEL_H
