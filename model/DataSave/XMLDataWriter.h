#ifndef XMLDATAWRITER_H
#define XMLDATAWRITER_H

#include "IDataWriter.h"

class XMLDataWriter : public IDataWriter
{
public:
    XMLDataWriter();

    // IDataWriter interface
public:
    bool saveData(QObject *obj) override;
};

#endif // XMLDATAWRITER_H
