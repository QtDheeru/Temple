#include "DevoteeDetailsSearchModel.h"

DevoteeDetailsSearchModel::DevoteeDetailsSearchModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
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
    const QModelIndex sourceIndex = sourceModel()->index(source_row, 0, source_parent);
    int i = sourceIndex.row();
    qDebug()<<Q_FUNC_INFO<<">>>>>>sourceIndex.row()>>>>>>>>> "<<i<<Qt::endl;
    if(m_txtTyped == ""){
        return true;
    }
    if(m_comboBoxText == "Serial No"){
        qDebug()<<Q_FUNC_INFO<<"hereee"<<Qt::endl;
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::SNO_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Person ID"){
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::PERSON_ID_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Person DbID"){
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::PERSON_DBID_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Devotee Name"){
        qDebug()<<Q_FUNC_INFO<<"hereee Devotee Name"<<Qt::endl;
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::DEVOTEE_NAME_ROLE).toString();
        if(filterElement.toLower().startsWith(m_txtTyped.toLower()))
        {
            QModelIndex proxyIndex  =  mapFromSource(sourceIndex);
            int proxyRow = proxyIndex.row();
            qDebug()<<Q_FUNC_INFO<<"hereee Devotee Name inside if"<<proxyRow<<Qt::endl;
            return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
        } else {
            return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
        }
    }
    else if(m_comboBoxText == "Mobile Number"){
        qDebug()<<Q_FUNC_INFO<<"hereee"<<Qt::endl;
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::MOBILE_NUMBER_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Gothra"){
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::GOTHRA_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Nakshatra"){
        const QString filterElement = sourceIndex.data(DevoteeDetailsTableModel::NAKSHATRA_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    return true;
}
