#include "SevaReceiptCsvProcessor.h"

SevaReceiptCsvProcessor::SevaReceiptCsvProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QString todayDate = QDate::currentDate().toString("ddd_dd_MMM_yyyy");
    QString path =  "Data/";
    QDir::setCurrent(path);
    m_file.setFileName(todayDate+".csv");

    if(!m_file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        qWarning()<<Q_FUNC_INFO<<"----file not open"<<m_file.error() << Qt::endl;
        return;
    }
    m_file.close();
}

SevaReceiptCsvProcessor::~SevaReceiptCsvProcessor()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_addHeader = 1;
}

int SevaReceiptCsvProcessor::m_addHeader =1;

void SevaReceiptCsvProcessor::writeToCsvFormate(SevaBookingElement *sr)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    if(!m_file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        qWarning()<<Q_FUNC_INFO<<m_file.error() <<Qt::endl;
        return;
    }
    QTextStream out(&m_file);
    QString storeData;
    if(m_addHeader)
    {
        QString header;
        header =  QString("Sno") + "," + "Name" + "," + "Mobile" + "," + "SevaName" + "," + "SevaDate" + "," + "ReceiptDate" + "," + "Total" + "," + "Cash" + "," + "Bank" + "," + "Reference" + "," + "Momento" + "," + "address"+'\n';
        out<<header.toUpper();
    }
    storeData = sr->sno()+","+
            sr->person()->devoteeName()+","+
            sr->person()->mobileNumber()+","+
            sr->sevaname()+","+
            sr->sevaDate()+","+
            sr->receiptDate()+","+
            sr->totalCost()+","+
            sr->cash()+","+
            sr->bank()+","+
            sr->reference()+","+
            sr->momento()+","+
            sr->address()+'\n';
    out<<storeData;
    m_file.close();
    m_addHeader =0;
}

const QList<MySevaReceipt *> &SevaReceiptCsvProcessor::sevaReceiptList() const
{
    return m_sevaReceiptList;
}

void SevaReceiptCsvProcessor::setSevaReceiptList(const QList<MySevaReceipt *> &newSevaReceiptList)
{
    m_sevaReceiptList = newSevaReceiptList;
}
