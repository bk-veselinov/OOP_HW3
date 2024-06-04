#pragma once
#include "KeyValuePair.hpp"
class Function
{
public:

	virtual KeyValuePair<bool, int> operator()(int x) const = 0;

	virtual ~Function() = default;
};

