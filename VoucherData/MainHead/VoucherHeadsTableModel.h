#ifndef VOUCHERHEADSTABLEMODEL_H
#define VOUCHERHEADSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>
#include <QList>
#include <string>
#include <fstream>
#include <sstream>
#include "VoucherData/MainHead/VoucherHeadsDataModel.h"

using namespace std;

class VoucherHeadsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit VoucherHeadsTableModel(QObject *parent = nullptr);
    ~VoucherHeadsTableModel();

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
    void addDetailsInTable(QString,QString,QString);
    void updateDetailsIntable(QString,QString,QString);
    void removeDetailsIntable(QString);
    void loadTbViewInTable();


signals:
    void vouchToProxy(QString,QString,QString);
    void sigToProxy();
    void addSuccessInTable();
    void updateFailInTable();
    void updateSuccessInTable();
    void removeSuccessInTable();
    void removeFailInTable();
    void ListCountToProxy(int);
    void serialErrorInTable();
    void voucherErrorInTable();
    void addFailInTable();
    void voucherNameErrorInTable();

public slots:
    void onAddTableModel(int,int);
    void callVouchToTableModel(QString,QString,QString );
    void onUpdateToTableModel(int);
    void onRemoveToTableModel(int);
    void onSigEmpty();
    void onSerialError();
    void onVoucherError();
    void onAddSuccessInData();
    void onUpdateFailInData();
    void onUpdateSuccessInData();
    void onRemoveSuccessInData();
    void onRemoveFailInData();
    void onAddFailInData();
    void onListCount(int);
    void rowClicked(int);
    void onVoucherNameError();

private:
    std::unique_ptr<VoucherHeadsDataModel> m_voucherHeadsDataModel;

    // QAbstractItemModel interface
};

#endif // VOUCHERHEADSTABLEMODEL_H
