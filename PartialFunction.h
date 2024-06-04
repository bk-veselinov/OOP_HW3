#pragma once
#include "KeyValuePair.hpp"
#include <exception>
//������: ����������� ���������� ����� ���� �������� �������,
//����� ����������� ���� 32 - ������ ����� � ���� 32 - ������ ����� �
//������������ ��������� �������� �� �������� ���� ��������� � ���������� �� ������ ����� �
//�������� �� ���������� �� ��������� �� ��������� �� �������� x.


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

