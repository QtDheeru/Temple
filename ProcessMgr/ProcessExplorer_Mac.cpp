#include "ProcessExplorer_p.h"
#include <QMap>
#include <QProcess>
#include <QEventLoop>
#include <QTimer>
#include <QDirIterator>

QEventLoop *m_eveLoop;
QStringList m_processIDList;
enum {
    P_ID = 2,
    P_NAM = 8
};

ProcessExplorerPrivate::ProcessExplorerPrivate() : QObject()
{
    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;

    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
}

ProcessExplorerPrivate::~ProcessExplorerPrivate()
{
    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;
    delete m_eveLoop;
    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
}

void ProcessExplorerPrivate::terminateProcess(QStringList procNames)
{
    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;

    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
}

bool ProcessExplorerPrivate::isProcessRunning(QStringList procNames)
{
    qDebug() << Q_FUNC_INFO << " ->>>>>>>> Start" << Qt::endl;
    bool isRunning = false;
    QMap<QString,QString> map;
    map.clear();
    QProcess process;
    process.start("ps",QStringList() << "-aef");
    process.waitForFinished(-1);

    QString arr = process.readAllStandardOutput();
    QStringList splitArr;
    splitArr = arr.split("\n");
    qDebug() << Q_FUNC_INFO << " Process list from System =" << arr <<Qt::endl;

    foreach (QString str, splitArr) {
        if(str.contains("  ")){
            str.replace("   "," ");
            if(str.contains("   ")){
                str.replace("  "," ");
            }
            if(str.contains("  ")){
                str.replace("  "," ");
            }
        }

        QStringList s = str.split(" ");
        QString id,name;
        for(int i=0 ; i<s.count() ; i++){
            switch(i){
            case P_ID:
                id = s.at(P_ID);
                break;
            case P_NAM:{
                QString str = s.at(P_NAM);
                QStringList n = str.split("/");
                QListIterator<QString> itr(n);
                itr.toBack();
                name = itr.previous();
                break;
            }
            default:
                break;
            }
            map.insert(name,id);
        }
    }

    QStringList::iterator itr;

    for(itr = procNames.begin() ; itr != procNames.end() ; itr++){
        qDebug() << Q_FUNC_INFO << " Checking the process   =" << *itr << Qt::endl;
        if(map.contains(*itr)){
            qDebug() << Q_FUNC_INFO << " Process is Still running  =" << *itr << Qt::endl;
            m_processIDList.append(map.value(*itr));
            isRunning = true;
        } else {
            qDebug() << Q_FUNC_INFO << " Process is terminated" << Qt::endl;
        }
    }
    qDebug() << Q_FUNC_INFO << " Process ID List = " <<  m_processIDList << Qt::endl<< " isRunning : " << isRunning << Qt::endl;
    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
    if (m_processIDList.size() >=2)
        return true;
    else
        return false;
    //return isRunning;
}

bool ProcessExplorerPrivate::isProcessRunning(QString procName)
{
    qDebug() << Q_FUNC_INFO << " ->>>>>>>> Start" << Qt::endl;
    bool isRunning = false;
    QMap<QString,QString> map;
    map.clear();
    QProcess process;
    process.start("ps",QStringList() << "-aef");
    process.waitForFinished(-1);

    QString arr = process.readAllStandardOutput();
    QStringList splitArr;
    splitArr = arr.split("\n");
    qDebug() << Q_FUNC_INFO << " Process list from System =" << arr <<Qt::endl;
    QList<QString> procs;

    foreach (QString str, splitArr) {
        if(str.contains("  ")){
            str.replace("   "," ");
            if(str.contains("   ")){
                str.replace("  "," ");
            }
            if(str.contains("  ")){
                str.replace("  "," ");
            }
        }

        QStringList s = str.split(" ");
        QString id,name;
        for(int i=0 ; i<s.count() ; i++){
            switch(i){
            case P_ID:
                id = s.at(P_ID);
                break;
            case P_NAM:{
                QString str = s.at(P_NAM);
                QStringList n = str.split("/");
                QListIterator<QString> itr(n);
                itr.toBack();
                name = itr.previous();
                break;
            }
            default:
                break;
            }
            if (name.compare(procName)==0)
                procs.append(name);
        }
    }

    qDebug() << Q_FUNC_INFO << " Process List = " <<  procs << Qt::endl<< " isRunning : " << isRunning << Qt::endl;
    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
    if (procs.size() >=2)
        return true;
    else
        return false;
}

bool ProcessExplorerPrivate::waitForProcTermUsingProcID()
{
    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;
    m_eveLoop = new QEventLoop;
    QTimer *timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&ProcessExplorerPrivate::monitorProcess,Qt::UniqueConnection);
    timer->start(1000);
    qDebug() << Q_FUNC_INFO << " IS TIMER ACTIVE : " << timer->isActive() << Qt::endl;
    m_eveLoop->exec();
    qDebug() << Q_FUNC_INFO << " IS TIMER ACTIVE : " << timer->isActive() << Qt::endl;
    timer->stop();
    timer->deleteLater();
    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
    return true;
}

