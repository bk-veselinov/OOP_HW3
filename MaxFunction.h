#pragma once
#include "PartialFunctionContainer.h"
class MaxFunction :
    public PartialFunctionContainer
{
public:
	MaxFunction(const PartialFunction** funcs, size_t size);
	MaxFunction(PartialFunction**&& funcs, size_t size) noexcept;
	PartialFunction* clone() const override;
	bool isPointDefined(int x) const override;

	int operator()(int x)const override;
	int operator()(int x) override;
};

