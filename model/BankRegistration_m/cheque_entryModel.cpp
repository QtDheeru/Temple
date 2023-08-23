#include "cheque_entryModel.h"

Cheque_EntryModel::Cheque_EntryModel(QObject *parent)
    : QAbstractTableModel{parent}
{

    QList<QString> bankName = {"SBI","ICICI","HDFC","KOTAK","AXIS","SBI","ICICI","HDFC","KOTAK","AXIS","SBI","ICICI","HDFC","KOTAK","AXIS","KOTAK"};
    QString date,receiptNumber,amount;
    date = "1-1-2023";
    amount = "10000";

    //chequeEntry_DB = new ChequeEntryDB();
    //    dbInterface = DBInterface::getInstance();

    for(int i=0;i<16;i++)
    {
        Cheque_Entry_Data *data = new Cheque_Entry_Data();
        receiptNumber = "100"+QString::number(i+1);
        data->setReceiptDate(date);
        data->setChequeDate(date);
        data->setBank(bankName.at(i));
        data->setAmount(amount);
        data->setReceiptNumber(receiptNumber);

        m_checklist.append(data);
    }

}

int Cheque_EntryModel::rowCount(const QModelIndex &parent) const
{
    return m_checklist.count();
}

int Cheque_EntryModel::columnCount(const QModelIndex &parent) const
{
    return m_checklist.count();
}

QVariant Cheque_EntryModel::data(const QModelIndex &index, int role) const
{
    switch(role){
    case RECEIPT_DATE: return m_checklist.at(index.row())->receiptDate(); break;
    case CHECK_DATE: return m_checklist.at(index.row())->chequeDate(); break;
    case BANK: return m_checklist.at(index.row())->bank(); break;
    case RECEIPT_NUMBER: return m_checklist.at(index.row())->receiptNumber(); break;
    case AMOUNT: return m_checklist.at(index.row())->amount(); break;
    }

    return QVariant("Hello");
}

QHash<int, QByteArray> Cheque_EntryModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[RECEIPT_DATE] = "receiptDate";
    roles[CHECK_DATE] = "checkDate";
    roles[BANK] = "bank";
    roles[RECEIPT_NUMBER] = "receiptNumber";
    roles[AMOUNT] = "anount";

    return roles;

}

QList<Cheque_Entry_Data *> Cheque_EntryModel::checklist() const
{
    return m_checklist;
}

void Cheque_EntryModel::setChecklist(const QList<Cheque_Entry_Data *> &newChecklist)
{
    if (m_checklist == newChecklist)
        return;
    m_checklist = newChecklist;
    emit checklistChanged();
}

void Cheque_EntryModel::addtoListMain(QString bankname, QString receiptNumber, QString receiptDate, QString amount, QString chequeDate)
{
    Cheque_Entry_Data *data = new Cheque_Entry_Data;
    beginInsertRows(QModelIndex(),m_checklist.size(),m_checklist.size());

    data->setBank(bankname);
    data->setReceiptNumber(receiptNumber);
    data->setReceiptDate(receiptDate);
    data->setAmount(amount);
    data->setChequeDate(chequeDate);
    m_checklist.append(data);

    endInsertRows();
}

void Cheque_EntryModel::addToList(int index)
{
    qDebug() <<"Received element : "<< index;
    m_listOfNumToAddDB.append(index);
}

void Cheque_EntryModel::removeFromList(int index)
{
    qDebug() <<"Received element to delet : "<< index;
    for(int i=0;i<m_listOfNumToAddDB.count();i++)
    {
        if(m_listOfNumToAddDB.at(i) == index )
        {
            m_listOfNumToAddDB.removeAt(i);
        }
    }
}

void Cheque_EntryModel::submitToBank()
{
    qDebug()<<"The list elements are helllo :";
    int index;

    for(int i=0;i<m_listOfNumToAddDB.count();i++)
    {
        index = m_listOfNumToAddDB.at(i);
        qDebug()<< index;
        qDebug()<<m_checklist.at(index)->receiptDate()<<" "<<m_checklist.at(index)->chequeDate()<<" "<<m_checklist.at(index)->bank()<<" "<<m_checklist.at(index)->receiptNumber()<<" "<<m_checklist.at(index)->amount();
        DBInterface::getInstance()->addChequeToDataBase(m_checklist.at(index)->receiptDate(),m_checklist.at(index)->chequeDate(),m_checklist.at(index)->bank(),m_checklist.at(index)->receiptNumber(),m_checklist.at(index)->amount());
    }
    emit addedToDataBase();
    removeDbAddedElementsFromList();
    emptyList();

}

void Cheque_EntryModel::emptyList()
{
    qDebug()<<"Empty List: ";
    m_listOfNumToAddDB.clear();
}

void Cheque_EntryModel::removeDbAddedElementsFromList()
{
    qSort(m_listOfNumToAddDB.begin(), m_listOfNumToAddDB.end());

    qDebug()<< Q_FUNC_INFO <<Qt::endl;


    for(int j=0;j<m_listOfNumToAddDB.count();j++)
    {
        qDebug()<<"ELEMENTSFOR = "<<m_listOfNumToAddDB.at(j);
    }

    for (int i = m_listOfNumToAddDB.count() - 1; i >= 0; i--) {
        int rowIndex = m_listOfNumToAddDB.at(i);

        if (rowIndex >= 0 && rowIndex < m_checklist.count()) {
            beginRemoveRows(QModelIndex(), rowIndex, rowIndex);
            m_checklist.removeAt(rowIndex);
            endRemoveRows();
        }
    }

}

void Cheque_EntryModel::onClearChequeList()
{
    qDebug()<<"CAMEHERE";
    this->m_checklist.clear();
}

void Cheque_EntryModel::fetchFromDataBase()
{
    connect(DBInterface::getInstance(), &DBInterface::clearChequeList, this, &Cheque_EntryModel::onClearChequeList, Qt::UniqueConnection);
    connect(DBInterface::getInstance(), &DBInterface::sendDataToModel, this, &Cheque_EntryModel::addtoListMain, Qt::UniqueConnection);

    DBInterface::getInstance()->getChequeData();

}





