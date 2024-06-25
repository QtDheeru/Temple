#ifndef PROCESSEXPLORER_P_H
#define PROCESSEXPLORER_P_H

#pragma once

#include <QObject>
#include <QDebug>
#include <QList>
#include <QSettings>
#include <QDir>
#include <QStringList>
#include <QProcess>
#include <QEventLoop>
#include <QDomDocument>
#include <QStandardPaths>

class ProcessExplorerPrivate : public QObject
{
    Q_OBJECT

public:
    ProcessExplorerPrivate();
    ~ProcessExplorerPrivate();

    void terminateProcess(QStringList procNames);
    bool isProcessRunning(QStringList procNames);
    bool isProcessRunning(QString procName);
    bool waitForProcTermUsingProcID();
    QStringList enumerateAllInstalledKobilApps();
    QStringList listApps();
    bool checkIfDeInstallationFile(QString);

private slots:
    void procOutput();
    void isAppKobilSigned(QString exeName);
    void enumerateAllKobilExes(QString exeName,QString appName);
    void procError(QProcess::ProcessError err);

signals:
    void done();
    void processTerminated();

private:
    void monitorProcess();

protected :
    bool m_validProc=false;
    QStringList m_kobil_apps;
    QEventLoop *loop;
};

#endif // PROCESSEXPLORER_P_H
