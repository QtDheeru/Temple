#include "AllViewReports.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QGroupBox>
#include <QKeyEvent>

AllViewReports::AllViewReports(QWidget *parent) : QWidget(parent)
{
    this->m_view  = new QTableView;
    m_sourceModel = new QStandardItemModel(0, 9, parent);
    m_proxyModel = new QSortFilterProxyModel;
    m_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_view->setAlternatingRowColors(true);
    this->insertHeader();
    init() ;
}

void AllViewReports::init() {
    sortCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive sorting"));
    filterCaseSensitivityCheckBox = new QCheckBox(tr("Case sensitive filter"));
    m_csvExportButton = new QPushButton;
    m_csvExportButton->setText("Export Data");

    filterPatternLineEdit = new QLineEdit;
    filterPatternLabel = new QLabel(tr("&Filter String:"));
    filterPatternLabel->setBuddy(filterPatternLineEdit);

    filterSyntaxComboBox = new QComboBox;
    filterSyntaxComboBox->addItem(tr("Regular expression"), QRegExp::RegExp);
    filterSyntaxComboBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
    filterSyntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
    filterSyntaxLabel = new QLabel(tr("Filter &syntax:"));
    filterSyntaxLabel->setBuddy(filterSyntaxComboBox);

    filterColumnComboBox = new QComboBox;
    filterColumnComboBox->addItem(tr("ReceiptNo"));
    filterColumnComboBox->addItem(tr("Devotee Name"));
    filterColumnComboBox->addItem(tr("Mobile"));
    filterColumnLabel = new QLabel(tr("Filter &By:"));
    filterColumnLabel->setBuddy(filterColumnComboBox);

    connect(m_csvExportButton, &QPushButton::clicked,
            this, &AllViewReports::exportCsvButtonClicked);
    connect(filterPatternLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(filterRegExpChanged()));
    connect(filterSyntaxComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterRegExpChanged()));
    connect(filterColumnComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(filterColumnChanged()));
    connect(filterCaseSensitivityCheckBox, SIGNAL(toggled(bool)),
            this, SLOT(filterRegExpChanged()));
    connect(sortCaseSensitivityCheckBox, SIGNAL(toggled(bool)),
            this, SLOT(sortChanged()));

    proxyGroupBox = new QGroupBox(tr("All Receipts View "));

    QVBoxLayout *proxyLayout = new QVBoxLayout;
    QHBoxLayout *h_searchBox = new QHBoxLayout;
    h_searchBox->addStretch(20);
    h_searchBox->addWidget(m_csvExportButton);
    h_searchBox->addWidget(filterPatternLabel, 1);
    h_searchBox->addWidget(filterPatternLineEdit, 8);
    h_searchBox->addWidget(filterColumnLabel, 1);
    h_searchBox->addWidget(filterColumnComboBox, 8);
    proxyLayout->addLayout(h_searchBox, 2);
    proxyLayout->addWidget(m_view, 10);
    proxyGroupBox->setLayout(proxyLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(proxyGroupBox);

    setLayout(mainLayout);

    setWindowTitle(tr("All Receipts View"));
    resize(500, 450);

    m_view->sortByColumn(1, Qt::AscendingOrder);
    filterColumnComboBox->setCurrentIndex(1);

    filterPatternLineEdit->setText("");
    filterCaseSensitivityCheckBox->setChecked(true);
    sortCaseSensitivityCheckBox->setChecked(true);

    this->setSourceModel(m_sourceModel);
    this->m_view->setModel(m_proxyModel);
}

void AllViewReports::filterRegExpChanged()
{
    QRegExp::PatternSyntax syntax =
            QRegExp::PatternSyntax(filterSyntaxComboBox->itemData(
                                       filterSyntaxComboBox->currentIndex()).toInt());
    Qt::CaseSensitivity caseSensitivity =
            filterCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseInsensitive;

    QRegExp regExp(filterPatternLineEdit->text(), caseSensitivity, syntax);
    m_proxyModel->setFilterRegExp(regExp);
}

