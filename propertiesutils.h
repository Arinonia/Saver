#ifndef PROPERTIESUTILS_H_
#define PROPERTIESUTILS_H_

#include <string>
#include <utility>

namespace cppproperties {
namespace PropertiesUtils {


std::string LeftTrim(const std::string& str);

std::string RightTrim(const std::string& str);

std::string Trim(const std::string& str);

bool IsProperty(const std::string& str);

std::pair<std::string, std::string> ParseProperty(const std::string& str);

bool IsComment(const std::string& str);

bool IsEmptyLine(const std::string& str);

}
}

#endif /* PROPERTIESUTILS_H_ */
