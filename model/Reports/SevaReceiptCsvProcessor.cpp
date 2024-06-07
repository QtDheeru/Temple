#include "SevaReceiptCsvProcessor.h"
#include <QFileDialog>
SevaReceiptCsvProcessor::SevaReceiptCsvProcessor(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    //    int id=0;
    //    QString todayDate = QDate::currentDate().toString("ddd_dd_MMM_yyyy"+QString::number(id++));
    //    QString path = "SevaBookingReportExcelSheets/";
    //    QDir::setCurrent(path);
    //    m_file.setFileName("Bookings"+todayDate+".csv");
    //    if(!m_file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    //    {
    //        qWarning()<<Q_FUNC_INFO<<"----sevabookings file not open"<<m_file.error() << Qt::endl;
    //        return;
    //    }
    //    m_file.close();
    QString todayDate ="SevaBookings_"+ QDate::currentDate().toString("ddd_dd_MMM_yyyy");
    m_fileName = QFileDialog::getSaveFileName(nullptr, "Save File", "" , "Text Files (*.csv)");  //Suman N added
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
    if(!m_fileName.isEmpty()){
        QFile file(m_fileName);
        if (file.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            QTextStream out(&file);
            QString storeData;
            if(m_addHeader)
            {
                QString header;
                header =  QString("Sno") + "," + "Name"+","+"Nakshatra"+"," + "Gothra" + "," + "Mobile" + "," + "SevaName" + "," + "SevaDate" + "," + "SevaCount" + '\n';
                out<<header.toUpper();
            }
            storeData = sr->sno()+","+
                        sr->person()->devoteeName()+","+
                        sr->person()->nakshatra()+","+
                        sr->person()->gothra()+","+
                        sr->person()->mobileNumber()+","+
                        sr->sevaname()+","+
                        sr->sevaDate()+","+
                        sr->quantity()+'\n';
            out<<storeData;
            qDebug() << "File saved: " << m_fileName;
            file.close();
        }
        else
        {
            qCritical() << "Failed to open file for saving.";
        }
    }
    m_addHeader =0;

}

void SevaReceiptCsvProcessor::recieveBookingReportList(QList<BookingReportElement *> bookingReportList)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int id=1;
    if(!m_fileName.isEmpty()){
        QFile file(m_fileName);
        if (file.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            QTextStream out(&file);
            QString storeData;
            if(m_addHeader)
            {
                QString header;
                header =  QString("Sno") + "," + "Name" + "," + "Nakshatra" + "," + "Gothra" + "," + "Mobile" + "," + "SevaName" + "," + "SevaDate" + "," + "SevaCount" + '\n';
                out<<header.toUpper();
            }
            for(auto it=bookingReportList.begin();it != bookingReportList.end();it++){
                storeData = QString::number(id++)+","+
                            (*it)->name()+","+
                            (*it)->nakshatra()+","+
                            (*it)->gothra()+","+
                            (*it)->mobileNumber()+","+
                            (*it)->sevaName()+","+
                            (*it)->sevaDate()+","+
                            QString::number((*it)->sevaCount())+'\n' ;
                out<<storeData;
                emit successMessage(msg);
            }
            qDebug() << "File saved: " << m_fileName;
            file.close();
        }
        else
        {
            qCritical() << "Failed to open file for saving.";
        }
    }
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
