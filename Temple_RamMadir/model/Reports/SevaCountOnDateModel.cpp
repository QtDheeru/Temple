#include "SevaCountOnDateModel.h"

SevaCountOnDateModel::SevaCountOnDateModel(QObject *parent)
    : QAbstractListModel(parent)
{
    qDebug() <<Q_FUNC_INFO << Qt::endl;
}

QVariant SevaCountOnDateModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

int SevaCountOnDateModel::rowCount(const QModelIndex &parent) const
{ 
    qDebug() << Q_FUNC_INFO << "dates == >"<< m_countOfStrings.size() << Qt::endl;
    return m_count.size();
    //    if (parent.isValid())
    //        return 0;
}

QVariant SevaCountOnDateModel::data(const QModelIndex &index, int role) const
{
    int r = index.row();
    int c = index.column();
    qDebug() << Q_FUNC_INFO << "  "<< r<<"  "<< c<<endl;
    SevaCountOnDateData *da = m_count.at(r);
    switch (role) {
    case 1:{
        qDebug()<<"in data"<< da->Date();
        return da->Date().toString("yyyy-MM-dd");
    }
    case 2:    {
        qDebug()<<"in data"<< da->Count()<<endl;
        return da->Count();
    }
    }

    //MyUser u =
    return "Vae";
}

//const QList<int> &SevaCountOnDateModel::count() const
//{
//     qDebug() << Q_FUNC_INFO << "dates == >"<< m_count << Qt::endl;
//    return m_count.size();
//}

//void SevaCountOnDateModel::setCount(const QList<int> &newCount)
//{
//    m_count = newCount;
//}

QHash<int, QByteArray> SevaCountOnDateModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO <<endl;
    QHash<int, QByteArray> roles;
    roles[1] ="sevadate";
    roles[2] = "countOfDate";
    return roles;
}


void SevaCountOnDateModel::getSevaDatesFromDB()
{
    m_SsevaDates = DBInterface::getInstance()->qrySevaDates();
    for(int j= 0;j<m_SsevaDates.size();j++)
    {
        m_DsevaDates.push_back( QDate::fromString(m_SsevaDates.at(j),"yyyy-MM-dd"));
        qDebug() << Q_FUNC_INFO << "dates == >"<< m_DsevaDates << Qt::endl;
    }

    // qDebug() << Q_FUNC_INFO << "dates == >"<< m_sevaDates.size() << Qt::endl;


    for(int i=0;i<m_DsevaDates.count();i++)
    {
        m_countOfStrings[m_DsevaDates[i]]++;
    }

    for (auto itr = m_countOfStrings.begin(); itr != m_countOfStrings.end(); ++itr) {
        qDebug()   << "Vagesshaaa"<<endl;
        qDebug()   <<  itr.key() << endl<< '\t' << itr.value()<<Qt::endl;
        // count += itr.value();
        SevaCountOnDateData *sevaData = new SevaCountOnDateData;
        sevaData->setDate(itr.key());
        sevaData->setCount(itr.value());
        m_count.push_back(sevaData);
    }
}




