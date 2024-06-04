#pragma once
#include "PartialFunction.h"
#define tp template<typename T>

tp
class CriteriaFunction :
    public PartialFunction
{
    T function;

public:
    CriteriaFunction(const T& func);
    bool isPointDefined(int x) const override;
    int operator()(int x)const override;
    int operator()(int x) override;
    PartialFunction* clone() const;
};

tp
PartialFunction* CriteriaFunction<T>::clone() const {
    return new CriteriaFunction(*this);
}

tp
bool CriteriaFunction<T>::isPointDefined(int x) const {
    return function(x).getKey();
}

tp
int CriteriaFunction<T>::operator()(int x)const {
    if (!isPointDefined(x))
    {
        throw std::exception("The point is not defined");
    }
    return function(x).getValue();
}

tp
int CriteriaFunction<T>::operator()(int x) {
    if (!isPointDefined(x))
    {
        throw std::exception("The point is not defined");
    }
    return function(x).getValue();
}

tp
CriteriaFunction<T>::CriteriaFunction(const T& func) : function(func) {

}
