#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include "Exception.hpp"

namespace commonex {
    COMMONEX_CLASS(NullPointerException);

    #define COMMONEX_CHECK_NOTNULL(pointer)\
        commonex::assertNotNull(pointer, COMMONEX_HERE  ": " #pointer " is null")

    inline void assertNotNull(const void * ptr, const char * msg=""){
        if(ptr == NULL){
            throw NullPointerException(msg);
        }
    }
}//namespace

#endif // NULLPOINTEREXCEPTION_H
