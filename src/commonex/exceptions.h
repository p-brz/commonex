#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Exception.hpp"
#include "IllegalArgumentException.hpp"
#include "IllegalStateException.h"
#include "IndexOutOfBoundsExceptions.h"
#include "IOException.h"
#include "NullPointerException.hpp"

namespace commonex {

    COMMONEX_CLASS(AssertionError);
    COMMONEX_CLASS(ParseException);
    COMMONEX_CLASS(DataException);
    COMMONEX_CLASS(NotImplementedException);

/** Checks if @param{condition} is true and trows an exception (AssertionError) otherwise.*/
#define COMMONEX_ASSERT(condition) \
do{\
    if(!(condition)){\
        std::string conditionStr = #condition;\
        std::string msgError = std::string("'").append(conditionStr).append("' is false.");\
        throw commonex::AssertionError(msgError);\
    }\
}while(false);

#define NOT_IMPLEMENTED(MSG) \
    throw commonex::NotImplementedException("at " COMMONEX_HERE " " #MSG)

}//namespace

#endif // EXCEPTIONS_H
