#ifndef TRUSTLISTMODEL_H
#define TRUSTLISTMODEL_H
#include<QDebug>
#include<QAbstractListModel>
#include"TrustConfiguration.h"
#include"Trust.h"
class TrustListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString trustCodeForConfig READ currentConfigLocation WRITE setCurrentConfigLocation NOTIFY currentConfigLocationChanged)
    Q_PROPERTY(QString trustCodeForData READ currentDataLocation WRITE setCurrentDataLocation NOTIFY currentDataLocationChanged)
    Q_PROPERTY(QString currentTrust READ currentTrust WRITE setCurrentTrust NOTIFY currentTrustChanged)
    Q_PROPERTY( QList<Trust*> trustList READ trustList CONSTANT)
    TrustListModel();
public:
    ~TrustListModel();
    static TrustListModel* getTrustListModelInstance();
    void init();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


    Q_INVOKABLE QString getDataLocation();
    Q_INVOKABLE QString getConfigLocation();
    Q_INVOKABLE int getTrustListSize();

    const QString &currentConfigLocation() const;
    void setCurrentConfigLocation(const QString &newCurrentConfigLocation);

    const QString &currentDataLocation() const;
    void setCurrentDataLocation(const QString &newCurrentDataLocation);

    const QString &currentTrust() const;
    void setCurrentTrust(const QString &newCurrentTrust);

    TrustListModel *self() const;
    void setSelf(TrustListModel *newSelf);

    const QList<Trust *> &trustList() const;
    void setTrustList(const QList<Trust *> &newTrustList);

private:
    QList<Trust*> m_trustList;
    TrustConfiguration* m_trustConfiguration;
    QString m_currentConfigLocation;
    QString m_currentDataLocation;
    QString m_currentTrust;
    static TrustListModel* m_self;

signals:
    void currentConfigLocationChanged();
    void currentDataLocationChanged();
    void currentTrustChanged();

public slots:
    void showCurrentConfigLocation();
    void showCurrentDataLocation();
};

#endif // TRUSTLISTMODEL_H
