#ifndef DBCHECKER_H
#define DBCHECKER_H

#include <QObject>
#include <QDebug>
#include "../DBInterface.h"

class DBChecker : public QObject
{
    Q_OBJECT
public:
    explicit DBChecker(QObject *parent = nullptr);
    Q_INVOKABLE bool checkCredentials(QString user,QString pass);

signals:
    void correctCredentials();
    void wrongCredentials();
private:
    DBInterface *m_db;

};

#endif // DBCHECKER_H
