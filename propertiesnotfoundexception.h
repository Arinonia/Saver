#ifndef PROPERTYNOTFOUNDEXCEPTION_H_
#define PROPERTYNOTFOUNDEXCEPTION_H_

#include <string>
#include <exception>

namespace cppproperties {

class PropertyNotFoundException : public std::exception {
public:
    PropertyNotFoundException() {}
    PropertyNotFoundException(const std::string& msg) throw() : message(msg) {}

    virtual ~PropertyNotFoundException() throw() {}

    const std::string& str() const throw() { return message; }

    virtual const char* what() const throw() { return message.c_str(); }

private:
    std::string message;
};

}

#endif /* PROPERTYNOTFOUNDEXCEPTION_H_ */
