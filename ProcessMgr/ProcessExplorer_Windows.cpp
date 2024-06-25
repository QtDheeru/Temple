#include "ProcessExplorer_p.h"

#include <windows.h>
#include <Tlhelp32.h>
#include <string.h>
#include <comdef.h>
#include <QDebug>
#include <QDirIterator>

#include "Settings.h"

QList<DWORD> m_processIDList;

ProcessExplorerPrivate::ProcessExplorerPrivate() : QObject()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

ProcessExplorerPrivate::~ProcessExplorerPrivate()
{
    qDebug() << Q_FUNC_INFO << " Start" << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;
}

void ProcessExplorerPrivate::terminateProcess(QStringList procNames)
{
    qDebug() << Q_FUNC_INFO << " START " << procNames << endl;
    PROCESSENTRY32 pEntry;
    HANDLE deleteprocess;
    DWORD dwExitCode = 0;

    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);

    while (hRes) {
        for (int i = 0; i < procNames.count(); i++) {
            _bstr_t b(pEntry.szExeFile);
            QString str(procNames.at(i));
            QString pName(str.trimmed());
            qDebug() << Q_FUNC_INFO << " Trying to stop process = " << pName << endl;

            if (!strcmp(b, pName.toLatin1().data())) {
                qDebug() << Q_FUNC_INFO << " FILE Terminate" << endl;
                deleteprocess = OpenProcess(PROCESS_TERMINATE, 0, pEntry.th32ProcessID);

                if (deleteprocess != nullptr) {
                            GetExitCodeProcess(deleteprocess, &dwExitCode);
                            TerminateProcess(deleteprocess, dwExitCode);
                            CloseHandle(deleteprocess);
                }
            }
        }

        hRes = Process32Next(hSnapShot, &pEntry);
    }

    CloseHandle(hSnapShot);
    qDebug() << Q_FUNC_INFO << " END" << endl;
}

bool ProcessExplorerPrivate::isProcessRunning(QStringList procNames)
{
    PROCESSENTRY32 pEntry;

    bool isRunning = false;

    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);

    while (hRes) {

        for (int i = 0; i < procNames.count(); i++)
        {
            _bstr_t b(pEntry.szExeFile);
            QString str(procNames.at(i));
            QString pName(str.trimmed());

            if (!strcmp(b, pName.toLatin1().data())) {
                m_processIDList.append(pEntry.th32ProcessID);
                isRunning = true;
                break;
            }
        }

        hRes = Process32Next(hSnapShot, &pEntry);
    }

    CloseHandle(hSnapShot);
    return isRunning;
}

bool ProcessExplorerPrivate::isProcessRunning(QString procName)
{
    PROCESSENTRY32 pEntry;

    bool isRunning = false;
    procName = procName.trimmed();
    procName.append(".exe");

    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);

    while (hRes) {
            _bstr_t b(pEntry.szExeFile);
            QString pName(procName.trimmed());
            if (!strcmp(b, pName.toLatin1().data())) {
                m_processIDList.append(pEntry.th32ProcessID);
            }
            hRes = Process32Next(hSnapShot, &pEntry);
    }

    CloseHandle(hSnapShot);

    qDebug() << Q_FUNC_INFO << " Number of Processes =" << m_processIDList << endl;
    if ( m_processIDList.size() >=2)
        return true;
    else
        return false;
}

bool ProcessExplorerPrivate::waitForProcTermUsingProcID()
{
    long count = m_processIDList.count();
    qDebug() << Q_FUNC_INFO << " Count : " << count << endl;
    HANDLE *handles = new HANDLE[static_cast<unsigned>(count)];

    for (int i=0 ; i<count ; i++) {
        HANDLE h1 = (OpenProcess(SYNCHRONIZE, FALSE, m_processIDList.at(i)));
        handles[i] = h1;
        qDebug() << Q_FUNC_INFO << " getting process id : " << m_processIDList.at(i) << " Handle : " << handles[i] << endl;
    }

    DWORD waitProcess;

    qDebug() << Q_FUNC_INFO << " Wait for Multiple objects " << endl;
    waitProcess = WaitForMultipleObjects(static_cast<unsigned>(count), handles, TRUE , INFINITE);
    qDebug() << Q_FUNC_INFO << " Wait for Multiple objects is over " << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;

    return true;
}

void ProcessExplorerPrivate::monitorProcess()
{
    qDebug() << Q_FUNC_INFO << endl;
}

