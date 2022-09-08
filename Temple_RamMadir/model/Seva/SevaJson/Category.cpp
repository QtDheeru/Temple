#include "Category.h"

Category::Category(QObject *parent)
    : QObject{parent}
{
 qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

Category::~Category()
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

const QString &Category::categoryName() const
{
    return m_categoryName;
}

void Category::setCategoryName(const QString &newCategoryName)
{
    m_categoryName = newCategoryName;
}

int Category::categoryId() const
{
    return m_categoryId;
}

void Category::setCategoryId(int newCategoryId)
{
    m_categoryId = newCategoryId;
}
