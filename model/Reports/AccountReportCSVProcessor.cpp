#include "AccountReportCSVProcessor.h"

AccountReportCSVProcessor::AccountReportCSVProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

AccountReportCSVProcessor::~AccountReportCSVProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_addHeader = 1;
}
int AccountReportCSVProcessor::m_addHeader = 1;
void AccountReportCSVProcessor::recieveAccountReportList(QList<AccountReportElement *> accountReportList)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString todayDate ="AccountsReport_"+ QDate::currentDate().toString("ddd_dd_MMM_yyyy");
    Q_UNUSED(todayDate);
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save File","", "Text Files (*.csv)");//Suman N added
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            // Perform save operation
            QTextStream out(&file);
            QString storeData;
            if(m_addHeader)
            {
                qDebug()<<"Inside if"<<Qt::endl;
                QString header;
                header =  QString("Sl_No") + "," + "Seva_Name" + "," + "Seva_Cost" + "," + "Seva_Count"+ "," +"Cash" + "," + "Cheque"+ "," + "NEFT" + "," + "UPI"+ "," + "Total_Amount" +'\n';
                out<<header.toUpper();
            }
            for(auto it =accountReportList.begin(); it != accountReportList.end(); it++){
                storeData =QString::number((*it)->slNo()) +","+
                        (*it)->getSeva_name()+","+
                        QString::number((*it)->getSeva_cost())+","+
                        QString::number((*it)->getSeva_ticket())+","+
                        QString::number((*it)->getCash())+","+
                         QString::number((*it)->getCheque()) +","+
                         QString::number((*it)->getNeft()) +","+
                         QString::number((*it)->getUpi()) +","+
                        QString::number((*it)->getSeva_total())+'\n';
                out<<storeData;
            }
            file.close();

            qDebug() << "File saved: " << fileName;
        }
        else
        {
            qCritical() << "Failed to open file for saving.";
        }
    }
    m_addHeader =0;
}
