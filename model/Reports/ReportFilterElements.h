#ifndef REPORTFILTERELEMENTS_H
#define REPORTFILTERELEMENTS_H

#include <QObject>

class ReportFilterElements : public QObject
{
    Q_OBJECT
public:
    explicit ReportFilterElements(QObject *parent = nullptr);

    Q_PROPERTY(bool bSevawise READ bSevawise WRITE setBSevawise NOTIFY bSevawiseChanged)
    Q_PROPERTY(bool bDatewise READ bDatewise WRITE setBDatewise NOTIFY bDatewiseChanged)
    Q_PROPERTY(int iSevaType READ iSevaType WRITE setISevaType NOTIFY iSevaTypeChanged)
    Q_PROPERTY(QString sSevaName READ sSevaName WRITE setSSevaName NOTIFY sSevaNameChanged)
    Q_PROPERTY(QString sSingleDate READ sSingleDate WRITE setSSingleDate NOTIFY sSingleDateChanged)
    Q_PROPERTY(QString sStartDate READ sStartDate WRITE setSStartDate NOTIFY sStartDateChanged)
    Q_PROPERTY(QString sEndDate READ sEndDate WRITE setSEndDate NOTIFY sEndDateChanged)
    Q_PROPERTY(QString sMonth READ sMonth WRITE setSMonth NOTIFY sMonthChanged)
    Q_PROPERTY(QString sYear READ sYear WRITE setSYear NOTIFY sYearChanged)
    Q_PROPERTY(int iSelectedType READ iSelectedType WRITE setISelectedType NOTIFY iSelectedTypeChanged)

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

private:
    bool m_bSevawise;
    bool m_bDatewise;
    int m_iSevaType;
    QString m_sSevaName;
    QString m_sSingleDate;
    QString m_sStartDate;
    QString m_sEndDate;
    QString m_sMonth;
    QString m_sYear;
    int m_iSelectedType;


};

#endif // REPORTFILTERELEMENTS_H