QStringList ProcessExplorerPrivate::enumerateAllInstalledKobilApps(){
    QLatin1String mainKey("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
    QSettings settings(mainKey,QSettings::NativeFormat);
    QStringList childKeys = settings.allKeys();
    qDebug() << Q_FUNC_INFO << "Number of Keys = " << childKeys.size() << endl;
    QString guidKey;

    foreach(QString key, childKeys) {
        QString value = settings.value(key).toString();
        int index = key.indexOf(QLatin1String("UninstallString"));

        if (index > 0) {
            qDebug() << Q_FUNC_INFO << key <<  " = " << value << endl;
            guidKey = key.mid(0,index-1);
            qDebug() << " GUID = " << guidKey << endl;
            QString dispKey = mainKey + "\\"+guidKey;
            qDebug() << " GUID Display Name = " << dispKey << endl;
            QSettings setts(dispKey,QSettings::NativeFormat);
            QString appName = setts.value("DisplayName", QString()).toString();
            qDebug() << appName;

            if (appName == ""){
                continue;
            }

            this->enumerateAllKobilExes(value, appName);
        }
    }

    QStringList apps = this->listApps();

    for(int i=0; i<apps.size();i++)
    {
        m_kobil_apps.append(apps.at(i));
    }

    qDebug() << " Final Applications for sending to QML = " << this->m_kobil_apps << endl;

    return m_kobil_apps;
}

void ProcessExplorerPrivate::enumerateAllKobilExes(QString exeName, QString appName) {
    int i1= exeName.lastIndexOf("\\");
    QString idir = exeName.left(i1);
    QString eName = exeName.mid(i1+1);
    qDebug() << " Directory Name = " << idir << " eName = " << eName << endl;

    QStringList exes;

    QDirIterator it(idir, QStringList() << "*.exe", QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()) {

        QString qs = it.next();

        int i = qs.lastIndexOf("/");

        if (qs.mid(i + 1) == eName ||
            qs.mid(i + 1) == "QtWebEngineProcess.exe" ||
            qs.mid(i + 1) == "vc_redist.x86.exe") {
            continue;
        }

        exes << qs;
    }

    if (exes.length() == 0) {
        return;
    }

    QString exePath;

    for (const auto &it: exes) {

        if (it.mid(it.lastIndexOf("/") + 1) == (appName + ".exe")) {
          exePath = it;
          break;
        }
    }

    this->isAppKobilSigned(exePath);
}

void ProcessExplorerPrivate::isAppKobilSigned(QString exeName) {
     m_validProc = false;
     qDebug() << Q_FUNC_INFO << " Executable to Verify = " << exeName << endl;
     QString signExe = "sigcheck.exe";
     QStringList args;
     args << "-c";
     args << exeName;
     QProcess *proc = new QProcess;
     connect(proc,SIGNAL(readyReadStandardOutput()),
             this,SLOT(procOutput()));
     connect(proc,SIGNAL(error(QProcess::ProcessError)),
             this,SLOT(procError(QProcess::ProcessError)));
     loop = new QEventLoop;
     connect(this,SIGNAL(done()),loop,SLOT(quit()));
     proc->start(signExe,args);
     proc->waitForStarted();
     proc->waitForFinished();

     qDebug() << Q_FUNC_INFO << " Process is already started $$$$$$$$$$"  << exeName << endl;

     // loop->exec();

     if (m_validProc) {
        m_kobil_apps.append(exeName);

        // no duplicates
        m_kobil_apps = m_kobil_apps.toSet().toList();

        m_kobil_apps.sort();
     }

     qDebug() << Q_FUNC_INFO << " Process is isAppKobilSigned ended " << endl;
     delete proc;
}

void ProcessExplorerPrivate::procError(QProcess::ProcessError err) {

    Q_UNUSED(err)

     m_validProc = false;
     qDebug() << Q_FUNC_INFO << " Process is not started its kobil sign " << endl;
     emit done();
    // loop->quit();
}

void ProcessExplorerPrivate::procOutput() {
     QProcess *proc = qobject_cast<QProcess*>(sender());

     if (proc != nullptr){
         QString output = proc->readAllStandardOutput();

         if (output.contains("KOBIL Systems GmbH")){
             qDebug() << " App = " <<proc->program() << " is Kobil signed " << endl;
             m_validProc = true;
         } else {
             m_validProc =false;
            qDebug() <<  " App is not signed by Kobil = " << output << endl;
         }
     }

     emit done();
}

QStringList ProcessExplorerPrivate::listApps() {

    qDebug() << Q_FUNC_INFO << " Start" << endl;

    const auto knownAppList = Settings::getInstance()->getKnownAppList();

    qDebug() << Q_FUNC_INFO << " Final Apps list = " << knownAppList << endl;
    qDebug() << Q_FUNC_INFO << " End" << endl;

    return knownAppList;
}


