#include "SevaBookingConformationDataModel.h"
#include "JSONWriter.h"
#include "model/Print/print_file.h"
#include "./model/DBInterface.h"


SevaBookingConformationDataModel::SevaBookingConformationDataModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    m_dataWriter = QSharedPointer<JsonWriter>(new JsonWriter);
    this->m_sevaReceipt = new MySevaReceipt;
}
int SevaBookingConformationDataModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index)
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_sevabookinglist.size();
}

QVariant SevaBookingConformationDataModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    SevaName *sevabooking=m_sevabookinglist.at(row);
    switch(role)
    {
    case Sevaname:return sevabooking->sevaName();
        break;
    case SevaCharge:return sevabooking->sevaCost();
        break;
    case Count:return sevabooking->count();
        break;
    case Extracharge:return sevabooking->additionalCost();
        break;
    case Cash:return sevabooking->sevaCost();
        break;
    case Sevadate:return sevabooking->sevaStartDate();
        break;
    case Sevatime:return sevabooking->sevaStartTime();

    }
    return 0;
}

QHash<int, QByteArray> SevaBookingConformationDataModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int,QByteArray> roles;
    roles[Sevaname]="sevaName";
    roles[SevaCharge]="sevaCharges";
    roles[Count]="count";
    roles[Extracharge]="extra";
    roles[Cash]="cash";
    roles[Sevadate]="sevaDate";
    roles[Sevatime]="sevaTime";
    return roles;

}

void SevaBookingConformationDataModel::init()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}
void SevaBookingConformationDataModel::addData(int receiptNumber, QString date,QString sevatime, QString mobile, QString name, QString Nakshatra, QString gothra,int bank, QString banklist, QString note)
{
    qDebug()<<Q_FUNC_INFO<<"addData function called"<<Qt::endl;
    this->setReceiptNumber(receiptNumber);
    this->setDate(date);
    this->setMobilenumber(mobile);
    this->setName(name);
    this->setNakshtra(Nakshatra);
    this->setGothra(gothra);
    this->setBank(bank);
    this->setBanklist(banklist);
    this->setNote(note);
    this->setSevatime(sevatime);
}

void SevaBookingConformationDataModel::print()
{
    m_sevaReceipt->print();
    foreach(SevaName *seva,m_sevabookinglist){
        qDebug() << Q_FUNC_INFO << " **** Print Seva Details...." << Qt::endl;
        seva->print();
    }

    qDebug() << Q_FUNC_INFO << " Seva List Size =" << m_sevabookinglist.size() <<Qt::endl;
    QList<Print_Detail*> printList;

    double totalAmount= 0;

    for(int i=0;i<m_sevabookinglist.size();i++){
        print_details *p = new Print_Detail;
        p->NAME.append(m_sevaReceipt->devoteeName());
        p->RECPT_NO = m_sevaReceipt->receiptNo();
        p->MOB_NO.append(m_sevaReceipt->mobilenumber());
        p->DATE.append(m_sevaReceipt->receiptDate());
        p->GOTHRA.append(m_sevaReceipt->gothra());
        p->NAKSHATRA.append(m_sevaReceipt->nakshtra());
        p->SEVA_TIME.append(m_sevaReceipt->sevatime());
        SevaName* seva = m_sevabookinglist.at(i);

        double totalSevaCost = (seva->sevaCost()*seva->count());
        p->SEVA_DESCR.append(seva->sevaName());
        p->QTY.append(QString::number(seva->count()));
        p->AMT.append(QString::number(totalSevaCost));
        p->CASH.append(QString::number(seva->sevaCost()));
        p->RATE.append(QString::number(seva->sevaCost()));
        p->ADDITIONAL.append(QString::number(seva->additionalCost()));

        p->SEVA_DATE.append(seva->sevaStartDate());
        totalAmount += totalSevaCost;
        totalAmount += seva->additionalCost();
        p->TOTAL_AMT.append(QString::number(totalAmount,'f',2));
        p->TOTAL_IN_WORDS.append(print_file::NumberToWord(totalAmount));
        p->NOTE.append(m_sevaReceipt->note());
        printList.append(p);
        qDebug() << Q_FUNC_INFO << " Total Seva Cost =" << p->TOTAL_AMT << Qt::endl;
        qDebug() << Q_FUNC_INFO << " Total Seva Cost =" << print_file::NumberToWord(totalAmount) << Qt::endl;
    }
    print_file file;
    file.printing_file(&printList);
}

void SevaBookingConformationDataModel::printReceipt()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->print();
}

