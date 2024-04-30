#include "SevaCancelModel.h"

SevaCancelModel::SevaCancelModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<"Inside SevaCancelModel Class"<<Qt::endl;
}

int SevaCancelModel::rowCount(const QModelIndex &parent) const
{
    return m_recptList.count();
}

QVariant SevaCancelModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<< " indexValInTBM "<<index.row()<<role;
    if (m_recptList.size() == 0  ) return "";

    if(role == 0 )
    {
        return m_recptList.at(index.row())->sevaname();
    }
    if(role == 1)
    {
        return m_recptList.at(index.row())->sevacost();
    }
    if(role == 2)
    {
        return m_recptList.at(index.row())->sevaChecked();
    }
    if(role == 3)
    {
        return m_recptList.at(index.row())->quantity();
    }
    return "";
}

QHash<int, QByteArray> SevaCancelModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO;
    QHash<int, QByteArray> roles;
    roles[0] = "SevaName";
    roles[1] = "SevaAmount";
    roles[2] = "SevaChecked";
    roles[3] = "Quantity";

    qDebug()<<Q_FUNC_INFO<<" 2 " <<roles;
    return roles;
}

int SevaCancelModel::setData(QList<SevaBookingElement*> l_recptList)
{
    this->beginResetModel();
    m_recptList.clear();
    m_recptList = l_recptList;
    SevaBookingElement *ele = l_recptList.at(0);
    this->getTotalAmount();
    this->setSevaReceiptNumber(ele->receiptNum());
    this->endResetModel();
    return 0;
}

QString SevaCancelModel::getTotalAmount()
{
    int amount=0;
    for(int var = 0;var < m_recptList.size();var++){
        qDebug() << Q_FUNC_INFO << "sevacost = " << m_recptList.at(var)->sevacost().toInt() << Qt::endl;
        qDebug() << Q_FUNC_INFO << "quantity = " << m_recptList.at(var)->quantity().toInt() << Qt::endl;
        int value = (m_recptList.at(var)->sevacost().toInt()) * (m_recptList.at(var)->quantity().toInt());
        qDebug() << Q_FUNC_INFO << "value = " << value << Qt::endl;
        amount += value;
        qDebug() << Q_FUNC_INFO << "amount = " << amount << Qt::endl;
    }
    m_totalAmount = QString::number(amount);
    qDebug() << Q_FUNC_INFO << "Amount = " << amount << Qt::endl;
    emit totalAmountChanged();
    return m_totalAmount;
}

QString SevaCancelModel::sevaReceiptNumber() const
{
    return m_sevaReceiptNumber;
}

void SevaCancelModel::setSevaReceiptNumber(const QString &newSevaReceiptNumber)
{
    m_sevaReceiptNumber = newSevaReceiptNumber;
}

QList<SevaBookingElement *> SevaCancelModel::recptList() const
{
    return m_recptList;
}

void SevaCancelModel::setRecptList(const QList<SevaBookingElement *> &newRecptList)
{
    m_recptList = newRecptList;
}
