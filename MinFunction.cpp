#include "MinFunction.h"

MinFunction::MinFunction(const PartialFunction** funcs, size_t size): PartialFunctionContainer(funcs, size)
{
}

MinFunction::MinFunction(PartialFunction**&& funcs, size_t size) noexcept: PartialFunctionContainer(std::move(funcs), size)
{
}

PartialFunction* MinFunction::clone() const
{
    return new MinFunction(*this);
}

bool MinFunction::isPointDefined(int x) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (!functions[i]->isPointDefined(x)) 
            return false;
    }
    return true;
}

int MinFunction::operator()(int x) const
{
    if (!isPointDefined(x))
    {
        throw new std::exception("The point is not defined");
    }

    int currMin = (*functions[0])(x);
    for (size_t i = 1; i < size; i++)
    {
        int currVal = (*functions[i])(x);
        if (currMin > currVal)
        {
            currMin = currVal;
        }
    }
    return currMin;
}

int MinFunction::operator()(int x)
{
    if (!isPointDefined(x))
    {
        throw new std::exception("The point is not defined");
    }

    int currMin = (*functions[0])(x);
    for (size_t i = 1; i < size; i++)
    {
        int currVal = (*functions[i])(x);
        if (currMin > currVal)
        {
            currMin = currVal;
        }
    }
    return currMin;
}
