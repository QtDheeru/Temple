#ifndef SEVARECEIPTCSVPROCESSOR_H
#define SEVARECEIPTCSVPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include "MySevaReceipt.h"
#include <QElapsedTimer>
#include "SevaBookingElement.h"
#include <QDate>
#include <QDir>

class SevaReceiptCsvProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SevaReceiptCsvProcessor(QObject *parent = nullptr);
    ~SevaReceiptCsvProcessor();

    //    void writeToCsvFormate(MySevaReceipt* sr);
    const QList<MySevaReceipt *> &sevaReceiptList() const;
    void setSevaReceiptList(const QList<MySevaReceipt *> &newSevaReceiptList);
    void writeToCsvFormate(SevaBookingElement* sr);
signals:
private:
    QList<MySevaReceipt*> m_sevaReceiptList;
    static int m_addHeader;
    QFile m_file;

};

#endif // SEVARECEIPTCSVPROCESSOR_H
