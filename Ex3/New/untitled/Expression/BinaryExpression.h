//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_BINARYEXPRESSION_H
#define UNTITLED_BINARYEXPRESSION_H


#include "Expression.h"

template <typename T, typename T2>
class BinaryExpression : public Expression<T> {
protected:
    Expression<T2>* m_first;
    Expression<T2>* m_second;
public:
    BinaryExpression(Expression<T2>* first, Expression<T2>* second) : m_first(first), m_second(second) {};
    virtual T calculate() = 0;
    virtual ~BinaryExpression() {
            delete m_first;
            delete m_second;
    }
};


#endif //UNTITLED_BINARYEXPRESSION_H
