#ifndef ARRAY_TRANSFORM_VIEW_H
#define ARRAY_TRANSFORM_VIEW_H

#include <vector>
#include <valarray>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <iostream>

template<class Type, class Filter>
class array_transform_view {

private:
    const std::vector<Type> *copy;
    const Type *const array;
    const size_t filtered_size;
    Filter thisone;

public:

    array_transform_view(const Type* array, int size) : copy(NULL), array(array), filtered_size(size)
    {

    }

    explicit array_transform_view(const std::vector<Type>& vector) : copy(&vector), array(NULL), filtered_size(0)
    {

    }

    size_t size() const
    {
        if(copy){
            return copy->size();
        }
        else{
            return filtered_size;
        }
    }

    Type operator[](size_t index) const
    {
        if(copy){
            return thisone((*copy)[index]);
        }else{
            return thisone(array[index]);
        }

    }

    Type at(size_t position) const
    {
        return (*this)[position];
    }

};


#endif //#ARRAY_TRANSFORM_VIEW_H


