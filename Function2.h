#pragma once
#include "Function.h"
#include "Vector.hpp"
class Function2 :
    public Function
{
    Vector<int> definedpoints;
    bool isPointDefined(int x) const;
public:
    Function2(const int* points, size_t size);
    KeyValuePair<bool, int> operator()(int x) const override;
};

