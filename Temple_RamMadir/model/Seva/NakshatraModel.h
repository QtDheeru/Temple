#ifndef NAKSHATRAMODEL_H
#define NAKSHATRAMODEL_H

#include <QAbstractListModel>
#include "../DBInterface.h"

class NakshatraModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit NakshatraModel(QObject *parent = nullptr);

    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private :
    bool getNakshathras();

private:
    QStringList m_nakshathras;
};

#endif // NAKSHATRAMODEL_H
