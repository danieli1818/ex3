//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_DIV_H
#define UNTITLED_DIV_H


#include "../BinaryExpression.h"

class Div : public BinaryExpression<double, double> {
public:
    Div(Expression* first, Expression* second) : BinaryExpression(first, second) {};
    virtual double calculate() {
        return m_first->calculate() / m_second->calculate();
    }
};


#endif //UNTITLED_DIV_H
