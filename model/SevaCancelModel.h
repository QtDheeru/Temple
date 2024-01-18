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
    Q_PROPERTY(QString totalAmount READ getTotalAmount NOTIFY totalAmountChanged)
    Q_PROPERTY(QString sevaReceiptNumber READ sevaReceiptNumber NOTIFY receiptNumberChanged)
public:
    explicit SevaCancelModel(QObject *parent = nullptr);
//    bool m_sevaChecked = true;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    int setData(QList<SevaBookingElement *>);

//    bool sevaChecked() const;
//    void setSevaChecked(bool newSevaChecked);

    QList<SevaBookingElement *> recptList() const;
    void setRecptList(const QList<SevaBookingElement *> &newRecptList);

    QString sevaReceiptNumber() const;
    void setSevaReceiptNumber(const QString &newSevaReceiptNumber);

public slots:
    QString getTotalAmount();

private:
    QList<SevaBookingElement*> m_recptList;
    QString m_totalAmount;
    QString m_sevaReceiptNumber;


signals:
    void sevaValueChanged();
    void totalAmountChanged();
    void receiptNumberChanged();


};

#endif // SEVACANCELMODEL_H
