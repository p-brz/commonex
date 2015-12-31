#ifndef INDEXOUTOFBOUNDSEXCEPTIONS_H
#define INDEXOUTOFBOUNDSEXCEPTIONS_H

#include "Exception.hpp"

#include <sstream>

namespace CommonExceptions {

EXCEPTION_CLASS(IndexOutOfBoundsException);

#define COMMON_EXC_BOUNDS_MSG(size, index)\
    ::CommonExceptions::makeCheckBoundsMessage(COMMON_EXC_HERE, size, index)

#define COMMON_EXC_CHECK_BOUNDS(collection, index)\
            ::CommonExceptions::checkIndex(collection, index, COMMON_EXC_BOUNDS_MSG(collection.size(), index))

#define COMMON_EXC_CHECK_NEG_BOUND(collection, index)\
            ::CommonExceptions::checkNegativeIndex(index, COMMON_EXC_BOUNDS_MSG(collection.size(), index))

template<typename Collection, typename Index>
inline void checkIndex(const Collection & coll, const Index index
                     , const std::string & msg = std::string())
{
    if(index < 0 || index >= coll.size()){
        throw IndexOutOfBoundsException(msg);
    }
}
template<typename Index>
inline void checkNegativeIndex(const Index index
                     , const std::string & msg = std::string())
{
    if(index < 0){
        throw IndexOutOfBoundsException(msg);
    }
}

template<typename SizeType, typename IndexType>
std::string makeCheckBoundsMessage(const char * FileLine, const SizeType & size, const IndexType & index){
    std::stringstream sstream;
    sstream << FileLine << ": Index(" << index << "); Size(" << size << ")";
    return sstream.str();
}

}//namespace

#endif // INDEXOUTOFBOUNDSEXCEPTIONS_H

