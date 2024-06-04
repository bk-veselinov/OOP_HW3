#pragma once
#include "Function.h"
#include "Vector.hpp"
#include "KeyValuePair.hpp"

class Function1 :
    public Function
{
    Vector<int> undefinedVals;
    bool isPointDefined(int x) const;
public:
    Function1(const int* points, size_t size);
    KeyValuePair<bool, int> operator()(int x) const override;
};

