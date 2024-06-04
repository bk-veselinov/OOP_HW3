#include "Function0.h"

int* Function0::getValue(int x) const
{
	for (size_t i = 0; i < points.getSize(); i++)
	{
		if (points[i].getKey()==x)
		{
			int res = points[i].getValue();
			return &res;
		}
	}
	return nullptr;
}

Function0::Function0(const int* keys, const int* pairs, size_t size):points(size)
{
	for (size_t i = 0; i < size; i++)
	{
		points.pushBack(KeyValuePair<int , int>(keys[i], pairs[i]));
	}
}

KeyValuePair<bool, int> Function0::operator()(int x) const
{
	int* val = getValue(x);
	if (!val)
	{
		return KeyValuePair<bool, int>(false, -1);
	}
    return KeyValuePair<bool, int>(true, *val);
}
