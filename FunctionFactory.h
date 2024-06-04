#pragma once
#include "PartialFunction.h"
#include "Function0.h"
#include "Function1.h"
#include "Function2.h"
#include "MinFunction.h"
#include "MaxFunction.h"
#include "CriteriaFunction.hpp"
#include <ostream>

class FunctionFactory {
	Function0 CreateFunc0(unsigned n, std::ifstream& in);
	Function1 CreateFunc1(unsigned n, std::ifstream& in);
	Function2 CreateFunc2(unsigned n, std::ifstream& in);

	PartialFunction* CreateMinFunc(size_t n, std::ifstream& in);
	PartialFunction* CreateMaxFunc(size_t n, std::ifstream& in);
	PartialFunction* CreateCriteriaFunc(const char* fileName);
	PartialFunction* CreateCriteriaFunc(unsigned n, unsigned t, std::ifstream& in);

public:
	PartialFunction* PartialFunctionFactory(const char* filename);

};