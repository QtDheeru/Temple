#ifndef BOOKINGREPORTDATERANGEELEMENT_H
#define BOOKINGREPORTDATERANGEELEMENT_H

#include <QObject>
#include<QDebug>

#include "ReportEnums.h"

class BookingReportDateRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)
    Q_PROPERTY(QString sevaTypeName READ sevaTypeName WRITE setSevaTypeName NOTIFY sevaTypeNameChanged FINAL)

public:
    explicit BookingReportDateRangeElement(QObject *parent = nullptr);
    ~BookingReportDateRangeElement();


    int slNo() const;
    void setSlNo(int newSlNo);

    const QString &date() const;
    void setDate(const QString &newDate);

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

    QString sevaTypeName() const;
    void setSevaTypeName(const QString &newSevaTypeName);

    ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource() const;
    void setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource);

    int sevaType() const;
    void setSevaType(int newSevaType);

    QString sevaName() const;
    void setSevaName(const QString &newSevaName);

signals:
    void dateChanged();
    void totalSevaCountChanged();
    void totalAmountChanged();
    void sevaTypeNameChanged();

    void reportGenerationSourceChanged();

    void sevaTypeChanged();

    void sevaNameChanged();

private:
    int m_slNo;
    QString m_date;
    int m_totalSevaCount;
    QString m_sevaTypeName;
    int m_sevaType;
    QString m_sevaName;
    ReportEnums::REPORT_GENERATION_SOURCE m_reportGenerationSource;
    Q_PROPERTY(ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource READ reportGenerationSource WRITE setReportGenerationSource NOTIFY reportGenerationSourceChanged FINAL)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged FINAL)
    Q_PROPERTY(QString sevaName READ sevaName WRITE setSevaName NOTIFY sevaNameChanged FINAL)
};

#endif // BOOKINGREPORTDATERANGEELEMENT_H