void ProcessExplorerPrivate::monitorProcess()
{
    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;
    QMap<QString,QString> map;
    map.clear();
    QProcess process;
    process.start("ps",QStringList() << "-aef");
    process.waitForFinished(-1);

    QString arr = process.readAllStandardOutput();
    QStringList splitArr;
    splitArr = arr.split("\n");

    foreach (QString str, splitArr) {
        if(str.contains("  ")){
            str.replace("   "," ");
            if(str.contains("   ")){
                str.replace("  "," ");
            }
            if(str.contains("  ")){
                str.replace("  "," ");
            }
        }

        QStringList s = str.split(" ");
        QString id,name;
        for(int i=0 ; i<s.count() ; i++){
            switch(i){
            case P_ID:
                id = s.at(P_ID);
                break;
            case P_NAM: {
                QString str = s.at(P_NAM);
                QStringList n = str.split("/");
                QListIterator<QString> itr(n);
                itr.toBack();
                name = itr.previous();
                break;
            }
            default:
                break;
            }
            map.insert(id,name);
        }
    }

    QMap<QString,QString>::iterator itr;
    QStringList::iterator lItr;

    for(itr = map.begin() ; itr != map.end() ; itr++){
        for(lItr = m_processIDList.begin() ; lItr != m_processIDList.end() ; lItr++){
            if(!map.contains(*lItr)){
                m_eveLoop->exit();
                qDebug() << Q_FUNC_INFO << " Process Terminated by user" << Qt::endl;
                break;
            }
        }
    }
    qDebug() << Q_FUNC_INFO << " End" << Qt::endl;
}

QStringList ProcessExplorerPrivate::enumerateAllInstalledKobilApps(){

    QProcess m_process;
     QList<QString> location;
    QString program = "system_profiler";
    QStringList arguments;
    arguments <<"SPApplicationsDataType";


    m_process.setProgram(program);
    m_process.setArguments(arguments);


    m_process.start();
    m_process.waitForFinished();

    QByteArray arr=m_process.readAll();
    m_process.close();

    QString s(arr);
    QStringList dataStrings = s.split('\n');
    QStringList result;
    result = dataStrings.filter("Location");

    for(int i=0;i<result.size();i++){
        QString stri = result.at(i);
        stri.remove(0,16);
        if(stri.contains("/Applications")){
        location.append(stri);
        }
    }

    QProcess m_KobilProcess;
    QStringList dataStringer;
    QByteArray arry;
    QStringList results;


    QString programs = "codesign";
    m_KobilProcess.setProgram(programs);
    for(int i = 0; i<location.size();i++){

        QStringList arguments;
        arguments  <<"-dv"<<"--verbose=4"<<location.at(i);
        m_KobilProcess.setArguments(arguments);
        m_KobilProcess.start();
        m_KobilProcess.waitForFinished();
        arry=m_KobilProcess.readAllStandardError();
        //        if(arry.contains("Authority=Developer ID Application: KOBIL Systems GmbH (GQYVQY42PQ)") && (arry.contains("Identifier=de.kobil.trustedverify.auth") | arry.contains("Identifier=com.kobil.midAppMacOS"))){
        if(arry.contains("Authority=Developer ID Application: KOBIL Systems GmbH (GQYVQY42PQ)")){
            if(checkIfDeInstallationFile(location[i])==false)
            {
                QString s(arry);
                dataStringer = s.split("\n");
                results= dataStringer.filter("Executable");
                for(int i=0;i<results.size();i++){
                    QString stri = results.at(i);
                    stri.remove(0,11);
                    m_kobil_apps.append(stri);
                }
            }
        }

        m_KobilProcess.close();
    }

    qDebug() << " Final Applications for sending to QML = " << this->m_kobil_apps << Qt::endl;
    return m_kobil_apps;
}

void ProcessExplorerPrivate::enumerateAllKobilExes(QString exeName, QString appName) {
    int i1= exeName.lastIndexOf("\\");
    QString idir = exeName.left(i1);
    QString eName = exeName.mid(i1+1);
    qDebug() << " Directory Name = " << idir << " eName = " << eName << Qt::endl;

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
     qDebug() << Q_FUNC_INFO << " Executable to Verify = " << exeName << Qt::endl;
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

     qDebug() << Q_FUNC_INFO << " Process is already started $$$$$$$$$$"  << exeName << Qt::endl;

     // loop->exec();

     if (m_validProc) {
        m_kobil_apps.append(exeName);

        // no duplicates
        m_kobil_apps = m_kobil_apps.toSet().toList();

        m_kobil_apps.sort();
     }

     qDebug() << Q_FUNC_INFO << " Process is isAppKobilSigned ended " << Qt::endl;
     delete proc;
}

