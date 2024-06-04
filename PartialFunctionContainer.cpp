#include "PartialFunctionContainer.h"

void PartialFunctionContainer::copyFrom(const PartialFunctionContainer& other)
{
	functions = new PartialFunction * [other.size];
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		functions[i] = other.functions[i]->clone();
	}
}

void PartialFunctionContainer::moveFrom(PartialFunctionContainer&& other)
{
	functions = other.functions;
	size = other.size;

	other.functions = nullptr;
	other.size = 0;
}

void PartialFunctionContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete functions[i];
	}
	delete[] functions;
}



PartialFunctionContainer::PartialFunctionContainer(const PartialFunction** funcs, size_t size): size(size)
{
	functions = new PartialFunction * [size];
	for (size_t i = 0; i < size; i++)
	{
		//TODO !!!!!!!!!!!!!!!!!!!!
		functions[i] = funcs[i]->clone();
	}
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
PartialFunctionContainer::PartialFunctionContainer(PartialFunction**&& funcs, size_t size) noexcept: size(size)
{
	delete[] functions;
	functions = funcs;
	funcs = nullptr;
}

PartialFunctionContainer::PartialFunctionContainer(const PartialFunctionContainer& other)
{
	copyFrom(other);
}

PartialFunctionContainer::PartialFunctionContainer(PartialFunctionContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

PartialFunctionContainer& PartialFunctionContainer::operator=(const PartialFunctionContainer& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

PartialFunctionContainer& PartialFunctionContainer::operator=(PartialFunctionContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

PartialFunctionContainer::~PartialFunctionContainer()
{
	free();
}
