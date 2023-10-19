#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QObject>
#include <QDebug>
class UserManagement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rolenum READ getCurrentRole WRITE setCurrentRole NOTIFY rolenumchanged)
    Q_PROPERTY(QString signIn_Name READ getSignIn_Name WRITE setSignIn_Name NOTIFY signIn_NameChanged)

public:
    explicit UserManagement(QObject *parent = nullptr);
    ~UserManagement();
    Q_INVOKABLE void addUser(QString name,QString lastname,QString userid,QString password,QString userRole,QString date);
    void modify(QString name,QString password,int userRole);
    Q_INVOKABLE void authorize(QString username,QString password);
    UserManagement* getUsrMgtInstance();

    int getCurrentRole() const;
    void setCurrentRole(int newCurrentRole);

    const QString &getSignIn_Name() const;
    void setSignIn_Name(const QString &newSignIn_Name);

signals:
    void userAdded(QString msg);
    void rolenumchanged();
    void signIn_NameChanged();

public slots:
   void user_Recieved(int rolenum,QString signInName);

private:
    int currentRole;
    QString signIn_Name;
};

#endif // USERMANAGEMENT_H
