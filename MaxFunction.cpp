#include "MaxFunction.h"

MaxFunction::MaxFunction(const PartialFunction** funcs, size_t size): PartialFunctionContainer(funcs, size)
{
}

MaxFunction::MaxFunction(PartialFunction**&& funcs, size_t size) noexcept : PartialFunctionContainer(std::move(funcs), size)
{
}


PartialFunction* MaxFunction::clone() const
{
    return new MaxFunction(*this);
}

bool MaxFunction::isPointDefined(int x) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (!functions[i]->isPointDefined(x))
            return false;
    }
    return true;
}

int MaxFunction::operator()(int x) const
{
    if (!isPointDefined(x))
    {
        throw new std::exception("The point is not defined");
    }

    int currMax = (*functions[0])(x);
    for (size_t i = 1; i < size; i++)
    {
        int currVal = (*functions[i])(x);
        if (currMax < currVal)
        {
            currMax = currVal;
        }
    }
    return currMax;
}

int MaxFunction::operator()(int x)
{
    if (!isPointDefined(x))
    {
        throw new std::exception("The point is not defined");
    }

    int currMax = (*functions[0])(x);
    for (size_t i = 1; i < size; i++)
    {
        int currVal = (*functions[i])(x);
        if (currMax < currVal)
        {
            currMax = currVal;
        }
    }
    return currMax;
}
