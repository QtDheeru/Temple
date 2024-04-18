#include "DevoteeDetailsSearchModel.h"

DevoteeDetailsSearchModel::DevoteeDetailsSearchModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_search2EnumMap["Mobile Number"] = DevoteeDetailsTableModel::MOBILE_NUMBER_ROLE;
    m_search2EnumMap["Serial No"]     = DevoteeDetailsTableModel::SNO_ROLE;
    m_search2EnumMap["Person ID"]     = DevoteeDetailsTableModel::PERSON_ID_ROLE;
    m_search2EnumMap["Person DbID"]   = DevoteeDetailsTableModel::PERSON_DBID_ROLE;
    m_search2EnumMap["Devotee Name"]  = DevoteeDetailsTableModel::DEVOTEE_NAME_ROLE;
    m_search2EnumMap["Gothra"]        = DevoteeDetailsTableModel::GOTHRA_ROLE;
    m_search2EnumMap["Nakshatra"]     = DevoteeDetailsTableModel::NAKSHATRA_ROLE ;
}

void DevoteeDetailsSearchModel::updateTableModel(QString txtTyped, QString comboBoxText)
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>>>>>>>>>"<< " Search Text " << txtTyped << " ComboBox =" << comboBoxText << Qt::endl;
    m_txtTyped = txtTyped;
    m_comboBoxText = comboBoxText;
    invalidateFilter();
}

int DevoteeDetailsSearchModel::getRowOfDataFromTableViewModel(int source_row)
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>getRowOfDataFromTableViewModel>>>>1>>>>"<<source_row<<Qt::endl;
    QModelIndex sourceIndex = mapToSource(this->index(source_row,0));
    qDebug()<<Q_FUNC_INFO<<">>>>>>>getRowOfDataFromTableViewModel>>>>1>>>>"<<sourceIndex.row()<<Qt::endl;
    return sourceIndex.row();
}

bool DevoteeDetailsSearchModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(m_txtTyped == ""){
       return true;
    }
    const QModelIndex sourceIndex = sourceModel()->index(source_row, 0, source_parent);

    DevoteeDetailsTableModel::DEVOTEE_ENUMS role = m_search2EnumMap.value(m_comboBoxText);
    const QString filterElement = sourceIndex.data(role).toString();
    return(filterElement.toLower().startsWith(m_txtTyped.toLower()));

    return true;
}