void AllViewReports::filterColumnChanged()
{
    m_proxyModel->setFilterKeyColumn(filterColumnComboBox->currentIndex());
}

void AllViewReports::sortChanged()
{
    m_proxyModel->setSortCaseSensitivity(
                sortCaseSensitivityCheckBox->isChecked() ? Qt::CaseSensitive
                                                         : Qt::CaseInsensitive);
}

void AllViewReports::setSourceModel(QAbstractItemModel *model)
{
    m_proxyModel->setSourceModel(model);
}

void AllViewReports::insertDummy() {
    for (int i=1000;i<1010;i++){
        QString data(QString::number(i));
        SevaBookingElement *el = new SevaBookingElement;
        DevotePersnalDetails *p = new DevotePersnalDetails;
        p->setDevoteeName(data);
        p->setMobileNumber(data);
        el->setPerson(p);
        el->setSevaname(data);
        el->setSno(data);
        this->insertSevaRow(el);
    }
}

void AllViewReports::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        this->close();
    }else {
        return QWidget::keyPressEvent(event);
    }
}

void AllViewReports::insertHeader(){
    m_sourceModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Sno"));
    m_sourceModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    m_sourceModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Mobile"));
    m_sourceModel->setHeaderData(3, Qt::Horizontal, QObject::tr("SevaName"));
    m_sourceModel->setHeaderData(4, Qt::Horizontal, QObject::tr("SevaDate"));
    m_sourceModel->setHeaderData(5, Qt::Horizontal, QObject::tr("ReceiptDate"));
    m_sourceModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Total"));
    m_sourceModel->setHeaderData(7, Qt::Horizontal, QObject::tr("Cash"));
    m_sourceModel->setHeaderData(8, Qt::Horizontal, QObject::tr("Bank"));
#ifndef RAM_MANDIRA
//    m_sourceModel->setHeaderData(9, Qt::Horizontal, QObject::tr("Reference"));
//    m_sourceModel->setHeaderData(10, Qt::Horizontal, QObject::tr("Momento"));
//    m_sourceModel->setHeaderData(11, Qt::Horizontal, QObject::tr("address"));
#endif
}

void AllViewReports::clearModel()
{
    qDebug() << Q_FUNC_INFO << " clear data called"<< Qt::endl;
    m_sourceModel->removeRows( 0, m_sourceModel->rowCount());
}

void AllViewReports::insertSevaRow(SevaBookingElement *elem)
{
    qDebug() << Q_FUNC_INFO << " Adding Devotee =" <<elem->person()->devoteeName();
    m_sourceModel->insertRow(0);
    m_sourceModel->setData(m_sourceModel->index(0, 0), elem->sno());
    m_sourceModel->setData(m_sourceModel->index(0, 1), elem->person()->devoteeName());
    m_sourceModel->setData(m_sourceModel->index(0, 2), elem->person()->mobileNumber());
    m_sourceModel->setData(m_sourceModel->index(0, 3), elem->sevaname());
    m_sourceModel->setData(m_sourceModel->index(0, 4), elem->sevaDate());
    m_sourceModel->setData(m_sourceModel->index(0, 5), elem->receiptDate());
    m_sourceModel->setData(m_sourceModel->index(0, 6), elem->totalCost());
    m_sourceModel->setData(m_sourceModel->index(0, 7), elem->cash());
    m_sourceModel->setData(m_sourceModel->index(0, 8), elem->bank());
#ifndef RAM_MANDIRA
    m_sourceModel->setData(m_sourceModel->index(0, 9), elem->reference());
    m_sourceModel->setData(m_sourceModel->index(0, 10), elem->momento());
    m_sourceModel->setData(m_sourceModel->index(0, 11), elem->address());
#endif
    qDebug() << Q_FUNC_INFO << " Size of Model " << m_sourceModel->rowCount();
}
