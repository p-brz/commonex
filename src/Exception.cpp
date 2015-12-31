#include "Exception.hpp"

namespace CommonExceptions{

Exception::Exception(const std::string &cause)
    : cause(cause)
    , message(std::string())
{}
Exception::Exception(const std::string &className, const std::string &message)
    : cause(generateMessage(className, message))
    , message(message)
{}

Exception::Exception(const std::string &className, const std::string &message, const std::exception &cause)
    : cause(generateMessage(className, message, &cause))
    , message(message)
{}

Exception::~Exception() throw() {}

const char *Exception::what() const throw(){
    return cause.c_str();
}

const std::string &Exception::getMessage() const
{
    return message;
}

std::string Exception::generateMessage(const std::string &className, const std::string &message, const std::exception *cause)
{
    std::string errMessage;
    if(!className.empty()){
        errMessage.append(className).append(": \t");
    }
    errMessage.append(message);

    if(cause != NULL && cause->what() != NULL){
        errMessage.append("\n");
        errMessage.append("Caused By:\n\t").append(cause->what());
    }

    return errMessage;
}

}//namespace
