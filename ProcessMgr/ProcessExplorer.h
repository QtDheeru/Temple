#ifndef PROCESSEXPLORER_H
#define PROCESSEXPLORER_H

#pragma once

#include "ProcessExplorer_p.h"

#include <QDebug>
#include <QSettings>
#include <QThread>

class ProcessExplorer : public QObject
{
    Q_OBJECT

public:
    ProcessExplorer();
    ~ProcessExplorer();

    void terminateprocess(QStringList procNames);
    bool isProcessRunning(QStringList procNames);
    bool isProcessRunning(QString procName);
    bool waitForProcTermUsingProcID();

    QStringList appList() const;
    void setAppList(const QStringList &appList);

public slots:
    QStringList enumerateAllInstalledKobilApps();

signals:
    void processTerminated();

private:
  ProcessExplorerPrivate *d = NULL;
  QStringList m_appList;
};

#endif // PROCESSEXPLORER_H
