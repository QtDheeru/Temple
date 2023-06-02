#ifndef VOUCHERREPORTCSVPROCESSOR_H
#define VOUCHERREPORTCSVPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <VoucherElement.h>
class VoucherReportCSVProcessor : public QObject
{
    Q_OBJECT
public:
    explicit VoucherReportCSVProcessor(QObject *parent = nullptr);
    ~VoucherReportCSVProcessor();
signals:
public slots:
    void writeToCsvFormatVoucherReport(QList<VoucherElement*>);
private:
    static int m_addHeader;
    QString fileName;
};

#endif // VOUCHERREPORTCSVPROCESSOR_H
