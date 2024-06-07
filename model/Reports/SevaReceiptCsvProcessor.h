#ifndef SEVARECEIPTCSVPROCESSOR_H
#define SEVARECEIPTCSVPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include "MySevaReceipt.h"
#include <QElapsedTimer>
#include "BookingReportElement.h"
#include "SevaBookingElement.h"
#include <QDate>
#include <QDir>
#include <QFileDialog>

class SevaReceiptCsvProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SevaReceiptCsvProcessor(QObject *parent = nullptr);
    ~SevaReceiptCsvProcessor();

    //    void writeToCsvFormate(MySevaReceipt* sr);
    const QList<MySevaReceipt *> &sevaReceiptList() const;
    void setSevaReceiptList(const QList<MySevaReceipt *> &newSevaReceiptList);
    void writeToCsvFormate(SevaBookingElement* sr);                             //Suman N

signals:
    void successMessage(QString exportmsg);

public slots:
    void recieveBookingReportList( QList<BookingReportElement*>);               //Suman N

private:
    QList<MySevaReceipt*> m_sevaReceiptList;
    static int m_addHeader;
    QFile m_file;
    QString m_fileName;
    const QString msg= "Export completed";
};

#endif // SEVARECEIPTCSVPROCESSOR_H
