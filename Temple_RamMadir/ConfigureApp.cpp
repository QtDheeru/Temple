#include "ConfigureApp.h"

ConfigureApp::ConfigureApp(QObject *parent) : QObject(parent)
{

}

ConfigureApp * ConfigureApp::m_obj = nullptr;

void ConfigureApp::loadXMLFile(){
    QDomDocument configXML;
    QFile xmlFile(m_appPath + "/app_config.xml");
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        qWarning() << Q_FUNC_INFO << xmlFile.error() << Qt::endl;
        return;
    }
    configXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = configXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    QString datas = "";

    while(node.isNull() == false)
    {
//        qDebug() << Q_FUNC_INFO << node.tagName();
        if(node.tagName() == "WelcomeScreenImage"){
            m_welcomeScreenImage = node.text();
            qDebug() << Q_FUNC_INFO << m_welcomeScreenImage;
        }
        if(node.tagName() == "LoginPageImage"){
            m_loginImage = node.text();
            qDebug() << Q_FUNC_INFO << m_loginImage;
        }
        if(node.tagName() == "Header1")
            m_header1 = node.text();
        if(node.tagName() == "Header2")
            m_header2 = node.text();
        if(node.tagName() == "Header3")
            m_header3 = node.text();
        if(node.tagName() == "Header4")
            m_header4 = node.text();
        if(node.tagName().contains("Footer"))
            m_footers<< node.text();
        node = node.nextSibling().toElement();
    }
}

ConfigureApp *ConfigureApp::getInstance()
{
    if(m_obj==nullptr){
        m_obj = new ConfigureApp;
        return m_obj;
    }
    return m_obj;
}

const QString &ConfigureApp::welcomeScreenImage() const
{
    return m_welcomeScreenImage;
}

void ConfigureApp::setWelcomeScreenImage(const QString &newWelcomeScreenImage)
{
    m_welcomeScreenImage = newWelcomeScreenImage;
}

const QString &ConfigureApp::loginImage() const
{
    return m_loginImage;
}

void ConfigureApp::setLoginImage(const QString &newLoginImage)
{
    m_loginImage = newLoginImage;
}

const QString &ConfigureApp::appPath() const
{
    return m_appPath;
}

void ConfigureApp::setAppPath(const QString &newAppPath)
{
    m_appPath = newAppPath;
}

const QString &ConfigureApp::header1() const
{
    return m_header1;
}

void ConfigureApp::setHeader1(const QString &newHeader1)
{
    m_header1 = newHeader1;
}

const QString &ConfigureApp::header2() const
{
    return m_header2;
}

void ConfigureApp::setHeader2(const QString &newHeader2)
{
    m_header2 = newHeader2;
}

const QString &ConfigureApp::header3() const
{
    return m_header3;
}

void ConfigureApp::setHeader3(const QString &newHeader3)
{
    m_header3 = newHeader3;
}

const QString &ConfigureApp::header4() const
{
    return m_header4;
}

void ConfigureApp::setHeader4(const QString &newHeader4)
{
    m_header4 = newHeader4;
}

const QStringList &ConfigureApp::footers() const
{
    return m_footers;
}

void ConfigureApp::setFooters(const QStringList &newFooters)
{
    m_footers = newFooters;
}

