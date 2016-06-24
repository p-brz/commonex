#ifndef INDEXOUTOFBOUNDSEXCEPTIONS_H
#define INDEXOUTOFBOUNDSEXCEPTIONS_H

#include "Exception.hpp"

#include <sstream>

namespace commonex {

COMMONEX_CLASS(IndexOutOfBoundsException);

#define COMMONEX_BOUNDS_MSG(size, index)\
    ::commonex::makeCheckBoundsMessage(COMMONEX_HERE, size, index)

#define COMMONEX_CHECK_BOUNDS(collection, index)\
            ::commonex::checkIndex(collection, index, COMMONEX_BOUNDS_MSG(collection.size(), index))

#define COMMONEX_CHECK_NEG_BOUND(collection, index)\
            ::commonex::checkNegativeIndex(index, COMMONEX_BOUNDS_MSG(collection.size(), index))

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

