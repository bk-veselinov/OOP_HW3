#pragma once
#include "FunctionFactory.h"
class System
{
	//TODO BIG 6
	PartialFunction* function = nullptr;

	bool hasInterval;
	int leftBound;
	int rightBound;
public:
	System() = default;

	System& operator=(const System&) = delete;
	System(const System&) = delete;


	void run() ;
	void initializeBound();
	void initializeFunction();
	void calculateFunctionWithBound() const;
	void calculateFunctionWithConsecotiveValues() const;

	~System();

};

