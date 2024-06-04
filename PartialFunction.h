#pragma once
#include "KeyValuePair.hpp"
#include <exception>
//ЗАДАЧА: Разглеждаме абстрактен базов клас Частична Функция,
//който преобразува цели 32 - битови числа в цели 32 - битови числа и
//задължително притежава операция за проверка дали функцията е дефинирана за дадена точка и
//операция за пресмятане на резултата на функцията за подадено x.


class PartialFunction
{
	//int(*fun)(int);

public:

	virtual PartialFunction* clone() const = 0;
	virtual bool isPointDefined(int x) const = 0;

	virtual int operator()(int x)const = 0;
	virtual int operator()(int x) = 0;

	virtual ~PartialFunction() = default;
};

