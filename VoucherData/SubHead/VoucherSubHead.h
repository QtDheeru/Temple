#ifndef VOUCHERSUBHEAD_H
#define VOUCHERSUBHEAD_H

#include <QObject>

class VoucherSubHead:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString my_subid READ getVSubid WRITE setVSubid NOTIFY vsub_Changed)
    Q_PROPERTY(QString my_vscn READ getVscn WRITE setVscn NOTIFY vscn_Changed)

public:
    QString vSubid,Vscn;
    VoucherSubHead();
    QString getVSubid() const;
    void setVSubid(const QString &newVSubid);
    QString getVscn() const;
    void setVscn(const QString &newVscn);

signals:
    void vsub_Changed();
    void vscn_Changed();

};

#endif // VOUCHERSUBHEAD_H

