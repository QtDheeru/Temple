#include "SevaCancelModel.h"

SevaCancelModel::SevaCancelModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<"Inside SevaCancelModel Class"<<Qt::endl;
}

bool SevaCancelModel::sevaChecked() const
{
    return m_sevaChecked;
}

void SevaCancelModel::setSevaChecked(bool newSevaChecked)
{
    m_sevaChecked = newSevaChecked;
}

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

}

QHash<int, QByteArray> SevaCancelModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO;
    QHash<int, QByteArray> roles;
    roles[0] = "SevaName";
    roles[1] = "SevaAmount";

    qDebug()<<Q_FUNC_INFO<<" 2 " <<roles;
    return roles;

}

void SevaCancelModel::setData(QList<SevaBookingElement*> l_recptList)
{
   m_recptList =l_recptList;
}
