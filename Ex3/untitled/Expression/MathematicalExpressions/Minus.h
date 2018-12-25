//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_MINUS_H
#define UNTITLED_MINUS_H


#include "../BinaryExpression.h"

class Minus : public BinaryExpression<double, double> {
public:
    Minus(Expression* first, Expression* second) : BinaryExpression(first, second) {};
    virtual double calculate() {
        return m_first->calculate() - m_second->calculate();
    }
};


#endif //UNTITLED_MINUS_H
