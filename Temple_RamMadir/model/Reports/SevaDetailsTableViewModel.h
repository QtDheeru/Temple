#ifndef SEVADEATILSTABLEVIEW_H
#define SEVADEATILSTABLEVIEW_H

#include <QObject>
#include <QAbstractTableModel>
#include <QDebug>
#include "SevaBookingElement.h"

class SevaDetailsTableView : public QAbstractTableModel
{
    Q_OBJECT
    enum  TableContentRole {
        DevoteName = Qt::UserRole + 1,
        MobileNo,
        HeaderRole
    };

public:
    explicit SevaDetailsTableView(QObject *parent = nullptr);
    ~SevaDetailsTableView();
    bool buildDataModel();
    int rowCount(const QModelIndex &index )const override;
    int columnCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    QHash<int, QByteArray> roleNames()const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex())override;

    bool insertSevaRow(SevaBookingElement *elm);
private:
    QList<QStringList *> m_deatailsList;
    QStringList *list;

    QList<SevaBookingElement*> m_sevaBookedList;
signals:

public slots:
    void getData(QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>,QList<QString>);
};

#endif // SEVADEATILSTABLEVIEW_H
