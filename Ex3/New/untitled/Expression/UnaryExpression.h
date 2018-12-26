//
// Created by daniel on 12/19/18.
//

#ifndef UNTITLED_UNARYEXPRESSION_H
#define UNTITLED_UNARYEXPRESSION_H


#include "Expression.h"

template <typename T>
class UnaryExpression : public Expression<T> {
protected:
    Expression<T>* m_expression;
public:
    UnaryExpression(Expression<T>* expression) : m_expression(expression) {};
    virtual T calculate() = 0;
    virtual ~UnaryExpression() {
        delete m_expression;
    }
};

#endif //UNTITLED_UNARYEXPRESSION_H
