#ifndef ACCOUNTREPORTCSVPROCESSOR_H
#define ACCOUNTREPORTCSVPROCESSOR_H

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
signals:
private:
    static int m_addHeader;
};

#endif // ACCOUNTREPORTCSVPROCESSOR_H
