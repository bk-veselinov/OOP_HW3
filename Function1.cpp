#include "Function1.h"

bool Function1::isPointDefined(int x) const
{
	for (size_t i = 0; i < undefinedVals.getSize(); i++)
	{
		if (x == undefinedVals[i])
		{
			return false;
		}
	}
    return true;
}

Function1::Function1(const int* points, size_t size): undefinedVals(size)
{
	for (size_t i = 0; i < size; i++)
	{
		undefinedVals.pushBack(points[i]);
	}
}

KeyValuePair<bool, int> Function1::operator()(int x) const
{
	if (!isPointDefined(x))
	{
		return KeyValuePair<bool, int>(false, -1);

	}
    return KeyValuePair<bool, int>(true, x);
}
