#include "DBChecker.h"

DBChecker::DBChecker(QObject *parent) : QObject(parent)
{
    m_db =  DBInterface::getInstance();
    connect(m_db,&DBInterface::success,this,&DBChecker::correctCredentials);
    connect(m_db,&DBInterface::wrongCred,this,&DBChecker::wrongCredentials);
}

bool DBChecker::checkCredentials(QString user, QString pass)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    return m_db->checkCredentials(user,pass);
}

