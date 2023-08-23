#ifndef VOUCHERSUBHEADDATABASE_H
#define VOUCHERSUBHEADDATABASE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
class VoucherSubheadDatabase : public QObject
{
    Q_OBJECT
public:
    explicit VoucherSubheadDatabase(QObject *parent = nullptr);
    QSqlDatabase Mydbase;
    QSqlQuery *Myquery;
    void addMyDB(QString,QString,QString);
    void selectData(QString);
    void updateToDb(QString,QString,QString);
    void deleteData(QString,QString,QString);
signals:
    void mySelectSignal(QString,QString,QString);
    void toModelDialog();
    void update_Failed();
    void deletion_Failed();

};

#endif // VOUCHERSUBHEADDATABASE_H
