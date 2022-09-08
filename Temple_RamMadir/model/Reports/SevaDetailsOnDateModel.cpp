#include "SevaDetailsOnDateModel.h"

SevaDetailsOnDateModel::SevaDetailsOnDateModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant SevaDetailsOnDateModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int SevaDetailsOnDateModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    return m_sevaDetailsOnDate.size();

    // FIXME: Implement me!
}

QVariant SevaDetailsOnDateModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    SevaBookingElement *_da = m_sevaDetailsOnDate.at(r);
    switch (role) {
    case 1:{return _da->sno();    }
    case 2:{return _da->person()->devoteeName();}
    case 3:{return _da->person()->mobileNumber();}
    case 4:{return _da->sevaname();}
    case 5:{return _da->sevaDate();}
    case 6:{return _da->receiptDate();}
    case 7:{return _da->totalCost();}
    case 8:{return _da->cash();}
    case 9:{return _da->bank();}
    case 10:{return _da->reference();}
    case 11:{return _da->momento();}
    case 12:{return _da->address();}

    }

}

QHash<int, QByteArray> SevaDetailsOnDateModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO <<endl;
    QHash<int, QByteArray> roles;
    roles[1] ="Sno";
    roles[2] = "name";
    roles[3] = "mobile";
    roles[4] = "sevaName";
    roles[5] = "sevaDate";
    roles[6] = "receiptDate";
    roles[7] = "total";
    roles[8] = "cash";
    roles[9] = "bank";
    roles[10] = "refernce";
    roles[11] = "momento";
    roles[12] = "address";
    return roles;
}

bool SevaDetailsOnDateModel::insertSevaRow(SevaBookingElement *elm)
{
    qDebug() << Q_FUNC_INFO << " ***** Inserting the element ***** Current Size= " << this->m_sevaDetailsOnDate.size() << Qt::endl;
    this->m_sevaDetailsOnDate.append(elm);
    return true;
}



void SevaDetailsOnDateModel::onDateSelected(QString date)
{
    qDebug()<<Q_FUNC_INFO<<date<<Qt::endl;
    DBInterface::getInstance()->qrySevabookingBySevaDate(date);

}

void SevaDetailsOnDateModel::onDateRangeSelected(QString start, QString end)
{
    DBInterface::getInstance()->qrySevabookingByDateRange(start,end);
}
