#include "SevaBookingSearchModel.h"
int SevaBookingSearchModel::i = 0;
SevaBookingSearchModel::SevaBookingSearchModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void SevaBookingSearchModel::updateTableModel(QString txtTyped, QString comboBoxText)
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>>>>>>>>>"<<Qt::endl;
    m_txtTyped = txtTyped;
    m_comboBoxText = comboBoxText;
    invalidateFilter();
}

int SevaBookingSearchModel::getRowOfDataFromTableViewModel(int source_row)
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>getRowOfDataFromTableViewModel>>>>1>>>>"<<source_row<<Qt::endl;
    QModelIndex sourceIndex = mapToSource(this->index(source_row,0));
    qDebug()<<Q_FUNC_INFO<<">>>>>>>getRowOfDataFromTableViewModel>>>>1>>>>"<<sourceIndex.row()<<Qt::endl;
    return sourceIndex.row();
}



bool SevaBookingSearchModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    qDebug()<<Q_FUNC_INFO<<">>>proxtRow>>>1>i>>>>>>>> "<<source_row<<i<<Qt::endl;
    i++;
    const QModelIndex sourceIndex = sourceModel()->index(source_row, 0, source_parent);
    int i = sourceIndex.row();
    qDebug()<<Q_FUNC_INFO<<">>>>>>sourceIndex.row()>>>>>>>>> "<<i<<Qt::endl;
    if(m_txtTyped == ""){
        return true;
    }
    if(m_comboBoxText == "Serial No"){
        qDebug()<<Q_FUNC_INFO<<"hereee"<<Qt::endl;
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::SNO_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Person ID"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::PERSON_ID_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Person DbID"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::PERSON_DBID_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Devotee Name"){
        qDebug()<<Q_FUNC_INFO<<"hereee Devotee Name"<<Qt::endl;
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::DEVOTEE_NAME_ROLE).toString();
        if(filterElement.toLower().startsWith(m_txtTyped.toLower()))
        {
            QModelIndex proxyIndex  =  mapFromSource(sourceIndex);
            int proxyRow = proxyIndex.row();
            qDebug()<<Q_FUNC_INFO<<"hereee Devotee Name inside if"<<proxyRow<<Qt::endl;
            return(filterElement.toLower().startsWith(m_txtTyped.toLower()));

        }
        else
        {
            return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
        }
    }
    else if(m_comboBoxText == "Mobile Number"){
        qDebug()<<Q_FUNC_INFO<<"hereee"<<Qt::endl;
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::MOBILE_NUMBER_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Gothra"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::GOTHRA_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Nakshatra"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::NAKSHATRA_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Seva Type"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::SEVA_TYPE_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Seva Name"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::SEVA_NAME_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Quantity"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::QUANTITY_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Receipt Date"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::RECEIPT_DATE_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Seva Date"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::SEVA_DATE_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Total Cost"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::TOTAL_COST_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Cash"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::CASH_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Bank"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::BANK_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Reference"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::REFERENCE_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Status"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::STATUS_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Address"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::ADDRESS_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Momento"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::MOMENTO_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    else if(m_comboBoxText == "Booked By"){
        const QString filterElement = sourceIndex.data(SevaBookingTableModel::BOOKED_BY_ROLE).toString();
        return(filterElement.toLower().startsWith(m_txtTyped.toLower()));
    }
    return true;
}
