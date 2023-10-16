#ifndef CSVDATAWRITER_H
#define CSVDATAWRITER_H
#include <QDebug>
#include "IDataWriter.h"
class CSVDataWriter : public IDataWriter
{
public:
    CSVDataWriter();

    // IDataWriter interface
public:
    bool saveData(QObject *obj) override;
};

#endif // CSVDATAWRITER_H
