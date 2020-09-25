#ifndef SAVER_H
#define SAVER_H

#include <QFile>
#include "properties.h"
#include "propertiesparser.h"

class Saver{
public:
    Saver(QFile &file);
private:
    QFile *file;
    cppproperties::Properties p;

public:
    std::string get(std::string);
    void put(std::string, std::string);
    void load();
    void save();
};

#endif // SAVER_H
