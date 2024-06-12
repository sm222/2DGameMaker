#ifndef BASIC_OBJECT_HPP
#define BASIC_OBJECT_HPP

#include "../inc/CPPDefine.hpp"
#include "../type/Number.hpp"
#include <vector>

class BasicObject{
    public:
        RenderValue *renderValue;


    protected:
        Vector2N pos;
        Number x;
        Number y;
};


#endif //BASIC_OBJECT_HPP