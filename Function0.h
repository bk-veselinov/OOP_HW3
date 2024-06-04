#pragma once
#include "Function.h"
#include "Vector.hpp"
class Function0 :
    public Function
{
    Vector<KeyValuePair<int, int>> points;
    int* getValue(int x) const;
public:
    Function0(const int* keys, const int* pairs, size_t size);
    KeyValuePair<bool, int> operator()(int x) const override;
};

