#ifndef SEVABOOKINGTABLEMODEL_H
#define SEVABOOKINGTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>
#include <QList>
#include "SevaBookingElement.h"
#include <string>
#include <fstream>
#include <sstream>
#include "./model/DBInterface.h"

using namespace std;

class SevaBookingTableModel : public QAbstractTableModel
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
        NAKSHATRA_ROLE,

        SEVA_TYPE_ROLE,
        SEVA_NAME_ROLE,
        QUANTITY_ROLE,
        RECEIPT_DATE_ROLE,
        SEVA_DATE_ROLE,
        TOTAL_COST_ROLE,
        CASH_ROLE,
        BANK_ROLE,
        BANK_NAME,
        REFERENCE_ROLE,
        STATUS_ROLE,
        ADDRESS_ROLE,
        MOMENTO_ROLE,
        BOOKED_BY_ROLE
    };
    explicit SevaBookingTableModel(QObject *parent = nullptr);
    ~SevaBookingTableModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    void printBookingList();


public slots:
    void addBookingDetails(SevaBookingElement *elem);
    Q_INVOKABLE SevaBookingElement* getRowOfData(int row);
    void reset(QString receiptNo);
    bool checkStatus(QString receiptNo);

private:
    QList<SevaBookingElement*> m_bookedSeva;
    static int x;
    static int y;
    static int z;
    const QString status="cancelled";
    bool found;

};

#endif // SEVABOOKINGTABLEMODEL_H
