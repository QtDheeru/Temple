#ifndef VOUCHERHEADSDATAMODEL_H
#define VOUCHERHEADSDATAMODEL_H

#include <QObject>
#include "VoucherData/MainHead/VoucherHeadsTypeDetails.h"
#include "VoucherData/MainHead/VoucherHeadsDataBase.h"
#include "model/DBInterface.h"

class VoucherHeadsDataModel : public QObject
{
    Q_OBJECT
public:
    enum role{
        serialNumber,voucherID,VoucherName
    };
    explicit VoucherHeadsDataModel(QObject *parent = nullptr);
    const QHash<int, QByteArray> &roles();
    QVariant data(int row, int col, int role);
    int size();
    void init();
    void callRowInDataModel(int);
    void addDetails(QString,QString,QString);
    void updateDetails(QString,QString,QString);
    void removeDetails(QString);
    void loadTbViewInData();

signals:
    void serialError();
    void voucherError();
    void sigEmpty();
    void voucherNameError();
    void countToTableModel(int num);
    void addTableModel(int,int);
    void vouchToTableModel(QString,QString,QString);
    void updateToTableModel(int);
    void removeToTableModel(int);
    void addSuccessInData();
    void updateFailInData();
    void updateSuccessInData();
    void removeSuccessInData();
    void listCount(int);
    void removeFailInData();
    void addFailInData();
public slots:
    void onSelectSignalFromDB(QString,QString,QString);
    void onUpdateSuccessInDB(QString,QString,QString);
    void onDeletionSuccessInDB(QString);
    void onUpdateFailInDB();
    void onDeletionFailInDB();
    void onAddFailInDB();
private :
    QString m_error;
    int m_devoteeFoundIndex;
    QHash<int, QByteArray> m_roles;
    QList<std::shared_ptr<VoucherHeadsTypeDetails>>m_voucherHeadList;
};

#endif // VOUCHERHEADSDATAMODEL_H
