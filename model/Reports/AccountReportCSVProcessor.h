#ifndef ACCOUNTREPORTCSVPROCESSOR_H
#define ACCOUNTREPORTCSVPROCESSOR_H

#include "AccountFullreportElement.h"
#include "AccountReportElement.h"
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDate>
#include <QDir>
#include <QFileDialog>
class AccountReportCSVProcessor : public QObject
{
    Q_OBJECT
public:
    explicit AccountReportCSVProcessor(QObject *parent = nullptr);
    ~AccountReportCSVProcessor();
public slots:
    void recieveAccountReportList(QList<AccountReportElement*>); //Suman N added
    void recieveAccountFullreportElementList(QList<AccountFullreportElement*> accntfulList);  //Suman N added
signals:
    void successMessage(QString exportmsg);
private:
    static int m_addHeader;
    const QString msg= "Export completed";
};

#endif // ACCOUNTREPORTCSVPROCESSOR_H
