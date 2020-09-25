#ifndef PROPERTIESEXCEPTION_H_
#define PROPERTIESEXCEPTION_H_

#include <string>
#include <exception>

namespace cppproperties {

class PropertiesException : public std::exception {
public:
    PropertiesException() {}
    PropertiesException(const std::string& msg) throw() : message(msg) {}

    virtual ~PropertiesException() throw() {}

    const std::string& str() const throw() { return message; }

    virtual const char* what() const throw() { return message.c_str(); }

private:
    std::string message;
};

}

#endif /* PROPERTIESEXCEPTION_H_ */
