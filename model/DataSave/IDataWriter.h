#ifndef IDATAWRITER_H
#define IDATAWRITER_H

#include <QObject>
#include <QDebug>

class IDataWriter : public QObject
{
    Q_OBJECT
public:
    explicit IDataWriter(QObject *parent = nullptr){Q_UNUSED(parent)}
    virtual bool saveData(QObject *obj) = 0;

signals:

};

#endif // IDATAWRITER_H
