#include "SevaBookingTableModel.h"
int SevaBookingTableModel::x= 0;
int SevaBookingTableModel::y= 0;
int SevaBookingTableModel::z= 0;
SevaBookingTableModel::SevaBookingTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    found=0;
}

SevaBookingTableModel::~SevaBookingTableModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int SevaBookingTableModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO << "Row count of SevaBooking =" << m_bookedSeva.size() << " :: x=" << x<< Qt::endl;
    Q_UNUSED(parent);
    x++;
    return m_bookedSeva.size();
}

int SevaBookingTableModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO << "bookedSeva size : " << m_bookedSeva.size() << " :: y value = " << y << Qt::endl;
    Q_UNUSED(parent);
    y++;
    return 14;
}

QVariant SevaBookingTableModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO << z << "row :" << index.row() << " :: column : " << index.column() << " :: role"   << role << Qt::endl;

    //    if (!index.isValid())
    //        return QVariant();

    int sevaRow = index.row();
    SevaBookingElement *tempSeva = m_bookedSeva.at(sevaRow);
    if(tempSeva == nullptr){
        qWarning() << Q_FUNC_INFO << "Error in fetching tempseva data for row : " << sevaRow << Qt::endl;
        return QVariant();
    }else
        qDebug() << Q_FUNC_INFO << "tempSeva is not null" << Qt::endl;

    tempSeva->print();
    qDebug() << Q_FUNC_INFO << " sno : " << tempSeva->sno() << Qt::endl;
    switch(role){
    case SNO_ROLE: return sevaRow;break;
    case RCPTNUM_ROLE: return tempSeva->sno();break;
    case PERSON_ID_ROLE: return tempSeva->person_id();break;
    case PERSON_DBID_ROLE: return tempSeva->person()->personDbId();break;
    case DEVOTEE_NAME_ROLE: return tempSeva->person()->devoteeName();break;
    case MOBILE_NUMBER_ROLE: return tempSeva->person()->mobileNumber();break;
    case GOTHRA_ROLE: return tempSeva->person()->gothra();break;
    case NAKSHATRA_ROLE: return tempSeva->person()->nakshatra();break;
    case SEVA_TYPE_ROLE: return tempSeva->sevatype();break;
    case SEVA_NAME_ROLE: return tempSeva->sevaname();break;
    case QUANTITY_ROLE: return tempSeva->quantity();break;
    case RECEIPT_DATE_ROLE: return tempSeva->receiptDate();break;
    case SEVA_DATE_ROLE: return tempSeva->sevaDate();break;
    case TOTAL_COST_ROLE: return tempSeva->totalCost();break;
    case CASH_ROLE: return tempSeva->cash();break;
    case BANK_ROLE: return tempSeva->bank();break;
    case BANK_NAME: return tempSeva->bankName();break;
    case REFERENCE_ROLE: return tempSeva->reference();break;
    case STATUS_ROLE: return tempSeva->status();break;
    case ADDRESS_ROLE: return tempSeva->address();break;
    case MOMENTO_ROLE: return tempSeva->momento();break;
    case BOOKED_BY_ROLE: return tempSeva->bookedBy();break;
    }

    qDebug()<<Q_FUNC_INFO<< " end" <<Qt::endl;
    return QVariant();
}

QHash<int, QByteArray> SevaBookingTableModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles.insert(SNO_ROLE,"serialNo");
    roles.insert(RCPTNUM_ROLE,"RecieptNumber");
    roles.insert(PERSON_ID_ROLE,"PersonID");
    roles.insert(PERSON_DBID_ROLE,"PersonDbID");
    roles.insert(DEVOTEE_NAME_ROLE,"DevoteeName");
    roles.insert(MOBILE_NUMBER_ROLE,"MobileNumber");
    roles.insert(GOTHRA_ROLE,"Gothra");
    roles.insert(NAKSHATRA_ROLE,"Nakshatra");
    roles.insert(SEVA_TYPE_ROLE,"SevaType");
    roles.insert(SEVA_NAME_ROLE,"SevaName");
    roles.insert(QUANTITY_ROLE,"Quantity");
    roles.insert(RECEIPT_DATE_ROLE,"ReceiptDate");
    roles.insert(SEVA_DATE_ROLE,"SevaDate");
    roles.insert(TOTAL_COST_ROLE,"TotalCost");
    roles.insert(CASH_ROLE,"Cash");
    roles.insert(BANK_ROLE,"PaymentMode");
    roles.insert(BANK_NAME,"BankName");
    roles.insert(REFERENCE_ROLE,"Reference");
    roles.insert(STATUS_ROLE,"Status");
    roles.insert(ADDRESS_ROLE,"Address");
    roles.insert(MOMENTO_ROLE,"Momento");
    roles.insert(BOOKED_BY_ROLE,"BookedBy");
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return roles;
}

