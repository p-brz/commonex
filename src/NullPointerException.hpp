#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include "Exception.hpp"

namespace CommonExceptions {

EXCEPTION_CLASS(NullPointerException);

#define CHECK_NOT_NULL(pointer)\
    CommonExceptions::assertNotNull(pointer, \
                        COMMON_EXC_HERE  ": " #pointer " is null")

    inline void assertNotNull(const void * ptr, const char * msg=""){
        if(ptr == NULL){
            throw NullPointerException(msg);
        }
    }

}//namespace

#endif // NULLPOINTEREXCEPTION_H
