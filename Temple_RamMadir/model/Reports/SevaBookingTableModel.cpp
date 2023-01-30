#include "SevaBookingTableModel.h"
int SevaBookingTableModel::x= 0;
int SevaBookingTableModel::y= 0;
int SevaBookingTableModel::z= 0;
SevaBookingTableModel::SevaBookingTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

SevaBookingTableModel::~SevaBookingTableModel()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int SevaBookingTableModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO << m_bookedSeva.size() <<x<< Qt::endl;
    Q_UNUSED(parent);
    x++;
    return m_bookedSeva.size();
}

int SevaBookingTableModel::columnCount(const QModelIndex &parent) const
{
    qDebug()<<Q_FUNC_INFO << m_bookedSeva.size() <<y<< Qt::endl;
    Q_UNUSED(parent);
    y++;
    return 19;
}

QVariant SevaBookingTableModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<z<<"row column role"<<index.row()<<index.column()<<role<<Qt::endl;
    z++;
    if (!index.isValid())
        return QVariant();

    int sevaRow = index.row();
    SevaBookingElement *tempSeva = m_bookedSeva.at(sevaRow);
    switch(role){
    case SNO_ROLE: return tempSeva->sno();break;
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
    case REFERENCE_ROLE: return tempSeva->reference();break;
    case ADDRESS_ROLE: return tempSeva->address();break;
    case MOMENTO_ROLE: return tempSeva->momento();break;
    case BOOKED_BY_ROLE: return tempSeva->bookedBy();break;
    }
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return QVariant();
}

QHash<int, QByteArray> SevaBookingTableModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles.insert(SNO_ROLE,"serialNo");
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
    roles.insert(BANK_ROLE,"Bank");
    roles.insert(REFERENCE_ROLE,"Reference");
    roles.insert(ADDRESS_ROLE,"Address");
    roles.insert(MOMENTO_ROLE,"Momento");
    roles.insert(BOOKED_BY_ROLE,"BookedBy");
    //    qDebug() << Q_FUNC_INFO << SNO_ROLE <<endl;
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return roles;
}

void SevaBookingTableModel::addBookingDetails(SevaBookingElement *elem)
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    beginInsertRows(QModelIndex(),m_bookedSeva.size(),m_bookedSeva.size());
    m_bookedSeva.append(elem);

    endInsertRows();
    qDebug()<<Q_FUNC_INFO<< "############# s" << m_bookedSeva.size()<< Qt::endl;





    //


    //    int i=0, commaCount = 0;
    //     string fileLine, word;

    //    //    ifstream nameFile("MOCK_DATA.TXT");
    //    ifstream nameFile("SEVA_MOCK_DATA.TXT");
    //    if(!nameFile.is_open())
    //    {
    //        qDebug()<<"Unable to open file!\n"<<Qt::endl;
    //        exit(1);
    //    }
    //    while(!nameFile.eof())
    //    {
    //        getline(nameFile,fileLine);
    //        stringstream sLine(fileLine);
    //        if(!fileLine.empty()){
    //            m_bookedSeva.append(new SevaBookingElement());
    //            while(getline(sLine,word,',')){
    //                if(commaCount == 0)
    //                    m_bookedSeva[i]->setSno(QString::fromStdString(word));
    //                else if(commaCount == 1)
    //                    m_bookedSeva[i]->setPerson_id(QString::fromStdString(word));
    //                else if(commaCount == 2)
    //                    m_bookedSeva[i]->person()->setPersonDbId(QString::fromStdString(word));
    //                else if(commaCount == 3)
    //                    m_bookedSeva[i]->person()->setDevoteeName(QString::fromStdString(word));
    //                else if(commaCount == 4)
    //                     m_bookedSeva[i]->person()->setMobileNumber(QString::fromStdString(word));
    //                else if(commaCount == 5)
    //                     m_bookedSeva[i]->person()->setGothra(QString::fromStdString(word));
    //                else if(commaCount == 6)
    //                     m_bookedSeva[i]->person()->setNakshatra(QString::fromStdString(word));
    //                else if(commaCount == 7)
    //                     m_bookedSeva[i]->setSevatype(QString::fromStdString(word));
    //                else if(commaCount == 8)
    //                    m_bookedSeva[i]->setSevaname(QString::fromStdString(word));
    //                else if(commaCount == 9)
    //                    m_bookedSeva[i]->setQuantity(QString::fromStdString(word));
    //                else if(commaCount == 10)
    //                    m_bookedSeva[i]->setReceiptDate(QString::fromStdString(word));
    //                else if(commaCount == 11)
    //                    m_bookedSeva[i]->setSevaDate(QString::fromStdString(word));
    //                else if(commaCount == 12)
    //                    m_bookedSeva[i]->setTotalCost(QString::fromStdString(word));
    //                else if(commaCount == 13)
    //                    m_bookedSeva[i]->setCash(QString::fromStdString(word));
    //                else if(commaCount == 14)
    //                    m_bookedSeva[i]->setBank(QString::fromStdString(word));
    //                else if(commaCount == 15)
    //                    m_bookedSeva[i]->setReference(QString::fromStdString(word));
    //                else if(commaCount == 16)
    //                    m_bookedSeva[i]->setAddress(QString::fromStdString(word));
    //                else if(commaCount == 17)
    //                    m_bookedSeva[i]->setMomento(QString::fromStdString(word));
    //                else if(commaCount == 18)
    //                    m_bookedSeva[i]->setBookedBy(QString::fromStdString(word));
    //                commaCount++;
    //            }
    //            commaCount = 0;
    //            i++;
    //        }
    //    }
    //    printBookingList();
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
        qDebug()<<"address"<<m_bookedSeva[i]->address()<<Qt::endl;
        qDebug()<<"momento"<<m_bookedSeva[i]->momento()<<Qt::endl;
        qDebug()<<"bookedBy"<<m_bookedSeva[i]->bookedBy()<<Qt::endl;
    }
}
