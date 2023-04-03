#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H

#include <QObject>
#include <QDebug>
#include"./model/BankDetails.h"
#include<QFile>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include"./model/MomentoCategory.h"

class JsonProcessor : public QObject
{
    Q_OBJECT
public:
    explicit JsonProcessor(QObject *parent = nullptr);
    ~JsonProcessor();

    void readBanksFromJsonToList();
    void readBanksFromJsonToMap();

    void readCategoriesFromJsonToList();
    void readCategoriesFromJsonToMap();
    void printBanksList();
    void printBanksMap();

    void printCategoriesList();
    void printCategoriesMap();

    const QList<BankDetails *> &banksList() const;
    void setBanksList(const QList<BankDetails *> &newBanksList);
    QStringList bankListAsStringList();

    const QMap<int, BankDetails *> &banksMap() const;
    void setBanksMap(const QMap<int, BankDetails *> &newBanksMap);

    const QList<MomentoCategory *> &categoryList() const;
    void setCategoryList(const QList<MomentoCategory *> &newCategoryList);

    const QMap<int, MomentoCategory *> &categoryMap() const;
    void setCategoryMap(const QMap<int, MomentoCategory *> &newCategoryMap);

    QStringList categoryListAsStringList();

signals:

private:
    QList<BankDetails*> m_banksList;
    QMap<int,BankDetails*> m_banksMap;

    QList<MomentoCategory*> m_categoryList;
    QMap<int,MomentoCategory*> m_categoryMap;
};

#endif // JSONPROCESSOR_H
