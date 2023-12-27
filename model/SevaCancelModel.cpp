#include "SevaCancelModel.h"

SevaCancelModel::SevaCancelModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<"Inside SevaCancelModel Class"<<Qt::endl;
}

//bool SevaCancelModel::sevaChecked() const
//{
//    return m_sevaChecked;
//}

//void SevaCancelModel::setSevaChecked(bool newSevaChecked)
//{
//    m_sevaChecked = newSevaChecked;
//}

int SevaCancelModel::rowCount(const QModelIndex &parent) const
{
    m_recptList.count();
}

QVariant SevaCancelModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<" indexValInTBM "<<index.row()<<role;

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
}

QHash<int, QByteArray> SevaCancelModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO;
    QHash<int, QByteArray> roles;
    roles[0] = "SevaName";
    roles[1] = "SevaAmount";
    roles[2] = "SevaChecked";

    qDebug()<<Q_FUNC_INFO<<" 2 " <<roles;
    return roles;

}

int SevaCancelModel::setData(QList<SevaBookingElement*> l_recptList)
{
    m_recptList =l_recptList;
    qDebug()<<"emitted setData";
}

QString SevaCancelModel::getTotalAmount()
{
    int l_value=0;
    for(int var=0;var<m_recptList.size();var++){
        m_totalAmount=m_recptList.at(var)->sevacost();
        l_value+=m_totalAmount.toInt();
    }
    QString l_amount=QString::number(l_value);
    return l_amount;
}
