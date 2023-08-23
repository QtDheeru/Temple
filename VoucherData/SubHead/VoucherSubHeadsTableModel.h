#ifndef VOUCHERSUBHEADSTABLEMODEL_H
#define VOUCHERSUBHEADSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QDebug>
#include <QList>
#include <string>
#include <fstream>
#include <sstream>
#include "VoucherData/SubHead/VoucherSubHeadsDataModel.h"

using namespace std;

class VoucherSubHeadsTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit VoucherSubHeadsTableModel(QObject *parent = nullptr);
    ~VoucherSubHeadsTableModel();
public:
    //virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
    void voucher_data(QString);
    void selectRow(int);
    void toTableModel();
    void clickTable();
    void clearTable();
    void updateToTable(QString,QString,QString);
    void deleteToTable(QString,QString,QString);

private:
    VoucherSubHeadsDataModel *m_voucherSubHeadsDataModel = new VoucherSubHeadsDataModel;
signals:
    void row_Signal(QString,QString);
    void toMyProxy(QString,QString,QString);
    void toProxyDialog();
    void toFailedUpdate();
    void toTableDelete();
    void UpdateSuccessProxy();
    void deletion_SuccessProxy();
    void Insert_SuccessProxy();

public slots:
    void row_Slot(QString,QString);
    void fromTm(QString,QString,QString);
    void addToTable(QString,QString,QString);
    void onAddToTableModel(int,int);
    void onTableDialog();


    // QAbstractItemModel interface
};

#endif // VOUCHERSUBHEADSTABLEMODEL_H

