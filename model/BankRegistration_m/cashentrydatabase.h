#ifndef CASHENTRYDATABASE_H
#define CASHENTRYDATABASE_H

#include <QObject>
#include <QSqlQuery>
#include <QDir>
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
class CashEntryDataBase : public QObject
{
    Q_OBJECT
public:
    explicit CashEntryDataBase(QObject *parent = nullptr);
    void addTOdatabase(QString a_date, QString a_lastreci, QString a_cashinhand, QString a_tobank, QString a_transType, QString a_bank, QString a_person,QString a_status,QString a_notes);
signals:
private:
    QSqlDatabase m_sqlDatabase;
    QSqlQuery *m_sqlquery;


};

#endif // CASHENTRYDATABASE_H
