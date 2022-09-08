#ifndef ALLVIEWREPORTS_H
#define ALLVIEWREPORTS_H

#include <QWidget>
#include <QTableView>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include "SevaBookingElement.h"

class AllViewReports : public QWidget
{
    Q_OBJECT
public:
    explicit AllViewReports(QWidget *parent = nullptr);
    void init();

    void setSourceModel(QAbstractItemModel *model);
    void insertSevaRow(SevaBookingElement *elem);

    void insertDummy();
    void insertHeader();
    void clearModel();

signals:
    void exportCsvButtonClicked();

protected :
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void filterRegExpChanged();
    void filterColumnChanged();
    void sortChanged();

private :
    QTableView *m_view;
    QSortFilterProxyModel *m_proxyModel;
    QStandardItemModel *m_sourceModel;

    QCheckBox *filterCaseSensitivityCheckBox;
    QCheckBox *sortCaseSensitivityCheckBox;
    QLabel *filterPatternLabel;
    QLabel *filterSyntaxLabel;
    QLabel *filterColumnLabel;
    QPushButton *m_csvExportButton;
    QLineEdit *filterPatternLineEdit;
    QComboBox *filterSyntaxComboBox;
    QComboBox *filterColumnComboBox;
    QGroupBox *sourceGroupBox;
    QGroupBox *proxyGroupBox;
};

#endif // ALLVIEWREPORTS_H
