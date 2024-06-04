#include "Function2.h"

bool Function2::isPointDefined(int x) const
{
	for (size_t i = 0; i < definedpoints.getSize(); i++)
	{
		if (x == definedpoints[i])
		{
			return true;
		}
	}
    return false;
}

Function2::Function2(const int* points, size_t size): definedpoints(size)
{
	for (size_t i = 0; i < size; i++)
	{
		definedpoints.pushBack(points[i]);
	}
}

KeyValuePair<bool, int> Function2::operator()(int x) const
{
	if (isPointDefined(x))
	{
		return KeyValuePair<bool, int>(true, 1);

	}
    return KeyValuePair<bool, int>(true, 0);
}
