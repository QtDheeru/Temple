#ifndef VOUCHERHEADSDATABASE_H
#define VOUCHERHEADSDATABASE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDir>

class VoucherHeadsDataBase : public QObject
{
    Q_OBJECT
public:
    explicit VoucherHeadsDataBase(QObject *parent = nullptr);
    QSqlDatabase dbase;
    QSqlQuery *query;
    void addData(QString,QString,QString);
    void updateData(QString,QString,QString);
    void selectData();
    void removeData(QString);
    void init();
signals:
    void selectSignal(QString,QString,QString);
    void removeSignal(QString,QString,QString);

};

#endif // VOUCHERHEADSDATABASE_H