void ProcessExplorerPrivate::procError(QProcess::ProcessError err) {

    Q_UNUSED(err)

     m_validProc = false;
     qDebug() << Q_FUNC_INFO << " Process is not started its kobil sign " << Qt::endl;
     emit done();
    // loop->quit();
}

void ProcessExplorerPrivate::procOutput() {
     QProcess *proc = qobject_cast<QProcess*>(sender());

     if (proc != nullptr){
         QString output = proc->readAllStandardOutput();

         if (output.contains("KOBIL Systems GmbH")){
             qDebug() << " App = " <<proc->program() << " is Kobil signed " << Qt::endl;
             m_validProc = true;
         } else {
             m_validProc =false;
            qDebug() <<  " App is not signed by Kobil = " << output << Qt::endl;
         }
     }

     emit done();
    // loop->quit();
}

QStringList ProcessExplorerPrivate::listApps() {

    QStringList apps;

    qDebug() << Q_FUNC_INFO << " Start" << Qt::endl;

    // QFile file(Settings::getInstance()->getConfigFile().c_str());
    // QByteArray array;

    // if (file.open(QIODevice::ReadOnly)) {
    //     array = file.readAll();
    // } else {
    //     qDebug() << Q_FUNC_INFO << "File couldn't open" << Qt::endl;
    //     qDebug() << file.errorString() << Qt::endl;
    // }

    // file.close();

    // QDomDocument doc;
    // doc.setContent(array);

    // QDomElement root = doc.documentElement();
    // QDomNodeList nodeList = root.childNodes();
    // QDomNodeList childNodeList;

    // for (int i=0 ; i<nodeList.size() ; i++) {
    //     QDomElement ele = nodeList.at(i).toElement();

    //     if (ele.tagName().compare("AppInstalled") == 0) {
    //         childNodeList = ele.childNodes();

    //         for (int k=0 ; k<childNodeList.size() ; k++) {
    //             QDomElement element = childNodeList.at(k).toElement();
    //             QString appLocation = element.text();
    //             qDebug() << Q_FUNC_INFO << appLocation << Qt::endl;
    //             int index = appLocation.indexOf("%");
    //             int lastIndex = appLocation.lastIndexOf("%");
    //             qDebug() << Q_FUNC_INFO << " Index = " << index << " Last Index = " << lastIndex << Qt::endl;
    //             QString finalPath = appLocation;

    //             if (index == 0 && lastIndex >0) {
    //                 QString loc = appLocation.mid(index+1,lastIndex-1);
    //                 qDebug() << Q_FUNC_INFO << " Location Details = " << loc << Qt::endl;

    //                 if (QString::compare("HomeDir",loc,Qt::CaseInsensitive)==0) {
    //                     //QString tempPath = QStandardPaths::displayName(QStandardPaths::HomeLocation);
    //                     QString tempPath = QDir::homePath();
    //                     QString addPath = appLocation.mid(lastIndex+1);
    //                     finalPath = tempPath + addPath;
    //                     qDebug() << Q_FUNC_INFO << " Path = " << finalPath << Qt::endl;
    //                 }

    //                 if (QString::compare("AppData",loc,Qt::CaseInsensitive)==0) {
    //                     // QString tempPath = QStandardPaths::displayName(QStandardPaths::AppDataLocation);
    //                     QString tempPath = QDir::homePath() + "/AppData/Roaming";
    //                     QString addPath = appLocation.mid(lastIndex+1);
    //                     finalPath = tempPath + addPath;
    //                     qDebug() << Q_FUNC_INFO << " Path = " << finalPath << Qt::endl;
    //                 }
    //             }

    //             if (QFile::exists(finalPath)) {
    //                 qDebug() << "The exe present in the system " << finalPath << Qt::endl;
    //                 apps.append(finalPath);
    //             }
    //         }
    //     }
    // }

    // qDebug() << Q_FUNC_INFO << " Final Apps list = " << apps << Qt::endl;
    // qDebug() << Q_FUNC_INFO << " End" << Qt::endl;

    return apps;
}



bool ProcessExplorerPrivate::checkIfDeInstallationFile(QString FolderPath)
{  
    int pos = FolderPath.lastIndexOf(QChar('/'));
    QDir dir(FolderPath.left(pos));
    QStringList filters;
    filters << "*.dat";
    QStringList list  = dir.entryList(filters, QDir::Files);
    for (int i = 0; i < list.size(); i++) {
        int pos1 = list[i].lastIndexOf(QChar('.'));
        if(FolderPath.contains( list[i].left(pos1))){
            return true;
        }else {
             return false;
        }
    }
}

