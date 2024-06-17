#ifndef BOOKINGREPORTMONTHRANGEELEMENT_H
#define BOOKINGREPORTMONTHRANGEELEMENT_H

#include <QObject>
#include<QDebug>

#include "ReportEnums.h"

class BookingReportMonthRangeElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(int totalSevaCount READ totalSevaCount WRITE setTotalSevaCount NOTIFY totalSevaCountChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged FINAL)
    Q_PROPERTY(QString year READ year WRITE setYear NOTIFY yearChanged FINAL)
    Q_PROPERTY(QString sevaTypeName READ sevaTypeName WRITE setSevaTypeName NOTIFY sevaTypeNameChanged FINAL)
    Q_PROPERTY(QString sevaName READ sevaName WRITE setSevaName NOTIFY sevaNameChanged FINAL)
    Q_PROPERTY(int sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged FINAL)
    Q_PROPERTY(ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource READ reportGenerationSource WRITE setReportGenerationSource NOTIFY reportGenerationSourceChanged FINAL)

public:
    explicit BookingReportMonthRangeElement(QObject *parent = nullptr);
    ~BookingReportMonthRangeElement();

    int totalSevaCount() const;
    void setTotalSevaCount(int newTotalSevaCount);

    const QString &month() const;
    void setMonth(const QString &newMonth);

    int slNo() const;
    void setSlNo(int newSlNo);

    QString date() const;
    void setDate(const QString &newDate);

    QString year() const;
    void setYear(const QString &newYear);

    QString sevaTypeName() const;
    void setSevaTypeName(const QString &newSevaTypeName);

    QString sevaName() const;
    void setSevaName(const QString &newSevaName);

    int sevaType() const;
    void setSevaType(int newSevaType);

    ReportEnums::REPORT_GENERATION_SOURCE reportGenerationSource() const;
    void setReportGenerationSource(const ReportEnums::REPORT_GENERATION_SOURCE &newReportGenerationSource);

signals:
    void monthChanged();
    void totalSevaCountChanged();

    void dateChanged();

    void yearChanged();

    void sevaTypeNameChanged();

    void sevaNameChanged();

    void sevaTypeChanged();

    void reportGenerationSourceChanged();

private:
    int m_slNo;
    QString m_month;
    int m_totalSevaCount;
    QString m_date;
    QString m_year;
    QString m_sevaTypeName;
    QString m_sevaName;
    int m_sevaType;
    ReportEnums::REPORT_GENERATION_SOURCE m_reportGenerationSource;
};

#endif // BOOKINGREPORTMONTHRANGEELEMENT_H
