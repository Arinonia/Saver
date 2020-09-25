#ifndef PROPERTIESPARSER_H_
#define PROPERTIESPARSER_H_

#include <string>
#include <exception>
#include "Properties.h"

namespace cppproperties {

class PropertiesParser {
public:
    PropertiesParser();
    virtual ~PropertiesParser();

    static Properties Read(const std::string& file);

    static void Write(const std::string& file, const Properties& props);
};

} /* namespace cppproperties */

#endif /* PROPERTIESPARSER_H_ */
