#ifndef REPORTFILTERELEMENTS_H
#define REPORTFILTERELEMENTS_H

#include <QObject>

class ReportFilterElements : public QObject
{
    Q_OBJECT
public:

    enum REPORT_TYPE{DETAIL_REPORT=1,SUMMARY_REPORT=2};
    enum REPORT_DATE_SELECTION_TYPE{SINGLE_DATE_REPORT=0,DATE_RANGE_REPORT=1,MONTH_REPORT=2};

    Q_ENUM(REPORT_TYPE)
    Q_ENUM(REPORT_DATE_SELECTION_TYPE)

    explicit ReportFilterElements(QObject *parent = nullptr);

    Q_PROPERTY(bool bSevawise READ bSevawise WRITE setBSevawise NOTIFY bSevawiseChanged)
    Q_PROPERTY(bool bDatewise READ bDatewise WRITE setBDatewise NOTIFY bDatewiseChanged)
    Q_PROPERTY(int iSevaType READ iSevaType WRITE setISevaType NOTIFY iSevaTypeChanged)
    Q_PROPERTY(QString sevaType READ sevaType WRITE setSevaType NOTIFY sevaTypeChanged)

    Q_PROPERTY(int sevaNameIndex READ sevaNameIndex WRITE setSevaNameIndex NOTIFY sevaNameIndexChanged)
    Q_PROPERTY(QString sSevaName READ sSevaName WRITE setSSevaName NOTIFY sSevaNameChanged)
    Q_PROPERTY(QString sSingleDate READ sSingleDate WRITE setSSingleDate NOTIFY sSingleDateChanged)
    Q_PROPERTY(QString sStartDate READ sStartDate WRITE setSStartDate NOTIFY sStartDateChanged)
    Q_PROPERTY(QString sEndDate READ sEndDate WRITE setSEndDate NOTIFY sEndDateChanged)
    Q_PROPERTY(QString sMonth READ sMonth WRITE setSMonth NOTIFY sMonthChanged)
    Q_PROPERTY(QString sYear READ sYear WRITE setSYear NOTIFY sYearChanged)
    Q_PROPERTY(int iSelectedType READ iSelectedType WRITE setISelectedType NOTIFY iSelectedTypeChanged)
    Q_PROPERTY(int reportType READ reportType WRITE setReportType NOTIFY reportTypeChanged FINAL)

    bool bSevawise() const;
    void setBSevawise(bool newBSevawise);

    bool bDatewise() const;
    void setBDatewise(bool newBDatewise);

    int iSevaType() const;
    void setISevaType(int newISevaType);

    const QString &sSevaName() const;
    void setSSevaName(const QString &newSSevaName);

    const QString &sSingleDate() const;
    void setSSingleDate(const QString &newSSingleDate);

    const QString &sStartDate() const;
    void setSStartDate(const QString &newSStartDate);

    const QString &sEndDate() const;
    void setSEndDate(const QString &newSEndDate);

    const QString &sMonth() const;
    void setSMonth(const QString &newSMonth);

    const QString &sYear() const;
    void setSYear(const QString &newSYear);

    int iSelectedType() const;
    void setISelectedType(int newISelectedType);

    int reportType() const;
    void setReportType(int newReportType);

    Q_INVOKABLE void print();

    QString sevaType() const;
    void setSevaType(const QString &newSevaType);

    int sevaNameIndex() const;
    void setSevaNameIndex(int newSevaNameIndex);

signals:
    void bSevawiseChanged();
    void bDatewiseChanged();
    void iSevaTypeChanged();
    void sSevaNameChanged();
    void sSingleDateChanged();
    void sStartDateChanged();
    void sEndDateChanged();
    void sMonthChanged();
    void sYearChanged();
    void iSelectedTypeChanged();

    void reportTypeChanged();
    void sevaTypeChanged();
    void sevaNameIndexChanged();

private:
    bool m_bSevawise;
    bool m_bDatewise;
    int m_iSevaType;
    QString m_sevaType;

    int     m_sevaNameIndex;
    QString m_sSevaName;
    QString m_sSingleDate;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sMonth;
    QString m_sYear;
    // Single Date, Date Range or Month
    int m_iSelectedType;
    // Report is details or Summary
    int m_reportType;
};

#endif // REPORTFILTERELEMENTS_H
