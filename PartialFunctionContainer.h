#pragma once
#include "PartialFunction.h"
class PartialFunctionContainer :
    public PartialFunction
{
protected:
    PartialFunction** functions;
    size_t size;
private:  
    void copyFrom(const PartialFunctionContainer& other);
    void moveFrom(PartialFunctionContainer&& other);
    void free();
public:
    PartialFunctionContainer(const PartialFunction** funcs, size_t size);
    PartialFunctionContainer(PartialFunction**&& funcs, size_t size) noexcept;
    PartialFunctionContainer(const PartialFunctionContainer& other);
    PartialFunctionContainer(PartialFunctionContainer&& other) noexcept;

    PartialFunctionContainer& operator=(const PartialFunctionContainer& other);
    PartialFunctionContainer& operator=(PartialFunctionContainer&& other) noexcept;
  
    ~PartialFunctionContainer();
};

