#ifndef COMMONEXCEPTIONS_H
#define COMMONEXCEPTIONS_H

#include "Exception.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "IndexOutOfBoundsExceptions.h"
#include "IOException.h"

namespace CommonExceptions {

    EXCEPTION_CLASS(AssertionError);
    EXCEPTION_CLASS(ParseException);
    EXCEPTION_CLASS(DataException);
    EXCEPTION_CLASS(NotImplementedException);

/** Checks if @param{condition} is true and trows an exception (AssertionError) otherwise.*/
#define CHECK_ASSERTION(condition) \
do{\
    if(!(condition)){\
        std::string conditionStr = #condition;\
        std::string msgError = std::string("'").append(conditionStr).append("' is false.");\
        throw CommonExceptions::AssertionError(msgError);\
    }\
}while(false);

#define NOT_IMPLEMENTED(MSG) \
    throw CommonExceptions::NotImplementedException("at " COMMON_EXC_HERE " " #MSG)

}//namespace

#endif // COMMONEXCEPTIONS_H
