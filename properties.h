#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <string>
#include <vector>
#include <map>
#include "PropertiesException.h"
#include "PropertiesNotFoundException.h"

namespace cppproperties {

class Properties {
public:
    Properties();
    virtual ~Properties();

    std::string GetProperty(const std::string& key) const;

    std::string GetProperty(const std::string& key, const std::string& defaultValue) const;

    std::vector<std::string> GetPropertyNames() const;

    void AddProperty(const std::string& key, const std::string& value);

    void RemoveProperty(const std::string& key);
private:
    std::vector<std::string> keys;
    std::map<std::string, std::string> properties;
};

}

#endif /* PROPERTIES_H_ */
