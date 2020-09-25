#include <fstream>
#include <iostream>
#include "PropertiesParser.h"
#include "PropertiesUtils.h"

namespace cppproperties {

PropertiesParser::PropertiesParser() {
}

PropertiesParser::~PropertiesParser() {
}

Properties PropertiesParser::Read(const std::string& file) {
    Properties properties;

    std::ifstream is;
    is.open(file.c_str());
    if (!is.is_open()) {
        throw PropertiesException("PropertiesParser::Read(" + file + "): Unable to open file for reading.");
    }

    try {
        size_t linenr = 0;
        std::string line;
        while (getline(is, line)) {
            if (PropertiesUtils::IsEmptyLine(line) || PropertiesUtils::IsComment(line)) {

            } else if (PropertiesUtils::IsProperty(line)) {
                std::pair<std::string, std::string> prop = PropertiesUtils::ParseProperty(line);
                properties.AddProperty(prop.first, prop.second);
            } else {
                throw PropertiesException("PropertiesParser::Read(" + file + "): Invalid line " + std::to_string(linenr) + ": " + line);
            }
            ++linenr;
        }
        is.close();
    } catch (...) {
        is.close();
        throw;
    }

    return properties;
}

void PropertiesParser::Write(const std::string& file, const Properties& props) {
    std::ofstream os(file, std::ios::binary);//remove (file, std::ios::binary) if you doesn't want hide the text

    os.open(file.c_str());
    if (!os.is_open()) {
        throw PropertiesException("PropertiesParser::Write(" + file + "): Unable to open file for writing.");
    }

    try {
        const std::vector<std::string>& keys = props.GetPropertyNames();
        for (std::vector<std::string>::const_iterator i = keys.begin();
            i != keys.end(); ++i) {
            os << *i << " = " << props.GetProperty(*i) << std::endl;
        }
        os.close();
    } catch (...) {
        os.close();
        throw;
    }
}

}
