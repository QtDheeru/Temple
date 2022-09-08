#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include<QDebug>
class Category : public QObject
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = nullptr);
    ~Category();

    const QString &categoryName() const;
    void setCategoryName(const QString &newCategoryName);

    int categoryId() const;
    void setCategoryId(int newCategoryId);

signals:

    private:

    QString m_categoryName;
    int m_categoryId;

};

#endif // CATEGORY_H
