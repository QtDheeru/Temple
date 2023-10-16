#ifndef SEVACOUNTONDATEMODEL_H
#define SEVACOUNTONDATEMODEL_H

#include <QAbstractListModel>
#include "./model/DBInterface.h"
#include "SevaCountOnDateData.h"

class SevaCountOnDateModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SevaCountOnDateModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  //  const QList<int> &count() const;
  //  void setCount(const QList<int> &newCount);
    QHash<int, QByteArray> roleNames() const override;

//    const QStringList &sevaDates() const;
 //   void setSevaDates(const QStringList &newSevaDate);
    void getSevaDatesFromDB();

private:
    QList<SevaCountOnDateData*> m_count;
   QStringList m_SsevaDates;
   QList<QDate> m_DsevaDates;
    QMap<QDate,int> m_countOfStrings;
   // QList<QDate> dateList;
    //QMap<QDate,int> m_sortDateList;

    // QAbstractItemModel interface
public:





};

#endif // SEVACOUNTONDATEMODEL_H
