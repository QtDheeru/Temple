#ifndef VOUCHERSUBHEADSDATAMODEL_H
#define VOUCHERSUBHEADSDATAMODEL_H


#include<QList>
#include "VoucherData/SubHead/VoucherSubHead.h"
#include <QString>
#include <QModelIndex>
#include "VoucherData/SubHead/vouchersubheaddatabase.h"
#include "model/DBInterface.h"

class VoucherSubHeadsDataModel : public QObject//, public IVoucherDataModel
{
    Q_OBJECT
public:
    Q_PROPERTY(QString my_subCat READ getSub_cat_id WRITE setSub_cat_id NOTIFY subcat_Changed)
    Q_PROPERTY(QString my_subName READ getSub_name WRITE setSub_name NOTIFY subname_Changed)

    explicit VoucherSubHeadsDataModel(QObject *parent = nullptr);
    QList <VoucherSubHead*> m_table2Data;
    QString voucherId;
    QString sub_cat_id;
    QString sub_name;
    void init();
    void clickModel();
    void clearModel();
    void updateToModel(QString,QString,QString);
    void deleteToModel(QString,QString,QString);

    // QAbstractItemModel interface
public:

    int my_rowCount(const QModelIndex &parent) const;
    int my_columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    QString getSub_cat_id() const;
    void setSub_cat_id(const QString &newSub_cat_id);

    QString getSub_name() const;
    void setSub_name(const QString &newSub_name);
    void set_MainId(QString);
    VoucherSubHead *table=new VoucherSubHead;
    void set_data(int);
    void getFromModel();
    void addFromModel(QString,QString,QString);
    //void display_sub();
public slots:

    void onMySelectSignal(QString,QString,QString);
    void onModelDialog();

    //void set_data(QString);

signals:
    void subcat_Changed();
    void subname_Changed();
    void updated_data(QString,QString);
    void mySignalVouch();
    void my_data(QString,QString,QString);
    void addToTableModel(int,int);
    void toTableDialog();
    void onUpdated_Failed();
    void onDeletion_Failed();
    void onUpdated_Success();
    void onDeletion_Success();
    void onInsert_Success();


};

#endif // VOUCHERSUBHEADSDATAMODEL_H
