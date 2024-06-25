#include "ProcessExplorer.h"

ProcessExplorer::ProcessExplorer() : QObject()
{
    qDebug() << Q_FUNC_INFO << " START" << Qt::endl;
    d = new ProcessExplorerPrivate;
    connect(d,&ProcessExplorerPrivate::processTerminated,this,&ProcessExplorer::processTerminated);
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
}

ProcessExplorer::~ProcessExplorer()
{
    qDebug() << Q_FUNC_INFO << " START" << Qt::endl;
    delete d;
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
}

void ProcessExplorer::terminateprocess(QStringList procNames)
{
    qDebug() << Q_FUNC_INFO << " START =" << procNames << Qt::endl;
    d->terminateProcess(procNames);
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
}

bool ProcessExplorer::isProcessRunning(QStringList procNames)
{
    qDebug() << Q_FUNC_INFO << " START" << Qt::endl;
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
    return d->isProcessRunning(procNames);
}

bool ProcessExplorer::isProcessRunning(QString procName)
{
    qDebug() << Q_FUNC_INFO << " START" << Qt::endl;
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
    return d->isProcessRunning(procName);
}

bool ProcessExplorer::waitForProcTermUsingProcID()
{
    qDebug() << Q_FUNC_INFO << " START" << Qt::endl;
    qDebug() << Q_FUNC_INFO << " END" << Qt::endl;
    return d->waitForProcTermUsingProcID();
}

QStringList ProcessExplorer::enumerateAllInstalledKobilApps()
{
    qDebug() << Q_FUNC_INFO << " Enumerate all installed Apps"<< Qt::endl;
    m_appList = d->enumerateAllInstalledKobilApps();
    qDebug() << Q_FUNC_INFO << " All the apps collected =" << m_appList << Qt::endl;
    this->thread()->quit();
    return m_appList;
}

QStringList ProcessExplorer::appList() const
{
    return m_appList;
}

void ProcessExplorer::setAppList(const QStringList &appList)
{
    m_appList = appList;
}
