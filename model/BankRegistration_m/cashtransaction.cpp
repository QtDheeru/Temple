#include "cashtransaction.h"

CashTransaction::CashTransaction(QObject *parent)
    : QObject{parent}
{

}
QString CashTransaction::receiptNumber() const
{
    return m_receiptNumber;
}

void CashTransaction::setReceiptNumber(const QString &newReceiptNumber)
{
    if (m_receiptNumber == newReceiptNumber)
        return;
    m_receiptNumber = newReceiptNumber;
    emit receiptNumberChanged();
}

QString CashTransaction::cashInHand() const
{
    return m_cashInHand;
}

void CashTransaction::setCashInHand(const QString &newCashInHand)
{
    if (m_cashInHand == newCashInHand)
        return;
    m_cashInHand = newCashInHand;
    emit cashInHandChanged();
}

void CashTransaction::initial()
{
    connect(DBInterface::init,&DBInterface::signalToCashTransaction,this,&CashTransaction::onSignalToCashTransaction);
    connect(DBInterface::init,&DBInterface::signalToCashEntry,this,&CashTransaction::onSignalToCashEntry);

    DBInterface::getInstance()->lastDataToCashEntry();
    DBInterface::getInstance()->databaseToCashEntry();
}

void CashTransaction::onSignalToCashTransaction(QString a_recieptNumber,QString a_cashInHand,QString a_toBank,QString a_TransactionType)
{
    qDebug()<<"executed onSignalToCashTransaction";
    qDebug()<< "rn"<<a_recieptNumber<<"cash"<<a_cashInHand;
    int l_balance;
    if(a_TransactionType=="debit"){
        l_balance=a_cashInHand.toInt()+a_toBank.toInt();
        m_cashInHand = QString::number(l_balance);
        m_receiptNumber=a_recieptNumber;
    }
    else{
        l_balance=a_cashInHand.toInt()-a_toBank.toInt();
        m_cashInHand = QString::number(l_balance);
        m_receiptNumber=a_recieptNumber;
    }
    qDebug()<< "rn"<<m_receiptNumber<<"cash"<<m_cashInHand<<"type"<<a_TransactionType;
}

void CashTransaction::onSignalToCashEntry(QString a_recieptNumber, QString a_cash, QString a_cashType)
{
    qDebug()<<"rn==="<<a_recieptNumber<<"cash=="<<a_cash<<"cashtype"<<a_cashType;
    if(a_recieptNumber>m_receiptNumber)
    {
        int l_balance;
        l_balance=m_cashInHand.toInt()+a_cash.toInt();
        m_cashInHand = QString::number(l_balance);
        m_receiptNumber=a_recieptNumber;
    }
    emit receiptNumberChanged();
    emit cashInHandChanged();
}

void CashTransaction::dataFromQml(QString a_date, QString a_lastreci, QString a_cashinhand, QString a_tobank, QString a_transType, QString a_bank, QString a_person, QString a_notes)
{
    if(a_tobank!="") {
        qDebug()<<a_date<<a_lastreci<<a_cashinhand<<a_tobank<<a_transType<<a_bank<<a_person<<a_notes<<Qt::endl;
        int l_balance;
        if(a_tobank.toInt()<=a_cashinhand.toInt() || a_transType=="debit"){

            DBInterface::getInstance()->addCashTOdatabase(a_date,a_lastreci,a_cashinhand,a_tobank,a_transType,a_bank,a_person,"Completed",a_notes);
            if(a_transType=="debit"){
                l_balance=m_cashInHand.toInt()+a_tobank.toInt();
                m_cashInHand = QString::number(l_balance);
            }
            else{
                l_balance=m_cashInHand.toInt()-a_tobank.toInt();
                m_cashInHand = QString::number(l_balance);
            }
            emit cashInHandChanged();
            emit addedData();
        }
        else
        {
            emit lowBalance();
        }
    }
    else{
        emit toBankEmpty();
    }
}
QStringList CashTransaction::getBanksList() const
{
    return m_banksList;
}

void CashTransaction::setBanksList(const QStringList &newBanksList)
{
    if (m_banksList == newBanksList)
        return;
    m_banksList = newBanksList;
    emit banksListChanged();
}

