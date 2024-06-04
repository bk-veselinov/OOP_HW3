#pragma once
#include "PartialFunctionContainer.h"
class MinFunction :
    public PartialFunctionContainer
{
public:
	MinFunction(const PartialFunction** funcs, size_t size);
	MinFunction(PartialFunction**&& funcs, size_t size) noexcept;

    PartialFunction* clone() const override;
	bool isPointDefined(int x) const override;

	int operator()(int x)const override;
	int operator()(int x) override;
};

