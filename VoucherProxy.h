#ifndef VOUCHERPROXY_H
#define VOUCHERPROXY_H

#include <QObject>
#include "VoucherData/MainHead/VoucherHeadsTableModel.h"
#include "VoucherData/SubHead/VoucherSubHeadsTableModel.h"

class VoucherProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(VoucherSubHeadsTableModel *voucherSubHeadTableModel READ voucherSubHeadsTableModel NOTIFY voucherSubHeadTableModelChanged)
    Q_PROPERTY(VoucherHeadsTableModel *voucherHeadsTableModel READ voucherHeadsTableModel NOTIFY voucherHeadsTableModelChanged)
    Q_PROPERTY(QString my_serial READ getSerialno WRITE setSerialno NOTIFY serial_Changed)
    Q_PROPERTY(QString my_vname READ getVouchername WRITE setVouchername NOTIFY vname_Changed)

public:
    QString serialno;
    QString vouchername;

    explicit VoucherProxy(QObject *parent = nullptr);

    VoucherSubHeadsTableModel*voucherSubHeadsTableModel() const;
    void setVoucherSubHeadsTableModel(std::unique_ptr<VoucherSubHeadsTableModel> newVoucherSubHeadsTableModel);

    VoucherHeadsTableModel*voucherHeadsTableModel() const;
    void setVoucherHeadsTableModel(std::unique_ptr<VoucherHeadsTableModel> newVoucherHeadsTableModel);

    QString getSerialno() const;
    void setSerialno(const QString &newSerialno);

    QString getVouchername() const;
    void setVouchername(const QString &newVouchername);

public slots:
    void addVoucherMainType(QString,QString,QString);
    void updateVoucherInProxy(QString,QString,QString);
    void onVouchToProxy(QString,QString,QString);
    void removeVoucherInProxy(QString);
    void send_Voucher(QString);
    void set_data(int);
    void from_Proxy(QString,QString);
    void toDataModel();
    void toMyQml(QString,QString,QString);
    void addToDb(QString,QString,QString);
    void clearProxy();
    void deleteToDb(QString,QString,QString);
    void updateToDb(QString,QString,QString);
    void onProxyDialog();
    void onSigToProxy();
    void onAddSuccessInTable();
    void onUpdateFailInTable();
    void onUpdateSuccessInTable();
    void onListCountToProxy(int);
    void onSerialErrorInTable();
    void onVoucherErrorInTable();
    void onRemoveSuccessInTable();
    void onRemoveFailInTable();
    void loadTbViewInProxy();
    void rowClickedInProxy(int row);
    void onAddFailInTable();
    void onVoucherNameErrorInTable();
    void listAppendProxy();
    void proxyList();

signals:
    void voucherSubHeadTableModelChanged();
    void voucherHeadsTableModelChanged();
    void vouchToQml(QString a_serial_no,QString a_voucherId,QString a_vouch_name);
    void my_update(QString subid,QString name);
    void use_Data(QString subcat,QString subname,QString voucherId);
    void serial_Changed();
    void vname_Changed();
    void qmlDialog();
    void proxyUpdate();
    void proxyDelete();
    void addSucsessInProxy();
    void updateFailInProxy();
    void updateSuccessInProxy();
    void listCountToQml(int);
    void sigToQml();
    void serialErrorInProxy();
    void voucherErrorInProxy();
    void removeSuccessInProxy();
    void removeFailInProxy();
    void updateQml();
    void deleteQml();
    void insertQml();
    void addFailInProxy();
    void voucherNameErrorInProxy();

private :
    std::unique_ptr<VoucherSubHeadsTableModel> m_voucherSubHeadsTableModel;
    std::unique_ptr<VoucherHeadsTableModel> m_voucherHeadsTableModel;
};

#endif // VOUCHERPROXY_H
