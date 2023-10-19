#ifndef CONFIGUREAPP_H
#define CONFIGUREAPP_H

#include <QObject>
#include <QtXml>
#include <QTextStream>

class ConfigureApp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString welcomescreenImg READ welcomeScreenImage NOTIFY welcomeScreenImageChanged)
    Q_PROPERTY(QString loginImg READ loginImage NOTIFY LoginImageChanged)
    Q_PROPERTY(QString appPath READ appPath NOTIFY appPathChanged)
public:
    explicit ConfigureApp(QObject *parent = nullptr);
    void loadXMLFile();
    static ConfigureApp* getInstance();

    const QString &welcomeScreenImage() const;
    void setWelcomeScreenImage(const QString &newWelcomeScreenImage);

    const QString &loginImage() const;
    void setLoginImage(const QString &newLoginImage);

    const QString &appPath() const;
    void setAppPath(const QString &newAppPath);

    const QString &header1() const;
    void setHeader1(const QString &newHeader1);

    const QString &header2() const;
    void setHeader2(const QString &newHeader2);

    const QString &header3() const;
    void setHeader3(const QString &newHeader3);

    const QString &header4() const;
    void setHeader4(const QString &newHeader4);

    const QStringList &footers() const;

    void setFooters(const QStringList &newFooters);

signals:
    void welcomeScreenImageChanged();
    void LoginImageChanged();
    void appPathChanged();

private:
    QString m_welcomeScreenImage;
    QString m_loginImage;
    QString m_appPath;
    //headers
    QString m_header1;
    QString m_header2;
    QString m_header3;
    QString m_header4;
    //footer
    QStringList m_footers;
    static ConfigureApp* m_obj;

};

#endif // CONFIGUREAPP_H
