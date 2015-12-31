/*
 * Exception.hpp
 *
 *  Created on: 10/10/2014
 *      Author: noface
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>

namespace CommonExceptions {

class Exception : public std::exception{
private:
	std::string cause;
    std::string message;
public:
    Exception(const std::string & cause);
    Exception(const std::string & className, const std::string & message);
    Exception(const std::string & className, const std::string & message, const std::exception & cause);
    virtual ~Exception() throw();
    virtual const char* what() const throw();
    /** Return the message used to create this exception*/
    virtual const std::string & getMessage() const;
protected:
    static std::string generateMessage(const std::string & className
                       , const std::string & message, const std::exception * cause=NULL);
};

#define EXCEPTION_SUBCLASS(ClassName, SuperClass) \
class ClassName : public SuperClass{\
public:\
    ClassName(const std::string & message="")\
        : SuperClass(#ClassName, message) \
    {}\
    ClassName(const std::string & message, const std::exception & cause)\
        : SuperClass(#ClassName, message, cause) \
    {}\
\
protected:\
    ClassName(const std::string & className, const std::string & message)\
        : SuperClass(className, message) \
    {}\
    ClassName(const std::string & className, const std::string & message, const std::exception & cause)\
        : SuperClass(className, message, cause) \
    {}\
}

#define EXCEPTION_CLASS(ClassName) EXCEPTION_SUBCLASS(ClassName, ::CommonExceptions::Exception)

#define COMMON_EXC_toString(x) #x
#define COMMON_EXC_toString_(x) COMMON_EXC_toString(x)
#define COMMON_EXC__STRLINE__ COMMON_EXC_toString_(__LINE__)
#define COMMON_EXC_HERE __FILE__ "::" COMMON_EXC__STRLINE__

} /* namespace CommonExceptions */

#endif /* EXCEPTION_HPP_ */
