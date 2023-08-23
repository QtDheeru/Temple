#ifndef CHEQUEENTRYDB_H
#define CHEQUEENTRYDB_H

#include <QObject>
#include <QSqlQuery>
#include <QDir>
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>

class ChequeEntryDB : public QObject
{
    Q_OBJECT
public:
    explicit ChequeEntryDB(QObject *parent = nullptr);
//    void addTOdatabase(QString db_receiptDate, QString db_chequeDate, QString db_bankName, QString db_recepitNumber, QString db_amount);

signals:

private:
    QSqlQuery *m_sqlquery2=nullptr;
    QSqlDatabase m_sqlDatabase2;

};

#endif // CHEQUEENTRYDB_H
