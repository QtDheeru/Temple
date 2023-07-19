#include "VoucherReportCSVProcessor.h"

VoucherReportCSVProcessor::VoucherReportCSVProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    //    int id=0;
    //    QString todayDate = QDate::currentDate().toString("ddd_dd_MMM_yyyy"+QString::number(id++));
    //    QString vpath= "VoucherReportExcelSheets/";
    //    m_filev.setFileName("Vouchers"+todayDate+".csv");
    //    if(!m_filev.open(QIODevice::WriteOnly|QIODevice::Truncate))
    //    {
    //        qWarning()<<Q_FUNC_INFO<<m_filev.error() <<Qt::endl;
    //        return;
    //    }
    //    m_filev.close();
    QString todayDate ="VouchereReport_"+ QDate::currentDate().toString("ddd_dd_MMM_yyyy");
    Q_UNUSED(todayDate);
    fileName = QFileDialog::getSaveFileName(nullptr, "Save File","", "Text Files (*.csv)");  //Suman N added
}

VoucherReportCSVProcessor::~VoucherReportCSVProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_addHeader = 1;
}

int VoucherReportCSVProcessor::m_addHeader =1;

void VoucherReportCSVProcessor::writeToCsvFormatVoucherReport(QList<VoucherElement*> voucherReportList)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(!fileName.isEmpty()){
        QFile m_filev(fileName);
        if(m_filev.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            QTextStream out(&m_filev);
            QString storeData;
            if(m_addHeader)
            {
                QString header;
                header =  QString("Voucher_No") + "," + "Date" + "," + "Name" + "," + "Phone_No" + "," + "Cost" + "," + "Voucher_Type" + "," + "Item" + "," + "PaymentMode" + "," + "Payment_ReferenceNo" +'\n';
                out<<header.toUpper();
            }
            for(auto it = voucherReportList.begin(); it != voucherReportList.end(); it++){
                storeData = QString::number((*it)->voucherNo())+","+
                        (*it)->voucherDate()+","+
                        (*it)->voucherName()+","+
                        (*it)->mobileNo()+","+
                        (*it)->voucherCost()+","+
                        (*it)->voucherType()+","+
                        (*it)->voucherItem()+","+
                        (*it)->voucherPaymentMode()+","+
                        (*it)->PaymentReference()+'\n';
                out<<storeData;
            }
            qDebug() << "File saved: " << fileName;
            m_filev.close();
        }
        else{
            qCritical() << "Failed to open file for saving.";
        }
    }
    m_addHeader = 0;
}
