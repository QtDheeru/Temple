#include "MomentoCategory.h"

MomentoCategory::MomentoCategory(QObject *parent)
    : QObject{parent}
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

MomentoCategory::~MomentoCategory()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &MomentoCategory::categoryName() const
{
    return m_categoryName;
}

void MomentoCategory::setCategoryName(const QString &newCategoryName)
{
    m_categoryName = newCategoryName;
}

int MomentoCategory::categoryId() const
{
    return m_categoryId;
}

void MomentoCategory::setCategoryId(int newCategoryId)
{
    m_categoryId = newCategoryId;
}
