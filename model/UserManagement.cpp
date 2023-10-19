#include "UserManagement.h"
#include "DBInterface.h"
UserManagement::UserManagement(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    this->setCurrentRole(-1);
    connect(DBInterface::getInstance(),&DBInterface::sendRolenumber,this,&UserManagement::user_Recieved);
}
UserManagement::~UserManagement()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void UserManagement::addUser(QString name, QString lastname, QString userid, QString password, QString userRole, QString date)
{
    qDebug()<<Q_FUNC_INFO<<name<<lastname<<userid<<password<<userRole<<date<<Qt::endl;
    int rolenum=-1;
    if(userRole=="Admin"){
        rolenum=1;
    } else {
        rolenum=2;
    }
    DBInterface::getInstance()->add_new_signin_details(name,lastname,userid,password,rolenum,"");
}

void UserManagement::modify(QString name, QString password, int userRole)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void UserManagement::authorize(QString username, QString password)
{
    qDebug()<<Q_FUNC_INFO<<username<<password<<Qt::endl;
    DBInterface::getInstance()->checkCredentials(username,password);

}

int UserManagement::getCurrentRole() const
{
    return currentRole;
}

void UserManagement::setCurrentRole(int newCurrentRole)
{
    qDebug()<<"The role number recieved"<<newCurrentRole<<Qt::endl;
    currentRole = newCurrentRole;
    emit rolenumchanged();
}

void UserManagement::user_Recieved(int rolenum, QString signInName)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    this->setCurrentRole(rolenum);
    this->setSignIn_Name(signInName);
}

const QString &UserManagement::getSignIn_Name() const
{
    return signIn_Name;
}

void UserManagement::setSignIn_Name(const QString &newSignIn_Name)
{
    signIn_Name = newSignIn_Name;
    emit signIn_NameChanged();
}


