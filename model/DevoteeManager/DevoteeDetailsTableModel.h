#ifndef DEVOTEEDETAILSTABLEMODEL_H
#define DEVOTEEDETAILSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>
#include <QList>
#include <string>
#include <fstream>
#include <sstream>
#include "model/DevotePersnalDetails.h"
#include "DevoteDetailsDataModel.h"

using namespace std;

class DevoteeDetailsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum{
        SNO_ROLE = Qt::UserRole+1,
        PERSON_ID_ROLE,
        PERSON_DBID_ROLE,
        DEVOTEE_NAME_ROLE,
        MOBILE_NUMBER_ROLE,
        GOTHRA_ROLE,
        NAKSHATRA_ROLE
    };
    explicit DevoteeDetailsTableModel(QObject *parent = nullptr);
    ~DevoteeDetailsTableModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    void printBookingList();

public slots:

private:

    static int x;
    static int y;
    static int z;

    DevoteDetailsDataModel *m_devoteModel;
};

#endif // DEVOTEEDETAILSTABLEMODEL_H