void SevaBookingConformationDataModel::addNewData(QString sevaname, int sevacharges, int count, int extra, int cash, QString sevadate, QString sevatime)
{
    qDebug()<<Q_FUNC_INFO<<"addNewData function called"<<Qt::endl;
    sb=new SevaName;
    sb->setSevaName(sevaname);
    sb->setSevaCost(sevacharges);
    sb->setCount(count);
    sb->setAdditionalCost(extra);
    sb->setSevaStartDate(sevadate);
    sb->setSevaStartTime(sevatime);
    m_sevabookinglist.append(sb);
    qDebug()<<Q_FUNC_INFO<<"new sevabooking data is added to the list"<<m_sevabookinglist<<Qt::endl;
    print();
}

void SevaBookingConformationDataModel::saveReceiptDetails(QString receiptNumber, QString name, QString mobile, QString nak, QString gotra)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->setReceiptNo(receiptNumber);
    this->setName(name);
    this->setMobilenumber(mobile);
    this->setNakshtra(nak);
    this->setGothra(gotra);
    this->print();
}

bool SevaBookingConformationDataModel::saveReceipt(MySevaReceipt *rec)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_sevaReceipt->clear();
    this->m_sevaReceipt->setReceiptNo(rec->receiptNo());
    this->m_sevaReceipt->setDevoteeName(rec->devoteeName());
    this->m_sevaReceipt->setGothra(rec->gothra());
    this->m_sevaReceipt->setNakshtra(rec->nakshtra());
    this->m_sevaReceipt->setMobilenumber(rec->mobilenumber());

    this->m_sevaReceipt->setReceiptDate(rec->receiptDate());
    this->m_sevaReceipt->setSevatime(rec->sevatime());
    this->m_sevaReceipt->setMomento(rec->momento());
    this->m_sevaReceipt->setBookedBy(rec->bookedBy());

    this->m_sevaReceipt->setReference(rec->reference());
    this->m_sevaReceipt->setAddress(rec->address());

    this->m_sevaReceipt->setBank(rec->bank());
    this->m_sevaReceipt->setCash(rec->cash());
    this->m_sevaReceipt->setCheckOrTranscationId(rec->checkOrTranscationId());
    this->m_sevaReceipt->setBookingStatus(rec->bookingStatus());
    this->m_sevaReceipt->setNote(rec->note());
    this->m_sevaReceipt->setPaymentMode(rec->paymentMode());
    if (!DBInterface::getInstance()->saveData(this)) {
        qWarning() << Q_FUNC_INFO << " Danger - Saving the receipt failed...RNo=" << m_sevaReceipt->receiptNo() << Qt::endl;
        return false;
    }
    this->m_dataWriter->saveData(this);
    return true;
}

bool SevaBookingConformationDataModel::addSeva(SevaName *s)
{
    qDebug() << Q_FUNC_INFO << " Add Seva is called" <<Qt::endl;
    s->print();
    qDebug() << Q_FUNC_INFO << " 11111111" <<Qt::endl;
    bool sevaExist = false;
    qDebug() << Q_FUNC_INFO << " 22222222 seva booking list size = " << m_sevabookinglist.size() <<Qt::endl;
    for(int i=0;i<this->m_sevabookinglist.size();i++){
        qDebug() << Q_FUNC_INFO << " 33333333" <<Qt::endl;
        SevaName *seva = m_sevabookinglist.at(i);
        qDebug() << Q_FUNC_INFO << "44444444" <<Qt::endl;
        if (s->sevaId() == seva->sevaId()){
            qDebug() << Q_FUNC_INFO << "55555555" <<Qt::endl;
            sevaExist = true;
            break;
        }
        qDebug() << Q_FUNC_INFO << " 6666666666" <<Qt::endl;
    }
    if (sevaExist){
        qDebug() << Q_FUNC_INFO << " 7777777777" <<Qt::endl;
        return false;
    }
    else {
        qDebug() << Q_FUNC_INFO << " 888888888888" <<Qt::endl;
        this->m_sevabookinglist.append(s);
        qDebug() << Q_FUNC_INFO << " 99999999999" <<Qt::endl;
        return true;
    }
    qDebug() << Q_FUNC_INFO << " end 0000000000" <<Qt::endl;
    this->display();
}
void SevaBookingConformationDataModel::display(){
    qDebug() << Q_FUNC_INFO <<Qt::endl;
    for(int var=0;var<m_sevabookinglist.size();var++){
        qDebug()<<m_sevabookinglist[var]->sevaName()<<Qt::endl;
        qDebug()<<m_sevabookinglist[var]->sevaCost()<<Qt::endl;
    }
}
bool SevaBookingConformationDataModel::deleteSeva(SevaName *s)
{
    for(int i=0;i<this->m_sevabookinglist.size();i++){
        SevaName *seva = m_sevabookinglist.at(i);
        if (s->sevaId() == seva->sevaId()){
            this->m_sevabookinglist.removeAt(i);
            break;
        }
    }
    return true;
}