void SevaBookingTableModel::addBookingDetails(SevaBookingElement *elem)
{
    qDebug()<<Q_FUNC_INFO<< elem << " :: Size = "  << m_bookedSeva.size() <<Qt::endl;
    beginInsertRows(QModelIndex(),m_bookedSeva.size(),m_bookedSeva.size());
    m_bookedSeva.append(elem);
    endInsertRows();

    //        printBookingList();
}

SevaBookingElement* SevaBookingTableModel::getRowOfData(int row)
{
    return m_bookedSeva.at(row);
}

void SevaBookingTableModel::printBookingList()
{
    for(int i=0;i<m_bookedSeva.size();i++)
    {
        qDebug()<<"sno"<<m_bookedSeva[i]->sno()<<Qt::endl;
        qDebug()<<"person_id"<<m_bookedSeva[i]->person_id()<<Qt::endl;
        qDebug()<<"sevatype"<<m_bookedSeva[i]->sevatype()<<Qt::endl;
        qDebug()<<"sevaname"<<m_bookedSeva[i]->sevaname()<<Qt::endl;
        qDebug()<<"quantity"<<m_bookedSeva[i]->quantity()<<Qt::endl;
        qDebug()<<"personDbId"<<m_bookedSeva[i]->person()->personDbId()<<Qt::endl;
        qDebug()<<"devoteeName"<<m_bookedSeva[i]->person()->devoteeName()<<Qt::endl;
        qDebug()<<"mobileNumber"<<m_bookedSeva[i]->person()->mobileNumber()<<Qt::endl;
        qDebug()<<"gothra"<<m_bookedSeva[i]->person()->gothra()<<Qt::endl;
        qDebug()<<"nakshatra"<<m_bookedSeva[i]->person()->nakshatra()<<Qt::endl;
        qDebug()<<"receiptDate"<<m_bookedSeva[i]->receiptDate()<<Qt::endl;
        qDebug()<<"sevaDate"<<m_bookedSeva[i]->sevaDate()<<Qt::endl;
        qDebug()<<"totalCost"<<m_bookedSeva[i]->totalCost()<<Qt::endl;
        qDebug()<<"cash"<<m_bookedSeva[i]->cash()<<Qt::endl;
        qDebug()<<"bank"<<m_bookedSeva[i]->bank()<<Qt::endl;
        qDebug()<<"reference"<<m_bookedSeva[i]->reference()<<Qt::endl;
        qDebug()<<"Seva Status"<<m_bookedSeva[i]->status()<<Qt::endl;
        qDebug()<<"address"<<m_bookedSeva[i]->address()<<Qt::endl;
        qDebug()<<"momento"<<m_bookedSeva[i]->momento()<<Qt::endl;
        qDebug()<<"bookedBy"<<m_bookedSeva[i]->bookedBy()<<Qt::endl;
    }
}
void SevaBookingTableModel::reset(QString receiptNo)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row = -1;
    SevaBookingElement *sevaReceipt = nullptr;
    for(int i=0;i<m_bookedSeva.size();i++)
    {
        if (receiptNo.contains(m_bookedSeva[i]->sno())){
            row = i;
            sevaReceipt = m_bookedSeva[i];
            sevaReceipt->setStatus(m_status);
        }
    }
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QModelIndex topLeft = createIndex(row,0);
    QModelIndex topRight = createIndex(row,20);
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    emit dataChanged(topLeft, topRight);
    emit statusCancelledSuccess();
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

void SevaBookingTableModel::checkStatus(QString receiptNo){
    bool check = false;
    if(receiptNo == nullptr){
        emit notAbleToCancel();
        return;
    }
    for(int var = 0;var < m_bookedSeva.size();var++) {
        if(m_bookedSeva[var]->sno() == receiptNo){
            if((m_bookedSeva[var]->status() == "")){
                emit notAbleToCancel();
                return;
            }
            qDebug() << Q_FUNC_INFO << "booked seva status =" << m_bookedSeva[var]->status() << Qt::endl;
            if(m_bookedSeva[var]->status() == m_status){
                check= true;
                emit alreadyCancelled();
            }
        }
    }
    if(!check){
        emit loadCancelPage();
    }
}

void SevaBookingTableModel::referseshTheModel(QString rownum)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    int count=0;
    for(int var=0;var<m_bookedSeva.size();var++) {
        if(m_bookedSeva[var]->sno()== rownum){
            count = var;
        }
    }
    beginRemoveRows(QModelIndex(),count,count);
    endRemoveRows();
}

void SevaBookingTableModel::clearData()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    for(int i=0; i<m_bookedSeva.size();i++)
    {
        delete m_bookedSeva.at(i);
        qDebug() << Q_FUNC_INFO << "Booked seva list is empty ? =" << m_bookedSeva.empty() << Qt::endl;
    }
    m_bookedSeva.clear();
}
