#include "FunctionFactory.h"
#include <fstream> 
#include <iostream> 
constexpr int BUFFER_SIZE = 1024;
Function0 FunctionFactory::CreateFunc0(unsigned n, std::ifstream& in)
{
	int* keys = new int[n];
	int* values = new int[n];

	in.read((char*)keys, sizeof(int)*n);
	in.read((char*)values, sizeof(int) * n);
	Function0* result = new Function0(keys, values, n);
	delete[] keys;
	delete[] values;

	return *result;
}

Function1 FunctionFactory::CreateFunc1(unsigned n, std::ifstream& in)
{
	int* values = new int[n];

	in.read((char*)values, sizeof(int) * n);
	Function1 result = Function1(values, n);
	delete[] values;

	return result;
}

Function2 FunctionFactory::CreateFunc2(unsigned n, std::ifstream& in)
{
	int* values = new int[n];

	in.read((char*)values, sizeof(int) * n);
	Function2 result = Function2(values, n);
	delete[] values;

	return result;
}

PartialFunction* FunctionFactory::CreateMinFunc(size_t n, std::ifstream& in)
{
	PartialFunction** funcs = new PartialFunction * [n];
	char* currFileName = new char[BUFFER_SIZE];
	for (size_t i = 0; i < n; i++)
	{
		in.read(currFileName, n);
		funcs[i] = PartialFunctionFactory(currFileName);
	}
	MinFunction* result = new MinFunction(std::move(funcs), n);

	delete[] currFileName;

	return result;
}

PartialFunction* FunctionFactory::CreateMaxFunc(size_t n, std::ifstream& in)
{
	PartialFunction** funcs = new PartialFunction*[n];
	char* currFileName = new char[BUFFER_SIZE];
	for (size_t i = 0; i < n; i++)
	{
		in.read(currFileName, n);
		funcs[i] = PartialFunctionFactory(currFileName);
	}
	MaxFunction* result = new MaxFunction(std::move(funcs), n);

	delete[] currFileName;
	
	return result;
}

PartialFunction* FunctionFactory::CreateCriteriaFunc(const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);
	if (!in.is_open()) {
		throw std::exception("could not open the file");
		
	}
	int n;
	int t;

	in.read((char*)&n, sizeof(n));
	in.read((char*)&t, sizeof(t));

	return CreateCriteriaFunc(n, t, in);
}

PartialFunction* FunctionFactory::CreateCriteriaFunc(unsigned n, unsigned t, std::ifstream& in)
{
	switch (t)
	{
		case 0:
			return new CriteriaFunction<Function0>(CreateFunc0(n, in));
		
		case 1:
			return new CriteriaFunction<Function1>(CreateFunc1(n, in));
		
		case 2:
			return new CriteriaFunction<Function2>(CreateFunc2(n, in));
	
	}
	return nullptr;
}

PartialFunction* FunctionFactory::PartialFunctionFactory(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);

	if (!in.is_open()) {
		throw std::exception("could not open the file");

	}
	int n;
	int t;

	in.read((char*)&n, sizeof(n));
	in.read((char*)&t, sizeof(t));

	switch (t)
	{
	case 0:
	case 1:
	case 2:
		return CreateCriteriaFunc(n, t, in);
		break;
	case 3:
		return CreateMaxFunc(n, in);
	case 4:
		return CreateMinFunc(n, in);
		break;
	}

	return nullptr;
}


