#include "SevaDetailsTableViewModel.h"

SevaDetailsTableView::SevaDetailsTableView(QObject *parent) : QAbstractTableModel(parent)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    list = new QStringList;
    *list <<"SNO"<< "PERSONID"<< "SEVATYPE"<< "SEVANAME"<< "SEVA_DATE"<< "RECEIPT_DATE"<< "SEVACOST"
          << "SEVATOTALPRICE"<< "CASH"<< "BANK"<< "BANKDETAILS"<< "REFERENCE"<< "ADDRESS"<< "MOMENTO"<< "NOTE";
    m_deatailsList.append(list);
}

SevaDetailsTableView::~SevaDetailsTableView()
{
    for(int i=0;i<m_deatailsList.size();i++)
        delete m_deatailsList.at(i);
}

int SevaDetailsTableView::rowCount(const QModelIndex &index) const
{
    // qDebug() << Q_FUNC_INFO << " Rows =" << m_deatailsList.size() << Qt::endl;
    Q_UNUSED(index);
    return m_sevaBookedList.size();
}

int SevaDetailsTableView::columnCount(const QModelIndex &index) const
{
    //    qDebug() << Q_FUNC_INFO << " Column =" << m_deatailsList.at(0)->size() << Qt::endl;
    Q_UNUSED(index);
    return 2;
}

QVariant SevaDetailsTableView::data(const QModelIndex &index, int role) const
{
    qDebug() <<  Q_FUNC_INFO << Qt::endl; //"Row =" <<  index.row() <<  " Col=" << index.column() <<  " Data = " <<  m_data.at(index.row()).at(index.column()) << Qt::endl;
    if( m_deatailsList.size() == 0){
        qDebug() <<  Q_FUNC_INFO <<  "detailslist size is 0" << Qt::endl;
        return QVariant();
    }

    SevaBookingElement *elem = this->m_sevaBookedList.at(index.row());
    switch(role){
    case DevoteName :
        if (index.column()==0)
            return elem->person()->devoteeName();
        if (index.column()==1)
            return elem->person()->mobileNumber();
        break;
    case HeaderRole: {
        if (index.row()==0)
            return true;
        else
            return false;
    }
    }
    return QVariant();
}

QHash<int, QByteArray> SevaDetailsTableView::roleNames() const
{
    qDebug() << Q_FUNC_INFO << Qt::endl;

    QHash<int, QByteArray> roles;
    roles[DevoteName] = "DevoteeName";
    //roles[MobileNo] = "MobileNo";
    return roles;
}

bool SevaDetailsTableView::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(row);
    Q_UNUSED(count);
    Q_UNUSED(parent);
    qDebug() << Q_FUNC_INFO << Qt::endl;
    beginInsertRows(QModelIndex(),0,0);
    m_deatailsList.append(list);
    endInsertRows();
    return true;
}

bool SevaDetailsTableView::insertSevaRow(SevaBookingElement *elm)
{
    qDebug() << Q_FUNC_INFO << " ***** Inserting the element ***** Current Size= " << this->m_sevaBookedList.size() << Qt::endl;
    beginInsertRows(QModelIndex(),0,0);
    this->m_sevaBookedList.append(elm);
    endInsertRows();
    elm->print();
    return true;
}

void SevaDetailsTableView::getData(QList<QString>sno, QList<QString>personid, QList<QString>sevatype, QList<QString>sevaname, QList<QString>quantity, QList<QString>date, QList<QString>month, QList<QString>year, QList<QString>seva_date, QList<QString>r_date, QList<QString>r_month, QList<QString>r_year, QList<QString>receipt_date, QList<QString>sevacost, QList<QString>additionalcost, QList<QString>sevatotalprice, QList<QString>note, QList<QString>cash, QList<QString>bank, QList<QString>bankdetails, QList<QString>reference, QList<QString>address, QList<QString>momento)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    for(int i=0;i<sno.size();i++){
        list = new QStringList;
        *list << sno.at(i) << personid.at(i) << sevatype.at(i) << sevaname.at(i) << seva_date.at(i)
              << receipt_date.at(i) << sevacost.at(i) << sevatotalprice.at(i) << cash.at(i) << bank.at(i) << bankdetails.at(i) << reference.at(i) << address.at(i) << momento.at(i) << note.at(i) ;
        insertRows(1,1,QModelIndex());
    }
}
