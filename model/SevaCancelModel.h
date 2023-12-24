#ifndef SEVACANCELMODEL_H
#define SEVACANCELMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "QDebug"
#include "SevaBookingElement.h"

class SevaCancelModel : public QAbstractListModel
{
    Q_OBJECT
//    Q_PROPERTY(bool my_sevachecked READ sevaChecked WRITE setSevaChecked NOTIFY sevaValueChanged )

public:
    explicit SevaCancelModel(QObject *parent = nullptr);
//    bool m_sevaChecked = true;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int setData(QList<SevaBookingElement *>);

//    bool sevaChecked() const;
//    void setSevaChecked(bool newSevaChecked);

private:
    QList<SevaBookingElement*> m_recptList;

signals:
    void sevaValueChanged();


};

#endif // SEVACANCELMODEL_H