bool SevaBookingConformationDataModel::removeSeva(int index,QString sevaname)
{
    qDebug() << Q_FUNC_INFO<<index<<" "<<sevaname << Qt::endl;
    beginRemoveRows(QModelIndex(),index,index);
    int cost = m_sevabookinglist.at(index)->sevaCost();
    m_sevabookinglist.removeAt(index);
    emit modelChanged(cost);
    endRemoveRows();
    return true;
}

bool SevaBookingConformationDataModel::reset()
{
    qDebug() << Q_FUNC_INFO << " 7777777777" <<m_sevabookinglist.size()<<Qt::endl;
    this->m_sevabookinglist.clear();
    qDebug() << Q_FUNC_INFO << " 7777777777" <<m_sevabookinglist.size()<<Qt::endl;
    beginResetModel();
    endResetModel();
    return true;
}

bool SevaBookingConformationDataModel::clearSevaList()
{
    this->m_sevabookinglist.clear();
    return true;
}

const QString &SevaBookingConformationDataModel::date() const
{
    return m_date;
}

void SevaBookingConformationDataModel::setDate(const QString &newDate)
{
    m_date = newDate;
}

QString SevaBookingConformationDataModel::mobilenumber() const
{
    return m_mobilenumber;
}

void SevaBookingConformationDataModel::setMobilenumber(QString newMobilenumber)
{
    m_mobilenumber = newMobilenumber;
}

const QString &SevaBookingConformationDataModel::name() const
{
    return m_name;
}

void SevaBookingConformationDataModel::setName(const QString &newName)
{
    m_name = newName;
}

const QString &SevaBookingConformationDataModel::nakshtra() const
{
    return m_nakshtra;
}

void SevaBookingConformationDataModel::setNakshtra(const QString &newNakshtra)
{
    m_nakshtra = newNakshtra;
}

const QString &SevaBookingConformationDataModel::gothra() const
{
    return m_gothra;
}

void SevaBookingConformationDataModel::setGothra(const QString &newGothra)
{
    m_gothra = newGothra;
}
int SevaBookingConformationDataModel::bank() const
{
    return m_bank;
}

void SevaBookingConformationDataModel::setBank(int newBank)
{
    m_bank = newBank;
}

const QString &SevaBookingConformationDataModel::banklist() const
{
    return m_banklist;
}

void SevaBookingConformationDataModel::setBanklist(const QString &newBanklist)
{
    m_banklist = newBanklist;

}

const QString &SevaBookingConformationDataModel::note() const
{
    return m_note;
}

void SevaBookingConformationDataModel::setNote(const QString &newNote)
{
    m_note = newNote;
}

int SevaBookingConformationDataModel::receiptNumber() const
{
    return m_receiptNumber;
}

void SevaBookingConformationDataModel::setReceiptNumber(int newReceiptNumber)
{
    m_receiptNumber = newReceiptNumber;
}

QString SevaBookingConformationDataModel::receiptNo() const
{
    return m_receiptNo;
}

void SevaBookingConformationDataModel::setReceiptNo(const QString &receiptNo)
{
    m_receiptNo = receiptNo;
}

QString SevaBookingConformationDataModel::reference() const
{
    return m_reference;
}

void SevaBookingConformationDataModel::setReference(const QString &reference)
{
    m_reference = reference;
}

QString SevaBookingConformationDataModel::address() const
{
    return m_address;
}

void SevaBookingConformationDataModel::setAddress(const QString &address)
{
    m_address = address;
}

QString SevaBookingConformationDataModel::momento() const
{
    return m_momento;
}

void SevaBookingConformationDataModel::setMomento(const QString &momento)
{
    m_momento = momento;
}

MySevaReceipt *SevaBookingConformationDataModel::sevaReceipt() const
{
    return m_sevaReceipt;
}

QList<SevaName *> SevaBookingConformationDataModel::sevabookinglist() const
{
    return m_sevabookinglist;
}

const QString &SevaBookingConformationDataModel::sevatime() const
{
    return m_sevatime;
}

void SevaBookingConformationDataModel::setSevatime(const QString &newSevatime)
{
    if (m_sevatime == newSevatime)
        return;
    m_sevatime = newSevatime;
    emit sevatimeChanged();
}
