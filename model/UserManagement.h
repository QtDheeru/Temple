#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QObject>
#include <QDebug>
class UserManagement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rolenum READ getCurrentRole WRITE setCurrentRole NOTIFY rolenumchanged)
public:
    explicit UserManagement(QObject *parent = nullptr);
    ~UserManagement();
    Q_INVOKABLE void addUser(QString name,QString lastname,QString userid,QString password,QString userRole,QString date);
    void modify(QString name,QString password,int userRole);
    Q_INVOKABLE void authorize(QString username,QString password);
    UserManagement* getUsrMgtInstance();

    int getCurrentRole() const;
    void setCurrentRole(int newCurrentRole);

signals:
    void userAdded(QString msg);
    void rolenumchanged();
private:
    int currentRole;
};

#endif // USERMANAGEMENT_H
